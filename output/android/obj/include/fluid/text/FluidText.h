#ifndef INCLUDED_fluid_text_FluidText
#define INCLUDED_fluid_text_FluidText

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/text/TextField.h>
HX_DECLARE_CLASS2(fluid,text,FluidText)
HX_DECLARE_CLASS2(fluid,text,FluidTextFormat)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,text,TextField)
namespace fluid{
namespace text{


class HXCPP_CLASS_ATTRIBUTES  FluidText_obj : public ::openfl::_v2::text::TextField_obj{
	public:
		typedef ::openfl::_v2::text::TextField_obj super;
		typedef FluidText_obj OBJ_;
		FluidText_obj();
		Void __construct(::String txt,::fluid::text::FluidTextFormat format);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FluidText_obj > __new(::String txt,::fluid::text::FluidTextFormat format);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FluidText_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("FluidText"); }

		Float _anchorX;
		Float _anchorY;
		bool interactive;
		virtual bool set_interactive( bool val);
		Dynamic set_interactive_dyn();

		virtual Void setText( ::String value);
		Dynamic setText_dyn();

		virtual Void setFormat( ::fluid::text::FluidTextFormat format);
		Dynamic setFormat_dyn();

		virtual Void setAnchor( Dynamic ax,Dynamic ay);
		Dynamic setAnchor_dyn();

};

} // end namespace fluid
} // end namespace text

#endif /* INCLUDED_fluid_text_FluidText */ 
