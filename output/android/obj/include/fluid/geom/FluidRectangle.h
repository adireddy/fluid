#ifndef INCLUDED_fluid_geom_FluidRectangle
#define INCLUDED_fluid_geom_FluidRectangle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/geom/Rectangle.h>
HX_DECLARE_CLASS2(fluid,geom,FluidRectangle)
HX_DECLARE_CLASS3(openfl,_v2,geom,Rectangle)
namespace fluid{
namespace geom{


class HXCPP_CLASS_ATTRIBUTES  FluidRectangle_obj : public ::openfl::_v2::geom::Rectangle_obj{
	public:
		typedef ::openfl::_v2::geom::Rectangle_obj super;
		typedef FluidRectangle_obj OBJ_;
		FluidRectangle_obj();
		Void __construct(Float x,Float y,Float width,Float height);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FluidRectangle_obj > __new(Float x,Float y,Float width,Float height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FluidRectangle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("FluidRectangle"); }

};

} // end namespace fluid
} // end namespace geom

#endif /* INCLUDED_fluid_geom_FluidRectangle */ 
