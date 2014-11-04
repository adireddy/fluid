#include <hxcpp.h>

#ifndef INCLUDED_msignal_Signal
#include <msignal/Signal.h>
#endif
#ifndef INCLUDED_msignal_SlotList
#include <msignal/SlotList.h>
#endif
namespace msignal{

Void Signal_obj::__construct(Dynamic valueClasses)
{
HX_STACK_FRAME("msignal.Signal","new",0x1a833cb3,"msignal.Signal.new","msignal/Signal.hx",49,0xeae291fc)
HX_STACK_THIS(this)
HX_STACK_ARG(valueClasses,"valueClasses")
{
	HX_STACK_LINE(50)
	if (((valueClasses == null()))){
		HX_STACK_LINE(50)
		valueClasses = Dynamic( Array_obj<Dynamic>::__new());
	}
	HX_STACK_LINE(51)
	this->valueClasses = valueClasses;
	HX_STACK_LINE(52)
	this->slots = ::msignal::SlotList_obj::NIL;
	HX_STACK_LINE(53)
	this->priorityBased = false;
}
;
	return null();
}

//Signal_obj::~Signal_obj() { }

Dynamic Signal_obj::__CreateEmpty() { return  new Signal_obj; }
hx::ObjectPtr< Signal_obj > Signal_obj::__new(Dynamic valueClasses)
{  hx::ObjectPtr< Signal_obj > result = new Signal_obj();
	result->__construct(valueClasses);
	return result;}

Dynamic Signal_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Signal_obj > result = new Signal_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic Signal_obj::add( Dynamic listener){
	HX_STACK_FRAME("msignal.Signal","add",0x1a795e74,"msignal.Signal.add","msignal/Signal.hx",64,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_LINE(64)
	return this->registerListener(listener,null(),null());
}


HX_DEFINE_DYNAMIC_FUNC1(Signal_obj,add,return )

Dynamic Signal_obj::addOnce( Dynamic listener){
	HX_STACK_FRAME("msignal.Signal","addOnce",0xf4875215,"msignal.Signal.addOnce","msignal/Signal.hx",77,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_LINE(77)
	return this->registerListener(listener,true,null());
}


HX_DEFINE_DYNAMIC_FUNC1(Signal_obj,addOnce,return )

Dynamic Signal_obj::addWithPriority( Dynamic listener,Dynamic __o_priority){
Dynamic priority = __o_priority.Default(0);
	HX_STACK_FRAME("msignal.Signal","addWithPriority",0x5150ac1e,"msignal.Signal.addWithPriority","msignal/Signal.hx",92,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_ARG(priority,"priority")
{
		HX_STACK_LINE(92)
		return this->registerListener(listener,false,priority);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Signal_obj,addWithPriority,return )

Dynamic Signal_obj::addOnceWithPriority( Dynamic listener,Dynamic __o_priority){
Dynamic priority = __o_priority.Default(0);
	HX_STACK_FRAME("msignal.Signal","addOnceWithPriority",0x200e0d3f,"msignal.Signal.addOnceWithPriority","msignal/Signal.hx",105,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_ARG(priority,"priority")
{
		HX_STACK_LINE(105)
		return this->registerListener(listener,true,priority);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Signal_obj,addOnceWithPriority,return )

Dynamic Signal_obj::remove( Dynamic listener){
	HX_STACK_FRAME("msignal.Signal","remove",0xcba165d1,"msignal.Signal.remove","msignal/Signal.hx",115,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_LINE(116)
	Dynamic slot = this->slots->find(listener);		HX_STACK_VAR(slot,"slot");
	HX_STACK_LINE(117)
	if (((slot == null()))){
		HX_STACK_LINE(117)
		return null();
	}
	HX_STACK_LINE(119)
	::msignal::SlotList _g = this->slots->filterNot(listener);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(119)
	this->slots = _g;
	HX_STACK_LINE(120)
	return slot;
}


HX_DEFINE_DYNAMIC_FUNC1(Signal_obj,remove,return )

Void Signal_obj::removeAll( ){
{
		HX_STACK_FRAME("msignal.Signal","removeAll",0xbbe303d0,"msignal.Signal.removeAll","msignal/Signal.hx",128,0xeae291fc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(128)
		this->slots = ::msignal::SlotList_obj::NIL;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Signal_obj,removeAll,(void))

Dynamic Signal_obj::registerListener( Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority){
bool once = __o_once.Default(false);
int priority = __o_priority.Default(0);
	HX_STACK_FRAME("msignal.Signal","registerListener",0x68c419c4,"msignal.Signal.registerListener","msignal/Signal.hx",132,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_ARG(once,"once")
	HX_STACK_ARG(priority,"priority")
{
		HX_STACK_LINE(133)
		if ((this->registrationPossible(listener,once))){
			HX_STACK_LINE(135)
			Dynamic newSlot = this->createSlot(listener,once,priority);		HX_STACK_VAR(newSlot,"newSlot");
			HX_STACK_LINE(137)
			if (((bool(!(this->priorityBased)) && bool((priority != (int)0))))){
				HX_STACK_LINE(137)
				this->priorityBased = true;
			}
			HX_STACK_LINE(138)
			if (((bool(!(this->priorityBased)) && bool((priority == (int)0))))){
				HX_STACK_LINE(138)
				::msignal::SlotList _g = this->slots->prepend(newSlot);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(138)
				this->slots = _g;
			}
			else{
				HX_STACK_LINE(139)
				::msignal::SlotList _g1 = this->slots->insertWithPriority(newSlot);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(139)
				this->slots = _g1;
			}
			HX_STACK_LINE(141)
			return newSlot;
		}
		HX_STACK_LINE(144)
		return this->slots->find(listener);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(Signal_obj,registerListener,return )

bool Signal_obj::registrationPossible( Dynamic listener,bool once){
	HX_STACK_FRAME("msignal.Signal","registrationPossible",0x7873dbd7,"msignal.Signal.registrationPossible","msignal/Signal.hx",148,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_ARG(once,"once")
	HX_STACK_LINE(149)
	if ((!(this->slots->nonEmpty))){
		HX_STACK_LINE(149)
		return true;
	}
	HX_STACK_LINE(151)
	Dynamic existingSlot = this->slots->find(listener);		HX_STACK_VAR(existingSlot,"existingSlot");
	HX_STACK_LINE(152)
	if (((existingSlot == null()))){
		HX_STACK_LINE(152)
		return true;
	}
	HX_STACK_LINE(154)
	if (((existingSlot->__Field(HX_CSTRING("once"),true) != once))){
		HX_STACK_LINE(158)
		HX_STACK_DO_THROW(HX_CSTRING("You cannot addOnce() then add() the same listener without removing the relationship first."));
	}
	HX_STACK_LINE(161)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(Signal_obj,registrationPossible,return )

Dynamic Signal_obj::createSlot( Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority){
bool once = __o_once.Default(false);
int priority = __o_priority.Default(0);
	HX_STACK_FRAME("msignal.Signal","createSlot",0x4c14b327,"msignal.Signal.createSlot","msignal/Signal.hx",167,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_ARG(once,"once")
	HX_STACK_ARG(priority,"priority")
{
		HX_STACK_LINE(167)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC3(Signal_obj,createSlot,return )

int Signal_obj::get_numListeners( ){
	HX_STACK_FRAME("msignal.Signal","get_numListeners",0xd16c76af,"msignal.Signal.get_numListeners","msignal/Signal.hx",172,0xeae291fc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(172)
	return this->slots->get_length();
}


HX_DEFINE_DYNAMIC_FUNC0(Signal_obj,get_numListeners,return )


Signal_obj::Signal_obj()
{
}

void Signal_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Signal);
	HX_MARK_MEMBER_NAME(valueClasses,"valueClasses");
	HX_MARK_MEMBER_NAME(numListeners,"numListeners");
	HX_MARK_MEMBER_NAME(slots,"slots");
	HX_MARK_MEMBER_NAME(priorityBased,"priorityBased");
	HX_MARK_END_CLASS();
}

void Signal_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(valueClasses,"valueClasses");
	HX_VISIT_MEMBER_NAME(numListeners,"numListeners");
	HX_VISIT_MEMBER_NAME(slots,"slots");
	HX_VISIT_MEMBER_NAME(priorityBased,"priorityBased");
}

Dynamic Signal_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"slots") ) { return slots; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addOnce") ) { return addOnce_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"removeAll") ) { return removeAll_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"createSlot") ) { return createSlot_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"valueClasses") ) { return valueClasses; }
		if (HX_FIELD_EQ(inName,"numListeners") ) { return inCallProp ? get_numListeners() : numListeners; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"priorityBased") ) { return priorityBased; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"addWithPriority") ) { return addWithPriority_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"registerListener") ) { return registerListener_dyn(); }
		if (HX_FIELD_EQ(inName,"get_numListeners") ) { return get_numListeners_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"addOnceWithPriority") ) { return addOnceWithPriority_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"registrationPossible") ) { return registrationPossible_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Signal_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"slots") ) { slots=inValue.Cast< ::msignal::SlotList >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"valueClasses") ) { valueClasses=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"numListeners") ) { numListeners=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"priorityBased") ) { priorityBased=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Signal_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("valueClasses"));
	outFields->push(HX_CSTRING("numListeners"));
	outFields->push(HX_CSTRING("slots"));
	outFields->push(HX_CSTRING("priorityBased"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Signal_obj,valueClasses),HX_CSTRING("valueClasses")},
	{hx::fsInt,(int)offsetof(Signal_obj,numListeners),HX_CSTRING("numListeners")},
	{hx::fsObject /*::msignal::SlotList*/ ,(int)offsetof(Signal_obj,slots),HX_CSTRING("slots")},
	{hx::fsBool,(int)offsetof(Signal_obj,priorityBased),HX_CSTRING("priorityBased")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("valueClasses"),
	HX_CSTRING("numListeners"),
	HX_CSTRING("slots"),
	HX_CSTRING("priorityBased"),
	HX_CSTRING("add"),
	HX_CSTRING("addOnce"),
	HX_CSTRING("addWithPriority"),
	HX_CSTRING("addOnceWithPriority"),
	HX_CSTRING("remove"),
	HX_CSTRING("removeAll"),
	HX_CSTRING("registerListener"),
	HX_CSTRING("registrationPossible"),
	HX_CSTRING("createSlot"),
	HX_CSTRING("get_numListeners"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Signal_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Signal_obj::__mClass,"__mClass");
};

#endif

Class Signal_obj::__mClass;

void Signal_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("msignal.Signal"), hx::TCanCast< Signal_obj> ,sStaticFields,sMemberFields,
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

void Signal_obj::__boot()
{
}

} // end namespace msignal
