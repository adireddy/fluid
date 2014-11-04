#include <hxcpp.h>

#ifndef INCLUDED_fluid_text_FluidTextFormat
#include <fluid/text/FluidTextFormat.h>
#endif
namespace fluid{
namespace text{

Void FluidTextFormat_obj::__construct(::String font,Dynamic size,::String fill,Dynamic bold,Dynamic italic,Dynamic underline,::String align)
{
HX_STACK_FRAME("fluid.text.FluidTextFormat","new",0x80b3a6e3,"fluid.text.FluidTextFormat.new","fluid/text/FluidTextFormat.hx",3,0x73dffa4d)
HX_STACK_THIS(this)
HX_STACK_ARG(font,"font")
HX_STACK_ARG(size,"size")
HX_STACK_ARG(fill,"fill")
HX_STACK_ARG(bold,"bold")
HX_STACK_ARG(italic,"italic")
HX_STACK_ARG(underline,"underline")
HX_STACK_ARG(align,"align")
{
	HX_STACK_LINE(11)
	this->align = HX_CSTRING("left");
	HX_STACK_LINE(10)
	this->fill = HX_CSTRING("#000000");
	HX_STACK_LINE(9)
	this->font = HX_CSTRING("Arial");
	HX_STACK_LINE(8)
	this->size = (int)20;
	HX_STACK_LINE(7)
	this->underline = false;
	HX_STACK_LINE(6)
	this->italic = false;
	HX_STACK_LINE(5)
	this->bold = false;
	HX_STACK_LINE(14)
	if (((font != null()))){
		HX_STACK_LINE(14)
		this->font = font;
	}
	HX_STACK_LINE(15)
	if (((size != null()))){
		HX_STACK_LINE(15)
		this->size = size;
	}
	HX_STACK_LINE(16)
	if (((fill != null()))){
		HX_STACK_LINE(16)
		this->fill = fill;
	}
	HX_STACK_LINE(17)
	if (((bold != null()))){
		HX_STACK_LINE(17)
		this->bold = bold;
	}
	HX_STACK_LINE(18)
	if (((italic != null()))){
		HX_STACK_LINE(18)
		this->italic = italic;
	}
	HX_STACK_LINE(19)
	if (((underline != null()))){
		HX_STACK_LINE(19)
		this->underline = underline;
	}
	HX_STACK_LINE(20)
	if (((align != null()))){
		HX_STACK_LINE(20)
		this->align = align;
	}
}
;
	return null();
}

//FluidTextFormat_obj::~FluidTextFormat_obj() { }

Dynamic FluidTextFormat_obj::__CreateEmpty() { return  new FluidTextFormat_obj; }
hx::ObjectPtr< FluidTextFormat_obj > FluidTextFormat_obj::__new(::String font,Dynamic size,::String fill,Dynamic bold,Dynamic italic,Dynamic underline,::String align)
{  hx::ObjectPtr< FluidTextFormat_obj > result = new FluidTextFormat_obj();
	result->__construct(font,size,fill,bold,italic,underline,align);
	return result;}

Dynamic FluidTextFormat_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FluidTextFormat_obj > result = new FluidTextFormat_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}


FluidTextFormat_obj::FluidTextFormat_obj()
{
}

void FluidTextFormat_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FluidTextFormat);
	HX_MARK_MEMBER_NAME(bold,"bold");
	HX_MARK_MEMBER_NAME(italic,"italic");
	HX_MARK_MEMBER_NAME(underline,"underline");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(font,"font");
	HX_MARK_MEMBER_NAME(fill,"fill");
	HX_MARK_MEMBER_NAME(align,"align");
	HX_MARK_END_CLASS();
}

void FluidTextFormat_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bold,"bold");
	HX_VISIT_MEMBER_NAME(italic,"italic");
	HX_VISIT_MEMBER_NAME(underline,"underline");
	HX_VISIT_MEMBER_NAME(size,"size");
	HX_VISIT_MEMBER_NAME(font,"font");
	HX_VISIT_MEMBER_NAME(fill,"fill");
	HX_VISIT_MEMBER_NAME(align,"align");
}

Dynamic FluidTextFormat_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bold") ) { return bold; }
		if (HX_FIELD_EQ(inName,"size") ) { return size; }
		if (HX_FIELD_EQ(inName,"font") ) { return font; }
		if (HX_FIELD_EQ(inName,"fill") ) { return fill; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"align") ) { return align; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"italic") ) { return italic; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"underline") ) { return underline; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FluidTextFormat_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bold") ) { bold=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"size") ) { size=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"font") ) { font=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fill") ) { fill=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"align") ) { align=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"italic") ) { italic=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"underline") ) { underline=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FluidTextFormat_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bold"));
	outFields->push(HX_CSTRING("italic"));
	outFields->push(HX_CSTRING("underline"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("font"));
	outFields->push(HX_CSTRING("fill"));
	outFields->push(HX_CSTRING("align"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(FluidTextFormat_obj,bold),HX_CSTRING("bold")},
	{hx::fsBool,(int)offsetof(FluidTextFormat_obj,italic),HX_CSTRING("italic")},
	{hx::fsBool,(int)offsetof(FluidTextFormat_obj,underline),HX_CSTRING("underline")},
	{hx::fsFloat,(int)offsetof(FluidTextFormat_obj,size),HX_CSTRING("size")},
	{hx::fsString,(int)offsetof(FluidTextFormat_obj,font),HX_CSTRING("font")},
	{hx::fsString,(int)offsetof(FluidTextFormat_obj,fill),HX_CSTRING("fill")},
	{hx::fsString,(int)offsetof(FluidTextFormat_obj,align),HX_CSTRING("align")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("bold"),
	HX_CSTRING("italic"),
	HX_CSTRING("underline"),
	HX_CSTRING("size"),
	HX_CSTRING("font"),
	HX_CSTRING("fill"),
	HX_CSTRING("align"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FluidTextFormat_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FluidTextFormat_obj::__mClass,"__mClass");
};

#endif

Class FluidTextFormat_obj::__mClass;

void FluidTextFormat_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.text.FluidTextFormat"), hx::TCanCast< FluidTextFormat_obj> ,sStaticFields,sMemberFields,
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

void FluidTextFormat_obj::__boot()
{
}

} // end namespace fluid
} // end namespace text
