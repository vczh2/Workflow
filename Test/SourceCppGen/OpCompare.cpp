/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/OpCompare.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "OpCompare.h"

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

#define GLOBAL_SYMBOL ::vl_workflow_global::OpCompare::
#define GLOBAL_NAME ::vl_workflow_global::OpCompare::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::OpCompare::Instance()
#define USERIMPL(...)

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_OpCompare)
	vl_workflow_global::OpCompare instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_OpCompare)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString OpCompare::main()
	{
		auto b = false;
		auto i8 = static_cast<::vl::vint8_t>(1);
		auto i16 = static_cast<::vl::vint16_t>(2);
		auto i32 = 4;
		auto i64 = static_cast<::vl::vint64_t>(8);
		auto u8 = static_cast<::vl::vuint8_t>(1);
		auto u16 = static_cast<::vl::vuint16_t>(2);
		auto u32 = static_cast<::vl::vuint32_t>(4);
		auto u64 = static_cast<::vl::vuint64_t>(8);
		auto f32 = static_cast<float>(1.5);
		auto f64 = static_cast<double>(3);
		auto s = ::vl::WString(L"text", false);
		auto p0 = [&](){ ::test::Point __vwsn_temp__; __vwsn_temp__.x = 0; return __vwsn_temp__; }();
		auto p1 = [&](){ ::test::Point __vwsn_temp__; __vwsn_temp__.y = 0; return __vwsn_temp__; }();
		auto p2 = [&](){ ::test::Point __vwsn_temp__; __vwsn_temp__.y = 0; __vwsn_temp__.x = 0; return __vwsn_temp__; }();
		auto p3 = ::test::Point{};
		auto p4 = [&](){ ::test::Point __vwsn_temp__; __vwsn_temp__.x = 1; __vwsn_temp__.y = 1; return __vwsn_temp__; }();
		auto q1 = ::vl::Nullable<::test::Point>(p2);
		auto q2 = ::vl::Nullable<::test::Point>(p4);
		auto q3 = ::vl::Nullable<::test::Point>();
		auto e1 = ::vl::Nullable<::MyEnum>();
		auto e2 = ::vl::Nullable<::MyEnum>::Item;
		return ((((((((((((((((((((((::vl::__vwsn::ToString((static_cast<::vl::vint16_t>(i8) < i16)) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((static_cast<::vl::vint32_t>(i16) > i32))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((static_cast<::vl::vint64_t>(i32) == i64))) + ::vl::WString(L", ", false)) + ((((::vl::__vwsn::ToString((static_cast<::vl::vuint16_t>(u8) <= u16)) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((static_cast<::vl::vuint32_t>(u16) >= u32))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((static_cast<::vl::vuint64_t>(u32) != u64)))) + ::vl::WString(L", ", false)) + ((((::vl::__vwsn::ToString((static_cast<double>(f32) < f64)) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((static_cast<double>(f32) > f64))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((static_cast<double>(f32) == f64)))) + ::vl::WString(L", ", false)) + ((::vl::__vwsn::ToString((b == true)) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((b != false)))) + ::vl::WString(L", ", false)) + ((::vl::__vwsn::ToString((s == ::vl::WString(L"string", false))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((s != ::vl::WString(L"string", false))))) + ::vl::WString(L", ", false)) + ((((((::vl::__vwsn::ToString((p0 == p1)) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((p1 == p2))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((p2 == p3))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((p3 == p4)))) + ::vl::WString(L", ", false)) + ((((::vl::__vwsn::ToString((q1 == q3)) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((q2 == q3))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((q3 == q3)))) + ::vl::WString(L", ", false)) + ((((::vl::__vwsn::ToString((q1 == ::vl::Nullable<::test::Point>(p2))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((q2 == ::vl::Nullable<::test::Point>(p2)))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((q3 == ::vl::Nullable<::test::Point>(p2))))) + ::vl::WString(L", ", false)) + ((((::vl::__vwsn::ToString((q1 == ::vl::Nullable<::test::Point>(p4))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((q2 == ::vl::Nullable<::test::Point>(p4)))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((q3 == ::vl::Nullable<::test::Point>(p4))))) + ::vl::WString(L", ", false)) + ((::vl::__vwsn::ToString((e1 == ::vl::Nullable<::MyEnum>(::MyEnum::Item))) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString((e2 == ::vl::Nullable<::MyEnum>(::MyEnum::Item)))));
	}

	OpCompare& OpCompare::Instance()
	{
		return Getvl_workflow_global_OpCompare().instance;
	}
}

#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ
#undef USERIMPL

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
			IMPL_CPP_TYPE_INFO(MyEnum)

#define _ ,
			BEGIN_ENUM_ITEM(::MyEnum)
				ENUM_CLASS_ITEM(Item)
			END_ENUM_ITEM(::MyEnum)

#undef _
			class OpCompareTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::MyEnum)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif

			bool LoadOpCompareTypes()
			{
#ifndef VCZH_DEBUG_NO_REFLECTION
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(MakePtr<OpCompareTypeLoader>());
				}
#endif
				return false;
			}
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
