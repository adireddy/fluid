#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_notifications_internal_MenuNotification
#include <com/arm/demo/notifications/internal/MenuNotification.h>
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

Void MenuNotification_obj::__construct()
{
	return null();
}

//MenuNotification_obj::~MenuNotification_obj() { }

Dynamic MenuNotification_obj::__CreateEmpty() { return  new MenuNotification_obj; }
hx::ObjectPtr< MenuNotification_obj > MenuNotification_obj::__new()
{  hx::ObjectPtr< MenuNotification_obj > result = new MenuNotification_obj();
	result->__construct();
	return result;}

Dynamic MenuNotification_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MenuNotification_obj > result = new MenuNotification_obj();
	result->__construct();
	return result;}

::msignal::Signal1 MenuNotification_obj::click;

::msignal::Signal0 MenuNotification_obj::reset;


MenuNotification_obj::MenuNotification_obj()
{
}

Dynamic MenuNotification_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"click") ) { return click; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MenuNotification_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"click") ) { click=inValue.Cast< ::msignal::Signal1 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"reset") ) { reset=inValue.Cast< ::msignal::Signal0 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MenuNotification_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("click"),
	HX_CSTRING("reset"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MenuNotification_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(MenuNotification_obj::click,"click");
	HX_MARK_MEMBER_NAME(MenuNotification_obj::reset,"reset");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MenuNotification_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(MenuNotification_obj::click,"click");
	HX_VISIT_MEMBER_NAME(MenuNotification_obj::reset,"reset");
};

#endif

Class MenuNotification_obj::__mClass;

void MenuNotification_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.notifications.internal.MenuNotification"), hx::TCanCast< MenuNotification_obj> ,sStaticFields,sMemberFields,
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

void MenuNotification_obj::__boot()
{
	click= ::msignal::Signal1_obj::__new(hx::ClassOf< ::Int >());
	reset= ::msignal::Signal0_obj::__new();
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace notifications
} // end namespace internal
