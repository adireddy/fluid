#include <hxcpp.h>

#ifndef INCLUDED_msignal_Signal
#include <msignal/Signal.h>
#endif
#ifndef INCLUDED_msignal_Signal0
#include <msignal/Signal0.h>
#endif
#ifndef INCLUDED_msignal_Slot
#include <msignal/Slot.h>
#endif
#ifndef INCLUDED_msignal_Slot0
#include <msignal/Slot0.h>
#endif
namespace msignal{

Void Slot0_obj::__construct(::msignal::Signal0 signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority)
{
HX_STACK_FRAME("msignal.Slot0","new",0x2992372b,"msignal.Slot0.new","msignal/Slot.hx",115,0x8d27aea6)
HX_STACK_THIS(this)
HX_STACK_ARG(signal,"signal")
HX_STACK_ARG(listener,"listener")
HX_STACK_ARG(__o_once,"once")
HX_STACK_ARG(__o_priority,"priority")
bool once = __o_once.Default(false);
int priority = __o_priority.Default(0);
{
	HX_STACK_LINE(115)
	super::__construct(signal,listener,once,priority);
}
;
	return null();
}

//Slot0_obj::~Slot0_obj() { }

Dynamic Slot0_obj::__CreateEmpty() { return  new Slot0_obj; }
hx::ObjectPtr< Slot0_obj > Slot0_obj::__new(::msignal::Signal0 signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority)
{  hx::ObjectPtr< Slot0_obj > result = new Slot0_obj();
	result->__construct(signal,listener,__o_once,__o_priority);
	return result;}

Dynamic Slot0_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Slot0_obj > result = new Slot0_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Slot0_obj::execute( ){
{
		HX_STACK_FRAME("msignal.Slot0","execute",0x2dce3280,"msignal.Slot0.execute","msignal/Slot.hx",122,0x8d27aea6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(123)
		if ((!(this->enabled))){
			HX_STACK_LINE(123)
			return null();
		}
		HX_STACK_LINE(124)
		if ((this->once)){
			HX_STACK_LINE(124)
			this->remove();
		}
		HX_STACK_LINE(125)
		this->get_listener()().Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Slot0_obj,execute,(void))


Slot0_obj::Slot0_obj()
{
}

Dynamic Slot0_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"execute") ) { return execute_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Slot0_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Slot0_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("execute"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Slot0_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Slot0_obj::__mClass,"__mClass");
};

#endif

Class Slot0_obj::__mClass;

void Slot0_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("msignal.Slot0"), hx::TCanCast< Slot0_obj> ,sStaticFields,sMemberFields,
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

void Slot0_obj::__boot()
{
}

} // end namespace msignal
