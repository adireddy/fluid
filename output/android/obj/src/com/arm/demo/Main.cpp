#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_Application
#include <com/arm/demo/Application.h>
#endif
#ifndef INCLUDED_com_arm_demo_Main
#include <com/arm/demo/Main.h>
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
#ifndef INCLUDED_com_arm_demo_notifications_internal_ViewStateNotification
#include <com/arm/demo/notifications/internal/ViewStateNotification.h>
#endif
#ifndef INCLUDED_com_arm_demo_view_DemoView
#include <com/arm/demo/view/DemoView.h>
#endif
#ifndef INCLUDED_fluid_Fluid
#include <fluid/Fluid.h>
#endif
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
#endif
#ifndef INCLUDED_msignal_Signal
#include <msignal/Signal.h>
#endif
#ifndef INCLUDED_msignal_Signal0
#include <msignal/Signal0.h>
#endif
#ifndef INCLUDED_msignal_Signal1
#include <msignal/Signal1.h>
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

Void Main_obj::__construct()
{
HX_STACK_FRAME("com.arm.demo.Main","new",0x87bbe177,"com.arm.demo.Main.new","com/arm/demo/Main.hx",13,0x9201fb7a)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(14)
	super::__construct();
	HX_STACK_LINE(16)
	this->set_stats(true);
	HX_STACK_LINE(17)
	this->set_backgroundColor((int)12515201);
	HX_STACK_LINE(18)
	this->skipFrame = true;
	HX_STACK_LINE(20)
	this->resize = this->_onResize_dyn();
	HX_STACK_LINE(21)
	this->update = this->_onUpdate_dyn();
	HX_STACK_LINE(23)
	this->_setupMVCS();
}
;
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::_setupMVCS( ){
{
		HX_STACK_FRAME("com.arm.demo.Main","_setupMVCS",0x3132e6e0,"com.arm.demo.Main._setupMVCS","com/arm/demo/Main.hx",26,0x9201fb7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(27)
		::com::arm::demo::view::DemoView _g = ::com::arm::demo::view::DemoView_obj::__new(this->container);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(27)
		this->view = _g;
		HX_STACK_LINE(28)
		::com::arm::demo::comms::DemoCommsController _g1 = ::com::arm::demo::comms::DemoCommsController_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(28)
		this->comms = _g1;
		HX_STACK_LINE(29)
		::com::arm::demo::model::DemoModel _g2 = ::com::arm::demo::model::DemoModel_obj::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(29)
		this->model = _g2;
		HX_STACK_LINE(30)
		::com::arm::demo::controller::DemoController _g3 = ::com::arm::demo::controller::DemoController_obj::__new(this->model,this->view,this->comms);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(30)
		this->controller = _g3;
		HX_STACK_LINE(31)
		this->controller->setupComponents();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,_setupMVCS,(void))

Void Main_obj::_onUpdate( Float time){
{
		HX_STACK_FRAME("com.arm.demo.Main","_onUpdate",0x5d00f03e,"com.arm.demo.Main._onUpdate","com/arm/demo/Main.hx",35,0x9201fb7a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(time,"time")
		HX_STACK_LINE(35)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::update->dispatch(time);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onUpdate,(void))

Void Main_obj::_onResize( ){
{
		HX_STACK_FRAME("com.arm.demo.Main","_onResize",0xde76c429,"com.arm.demo.Main._onResize","com/arm/demo/Main.hx",39,0x9201fb7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(39)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::resize->dispatch();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,_onResize,(void))


Main_obj::Main_obj()
{
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_onUpdate") ) { return _onUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"_onResize") ) { return _onResize_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_setupMVCS") ) { return _setupMVCS_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_setupMVCS"),
	HX_CSTRING("_onUpdate"),
	HX_CSTRING("_onResize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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

void Main_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
