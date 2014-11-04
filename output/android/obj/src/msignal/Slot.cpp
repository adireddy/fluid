#include <hxcpp.h>

#ifndef INCLUDED_msignal_Slot
#include <msignal/Slot.h>
#endif
namespace msignal{

Void Slot_obj::__construct(Dynamic signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority)
{
HX_STACK_FRAME("msignal.Slot","new",0x22a43709,"msignal.Slot.new","msignal/Slot.hx",74,0x8d27aea6)
HX_STACK_THIS(this)
HX_STACK_ARG(signal,"signal")
HX_STACK_ARG(listener,"listener")
HX_STACK_ARG(__o_once,"once")
HX_STACK_ARG(__o_priority,"priority")
bool once = __o_once.Default(false);
int priority = __o_priority.Default(0);
{
	HX_STACK_LINE(75)
	this->signal = signal;
	HX_STACK_LINE(76)
	this->set_listener(listener);
	HX_STACK_LINE(77)
	this->once = once;
	HX_STACK_LINE(78)
	this->priority = priority;
	HX_STACK_LINE(79)
	this->enabled = true;
}
;
	return null();
}

//Slot_obj::~Slot_obj() { }

Dynamic Slot_obj::__CreateEmpty() { return  new Slot_obj; }
hx::ObjectPtr< Slot_obj > Slot_obj::__new(Dynamic signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority)
{  hx::ObjectPtr< Slot_obj > result = new Slot_obj();
	result->__construct(signal,listener,__o_once,__o_priority);
	return result;}

Dynamic Slot_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Slot_obj > result = new Slot_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Slot_obj::remove( ){
{
		HX_STACK_FRAME("msignal.Slot","remove",0x0fb1053b,"msignal.Slot.remove","msignal/Slot.hx",86,0x8d27aea6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(87)
		Dynamic _g = this->get_listener();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(87)
		this->signal->__Field(HX_CSTRING("remove"),true)(_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Slot_obj,remove,(void))

Dynamic Slot_obj::get_listener( ){
	HX_STACK_FRAME("msignal.Slot","get_listener",0x9de7b0b4,"msignal.Slot.get_listener","msignal/Slot.hx",97,0x8d27aea6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(97)
	return this->listener;
}


HX_DEFINE_DYNAMIC_FUNC0(Slot_obj,get_listener,return )

Dynamic Slot_obj::set_listener( Dynamic value){
	HX_STACK_FRAME("msignal.Slot","set_listener",0xb2e0d428,"msignal.Slot.set_listener","msignal/Slot.hx",102,0x8d27aea6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(103)
	if (((value == null()))){
		HX_STACK_LINE(103)
		HX_STACK_DO_THROW(HX_CSTRING("listener cannot be null"));
	}
	HX_STACK_LINE(104)
	return this->listener = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Slot_obj,set_listener,return )


Slot_obj::Slot_obj()
{
}

void Slot_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Slot);
	HX_MARK_MEMBER_NAME(listener,"listener");
	HX_MARK_MEMBER_NAME(once,"once");
	HX_MARK_MEMBER_NAME(priority,"priority");
	HX_MARK_MEMBER_NAME(enabled,"enabled");
	HX_MARK_MEMBER_NAME(signal,"signal");
	HX_MARK_END_CLASS();
}

void Slot_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(listener,"listener");
	HX_VISIT_MEMBER_NAME(once,"once");
	HX_VISIT_MEMBER_NAME(priority,"priority");
	HX_VISIT_MEMBER_NAME(enabled,"enabled");
	HX_VISIT_MEMBER_NAME(signal,"signal");
}

Dynamic Slot_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"once") ) { return once; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"signal") ) { return signal; }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return enabled; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { return inCallProp ? get_listener() : listener; }
		if (HX_FIELD_EQ(inName,"priority") ) { return priority; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_listener") ) { return get_listener_dyn(); }
		if (HX_FIELD_EQ(inName,"set_listener") ) { return set_listener_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Slot_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"once") ) { once=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"signal") ) { signal=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { enabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { if (inCallProp) return set_listener(inValue);listener=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"priority") ) { priority=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Slot_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("listener"));
	outFields->push(HX_CSTRING("once"));
	outFields->push(HX_CSTRING("priority"));
	outFields->push(HX_CSTRING("enabled"));
	outFields->push(HX_CSTRING("signal"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Slot_obj,listener),HX_CSTRING("listener")},
	{hx::fsBool,(int)offsetof(Slot_obj,once),HX_CSTRING("once")},
	{hx::fsInt,(int)offsetof(Slot_obj,priority),HX_CSTRING("priority")},
	{hx::fsBool,(int)offsetof(Slot_obj,enabled),HX_CSTRING("enabled")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Slot_obj,signal),HX_CSTRING("signal")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("listener"),
	HX_CSTRING("once"),
	HX_CSTRING("priority"),
	HX_CSTRING("enabled"),
	HX_CSTRING("signal"),
	HX_CSTRING("remove"),
	HX_CSTRING("get_listener"),
	HX_CSTRING("set_listener"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Slot_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Slot_obj::__mClass,"__mClass");
};

#endif

Class Slot_obj::__mClass;

void Slot_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("msignal.Slot"), hx::TCanCast< Slot_obj> ,sStaticFields,sMemberFields,
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

void Slot_obj::__boot()
{
}

} // end namespace msignal
