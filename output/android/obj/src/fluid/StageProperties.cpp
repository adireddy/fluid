#include <hxcpp.h>

#ifndef INCLUDED_fluid_StageProperties
#include <fluid/StageProperties.h>
#endif
namespace fluid{

Void StageProperties_obj::__construct()
{
	return null();
}

//StageProperties_obj::~StageProperties_obj() { }

Dynamic StageProperties_obj::__CreateEmpty() { return  new StageProperties_obj; }
hx::ObjectPtr< StageProperties_obj > StageProperties_obj::__new()
{  hx::ObjectPtr< StageProperties_obj > result = new StageProperties_obj();
	result->__construct();
	return result;}

Dynamic StageProperties_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StageProperties_obj > result = new StageProperties_obj();
	result->__construct();
	return result;}

Float StageProperties_obj::actualPixelRatio;

Float StageProperties_obj::pixelRatio;

int StageProperties_obj::screenWidth;

int StageProperties_obj::screenHeight;

::String StageProperties_obj::orientation;

::String StageProperties_obj::LANDSCAPE;

::String StageProperties_obj::PORTRAIT;


StageProperties_obj::StageProperties_obj()
{
}

Dynamic StageProperties_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic StageProperties_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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

void StageProperties_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(StageProperties_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(StageProperties_obj::actualPixelRatio,"actualPixelRatio");
	HX_MARK_MEMBER_NAME(StageProperties_obj::pixelRatio,"pixelRatio");
	HX_MARK_MEMBER_NAME(StageProperties_obj::screenWidth,"screenWidth");
	HX_MARK_MEMBER_NAME(StageProperties_obj::screenHeight,"screenHeight");
	HX_MARK_MEMBER_NAME(StageProperties_obj::orientation,"orientation");
	HX_MARK_MEMBER_NAME(StageProperties_obj::LANDSCAPE,"LANDSCAPE");
	HX_MARK_MEMBER_NAME(StageProperties_obj::PORTRAIT,"PORTRAIT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StageProperties_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StageProperties_obj::actualPixelRatio,"actualPixelRatio");
	HX_VISIT_MEMBER_NAME(StageProperties_obj::pixelRatio,"pixelRatio");
	HX_VISIT_MEMBER_NAME(StageProperties_obj::screenWidth,"screenWidth");
	HX_VISIT_MEMBER_NAME(StageProperties_obj::screenHeight,"screenHeight");
	HX_VISIT_MEMBER_NAME(StageProperties_obj::orientation,"orientation");
	HX_VISIT_MEMBER_NAME(StageProperties_obj::LANDSCAPE,"LANDSCAPE");
	HX_VISIT_MEMBER_NAME(StageProperties_obj::PORTRAIT,"PORTRAIT");
};

#endif

Class StageProperties_obj::__mClass;

void StageProperties_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.StageProperties"), hx::TCanCast< StageProperties_obj> ,sStaticFields,sMemberFields,
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

void StageProperties_obj::__boot()
{
	pixelRatio= (int)1;
	screenWidth= (int)800;
	screenHeight= (int)600;
	LANDSCAPE= HX_CSTRING("LANDSCAPE");
	PORTRAIT= HX_CSTRING("PORTRAIT");
}

} // end namespace fluid
