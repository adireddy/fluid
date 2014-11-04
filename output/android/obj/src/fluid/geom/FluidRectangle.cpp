#include <hxcpp.h>

#ifndef INCLUDED_fluid_geom_FluidRectangle
#include <fluid/geom/FluidRectangle.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Rectangle
#include <openfl/_v2/geom/Rectangle.h>
#endif
namespace fluid{
namespace geom{

Void FluidRectangle_obj::__construct(Float x,Float y,Float width,Float height)
{
HX_STACK_FRAME("fluid.geom.FluidRectangle","new",0x8c7d0c65,"fluid.geom.FluidRectangle.new","fluid/geom/FluidRectangle.hx",104,0xa6bbfe4b)
HX_STACK_THIS(this)
HX_STACK_ARG(x,"x")
HX_STACK_ARG(y,"y")
HX_STACK_ARG(width,"width")
HX_STACK_ARG(height,"height")
{
	HX_STACK_LINE(104)
	super::__construct(x,y,width,height);
}
;
	return null();
}

//FluidRectangle_obj::~FluidRectangle_obj() { }

Dynamic FluidRectangle_obj::__CreateEmpty() { return  new FluidRectangle_obj; }
hx::ObjectPtr< FluidRectangle_obj > FluidRectangle_obj::__new(Float x,Float y,Float width,Float height)
{  hx::ObjectPtr< FluidRectangle_obj > result = new FluidRectangle_obj();
	result->__construct(x,y,width,height);
	return result;}

Dynamic FluidRectangle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FluidRectangle_obj > result = new FluidRectangle_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}


FluidRectangle_obj::FluidRectangle_obj()
{
}

Dynamic FluidRectangle_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic FluidRectangle_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FluidRectangle_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(FluidRectangle_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FluidRectangle_obj::__mClass,"__mClass");
};

#endif

Class FluidRectangle_obj::__mClass;

void FluidRectangle_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.geom.FluidRectangle"), hx::TCanCast< FluidRectangle_obj> ,sStaticFields,sMemberFields,
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

void FluidRectangle_obj::__boot()
{
}

} // end namespace fluid
} // end namespace geom
