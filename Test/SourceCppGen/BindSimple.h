/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/BindSimple.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_BINDSIMPLE
#define VCZH_WORKFLOW_COMPILER_GENERATED_BINDSIMPLE

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
	struct __vwsnf1_BindSimple_OuterClass_Base_Initialize_;
	class __vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription;
	class __vwsnc2_BindSimple_OuterClass_Base_Initialize_Subscribe__vl_reflection_description_IValueListener;
}

class OuterClass;
class Derived;

class OuterClass : public ::vl::Object, public ::vl::reflection::Description<OuterClass>
{
	friend class ::vl_workflow_global::__vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription;
	friend class ::vl_workflow_global::__vwsnc2_BindSimple_OuterClass_Base_Initialize_Subscribe__vl_reflection_description_IValueListener;
	friend struct ::vl_workflow_global::__vwsnf1_BindSimple_OuterClass_Base_Initialize_;
#ifndef VCZH_DEBUG_NO_REFLECTION
	friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<OuterClass>;
#endif
public:
	class Base;

	class Base : public ::vl::Object, public ::vl::reflection::Description<Base>
	{
		friend class ::vl_workflow_global::__vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc2_BindSimple_OuterClass_Base_Initialize_Subscribe__vl_reflection_description_IValueListener;
		friend struct ::vl_workflow_global::__vwsnf1_BindSimple_OuterClass_Base_Initialize_;
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<Base>;
#endif
	public:
		::vl::Ptr<::vl::reflection::description::IValueSubscription> subscription = ::vl::Ptr<::vl::reflection::description::IValueSubscription>();
		::vl::WString s = ::vl::WString(L"", false);
		void Initialize(::Derived* derived);
		Base();
	};
	OuterClass();
};

class Derived : public ::OuterClass::Base, public ::vl::reflection::Description<Derived>
{
	friend class ::OuterClass;
	friend class ::OuterClass::Base;
	friend class ::vl_workflow_global::__vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription;
	friend class ::vl_workflow_global::__vwsnc2_BindSimple_OuterClass_Base_Initialize_Subscribe__vl_reflection_description_IValueListener;
	friend struct ::vl_workflow_global::__vwsnf1_BindSimple_OuterClass_Base_Initialize_;
#ifndef VCZH_DEBUG_NO_REFLECTION
	friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<Derived>;
#endif
protected:
	::vl::Ptr<::test::ObservableValue> x = ::vl::Ptr<::test::ObservableValue>(new ::test::ObservableValue());
	::vl::Ptr<::test::ObservableValue> y = ::vl::Ptr<::test::ObservableValue>(new ::test::ObservableValue());
	::vl::Ptr<::test::ObservableValue> z = ::vl::Ptr<::test::ObservableValue>(new ::test::ObservableValue());
public:
	Derived();
	void Execute();
};

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class BindSimple
	{
	public:

		::vl::WString main();

		static BindSimple& Instance();
	};

/***********************************************************************
Closures
***********************************************************************/

	struct __vwsnf1_BindSimple_OuterClass_Base_Initialize_
	{
		::OuterClass::Base* __vwsnthis_0;

		__vwsnf1_BindSimple_OuterClass_Base_Initialize_(::OuterClass::Base* __vwsnctorthis_0);

		void operator()(const ::vl::reflection::description::Value& value) const;
	};

	class __vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription : public ::vl::Object, public virtual ::vl::reflection::description::IValueSubscription
	{
	public:
		::Derived* derived;
		::OuterClass::Base* __vwsnthis_0;

		__vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription(::Derived* __vwsnctor_derived, ::OuterClass::Base* __vwsnctorthis_0);

		::vl::Ptr<::test::ObservableValue> __vwsn_bind_cache_0;
		::vl::Ptr<::vl::reflection::description::IEventHandler> __vwsn_bind_handler_0_0;
		::vl::Ptr<::test::ObservableValue> __vwsn_bind_cache_1;
		::vl::Ptr<::vl::reflection::description::IEventHandler> __vwsn_bind_handler_1_0;
		::vl::Ptr<::test::ObservableValue> __vwsn_bind_cache_2;
		::vl::Ptr<::vl::reflection::description::IEventHandler> __vwsn_bind_handler_2_0;
		bool __vwsn_bind_opened_ = false;
		bool __vwsn_bind_closed_ = false;
		::vl::Ptr<::vl::reflection::description::IValueDictionary> __vwsn_bind_listeners_;
		void __vwsn_bind_activator_();
		void __vwsn_bind_callback_0_0(::vl::vint32_t __vwsn_bind_callback_argument_0, ::vl::vint32_t __vwsn_bind_callback_argument_1);
		void __vwsn_bind_callback_1_0(::vl::vint32_t __vwsn_bind_callback_argument_0, ::vl::vint32_t __vwsn_bind_callback_argument_1);
		void __vwsn_bind_callback_2_0(::vl::vint32_t __vwsn_bind_callback_argument_0, ::vl::vint32_t __vwsn_bind_callback_argument_1);
		void __vwsn_bind_initialize_();
		::vl::Ptr<::vl::reflection::description::IValueListener> Subscribe(const ::vl::Func<void(const ::vl::reflection::description::Value&)>& __vwsn_bind_callback_) override;
		bool Update() override;
		bool Close() override;
	};

	class __vwsnc2_BindSimple_OuterClass_Base_Initialize_Subscribe__vl_reflection_description_IValueListener : public ::vl::Object, public virtual ::vl::reflection::description::IValueListener
	{
	public:
		::vl::Ptr<::vl::reflection::description::IValueDictionary> __vwsn_bind_listeners_;
		::vl::reflection::description::IValueSubscription* __vwsn_subscription_;
		::vl::reflection::description::IValueSubscription* __vwsnthis_0;
		::OuterClass::Base* __vwsnthis_1;

		__vwsnc2_BindSimple_OuterClass_Base_Initialize_Subscribe__vl_reflection_description_IValueListener(::vl::Ptr<::vl::reflection::description::IValueDictionary> __vwsnctor___vwsn_bind_listeners_, ::vl::reflection::description::IValueSubscription* __vwsnctor___vwsn_subscription_, ::vl::reflection::description::IValueSubscription* __vwsnctorthis_0, ::OuterClass::Base* __vwsnctorthis_1);

		::vl::reflection::description::IValueSubscription* GetSubscription() override;
		bool GetStopped() override;
		bool StopListening() override;
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
			DECL_TYPE_INFO(::Derived)
			DECL_TYPE_INFO(::OuterClass)
			DECL_TYPE_INFO(::OuterClass::Base)
#endif

			extern bool LoadBindSimpleTypes();
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
