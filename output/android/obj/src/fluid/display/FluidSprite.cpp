#include <hxcpp.h>

#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Bitmap
#include <openfl/_v2/display/Bitmap.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BitmapData
#include <openfl/_v2/display/BitmapData.h>
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
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_display_PixelSnapping
#include <openfl/display/PixelSnapping.h>
#endif
namespace fluid{
namespace display{

Void FluidSprite_obj::__construct(::openfl::_v2::display::BitmapData texture)
{
HX_STACK_FRAME("fluid.display.FluidSprite","new",0x6e411971,"fluid.display.FluidSprite.new","fluid/display/FluidSprite.hx",5,0x63bd07a1)
HX_STACK_THIS(this)
HX_STACK_ARG(texture,"texture")
{
	HX_STACK_LINE(6)
	super::__construct();
	HX_STACK_LINE(8)
	::openfl::_v2::display::Bitmap _g = ::openfl::_v2::display::Bitmap_obj::__new(texture,null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(8)
	this->addChild(_g);
}
;
	return null();
}

//FluidSprite_obj::~FluidSprite_obj() { }

Dynamic FluidSprite_obj::__CreateEmpty() { return  new FluidSprite_obj; }
hx::ObjectPtr< FluidSprite_obj > FluidSprite_obj::__new(::openfl::_v2::display::BitmapData texture)
{  hx::ObjectPtr< FluidSprite_obj > result = new FluidSprite_obj();
	result->__construct(texture);
	return result;}

Dynamic FluidSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FluidSprite_obj > result = new FluidSprite_obj();
	result->__construct(inArgs[0]);
	return result;}


FluidSprite_obj::FluidSprite_obj()
{
}

Dynamic FluidSprite_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic FluidSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FluidSprite_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FluidSprite_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FluidSprite_obj::__mClass,"__mClass");
};

#endif

Class FluidSprite_obj::__mClass;

void FluidSprite_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.display.FluidSprite"), hx::TCanCast< FluidSprite_obj> ,sStaticFields,sMemberFields,
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

void FluidSprite_obj::__boot()
{
}

} // end namespace fluid
} // end namespace display
