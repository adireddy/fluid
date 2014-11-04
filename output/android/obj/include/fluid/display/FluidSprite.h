#ifndef INCLUDED_fluid_display_FluidSprite
#define INCLUDED_fluid_display_FluidSprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Sprite.h>
HX_DECLARE_CLASS2(fluid,display,FluidSprite)
HX_DECLARE_CLASS2(fluid,events,EventData)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,BitmapData)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
namespace fluid{
namespace display{


class HXCPP_CLASS_ATTRIBUTES  FluidSprite_obj : public ::openfl::_v2::display::Sprite_obj{
	public:
		typedef ::openfl::_v2::display::Sprite_obj super;
		typedef FluidSprite_obj OBJ_;
		FluidSprite_obj();
		Void __construct(::openfl::_v2::display::BitmapData texture);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FluidSprite_obj > __new(::openfl::_v2::display::BitmapData texture);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FluidSprite_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FluidSprite"); }

		::openfl::_v2::display::Bitmap _texture;
		Dynamic mouseDown;
		Dynamic &mouseDown_dyn() { return mouseDown;}
		Dynamic mouseOut;
		Dynamic &mouseOut_dyn() { return mouseOut;}
		Dynamic mouseOver;
		Dynamic &mouseOver_dyn() { return mouseOver;}
		Dynamic mouseUp;
		Dynamic &mouseUp_dyn() { return mouseUp;}
		Dynamic mouseMove;
		Dynamic &mouseMove_dyn() { return mouseMove;}
		Dynamic mouseClick;
		Dynamic &mouseClick_dyn() { return mouseClick;}
		Dynamic rightClick;
		Dynamic &rightClick_dyn() { return rightClick;}
		Dynamic rightMouseDown;
		Dynamic &rightMouseDown_dyn() { return rightMouseDown;}
		Dynamic rightMouseUp;
		Dynamic &rightMouseUp_dyn() { return rightMouseUp;}
		Dynamic touchBegin;
		Dynamic &touchBegin_dyn() { return touchBegin;}
		Dynamic touchEnd;
		Dynamic &touchEnd_dyn() { return touchEnd;}
		Dynamic touchOut;
		Dynamic &touchOut_dyn() { return touchOut;}
		Dynamic touchMove;
		Dynamic &touchMove_dyn() { return touchMove;}
		bool interactive;
		virtual bool set_interactive( bool val);
		Dynamic set_interactive_dyn();

		virtual Void _fluidOnMouseDown( Dynamic evt);
		Dynamic _fluidOnMouseDown_dyn();

		virtual Void _fluidOnMouseOver( Dynamic evt);
		Dynamic _fluidOnMouseOver_dyn();

		virtual Void _fluidOnMouseOut( Dynamic evt);
		Dynamic _fluidOnMouseOut_dyn();

		virtual Void _fluidOnMouseUp( Dynamic evt);
		Dynamic _fluidOnMouseUp_dyn();

		virtual Void _fluidOnMouseMove( Dynamic evt);
		Dynamic _fluidOnMouseMove_dyn();

		virtual Void _fluidOnMouseClick( Dynamic evt);
		Dynamic _fluidOnMouseClick_dyn();

		virtual Void _fluidOnRightClick( Dynamic evt);
		Dynamic _fluidOnRightClick_dyn();

		virtual Void _fluidOnRightMouseDown( Dynamic evt);
		Dynamic _fluidOnRightMouseDown_dyn();

		virtual Void _fluidOnRightMouseUp( Dynamic evt);
		Dynamic _fluidOnRightMouseUp_dyn();

		virtual Void _fluidOnTouchBegin( Dynamic evt);
		Dynamic _fluidOnTouchBegin_dyn();

		virtual Void _fluidOnTouchEnd( Dynamic evt);
		Dynamic _fluidOnTouchEnd_dyn();

		virtual Void _fluidOnTouchOut( Dynamic evt);
		Dynamic _fluidOnTouchOut_dyn();

		virtual Void _fluidOnTouchMove( Dynamic evt);
		Dynamic _fluidOnTouchMove_dyn();

		virtual ::fluid::events::EventData _prepareEventData( Dynamic data);
		Dynamic _prepareEventData_dyn();

};

} // end namespace fluid
} // end namespace display

#endif /* INCLUDED_fluid_display_FluidSprite */ 
