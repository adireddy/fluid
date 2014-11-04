#include <hxcpp.h>

#ifndef INCLUDED_motion_easing_CubicEaseOut
#include <motion/easing/CubicEaseOut.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
#endif
namespace motion{
namespace easing{

Void CubicEaseOut_obj::__construct()
{
HX_STACK_FRAME("motion.easing.CubicEaseOut","new",0xf5de9a13,"motion.easing.CubicEaseOut.new","motion/easing/Cubic.hx",100,0x157bb7df)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//CubicEaseOut_obj::~CubicEaseOut_obj() { }

Dynamic CubicEaseOut_obj::__CreateEmpty() { return  new CubicEaseOut_obj; }
hx::ObjectPtr< CubicEaseOut_obj > CubicEaseOut_obj::__new()
{  hx::ObjectPtr< CubicEaseOut_obj > result = new CubicEaseOut_obj();
	result->__construct();
	return result;}

Dynamic CubicEaseOut_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CubicEaseOut_obj > result = new CubicEaseOut_obj();
	result->__construct();
	return result;}

hx::Object *CubicEaseOut_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::motion::easing::IEasing_obj)) return operator ::motion::easing::IEasing_obj *();
	return super::__ToInterface(inType);
}

Float CubicEaseOut_obj::calculate( Float k){
	HX_STACK_FRAME("motion.easing.CubicEaseOut","calculate",0x2c342759,"motion.easing.CubicEaseOut.calculate","motion/easing/Cubic.hx",107,0x157bb7df)
	HX_STACK_THIS(this)
	HX_STACK_ARG(k,"k")
	HX_STACK_LINE(109)
	Float _g = --(k);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(109)
	Float _g1 = (_g * k);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(109)
	Float _g2 = (_g1 * k);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(109)
	return (_g2 + (int)1);
}


HX_DEFINE_DYNAMIC_FUNC1(CubicEaseOut_obj,calculate,return )

Float CubicEaseOut_obj::ease( Float t,Float b,Float c,Float d){
	HX_STACK_FRAME("motion.easing.CubicEaseOut","ease",0x26f23edb,"motion.easing.CubicEaseOut.ease","motion/easing/Cubic.hx",114,0x157bb7df)
	HX_STACK_THIS(this)
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(d,"d")
	HX_STACK_LINE(116)
	Float _g = t = ((Float(t) / Float(d)) - (int)1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(116)
	Float _g1 = (_g * t);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(116)
	Float _g2 = (_g1 * t);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(116)
	Float _g3 = (_g2 + (int)1);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(116)
	Float _g4 = (c * _g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(116)
	return (_g4 + b);
}


HX_DEFINE_DYNAMIC_FUNC4(CubicEaseOut_obj,ease,return )


CubicEaseOut_obj::CubicEaseOut_obj()
{
}

Dynamic CubicEaseOut_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic CubicEaseOut_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CubicEaseOut_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(CubicEaseOut_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CubicEaseOut_obj::__mClass,"__mClass");
};

#endif

Class CubicEaseOut_obj::__mClass;

void CubicEaseOut_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.easing.CubicEaseOut"), hx::TCanCast< CubicEaseOut_obj> ,sStaticFields,sMemberFields,
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

void CubicEaseOut_obj::__boot()
{
}

} // end namespace motion
} // end namespace easing
