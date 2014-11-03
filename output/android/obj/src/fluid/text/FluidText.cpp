#include <hxcpp.h>

#ifndef INCLUDED_fluid_text_FluidText
#include <fluid/text/FluidText.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextField
#include <openfl/_v2/text/TextField.h>
#endif
namespace fluid{
namespace text{

Void FluidText_obj::__construct(::String txt)
{
HX_STACK_FRAME("fluid.text.FluidText","new",0x1a16fc8c,"fluid.text.FluidText.new","fluid/text/FluidText.hx",5,0x3b8f44c4)
HX_STACK_THIS(this)
HX_STACK_ARG(txt,"txt")
{
	HX_STACK_LINE(6)
	super::__construct();
	HX_STACK_LINE(7)
	this->set_text(txt);
}
;
	return null();
}

//FluidText_obj::~FluidText_obj() { }

Dynamic FluidText_obj::__CreateEmpty() { return  new FluidText_obj; }
hx::ObjectPtr< FluidText_obj > FluidText_obj::__new(::String txt)
{  hx::ObjectPtr< FluidText_obj > result = new FluidText_obj();
	result->__construct(txt);
	return result;}

Dynamic FluidText_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FluidText_obj > result = new FluidText_obj();
	result->__construct(inArgs[0]);
	return result;}

Void FluidText_obj::setText( ::String value){
{
		HX_STACK_FRAME("fluid.text.FluidText","setText",0xc0e8bf9b,"fluid.text.FluidText.setText","fluid/text/FluidText.hx",12,0x3b8f44c4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(12)
		this->set_text(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidText_obj,setText,(void))


FluidText_obj::FluidText_obj()
{
}

Dynamic FluidText_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"setText") ) { return setText_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FluidText_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FluidText_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("setText"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FluidText_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FluidText_obj::__mClass,"__mClass");
};

#endif

Class FluidText_obj::__mClass;

void FluidText_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.text.FluidText"), hx::TCanCast< FluidText_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void FluidText_obj::__boot()
{
}

} // end namespace fluid
} // end namespace text
