#include "WfCpp.h"

namespace vl
{
	namespace workflow
	{
		namespace cppcodegen
		{
			using namespace collections;
			using namespace stream;
			using namespace filesystem;
			using namespace regex;

/***********************************************************************
WfCppInput
***********************************************************************/

			WfCppInput::WfCppInput(const WString& _assemblyName)
			{
				headerGuardPrefix = L"VCZH_WORKFLOW_COMPILER_GENERATED_";
				assemblyName = _assemblyName;
				assemblyNamespace = L"vl_workflow_global";
				includeFileName = _assemblyName + L"Includes";
				reflectionFileName = assemblyName + L"Reflection";
				defaultFileName = _assemblyName;
			}

/***********************************************************************
GenerateCppFiles
***********************************************************************/

			template<typename TCallback>
			WString GenerateToStream(const TCallback& callback)
			{
				MemoryStream stream;
				{
					StreamWriter writer(stream);
					callback(writer);
				}
				stream.SeekFromBegin(0);
				{
					StreamReader reader(stream);
					return reader.ReadToEnd();
				}
			}

			void GenerateCppComment(StreamWriter& writer, const WString& comment)
			{
				writer.WriteLine(L"/***********************************************************************");
				writer.WriteLine(L"!!!!!! DO NOT MODIFY !!!!!!");
				writer.WriteLine(L"");
				writer.WriteLine(comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"This file is generated by Workflow compiler");
				writer.WriteLine(L"https://github.com/vczh-libraries");
				writer.WriteLine(L"***********************************************************************/");
			}

			void WriteReflectionInclude(bool reflection, Ptr<WfCppInput> input, stream::StreamWriter& writer)
			{
				if (reflection || input->reflectionIncludes.Count() > 0)
				{
					writer.WriteLine(L"/* CodePack:BeginIgnore() */");
					writer.WriteLine(L"#ifndef VCZH_DEBUG_NO_REFLECTION");
					if (reflection)
					{
						writer.WriteLine(L"/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, " + input->reflectionFileName + L".h) */");
						writer.WriteLine(L"#include \"" + input->reflectionFileName + L".h\"");
					}
					else
					{
						FOREACH(WString, include, input->reflectionIncludes)
						{
							writer.WriteLine(L"/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, " + include + L") */");
							writer.WriteLine(L"#include \"" + include + L"\"");
						}
					}
					writer.WriteLine(L"#endif");
					writer.WriteLine(L"/* CodePack:EndIgnore() */");
				}
			}

			void WriteDependedInclude(WfCppConfig& config, const List<Ptr<WfClassDeclaration>>& classDecls, stream::StreamWriter& writer)
			{
				List<Ptr<WfDeclaration>> decls;
				CopyFrom(decls, classDecls);
				for (vint i = 0; i < decls.Count(); i++)
				{
					if (auto classDecl = decls[i].Cast<WfClassDeclaration>())
					{
						{
							vint index = config.enumDecls.Keys().IndexOf(classDecl.Obj());
							if (index != -1)
							{
								CopyFrom(decls, config.enumDecls.GetByIndex(index), true);
							}
						}
						{
							vint index = config.structDecls.Keys().IndexOf(classDecl.Obj());
							if (index != -1)
							{
								CopyFrom(decls, config.structDecls.GetByIndex(index), true);
							}
						}
						{
							vint index = config.classDecls.Keys().IndexOf(classDecl.Obj());
							if (index != -1)
							{
								CopyFrom(decls, config.classDecls.GetByIndex(index), true);
							}
						}
					}
				}

				SortedList<WString> fileNames;
				FOREACH(Ptr<WfDeclaration>, decl, decls)
				{
					vint index = config.declDependencies.Keys().IndexOf(decl.Obj());
					if (index != -1)
					{
						FOREACH(Ptr<WfDeclaration>, declDep, config.declDependencies.GetByIndex(index))
						{
							WString fileName = config.declFiles[declDep.Obj()];
							if (fileName != L"" && !fileNames.Contains(fileName))
							{
								fileNames.Add(fileName);
							}
						}
					}
				}

				FOREACH(WString, fileName, fileNames)
				{
					writer.WriteLine(L"#include \"" + fileName + L".h\"");
				}
			}

			void WriteHeader(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(input->defaultFileName));
				writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(input->defaultFileName));
				writer.WriteLine(L"");
				FOREACH(WString, include, input->normalIncludes)
				{
					writer.WriteLine(L"#include \"" + include + L"\"");
				}
				writer.WriteLine(L"");
				config.WriteHeader(writer, multiFile);
				writer.WriteLine(L"");
				writer.WriteLine(L"#endif");
			}

