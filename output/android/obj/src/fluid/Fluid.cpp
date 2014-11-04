#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
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
#ifndef INCLUDED_openfl__v2_display_Stage
#include <openfl/_v2/display/Stage.h>
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
#ifndef INCLUDED_openfl__v2_system_Capabilities
#include <openfl/_v2/system/Capabilities.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextField
#include <openfl/_v2/text/TextField.h>
#endif
#ifndef INCLUDED_openfl_display_FPS
#include <openfl/display/FPS.h>
#endif
namespace fluid{

Void Fluid_obj::__construct()
{
HX_STACK_FRAME("fluid.Fluid","new",0xb9023c78,"fluid.Fluid.new","fluid/Fluid.hx",6,0x6b4e62f9)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(30)
	this->backgroundColor = (int)16777215;
	HX_STACK_LINE(29)
	this->stats = false;
	HX_STACK_LINE(28)
	this->skipFrame = false;
	HX_STACK_LINE(13)
	this->_fluidFrameSkip = false;
	HX_STACK_LINE(42)
	::Date _g = ::Date_obj::now();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(42)
	this->_lastTime = _g;
	HX_STACK_LINE(43)
	this->_setStageProperties();
	HX_STACK_LINE(75)
	super::__construct();
	HX_STACK_LINE(76)
	::fluid::display::FluidSprite _g1 = ::fluid::display::FluidSprite_obj::__new(null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(76)
	this->container = _g1;
	HX_STACK_LINE(77)
	this->get_stage()->addEventListener(::openfl::_v2::events::Event_obj::ENTER_FRAME,this->_fluidOnEnterFrame_dyn(),null(),null(),null());
	HX_STACK_LINE(78)
	this->get_stage()->addEventListener(::openfl::_v2::events::Event_obj::RESIZE,this->_fluidOnResize_dyn(),null(),null(),null());
	HX_STACK_LINE(79)
	this->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_DOWN,this->_fluidOnMouseDown_dyn(),null(),null(),null());
	HX_STACK_LINE(80)
	this->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_OVER,this->_fluidOnMouseOver_dyn(),null(),null(),null());
	HX_STACK_LINE(81)
	this->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_OUT,this->_fluidOnMouseOut_dyn(),null(),null(),null());
	HX_STACK_LINE(82)
	this->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP,this->_fluidOnMouseUp_dyn(),null(),null(),null());
	HX_STACK_LINE(83)
	this->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::CLICK,this->_fluidOnMouseClick_dyn(),null(),null(),null());
	HX_STACK_LINE(84)
	this->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::RIGHT_CLICK,this->_fluidOnRightClick_dyn(),null(),null(),null());
	HX_STACK_LINE(85)
	this->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::RIGHT_MOUSE_DOWN,this->_fluidOnRightMouseDown_dyn(),null(),null(),null());
	HX_STACK_LINE(86)
	this->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::RIGHT_MOUSE_UP,this->_fluidOnRightMouseUp_dyn(),null(),null(),null());
	HX_STACK_LINE(87)
	this->get_stage()->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_BEGIN,this->_fluidOnTouchBegin_dyn(),null(),null(),null());
	HX_STACK_LINE(88)
	this->get_stage()->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_END,this->_fluidOnTouchEnd_dyn(),null(),null(),null());
	HX_STACK_LINE(89)
	this->get_stage()->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_OUT,this->_fluidOnTouchOut_dyn(),null(),null(),null());
	HX_STACK_LINE(90)
	this->addChild(this->container);
}
;
	return null();
}

//Fluid_obj::~Fluid_obj() { }

Dynamic Fluid_obj::__CreateEmpty() { return  new Fluid_obj; }
hx::ObjectPtr< Fluid_obj > Fluid_obj::__new()
{  hx::ObjectPtr< Fluid_obj > result = new Fluid_obj();
	result->__construct();
	return result;}

Dynamic Fluid_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Fluid_obj > result = new Fluid_obj();
	result->__construct();
	return result;}

