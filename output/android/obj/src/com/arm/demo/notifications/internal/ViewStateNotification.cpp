#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_notifications_internal_ViewStateNotification
#include <com/arm/demo/notifications/internal/ViewStateNotification.h>
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
namespace com{
namespace arm{
namespace demo{
namespace notifications{
namespace internal{

Void ViewStateNotification_obj::__construct()
{
	return null();
}

//ViewStateNotification_obj::~ViewStateNotification_obj() { }

Dynamic ViewStateNotification_obj::__CreateEmpty() { return  new ViewStateNotification_obj; }
hx::ObjectPtr< ViewStateNotification_obj > ViewStateNotification_obj::__new()
{  hx::ObjectPtr< ViewStateNotification_obj > result = new ViewStateNotification_obj();
	result->__construct();
	return result;}

Dynamic ViewStateNotification_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ViewStateNotification_obj > result = new ViewStateNotification_obj();
	result->__construct();
	return result;}

::msignal::Signal0 ViewStateNotification_obj::preloader;

::msignal::Signal0 ViewStateNotification_obj::preloaderProgress;

::msignal::Signal0 ViewStateNotification_obj::preload;

::msignal::Signal0 ViewStateNotification_obj::create;

::msignal::Signal1 ViewStateNotification_obj::update;

::msignal::Signal0 ViewStateNotification_obj::destroy;

::msignal::Signal0 ViewStateNotification_obj::resize;

Void ViewStateNotification_obj::reset( ){
{
		HX_STACK_FRAME("com.arm.demo.notifications.internal.ViewStateNotification","reset",0xc7609179,"com.arm.demo.notifications.internal.ViewStateNotification.reset","com/arm/demo/notifications/internal/ViewStateNotification.hx",15,0x63010ba7)
		HX_STACK_LINE(16)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::preloader->removeAll();
		HX_STACK_LINE(17)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::preloaderProgress->removeAll();
		HX_STACK_LINE(18)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::preload->removeAll();
		HX_STACK_LINE(19)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::create->removeAll();
		HX_STACK_LINE(20)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::update->removeAll();
		HX_STACK_LINE(21)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::destroy->removeAll();
		HX_STACK_LINE(22)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::resize->removeAll();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ViewStateNotification_obj,reset,(void))


ViewStateNotification_obj::ViewStateNotification_obj()
{
}

Dynamic ViewStateNotification_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create; }
		if (HX_FIELD_EQ(inName,"update") ) { return update; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"preload") ) { return preload; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"preloader") ) { return preloader; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"preloaderProgress") ) { return preloaderProgress; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ViewStateNotification_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { create=inValue.Cast< ::msignal::Signal0 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"update") ) { update=inValue.Cast< ::msignal::Signal1 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"resize") ) { resize=inValue.Cast< ::msignal::Signal0 >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"preload") ) { preload=inValue.Cast< ::msignal::Signal0 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"destroy") ) { destroy=inValue.Cast< ::msignal::Signal0 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"preloader") ) { preloader=inValue.Cast< ::msignal::Signal0 >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"preloaderProgress") ) { preloaderProgress=inValue.Cast< ::msignal::Signal0 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ViewStateNotification_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("preloader"),
	HX_CSTRING("preloaderProgress"),
	HX_CSTRING("preload"),
	HX_CSTRING("create"),
	HX_CSTRING("update"),
	HX_CSTRING("destroy"),
	HX_CSTRING("resize"),
	HX_CSTRING("reset"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ViewStateNotification_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ViewStateNotification_obj::preloader,"preloader");
	HX_MARK_MEMBER_NAME(ViewStateNotification_obj::preloaderProgress,"preloaderProgress");
	HX_MARK_MEMBER_NAME(ViewStateNotification_obj::preload,"preload");
	HX_MARK_MEMBER_NAME(ViewStateNotification_obj::create,"create");
	HX_MARK_MEMBER_NAME(ViewStateNotification_obj::update,"update");
	HX_MARK_MEMBER_NAME(ViewStateNotification_obj::destroy,"destroy");
	HX_MARK_MEMBER_NAME(ViewStateNotification_obj::resize,"resize");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ViewStateNotification_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ViewStateNotification_obj::preloader,"preloader");
	HX_VISIT_MEMBER_NAME(ViewStateNotification_obj::preloaderProgress,"preloaderProgress");
	HX_VISIT_MEMBER_NAME(ViewStateNotification_obj::preload,"preload");
	HX_VISIT_MEMBER_NAME(ViewStateNotification_obj::create,"create");
	HX_VISIT_MEMBER_NAME(ViewStateNotification_obj::update,"update");
	HX_VISIT_MEMBER_NAME(ViewStateNotification_obj::destroy,"destroy");
	HX_VISIT_MEMBER_NAME(ViewStateNotification_obj::resize,"resize");
};

#endif

Class ViewStateNotification_obj::__mClass;

void ViewStateNotification_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.notifications.internal.ViewStateNotification"), hx::TCanCast< ViewStateNotification_obj> ,sStaticFields,sMemberFields,
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

void ViewStateNotification_obj::__boot()
{
	preloader= ::msignal::Signal0_obj::__new();
	preloaderProgress= ::msignal::Signal0_obj::__new();
	preload= ::msignal::Signal0_obj::__new();
	create= ::msignal::Signal0_obj::__new();
	update= ::msignal::Signal1_obj::__new(hx::ClassOf< ::Float >());
	destroy= ::msignal::Signal0_obj::__new();
	resize= ::msignal::Signal0_obj::__new();
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace notifications
} // end namespace internal
