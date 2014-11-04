#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_fluid_text_FluidText
#include <fluid/text/FluidText.h>
#endif
#ifndef INCLUDED_fluid_text_FluidTextFormat
#include <fluid/text/FluidTextFormat.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
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
#ifndef INCLUDED_openfl__v2_text_TextFormat
#include <openfl/_v2/text/TextFormat.h>
#endif
#ifndef INCLUDED_openfl_text_TextFieldAutoSize
#include <openfl/text/TextFieldAutoSize.h>
#endif
namespace fluid{
namespace text{

Void FluidText_obj::__construct(::String txt,::fluid::text::FluidTextFormat format)
{
HX_STACK_FRAME("fluid.text.FluidText","new",0x1a16fc8c,"fluid.text.FluidText.new","fluid/text/FluidText.hx",4,0x3b8f44c4)
HX_STACK_THIS(this)
HX_STACK_ARG(txt,"txt")
HX_STACK_ARG(format,"format")
{
	HX_STACK_LINE(8)
	this->_anchorY = (int)0;
	HX_STACK_LINE(7)
	this->_anchorX = (int)0;
	HX_STACK_LINE(18)
	super::__construct();
	HX_STACK_LINE(19)
	if (((format != null()))){
		HX_STACK_LINE(19)
		this->setFormat(format);
	}
	HX_STACK_LINE(20)
	this->set_text(txt);
	HX_STACK_LINE(20)
	this->set_autoSize(::openfl::text::TextFieldAutoSize_obj::LEFT);
	HX_STACK_LINE(20)
	this->set_selectable(false);
}
;
	return null();
}

//FluidText_obj::~FluidText_obj() { }

Dynamic FluidText_obj::__CreateEmpty() { return  new FluidText_obj; }
hx::ObjectPtr< FluidText_obj > FluidText_obj::__new(::String txt,::fluid::text::FluidTextFormat format)
{  hx::ObjectPtr< FluidText_obj > result = new FluidText_obj();
	result->__construct(txt,format);
	return result;}

Dynamic FluidText_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FluidText_obj > result = new FluidText_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool FluidText_obj::set_interactive( bool val){
	HX_STACK_FRAME("fluid.text.FluidText","set_interactive",0x3df130b1,"fluid.text.FluidText.set_interactive","fluid/text/FluidText.hx",11,0x3b8f44c4)
	HX_STACK_THIS(this)
	HX_STACK_ARG(val,"val")
	HX_STACK_LINE(12)
	this->set_mouseEnabled(val);
	HX_STACK_LINE(13)
	return this->interactive = val;
}


HX_DEFINE_DYNAMIC_FUNC1(FluidText_obj,set_interactive,return )

Void FluidText_obj::setText( ::String value){
{
		HX_STACK_FRAME("fluid.text.FluidText","setText",0xc0e8bf9b,"fluid.text.FluidText.setText","fluid/text/FluidText.hx",23,0x3b8f44c4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(25)
		this->set_text(value);
		HX_STACK_LINE(25)
		this->setAnchor(this->_anchorX,this->_anchorY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidText_obj,setText,(void))

Void FluidText_obj::setFormat( ::fluid::text::FluidTextFormat format){
{
		HX_STACK_FRAME("fluid.text.FluidText","setFormat",0x815299a5,"fluid.text.FluidText.setFormat","fluid/text/FluidText.hx",28,0x3b8f44c4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(format,"format")
		HX_STACK_LINE(40)
		::openfl::_v2::text::TextFormat tf = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(tf,"tf");
		HX_STACK_LINE(41)
		tf->font = format->font;
		HX_STACK_LINE(42)
		tf->size = format->size;
		HX_STACK_LINE(43)
		::String _g = ::StringTools_obj::replace(format->fill,HX_CSTRING("#"),HX_CSTRING("0x"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(43)
		Dynamic _g1 = ::Std_obj::parseInt(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(43)
		tf->color = _g1;
		HX_STACK_LINE(44)
		tf->bold = format->bold;
		HX_STACK_LINE(45)
		tf->italic = format->italic;
		HX_STACK_LINE(46)
		tf->underline = format->underline;
		HX_STACK_LINE(47)
		this->set_defaultTextFormat(tf);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FluidText_obj,setFormat,(void))

Void FluidText_obj::setAnchor( Dynamic __o_ax,Dynamic __o_ay){
Dynamic ax = __o_ax.Default(0.5);
Dynamic ay = __o_ay.Default(0.5);
	HX_STACK_FRAME("fluid.text.FluidText","setAnchor",0xe43544e3,"fluid.text.FluidText.setAnchor","fluid/text/FluidText.hx",51,0x3b8f44c4)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ax,"ax")
	HX_STACK_ARG(ay,"ay")
{
		HX_STACK_LINE(53)
		this->_anchorX = ax;
		HX_STACK_LINE(54)
		this->_anchorY = ay;
		HX_STACK_LINE(55)
		{
			HX_STACK_LINE(55)
			::fluid::text::FluidText _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(55)
			Float _g1 = _g->get_x();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(55)
			Float _g11 = this->get_width();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(55)
			Float _g2 = (_g11 * ax);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(55)
			Float _g3 = (_g1 - _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(55)
			_g->set_x(_g3);
		}
		HX_STACK_LINE(56)
		{
			HX_STACK_LINE(56)
			::fluid::text::FluidText _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(56)
			Float _g4 = _g->get_y();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(56)
			Float _g5 = this->get_height();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(56)
			Float _g6 = (_g5 * ay);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(56)
			Float _g7 = (_g4 - _g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(56)
			_g->set_y(_g7);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FluidText_obj,setAnchor,(void))


FluidText_obj::FluidText_obj()
{
}

Dynamic FluidText_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"setText") ) { return setText_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_anchorX") ) { return _anchorX; }
		if (HX_FIELD_EQ(inName,"_anchorY") ) { return _anchorY; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setFormat") ) { return setFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"setAnchor") ) { return setAnchor_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"interactive") ) { return interactive; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_interactive") ) { return set_interactive_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FluidText_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"_anchorX") ) { _anchorX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_anchorY") ) { _anchorY=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"interactive") ) { if (inCallProp) return set_interactive(inValue);interactive=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FluidText_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_anchorX"));
	outFields->push(HX_CSTRING("_anchorY"));
	outFields->push(HX_CSTRING("interactive"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(FluidText_obj,_anchorX),HX_CSTRING("_anchorX")},
	{hx::fsFloat,(int)offsetof(FluidText_obj,_anchorY),HX_CSTRING("_anchorY")},
	{hx::fsBool,(int)offsetof(FluidText_obj,interactive),HX_CSTRING("interactive")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_anchorX"),
	HX_CSTRING("_anchorY"),
	HX_CSTRING("interactive"),
	HX_CSTRING("set_interactive"),
	HX_CSTRING("setText"),
	HX_CSTRING("setFormat"),
	HX_CSTRING("setAnchor"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FluidText_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FluidText_obj::__mClass,"__mClass");
};

#endif

Class FluidText_obj::__mClass;

void FluidText_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.text.FluidText"), hx::TCanCast< FluidText_obj> ,sStaticFields,sMemberFields,
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

void FluidText_obj::__boot()
{
}

} // end namespace fluid
} // end namespace text
