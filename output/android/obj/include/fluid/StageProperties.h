#ifndef INCLUDED_fluid_StageProperties
#define INCLUDED_fluid_StageProperties

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(fluid,StageProperties)
namespace fluid{


class HXCPP_CLASS_ATTRIBUTES  StageProperties_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StageProperties_obj OBJ_;
		StageProperties_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< StageProperties_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~StageProperties_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("StageProperties"); }

		static Float actualPixelRatio;
		static Float pixelRatio;
		static int screenWidth;
		static int screenHeight;
		static ::String orientation;
		static ::String LANDSCAPE;
		static ::String PORTRAIT;
};

} // end namespace fluid

#endif /* INCLUDED_fluid_StageProperties */ 
