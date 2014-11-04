#ifndef INCLUDED_com_arm_demo_Application
#define INCLUDED_com_arm_demo_Application

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <fluid/Fluid.h>
HX_DECLARE_CLASS3(com,arm,demo,Application)
HX_DECLARE_CLASS4(com,arm,demo,comms,DemoCommsController)
HX_DECLARE_CLASS4(com,arm,demo,controller,DemoController)
HX_DECLARE_CLASS4(com,arm,demo,model,DemoModel)
HX_DECLARE_CLASS4(com,arm,demo,view,DemoView)
HX_DECLARE_CLASS1(fluid,Fluid)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
namespace com{
namespace arm{
namespace demo{


class HXCPP_CLASS_ATTRIBUTES  Application_obj : public ::fluid::Fluid_obj{
	public:
		typedef ::fluid::Fluid_obj super;
		typedef Application_obj OBJ_;
		Application_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Application_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Application_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Application"); }

		::com::arm::demo::model::DemoModel model;
		::com::arm::demo::view::DemoView view;
		::com::arm::demo::controller::DemoController controller;
		::com::arm::demo::comms::DemoCommsController comms;
};

} // end namespace com
} // end namespace arm
} // end namespace demo

#endif /* INCLUDED_com_arm_demo_Application */ 
