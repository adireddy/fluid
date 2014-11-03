#include <hxcpp.h>

#ifndef INCLUDED_ScaledStage
#include <ScaledStage.h>
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

Void ScaledStage_obj::__construct(Dynamic inHandle,int inWidth,int inHeight)
{
HX_STACK_FRAME("ScaledStage","new",0x3bde1c96,"ScaledStage.new","ApplicationMain.hx",206,0x0780ded5)
HX_STACK_THIS(this)
HX_STACK_ARG(inHandle,"inHandle")
HX_STACK_ARG(inWidth,"inWidth")
HX_STACK_ARG(inHeight,"inHeight")
{
	HX_STACK_LINE(206)
	super::__construct(inHandle,(int)0,(int)0);
}
;
	return null();
}

//ScaledStage_obj::~ScaledStage_obj() { }

Dynamic ScaledStage_obj::__CreateEmpty() { return  new ScaledStage_obj; }
hx::ObjectPtr< ScaledStage_obj > ScaledStage_obj::__new(Dynamic inHandle,int inWidth,int inHeight)
{  hx::ObjectPtr< ScaledStage_obj > result = new ScaledStage_obj();
	result->__construct(inHandle,inWidth,inHeight);
	return result;}

Dynamic ScaledStage_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ScaledStage_obj > result = new ScaledStage_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

int ScaledStage_obj::get___stageHeight( ){
	HX_STACK_FRAME("ScaledStage","get___stageHeight",0x9db8d432,"ScaledStage.get___stageHeight","ApplicationMain.hx",213,0x0780ded5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(213)
	return this->super::get_stageHeight();
}


HX_DEFINE_DYNAMIC_FUNC0(ScaledStage_obj,get___stageHeight,return )

int ScaledStage_obj::get___stageWidth( ){
	HX_STACK_FRAME("ScaledStage","get___stageWidth",0xb66b3c1b,"ScaledStage.get___stageWidth","ApplicationMain.hx",220,0x0780ded5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(220)
	return this->super::get_stageWidth();
}


HX_DEFINE_DYNAMIC_FUNC0(ScaledStage_obj,get___stageWidth,return )

int ScaledStage_obj::get_stageHeight( ){
	HX_STACK_FRAME("ScaledStage","get_stageHeight",0x948e0612,"ScaledStage.get_stageHeight","ApplicationMain.hx",227,0x0780ded5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(227)
	return (int)768;
}


int ScaledStage_obj::get_stageWidth( ){
	HX_STACK_FRAME("ScaledStage","get_stageWidth",0x034ae63b,"ScaledStage.get_stageWidth","ApplicationMain.hx",233,0x0780ded5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(233)
	return (int)1024;
}



ScaledStage_obj::ScaledStage_obj()
{
}

Dynamic ScaledStage_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"__stageWidth") ) { return inCallProp ? get___stageWidth() : __stageWidth; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"__stageHeight") ) { return inCallProp ? get___stageHeight() : __stageHeight; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_stageWidth") ) { return get_stageWidth_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_stageHeight") ) { return get_stageHeight_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get___stageWidth") ) { return get___stageWidth_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get___stageHeight") ) { return get___stageHeight_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ScaledStage_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"__stageWidth") ) { __stageWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"__stageHeight") ) { __stageHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ScaledStage_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__stageHeight"));
	outFields->push(HX_CSTRING("__stageWidth"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(ScaledStage_obj,__stageHeight),HX_CSTRING("__stageHeight")},
	{hx::fsInt,(int)offsetof(ScaledStage_obj,__stageWidth),HX_CSTRING("__stageWidth")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("__stageHeight"),
	HX_CSTRING("__stageWidth"),
	HX_CSTRING("get___stageHeight"),
	HX_CSTRING("get___stageWidth"),
	HX_CSTRING("get_stageHeight"),
	HX_CSTRING("get_stageWidth"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ScaledStage_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ScaledStage_obj::__mClass,"__mClass");
};

#endif

Class ScaledStage_obj::__mClass;

void ScaledStage_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("ScaledStage"), hx::TCanCast< ScaledStage_obj> ,sStaticFields,sMemberFields,
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

void ScaledStage_obj::__boot()
{
}

