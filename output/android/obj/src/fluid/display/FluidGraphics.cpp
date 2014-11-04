#include <hxcpp.h>

#ifndef INCLUDED_fluid_display_FluidGraphics
#include <fluid/display/FluidGraphics.h>
#endif
#ifndef INCLUDED_fluid_events_EventData
#include <fluid/events/EventData.h>
#endif
#ifndef INCLUDED_openfl__v2_display_CapsStyle
#include <openfl/_v2/display/CapsStyle.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Graphics
#include <openfl/_v2/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_JointStyle
#include <openfl/_v2/display/JointStyle.h>
#endif
#ifndef INCLUDED_openfl__v2_display_LineScaleMode
#include <openfl/_v2/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_events_Event
#include <openfl/_v2/events/Event.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_MouseEvent
#include <openfl/_v2/events/MouseEvent.h>
#endif
#ifndef INCLUDED_openfl__v2_events_TouchEvent
#include <openfl/_v2/events/TouchEvent.h>
#endif
namespace fluid{
namespace display{

Void FluidGraphics_obj::__construct()
{
HX_STACK_FRAME("fluid.display.FluidGraphics","new",0x25bd03b7,"fluid.display.FluidGraphics.new","fluid/display/FluidGraphics.hx",30,0xc8fe2c9b)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(31)
	super::__construct();
	HX_STACK_LINE(47)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_DOWN,this->_fluidOnMouseDown_dyn(),null(),null(),null());
	HX_STACK_LINE(48)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_OVER,this->_fluidOnMouseOver_dyn(),null(),null(),null());
	HX_STACK_LINE(49)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_OUT,this->_fluidOnMouseOut_dyn(),null(),null(),null());
	HX_STACK_LINE(50)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP,this->_fluidOnMouseUp_dyn(),null(),null(),null());
	HX_STACK_LINE(51)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_MOVE,this->_fluidOnMouseMove_dyn(),null(),null(),null());
	HX_STACK_LINE(52)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::CLICK,this->_fluidOnMouseClick_dyn(),null(),null(),null());
	HX_STACK_LINE(53)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::RIGHT_CLICK,this->_fluidOnRightClick_dyn(),null(),null(),null());
	HX_STACK_LINE(54)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::RIGHT_MOUSE_DOWN,this->_fluidOnRightMouseDown_dyn(),null(),null(),null());
	HX_STACK_LINE(55)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::RIGHT_MOUSE_UP,this->_fluidOnRightMouseUp_dyn(),null(),null(),null());
	HX_STACK_LINE(56)
	this->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_BEGIN,this->_fluidOnTouchBegin_dyn(),null(),null(),null());
	HX_STACK_LINE(57)
	this->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_END,this->_fluidOnTouchEnd_dyn(),null(),null(),null());
	HX_STACK_LINE(58)
	this->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_OUT,this->_fluidOnTouchOut_dyn(),null(),null(),null());
	HX_STACK_LINE(59)
	this->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_MOVE,this->_fluidOnTouchMove_dyn(),null(),null(),null());
}
;
	return null();
}

//FluidGraphics_obj::~FluidGraphics_obj() { }

Dynamic FluidGraphics_obj::__CreateEmpty() { return  new FluidGraphics_obj; }
hx::ObjectPtr< FluidGraphics_obj > FluidGraphics_obj::__new()
{  hx::ObjectPtr< FluidGraphics_obj > result = new FluidGraphics_obj();
	result->__construct();
	return result;}

Dynamic FluidGraphics_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FluidGraphics_obj > result = new FluidGraphics_obj();
	result->__construct();
	return result;}

