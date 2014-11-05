#ifndef INCLUDED_com_arm_demo_Main
#define INCLUDED_com_arm_demo_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/arm/demo/Application.h>
HX_DECLARE_CLASS3(com,arm,demo,Application)
HX_DECLARE_CLASS3(com,arm,demo,Main)
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


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public ::com::arm::demo::Application_obj{
	public:
		typedef ::com::arm::demo::Application_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Main"); }

		virtual Void _setupMVCS( );
		Dynamic _setupMVCS_dyn();

		virtual Void _onUpdate( Float time);
		Dynamic _onUpdate_dyn();

		virtual Void _onResize( );
		Dynamic _onResize_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo

#endif /* INCLUDED_com_arm_demo_Main */ 
