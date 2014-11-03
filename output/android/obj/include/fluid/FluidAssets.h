#ifndef INCLUDED_fluid_FluidAssets
#define INCLUDED_fluid_FluidAssets

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(fluid,FluidAssets)
HX_DECLARE_CLASS3(openfl,_v2,display,BitmapData)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
namespace fluid{


class HXCPP_CLASS_ATTRIBUTES  FluidAssets_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FluidAssets_obj OBJ_;
		FluidAssets_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FluidAssets_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FluidAssets_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("FluidAssets"); }

		static ::openfl::_v2::display::BitmapData getImage( ::String url);
		static Dynamic getImage_dyn();

};

} // end namespace fluid

#endif /* INCLUDED_fluid_FluidAssets */ 
