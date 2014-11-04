#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_widgets_Button
#include <com/arm/demo/widgets/Button.h>
#endif
#ifndef INCLUDED_com_arm_demo_widgets_menu_MenuItem
#include <com/arm/demo/widgets/menu/MenuItem.h>
#endif
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
#endif
#ifndef INCLUDED_msignal_Signal
#include <msignal/Signal.h>
#endif
#ifndef INCLUDED_msignal_Signal1
#include <msignal/Signal1.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BitmapData
#include <openfl/_v2/display/BitmapData.h>
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
namespace widgets{
namespace menu{

Void MenuItem_obj::__construct(::String label,Float width,Float height,Dynamic data)
{
HX_STACK_FRAME("com.arm.demo.widgets.menu.MenuItem","new",0xfe9d0368,"com.arm.demo.widgets.menu.MenuItem.new","com/arm/demo/widgets/menu/MenuItem.hx",14,0x9e38f9e7)
HX_STACK_THIS(this)
HX_STACK_ARG(label,"label")
HX_STACK_ARG(width,"width")
HX_STACK_ARG(height,"height")
HX_STACK_ARG(data,"data")
{
	HX_STACK_LINE(15)
	super::__construct(null());
	HX_STACK_LINE(16)
	::com::arm::demo::widgets::Button _g = ::com::arm::demo::widgets::Button_obj::__new(label,width,height,data,null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(16)
	this->_button = _g;
	HX_STACK_LINE(17)
	this->action = this->_button->action;
	HX_STACK_LINE(18)
	this->addChild(this->_button);
}
;
	return null();
}

//MenuItem_obj::~MenuItem_obj() { }

Dynamic MenuItem_obj::__CreateEmpty() { return  new MenuItem_obj; }
hx::ObjectPtr< MenuItem_obj > MenuItem_obj::__new(::String label,Float width,Float height,Dynamic data)
{  hx::ObjectPtr< MenuItem_obj > result = new MenuItem_obj();
	result->__construct(label,width,height,data);
	return result;}

Dynamic MenuItem_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MenuItem_obj > result = new MenuItem_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void MenuItem_obj::setText( ::String label){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.MenuItem","setText",0x74116477,"com.arm.demo.widgets.menu.MenuItem.setText","com/arm/demo/widgets/menu/MenuItem.hx",22,0x9e38f9e7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(label,"label")
		HX_STACK_LINE(22)
		this->_button->setText(label);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MenuItem_obj,setText,(void))

Void MenuItem_obj::enable( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.MenuItem","enable",0x090a107b,"com.arm.demo.widgets.menu.MenuItem.enable","com/arm/demo/widgets/menu/MenuItem.hx",26,0x9e38f9e7)
		HX_STACK_THIS(this)
		HX_STACK_LINE(26)
		this->_button->enable();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MenuItem_obj,enable,(void))

Void MenuItem_obj::disable( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.MenuItem","disable",0x12ebc0f0,"com.arm.demo.widgets.menu.MenuItem.disable","com/arm/demo/widgets/menu/MenuItem.hx",30,0x9e38f9e7)
		HX_STACK_THIS(this)
		HX_STACK_LINE(30)
		this->_button->disable();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MenuItem_obj,disable,(void))


MenuItem_obj::MenuItem_obj()
{
}

void MenuItem_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MenuItem);
	HX_MARK_MEMBER_NAME(_data,"_data");
	HX_MARK_MEMBER_NAME(_button,"_button");
	HX_MARK_MEMBER_NAME(action,"action");
	::fluid::display::FluidSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MenuItem_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_data,"_data");
	HX_VISIT_MEMBER_NAME(_button,"_button");
	HX_VISIT_MEMBER_NAME(action,"action");
	::fluid::display::FluidSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic MenuItem_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { return _data; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"action") ) { return action; }
		if (HX_FIELD_EQ(inName,"enable") ) { return enable_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_button") ) { return _button; }
		if (HX_FIELD_EQ(inName,"setText") ) { return setText_dyn(); }
		if (HX_FIELD_EQ(inName,"disable") ) { return disable_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MenuItem_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { _data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"action") ) { action=inValue.Cast< ::msignal::Signal1 >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_button") ) { _button=inValue.Cast< ::com::arm::demo::widgets::Button >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MenuItem_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_data"));
	outFields->push(HX_CSTRING("_button"));
	outFields->push(HX_CSTRING("action"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(MenuItem_obj,_data),HX_CSTRING("_data")},
	{hx::fsObject /*::com::arm::demo::widgets::Button*/ ,(int)offsetof(MenuItem_obj,_button),HX_CSTRING("_button")},
	{hx::fsObject /*::msignal::Signal1*/ ,(int)offsetof(MenuItem_obj,action),HX_CSTRING("action")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_data"),
	HX_CSTRING("_button"),
	HX_CSTRING("action"),
	HX_CSTRING("setText"),
	HX_CSTRING("enable"),
	HX_CSTRING("disable"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MenuItem_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MenuItem_obj::__mClass,"__mClass");
};

#endif

Class MenuItem_obj::__mClass;

void MenuItem_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.widgets.menu.MenuItem"), hx::TCanCast< MenuItem_obj> ,sStaticFields,sMemberFields,
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

void MenuItem_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace widgets
} // end namespace menu
