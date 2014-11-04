#include <hxcpp.h>

#ifndef INCLUDED_motion_easing_CubicEaseIn
#include <motion/easing/CubicEaseIn.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
namespace motion{
namespace easing{

Void CubicEaseIn_obj::__construct()
{
HX_STACK_FRAME("motion.easing.CubicEaseIn","new",0x6bf6ed24,"motion.easing.CubicEaseIn.new","motion/easing/Cubic.hx",46,0x157bb7df)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//CubicEaseIn_obj::~CubicEaseIn_obj() { }

Dynamic CubicEaseIn_obj::__CreateEmpty() { return  new CubicEaseIn_obj; }
hx::ObjectPtr< CubicEaseIn_obj > CubicEaseIn_obj::__new()
{  hx::ObjectPtr< CubicEaseIn_obj > result = new CubicEaseIn_obj();
	result->__construct();
	return result;}

Dynamic CubicEaseIn_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CubicEaseIn_obj > result = new CubicEaseIn_obj();
	result->__construct();
	return result;}

hx::Object *CubicEaseIn_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::motion::easing::IEasing_obj)) return operator ::motion::easing::IEasing_obj *();
	return super::__ToInterface(inType);
}

Float CubicEaseIn_obj::calculate( Float k){
	HX_STACK_FRAME("motion.easing.CubicEaseIn","calculate",0x7cb99d2a,"motion.easing.CubicEaseIn.calculate","motion/easing/Cubic.hx",55,0x157bb7df)
	HX_STACK_THIS(this)
	HX_STACK_ARG(k,"k")
	HX_STACK_LINE(55)
	return ((k * k) * k);
}


HX_DEFINE_DYNAMIC_FUNC1(CubicEaseIn_obj,calculate,return )

Float CubicEaseIn_obj::ease( Float t,Float b,Float c,Float d){
	HX_STACK_FRAME("motion.easing.CubicEaseIn","ease",0x06229aaa,"motion.easing.CubicEaseIn.ease","motion/easing/Cubic.hx",60,0x157bb7df)
	HX_STACK_THIS(this)
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(d,"d")
	HX_STACK_LINE(62)
	Float _g = hx::DivEq(t,d);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(62)
	Float _g1 = (c * _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(62)
	Float _g2 = (_g1 * t);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(62)
	Float _g3 = (_g2 * t);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(62)
	return (_g3 + b);
}


HX_DEFINE_DYNAMIC_FUNC4(CubicEaseIn_obj,ease,return )


CubicEaseIn_obj::CubicEaseIn_obj()
{
}

Dynamic CubicEaseIn_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"ease") ) { return ease_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"calculate") ) { return calculate_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CubicEaseIn_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CubicEaseIn_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("calculate"),
	HX_CSTRING("ease"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CubicEaseIn_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CubicEaseIn_obj::__mClass,"__mClass");
};

#endif

Class CubicEaseIn_obj::__mClass;

void CubicEaseIn_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.easing.CubicEaseIn"), hx::TCanCast< CubicEaseIn_obj> ,sStaticFields,sMemberFields,
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

void CubicEaseIn_obj::__boot()
{
}

} // end namespace motion
} // end namespace easing
