#ifndef INCLUDED_fluid_text_FluidTextFormat
#define INCLUDED_fluid_text_FluidTextFormat

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(fluid,text,FluidTextFormat)
namespace fluid{
namespace text{


class HXCPP_CLASS_ATTRIBUTES  FluidTextFormat_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FluidTextFormat_obj OBJ_;
		FluidTextFormat_obj();
		Void __construct(::String font,Dynamic size,::String fill,Dynamic bold,Dynamic italic,Dynamic underline,::String align);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FluidTextFormat_obj > __new(::String font,Dynamic size,::String fill,Dynamic bold,Dynamic italic,Dynamic underline,::String align);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FluidTextFormat_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FluidTextFormat"); }

		bool bold;
		bool italic;
		bool underline;
		Float size;
		::String font;
		::String fill;
		::String align;
};

} // end namespace fluid
} // end namespace text

#endif /* INCLUDED_fluid_text_FluidTextFormat */ 
