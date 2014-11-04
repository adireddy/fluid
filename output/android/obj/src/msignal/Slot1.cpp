#include <hxcpp.h>

#ifndef INCLUDED_msignal_Signal
#include <msignal/Signal.h>
#endif
#ifndef INCLUDED_msignal_Signal1
#include <msignal/Signal1.h>
#endif
#ifndef INCLUDED_msignal_Slot
#include <msignal/Slot.h>
#endif
#ifndef INCLUDED_msignal_Slot1
#include <msignal/Slot1.h>
#endif
namespace msignal{

Void Slot1_obj::__construct(::msignal::Signal1 signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority)
{
HX_STACK_FRAME("msignal.Slot1","new",0xbcf8cbac,"msignal.Slot1.new","msignal/Slot.hx",141,0x8d27aea6)
HX_STACK_THIS(this)
HX_STACK_ARG(signal,"signal")
HX_STACK_ARG(listener,"listener")
HX_STACK_ARG(__o_once,"once")
HX_STACK_ARG(__o_priority,"priority")
bool once = __o_once.Default(false);
int priority = __o_priority.Default(0);
{
	HX_STACK_LINE(141)
	super::__construct(signal,listener,once,priority);
}
;
	return null();
}

//Slot1_obj::~Slot1_obj() { }

Dynamic Slot1_obj::__CreateEmpty() { return  new Slot1_obj; }
hx::ObjectPtr< Slot1_obj > Slot1_obj::__new(::msignal::Signal1 signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority)
{  hx::ObjectPtr< Slot1_obj > result = new Slot1_obj();
	result->__construct(signal,listener,__o_once,__o_priority);
	return result;}

Dynamic Slot1_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Slot1_obj > result = new Slot1_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Slot1_obj::execute( Dynamic value1){
{
		HX_STACK_FRAME("msignal.Slot1","execute",0x00bf9b81,"msignal.Slot1.execute","msignal/Slot.hx",149,0x8d27aea6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value1,"value1")
		HX_STACK_LINE(150)
		if ((!(this->enabled))){
			HX_STACK_LINE(150)
			return null();
		}
		HX_STACK_LINE(151)
		if ((this->once)){
			HX_STACK_LINE(151)
			this->remove();
		}
		HX_STACK_LINE(152)
		if (((this->param != null()))){
			HX_STACK_LINE(152)
			value1 = this->param;
		}
		HX_STACK_LINE(153)
		this->get_listener()(value1).Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Slot1_obj,execute,(void))


Slot1_obj::Slot1_obj()
{
}

void Slot1_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Slot1);
	HX_MARK_MEMBER_NAME(param,"param");
	::msignal::Slot_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Slot1_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(param,"param");
	::msignal::Slot_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Slot1_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"param") ) { return param; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"execute") ) { return execute_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Slot1_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"param") ) { param=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Slot1_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("param"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Slot1_obj,param),HX_CSTRING("param")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("param"),
	HX_CSTRING("execute"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Slot1_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Slot1_obj::__mClass,"__mClass");
};

#endif

Class Slot1_obj::__mClass;

void Slot1_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("msignal.Slot1"), hx::TCanCast< Slot1_obj> ,sStaticFields,sMemberFields,
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

void Slot1_obj::__boot()
{
}

} // end namespace msignal
