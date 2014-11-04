#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_comms_DemoCommsController
#include <com/arm/demo/comms/DemoCommsController.h>
#endif
#ifndef INCLUDED_msignal_Signal
#include <msignal/Signal.h>
#endif
#ifndef INCLUDED_msignal_Signal1
#include <msignal/Signal1.h>
#endif
#ifndef INCLUDED_msignal_Signal2
#include <msignal/Signal2.h>
#endif
namespace com{
namespace arm{
namespace demo{
namespace comms{

Void DemoCommsController_obj::__construct()
{
HX_STACK_FRAME("com.arm.demo.comms.DemoCommsController","new",0x67b01d9f,"com.arm.demo.comms.DemoCommsController.new","com/arm/demo/comms/DemoCommsController.hx",5,0xb8f2e831)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(8)
	this->error = ::msignal::Signal1_obj::__new(hx::ClassOf< ::String >());
	HX_STACK_LINE(7)
	this->success = ::msignal::Signal2_obj::__new(hx::ClassOf< ::String >(),hx::ClassOf< ::String >());
}
;
	return null();
}

//DemoCommsController_obj::~DemoCommsController_obj() { }

Dynamic DemoCommsController_obj::__CreateEmpty() { return  new DemoCommsController_obj; }
hx::ObjectPtr< DemoCommsController_obj > DemoCommsController_obj::__new()
{  hx::ObjectPtr< DemoCommsController_obj > result = new DemoCommsController_obj();
	result->__construct();
	return result;}

Dynamic DemoCommsController_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DemoCommsController_obj > result = new DemoCommsController_obj();
	result->__construct();
	return result;}

Void DemoCommsController_obj::reset( ){
{
		HX_STACK_FRAME("com.arm.demo.comms.DemoCommsController","reset",0x17c1a4ce,"com.arm.demo.comms.DemoCommsController.reset","com/arm/demo/comms/DemoCommsController.hx",14,0xb8f2e831)
		HX_STACK_THIS(this)
		HX_STACK_LINE(15)
		this->success->removeAll();
		HX_STACK_LINE(16)
		this->error->removeAll();
		HX_STACK_LINE(17)
		this->success = null();
		HX_STACK_LINE(18)
		this->error = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DemoCommsController_obj,reset,(void))


DemoCommsController_obj::DemoCommsController_obj()
{
}

void DemoCommsController_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DemoCommsController);
	HX_MARK_MEMBER_NAME(success,"success");
	HX_MARK_MEMBER_NAME(error,"error");
	HX_MARK_END_CLASS();
}

void DemoCommsController_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(success,"success");
	HX_VISIT_MEMBER_NAME(error,"error");
}

Dynamic DemoCommsController_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"error") ) { return error; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"success") ) { return success; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DemoCommsController_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"error") ) { error=inValue.Cast< ::msignal::Signal1 >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"success") ) { success=inValue.Cast< ::msignal::Signal2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DemoCommsController_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("success"));
	outFields->push(HX_CSTRING("error"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::msignal::Signal2*/ ,(int)offsetof(DemoCommsController_obj,success),HX_CSTRING("success")},
	{hx::fsObject /*::msignal::Signal1*/ ,(int)offsetof(DemoCommsController_obj,error),HX_CSTRING("error")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("success"),
	HX_CSTRING("error"),
	HX_CSTRING("reset"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DemoCommsController_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DemoCommsController_obj::__mClass,"__mClass");
};

#endif

Class DemoCommsController_obj::__mClass;

void DemoCommsController_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.comms.DemoCommsController"), hx::TCanCast< DemoCommsController_obj> ,sStaticFields,sMemberFields,
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

void DemoCommsController_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace comms