			void WriteNonCustomSubHeader(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, vint fileIndex, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + L"DEPENDED_GROUP_" + itow(fileIndex));
				writer.WriteLine(L"#define " + input->headerGuardPrefix + L"DEPENDED_GROUP_" + itow(fileIndex));
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + input->defaultFileName + L".h\"");
				WriteDependedInclude(config, config.headerFilesClasses[fileIndex], writer);
				writer.WriteLine(L"");
				config.WriteNonCustomSubHeader(writer, fileIndex);
				writer.WriteLine(L"");
				writer.WriteLine(L"#endif");
			}

			void WriteCpp(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + output->entryFileName + L".h\"");
				WriteReflectionInclude(reflection, input, writer);
				writer.WriteLine(L"");
				config.WriteCpp(writer, multiFile);
			}

			void WriteReflectionHeader(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(input->reflectionFileName));
				writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(input->reflectionFileName));
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + output->entryFileName + L".h\"");
				if (input->reflectionIncludes.Count() > 0)
				{
					writer.WriteLine(L"#ifndef VCZH_DEBUG_NO_REFLECTION");
					FOREACH(WString, include, input->reflectionIncludes)
					{
						writer.WriteLine(L"#include \"" + include + L"\"");
					}
					writer.WriteLine(L"#endif");
				}
				writer.WriteLine(L"");
				config.WriteReflectionHeader(writer, multiFile);
				writer.WriteLine(L"");
				writer.WriteLine(L"#endif");
			}

			void WriteReflectionCpp(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + input->reflectionFileName + L".h\"");
				writer.WriteLine(L"");
				config.WriteReflectionCpp(writer, multiFile);
			}

			void WriteIncludesHeader(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(input->includeFileName));
				writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(input->includeFileName));
				writer.WriteLine(L"");

				writer.WriteLine(L"#include \"" + input->defaultFileName + L".h\"");
				FOREACH(WString, fileName, config.customFilesClasses.Keys())
				{
					if (fileName != L"")
					{
						writer.WriteLine(L"#include \"" + fileName + L".h\"");
					}
				}
				FOREACH(vint, fileIndex, config.headerFilesClasses.Keys())
				{
					if (fileIndex != 0)
					{
						writer.WriteLine(L"#include \"" + input->defaultFileName + itow(fileIndex) + L".h\"");
					}
				}

				writer.WriteLine(L"");
				writer.WriteLine(L"#endif");
			}

			void WriteSubHeader(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, const WString& fileName, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(fileName));
				writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(fileName));
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + input->defaultFileName + L".h\"");
				WriteDependedInclude(config, config.customFilesClasses[fileName], writer);
				writer.WriteLine(L"");
				config.WriteSubHeader(writer, fileName);
				writer.WriteLine(L"");
				writer.WriteLine(L"#endif");
			}

			void WriteSubCpp(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, const WString& fileName, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + input->includeFileName + L".h\"");
				WriteReflectionInclude(reflection, input, writer);
				writer.WriteLine(L"");
				config.WriteSubCpp(writer, fileName);
			}

			Ptr<WfCppOutput> GenerateCppFiles(Ptr<WfCppInput> input, analyzer::WfLexicalScopeManager* manager)
			{
				WfCppConfig config(manager, input->assemblyName, input->assemblyNamespace);
				for (vint i = 0; i < config.topLevelClassDeslcForHeaderFilesReversed.Count(); i++)
				{
					auto key = config.topLevelClassDeslcForHeaderFilesReversed.Keys()[i];
					auto value = config.topLevelClassDeslcForHeaderFilesReversed.Values()[i];
					config.declFiles.Set(key, input->defaultFileName + itow(value));
				}

				auto output = MakePtr<WfCppOutput>();
				if (config.manager->declarationTypes.Count() > 0)
				{
					output->containsReflectionInfo = true;
				}

				bool multiFile = false;
				switch (input->multiFile)
				{
				case WfCppFileSwitch::Enabled:
					multiFile = true;
					break;
				case WfCppFileSwitch::Disabled:
					multiFile = false;
					break;
				default:
					multiFile = config.topLevelClassDeclsForCustomFiles.Count() > 1;
				}

				bool reflection = false;
				switch (input->reflection)
				{
				case WfCppFileSwitch::Enabled:
					reflection = true;
					break;
				case WfCppFileSwitch::Disabled:
					reflection = false;
					break;
				default:
					reflection = config.manager->declarationTypes.Count() > 0;
				}

				output->multiFile = multiFile;
				output->reflection = reflection;

				if (multiFile)
				{
					output->entryFileName = input->includeFileName;
				}
				else
				{
					output->entryFileName = input->defaultFileName;
				}

				output->cppFiles.Add(input->defaultFileName + L".h", GenerateToStream([&](StreamWriter& writer)
				{
					WriteHeader(input, output, config, multiFile, reflection, writer);
				}));
				FOREACH(vint, fileIndex, config.topLevelClassDeclsForHeaderFiles.Keys())
				{
					output->cppFiles.Add(input->defaultFileName + itow(fileIndex) + L".h", GenerateToStream([&](StreamWriter& writer)
					{
						WriteNonCustomSubHeader(input, output, config, multiFile, reflection, fileIndex, writer);
					}));
				}

				output->cppFiles.Add(input->defaultFileName + L".cpp", GenerateToStream([&](StreamWriter& writer)
				{
					WriteCpp(input, output, config, multiFile, reflection, writer);
				}));

				if (reflection)
				{
					output->cppFiles.Add(input->reflectionFileName + L".h", GenerateToStream([&](StreamWriter& writer)
					{
						WriteReflectionHeader(input, output, config, multiFile, reflection, writer);
					}));

					output->cppFiles.Add(input->reflectionFileName + L".cpp", GenerateToStream([&](StreamWriter& writer)
					{
						WriteReflectionCpp(input, output, config, multiFile, reflection, writer);
					}));
				}

				if (multiFile)
				{
					output->cppFiles.Add(input->includeFileName + L".h", GenerateToStream([&](StreamWriter& writer)
					{
						WriteIncludesHeader(input, output, config, multiFile, reflection, writer);
					}));

					FOREACH(WString, fileName, config.topLevelClassDeclsForCustomFiles.Keys())
					{
						if (fileName != L"")
						{
							output->cppFiles.Add(fileName + L".h", GenerateToStream([&](StreamWriter& writer)
							{
								WriteSubHeader(input, output, config, multiFile, reflection, fileName, writer);
							}));

							output->cppFiles.Add(fileName + L".cpp", GenerateToStream([&](StreamWriter& writer)
							{
								WriteSubCpp(input, output, config, multiFile, reflection, fileName, writer);
							}));
						}
					}
				}

				return output;
			}

