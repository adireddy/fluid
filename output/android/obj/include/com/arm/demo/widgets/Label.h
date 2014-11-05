#ifndef INCLUDED_com_arm_demo_widgets_Label
#define INCLUDED_com_arm_demo_widgets_Label

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <fluid/display/FluidSprite.h>
HX_DECLARE_CLASS4(com,arm,demo,widgets,Label)
HX_DECLARE_CLASS2(fluid,display,FluidGraphics)
HX_DECLARE_CLASS2(fluid,display,FluidSprite)
HX_DECLARE_CLASS2(fluid,geom,FluidRectangle)
HX_DECLARE_CLASS2(fluid,text,FluidText)
HX_DECLARE_CLASS2(fluid,text,FluidTextFormat)
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


class HXCPP_CLASS_ATTRIBUTES  Label_obj : public ::fluid::display::FluidSprite_obj{
	public:
		typedef ::fluid::display::FluidSprite_obj super;
		typedef Label_obj OBJ_;
		Label_obj();
		Void __construct(::String label,Float width,Float height,Dynamic style);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Label_obj > __new(::String label,Float width,Float height,Dynamic style);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Label_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Label"); }

		::fluid::text::FluidText _label;
		::fluid::geom::FluidRectangle _rect;
		::fluid::display::FluidGraphics _background;
		::fluid::text::FluidTextFormat _format;
		virtual Void _setupBackground( Float width,Float height);
		Dynamic _setupBackground_dyn();

		virtual Void _setupLabel( Float width,Float height);
		Dynamic _setupLabel_dyn();

		virtual Void setText( ::String label);
		Dynamic setText_dyn();

		static int BACKGROUND_COLOUR;
		static int BORDER_COLOUR;
		static ::String TEXT_COLOUR;
		static int TEXT_SIZE;
		static int PADDING;
};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace widgets

#endif /* INCLUDED_com_arm_demo_widgets_Label */ 
