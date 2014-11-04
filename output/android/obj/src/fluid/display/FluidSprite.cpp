#include <hxcpp.h>

#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
#endif
#ifndef INCLUDED_fluid_events_EventData
#include <fluid/events/EventData.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Bitmap
#include <openfl/_v2/display/Bitmap.h>
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
#ifndef INCLUDED_openfl_display_PixelSnapping
#include <openfl/display/PixelSnapping.h>
#endif
namespace fluid{
namespace display{

Void FluidSprite_obj::__construct(::openfl::_v2::display::BitmapData texture)
{
HX_STACK_FRAME("fluid.display.FluidSprite","new",0x6e411971,"fluid.display.FluidSprite.new","fluid/display/FluidSprite.hx",32,0x63bd07a1)
HX_STACK_THIS(this)
HX_STACK_ARG(texture,"texture")
{
	HX_STACK_LINE(33)
	super::__construct();
	HX_STACK_LINE(34)
	if (((texture != null()))){
		HX_STACK_LINE(38)
		this->set_mouseChildren(false);
		HX_STACK_LINE(39)
		::openfl::_v2::display::Bitmap _g = ::openfl::_v2::display::Bitmap_obj::__new(texture,null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(39)
		this->_texture = _g;
		HX_STACK_LINE(41)
		this->addChild(this->_texture);
	}
	HX_STACK_LINE(59)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_DOWN,this->_fluidOnMouseDown_dyn(),null(),null(),null());
	HX_STACK_LINE(60)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_OVER,this->_fluidOnMouseOver_dyn(),null(),null(),null());
	HX_STACK_LINE(61)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_OUT,this->_fluidOnMouseOut_dyn(),null(),null(),null());
	HX_STACK_LINE(62)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP,this->_fluidOnMouseUp_dyn(),null(),null(),null());
	HX_STACK_LINE(63)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_MOVE,this->_fluidOnMouseMove_dyn(),null(),null(),null());
	HX_STACK_LINE(64)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::CLICK,this->_fluidOnMouseClick_dyn(),null(),null(),null());
	HX_STACK_LINE(65)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::RIGHT_CLICK,this->_fluidOnRightClick_dyn(),null(),null(),null());
	HX_STACK_LINE(66)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::RIGHT_MOUSE_DOWN,this->_fluidOnRightMouseDown_dyn(),null(),null(),null());
	HX_STACK_LINE(67)
	this->addEventListener(::openfl::_v2::events::MouseEvent_obj::RIGHT_MOUSE_UP,this->_fluidOnRightMouseUp_dyn(),null(),null(),null());
	HX_STACK_LINE(68)
	this->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_BEGIN,this->_fluidOnTouchBegin_dyn(),null(),null(),null());
	HX_STACK_LINE(69)
	this->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_END,this->_fluidOnTouchEnd_dyn(),null(),null(),null());
	HX_STACK_LINE(70)
	this->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_OUT,this->_fluidOnTouchOut_dyn(),null(),null(),null());
	HX_STACK_LINE(71)
	this->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_MOVE,this->_fluidOnTouchMove_dyn(),null(),null(),null());
}
;
	return null();
}

//FluidSprite_obj::~FluidSprite_obj() { }

Dynamic FluidSprite_obj::__CreateEmpty() { return  new FluidSprite_obj; }
hx::ObjectPtr< FluidSprite_obj > FluidSprite_obj::__new(::openfl::_v2::display::BitmapData texture)
{  hx::ObjectPtr< FluidSprite_obj > result = new FluidSprite_obj();
	result->__construct(texture);
	return result;}

Dynamic FluidSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FluidSprite_obj > result = new FluidSprite_obj();
	result->__construct(inArgs[0]);
	return result;}

bool FluidSprite_obj::set_interactive( bool val){
	HX_STACK_FRAME("fluid.display.FluidSprite","set_interactive",0x9c059116,"fluid.display.FluidSprite.set_interactive","fluid/display/FluidSprite.hx",26,0x63bd07a1)
	HX_STACK_THIS(this)
	HX_STACK_ARG(val,"val")
	HX_STACK_LINE(27)
	this->set_mouseEnabled(val);
	HX_STACK_LINE(28)
	return this->interactive = val;
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,set_interactive,return )

