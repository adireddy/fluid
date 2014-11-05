#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_widgets_Button
#include <com/arm/demo/widgets/Button.h>
#endif
#ifndef INCLUDED_fluid_display_FluidGraphics
#include <fluid/display/FluidGraphics.h>
#endif
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
#endif
#ifndef INCLUDED_fluid_events_EventData
#include <fluid/events/EventData.h>
#endif
#ifndef INCLUDED_fluid_geom_FluidRectangle
#include <fluid/geom/FluidRectangle.h>
#endif
#ifndef INCLUDED_fluid_text_FluidText
#include <fluid/text/FluidText.h>
#endif
#ifndef INCLUDED_fluid_text_FluidTextFormat
#include <fluid/text/FluidTextFormat.h>
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
#ifndef INCLUDED_openfl__v2_geom_Rectangle
#include <openfl/_v2/geom/Rectangle.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextField
#include <openfl/_v2/text/TextField.h>
#endif
namespace com{
namespace arm{
namespace demo{
namespace widgets{

Void Button_obj::__construct(::String label,Float width,Float height,Dynamic data,Dynamic fontSize)
{
HX_STACK_FRAME("com.arm.demo.widgets.Button","new",0x0ba9bc8f,"com.arm.demo.widgets.Button.new","com/arm/demo/widgets/Button.hx",10,0x40a93681)
HX_STACK_THIS(this)
HX_STACK_ARG(label,"label")
HX_STACK_ARG(width,"width")
HX_STACK_ARG(height,"height")
HX_STACK_ARG(data,"data")
HX_STACK_ARG(fontSize,"fontSize")
{
	HX_STACK_LINE(24)
	this->action = ::msignal::Signal1_obj::__new(hx::ClassOf< ::Dynamic >());
	HX_STACK_LINE(27)
	super::__construct(null());
	HX_STACK_LINE(28)
	this->_data = data;
	HX_STACK_LINE(29)
	this->_setupBackground(width,height);
	HX_STACK_LINE(30)
	this->_setupLabel(width,height,fontSize);
	HX_STACK_LINE(31)
	this->setText(label);
}
;
	return null();
}

//Button_obj::~Button_obj() { }

Dynamic Button_obj::__CreateEmpty() { return  new Button_obj; }
hx::ObjectPtr< Button_obj > Button_obj::__new(::String label,Float width,Float height,Dynamic data,Dynamic fontSize)
{  hx::ObjectPtr< Button_obj > result = new Button_obj();
	result->__construct(label,width,height,data,fontSize);
	return result;}

Dynamic Button_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Button_obj > result = new Button_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

Void Button_obj::_setupBackground( Float width,Float height){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","_setupBackground",0x165649bd,"com.arm.demo.widgets.Button._setupBackground","com/arm/demo/widgets/Button.hx",34,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_ARG(width,"width")
		HX_STACK_ARG(height,"height")
		HX_STACK_LINE(35)
		::fluid::geom::FluidRectangle _g = ::fluid::geom::FluidRectangle_obj::__new((int)0,(int)0,width,height);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(35)
		this->_rect = _g;
		HX_STACK_LINE(36)
		::fluid::display::FluidGraphics _g1 = ::fluid::display::FluidGraphics_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(36)
		this->_background = _g1;
		HX_STACK_LINE(38)
		this->_redraw((int)2187531);
		HX_STACK_LINE(39)
		this->addChild(this->_background);
		HX_STACK_LINE(41)
		this->_background->set_interactive(true);
		HX_STACK_LINE(42)
		this->_background->mouseOver = this->_onMouseOver_dyn();
		HX_STACK_LINE(43)
		this->_background->mouseOut = this->_onMouseOut_dyn();
		HX_STACK_LINE(44)
		this->_background->mouseDown = this->_onMouseDown_dyn();
		HX_STACK_LINE(45)
		this->_background->mouseUp = this->_onMouseUp_dyn();
		HX_STACK_LINE(46)
		this->_background->touchBegin = this->_onTouchStart_dyn();
		HX_STACK_LINE(47)
		this->_background->touchEnd = this->_onTouchEnd_dyn();
		HX_STACK_LINE(48)
		this->_background->touchOut = this->_onTouchEndOutside_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Button_obj,_setupBackground,(void))

Void Button_obj::_setupLabel( Float width,Float height,Dynamic __o_fontSize){
Dynamic fontSize = __o_fontSize.Default(16);
	HX_STACK_FRAME("com.arm.demo.widgets.Button","_setupLabel",0x53b02a85,"com.arm.demo.widgets.Button._setupLabel","com/arm/demo/widgets/Button.hx",51,0x40a93681)
	HX_STACK_THIS(this)
	HX_STACK_ARG(width,"width")
	HX_STACK_ARG(height,"height")
	HX_STACK_ARG(fontSize,"fontSize")
{
		HX_STACK_LINE(52)
		::fluid::text::FluidTextFormat format = ::fluid::text::FluidTextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format,"format");
		HX_STACK_LINE(53)
		format->size = fontSize;
		HX_STACK_LINE(54)
		format->font = HX_CSTRING("Arial");
		HX_STACK_LINE(55)
		format->fill = HX_CSTRING("#FFFFFF");
		HX_STACK_LINE(56)
		::fluid::text::FluidText _g = ::fluid::text::FluidText_obj::__new(HX_CSTRING(""),format);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(56)
		this->_label = _g;
		HX_STACK_LINE(57)
		this->_label->setAnchor(0.5,0.5);
		HX_STACK_LINE(58)
		this->_label->set_interactive(false);
		HX_STACK_LINE(59)
		this->_label->set_x((Float(width) / Float((int)2)));
		HX_STACK_LINE(60)
		this->_label->set_y((Float(height) / Float((int)2)));
		HX_STACK_LINE(61)
		this->addChild(this->_label);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Button_obj,_setupLabel,(void))

Void Button_obj::_redraw( int colour){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","_redraw",0xe7a02685,"com.arm.demo.widgets.Button._redraw","com/arm/demo/widgets/Button.hx",64,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_ARG(colour,"colour")
		HX_STACK_LINE(65)
		Float border = (int)1;		HX_STACK_VAR(border,"border");
		HX_STACK_LINE(66)
		this->_background->clear();
		HX_STACK_LINE(67)
		this->_background->beginFill(colour,null());
		HX_STACK_LINE(68)
		this->_background->drawRect(this->_rect->x,this->_rect->y,this->_rect->width,this->_rect->height);
		HX_STACK_LINE(69)
		this->_background->endFill();
		HX_STACK_LINE(70)
		this->_background->beginFill(colour,null());
		HX_STACK_LINE(71)
		this->_background->drawRect((this->_rect->x + (Float(border) / Float((int)2))),(this->_rect->y + (Float(border) / Float((int)2))),(this->_rect->width - border),(this->_rect->height - border));
		HX_STACK_LINE(72)
		this->_background->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Button_obj,_redraw,(void))

Void Button_obj::setText( ::String label){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","setText",0x8d0f3d1e,"com.arm.demo.widgets.Button.setText","com/arm/demo/widgets/Button.hx",76,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_ARG(label,"label")
		HX_STACK_LINE(76)
		this->_label->setText(label);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Button_obj,setText,(void))

Void Button_obj::_onMouseDown( Dynamic data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","_onMouseDown",0xcd47d7fa,"com.arm.demo.widgets.Button._onMouseDown","com/arm/demo/widgets/Button.hx",80,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(80)
		if ((this->_enabled)){
			HX_STACK_LINE(80)
			this->_redraw((int)13158);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Button_obj,_onMouseDown,(void))

Void Button_obj::_onMouseUp( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","_onMouseUp",0x2e82aff3,"com.arm.demo.widgets.Button._onMouseUp","com/arm/demo/widgets/Button.hx",84,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(84)
		if ((this->_enabled)){
			HX_STACK_LINE(85)
			this->action->dispatch(this->_data);
			HX_STACK_LINE(86)
			this->_redraw((int)2187531);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Button_obj,_onMouseUp,(void))

Void Button_obj::_onMouseUpOutside( Dynamic data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","_onMouseUpOutside",0x00533972,"com.arm.demo.widgets.Button._onMouseUpOutside","com/arm/demo/widgets/Button.hx",91,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(91)
		if ((this->_enabled)){
			HX_STACK_LINE(91)
			this->_redraw((int)2187531);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Button_obj,_onMouseUpOutside,(void))

Void Button_obj::_onMouseOver( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","_onMouseOver",0xd49270ec,"com.arm.demo.widgets.Button._onMouseOver","com/arm/demo/widgets/Button.hx",95,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(95)
		if ((this->_enabled)){
			HX_STACK_LINE(95)
			this->_redraw((int)13158);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Button_obj,_onMouseOver,(void))

Void Button_obj::_onMouseOut( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","_onMouseOut",0x83d2bbf6,"com.arm.demo.widgets.Button._onMouseOut","com/arm/demo/widgets/Button.hx",99,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(99)
		if ((this->_enabled)){
			HX_STACK_LINE(99)
			this->_redraw((int)2187531);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Button_obj,_onMouseOut,(void))

Void Button_obj::_onTouchEndOutside( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","_onTouchEndOutside",0x9cd01a3c,"com.arm.demo.widgets.Button._onTouchEndOutside","com/arm/demo/widgets/Button.hx",103,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(103)
		if ((this->_enabled)){
			HX_STACK_LINE(103)
			this->_redraw((int)2187531);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Button_obj,_onTouchEndOutside,(void))

Void Button_obj::_onTouchEnd( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","_onTouchEnd",0xdfbe99e9,"com.arm.demo.widgets.Button._onTouchEnd","com/arm/demo/widgets/Button.hx",107,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(107)
		if ((this->_enabled)){
			HX_STACK_LINE(108)
			this->_redraw((int)2187531);
			HX_STACK_LINE(109)
			this->action->dispatch(this->_data);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Button_obj,_onTouchEnd,(void))

Void Button_obj::_onTouchStart( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","_onTouchStart",0x539929f0,"com.arm.demo.widgets.Button._onTouchStart","com/arm/demo/widgets/Button.hx",114,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(114)
		if ((this->_enabled)){
			HX_STACK_LINE(114)
			this->_redraw((int)13158);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Button_obj,_onTouchStart,(void))

Void Button_obj::enable( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","enable",0x0dbe49b4,"com.arm.demo.widgets.Button.enable","com/arm/demo/widgets/Button.hx",118,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_LINE(118)
		this->_enabled = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Button_obj,enable,(void))

Void Button_obj::disable( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Button","disable",0x2be99997,"com.arm.demo.widgets.Button.disable","com/arm/demo/widgets/Button.hx",121,0x40a93681)
		HX_STACK_THIS(this)
		HX_STACK_LINE(122)
		this->_redraw((int)2187531);
		HX_STACK_LINE(123)
		this->_enabled = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Button_obj,disable,(void))

int Button_obj::OVER_COLOUR;

int Button_obj::OUT_COLOUR;

::String Button_obj::TEXT_COLOUR;


Button_obj::Button_obj()
{
}

void Button_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Button);
	HX_MARK_MEMBER_NAME(_data,"_data");
	HX_MARK_MEMBER_NAME(_label,"_label");
	HX_MARK_MEMBER_NAME(_rect,"_rect");
	HX_MARK_MEMBER_NAME(_background,"_background");
	HX_MARK_MEMBER_NAME(_enabled,"_enabled");
	HX_MARK_MEMBER_NAME(action,"action");
	::fluid::display::FluidSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Button_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_data,"_data");
	HX_VISIT_MEMBER_NAME(_label,"_label");
	HX_VISIT_MEMBER_NAME(_rect,"_rect");
	HX_VISIT_MEMBER_NAME(_background,"_background");
	HX_VISIT_MEMBER_NAME(_enabled,"_enabled");
	HX_VISIT_MEMBER_NAME(action,"action");
	::fluid::display::FluidSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Button_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { return _data; }
		if (HX_FIELD_EQ(inName,"_rect") ) { return _rect; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_label") ) { return _label; }
		if (HX_FIELD_EQ(inName,"action") ) { return action; }
		if (HX_FIELD_EQ(inName,"enable") ) { return enable_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_redraw") ) { return _redraw_dyn(); }
		if (HX_FIELD_EQ(inName,"setText") ) { return setText_dyn(); }
		if (HX_FIELD_EQ(inName,"disable") ) { return disable_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_enabled") ) { return _enabled; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_onMouseUp") ) { return _onMouseUp_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_background") ) { return _background; }
		if (HX_FIELD_EQ(inName,"_setupLabel") ) { return _setupLabel_dyn(); }
		if (HX_FIELD_EQ(inName,"_onMouseOut") ) { return _onMouseOut_dyn(); }
		if (HX_FIELD_EQ(inName,"_onTouchEnd") ) { return _onTouchEnd_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_onMouseDown") ) { return _onMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"_onMouseOver") ) { return _onMouseOver_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_onTouchStart") ) { return _onTouchStart_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_setupBackground") ) { return _setupBackground_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_onMouseUpOutside") ) { return _onMouseUpOutside_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_onTouchEndOutside") ) { return _onTouchEndOutside_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Button_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { _data=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_rect") ) { _rect=inValue.Cast< ::fluid::geom::FluidRectangle >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_label") ) { _label=inValue.Cast< ::fluid::text::FluidText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"action") ) { action=inValue.Cast< ::msignal::Signal1 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_enabled") ) { _enabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_background") ) { _background=inValue.Cast< ::fluid::display::FluidGraphics >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Button_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_data"));
	outFields->push(HX_CSTRING("_label"));
	outFields->push(HX_CSTRING("_rect"));
	outFields->push(HX_CSTRING("_background"));
	outFields->push(HX_CSTRING("_enabled"));
	outFields->push(HX_CSTRING("action"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("OVER_COLOUR"),
	HX_CSTRING("OUT_COLOUR"),
	HX_CSTRING("TEXT_COLOUR"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Button_obj,_data),HX_CSTRING("_data")},
	{hx::fsObject /*::fluid::text::FluidText*/ ,(int)offsetof(Button_obj,_label),HX_CSTRING("_label")},
	{hx::fsObject /*::fluid::geom::FluidRectangle*/ ,(int)offsetof(Button_obj,_rect),HX_CSTRING("_rect")},
	{hx::fsObject /*::fluid::display::FluidGraphics*/ ,(int)offsetof(Button_obj,_background),HX_CSTRING("_background")},
	{hx::fsBool,(int)offsetof(Button_obj,_enabled),HX_CSTRING("_enabled")},
	{hx::fsObject /*::msignal::Signal1*/ ,(int)offsetof(Button_obj,action),HX_CSTRING("action")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_data"),
	HX_CSTRING("_label"),
	HX_CSTRING("_rect"),
	HX_CSTRING("_background"),
	HX_CSTRING("_enabled"),
	HX_CSTRING("action"),
	HX_CSTRING("_setupBackground"),
	HX_CSTRING("_setupLabel"),
	HX_CSTRING("_redraw"),
	HX_CSTRING("setText"),
	HX_CSTRING("_onMouseDown"),
	HX_CSTRING("_onMouseUp"),
	HX_CSTRING("_onMouseUpOutside"),
	HX_CSTRING("_onMouseOver"),
	HX_CSTRING("_onMouseOut"),
	HX_CSTRING("_onTouchEndOutside"),
	HX_CSTRING("_onTouchEnd"),
	HX_CSTRING("_onTouchStart"),
	HX_CSTRING("enable"),
	HX_CSTRING("disable"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Button_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Button_obj::OVER_COLOUR,"OVER_COLOUR");
	HX_MARK_MEMBER_NAME(Button_obj::OUT_COLOUR,"OUT_COLOUR");
	HX_MARK_MEMBER_NAME(Button_obj::TEXT_COLOUR,"TEXT_COLOUR");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Button_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Button_obj::OVER_COLOUR,"OVER_COLOUR");
	HX_VISIT_MEMBER_NAME(Button_obj::OUT_COLOUR,"OUT_COLOUR");
	HX_VISIT_MEMBER_NAME(Button_obj::TEXT_COLOUR,"TEXT_COLOUR");
};

#endif

Class Button_obj::__mClass;

void Button_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.widgets.Button"), hx::TCanCast< Button_obj> ,sStaticFields,sMemberFields,
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

void Button_obj::__boot()
{
	OVER_COLOUR= (int)13158;
	OUT_COLOUR= (int)2187531;
	TEXT_COLOUR= HX_CSTRING("#FFFFFF");
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace widgets
