#include <hxcpp.h>

#ifndef INCLUDED_fluid_display_FluidGraphics
#include <fluid/display/FluidGraphics.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Graphics
#include <openfl/_v2/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Shape
#include <openfl/_v2/display/Shape.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
namespace fluid{
namespace display{

Void FluidGraphics_obj::__construct()
{
HX_STACK_FRAME("fluid.display.FluidGraphics","new",0x25bd03b7,"fluid.display.FluidGraphics.new","fluid/display/FluidGraphics.hx",6,0xc8fe2c9b)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(6)
	super::__construct();
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

Void FluidGraphics_obj::clear( ){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","clear",0x80f968a4,"fluid.display.FluidGraphics.clear","fluid/display/FluidGraphics.hx",11,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(11)
		this->get_graphics()->clear();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FluidGraphics_obj,clear,(void))

Void FluidGraphics_obj::beginFill( int fill,Dynamic __o_alpha){
Dynamic alpha = __o_alpha.Default(1);
	HX_STACK_FRAME("fluid.display.FluidGraphics","beginFill",0x0f327be3,"fluid.display.FluidGraphics.beginFill","fluid/display/FluidGraphics.hx",14,0xc8fe2c9b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(fill,"fill")
	HX_STACK_ARG(alpha,"alpha")
{
		HX_STACK_LINE(16)
		this->get_graphics()->beginFill(fill,null());
		HX_STACK_LINE(16)
		this->set_alpha(alpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FluidGraphics_obj,beginFill,(void))

Void FluidGraphics_obj::endFill( ){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","endFill",0x3b3bb2d5,"fluid.display.FluidGraphics.endFill","fluid/display/FluidGraphics.hx",21,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(21)
		this->get_graphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FluidGraphics_obj,endFill,(void))

Void FluidGraphics_obj::drawRect( Float x,Float y,Float w,Float h){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","drawRect",0xfa7b4891,"fluid.display.FluidGraphics.drawRect","fluid/display/FluidGraphics.hx",26,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(w,"w")
		HX_STACK_ARG(h,"h")
		HX_STACK_LINE(26)
		this->get_graphics()->drawRect(x,y,w,h);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FluidGraphics_obj,drawRect,(void))

Void FluidGraphics_obj::drawCircle( Float x,Float y,Float r){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","drawCircle",0x5e68e2bd,"fluid.display.FluidGraphics.drawCircle","fluid/display/FluidGraphics.hx",31,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(31)
		this->get_graphics()->drawCircle(x,y,r);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FluidGraphics_obj,drawCircle,(void))

Void FluidGraphics_obj::drawEllipse( Float x,Float y,Float w,Float h){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","drawEllipse",0x532d6791,"fluid.display.FluidGraphics.drawEllipse","fluid/display/FluidGraphics.hx",36,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(w,"w")
		HX_STACK_ARG(h,"h")
		HX_STACK_LINE(36)
		this->get_graphics()->drawEllipse(x,y,w,h);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FluidGraphics_obj,drawEllipse,(void))

Void FluidGraphics_obj::drawRoundedRect( Float x,Float y,Float w,Float h,Float r){
{
		HX_STACK_FRAME("fluid.display.FluidGraphics","drawRoundedRect",0x1c441024,"fluid.display.FluidGraphics.drawRoundedRect","fluid/display/FluidGraphics.hx",41,0xc8fe2c9b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(w,"w")
		HX_STACK_ARG(h,"h")
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(41)
		this->get_graphics()->drawRoundRectComplex(x,y,w,h,r,r,r,r);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(FluidGraphics_obj,drawRoundedRect,(void))


FluidGraphics_obj::FluidGraphics_obj()
{
}

Dynamic FluidGraphics_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"endFill") ) { return endFill_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"drawRect") ) { return drawRect_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"beginFill") ) { return beginFill_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"drawCircle") ) { return drawCircle_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"drawEllipse") ) { return drawEllipse_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"drawRoundedRect") ) { return drawRoundedRect_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FluidGraphics_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FluidGraphics_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("clear"),
	HX_CSTRING("beginFill"),
	HX_CSTRING("endFill"),
	HX_CSTRING("drawRect"),
	HX_CSTRING("drawCircle"),
	HX_CSTRING("drawEllipse"),
	HX_CSTRING("drawRoundedRect"),
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
