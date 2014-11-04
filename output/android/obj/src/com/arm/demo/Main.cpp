#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_Application
#include <com/arm/demo/Application.h>
#endif
#ifndef INCLUDED_com_arm_demo_Bunny
#include <com/arm/demo/Bunny.h>
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
#ifndef INCLUDED_com_arm_demo_view_DemoView
#include <com/arm/demo/view/DemoView.h>
#endif
#ifndef INCLUDED_fluid_Fluid
#include <fluid/Fluid.h>
#endif
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
#endif
#ifndef INCLUDED_fluid_display_FluidStage
#include <fluid/display/FluidStage.h>
#endif
#ifndef INCLUDED_fluid_text_FluidText
#include <fluid/text/FluidText.h>
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
#ifndef INCLUDED_openfl__v2_display_Stage
#include <openfl/_v2/display/Stage.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextField
#include <openfl/_v2/text/TextField.h>
#endif
namespace com{
namespace arm{
namespace demo{

Void Main_obj::__construct()
{
HX_STACK_FRAME("com.arm.demo.Main","new",0x87bbe177,"com.arm.demo.Main.new","com/arm/demo/Main.hx",16,0x9201fb7a)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(29)
	this->_addBunnies = false;
	HX_STACK_LINE(26)
	this->_count = (int)0;
	HX_STACK_LINE(32)
	super::__construct();
	HX_STACK_LINE(34)
	this->set_stats(true);
	HX_STACK_LINE(35)
	this->set_backgroundColor((int)13421772);
	HX_STACK_LINE(36)
	this->skipFrame = true;
	HX_STACK_LINE(38)
	this->resize = this->_onRresize_dyn();
	HX_STACK_LINE(41)
	this->_setupMVCS();
	HX_STACK_LINE(43)
	Float _g = this->_minY = (int)0;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(43)
	this->_minX = _g;
	HX_STACK_LINE(44)
	this->_maxX = ::fluid::display::FluidStage_obj::screenWidth;
	HX_STACK_LINE(45)
	this->_maxY = ::fluid::display::FluidStage_obj::screenHeight;
	HX_STACK_LINE(46)
	this->_sprites = Array_obj< ::Dynamic >::__new();
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
		HX_STACK_FRAME("com.arm.demo.Main","_setupMVCS",0x3132e6e0,"com.arm.demo.Main._setupMVCS","com/arm/demo/Main.hx",66,0x9201fb7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(67)
		::com::arm::demo::view::DemoView _g = ::com::arm::demo::view::DemoView_obj::__new(this->container);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(67)
		this->view = _g;
		HX_STACK_LINE(68)
		::com::arm::demo::comms::DemoCommsController _g1 = ::com::arm::demo::comms::DemoCommsController_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(68)
		this->comms = _g1;
		HX_STACK_LINE(69)
		::com::arm::demo::model::DemoModel _g2 = ::com::arm::demo::model::DemoModel_obj::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(69)
		this->model = _g2;
		HX_STACK_LINE(70)
		::com::arm::demo::controller::DemoController _g3 = ::com::arm::demo::controller::DemoController_obj::__new(this->model,this->view,this->comms);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(70)
		this->controller = _g3;
		HX_STACK_LINE(71)
		this->controller->setupComponents();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,_setupMVCS,(void))

Void Main_obj::_onRresize( ){
{
		HX_STACK_FRAME("com.arm.demo.Main","_onRresize",0xf30bc011,"com.arm.demo.Main._onRresize","com/arm/demo/Main.hx",132,0x9201fb7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(133)
		this->_maxX = ::fluid::display::FluidStage_obj::screenWidth;
		HX_STACK_LINE(134)
		this->_maxY = ::fluid::display::FluidStage_obj::screenHeight;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,_onRresize,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(_bunnyTexture,"_bunnyTexture");
	HX_MARK_MEMBER_NAME(_sprites,"_sprites");
	HX_MARK_MEMBER_NAME(_maxX,"_maxX");
	HX_MARK_MEMBER_NAME(_maxY,"_maxY");
	HX_MARK_MEMBER_NAME(_minX,"_minX");
	HX_MARK_MEMBER_NAME(_minY,"_minY");
	HX_MARK_MEMBER_NAME(_count,"_count");
	HX_MARK_MEMBER_NAME(_countText,"_countText");
	HX_MARK_MEMBER_NAME(_addBunnies,"_addBunnies");
	::com::arm::demo::Application_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_bunnyTexture,"_bunnyTexture");
	HX_VISIT_MEMBER_NAME(_sprites,"_sprites");
	HX_VISIT_MEMBER_NAME(_maxX,"_maxX");
	HX_VISIT_MEMBER_NAME(_maxY,"_maxY");
	HX_VISIT_MEMBER_NAME(_minX,"_minX");
	HX_VISIT_MEMBER_NAME(_minY,"_minY");
	HX_VISIT_MEMBER_NAME(_count,"_count");
	HX_VISIT_MEMBER_NAME(_countText,"_countText");
	HX_VISIT_MEMBER_NAME(_addBunnies,"_addBunnies");
	::com::arm::demo::Application_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_maxX") ) { return _maxX; }
		if (HX_FIELD_EQ(inName,"_maxY") ) { return _maxY; }
		if (HX_FIELD_EQ(inName,"_minX") ) { return _minX; }
		if (HX_FIELD_EQ(inName,"_minY") ) { return _minY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_count") ) { return _count; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_sprites") ) { return _sprites; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_countText") ) { return _countText; }
		if (HX_FIELD_EQ(inName,"_setupMVCS") ) { return _setupMVCS_dyn(); }
		if (HX_FIELD_EQ(inName,"_onRresize") ) { return _onRresize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_addBunnies") ) { return _addBunnies; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_bunnyTexture") ) { return _bunnyTexture; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_maxX") ) { _maxX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_maxY") ) { _maxY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_minX") ) { _minX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_minY") ) { _minY=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_count") ) { _count=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_sprites") ) { _sprites=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_countText") ) { _countText=inValue.Cast< ::fluid::text::FluidText >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_addBunnies") ) { _addBunnies=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_bunnyTexture") ) { _bunnyTexture=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_bunnyTexture"));
	outFields->push(HX_CSTRING("_sprites"));
	outFields->push(HX_CSTRING("_maxX"));
	outFields->push(HX_CSTRING("_maxY"));
	outFields->push(HX_CSTRING("_minX"));
	outFields->push(HX_CSTRING("_minY"));
	outFields->push(HX_CSTRING("_count"));
	outFields->push(HX_CSTRING("_countText"));
	outFields->push(HX_CSTRING("_addBunnies"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Main_obj,_bunnyTexture),HX_CSTRING("_bunnyTexture")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Main_obj,_sprites),HX_CSTRING("_sprites")},
	{hx::fsFloat,(int)offsetof(Main_obj,_maxX),HX_CSTRING("_maxX")},
	{hx::fsFloat,(int)offsetof(Main_obj,_maxY),HX_CSTRING("_maxY")},
	{hx::fsFloat,(int)offsetof(Main_obj,_minX),HX_CSTRING("_minX")},
	{hx::fsFloat,(int)offsetof(Main_obj,_minY),HX_CSTRING("_minY")},
	{hx::fsInt,(int)offsetof(Main_obj,_count),HX_CSTRING("_count")},
	{hx::fsObject /*::fluid::text::FluidText*/ ,(int)offsetof(Main_obj,_countText),HX_CSTRING("_countText")},
	{hx::fsBool,(int)offsetof(Main_obj,_addBunnies),HX_CSTRING("_addBunnies")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_bunnyTexture"),
	HX_CSTRING("_sprites"),
	HX_CSTRING("_maxX"),
	HX_CSTRING("_maxY"),
	HX_CSTRING("_minX"),
	HX_CSTRING("_minY"),
	HX_CSTRING("_count"),
	HX_CSTRING("_countText"),
	HX_CSTRING("_addBunnies"),
	HX_CSTRING("_setupMVCS"),
	HX_CSTRING("_onRresize"),
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