Void FluidSprite_obj::_fluidOnMouseDown( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnMouseDown",0xc0eced4e,"fluid.display.FluidSprite._fluidOnMouseDown","fluid/display/FluidSprite.hx",75,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(75)
		if (((this->mouseDown_dyn() != null()))){
			HX_STACK_LINE(75)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(75)
			this->mouseDown(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnMouseDown,(void))

Void FluidSprite_obj::_fluidOnMouseOver( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnMouseOver",0xc8378640,"fluid.display.FluidSprite._fluidOnMouseOver","fluid/display/FluidSprite.hx",76,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(76)
		if (((this->mouseOver_dyn() != null()))){
			HX_STACK_LINE(76)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(76)
			this->mouseOver(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnMouseOver,(void))

Void FluidSprite_obj::_fluidOnMouseOut( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnMouseOut",0x0c60ad22,"fluid.display.FluidSprite._fluidOnMouseOut","fluid/display/FluidSprite.hx",77,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(77)
		if (((this->mouseOut_dyn() != null()))){
			HX_STACK_LINE(77)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(77)
			this->mouseOut(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnMouseOut,(void))

Void FluidSprite_obj::_fluidOnMouseUp( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnMouseUp",0x29620847,"fluid.display.FluidSprite._fluidOnMouseUp","fluid/display/FluidSprite.hx",78,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(78)
		if (((this->mouseUp_dyn() != null()))){
			HX_STACK_LINE(78)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(78)
			this->mouseUp(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnMouseUp,(void))

Void FluidSprite_obj::_fluidOnMouseMove( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnMouseMove",0xc6dfd7fd,"fluid.display.FluidSprite._fluidOnMouseMove","fluid/display/FluidSprite.hx",79,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(79)
		if (((this->mouseMove_dyn() != null()))){
			HX_STACK_LINE(79)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(79)
			this->mouseMove(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnMouseMove,(void))

Void FluidSprite_obj::_fluidOnMouseClick( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnMouseClick",0x78f5d5dc,"fluid.display.FluidSprite._fluidOnMouseClick","fluid/display/FluidSprite.hx",80,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(80)
		if (((this->mouseClick_dyn() != null()))){
			HX_STACK_LINE(80)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(80)
			this->mouseClick(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnMouseClick,(void))

Void FluidSprite_obj::_fluidOnRightClick( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnRightClick",0x5dedc8c5,"fluid.display.FluidSprite._fluidOnRightClick","fluid/display/FluidSprite.hx",81,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(81)
		if (((this->rightClick_dyn() != null()))){
			HX_STACK_LINE(81)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(81)
			this->rightClick(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnRightClick,(void))

Void FluidSprite_obj::_fluidOnRightMouseDown( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnRightMouseDown",0xe4fe8024,"fluid.display.FluidSprite._fluidOnRightMouseDown","fluid/display/FluidSprite.hx",82,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(82)
		if (((this->rightMouseDown_dyn() != null()))){
			HX_STACK_LINE(82)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(82)
			this->rightMouseDown(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnRightMouseDown,(void))

Void FluidSprite_obj::_fluidOnRightMouseUp( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnRightMouseUp",0xd1cc199d,"fluid.display.FluidSprite._fluidOnRightMouseUp","fluid/display/FluidSprite.hx",83,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(83)
		if (((this->rightMouseUp_dyn() != null()))){
			HX_STACK_LINE(83)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(83)
			this->rightMouseUp(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnRightMouseUp,(void))

Void FluidSprite_obj::_fluidOnTouchBegin( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnTouchBegin",0xbcb133e3,"fluid.display.FluidSprite._fluidOnTouchBegin","fluid/display/FluidSprite.hx",84,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(84)
		if (((this->touchBegin_dyn() != null()))){
			HX_STACK_LINE(84)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(84)
			this->touchBegin(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnTouchBegin,(void))

Void FluidSprite_obj::_fluidOnTouchEnd( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnTouchEnd",0x684c8b15,"fluid.display.FluidSprite._fluidOnTouchEnd","fluid/display/FluidSprite.hx",85,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(85)
		if (((this->touchEnd_dyn() != null()))){
			HX_STACK_LINE(85)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(85)
			this->touchEnd(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnTouchEnd,(void))

Void FluidSprite_obj::_fluidOnTouchOut( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnTouchOut",0x685427c8,"fluid.display.FluidSprite._fluidOnTouchOut","fluid/display/FluidSprite.hx",86,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(86)
		if (((this->touchOut_dyn() != null()))){
			HX_STACK_LINE(86)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(86)
			this->touchOut(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnTouchOut,(void))

Void FluidSprite_obj::_fluidOnTouchMove( Dynamic evt){
{
		HX_STACK_FRAME("fluid.display.FluidSprite","_fluidOnTouchMove",0xdff7ae97,"fluid.display.FluidSprite._fluidOnTouchMove","fluid/display/FluidSprite.hx",87,0x63bd07a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(87)
		if (((this->touchMove_dyn() != null()))){
			HX_STACK_LINE(87)
			::fluid::events::EventData _g = this->_prepareEventData(evt);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(87)
			this->touchMove(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_fluidOnTouchMove,(void))

::fluid::events::EventData FluidSprite_obj::_prepareEventData( Dynamic data){
	HX_STACK_FRAME("fluid.display.FluidSprite","_prepareEventData",0xdd5c580d,"fluid.display.FluidSprite._prepareEventData","fluid/display/FluidSprite.hx",89,0x63bd07a1)
	HX_STACK_THIS(this)
	HX_STACK_ARG(data,"data")
	HX_STACK_LINE(90)
	::fluid::events::EventData evtData = ::fluid::events::EventData_obj::__new();		HX_STACK_VAR(evtData,"evtData");
	HX_STACK_LINE(91)
	evtData->localX = data->__Field(HX_CSTRING("localX"),true);
	HX_STACK_LINE(92)
	evtData->localY = data->__Field(HX_CSTRING("localY"),true);
	HX_STACK_LINE(93)
	evtData->stageX = data->__Field(HX_CSTRING("stageX"),true);
	HX_STACK_LINE(94)
	evtData->stageY = data->__Field(HX_CSTRING("stageY"),true);
	HX_STACK_LINE(95)
	evtData->target = data->__Field(HX_CSTRING("target"),true);
	HX_STACK_LINE(96)
	return evtData;
}


HX_DEFINE_DYNAMIC_FUNC1(FluidSprite_obj,_prepareEventData,return )


FluidSprite_obj::FluidSprite_obj()
{
}

void FluidSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FluidSprite);
	HX_MARK_MEMBER_NAME(_texture,"_texture");
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

void FluidSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_texture,"_texture");
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

Dynamic FluidSprite_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"mouseUp") ) { return mouseUp; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_texture") ) { return _texture; }
		if (HX_FIELD_EQ(inName,"mouseOut") ) { return mouseOut; }
		if (HX_FIELD_EQ(inName,"touchEnd") ) { return touchEnd; }
		if (HX_FIELD_EQ(inName,"touchOut") ) { return touchOut; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mouseDown") ) { return mouseDown; }
		if (HX_FIELD_EQ(inName,"mouseOver") ) { return mouseOver; }
		if (HX_FIELD_EQ(inName,"mouseMove") ) { return mouseMove; }
		if (HX_FIELD_EQ(inName,"touchMove") ) { return touchMove; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mouseClick") ) { return mouseClick; }
		if (HX_FIELD_EQ(inName,"rightClick") ) { return rightClick; }
		if (HX_FIELD_EQ(inName,"touchBegin") ) { return touchBegin; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"interactive") ) { return interactive; }
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

Dynamic FluidSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"mouseUp") ) { mouseUp=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_texture") ) { _texture=inValue.Cast< ::openfl::_v2::display::Bitmap >(); return inValue; }
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

void FluidSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_texture"));
	outFields->push(HX_CSTRING("interactive"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::openfl::_v2::display::Bitmap*/ ,(int)offsetof(FluidSprite_obj,_texture),HX_CSTRING("_texture")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,mouseDown),HX_CSTRING("mouseDown")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,mouseOut),HX_CSTRING("mouseOut")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,mouseOver),HX_CSTRING("mouseOver")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,mouseUp),HX_CSTRING("mouseUp")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,mouseMove),HX_CSTRING("mouseMove")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,mouseClick),HX_CSTRING("mouseClick")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,rightClick),HX_CSTRING("rightClick")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,rightMouseDown),HX_CSTRING("rightMouseDown")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,rightMouseUp),HX_CSTRING("rightMouseUp")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,touchBegin),HX_CSTRING("touchBegin")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,touchEnd),HX_CSTRING("touchEnd")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,touchOut),HX_CSTRING("touchOut")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FluidSprite_obj,touchMove),HX_CSTRING("touchMove")},
	{hx::fsBool,(int)offsetof(FluidSprite_obj,interactive),HX_CSTRING("interactive")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_texture"),
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
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FluidSprite_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FluidSprite_obj::__mClass,"__mClass");
};

#endif

Class FluidSprite_obj::__mClass;

void FluidSprite_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.display.FluidSprite"), hx::TCanCast< FluidSprite_obj> ,sStaticFields,sMemberFields,
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

void FluidSprite_obj::__boot()
{
}

} // end namespace fluid
} // end namespace display