bool FluidGraphics_obj::set_interactive( bool val){
	HX_STACK_FRAME("fluid.display.FluidGraphics","set_interactive",0x255acc5c,"fluid.display.FluidGraphics.set_interactive","fluid/display/FluidGraphics.hx",24,0xc8fe2c9b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(val,"val")
	HX_STACK_LINE(25)
	this->set_mouseEnabled(val);
	HX_STACK_LINE(26)
	return this->interactive = val;
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,set_interactive,return )

Void FluidGraphics_obj::_fluidOnMouseDown( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnMouseDown",0x367c0614,"fluid.display.FluidGraphics._fluidOnMouseDown","fluid/display/FluidGraphics.hx",63,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(63)
		if (((this->mouseDown_dyn() != null()))){
			HX_STACK_LINE(63)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(63)
			this->mouseDown(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnMouseDown,(void))

Void FluidGraphics_obj::_fluidOnMouseOver( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnMouseOver",0x3dc69f06,"fluid.display.FluidGraphics._fluidOnMouseOver","fluid/display/FluidGraphics.hx",64,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(64)
		if (((this->mouseOver_dyn() != null()))){
			HX_STACK_LINE(64)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(64)
			this->mouseOver(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnMouseOver,(void))

Void FluidGraphics_obj::_fluidOnMouseOut( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnMouseOut",0xad9f4f1c,"fluid.display.FluidGraphics._fluidOnMouseOut","fluid/display/FluidGraphics.hx",65,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(65)
		if (((this->mouseOut_dyn() != null()))){
			HX_STACK_LINE(65)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(65)
			this->mouseOut(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnMouseOut,(void))

Void FluidGraphics_obj::_fluidOnMouseUp( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnMouseUp",0xb2b7438d,"fluid.display.FluidGraphics._fluidOnMouseUp","fluid/display/FluidGraphics.hx",66,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(66)
		if (((this->mouseUp_dyn() != null()))){
			HX_STACK_LINE(66)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(66)
			this->mouseUp(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnMouseUp,(void))

Void FluidGraphics_obj::_fluidOnMouseMove( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnMouseMove",0x3c6ef0c3,"fluid.display.FluidGraphics._fluidOnMouseMove","fluid/display/FluidGraphics.hx",67,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(67)
		if (((this->mouseMove_dyn() != null()))){
			HX_STACK_LINE(67)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(67)
			this->mouseMove(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnMouseMove,(void))

Void FluidGraphics_obj::_fluidOnMouseClick( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnMouseClick",0xe09c6a56,"fluid.display.FluidGraphics._fluidOnMouseClick","fluid/display/FluidGraphics.hx",68,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(68)
		if (((this->mouseClick_dyn() != null()))){
			HX_STACK_LINE(68)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(68)
			this->mouseClick(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnMouseClick,(void))

Void FluidGraphics_obj::_fluidOnRightClick( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnRightClick",0xc5945d3f,"fluid.display.FluidGraphics._fluidOnRightClick","fluid/display/FluidGraphics.hx",69,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(69)
		if (((this->rightClick_dyn() != null()))){
			HX_STACK_LINE(69)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(69)
			this->rightClick(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnRightClick,(void))

Void FluidGraphics_obj::_fluidOnRightMouseDown( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnRightMouseDown",0xa461d99e,"fluid.display.FluidGraphics._fluidOnRightMouseDown","fluid/display/FluidGraphics.hx",70,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(70)
		if (((this->rightMouseDown_dyn() != null()))){
			HX_STACK_LINE(70)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(70)
			this->rightMouseDown(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnRightMouseDown,(void))

Void FluidGraphics_obj::_fluidOnRightMouseUp( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnRightMouseUp",0x5f9c4097,"fluid.display.FluidGraphics._fluidOnRightMouseUp","fluid/display/FluidGraphics.hx",71,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(71)
		if (((this->rightMouseUp_dyn() != null()))){
			HX_STACK_LINE(71)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(71)
			this->rightMouseUp(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnRightMouseUp,(void))

Void FluidGraphics_obj::_fluidOnTouchBegin( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnTouchBegin",0x2457c85d,"fluid.display.FluidGraphics._fluidOnTouchBegin","fluid/display/FluidGraphics.hx",72,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(72)
		if (((this->touchBegin_dyn() != null()))){
			HX_STACK_LINE(72)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(72)
			this->touchBegin(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnTouchBegin,(void))

Void FluidGraphics_obj::_fluidOnTouchEnd( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnTouchEnd",0x098b2d0f,"fluid.display.FluidGraphics._fluidOnTouchEnd","fluid/display/FluidGraphics.hx",73,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(73)
		if (((this->touchEnd_dyn() != null()))){
			HX_STACK_LINE(73)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(73)
			this->touchEnd(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnTouchEnd,(void))

Void FluidGraphics_obj::_fluidOnTouchOut( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnTouchOut",0x0992c9c2,"fluid.display.FluidGraphics._fluidOnTouchOut","fluid/display/FluidGraphics.hx",74,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(74)
		if (((this->touchOut_dyn() != null()))){
			HX_STACK_LINE(74)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(74)
			this->touchOut(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnTouchOut,(void))

Void FluidGraphics_obj::_fluidOnTouchMove( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","_fluidOnTouchMove",0x5586c75d,"fluid.display.FluidGraphics._fluidOnTouchMove","fluid/display/FluidGraphics.hx",75,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(75)
		if (((this->touchMove_dyn() != null()))){
			HX_STACK_LINE(75)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(75)
			this->touchMove(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_fluidOnTouchMove,(void))

::fluid::events::EventData FluidGraphics_obj::_prepareEventData( Dynamic data){
	HX_STACK_FRAME("fluid.display.FluidGraphics","_prepareEventData",0x52eb70d3,"fluid.display.FluidGraphics._prepareEventData","fluid/display/FluidGraphics.hx",77,0xc8fe2c9b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(data,"data")
	HX_STACK_LINE(78)
	::fluid::events::EventData evtData = ::fluid::events::EventData_obj::__new();		HX_STACK_VAR(evtData,"evtData");
	HX_STACK_LINE(79)
	evtData->localX = data->__Field(HX_CSTRING("localX"),true);
	HX_STACK_LINE(80)
	evtData->localY = data->__Field(HX_CSTRING("localY"),true);
	HX_STACK_LINE(81)
	evtData->stageX = data->__Field(HX_CSTRING("stageX"),true);
	HX_STACK_LINE(82)
	evtData->stageY = data->__Field(HX_CSTRING("stageY"),true);
	HX_STACK_LINE(83)
	evtData->target = data->__Field(HX_CSTRING("target"),true);
	HX_STACK_LINE(84)
	return evtData;
}


HX_DEFINE_DYNAMIC_FUNC1(FluidGraphics_obj,_prepareEventData,return )

Void FluidGraphics_obj::clear( ){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","clear",0x80f968a4,"fluid.display.FluidGraphics.clear","fluid/display/FluidGraphics.hx",89,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(89)
		this->get_graphics()->clear();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FluidGraphics_obj,clear,(void))

Void FluidGraphics_obj::beginFill( int fill,Dynamic __o_alpha){
Dynamic alpha = __o_alpha.Default(1);
	HX_STACK_FRAME("fluid.display.FluidGraphics","beginFill",0x0f327be3,"fluid.display.FluidGraphics.beginFill","fluid/display/FluidGraphics.hx",92,0xc8fe2c9b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(fill,"fill")
	HX_STACK_ARG(alpha,"alpha")
{
		HX_STACK_LINE(94)
		this->get_graphics()->beginFill(fill,null());
		HX_STACK_LINE(94)
		this->set_alpha(alpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FluidGraphics_obj,beginFill,(void))

Void FluidGraphics_obj::endFill( ){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","endFill",0x3b3bb2d5,"fluid.display.FluidGraphics.endFill","fluid/display/FluidGraphics.hx",99,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(99)
		this->get_graphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FluidGraphics_obj,endFill,(void))

Void FluidGraphics_obj::drawRect( Float x,Float y,Float w,Float h){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","drawRect",0xfa7b4891,"fluid.display.FluidGraphics.drawRect","fluid/display/FluidGraphics.hx",104,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(w,"w")
		HX_STACK_ARG(h,"h")
		HX_STACK_LINE(104)
		this->get_graphics()->drawRect(x,y,w,h);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FluidGraphics_obj,drawRect,(void))

Void FluidGraphics_obj::drawCircle( Float x,Float y,Float r){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","drawCircle",0x5e68e2bd,"fluid.display.FluidGraphics.drawCircle","fluid/display/FluidGraphics.hx",109,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(109)
		this->get_graphics()->drawCircle(x,y,r);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FluidGraphics_obj,drawCircle,(void))

Void FluidGraphics_obj::drawEllipse( Float x,Float y,Float w,Float h){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","drawEllipse",0x532d6791,"fluid.display.FluidGraphics.drawEllipse","fluid/display/FluidGraphics.hx",114,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(w,"w")
		HX_STACK_ARG(h,"h")
		HX_STACK_LINE(114)
		this->get_graphics()->drawEllipse(x,y,w,h);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FluidGraphics_obj,drawEllipse,(void))

Void FluidGraphics_obj::drawRoundedRect( Float x,Float y,Float w,Float h,Float r){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","drawRoundedRect",0x1c441024,"fluid.display.FluidGraphics.drawRoundedRect","fluid/display/FluidGraphics.hx",119,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(w,"w")
		HX_STACK_ARG(h,"h")
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(119)
		this->get_graphics()->drawRoundRectComplex(x,y,w,h,r,r,r,r);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(FluidGraphics_obj,drawRoundedRect,(void))

Void FluidGraphics_obj::lineStyle( Float lineWidth,Dynamic __o_color,Dynamic __o_alpha){
Dynamic color = __o_color.Default(0);
Dynamic alpha = __o_alpha.Default(1);
	HX_STACK_FRAME("fluid.display.FluidGraphics","lineStyle",0x4db57734,"fluid.display.FluidGraphics.lineStyle","fluid/display/FluidGraphics.hx",124,0xc8fe2c9b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(lineWidth,"lineWidth")
	HX_STACK_ARG(color,"color")
	HX_STACK_ARG(alpha,"alpha")
{
		HX_STACK_LINE(124)
		this->get_graphics()->lineStyle(lineWidth,color,alpha,null(),null(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FluidGraphics_obj,lineStyle,(void))

Void FluidGraphics_obj::lineTo( Float x,Float y){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","lineTo",0x3e3a8398,"fluid.display.FluidGraphics.lineTo","fluid/display/FluidGraphics.hx",129,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(129)
		this->get_graphics()->lineTo(x,y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FluidGraphics_obj,lineTo,(void))

Void FluidGraphics_obj::moveTo( Float x,Float y){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","moveTo",0x1e470ff5,"fluid.display.FluidGraphics.moveTo","fluid/display/FluidGraphics.hx",134,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(134)
		this->get_graphics()->moveTo(x,y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FluidGraphics_obj,moveTo,(void))


FluidGraphics_obj::FluidGraphics_obj()
{
}

void FluidGraphics_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FluidGraphics);
	HX_MARK_MEMBER_NAME(mouseDown,"mouseDown");
	HX_MARK_MEMBER_NAME(mouseOut,"mouseOut");
	HX_MARK_MEMBER_NAME(mouseOver,"mouseOver");
	HX_MARK_MEMBER_NAME(mouseUp,"mouseUp");
	HX_MARK_MEMBER_NAME(mouseMove,"mouseMove");
	HX_MARK_MEMBER_NAME(mouseClick,"mouseClick");
	HX_MARK_MEMBER_NAME(rightClick,"rightClick");
	HX_MARK_MEMBER_NAME(rightMouseDown,"rightMouseDown");
	HX_MARK_MEMBER_NAME(rightMouseUp,"rightMouseUp");
	HX_MARK_MEMBER_NAME(touchBegin,"touchBegin");
	HX_MARK_MEMBER_NAME(touchEnd,"touchEnd");
	HX_MARK_MEMBER_NAME(touchOut,"touchOut");
	HX_MARK_MEMBER_NAME(touchMove,"touchMove");
	HX_MARK_MEMBER_NAME(interactive,"interactive");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FluidGraphics_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mouseDown,"mouseDown");
	HX_VISIT_MEMBER_NAME(mouseOut,"mouseOut");
	HX_VISIT_MEMBER_NAME(mouseOver,"mouseOver");
	HX_VISIT_MEMBER_NAME(mouseUp,"mouseUp");
	HX_VISIT_MEMBER_NAME(mouseMove,"mouseMove");
	HX_VISIT_MEMBER_NAME(mouseClick,"mouseClick");
	HX_VISIT_MEMBER_NAME(rightClick,"rightClick");
	HX_VISIT_MEMBER_NAME(rightMouseDown,"rightMouseDown");
	HX_VISIT_MEMBER_NAME(rightMouseUp,"rightMouseUp");
	HX_VISIT_MEMBER_NAME(touchBegin,"touchBegin");
	HX_VISIT_MEMBER_NAME(touchEnd,"touchEnd");
	HX_VISIT_MEMBER_NAME(touchOut,"touchOut");
	HX_VISIT_MEMBER_NAME(touchMove,"touchMove");
	HX_VISIT_MEMBER_NAME(interactive,"interactive");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic FluidGraphics_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"lineTo") ) { return lineTo_dyn(); }
		if (HX_FIELD_EQ(inName,"moveTo") ) { return moveTo_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mouseUp") ) { return mouseUp; }
		if (HX_FIELD_EQ(inName,"endFill") ) { return endFill_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mouseOut") ) { return mouseOut; }
		if (HX_FIELD_EQ(inName,"touchEnd") ) { return touchEnd; }
		if (HX_FIELD_EQ(inName,"touchOut") ) { return touchOut; }
		if (HX_FIELD_EQ(inName,"drawRect") ) { return drawRect_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mouseDown") ) { return mouseDown; }
		if (HX_FIELD_EQ(inName,"mouseOver") ) { return mouseOver; }
		if (HX_FIELD_EQ(inName,"mouseMove") ) { return mouseMove; }
		if (HX_FIELD_EQ(inName,"touchMove") ) { return touchMove; }
		if (HX_FIELD_EQ(inName,"beginFill") ) { return beginFill_dyn(); }
		if (HX_FIELD_EQ(inName,"lineStyle") ) { return lineStyle_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mouseClick") ) { return mouseClick; }
		if (HX_FIELD_EQ(inName,"rightClick") ) { return rightClick; }
		if (HX_FIELD_EQ(inName,"touchBegin") ) { return touchBegin; }
		if (HX_FIELD_EQ(inName,"drawCircle") ) { return drawCircle_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"interactive") ) { return interactive; }
		if (HX_FIELD_EQ(inName,"drawEllipse") ) { return drawEllipse_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"rightMouseUp") ) { return rightMouseUp; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"rightMouseDown") ) { return rightMouseDown; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_interactive") ) { return set_interactive_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnMouseUp") ) { return _fluidOnMouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"drawRoundedRect") ) { return drawRoundedRect_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_fluidOnMouseOut") ) { return _fluidOnMouseOut_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnTouchEnd") ) { return _fluidOnTouchEnd_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnTouchOut") ) { return _fluidOnTouchOut_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_fluidOnMouseDown") ) { return _fluidOnMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnMouseOver") ) { return _fluidOnMouseOver_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnMouseMove") ) { return _fluidOnMouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnTouchMove") ) { return _fluidOnTouchMove_dyn(); }
		if (HX_FIELD_EQ(inName,"_prepareEventData") ) { return _prepareEventData_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_fluidOnMouseClick") ) { return _fluidOnMouseClick_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnRightClick") ) { return _fluidOnRightClick_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnTouchBegin") ) { return _fluidOnTouchBegin_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_fluidOnRightMouseUp") ) { return _fluidOnRightMouseUp_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_fluidOnRightMouseDown") ) { return _fluidOnRightMouseDown_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FluidGraphics_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"mouseUp") ) { mouseUp=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mouseOut") ) { mouseOut=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchEnd") ) { touchEnd=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchOut") ) { touchOut=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mouseDown") ) { mouseDown=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseOver") ) { mouseOver=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseMove") ) { mouseMove=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchMove") ) { touchMove=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mouseClick") ) { mouseClick=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rightClick") ) { rightClick=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchBegin") ) { touchBegin=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"interactive") ) { if (inCallProp) return set_interactive(inValue);interactive=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"rightMouseUp") ) { rightMouseUp=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"rightMouseDown") ) { rightMouseDown=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FluidGraphics_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("interactive"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,mouseDown),HX_CSTRING("mouseDown")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,mouseOut),HX_CSTRING("mouseOut")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,mouseOver),HX_CSTRING("mouseOver")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,mouseUp),HX_CSTRING("mouseUp")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,mouseMove),HX_CSTRING("mouseMove")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,mouseClick),HX_CSTRING("mouseClick")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,rightClick),HX_CSTRING("rightClick")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,rightMouseDown),HX_CSTRING("rightMouseDown")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,rightMouseUp),HX_CSTRING("rightMouseUp")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,touchBegin),HX_CSTRING("touchBegin")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,touchEnd),HX_CSTRING("touchEnd")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,touchOut),HX_CSTRING("touchOut")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidGraphics_obj,touchMove),HX_CSTRING("touchMove")},
	{hx::fsBool,(int)offsetof(FluidGraphics_obj,interactive),HX_CSTRING("interactive")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("mouseDown"),
	HX_CSTRING("mouseOut"),
	HX_CSTRING("mouseOver"),
	HX_CSTRING("mouseUp"),
	HX_CSTRING("mouseMove"),
	HX_CSTRING("mouseClick"),
	HX_CSTRING("rightClick"),
	HX_CSTRING("rightMouseDown"),
	HX_CSTRING("rightMouseUp"),
	HX_CSTRING("touchBegin"),
	HX_CSTRING("touchEnd"),
	HX_CSTRING("touchOut"),
	HX_CSTRING("touchMove"),
	HX_CSTRING("interactive"),
	HX_CSTRING("set_interactive"),
	HX_CSTRING("_fluidOnMouseDown"),
	HX_CSTRING("_fluidOnMouseOver"),
	HX_CSTRING("_fluidOnMouseOut"),
	HX_CSTRING("_fluidOnMouseUp"),
	HX_CSTRING("_fluidOnMouseMove"),
	HX_CSTRING("_fluidOnMouseClick"),
	HX_CSTRING("_fluidOnRightClick"),
	HX_CSTRING("_fluidOnRightMouseDown"),
	HX_CSTRING("_fluidOnRightMouseUp"),
	HX_CSTRING("_fluidOnTouchBegin"),
	HX_CSTRING("_fluidOnTouchEnd"),
	HX_CSTRING("_fluidOnTouchOut"),
	HX_CSTRING("_fluidOnTouchMove"),
	HX_CSTRING("_prepareEventData"),
	HX_CSTRING("clear"),
	HX_CSTRING("beginFill"),
	HX_CSTRING("endFill"),
	HX_CSTRING("drawRect"),
	HX_CSTRING("drawCircle"),
	HX_CSTRING("drawEllipse"),
	HX_CSTRING("drawRoundedRect"),
	HX_CSTRING("lineStyle"),
	HX_CSTRING("lineTo"),
	HX_CSTRING("moveTo"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FluidGraphics_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FluidGraphics_obj::__mClass,"__mClass");
};

#endif

Class FluidGraphics_obj::__mClass;

void FluidGraphics_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.display.FluidGraphics"), hx::TCanCast< FluidGraphics_obj> ,sStaticFields,sMemberFields,
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

void FluidGraphics_obj::__boot()
{
}

} // end namespace fluid
} // end namespace display
