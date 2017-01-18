/***********************************************************************
Generated from ../Resources/Codegen/ClassMethod.txt
***********************************************************************/

#ifndef VCZH_WORKFLOW_CPP_GENERATED_CLASSMETHOD
#define VCZH_WORKFLOW_CPP_GENERATED_CLASSMETHOD

#include "../Source/CppTypes.h"

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

#pragma warning(push)
#pragma warning(disable:4250)
class Methods;

class Methods : public ::vl::Object, public ::vl::reflection::Description<Methods>
{
public:

	::vl::vint32_t x = 0;
	Methods();
	Methods(::vl::vint32_t _x);
	::vl::vint32_t GetX();
	void SetX(::vl::vint32_t _x);
	::vl::Event<void()> XChanged;
};
#pragma warning(pop)

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class ClassMethod
	{
	public:

		::vl::WString s;

		::vl::WString main();

		static ClassMethod& Instance();
	};
}

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

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
			DECL_TYPE_INFO(::Methods)
#endif

			extern bool LoadClassMethodTypes();
		}
	}
}

#endif
