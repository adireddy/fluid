#include <hxcpp.h>

#ifndef INCLUDED_motion_easing_CubicEaseInOut
#include <motion/easing/CubicEaseInOut.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
namespace motion{
namespace easing{

Void CubicEaseInOut_obj::__construct()
{
HX_STACK_FRAME("motion.easing.CubicEaseInOut","new",0x4d00a76e,"motion.easing.CubicEaseInOut.new","motion/easing/Cubic.hx",73,0x157bb7df)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//CubicEaseInOut_obj::~CubicEaseInOut_obj() { }

Dynamic CubicEaseInOut_obj::__CreateEmpty() { return  new CubicEaseInOut_obj; }
hx::ObjectPtr< CubicEaseInOut_obj > CubicEaseInOut_obj::__new()
{  hx::ObjectPtr< CubicEaseInOut_obj > result = new CubicEaseInOut_obj();
	result->__construct();
	return result;}

Dynamic CubicEaseInOut_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CubicEaseInOut_obj > result = new CubicEaseInOut_obj();
	result->__construct();
	return result;}

hx::Object *CubicEaseInOut_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::motion::easing::IEasing_obj)) return operator ::motion::easing::IEasing_obj *();
	return super::__ToInterface(inType);
}

Float CubicEaseInOut_obj::calculate( Float k){
	HX_STACK_FRAME("motion.easing.CubicEaseInOut","calculate",0xe7ff2af4,"motion.easing.CubicEaseInOut.calculate","motion/easing/Cubic.hx",80,0x157bb7df)
	HX_STACK_THIS(this)
	HX_STACK_ARG(k,"k")
	HX_STACK_LINE(82)
	Float _g = hx::DivEq(k,0.5);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(82)
	if (((_g < (int)1))){
		HX_STACK_LINE(82)
		return (((0.5 * k) * k) * k);
	}
	else{
		HX_STACK_LINE(82)
		Float _g1 = hx::SubEq(k,(int)2);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(82)
		Float _g2 = (_g1 * k);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(82)
		Float _g3 = (_g2 * k);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(82)
		Float _g4 = (_g3 + (int)2);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(82)
		return (0.5 * _g4);
	}
	HX_STACK_LINE(82)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC1(CubicEaseInOut_obj,calculate,return )

Float CubicEaseInOut_obj::ease( Float t,Float b,Float c,Float d){
	HX_STACK_FRAME("motion.easing.CubicEaseInOut","ease",0x0d9be120,"motion.easing.CubicEaseInOut.ease","motion/easing/Cubic.hx",87,0x157bb7df)
	HX_STACK_THIS(this)
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(d,"d")
	HX_STACK_LINE(89)
	Float _g = hx::DivEq(t,(Float(d) / Float((int)2)));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(89)
	if (((_g < (int)1))){
		HX_STACK_LINE(89)
		return (((((Float(c) / Float((int)2)) * t) * t) * t) + b);
	}
	else{
		HX_STACK_LINE(89)
		Float _g1 = hx::SubEq(t,(int)2);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(89)
		Float _g2 = (_g1 * t);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(89)
		Float _g3 = (_g2 * t);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(89)
		Float _g4 = (_g3 + (int)2);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(89)
		Float _g5 = ((Float(c) / Float((int)2)) * _g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(89)
		return (_g5 + b);
	}
	HX_STACK_LINE(89)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC4(CubicEaseInOut_obj,ease,return )


CubicEaseInOut_obj::CubicEaseInOut_obj()
{
}

Dynamic CubicEaseInOut_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic CubicEaseInOut_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CubicEaseInOut_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(CubicEaseInOut_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CubicEaseInOut_obj::__mClass,"__mClass");
};

#endif

Class CubicEaseInOut_obj::__mClass;

void CubicEaseInOut_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.easing.CubicEaseInOut"), hx::TCanCast< CubicEaseInOut_obj> ,sStaticFields,sMemberFields,
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

void CubicEaseInOut_obj::__boot()
{
}

} // end namespace motion
} // end namespace easing
