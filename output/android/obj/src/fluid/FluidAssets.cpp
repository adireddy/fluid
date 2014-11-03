#include <hxcpp.h>

#ifndef INCLUDED_fluid_FluidAssets
#include <fluid/FluidAssets.h>
#endif
#ifndef INCLUDED_openfl__v2_Assets
#include <openfl/_v2/Assets.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BitmapData
#include <openfl/_v2/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
namespace fluid{

Void FluidAssets_obj::__construct()
{
HX_STACK_FRAME("fluid.FluidAssets","new",0x3c1aef1b,"fluid.FluidAssets.new","fluid/FluidAssets.hx",5,0x497c4c76)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//FluidAssets_obj::~FluidAssets_obj() { }

Dynamic FluidAssets_obj::__CreateEmpty() { return  new FluidAssets_obj; }
hx::ObjectPtr< FluidAssets_obj > FluidAssets_obj::__new()
{  hx::ObjectPtr< FluidAssets_obj > result = new FluidAssets_obj();
	result->__construct();
	return result;}

Dynamic FluidAssets_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FluidAssets_obj > result = new FluidAssets_obj();
	result->__construct();
	return result;}

::openfl::_v2::display::BitmapData FluidAssets_obj::getImage( ::String url){
	HX_STACK_FRAME("fluid.FluidAssets","getImage",0x49a8ca4a,"fluid.FluidAssets.getImage","fluid/FluidAssets.hx",9,0x497c4c76)
	HX_STACK_ARG(url,"url")
	HX_STACK_LINE(9)
	return ::openfl::_v2::Assets_obj::getBitmapData(url,null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FluidAssets_obj,getImage,return )


FluidAssets_obj::FluidAssets_obj()
{
}

Dynamic FluidAssets_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"getImage") ) { return getImage_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FluidAssets_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FluidAssets_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getImage"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FluidAssets_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FluidAssets_obj::__mClass,"__mClass");
};

#endif

Class FluidAssets_obj::__mClass;

void FluidAssets_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.FluidAssets"), hx::TCanCast< FluidAssets_obj> ,sStaticFields,sMemberFields,
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

void FluidAssets_obj::__boot()
{
}

} // end namespace fluid
