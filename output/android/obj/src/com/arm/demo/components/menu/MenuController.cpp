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
namespace com{
namespace arm{
namespace demo{
namespace components{
namespace menu{

Void MenuController_obj::__construct(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mainModel)
{
HX_STACK_FRAME("com.arm.demo.components.menu.MenuController","new",0xd4699a70,"com.arm.demo.components.menu.MenuController.new","com/arm/demo/components/menu/MenuController.hx",9,0x5f9b4181)
HX_STACK_THIS(this)
HX_STACK_ARG(m,"m")
HX_STACK_ARG(v,"v")
HX_STACK_ARG(c,"c")
HX_STACK_ARG(mainModel,"mainModel")
{
	HX_STACK_LINE(10)
	super::__construct(m,v,c,mainModel);
	HX_STACK_LINE(11)
	::com::arm::demo::components::menu::MenuView _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(11)
	_g = hx::TCast< com::arm::demo::components::menu::MenuView >::cast(v);
	HX_STACK_LINE(11)
	this->_view = _g;
	HX_STACK_LINE(13)
	this->_view->create();
}
;
	return null();
}

//MenuController_obj::~MenuController_obj() { }

Dynamic MenuController_obj::__CreateEmpty() { return  new MenuController_obj; }
hx::ObjectPtr< MenuController_obj > MenuController_obj::__new(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mainModel)
{  hx::ObjectPtr< MenuController_obj > result = new MenuController_obj();
	result->__construct(m,v,c,mainModel);
	return result;}

Dynamic MenuController_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MenuController_obj > result = new MenuController_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void MenuController_obj::_create( ){
{
		HX_STACK_FRAME("com.arm.demo.components.menu.MenuController","_create",0x14b28aab,"com.arm.demo.components.menu.MenuController._create","com/arm/demo/components/menu/MenuController.hx",17,0x5f9b4181)
		HX_STACK_THIS(this)
		HX_STACK_LINE(17)
		this->_view->create();
	}
return null();
}



MenuController_obj::MenuController_obj()
{
}

void MenuController_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MenuController);
	HX_MARK_MEMBER_NAME(_view,"_view");
	::com::arm::demo::components::GameComponentController_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MenuController_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_view,"_view");
	::com::arm::demo::components::GameComponentController_obj::__Visit(HX_VISIT_ARG);
}

Dynamic MenuController_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_view") ) { return _view; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_create") ) { return _create_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MenuController_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_view") ) { _view=inValue.Cast< ::com::arm::demo::components::menu::MenuView >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MenuController_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_view"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::com::arm::demo::components::menu::MenuView*/ ,(int)offsetof(MenuController_obj,_view),HX_CSTRING("_view")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_view"),
	HX_CSTRING("_create"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MenuController_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MenuController_obj::__mClass,"__mClass");
};

#endif

Class MenuController_obj::__mClass;

void MenuController_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.components.menu.MenuController"), hx::TCanCast< MenuController_obj> ,sStaticFields,sMemberFields,
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

void MenuController_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components
} // end namespace menu
