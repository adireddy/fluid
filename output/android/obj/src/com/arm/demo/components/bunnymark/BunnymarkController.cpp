#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_comms_DemoCommsController
#include <com/arm/demo/comms/DemoCommsController.h>
#endif
#ifndef INCLUDED_com_arm_demo_components_GameComponentController
#include <com/arm/demo/components/GameComponentController.h>
#endif
#ifndef INCLUDED_com_arm_demo_components_GameComponentView
#include <com/arm/demo/components/GameComponentView.h>
#endif
#ifndef INCLUDED_com_arm_demo_components_bunnymark_BunnymarkController
#include <com/arm/demo/components/bunnymark/BunnymarkController.h>
#endif
#ifndef INCLUDED_com_arm_demo_components_bunnymark_BunnymarkView
#include <com/arm/demo/components/bunnymark/BunnymarkView.h>
#endif
#ifndef INCLUDED_com_arm_demo_controller_DemoController
#include <com/arm/demo/controller/DemoController.h>
#endif
#ifndef INCLUDED_com_arm_demo_model_DemoModel
#include <com/arm/demo/model/DemoModel.h>
#endif
#ifndef INCLUDED_com_arm_demo_notifications_internal_MenuNotification
#include <com/arm/demo/notifications/internal/MenuNotification.h>
#endif
#ifndef INCLUDED_com_arm_demo_view_DemoView
#include <com/arm/demo/view/DemoView.h>
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
#ifndef INCLUDED_msignal_Slot
#include <msignal/Slot.h>
#endif
#ifndef INCLUDED_msignal_Slot0
#include <msignal/Slot0.h>
#endif
#ifndef INCLUDED_msignal_Slot1
#include <msignal/Slot1.h>
#endif
namespace com{
namespace arm{
namespace demo{
namespace components{
namespace bunnymark{

Void BunnymarkController_obj::__construct(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mainModel)
{
HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkController","new",0x7020cc5a,"com.arm.demo.components.bunnymark.BunnymarkController.new","com/arm/demo/components/bunnymark/BunnymarkController.hx",6,0x9305b339)
HX_STACK_THIS(this)
HX_STACK_ARG(m,"m")
HX_STACK_ARG(v,"v")
HX_STACK_ARG(c,"c")
HX_STACK_ARG(mainModel,"mainModel")
{
	HX_STACK_LINE(10)
	this->_showing = false;
	HX_STACK_LINE(8)
	this->_id = (int)4;
	HX_STACK_LINE(13)
	super::__construct(m,v,c,mainModel);
	HX_STACK_LINE(14)
	::com::arm::demo::components::bunnymark::BunnymarkView _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(14)
	_g = hx::TCast< com::arm::demo::components::bunnymark::BunnymarkView >::cast(v);
	HX_STACK_LINE(14)
	this->_view = _g;
}
;
	return null();
}

//BunnymarkController_obj::~BunnymarkController_obj() { }

Dynamic BunnymarkController_obj::__CreateEmpty() { return  new BunnymarkController_obj; }
hx::ObjectPtr< BunnymarkController_obj > BunnymarkController_obj::__new(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mainModel)
{  hx::ObjectPtr< BunnymarkController_obj > result = new BunnymarkController_obj();
	result->__construct(m,v,c,mainModel);
	return result;}

Dynamic BunnymarkController_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BunnymarkController_obj > result = new BunnymarkController_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void BunnymarkController_obj::_update( Float elapsedTime){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkController","_update",0xc11018a2,"com.arm.demo.components.bunnymark.BunnymarkController._update","com/arm/demo/components/bunnymark/BunnymarkController.hx",18,0x9305b339)
		HX_STACK_THIS(this)
		HX_STACK_ARG(elapsedTime,"elapsedTime")
		HX_STACK_LINE(18)
		if ((this->_showing)){
			HX_STACK_LINE(18)
			this->_view->update(elapsedTime);
		}
	}
return null();
}


Void BunnymarkController_obj::_resize( ){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkController","_resize",0x4285ec8d,"com.arm.demo.components.bunnymark.BunnymarkController._resize","com/arm/demo/components/bunnymark/BunnymarkController.hx",22,0x9305b339)
		HX_STACK_THIS(this)
		HX_STACK_LINE(22)
		if ((this->_showing)){
			HX_STACK_LINE(22)
			this->_view->resize();
		}
	}
return null();
}


Void BunnymarkController_obj::_addNotificationListeners( ){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkController","_addNotificationListeners",0x4a9b5a0c,"com.arm.demo.components.bunnymark.BunnymarkController._addNotificationListeners","com/arm/demo/components/bunnymark/BunnymarkController.hx",25,0x9305b339)
		HX_STACK_THIS(this)
		HX_STACK_LINE(26)
		this->super::_addNotificationListeners();
		HX_STACK_LINE(27)
		::com::arm::demo::notifications::internal::MenuNotification_obj::click->add(this->_onMenuClick_dyn());
		HX_STACK_LINE(28)
		::com::arm::demo::notifications::internal::MenuNotification_obj::reset->add(this->_reset_dyn());
	}
return null();
}


Void BunnymarkController_obj::_reset( ){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkController","_reset",0xe830cd56,"com.arm.demo.components.bunnymark.BunnymarkController._reset","com/arm/demo/components/bunnymark/BunnymarkController.hx",32,0x9305b339)
		HX_STACK_THIS(this)
		HX_STACK_LINE(32)
		if ((this->_showing)){
			HX_STACK_LINE(33)
			this->_view->hide();
			HX_STACK_LINE(34)
			this->_showing = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BunnymarkController_obj,_reset,(void))

Void BunnymarkController_obj::_onMenuClick( int id){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkController","_onMenuClick",0x6e782bd1,"com.arm.demo.components.bunnymark.BunnymarkController._onMenuClick","com/arm/demo/components/bunnymark/BunnymarkController.hx",39,0x9305b339)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_LINE(39)
		if (((id == this->_id))){
			HX_STACK_LINE(40)
			if ((!(this->_showing))){
				HX_STACK_LINE(40)
				this->_view->show();
			}
			HX_STACK_LINE(41)
			this->_showing = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BunnymarkController_obj,_onMenuClick,(void))


BunnymarkController_obj::BunnymarkController_obj()
{
}

void BunnymarkController_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BunnymarkController);
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_MEMBER_NAME(_view,"_view");
	HX_MARK_MEMBER_NAME(_showing,"_showing");
	::com::arm::demo::components::GameComponentController_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BunnymarkController_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_id,"_id");
	HX_VISIT_MEMBER_NAME(_view,"_view");
	HX_VISIT_MEMBER_NAME(_showing,"_showing");
	::com::arm::demo::components::GameComponentController_obj::__Visit(HX_VISIT_ARG);
}

Dynamic BunnymarkController_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_id") ) { return _id; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_view") ) { return _view; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_reset") ) { return _reset_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_update") ) { return _update_dyn(); }
		if (HX_FIELD_EQ(inName,"_resize") ) { return _resize_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_showing") ) { return _showing; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_onMenuClick") ) { return _onMenuClick_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_addNotificationListeners") ) { return _addNotificationListeners_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BunnymarkController_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_view") ) { _view=inValue.Cast< ::com::arm::demo::components::bunnymark::BunnymarkView >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_showing") ) { _showing=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BunnymarkController_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_id"));
	outFields->push(HX_CSTRING("_view"));
	outFields->push(HX_CSTRING("_showing"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(BunnymarkController_obj,_id),HX_CSTRING("_id")},
	{hx::fsObject /*::com::arm::demo::components::bunnymark::BunnymarkView*/ ,(int)offsetof(BunnymarkController_obj,_view),HX_CSTRING("_view")},
	{hx::fsBool,(int)offsetof(BunnymarkController_obj,_showing),HX_CSTRING("_showing")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_id"),
	HX_CSTRING("_view"),
	HX_CSTRING("_showing"),
	HX_CSTRING("_update"),
	HX_CSTRING("_resize"),
	HX_CSTRING("_addNotificationListeners"),
	HX_CSTRING("_reset"),
	HX_CSTRING("_onMenuClick"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BunnymarkController_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BunnymarkController_obj::__mClass,"__mClass");
};

#endif

Class BunnymarkController_obj::__mClass;

void BunnymarkController_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.components.bunnymark.BunnymarkController"), hx::TCanCast< BunnymarkController_obj> ,sStaticFields,sMemberFields,
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

void BunnymarkController_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components
} // end namespace bunnymark
