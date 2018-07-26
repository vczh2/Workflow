/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/WorkflowMultiFiles.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_WORKFLOWMULTIFILES_DP1
#define VCZH_WORKFLOW_COMPILER_GENERATED_WORKFLOWMULTIFILES_DP1

#include "WorkflowMultiFiles.h"
#include "WorkflowMultiFiles1.h"
#include "WorkflowMultiFiles_Animal.h"

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

namespace multifiles
{
	class Cat : public ::multifiles::Animal, public ::vl::reflection::Description<Cat>
	{
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<Cat>;
#endif
	public:
		Cat();
	};

	class Dog : public ::multifiles::Animal, public ::vl::reflection::Description<Dog>
	{
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<Dog>;
#endif
	public:
		Dog();
	};

	class BadDog : public ::multifiles::Dog, public ::vl::reflection::Description<BadDog>
	{
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<BadDog>;
#endif
	public:
		BadDog();
	};

	class GoodDog : public ::multifiles::Dog, public ::vl::reflection::Description<GoodDog>
	{
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<GoodDog>;
#endif
	public:
		GoodDog();
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
