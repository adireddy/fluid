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
#ifndef INCLUDED_msignal_SlotList
#include <msignal/SlotList.h>
#endif
namespace msignal{

Void Signal1_obj::__construct(Dynamic type)
{
HX_STACK_FRAME("msignal.Signal1","new",0xa83ebac2,"msignal.Signal1.new","msignal/Signal.hx",213,0xeae291fc)
HX_STACK_THIS(this)
HX_STACK_ARG(type,"type")
{
	HX_STACK_LINE(213)
	super::__construct(Dynamic( Array_obj<Dynamic>::__new().Add(type)));
}
;
	return null();
}

//Signal1_obj::~Signal1_obj() { }

Dynamic Signal1_obj::__CreateEmpty() { return  new Signal1_obj; }
hx::ObjectPtr< Signal1_obj > Signal1_obj::__new(Dynamic type)
{  hx::ObjectPtr< Signal1_obj > result = new Signal1_obj();
	result->__construct(type);
	return result;}

Dynamic Signal1_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Signal1_obj > result = new Signal1_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Signal1_obj::dispatch( Dynamic value){
{
		HX_STACK_FRAME("msignal.Signal1","dispatch",0x37a20118,"msignal.Signal1.dispatch","msignal/Signal.hx",220,0xeae291fc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(221)
		::msignal::SlotList slotsToProcess = this->slots;		HX_STACK_VAR(slotsToProcess,"slotsToProcess");
		HX_STACK_LINE(223)
		while((true)){
			HX_STACK_LINE(223)
			if ((!(slotsToProcess->nonEmpty))){
				HX_STACK_LINE(223)
				break;
			}
			HX_STACK_LINE(225)
			slotsToProcess->head->__Field(HX_CSTRING("execute"),true)(value);
			HX_STACK_LINE(226)
			slotsToProcess = slotsToProcess->tail;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Signal1_obj,dispatch,(void))

Dynamic Signal1_obj::createSlot( Dynamic _tmp_listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority){
bool once = __o_once.Default(false);
int priority = __o_priority.Default(0);
	HX_STACK_FRAME("msignal.Signal1","createSlot",0xe9d9a4f8,"msignal.Signal1.createSlot","msignal/Signal.hx",232,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(_tmp_listener,"_tmp_listener")
	HX_STACK_ARG(once,"once")
	HX_STACK_ARG(priority,"priority")
{
		HX_STACK_LINE(232)
		Dynamic listener = _tmp_listener;		HX_STACK_VAR(listener,"listener");
		HX_STACK_LINE(232)
		return ::msignal::Slot1_obj::__new(hx::ObjectPtr<OBJ_>(this),listener,once,priority);
	}
}



Signal1_obj::Signal1_obj()
{
}

Dynamic Signal1_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Signal1_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Signal1_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Signal1_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Signal1_obj::__mClass,"__mClass");
};

#endif

Class Signal1_obj::__mClass;

void Signal1_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("msignal.Signal1"), hx::TCanCast< Signal1_obj> ,sStaticFields,sMemberFields,
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

void Signal1_obj::__boot()
{
}

} // end namespace msignal
