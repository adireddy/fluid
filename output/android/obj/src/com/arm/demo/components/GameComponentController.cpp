#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_comms_DemoCommsController
#include <com/arm/demo/comms/DemoCommsController.h>
#endif
#ifndef INCLUDED_com_arm_demo_components_GameComponentController
#include <com/arm/demo/components/GameComponentController.h>
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

Void GameComponentController_obj::__construct(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mm)
{
HX_STACK_FRAME("com.arm.demo.components.GameComponentController","new",0x0239208d,"com.arm.demo.components.GameComponentController.new","com/arm/demo/components/GameComponentController.hx",13,0xaa643825)
HX_STACK_THIS(this)
HX_STACK_ARG(m,"m")
HX_STACK_ARG(v,"v")
HX_STACK_ARG(c,"c")
HX_STACK_ARG(mm,"mm")
{
	HX_STACK_LINE(14)
	super::__construct(m,v,c);
	HX_STACK_LINE(15)
	this->mainModel = mm;
}
;
	return null();
}

//GameComponentController_obj::~GameComponentController_obj() { }

Dynamic GameComponentController_obj::__CreateEmpty() { return  new GameComponentController_obj; }
hx::ObjectPtr< GameComponentController_obj > GameComponentController_obj::__new(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mm)
{  hx::ObjectPtr< GameComponentController_obj > result = new GameComponentController_obj();
	result->__construct(m,v,c,mm);
	return result;}

Dynamic GameComponentController_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameComponentController_obj > result = new GameComponentController_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void GameComponentController_obj::_addNotificationListeners( ){
{
		HX_STACK_FRAME("com.arm.demo.components.GameComponentController","_addNotificationListeners",0x62b0ac7f,"com.arm.demo.components.GameComponentController._addNotificationListeners","com/arm/demo/components/GameComponentController.hx",18,0xaa643825)
		HX_STACK_THIS(this)
		HX_STACK_LINE(19)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::preload->addOnce(this->_preload_dyn());
		HX_STACK_LINE(20)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::create->addOnce(this->_create_dyn());
		HX_STACK_LINE(21)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::update->add(this->_update_dyn());
		HX_STACK_LINE(22)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::resize->add(this->_resize_dyn());
	}
return null();
}


Void GameComponentController_obj::_preload( ){
{
		HX_STACK_FRAME("com.arm.demo.components.GameComponentController","_preload",0xf9e38dfd,"com.arm.demo.components.GameComponentController._preload","com/arm/demo/components/GameComponentController.hx",25,0xaa643825)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameComponentController_obj,_preload,(void))

Void GameComponentController_obj::_create( ){
{
		HX_STACK_FRAME("com.arm.demo.components.GameComponentController","_create",0x3a5be348,"com.arm.demo.components.GameComponentController._create","com/arm/demo/components/GameComponentController.hx",26,0xaa643825)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameComponentController_obj,_create,(void))

Void GameComponentController_obj::_update( Float elapsedTime){
{
		HX_STACK_FRAME("com.arm.demo.components.GameComponentController","_update",0x45520255,"com.arm.demo.components.GameComponentController._update","com/arm/demo/components/GameComponentController.hx",27,0xaa643825)
		HX_STACK_THIS(this)
		HX_STACK_ARG(elapsedTime,"elapsedTime")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameComponentController_obj,_update,(void))

Void GameComponentController_obj::_resize( ){
{
		HX_STACK_FRAME("com.arm.demo.components.GameComponentController","_resize",0xc6c7d640,"com.arm.demo.components.GameComponentController._resize","com/arm/demo/components/GameComponentController.hx",29,0xaa643825)
		HX_STACK_THIS(this)
		HX_STACK_LINE(30)
		this->mainModel = null();
		HX_STACK_LINE(31)
		::com::arm::demo::notifications::internal::ViewStateNotification_obj::reset();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameComponentController_obj,_resize,(void))


GameComponentController_obj::GameComponentController_obj()
{
}

void GameComponentController_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameComponentController);
	HX_MARK_MEMBER_NAME(mainModel,"mainModel");
	::com::arm::demo::controller::DemoController_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GameComponentController_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mainModel,"mainModel");
	::com::arm::demo::controller::DemoController_obj::__Visit(HX_VISIT_ARG);
}

Dynamic GameComponentController_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"_create") ) { return _create_dyn(); }
		if (HX_FIELD_EQ(inName,"_update") ) { return _update_dyn(); }
		if (HX_FIELD_EQ(inName,"_resize") ) { return _resize_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_preload") ) { return _preload_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mainModel") ) { return mainModel; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_addNotificationListeners") ) { return _addNotificationListeners_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameComponentController_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"mainModel") ) { mainModel=inValue.Cast< ::com::arm::demo::model::DemoModel >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameComponentController_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mainModel"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::com::arm::demo::model::DemoModel*/ ,(int)offsetof(GameComponentController_obj,mainModel),HX_CSTRING("mainModel")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("mainModel"),
	HX_CSTRING("_addNotificationListeners"),
	HX_CSTRING("_preload"),
	HX_CSTRING("_create"),
	HX_CSTRING("_update"),
	HX_CSTRING("_resize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameComponentController_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameComponentController_obj::__mClass,"__mClass");
};

#endif

Class GameComponentController_obj::__mClass;

void GameComponentController_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.components.GameComponentController"), hx::TCanCast< GameComponentController_obj> ,sStaticFields,sMemberFields,
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

void GameComponentController_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components
