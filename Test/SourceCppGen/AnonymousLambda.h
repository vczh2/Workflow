/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/AnonymousLambda.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_ANONYMOUSLAMBDA
#define VCZH_WORKFLOW_COMPILER_GENERATED_ANONYMOUSLAMBDA

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
	struct __vwsnf1_AnonymousLambda_Adder_;
	struct __vwsnf2_AnonymousLambda_Adder__;
}

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class AnonymousLambda
	{
	public:

		::vl::Func<::vl::Func<::vl::vint32_t()>(::vl::vint32_t)> Adder(::vl::vint32_t x);
		::vl::WString main();

		static AnonymousLambda& Instance();
	};

/***********************************************************************
Closures
***********************************************************************/

	struct __vwsnf1_AnonymousLambda_Adder_
	{
		::vl::vint32_t x;

		__vwsnf1_AnonymousLambda_Adder_(::vl::vint32_t __vwsnctor_x);

		::vl::Func<::vl::vint32_t()> operator()(::vl::vint32_t y) const;
	};

	struct __vwsnf2_AnonymousLambda_Adder__
	{
		::vl::vint32_t x;
		::vl::vint32_t y;

		__vwsnf2_AnonymousLambda_Adder__(::vl::vint32_t __vwsnctor_x, ::vl::vint32_t __vwsnctor_y);

		::vl::vint32_t operator()() const;
	};
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif
