#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_widgets_Label
#include <com/arm/demo/widgets/Label.h>
#endif
#ifndef INCLUDED_fluid_display_FluidGraphics
#include <fluid/display/FluidGraphics.h>
#endif
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
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

Void Label_obj::__construct(::String label,Float width,Float height,Dynamic style)
{
HX_STACK_FRAME("com.arm.demo.widgets.Label","new",0x1d8ade9b,"com.arm.demo.widgets.Label.new","com/arm/demo/widgets/Label.hx",22,0x6b011875)
HX_STACK_THIS(this)
HX_STACK_ARG(label,"label")
HX_STACK_ARG(width,"width")
HX_STACK_ARG(height,"height")
HX_STACK_ARG(style,"style")
{
	HX_STACK_LINE(23)
	super::__construct(null());
	HX_STACK_LINE(24)
	::fluid::text::FluidTextFormat _g = ::fluid::text::FluidTextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(24)
	this->_format = _g;
	HX_STACK_LINE(25)
	this->_format->size = (int)16;
	HX_STACK_LINE(26)
	this->_format->font = HX_CSTRING("Arial");
	HX_STACK_LINE(27)
	this->_format->fill = HX_CSTRING("#333333");
	HX_STACK_LINE(29)
	this->_setupBackground(width,height);
	HX_STACK_LINE(30)
	this->_setupLabel(width,height);
	HX_STACK_LINE(31)
	this->setText(label);
}
;
	return null();
}

//Label_obj::~Label_obj() { }

Dynamic Label_obj::__CreateEmpty() { return  new Label_obj; }
hx::ObjectPtr< Label_obj > Label_obj::__new(::String label,Float width,Float height,Dynamic style)
{  hx::ObjectPtr< Label_obj > result = new Label_obj();
	result->__construct(label,width,height,style);
	return result;}

Dynamic Label_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Label_obj > result = new Label_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Label_obj::_setupBackground( Float width,Float height){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Label","_setupBackground",0xd107d031,"com.arm.demo.widgets.Label._setupBackground","com/arm/demo/widgets/Label.hx",34,0x6b011875)
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
		this->_background->beginFill((int)3355443,null());
		HX_STACK_LINE(39)
		this->_background->drawRect(this->_rect->x,this->_rect->y,this->_rect->width,this->_rect->height);
		HX_STACK_LINE(40)
		this->_background->endFill();
		HX_STACK_LINE(42)
		this->_background->beginFill((int)16777215,null());
		HX_STACK_LINE(43)
		this->_background->drawRect((this->_rect->x + (int)1),(this->_rect->y + (int)1),(this->_rect->width - (int)2),(this->_rect->height - (int)2));
		HX_STACK_LINE(44)
		this->_background->endFill();
		HX_STACK_LINE(46)
		this->addChild(this->_background);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Label_obj,_setupBackground,(void))

Void Label_obj::_setupLabel( Float width,Float height){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Label","_setupLabel",0xa1d43891,"com.arm.demo.widgets.Label._setupLabel","com/arm/demo/widgets/Label.hx",49,0x6b011875)
		HX_STACK_THIS(this)
		HX_STACK_ARG(width,"width")
		HX_STACK_ARG(height,"height")
		HX_STACK_LINE(50)
		::fluid::text::FluidText _g = ::fluid::text::FluidText_obj::__new(HX_CSTRING(""),this->_format);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(50)
		this->_label = _g;
		HX_STACK_LINE(51)
		this->_label->setAnchor(0.5,null());
		HX_STACK_LINE(52)
		this->_label->set_x((Float(width) / Float((int)2)));
		HX_STACK_LINE(53)
		this->_label->set_y((int)4);
		HX_STACK_LINE(54)
		this->addChild(this->_label);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Label_obj,_setupLabel,(void))

