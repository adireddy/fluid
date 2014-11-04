#ifndef INCLUDED_fluid_display_FluidStage
#define INCLUDED_fluid_display_FluidStage

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Stage.h>
HX_DECLARE_CLASS2(fluid,display,FluidStage)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Stage)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
namespace fluid{
namespace display{


class HXCPP_CLASS_ATTRIBUTES  FluidStage_obj : public ::openfl::_v2::display::Stage_obj{
	public:
		typedef ::openfl::_v2::display::Stage_obj super;
		typedef FluidStage_obj OBJ_;
		FluidStage_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FluidStage_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FluidStage_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("FluidStage"); }

		static Float actualPixelRatio;
		static Float pixelRatio;
		static int screenWidth;
		static int screenHeight;
		static ::String orientation;
		static ::String LANDSCAPE;
		static ::String PORTRAIT;
};

} // end namespace fluid
} // end namespace display

#endif /* INCLUDED_fluid_display_FluidStage */ 