/***********************************************************************
MergeCppFile
***********************************************************************/

			WString RemoveSpacePrefix(const WString& s)
			{
				for (vint i = 0; i < s.Length(); i++)
				{
					if (s[i] != L' '&&s[i] != L'\t')
					{
						return s.Sub(i, s.Length() - i);
					}
				}
				return WString::Empty;
			}

			const vint NORMAL = 0;
			const vint WAIT_HEADER = 1;
			const vint WAIT_OPEN = 2;
			const vint WAIT_CLOSE = 3;
			const vint USER_CONTENT = 4;
			const vint UNUSED_USER_CONTENT = 5;

			template<typename TCallback>
			void ProcessCppContent(const WString& code, const TCallback& callback)
			{
				Regex regexUserContentBegin(L"/.*?(?/{)?///* USER_CONTENT_BEGIN/((<name>[^)]*?)/) /*//");

				vint state = NORMAL;
				vint counter = 0;
				WString previousContent;

				StringReader reader(code);
				while (!reader.IsEnd())
				{
					auto line = reader.ReadLine();
					if (reader.IsEnd() && line == L"")
					{
						break;
					}

					if (line == L"// UNUSED_USER_CONTENT:")
					{
						state = UNUSED_USER_CONTENT;
					}

					if (state == UNUSED_USER_CONTENT)
					{
						callback(state, state, line, line);
					}
					else
					{
						auto content = RemoveSpacePrefix(line);
						auto previousState = state;
						switch (state)
						{
						case NORMAL:
							if (auto match = regexUserContentBegin.MatchHead(content))
							{
								content = L"USERIMPL(/* " + match->Groups()[L"name"][0].Value() + L" */)";
								if (match->Captures().Count() > 0)
								{
									content += previousContent;
								}
								state = USER_CONTENT;
							}
							else if (INVLOC.StartsWith(content, L"USERIMPL(",Locale::None))
							{
								state = WAIT_HEADER;
							}
							break;
						case WAIT_HEADER:
							state = WAIT_OPEN;
							break;
						case WAIT_OPEN:
							if (INVLOC.StartsWith(content, L"{", Locale::None))
							{
								state = WAIT_CLOSE;
							}
							break;
						case WAIT_CLOSE:
							if (INVLOC.StartsWith(content, L"{", Locale::None))
							{
								counter++;
							}
							else if (INVLOC.StartsWith(content, L"}", Locale::None))
							{
								if (counter == 0)
								{
									state = NORMAL;
								}
								else
								{
									counter--;
								}
							}
							break;
						case USER_CONTENT:
							if (INVLOC.EndsWith(content, L"/* USER_CONTENT_END() */", Locale::None))
							{
								state = NORMAL;
							}
							break;
						}
						callback(previousState, state, line, content);
					}
					previousContent = RemoveSpacePrefix(line);
				}
			}

			template<typename TCallback>
			void SplitCppContent(const WString& code, Dictionary<WString, WString>& userContents, Dictionary<WString, WString>& userContentsFull, const TCallback& callback)
			{
				WString name;
				WString userImpl;
				WString userImplFull;
				ProcessCppContent(code, [&](vint previousState, vint state, const WString& line, const WString& content)
				{
					if (state == UNUSED_USER_CONTENT)
					{
						callback(line);
					}
					else
					{
						switch (previousState)
						{
						case NORMAL:
							switch (state)
							{
							case WAIT_HEADER:
							case USER_CONTENT:
								name = content;
								userImpl = L"";
								userImplFull = L"";
								break;
							}
							break;
						case WAIT_HEADER:
							name += content;
							break;
						case WAIT_CLOSE:
						case USER_CONTENT:
							switch (state)
							{
							case WAIT_CLOSE:
							case USER_CONTENT:
								userImpl += line + L"\r\n";
								break;
							case NORMAL:
								userImplFull += L"//" + line + L"\r\n";
								userContents.Add(name, userImpl);
								userContentsFull.Add(name, userImplFull);
								name = L"";
								break;
							}
							break;
						}

						if (name != L"")
						{
							userImplFull += L"//" + line + L"\r\n";
						}
					}
				});
			}

			WString MergeCppMultiPlatform(const WString& code32, const WString& code64)
			{
				static wchar_t stringCast32[] = L"static_cast<::vl::vint32_t>(";
				const vint lengthCast32 = sizeof(stringCast32) / sizeof(*stringCast32) - 1;

				static wchar_t stringCast64[] = L"static_cast<::vl::vint64_t>(";
				const vint lengthCast64 = sizeof(stringCast64) / sizeof(*stringCast64) - 1;

				return GenerateToStream([&](StreamWriter& writer)
				{
					const wchar_t* reading32 = code32.Buffer();
					const wchar_t* reading64 = code64.Buffer();
					const wchar_t* start32 = reading32;
					while (true)
					{
						vint length = 0;
						while (reading32[length] && reading64[length])
						{
							if (reading32[length] == reading64[length])
							{
								length++;
							}
							else
							{
								break;
							}
						}

						writer.WriteString(reading32, length);
						reading32 += length;
						reading64 += length;

						if (*reading32 == 0 && *reading64 == 0)
						{
							break;
						}

#define IS_DIGIT(C) (L'0' <= C && C <= L'9')

						if (reading32[0] == L'3' && reading32[1] == L'2' && reading64[0] == L'6' && reading64[1] == L'4')
						{
							if (length >= 4)
							{
								if (wcsncmp(reading32 - 4, L"vint32_t", 8) == 0 && wcsncmp(reading64 - 4, L"vint64_t", 8) == 0)
								{
									reading32 += 4;
									reading64 += 4;
									goto NEXT_ROUND;
								}
							}
						}
						else if (reading64[0] == L'L')
						{
							if (reading32[0] == reading64[1] && length >= 1)
							{
								if (IS_DIGIT(reading32[-1]) && !IS_DIGIT(reading32[0]))
								{
									if (IS_DIGIT(reading64[-1]) && !IS_DIGIT(reading64[1]))
									{
										reading64 += 1;
										goto NEXT_ROUND;
									}
								}
							}
						}
						else if (reading64[0] == L'U' && reading64[1] == L'L')
						{
							if (reading32[0] == reading64[2] && length >= 1)
							{
								if (IS_DIGIT(reading32[-1]) && !IS_DIGIT(reading32[0]))
								{
									if (IS_DIGIT(reading64[-1]) && !IS_DIGIT(reading64[2]))
									{
										reading64 += 2;
										goto NEXT_ROUND;
									}
								}
							}
						}
						else if (wcsncmp(reading32, stringCast32, lengthCast32) == 0 && IS_DIGIT(reading32[lengthCast32]) && IS_DIGIT(reading64[0]))
						{
							reading32 += lengthCast32;
							vint digitCount = 0;
							while (IS_DIGIT(reading32[digitCount])) digitCount++;
							if (wcsncmp(reading32, reading64, digitCount) == 0 && reading64[digitCount] == L'L' && reading32[digitCount] == L')')
							{
								writer.WriteString(L"static_cast<::vl::vint>(");
								writer.WriteString(WString(reading32, digitCount));
								writer.WriteChar(L')');
								reading64 += digitCount + 1;
								reading32 += digitCount + 1;
								goto NEXT_ROUND;
							}
						}
						else if (wcsncmp(reading64, stringCast64, lengthCast64) == 0 && IS_DIGIT(reading64[lengthCast64]) && IS_DIGIT(reading32[0]))
						{
							reading64 += lengthCast64;
							vint digitCount = 0;
							while (IS_DIGIT(reading64[digitCount])) digitCount++;
							if (wcsncmp(reading64, reading32, digitCount) == 0 && reading64[digitCount] == L'L' && reading64[digitCount + 1] == L')')
							{
								writer.WriteString(L"static_cast<::vl::vint>(");
								writer.WriteString(WString(reading64, digitCount));
								writer.WriteChar(L')');
								reading64 += digitCount + 2;
								reading32 += digitCount;
								goto NEXT_ROUND;
							}
						}
						throw Exception(L"The difference at " + itow((vint)(reading32 - start32)) + L"-th character between Input C++ source files are not "
							L"\"vint32_t\" and \"vint64_t\", "
							L"\"<number>\" and \"<number>L\", "
							L"\"<number>\" and \"<number>UL\"."
							);
					NEXT_ROUND:;

#undef IS_DIGIT
					}
				});
			}

			WString MergeCppFileContent(const WString& dst, const WString& src)
			{
				Dictionary<WString, WString> userContents, userContentsFull;
				WString unusedUserContent = GenerateToStream([&](StreamWriter& writer)
				{
					SplitCppContent(dst, userContents, userContentsFull, [&](const WString& line)
					{
						writer.WriteLine(line);
					});
				});

				WString processedUnusedUserContent = GenerateToStream([&](StreamWriter& writer)
				{
					StringReader reader(unusedUserContent);
					while (!reader.IsEnd())
					{
						auto line = reader.ReadLine();
						if (line != L"// UNUSED_USER_CONTENT:")
						{
							if (INVLOC.StartsWith(line, L"//", Locale::None))
							{
								line = line.Right(line.Length() - 2);
							}
							writer.WriteLine(line);
						}
					}
				});

				SplitCppContent(processedUnusedUserContent, userContents, userContentsFull, [&](const WString& line) {});
				
				return GenerateToStream([&](StreamWriter& writer)
				{
					WString name;
					WString userImpl;
					ProcessCppContent(src, [&](vint previousState, vint state, const WString& line, const WString& content)
					{
						switch (previousState)
						{
						case NORMAL:
							switch (state)
							{
							case WAIT_HEADER:
							case USER_CONTENT:
								name = content;
								userImpl = L"";
								break;
							}
							break;
						case WAIT_HEADER:
							name += content;
							break;
						case WAIT_CLOSE:
						case USER_CONTENT:
							switch (state)
							{
							case WAIT_CLOSE:
							case USER_CONTENT:
								userImpl += line + L"\r\n";
								return;
							case NORMAL:
								{
									vint index = userContents.Keys().IndexOf(name);
									if (index == -1)
									{
										writer.WriteString(userImpl);
									}
									else
									{
										writer.WriteString(userContents.Values()[index]);
										userContentsFull.Remove(name);
									}
								}
								break;
							}
							break;
						}
						writer.WriteLine(line);
					});

					if (userContentsFull.Count() > 0)
					{
						writer.WriteLine(L"// UNUSED_USER_CONTENT:");
						FOREACH(WString, content, userContentsFull.Values())
						{
							writer.WriteString(content);
						}
					}
				});
			}
		}
	}
}
