#ifndef INCLUDED_com_arm_demo_notifications_internal_ViewStateNotification
#define INCLUDED_com_arm_demo_notifications_internal_ViewStateNotification

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(com,arm,demo,notifications,internal,ViewStateNotification)
HX_DECLARE_CLASS1(msignal,Signal)
HX_DECLARE_CLASS1(msignal,Signal0)
HX_DECLARE_CLASS1(msignal,Signal1)
namespace com{
namespace arm{
namespace demo{
namespace notifications{
namespace internal{


class HXCPP_CLASS_ATTRIBUTES  ViewStateNotification_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ViewStateNotification_obj OBJ_;
		ViewStateNotification_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ViewStateNotification_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ViewStateNotification_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("ViewStateNotification"); }

		static ::msignal::Signal0 preloader;
		static ::msignal::Signal0 preloaderProgress;
		static ::msignal::Signal0 preload;
		static ::msignal::Signal0 create;
		static ::msignal::Signal1 update;
		static ::msignal::Signal0 destroy;
		static ::msignal::Signal0 resize;
		static Void reset( );
		static Dynamic reset_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace notifications
} // end namespace internal

#endif /* INCLUDED_com_arm_demo_notifications_internal_ViewStateNotification */ 
