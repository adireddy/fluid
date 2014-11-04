#ifndef INCLUDED_com_arm_demo_widgets_Button
#define INCLUDED_com_arm_demo_widgets_Button

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <fluid/display/FluidSprite.h>
HX_DECLARE_CLASS4(com,arm,demo,widgets,Button)
HX_DECLARE_CLASS2(fluid,display,FluidGraphics)
HX_DECLARE_CLASS2(fluid,display,FluidSprite)
HX_DECLARE_CLASS2(fluid,events,EventData)
HX_DECLARE_CLASS2(fluid,geom,FluidRectangle)
HX_DECLARE_CLASS2(fluid,text,FluidText)
HX_DECLARE_CLASS1(msignal,Signal)
HX_DECLARE_CLASS1(msignal,Signal1)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,geom,Rectangle)
HX_DECLARE_CLASS3(openfl,_v2,text,TextField)
namespace com{
namespace arm{
namespace demo{
namespace widgets{


class HXCPP_CLASS_ATTRIBUTES  Button_obj : public ::fluid::display::FluidSprite_obj{
	public:
		typedef ::fluid::display::FluidSprite_obj super;
		typedef Button_obj OBJ_;
		Button_obj();
		Void __construct(::String label,Float width,Float height,Dynamic data,Dynamic fontSize);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Button_obj > __new(::String label,Float width,Float height,Dynamic data,Dynamic fontSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Button_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Button"); }

		Dynamic _data;
		::fluid::text::FluidText _label;
		::fluid::geom::FluidRectangle _rect;
		::fluid::display::FluidGraphics _background;
		bool _enabled;
		::msignal::Signal1 action;
		virtual Void _setupBackground( Float width,Float height);
		Dynamic _setupBackground_dyn();

		virtual Void _setupLabel( Float width,Float height,Dynamic fontSize);
		Dynamic _setupLabel_dyn();

		virtual Void _redraw( int colour);
		Dynamic _redraw_dyn();

		virtual Void setText( ::String label);
		Dynamic setText_dyn();

		virtual Void _onMouseDown( Dynamic data);
		Dynamic _onMouseDown_dyn();

		virtual Void _onMouseUp( ::fluid::events::EventData data);
		Dynamic _onMouseUp_dyn();

		virtual Void _onMouseUpOutside( Dynamic data);
		Dynamic _onMouseUpOutside_dyn();

		virtual Void _onMouseOver( ::fluid::events::EventData data);
		Dynamic _onMouseOver_dyn();

		virtual Void _onMouseOut( ::fluid::events::EventData data);
		Dynamic _onMouseOut_dyn();

		virtual Void _onTouchEndOutside( ::fluid::events::EventData data);
		Dynamic _onTouchEndOutside_dyn();

		virtual Void _onTouchEnd( ::fluid::events::EventData data);
		Dynamic _onTouchEnd_dyn();

		virtual Void _onTouchStart( ::fluid::events::EventData data);
		Dynamic _onTouchStart_dyn();

		virtual Void enable( );
		Dynamic enable_dyn();

		virtual Void disable( );
		Dynamic disable_dyn();

		static int OVER_COLOUR;
		static int OUT_COLOUR;
		static ::String TEXT_COLOUR;
};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace widgets

#endif /* INCLUDED_com_arm_demo_widgets_Button */ 
