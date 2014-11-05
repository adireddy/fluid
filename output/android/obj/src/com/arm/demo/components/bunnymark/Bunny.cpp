#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_components_bunnymark_Bunny
#include <com/arm/demo/components/bunnymark/Bunny.h>
#endif
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
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
namespace com{
namespace arm{
namespace demo{
namespace components{
namespace bunnymark{

Void Bunny_obj::__construct(::openfl::_v2::display::BitmapData texture)
{
HX_STACK_FRAME("com.arm.demo.components.bunnymark.Bunny","new",0x1d934c91,"com.arm.demo.components.bunnymark.Bunny.new","com/arm/demo/components/bunnymark/Bunny.hx",13,0x35e96fa2)
HX_STACK_THIS(this)
HX_STACK_ARG(texture,"texture")
{
	HX_STACK_LINE(13)
	super::__construct(texture);
}
;
	return null();
}

//Bunny_obj::~Bunny_obj() { }

Dynamic Bunny_obj::__CreateEmpty() { return  new Bunny_obj; }
hx::ObjectPtr< Bunny_obj > Bunny_obj::__new(::openfl::_v2::display::BitmapData texture)
{  hx::ObjectPtr< Bunny_obj > result = new Bunny_obj();
	result->__construct(texture);
	return result;}

Dynamic Bunny_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bunny_obj > result = new Bunny_obj();
	result->__construct(inArgs[0]);
	return result;}


Bunny_obj::Bunny_obj()
{
}

Dynamic Bunny_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"speedX") ) { return speedX; }
		if (HX_FIELD_EQ(inName,"speedY") ) { return speedY; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"scaleSpeed") ) { return scaleSpeed; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"rotationSpeed") ) { return rotationSpeed; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bunny_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"speedX") ) { speedX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"speedY") ) { speedY=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"scaleSpeed") ) { scaleSpeed=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"rotationSpeed") ) { rotationSpeed=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bunny_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("speedX"));
	outFields->push(HX_CSTRING("speedY"));
	outFields->push(HX_CSTRING("scaleSpeed"));
	outFields->push(HX_CSTRING("rotationSpeed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Bunny_obj,speedX),HX_CSTRING("speedX")},
	{hx::fsFloat,(int)offsetof(Bunny_obj,speedY),HX_CSTRING("speedY")},
	{hx::fsFloat,(int)offsetof(Bunny_obj,scaleSpeed),HX_CSTRING("scaleSpeed")},
	{hx::fsFloat,(int)offsetof(Bunny_obj,rotationSpeed),HX_CSTRING("rotationSpeed")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("speedX"),
	HX_CSTRING("speedY"),
	HX_CSTRING("scaleSpeed"),
	HX_CSTRING("rotationSpeed"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bunny_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bunny_obj::__mClass,"__mClass");
};

#endif

Class Bunny_obj::__mClass;

void Bunny_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.components.bunnymark.Bunny"), hx::TCanCast< Bunny_obj> ,sStaticFields,sMemberFields,
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

void Bunny_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components
} // end namespace bunnymark
