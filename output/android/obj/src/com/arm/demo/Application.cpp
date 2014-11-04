#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_Application
#include <com/arm/demo/Application.h>
#endif
#ifndef INCLUDED_com_arm_demo_comms_DemoCommsController
#include <com/arm/demo/comms/DemoCommsController.h>
#endif
#ifndef INCLUDED_com_arm_demo_controller_DemoController
#include <com/arm/demo/controller/DemoController.h>
#endif
#ifndef INCLUDED_com_arm_demo_model_DemoModel
#include <com/arm/demo/model/DemoModel.h>
#endif
#ifndef INCLUDED_com_arm_demo_view_DemoView
#include <com/arm/demo/view/DemoView.h>
#endif
#ifndef INCLUDED_fluid_Fluid
#include <fluid/Fluid.h>
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

Void Application_obj::__construct()
{
HX_STACK_FRAME("com.arm.demo.Application","new",0xd0f30df6,"com.arm.demo.Application.new","com/arm/demo/Application.hx",17,0xad2486b9)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(17)
	super::__construct();
}
;
	return null();
}

//Application_obj::~Application_obj() { }

Dynamic Application_obj::__CreateEmpty() { return  new Application_obj; }
hx::ObjectPtr< Application_obj > Application_obj::__new()
{  hx::ObjectPtr< Application_obj > result = new Application_obj();
	result->__construct();
	return result;}

Dynamic Application_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Application_obj > result = new Application_obj();
	result->__construct();
	return result;}


Application_obj::Application_obj()
{
}

void Application_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Application);
	HX_MARK_MEMBER_NAME(model,"model");
	HX_MARK_MEMBER_NAME(view,"view");
	HX_MARK_MEMBER_NAME(controller,"controller");
	HX_MARK_MEMBER_NAME(comms,"comms");
	::fluid::Fluid_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Application_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(model,"model");
	HX_VISIT_MEMBER_NAME(view,"view");
	HX_VISIT_MEMBER_NAME(controller,"controller");
	HX_VISIT_MEMBER_NAME(comms,"comms");
	::fluid::Fluid_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Application_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { return view; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"model") ) { return model; }
		if (HX_FIELD_EQ(inName,"comms") ) { return comms; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"controller") ) { return controller; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Application_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { view=inValue.Cast< ::com::arm::demo::view::DemoView >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"model") ) { model=inValue.Cast< ::com::arm::demo::model::DemoModel >(); return inValue; }
		if (HX_FIELD_EQ(inName,"comms") ) { comms=inValue.Cast< ::com::arm::demo::comms::DemoCommsController >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"controller") ) { controller=inValue.Cast< ::com::arm::demo::controller::DemoController >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Application_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("model"));
	outFields->push(HX_CSTRING("view"));
	outFields->push(HX_CSTRING("controller"));
	outFields->push(HX_CSTRING("comms"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::com::arm::demo::model::DemoModel*/ ,(int)offsetof(Application_obj,model),HX_CSTRING("model")},
	{hx::fsObject /*::com::arm::demo::view::DemoView*/ ,(int)offsetof(Application_obj,view),HX_CSTRING("view")},
	{hx::fsObject /*::com::arm::demo::controller::DemoController*/ ,(int)offsetof(Application_obj,controller),HX_CSTRING("controller")},
	{hx::fsObject /*::com::arm::demo::comms::DemoCommsController*/ ,(int)offsetof(Application_obj,comms),HX_CSTRING("comms")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("model"),
	HX_CSTRING("view"),
	HX_CSTRING("controller"),
	HX_CSTRING("comms"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Application_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Application_obj::__mClass,"__mClass");
};

#endif

Class Application_obj::__mClass;

void Application_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.Application"), hx::TCanCast< Application_obj> ,sStaticFields,sMemberFields,
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

void Application_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
