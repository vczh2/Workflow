/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/NewCustomInterface3.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_NEWCUSTOMINTERFACE3
#define VCZH_WORKFLOW_COMPILER_GENERATED_NEWCUSTOMINTERFACE3

#include "../Source/CppTypes.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

namespace vl_workflow_global
{
	class __vwsnc1_NewCustomInterface3_MyClass_CreateMyInterface__IMyInterface3;
	class __vwsnc2_NewCustomInterface3_MyClass_CreateMyInterface_CreateEnumerator__vl_reflection_description_IValueEnumerator;
}

class IMyInterface3;
class MyClass;

class IMyInterface3 : public virtual ::vl::reflection::description::IValueEnumerable, public ::vl::reflection::Description<IMyInterface3>
{
#ifndef VCZH_DEBUG_NO_REFLECTION
	friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<IMyInterface3>;
#endif
public:
	virtual ::vl::vint32_t Get100() = 0;
};

class MyClass : public ::vl::Object, public ::vl::reflection::Description<MyClass>
{
#ifndef VCZH_DEBUG_NO_REFLECTION
	friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<MyClass>;
#endif
public:
	::vl::vint32_t begin = (- 1);
	::vl::vint32_t end = (- 1);
	MyClass(::vl::vint32_t _begin, ::vl::vint32_t _end);
	static ::vl::vint32_t Get50();
	::vl::Ptr<::IMyInterface3> CreateMyInterface();
};

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class NewCustomInterface3
	{
	public:

		::vl::WString main();

		static NewCustomInterface3& Instance();
	};
}

/***********************************************************************
Reflection
***********************************************************************/

namespace vl
{
	namespace reflection
	{
		namespace description
		{
#ifndef VCZH_DEBUG_NO_REFLECTION
			DECL_TYPE_INFO(::IMyInterface3)
			DECL_TYPE_INFO(::MyClass)

			BEGIN_INTERFACE_PROXY_SHAREDPTR(::IMyInterface3, ::vl::reflection::description::IValueEnumerable)
				::vl::vint32_t Get100() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(Get100);
				}
			END_INTERFACE_PROXY(::IMyInterface3)
#endif

			extern bool LoadNewCustomInterface3Types();
		}
	}
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif
