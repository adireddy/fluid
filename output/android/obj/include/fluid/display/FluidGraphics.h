#ifndef INCLUDED_fluid_display_FluidGraphics
#define INCLUDED_fluid_display_FluidGraphics

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Shape.h>
HX_DECLARE_CLASS2(fluid,display,FluidGraphics)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,Shape)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
namespace fluid{
namespace display{


class HXCPP_CLASS_ATTRIBUTES  FluidGraphics_obj : public ::openfl::_v2::display::Shape_obj{
	public:
		typedef ::openfl::_v2::display::Shape_obj super;
		typedef FluidGraphics_obj OBJ_;
		FluidGraphics_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FluidGraphics_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FluidGraphics_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("FluidGraphics"); }

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void beginFill( int fill,Dynamic alpha);
		Dynamic beginFill_dyn();

		virtual Void endFill( );
		Dynamic endFill_dyn();

		virtual Void drawRect( Float x,Float y,Float w,Float h);
		Dynamic drawRect_dyn();

		virtual Void drawCircle( Float x,Float y,Float r);
		Dynamic drawCircle_dyn();

		virtual Void drawEllipse( Float x,Float y,Float w,Float h);
		Dynamic drawEllipse_dyn();

		virtual Void drawRoundedRect( Float x,Float y,Float w,Float h,Float r);
		Dynamic drawRoundedRect_dyn();

};

} // end namespace fluid
} // end namespace display

#endif /* INCLUDED_fluid_display_FluidGraphics */ 
