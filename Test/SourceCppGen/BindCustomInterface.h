/***********************************************************************
Generated from ../Resources/Codegen/BindCustomInterface.txt
***********************************************************************/

#ifndef VCZH_WORKFLOW_CPP_GENERATED_BINDCUSTOMINTERFACE
#define VCZH_WORKFLOW_CPP_GENERATED_BINDCUSTOMINTERFACE

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
class ISummer;
class IAdder;

class ISummer : public virtual ::vl::reflection::IDescriptable, public ::vl::reflection::Description<ISummer>
{
public:

	virtual ::vl::vint32_t GetSum() = 0;
	::vl::Event<void()> SumChanged;
};

class IAdder : public virtual ::ISummer, public ::vl::reflection::Description<IAdder>
{
public:

	virtual void Add(::vl::vint32_t value) = 0;
};
#pragma warning(pop)

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class BindCustomInterface
	{
	public:

		::vl::WString s;

		::vl::Ptr<::vl::reflection::description::IValueSubscription> Bind(::vl::Ptr<::ISummer> summer);
		void Execute(::vl::Ptr<::IAdder> adder);
		::vl::WString main();

		static BindCustomInterface& Instance();
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
			DECL_TYPE_INFO(::IAdder)
			DECL_TYPE_INFO(::ISummer)
#endif

			extern bool LoadBindCustomInterfaceTypes();
		}
	}
}

#endif
