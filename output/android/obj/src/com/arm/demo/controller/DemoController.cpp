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
#ifndef INCLUDED_com_arm_demo_components_menu_MenuController
#include <com/arm/demo/components/menu/MenuController.h>
#endif
#ifndef INCLUDED_com_arm_demo_components_menu_MenuView
#include <com/arm/demo/components/menu/MenuView.h>
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
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
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
namespace controller{

Void DemoController_obj::__construct(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c)
{
HX_STACK_FRAME("com.arm.demo.controller.DemoController","new",0x8c3e9997,"com.arm.demo.controller.DemoController.new","com/arm/demo/controller/DemoController.hx",16,0x66db3957)
HX_STACK_THIS(this)
HX_STACK_ARG(m,"m")
HX_STACK_ARG(v,"v")
HX_STACK_ARG(c,"c")
{
	HX_STACK_LINE(17)
	this->model = m;
	HX_STACK_LINE(18)
	this->view = v;
	HX_STACK_LINE(19)
	this->comms = c;
	HX_STACK_LINE(21)
	this->_addNotificationListeners();
	HX_STACK_LINE(22)
	this->_addViewListeners();
}
;
	return null();
}

//DemoController_obj::~DemoController_obj() { }

Dynamic DemoController_obj::__CreateEmpty() { return  new DemoController_obj; }
hx::ObjectPtr< DemoController_obj > DemoController_obj::__new(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c)
{  hx::ObjectPtr< DemoController_obj > result = new DemoController_obj();
	result->__construct(m,v,c);
	return result;}

Dynamic DemoController_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DemoController_obj > result = new DemoController_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void DemoController_obj::_addNotificationListeners( ){
{
		HX_STACK_FRAME("com.arm.demo.controller.DemoController","_addNotificationListeners",0x5b54bd09,"com.arm.demo.controller.DemoController._addNotificationListeners","com/arm/demo/controller/DemoController.hx",25,0x66db3957)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DemoController_obj,_addNotificationListeners,(void))

Void DemoController_obj::_addViewListeners( ){
{
		HX_STACK_FRAME("com.arm.demo.controller.DemoController","_addViewListeners",0xe98ec54f,"com.arm.demo.controller.DemoController._addViewListeners","com/arm/demo/controller/DemoController.hx",26,0x66db3957)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DemoController_obj,_addViewListeners,(void))

Void DemoController_obj::reset( ){
{
		HX_STACK_FRAME("com.arm.demo.controller.DemoController","reset",0x59e10ec6,"com.arm.demo.controller.DemoController.reset","com/arm/demo/controller/DemoController.hx",28,0x66db3957)
		HX_STACK_THIS(this)
		HX_STACK_LINE(29)
		if (((this->view != null()))){
			HX_STACK_LINE(29)
			this->view->reset();
		}
		HX_STACK_LINE(30)
		if (((this->model != null()))){
			HX_STACK_LINE(30)
			this->model->reset();
		}
		HX_STACK_LINE(31)
		if (((this->comms != null()))){
			HX_STACK_LINE(31)
			this->comms->reset();
		}
		HX_STACK_LINE(32)
		this->model = null();
		HX_STACK_LINE(33)
		this->view = null();
		HX_STACK_LINE(34)
		this->comms = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DemoController_obj,reset,(void))

Void DemoController_obj::setupComponents( ){
{
		HX_STACK_FRAME("com.arm.demo.controller.DemoController","setupComponents",0xf70e85aa,"com.arm.demo.controller.DemoController.setupComponents","com/arm/demo/controller/DemoController.hx",38,0x66db3957)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		this->_setupMenuComponent();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DemoController_obj,setupComponents,(void))

Void DemoController_obj::_setupMenuComponent( ){
{
		HX_STACK_FRAME("com.arm.demo.controller.DemoController","_setupMenuComponent",0x41f461b7,"com.arm.demo.controller.DemoController._setupMenuComponent","com/arm/demo/controller/DemoController.hx",43,0x66db3957)
		HX_STACK_THIS(this)
		HX_STACK_LINE(44)
		::fluid::display::FluidSprite _g = this->view->get_container();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(44)
		::com::arm::demo::components::menu::MenuView menuView = ::com::arm::demo::components::menu::MenuView_obj::__new(_g);		HX_STACK_VAR(menuView,"menuView");
		HX_STACK_LINE(45)
		::com::arm::demo::components::menu::MenuController menuController = ::com::arm::demo::components::menu::MenuController_obj::__new(null(),menuView,this->comms,this->model);		HX_STACK_VAR(menuController,"menuController");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DemoController_obj,_setupMenuComponent,(void))


DemoController_obj::DemoController_obj()
{
}

void DemoController_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DemoController);
	HX_MARK_MEMBER_NAME(model,"model");
	HX_MARK_MEMBER_NAME(view,"view");
	HX_MARK_MEMBER_NAME(comms,"comms");
	HX_MARK_END_CLASS();
}

void DemoController_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(model,"model");
	HX_VISIT_MEMBER_NAME(view,"view");
	HX_VISIT_MEMBER_NAME(comms,"comms");
}

Dynamic DemoController_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { return view; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"model") ) { return model; }
		if (HX_FIELD_EQ(inName,"comms") ) { return comms; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setupComponents") ) { return setupComponents_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_addViewListeners") ) { return _addViewListeners_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_setupMenuComponent") ) { return _setupMenuComponent_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_addNotificationListeners") ) { return _addNotificationListeners_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DemoController_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { view=inValue.Cast< ::com::arm::demo::view::DemoView >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"model") ) { model=inValue.Cast< ::com::arm::demo::model::DemoModel >(); return inValue; }
		if (HX_FIELD_EQ(inName,"comms") ) { comms=inValue.Cast< ::com::arm::demo::comms::DemoCommsController >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DemoController_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("model"));
	outFields->push(HX_CSTRING("view"));
	outFields->push(HX_CSTRING("comms"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::com::arm::demo::model::DemoModel*/ ,(int)offsetof(DemoController_obj,model),HX_CSTRING("model")},
	{hx::fsObject /*::com::arm::demo::view::DemoView*/ ,(int)offsetof(DemoController_obj,view),HX_CSTRING("view")},
	{hx::fsObject /*::com::arm::demo::comms::DemoCommsController*/ ,(int)offsetof(DemoController_obj,comms),HX_CSTRING("comms")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("model"),
	HX_CSTRING("view"),
	HX_CSTRING("comms"),
	HX_CSTRING("_addNotificationListeners"),
	HX_CSTRING("_addViewListeners"),
	HX_CSTRING("reset"),
	HX_CSTRING("setupComponents"),
	HX_CSTRING("_setupMenuComponent"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DemoController_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DemoController_obj::__mClass,"__mClass");
};

#endif

Class DemoController_obj::__mClass;

void DemoController_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.controller.DemoController"), hx::TCanCast< DemoController_obj> ,sStaticFields,sMemberFields,
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

void DemoController_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace controller
