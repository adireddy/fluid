#include <hxcpp.h>

#ifndef INCLUDED_msignal_Signal
#include <msignal/Signal.h>
#endif
#ifndef INCLUDED_msignal_Signal2
#include <msignal/Signal2.h>
#endif
#ifndef INCLUDED_msignal_Slot
#include <msignal/Slot.h>
#endif
#ifndef INCLUDED_msignal_Slot2
#include <msignal/Slot2.h>
#endif
namespace msignal{

Void Slot2_obj::__construct(::msignal::Signal2 signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority)
{
HX_STACK_FRAME("msignal.Slot2","new",0x505f602d,"msignal.Slot2.new","msignal/Slot.hx",174,0x8d27aea6)
HX_STACK_THIS(this)
HX_STACK_ARG(signal,"signal")
HX_STACK_ARG(listener,"listener")
HX_STACK_ARG(__o_once,"once")
HX_STACK_ARG(__o_priority,"priority")
bool once = __o_once.Default(false);
int priority = __o_priority.Default(0);
{
	HX_STACK_LINE(174)
	super::__construct(signal,listener,once,priority);
}
;
	return null();
}

//Slot2_obj::~Slot2_obj() { }

Dynamic Slot2_obj::__CreateEmpty() { return  new Slot2_obj; }
hx::ObjectPtr< Slot2_obj > Slot2_obj::__new(::msignal::Signal2 signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority)
{  hx::ObjectPtr< Slot2_obj > result = new Slot2_obj();
	result->__construct(signal,listener,__o_once,__o_priority);
	return result;}

Dynamic Slot2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Slot2_obj > result = new Slot2_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Slot2_obj::execute( Dynamic value1,Dynamic value2){
{
		HX_STACK_FRAME("msignal.Slot2","execute",0xd3b10482,"msignal.Slot2.execute","msignal/Slot.hx",183,0x8d27aea6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value1,"value1")
		HX_STACK_ARG(value2,"value2")
		HX_STACK_LINE(184)
		if ((!(this->enabled))){
			HX_STACK_LINE(184)
			return null();
		}
		HX_STACK_LINE(185)
		if ((this->once)){
			HX_STACK_LINE(185)
			this->remove();
		}
		HX_STACK_LINE(187)
		if (((this->param1 != null()))){
			HX_STACK_LINE(187)
			value1 = this->param1;
		}
		HX_STACK_LINE(188)
		if (((this->param2 != null()))){
			HX_STACK_LINE(188)
			value2 = this->param2;
		}
		HX_STACK_LINE(190)
		this->get_listener()(value1,value2).Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Slot2_obj,execute,(void))


Slot2_obj::Slot2_obj()
{
}

void Slot2_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Slot2);
	HX_MARK_MEMBER_NAME(param1,"param1");
	HX_MARK_MEMBER_NAME(param2,"param2");
	::msignal::Slot_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Slot2_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(param1,"param1");
	HX_VISIT_MEMBER_NAME(param2,"param2");
	::msignal::Slot_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Slot2_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"param1") ) { return param1; }
		if (HX_FIELD_EQ(inName,"param2") ) { return param2; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"execute") ) { return execute_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Slot2_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"param1") ) { param1=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"param2") ) { param2=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Slot2_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("param1"));
	outFields->push(HX_CSTRING("param2"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Slot2_obj,param1),HX_CSTRING("param1")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Slot2_obj,param2),HX_CSTRING("param2")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("param1"),
	HX_CSTRING("param2"),
	HX_CSTRING("execute"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Slot2_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Slot2_obj::__mClass,"__mClass");
};

#endif

Class Slot2_obj::__mClass;

void Slot2_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("msignal.Slot2"), hx::TCanCast< Slot2_obj> ,sStaticFields,sMemberFields,
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

void Slot2_obj::__boot()
{
}

} // end namespace msignal
