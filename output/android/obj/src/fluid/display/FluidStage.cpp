#include <hxcpp.h>

#ifndef INCLUDED_fluid_display_FluidStage
#include <fluid/display/FluidStage.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Stage
#include <openfl/_v2/display/Stage.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
namespace fluid{
namespace display{

Void FluidStage_obj::__construct()
{
HX_STACK_FRAME("fluid.display.FluidStage","new",0xdc87e9f6,"fluid.display.FluidStage.new","fluid/display/FluidStage.hx",16,0xc43da3f8)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(16)
	super::__construct(null(),::fluid::display::FluidStage_obj::screenWidth,::fluid::display::FluidStage_obj::screenHeight);
}
;
	return null();
}

//FluidStage_obj::~FluidStage_obj() { }

Dynamic FluidStage_obj::__CreateEmpty() { return  new FluidStage_obj; }
hx::ObjectPtr< FluidStage_obj > FluidStage_obj::__new()
{  hx::ObjectPtr< FluidStage_obj > result = new FluidStage_obj();
	result->__construct();
	return result;}

Dynamic FluidStage_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FluidStage_obj > result = new FluidStage_obj();
	result->__construct();
	return result;}

Float FluidStage_obj::actualPixelRatio;

Float FluidStage_obj::pixelRatio;

int FluidStage_obj::screenWidth;

int FluidStage_obj::screenHeight;

::String FluidStage_obj::orientation;

::String FluidStage_obj::LANDSCAPE;

::String FluidStage_obj::PORTRAIT;


FluidStage_obj::FluidStage_obj()
{
}

Dynamic FluidStage_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"pixelRatio") ) { return pixelRatio; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"screenWidth") ) { return screenWidth; }
		if (HX_FIELD_EQ(inName,"orientation") ) { return orientation; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"screenHeight") ) { return screenHeight; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"actualPixelRatio") ) { return actualPixelRatio; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FluidStage_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"pixelRatio") ) { pixelRatio=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"screenWidth") ) { screenWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"orientation") ) { orientation=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"screenHeight") ) { screenHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"actualPixelRatio") ) { actualPixelRatio=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FluidStage_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("actualPixelRatio"),
	HX_CSTRING("pixelRatio"),
	HX_CSTRING("screenWidth"),
	HX_CSTRING("screenHeight"),
	HX_CSTRING("orientation"),
	HX_CSTRING("LANDSCAPE"),
	HX_CSTRING("PORTRAIT"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FluidStage_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FluidStage_obj::actualPixelRatio,"actualPixelRatio");
	HX_MARK_MEMBER_NAME(FluidStage_obj::pixelRatio,"pixelRatio");
	HX_MARK_MEMBER_NAME(FluidStage_obj::screenWidth,"screenWidth");
	HX_MARK_MEMBER_NAME(FluidStage_obj::screenHeight,"screenHeight");
	HX_MARK_MEMBER_NAME(FluidStage_obj::orientation,"orientation");
	HX_MARK_MEMBER_NAME(FluidStage_obj::LANDSCAPE,"LANDSCAPE");
	HX_MARK_MEMBER_NAME(FluidStage_obj::PORTRAIT,"PORTRAIT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FluidStage_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FluidStage_obj::actualPixelRatio,"actualPixelRatio");
	HX_VISIT_MEMBER_NAME(FluidStage_obj::pixelRatio,"pixelRatio");
	HX_VISIT_MEMBER_NAME(FluidStage_obj::screenWidth,"screenWidth");
	HX_VISIT_MEMBER_NAME(FluidStage_obj::screenHeight,"screenHeight");
	HX_VISIT_MEMBER_NAME(FluidStage_obj::orientation,"orientation");
	HX_VISIT_MEMBER_NAME(FluidStage_obj::LANDSCAPE,"LANDSCAPE");
	HX_VISIT_MEMBER_NAME(FluidStage_obj::PORTRAIT,"PORTRAIT");
};

#endif

Class FluidStage_obj::__mClass;

void FluidStage_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.display.FluidStage"), hx::TCanCast< FluidStage_obj> ,sStaticFields,sMemberFields,
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

void FluidStage_obj::__boot()
{
	pixelRatio= (int)1;
	screenWidth= (int)800;
	screenHeight= (int)600;
	LANDSCAPE= HX_CSTRING("LANDSCAPE");
	PORTRAIT= HX_CSTRING("PORTRAIT");
}

} // end namespace fluid
} // end namespace display