Void Label_obj::setText( ::String label){
{
		HX_STACK_FRAME("com.arm.demo.widgets.Label","setText",0x2bf8552a,"com.arm.demo.widgets.Label.setText","com/arm/demo/widgets/Label.hx",58,0x6b011875)
		HX_STACK_THIS(this)
		HX_STACK_ARG(label,"label")
		HX_STACK_LINE(58)
		this->_label->setText(label);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Label_obj,setText,(void))

int Label_obj::BACKGROUND_COLOUR;

int Label_obj::BORDER_COLOUR;

::String Label_obj::TEXT_COLOUR;

int Label_obj::TEXT_SIZE;

int Label_obj::PADDING;


Label_obj::Label_obj()
{
}

void Label_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Label);
	HX_MARK_MEMBER_NAME(_label,"_label");
	HX_MARK_MEMBER_NAME(_rect,"_rect");
	HX_MARK_MEMBER_NAME(_background,"_background");
	HX_MARK_MEMBER_NAME(_format,"_format");
	::fluid::display::FluidSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Label_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_label,"_label");
	HX_VISIT_MEMBER_NAME(_rect,"_rect");
	HX_VISIT_MEMBER_NAME(_background,"_background");
	HX_VISIT_MEMBER_NAME(_format,"_format");
	::fluid::display::FluidSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Label_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_rect") ) { return _rect; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_label") ) { return _label; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_format") ) { return _format; }
		if (HX_FIELD_EQ(inName,"setText") ) { return setText_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_background") ) { return _background; }
		if (HX_FIELD_EQ(inName,"_setupLabel") ) { return _setupLabel_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_setupBackground") ) { return _setupBackground_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Label_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_rect") ) { _rect=inValue.Cast< ::fluid::geom::FluidRectangle >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_label") ) { _label=inValue.Cast< ::fluid::text::FluidText >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_format") ) { _format=inValue.Cast< ::fluid::text::FluidTextFormat >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_background") ) { _background=inValue.Cast< ::fluid::display::FluidGraphics >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Label_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_label"));
	outFields->push(HX_CSTRING("_rect"));
	outFields->push(HX_CSTRING("_background"));
	outFields->push(HX_CSTRING("_format"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("BACKGROUND_COLOUR"),
	HX_CSTRING("BORDER_COLOUR"),
	HX_CSTRING("TEXT_COLOUR"),
	HX_CSTRING("TEXT_SIZE"),
	HX_CSTRING("PADDING"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::fluid::text::FluidText*/ ,(int)offsetof(Label_obj,_label),HX_CSTRING("_label")},
	{hx::fsObject /*::fluid::geom::FluidRectangle*/ ,(int)offsetof(Label_obj,_rect),HX_CSTRING("_rect")},
	{hx::fsObject /*::fluid::display::FluidGraphics*/ ,(int)offsetof(Label_obj,_background),HX_CSTRING("_background")},
	{hx::fsObject /*::fluid::text::FluidTextFormat*/ ,(int)offsetof(Label_obj,_format),HX_CSTRING("_format")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_label"),
	HX_CSTRING("_rect"),
	HX_CSTRING("_background"),
	HX_CSTRING("_format"),
	HX_CSTRING("_setupBackground"),
	HX_CSTRING("_setupLabel"),
	HX_CSTRING("setText"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Label_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Label_obj::BACKGROUND_COLOUR,"BACKGROUND_COLOUR");
	HX_MARK_MEMBER_NAME(Label_obj::BORDER_COLOUR,"BORDER_COLOUR");
	HX_MARK_MEMBER_NAME(Label_obj::TEXT_COLOUR,"TEXT_COLOUR");
	HX_MARK_MEMBER_NAME(Label_obj::TEXT_SIZE,"TEXT_SIZE");
	HX_MARK_MEMBER_NAME(Label_obj::PADDING,"PADDING");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Label_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Label_obj::BACKGROUND_COLOUR,"BACKGROUND_COLOUR");
	HX_VISIT_MEMBER_NAME(Label_obj::BORDER_COLOUR,"BORDER_COLOUR");
	HX_VISIT_MEMBER_NAME(Label_obj::TEXT_COLOUR,"TEXT_COLOUR");
	HX_VISIT_MEMBER_NAME(Label_obj::TEXT_SIZE,"TEXT_SIZE");
	HX_VISIT_MEMBER_NAME(Label_obj::PADDING,"PADDING");
};

#endif

Class Label_obj::__mClass;

void Label_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.widgets.Label"), hx::TCanCast< Label_obj> ,sStaticFields,sMemberFields,
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

void Label_obj::__boot()
{
	BACKGROUND_COLOUR= (int)16777215;
	BORDER_COLOUR= (int)3355443;
	TEXT_COLOUR= HX_CSTRING("#333333");
	TEXT_SIZE= (int)16;
	PADDING= (int)4;
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace widgets