Void Fluid_obj::_setStageProperties( ){
{
		HX_STACK_FRAME("fluid.Fluid","_setStageProperties",0x3c78f706,"fluid.Fluid._setStageProperties","fluid/Fluid.hx",94,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(95)
		Float _g = ::openfl::_v2::system::Capabilities_obj::get_screenDPI();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(95)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(95)
		if (((_g < (int)300))){
			HX_STACK_LINE(95)
			_g1 = (int)1;
		}
		else{
			HX_STACK_LINE(95)
			_g1 = (int)2;
		}
		HX_STACK_LINE(95)
		::fluid::display::FluidStage_obj::pixelRatio = _g1;
		HX_STACK_LINE(96)
		int _g2 = this->get_stage()->get_stageWidth();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(96)
		::fluid::display::FluidStage_obj::screenWidth = _g2;
		HX_STACK_LINE(97)
		int _g3 = this->get_stage()->get_stageHeight();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(97)
		::fluid::display::FluidStage_obj::screenHeight = _g3;
		HX_STACK_LINE(98)
		if (((::fluid::display::FluidStage_obj::screenWidth > ::fluid::display::FluidStage_obj::screenHeight))){
			HX_STACK_LINE(98)
			::fluid::display::FluidStage_obj::orientation = HX_CSTRING("LANDSCAPE");
		}
		else{
			HX_STACK_LINE(98)
			::fluid::display::FluidStage_obj::orientation = HX_CSTRING("PORTRAIT");
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Fluid_obj,_setStageProperties,(void))

int Fluid_obj::set_backgroundColor( int clr){
	HX_STACK_FRAME("fluid.Fluid","set_backgroundColor",0x6d112cd0,"fluid.Fluid.set_backgroundColor","fluid/Fluid.hx",101,0x6b4e62f9)
	HX_STACK_THIS(this)
	HX_STACK_ARG(clr,"clr")
	HX_STACK_LINE(102)
	this->get_stage()->set_color(clr);
	HX_STACK_LINE(103)
	return this->backgroundColor = clr;
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,set_backgroundColor,return )

Void Fluid_obj::_fluidOnMouseDown( ::openfl::_v2::events::MouseEvent evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnMouseDown",0x7526ae95,"fluid.Fluid._fluidOnMouseDown","fluid/Fluid.hx",106,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(106)
		if (((this->mouseDown_dyn() != null()))){
			HX_STACK_LINE(106)
			this->mouseDown(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnMouseDown,(void))

Void Fluid_obj::_fluidOnMouseOver( ::openfl::_v2::events::MouseEvent evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnMouseOver",0x7c714787,"fluid.Fluid._fluidOnMouseOver","fluid/Fluid.hx",107,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(107)
		if (((this->mouseOver_dyn() != null()))){
			HX_STACK_LINE(107)
			this->mouseOver(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnMouseOver,(void))

Void Fluid_obj::_fluidOnMouseOut( ::openfl::_v2::events::MouseEvent evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnMouseOut",0x6222f1bb,"fluid.Fluid._fluidOnMouseOut","fluid/Fluid.hx",108,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(108)
		if (((this->mouseOut_dyn() != null()))){
			HX_STACK_LINE(108)
			this->mouseOut(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnMouseOut,(void))

Void Fluid_obj::_fluidOnMouseUp( ::openfl::_v2::events::MouseEvent evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnMouseUp",0x4b0f19ce,"fluid.Fluid._fluidOnMouseUp","fluid/Fluid.hx",109,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(109)
		if (((this->mouseUp_dyn() != null()))){
			HX_STACK_LINE(109)
			this->mouseUp(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnMouseUp,(void))

Void Fluid_obj::_fluidOnMouseClick( ::openfl::_v2::events::MouseEvent evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnMouseClick",0x774532b5,"fluid.Fluid._fluidOnMouseClick","fluid/Fluid.hx",110,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(110)
		if (((this->mouseClick_dyn() != null()))){
			HX_STACK_LINE(110)
			this->mouseClick(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnMouseClick,(void))

Void Fluid_obj::_fluidOnRightClick( ::openfl::_v2::events::MouseEvent evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnRightClick",0x5c3d259e,"fluid.Fluid._fluidOnRightClick","fluid/Fluid.hx",111,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(111)
		if (((this->rightClick_dyn() != null()))){
			HX_STACK_LINE(111)
			this->rightClick(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnRightClick,(void))

Void Fluid_obj::_fluidOnRightMouseDown( ::openfl::_v2::events::MouseEvent evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnRightMouseDown",0x861fbd7d,"fluid.Fluid._fluidOnRightMouseDown","fluid/Fluid.hx",112,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(112)
		if (((this->rightMouseDown_dyn() != null()))){
			HX_STACK_LINE(112)
			this->rightMouseDown(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnRightMouseDown,(void))

Void Fluid_obj::_fluidOnRightMouseUp( ::openfl::_v2::events::MouseEvent evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnRightMouseUp",0x884f1eb6,"fluid.Fluid._fluidOnRightMouseUp","fluid/Fluid.hx",113,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(113)
		if (((this->rightMouseUp_dyn() != null()))){
			HX_STACK_LINE(113)
			this->rightMouseUp(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnRightMouseUp,(void))

Void Fluid_obj::_fluidOnTouchBegin( ::openfl::_v2::events::TouchEvent evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnTouchBegin",0xbb0090bc,"fluid.Fluid._fluidOnTouchBegin","fluid/Fluid.hx",114,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(114)
		if (((this->touchBegin_dyn() != null()))){
			HX_STACK_LINE(114)
			this->touchBegin(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnTouchBegin,(void))

Void Fluid_obj::_fluidOnTouchEnd( ::openfl::_v2::events::TouchEvent evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnTouchEnd",0xbe0ecfae,"fluid.Fluid._fluidOnTouchEnd","fluid/Fluid.hx",115,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(115)
		if (((this->touchEnd_dyn() != null()))){
			HX_STACK_LINE(115)
			this->touchEnd(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnTouchEnd,(void))

Void Fluid_obj::_fluidOnTouchOut( ::openfl::_v2::events::TouchEvent evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnTouchOut",0xbe166c61,"fluid.Fluid._fluidOnTouchOut","fluid/Fluid.hx",116,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(116)
		if (((this->touchOut_dyn() != null()))){
			HX_STACK_LINE(116)
			this->touchOut(evt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnTouchOut,(void))

Void Fluid_obj::_fluidOnEnterFrame( Dynamic evt){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnEnterFrame",0x1369c6c7,"fluid.Fluid._fluidOnEnterFrame","fluid/Fluid.hx",119,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_LINE(119)
		if (((bool(this->skipFrame) && bool(this->_fluidFrameSkip)))){
			HX_STACK_LINE(119)
			this->_fluidFrameSkip = false;
		}
		else{
			HX_STACK_LINE(121)
			this->_fluidFrameSkip = true;
			HX_STACK_LINE(122)
			this->_fluidCalculateElapsedTime();
			HX_STACK_LINE(123)
			if (((this->update_dyn() != null()))){
				HX_STACK_LINE(123)
				this->update(this->_elapsedTime);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnEnterFrame,(void))

Void Fluid_obj::_fluidOnUpdate( ){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnUpdate",0xe6ecf7db,"fluid.Fluid._fluidOnUpdate","fluid/Fluid.hx",128,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(128)
		if (((bool(this->skipFrame) && bool(this->_fluidFrameSkip)))){
			HX_STACK_LINE(128)
			this->_fluidFrameSkip = false;
		}
		else{
			HX_STACK_LINE(130)
			this->_fluidFrameSkip = true;
			HX_STACK_LINE(131)
			this->_fluidCalculateElapsedTime();
			HX_STACK_LINE(132)
			if (((this->update_dyn() != null()))){
				HX_STACK_LINE(132)
				this->update(this->_elapsedTime);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Fluid_obj,_fluidOnUpdate,(void))

Void Fluid_obj::_fluidCalculateElapsedTime( ){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidCalculateElapsedTime",0xcfd8da76,"fluid.Fluid._fluidCalculateElapsedTime","fluid/Fluid.hx",141,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(142)
		::Date _g = ::Date_obj::now();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(142)
		this->_currentTime = _g;
		HX_STACK_LINE(143)
		Float _g1 = this->_currentTime->getTime();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(143)
		Float _g2 = this->_lastTime->getTime();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(143)
		Float _g3 = (_g1 - _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(143)
		this->_elapsedTime = _g3;
		HX_STACK_LINE(144)
		this->_lastTime = this->_currentTime;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Fluid_obj,_fluidCalculateElapsedTime,(void))

Void Fluid_obj::_fluidOnResize( Dynamic event){
{
		HX_STACK_FRAME("fluid.Fluid","_fluidOnResize",0x6862cbc6,"fluid.Fluid._fluidOnResize","fluid/Fluid.hx",147,0x6b4e62f9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(148)
		this->_setStageProperties();
		HX_STACK_LINE(150)
		if ((this->stats)){
			HX_STACK_LINE(150)
			this->_stats->set_x((::fluid::display::FluidStage_obj::screenWidth - (int)50));
		}
		HX_STACK_LINE(152)
		if (((this->resize_dyn() != null()))){
			HX_STACK_LINE(152)
			this->resize();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,_fluidOnResize,(void))

bool Fluid_obj::set_stats( bool val){
	HX_STACK_FRAME("fluid.Fluid","set_stats",0x0e504c9a,"fluid.Fluid.set_stats","fluid/Fluid.hx",155,0x6b4e62f9)
	HX_STACK_THIS(this)
	HX_STACK_ARG(val,"val")
	HX_STACK_LINE(156)
	if ((val)){
		HX_STACK_LINE(167)
		::openfl::display::FPS _g = ::openfl::display::FPS_obj::__new(null(),null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(167)
		this->_stats = _g;
		HX_STACK_LINE(168)
		this->_stats->set_x((::fluid::display::FluidStage_obj::screenWidth - (int)50));
		HX_STACK_LINE(169)
		this->addChild(this->_stats);
	}
	HX_STACK_LINE(172)
	return this->stats = val;
}


HX_DEFINE_DYNAMIC_FUNC1(Fluid_obj,set_stats,return )


Fluid_obj::Fluid_obj()
{
}

void Fluid_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Fluid);
	HX_MARK_MEMBER_NAME(_canvas,"_canvas");
	HX_MARK_MEMBER_NAME(_renderer,"_renderer");
	HX_MARK_MEMBER_NAME(_lastTime,"_lastTime");
	HX_MARK_MEMBER_NAME(_currentTime,"_currentTime");
	HX_MARK_MEMBER_NAME(_elapsedTime,"_elapsedTime");
	HX_MARK_MEMBER_NAME(_fluidFrameSkip,"_fluidFrameSkip");
	HX_MARK_MEMBER_NAME(mouseDown,"mouseDown");
	HX_MARK_MEMBER_NAME(mouseOut,"mouseOut");
	HX_MARK_MEMBER_NAME(mouseOver,"mouseOver");
	HX_MARK_MEMBER_NAME(mouseUp,"mouseUp");
	HX_MARK_MEMBER_NAME(mouseClick,"mouseClick");
	HX_MARK_MEMBER_NAME(rightClick,"rightClick");
	HX_MARK_MEMBER_NAME(rightMouseDown,"rightMouseDown");
	HX_MARK_MEMBER_NAME(rightMouseUp,"rightMouseUp");
	HX_MARK_MEMBER_NAME(touchBegin,"touchBegin");
	HX_MARK_MEMBER_NAME(touchEnd,"touchEnd");
	HX_MARK_MEMBER_NAME(touchOut,"touchOut");
	HX_MARK_MEMBER_NAME(skipFrame,"skipFrame");
	HX_MARK_MEMBER_NAME(stats,"stats");
	HX_MARK_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_MARK_MEMBER_NAME(update,"update");
	HX_MARK_MEMBER_NAME(resize,"resize");
	HX_MARK_MEMBER_NAME(_fluidStage,"_fluidStage");
	HX_MARK_MEMBER_NAME(container,"container");
	HX_MARK_MEMBER_NAME(_stats,"_stats");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Fluid_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_canvas,"_canvas");
	HX_VISIT_MEMBER_NAME(_renderer,"_renderer");
	HX_VISIT_MEMBER_NAME(_lastTime,"_lastTime");
	HX_VISIT_MEMBER_NAME(_currentTime,"_currentTime");
	HX_VISIT_MEMBER_NAME(_elapsedTime,"_elapsedTime");
	HX_VISIT_MEMBER_NAME(_fluidFrameSkip,"_fluidFrameSkip");
	HX_VISIT_MEMBER_NAME(mouseDown,"mouseDown");
	HX_VISIT_MEMBER_NAME(mouseOut,"mouseOut");
	HX_VISIT_MEMBER_NAME(mouseOver,"mouseOver");
	HX_VISIT_MEMBER_NAME(mouseUp,"mouseUp");
	HX_VISIT_MEMBER_NAME(mouseClick,"mouseClick");
	HX_VISIT_MEMBER_NAME(rightClick,"rightClick");
	HX_VISIT_MEMBER_NAME(rightMouseDown,"rightMouseDown");
	HX_VISIT_MEMBER_NAME(rightMouseUp,"rightMouseUp");
	HX_VISIT_MEMBER_NAME(touchBegin,"touchBegin");
	HX_VISIT_MEMBER_NAME(touchEnd,"touchEnd");
	HX_VISIT_MEMBER_NAME(touchOut,"touchOut");
	HX_VISIT_MEMBER_NAME(skipFrame,"skipFrame");
	HX_VISIT_MEMBER_NAME(stats,"stats");
	HX_VISIT_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_VISIT_MEMBER_NAME(update,"update");
	HX_VISIT_MEMBER_NAME(resize,"resize");
	HX_VISIT_MEMBER_NAME(_fluidStage,"_fluidStage");
	HX_VISIT_MEMBER_NAME(container,"container");
	HX_VISIT_MEMBER_NAME(_stats,"_stats");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Fluid_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"stats") ) { return stats; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize; }
		if (HX_FIELD_EQ(inName,"_stats") ) { return _stats; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_canvas") ) { return _canvas; }
		if (HX_FIELD_EQ(inName,"mouseUp") ) { return mouseUp; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mouseOut") ) { return mouseOut; }
		if (HX_FIELD_EQ(inName,"touchEnd") ) { return touchEnd; }
		if (HX_FIELD_EQ(inName,"touchOut") ) { return touchOut; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_renderer") ) { return _renderer; }
		if (HX_FIELD_EQ(inName,"_lastTime") ) { return _lastTime; }
		if (HX_FIELD_EQ(inName,"mouseDown") ) { return mouseDown; }
		if (HX_FIELD_EQ(inName,"mouseOver") ) { return mouseOver; }
		if (HX_FIELD_EQ(inName,"skipFrame") ) { return skipFrame; }
		if (HX_FIELD_EQ(inName,"container") ) { return container; }
		if (HX_FIELD_EQ(inName,"set_stats") ) { return set_stats_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mouseClick") ) { return mouseClick; }
		if (HX_FIELD_EQ(inName,"rightClick") ) { return rightClick; }
		if (HX_FIELD_EQ(inName,"touchBegin") ) { return touchBegin; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_fluidStage") ) { return _fluidStage; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_currentTime") ) { return _currentTime; }
		if (HX_FIELD_EQ(inName,"_elapsedTime") ) { return _elapsedTime; }
		if (HX_FIELD_EQ(inName,"rightMouseUp") ) { return rightMouseUp; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"rightMouseDown") ) { return rightMouseDown; }
		if (HX_FIELD_EQ(inName,"_fluidOnUpdate") ) { return _fluidOnUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnResize") ) { return _fluidOnResize_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_fluidFrameSkip") ) { return _fluidFrameSkip; }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return backgroundColor; }
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
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_fluidOnMouseClick") ) { return _fluidOnMouseClick_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnRightClick") ) { return _fluidOnRightClick_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnTouchBegin") ) { return _fluidOnTouchBegin_dyn(); }
		if (HX_FIELD_EQ(inName,"_fluidOnEnterFrame") ) { return _fluidOnEnterFrame_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_setStageProperties") ) { return _setStageProperties_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundColor") ) { return set_backgroundColor_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_fluidOnRightMouseUp") ) { return _fluidOnRightMouseUp_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_fluidOnRightMouseDown") ) { return _fluidOnRightMouseDown_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"_fluidCalculateElapsedTime") ) { return _fluidCalculateElapsedTime_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Fluid_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"stats") ) { if (inCallProp) return set_stats(inValue);stats=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { update=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"resize") ) { resize=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_stats") ) { _stats=inValue.Cast< ::openfl::display::FPS >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_canvas") ) { _canvas=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseUp") ) { mouseUp=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mouseOut") ) { mouseOut=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchEnd") ) { touchEnd=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchOut") ) { touchOut=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_renderer") ) { _renderer=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_lastTime") ) { _lastTime=inValue.Cast< ::Date >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseDown") ) { mouseDown=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseOver") ) { mouseOver=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skipFrame") ) { skipFrame=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"container") ) { container=inValue.Cast< ::fluid::display::FluidSprite >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mouseClick") ) { mouseClick=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rightClick") ) { rightClick=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchBegin") ) { touchBegin=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_fluidStage") ) { _fluidStage=inValue.Cast< ::fluid::display::FluidStage >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_currentTime") ) { _currentTime=inValue.Cast< ::Date >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_elapsedTime") ) { _elapsedTime=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rightMouseUp") ) { rightMouseUp=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"rightMouseDown") ) { rightMouseDown=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_fluidFrameSkip") ) { _fluidFrameSkip=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { if (inCallProp) return set_backgroundColor(inValue);backgroundColor=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Fluid_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_canvas"));
	outFields->push(HX_CSTRING("_renderer"));
	outFields->push(HX_CSTRING("_lastTime"));
	outFields->push(HX_CSTRING("_currentTime"));
	outFields->push(HX_CSTRING("_elapsedTime"));
	outFields->push(HX_CSTRING("_fluidFrameSkip"));
	outFields->push(HX_CSTRING("skipFrame"));
	outFields->push(HX_CSTRING("stats"));
	outFields->push(HX_CSTRING("backgroundColor"));
	outFields->push(HX_CSTRING("_fluidStage"));
	outFields->push(HX_CSTRING("container"));
	outFields->push(HX_CSTRING("_stats"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,_canvas),HX_CSTRING("_canvas")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,_renderer),HX_CSTRING("_renderer")},
	{hx::fsObject /*::Date*/ ,(int)offsetof(Fluid_obj,_lastTime),HX_CSTRING("_lastTime")},
	{hx::fsObject /*::Date*/ ,(int)offsetof(Fluid_obj,_currentTime),HX_CSTRING("_currentTime")},
	{hx::fsFloat,(int)offsetof(Fluid_obj,_elapsedTime),HX_CSTRING("_elapsedTime")},
	{hx::fsBool,(int)offsetof(Fluid_obj,_fluidFrameSkip),HX_CSTRING("_fluidFrameSkip")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,mouseDown),HX_CSTRING("mouseDown")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,mouseOut),HX_CSTRING("mouseOut")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,mouseOver),HX_CSTRING("mouseOver")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,mouseUp),HX_CSTRING("mouseUp")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,mouseClick),HX_CSTRING("mouseClick")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,rightClick),HX_CSTRING("rightClick")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,rightMouseDown),HX_CSTRING("rightMouseDown")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,rightMouseUp),HX_CSTRING("rightMouseUp")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,touchBegin),HX_CSTRING("touchBegin")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,touchEnd),HX_CSTRING("touchEnd")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,touchOut),HX_CSTRING("touchOut")},
	{hx::fsBool,(int)offsetof(Fluid_obj,skipFrame),HX_CSTRING("skipFrame")},
	{hx::fsBool,(int)offsetof(Fluid_obj,stats),HX_CSTRING("stats")},
	{hx::fsInt,(int)offsetof(Fluid_obj,backgroundColor),HX_CSTRING("backgroundColor")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,update),HX_CSTRING("update")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Fluid_obj,resize),HX_CSTRING("resize")},
	{hx::fsObject /*::fluid::display::FluidStage*/ ,(int)offsetof(Fluid_obj,_fluidStage),HX_CSTRING("_fluidStage")},
	{hx::fsObject /*::fluid::display::FluidSprite*/ ,(int)offsetof(Fluid_obj,container),HX_CSTRING("container")},
	{hx::fsObject /*::openfl::display::FPS*/ ,(int)offsetof(Fluid_obj,_stats),HX_CSTRING("_stats")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_canvas"),
	HX_CSTRING("_renderer"),
	HX_CSTRING("_lastTime"),
	HX_CSTRING("_currentTime"),
	HX_CSTRING("_elapsedTime"),
	HX_CSTRING("_fluidFrameSkip"),
	HX_CSTRING("mouseDown"),
	HX_CSTRING("mouseOut"),
	HX_CSTRING("mouseOver"),
	HX_CSTRING("mouseUp"),
	HX_CSTRING("mouseClick"),
	HX_CSTRING("rightClick"),
	HX_CSTRING("rightMouseDown"),
	HX_CSTRING("rightMouseUp"),
	HX_CSTRING("touchBegin"),
	HX_CSTRING("touchEnd"),
	HX_CSTRING("touchOut"),
	HX_CSTRING("skipFrame"),
	HX_CSTRING("stats"),
	HX_CSTRING("backgroundColor"),
	HX_CSTRING("update"),
	HX_CSTRING("resize"),
	HX_CSTRING("_fluidStage"),
	HX_CSTRING("container"),
	HX_CSTRING("_stats"),
	HX_CSTRING("_setStageProperties"),
	HX_CSTRING("set_backgroundColor"),
	HX_CSTRING("_fluidOnMouseDown"),
	HX_CSTRING("_fluidOnMouseOver"),
	HX_CSTRING("_fluidOnMouseOut"),
	HX_CSTRING("_fluidOnMouseUp"),
	HX_CSTRING("_fluidOnMouseClick"),
	HX_CSTRING("_fluidOnRightClick"),
	HX_CSTRING("_fluidOnRightMouseDown"),
	HX_CSTRING("_fluidOnRightMouseUp"),
	HX_CSTRING("_fluidOnTouchBegin"),
	HX_CSTRING("_fluidOnTouchEnd"),
	HX_CSTRING("_fluidOnTouchOut"),
	HX_CSTRING("_fluidOnEnterFrame"),
	HX_CSTRING("_fluidOnUpdate"),
	HX_CSTRING("_fluidCalculateElapsedTime"),
	HX_CSTRING("_fluidOnResize"),
	HX_CSTRING("set_stats"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Fluid_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Fluid_obj::__mClass,"__mClass");
};

#endif

Class Fluid_obj::__mClass;

void Fluid_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.Fluid"), hx::TCanCast< Fluid_obj> ,sStaticFields,sMemberFields,
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

void Fluid_obj::__boot()
{
}

} // end namespace fluid
