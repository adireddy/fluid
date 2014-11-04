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
#ifndef INCLUDED_msignal_SlotList
#include <msignal/SlotList.h>
#endif
namespace msignal{

Void Signal0_obj::__construct()
{
HX_STACK_FRAME("msignal.Signal0","new",0x14d82641,"msignal.Signal0.new","msignal/Signal.hx",183,0xeae291fc)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(183)
	super::__construct(null());
}
;
	return null();
}

//Signal0_obj::~Signal0_obj() { }

Dynamic Signal0_obj::__CreateEmpty() { return  new Signal0_obj; }
hx::ObjectPtr< Signal0_obj > Signal0_obj::__new()
{  hx::ObjectPtr< Signal0_obj > result = new Signal0_obj();
	result->__construct();
	return result;}

Dynamic Signal0_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Signal0_obj > result = new Signal0_obj();
	result->__construct();
	return result;}

Void Signal0_obj::dispatch( ){
{
		HX_STACK_FRAME("msignal.Signal0","dispatch",0x77578939,"msignal.Signal0.dispatch","msignal/Signal.hx",190,0xeae291fc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(191)
		::msignal::SlotList slotsToProcess = this->slots;		HX_STACK_VAR(slotsToProcess,"slotsToProcess");
		HX_STACK_LINE(193)
		while((true)){
			HX_STACK_LINE(193)
			if ((!(slotsToProcess->nonEmpty))){
				HX_STACK_LINE(193)
				break;
			}
			HX_STACK_LINE(195)
			slotsToProcess->head->__Field(HX_CSTRING("execute"),true)();
			HX_STACK_LINE(196)
			slotsToProcess = slotsToProcess->tail;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Signal0_obj,dispatch,(void))

Dynamic Signal0_obj::createSlot( Dynamic _tmp_listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority){
bool once = __o_once.Default(false);
int priority = __o_priority.Default(0);
	HX_STACK_FRAME("msignal.Signal0","createSlot",0xa81a3759,"msignal.Signal0.createSlot","msignal/Signal.hx",202,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(_tmp_listener,"_tmp_listener")
	HX_STACK_ARG(once,"once")
	HX_STACK_ARG(priority,"priority")
{
		HX_STACK_LINE(202)
		Dynamic listener = _tmp_listener;		HX_STACK_VAR(listener,"listener");
		HX_STACK_LINE(202)
		return ::msignal::Slot0_obj::__new(hx::ObjectPtr<OBJ_>(this),listener,once,priority);
	}
}



Signal0_obj::Signal0_obj()
{
}

Dynamic Signal0_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Signal0_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Signal0_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Signal0_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Signal0_obj::__mClass,"__mClass");
};

#endif

Class Signal0_obj::__mClass;

void Signal0_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("msignal.Signal0"), hx::TCanCast< Signal0_obj> ,sStaticFields,sMemberFields,
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

void Signal0_obj::__boot()
{
}

} // end namespace msignal
