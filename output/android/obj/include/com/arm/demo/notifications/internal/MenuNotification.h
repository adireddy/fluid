#ifndef INCLUDED_com_arm_demo_notifications_internal_MenuNotification
#define INCLUDED_com_arm_demo_notifications_internal_MenuNotification

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,arm,demo,notifications,internal,MenuNotification)
HX_DECLARE_CLASS1(msignal,Signal)
HX_DECLARE_CLASS1(msignal,Signal0)
HX_DECLARE_CLASS1(msignal,Signal1)
namespace com{
namespace arm{
namespace demo{
namespace notifications{
namespace internal{


class HXCPP_CLASS_ATTRIBUTES  MenuNotification_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MenuNotification_obj OBJ_;
		MenuNotification_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MenuNotification_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MenuNotification_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("MenuNotification"); }

		static ::msignal::Signal1 click;
		static ::msignal::Signal0 reset;
};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace notifications
} // end namespace internal

#endif /* INCLUDED_com_arm_demo_notifications_internal_MenuNotification */ 
