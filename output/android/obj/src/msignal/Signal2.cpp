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
#ifndef INCLUDED_msignal_SlotList
#include <msignal/SlotList.h>
#endif
namespace msignal{

Void Signal2_obj::__construct(Dynamic type1,Dynamic type2)
{
HX_STACK_FRAME("msignal.Signal2","new",0x3ba54f43,"msignal.Signal2.new","msignal/Signal.hx",243,0xeae291fc)
HX_STACK_THIS(this)
HX_STACK_ARG(type1,"type1")
HX_STACK_ARG(type2,"type2")
{
	HX_STACK_LINE(243)
	super::__construct(Dynamic( Array_obj<Dynamic>::__new().Add(type1).Add(type2)));
}
;
	return null();
}

//Signal2_obj::~Signal2_obj() { }

Dynamic Signal2_obj::__CreateEmpty() { return  new Signal2_obj; }
hx::ObjectPtr< Signal2_obj > Signal2_obj::__new(Dynamic type1,Dynamic type2)
{  hx::ObjectPtr< Signal2_obj > result = new Signal2_obj();
	result->__construct(type1,type2);
	return result;}

Dynamic Signal2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Signal2_obj > result = new Signal2_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Signal2_obj::dispatch( Dynamic value1,Dynamic value2){
{
		HX_STACK_FRAME("msignal.Signal2","dispatch",0xf7ec78f7,"msignal.Signal2.dispatch","msignal/Signal.hx",250,0xeae291fc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value1,"value1")
		HX_STACK_ARG(value2,"value2")
		HX_STACK_LINE(251)
		::msignal::SlotList slotsToProcess = this->slots;		HX_STACK_VAR(slotsToProcess,"slotsToProcess");
		HX_STACK_LINE(253)
		while((true)){
			HX_STACK_LINE(253)
			if ((!(slotsToProcess->nonEmpty))){
				HX_STACK_LINE(253)
				break;
			}
			HX_STACK_LINE(255)
			slotsToProcess->head->__Field(HX_CSTRING("execute"),true)(value1,value2);
			HX_STACK_LINE(256)
			slotsToProcess = slotsToProcess->tail;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Signal2_obj,dispatch,(void))

Dynamic Signal2_obj::createSlot( Dynamic _tmp_listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority){
bool once = __o_once.Default(false);
int priority = __o_priority.Default(0);
	HX_STACK_FRAME("msignal.Signal2","createSlot",0x2b991297,"msignal.Signal2.createSlot","msignal/Signal.hx",262,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(_tmp_listener,"_tmp_listener")
	HX_STACK_ARG(once,"once")
	HX_STACK_ARG(priority,"priority")
{
		HX_STACK_LINE(262)
		Dynamic listener = _tmp_listener;		HX_STACK_VAR(listener,"listener");
		HX_STACK_LINE(262)
		return ::msignal::Slot2_obj::__new(hx::ObjectPtr<OBJ_>(this),listener,once,priority);
	}
}



Signal2_obj::Signal2_obj()
{
}

Dynamic Signal2_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"dispatch") ) { return dispatch_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"createSlot") ) { return createSlot_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Signal2_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Signal2_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("dispatch"),
	HX_CSTRING("createSlot"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Signal2_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Signal2_obj::__mClass,"__mClass");
};

#endif

Class Signal2_obj::__mClass;

void Signal2_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("msignal.Signal2"), hx::TCanCast< Signal2_obj> ,sStaticFields,sMemberFields,
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

void Signal2_obj::__boot()
{
}

} // end namespace msignal
