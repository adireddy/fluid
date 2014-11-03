#ifndef INCLUDED_fluid_Fluid
#define INCLUDED_fluid_Fluid

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Sprite.h>
HX_DECLARE_CLASS0(Date)
HX_DECLARE_CLASS1(fluid,Fluid)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,Event)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,MouseEvent)
HX_DECLARE_CLASS3(openfl,_v2,events,TouchEvent)
HX_DECLARE_CLASS3(openfl,_v2,text,TextField)
HX_DECLARE_CLASS2(openfl,display,FPS)
namespace fluid{


class HXCPP_CLASS_ATTRIBUTES  Fluid_obj : public ::openfl::_v2::display::Sprite_obj{
	public:
		typedef ::openfl::_v2::display::Sprite_obj super;
		typedef Fluid_obj OBJ_;
		Fluid_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Fluid_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Fluid_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Fluid"); }

		Dynamic _canvas;
		Dynamic _renderer;
		::Date _lastTime;
		::Date _currentTime;
		Dynamic mouseDown;
		Dynamic &mouseDown_dyn() { return mouseDown;}
		Dynamic mouseOut;
		Dynamic &mouseOut_dyn() { return mouseOut;}
		Dynamic mouseOver;
		Dynamic &mouseOver_dyn() { return mouseOver;}
		Dynamic mouseUp;
		Dynamic &mouseUp_dyn() { return mouseUp;}
		Dynamic click;
		Dynamic &click_dyn() { return click;}
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
		Float elapsedTime;
		bool skipFrame;
		bool _fluidFrameSkip;
		::openfl::_v2::display::Sprite container;
		::openfl::display::FPS _stats;
		virtual Void _setStageProperties( );
		Dynamic _setStageProperties_dyn();

		virtual Void _fluidOnMouseDown( ::openfl::_v2::events::MouseEvent evt);
		Dynamic _fluidOnMouseDown_dyn();

		virtual Void _fluidOnMouseOver( ::openfl::_v2::events::MouseEvent evt);
		Dynamic _fluidOnMouseOver_dyn();

		virtual Void _fluidOnMouseOut( ::openfl::_v2::events::MouseEvent evt);
		Dynamic _fluidOnMouseOut_dyn();

		virtual Void _fluidOnMouseUp( ::openfl::_v2::events::MouseEvent evt);
		Dynamic _fluidOnMouseUp_dyn();

		virtual Void _fluidOnMouseClick( ::openfl::_v2::events::MouseEvent evt);
		Dynamic _fluidOnMouseClick_dyn();

		virtual Void _fluidOnRightClick( ::openfl::_v2::events::MouseEvent evt);
		Dynamic _fluidOnRightClick_dyn();

		virtual Void _fluidOnRightMouseDown( ::openfl::_v2::events::MouseEvent evt);
		Dynamic _fluidOnRightMouseDown_dyn();

		virtual Void _fluidOnRightMouseUp( ::openfl::_v2::events::MouseEvent evt);
		Dynamic _fluidOnRightMouseUp_dyn();

		virtual Void _fluidOnTouchBegin( ::openfl::_v2::events::TouchEvent evt);
		Dynamic _fluidOnTouchBegin_dyn();

		virtual Void _fluidOnTouchEnd( ::openfl::_v2::events::TouchEvent evt);
		Dynamic _fluidOnTouchEnd_dyn();

		virtual Void _fluidOnTouchOut( ::openfl::_v2::events::TouchEvent evt);
		Dynamic _fluidOnTouchOut_dyn();

		virtual Void _fluidOnEnterFrame( Dynamic evt);
		Dynamic _fluidOnEnterFrame_dyn();

		virtual Void _fluidOnUpdate( );
		Dynamic _fluidOnUpdate_dyn();

		virtual Void _fluidCalculateElapsedTime( );
		Dynamic _fluidCalculateElapsedTime_dyn();

		virtual Void _fluidOnResize( Dynamic event);
		Dynamic _fluidOnResize_dyn();

		virtual Void _update( Float elapsed);
		Dynamic _update_dyn();

		virtual Void _resize( );
		Dynamic _resize_dyn();

		virtual Void _showStats( );
		Dynamic _showStats_dyn();

};

} // end namespace fluid

#endif /* INCLUDED_fluid_Fluid */ 
