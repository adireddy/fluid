#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_openfl__v2_events_Event
#include <openfl/_v2/events/Event.h>
#endif
#ifndef INCLUDED_openfl__v2_events_Listener
#include <openfl/_v2/events/Listener.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_WeakRef
#include <openfl/_v2/utils/WeakRef.h>
#endif
namespace openfl{
namespace _v2{
namespace events{

Void Listener_obj::__construct(::openfl::_v2::utils::WeakRef listener,bool useCapture,int priority)
{
HX_STACK_FRAME("openfl._v2.events.Listener","new",0x5af4744a,"openfl._v2.events.Listener.new","openfl/_v2/events/EventDispatcher.hx",258,0x3e68c260)
HX_STACK_THIS(this)
HX_STACK_ARG(listener,"listener")
HX_STACK_ARG(useCapture,"useCapture")
HX_STACK_ARG(priority,"priority")
{
	HX_STACK_LINE(260)
	this->listener = listener;
	HX_STACK_LINE(261)
	this->useCapture = useCapture;
	HX_STACK_LINE(262)
	this->priority = priority;
	HX_STACK_LINE(263)
	int _g = (::openfl::_v2::events::Listener_obj::__id)++;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(263)
	this->id = _g;
}
;
	return null();
}

//Listener_obj::~Listener_obj() { }

Dynamic Listener_obj::__CreateEmpty() { return  new Listener_obj; }
hx::ObjectPtr< Listener_obj > Listener_obj::__new(::openfl::_v2::utils::WeakRef listener,bool useCapture,int priority)
{  hx::ObjectPtr< Listener_obj > result = new Listener_obj();
	result->__construct(listener,useCapture,priority);
	return result;}

Dynamic Listener_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Listener_obj > result = new Listener_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Listener_obj::dispatchEvent( ::openfl::_v2::events::Event event){
{
		HX_STACK_FRAME("openfl._v2.events.Listener","dispatchEvent",0x129d336a,"openfl._v2.events.Listener.dispatchEvent","openfl/_v2/events/EventDispatcher.hx",270,0x3e68c260)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(270)
		this->listener->get()(event).Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Listener_obj,dispatchEvent,(void))

bool Listener_obj::is( Dynamic listener,bool useCapture){
	HX_STACK_FRAME("openfl._v2.events.Listener","is",0x656e2340,"openfl._v2.events.Listener.is","openfl/_v2/events/EventDispatcher.hx",275,0x3e68c260)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_ARG(useCapture,"useCapture")
	HX_STACK_LINE(277)
	Dynamic _g = this->listener->get();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(277)
	if ((::Reflect_obj::compareMethods(_g,listener))){
		HX_STACK_LINE(277)
		return (this->useCapture == useCapture);
	}
	else{
		HX_STACK_LINE(277)
		return false;
	}
	HX_STACK_LINE(277)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(Listener_obj,is,return )

int Listener_obj::__id;


Listener_obj::Listener_obj()
{
}

void Listener_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Listener);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(listener,"listener");
	HX_MARK_MEMBER_NAME(priority,"priority");
	HX_MARK_MEMBER_NAME(useCapture,"useCapture");
	HX_MARK_END_CLASS();
}

void Listener_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(listener,"listener");
	HX_VISIT_MEMBER_NAME(priority,"priority");
	HX_VISIT_MEMBER_NAME(useCapture,"useCapture");
}

Dynamic Listener_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		if (HX_FIELD_EQ(inName,"is") ) { return is_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"__id") ) { return __id; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { return listener; }
		if (HX_FIELD_EQ(inName,"priority") ) { return priority; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"useCapture") ) { return useCapture; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Listener_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"__id") ) { __id=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { listener=inValue.Cast< ::openfl::_v2::utils::WeakRef >(); return inValue; }
		if (HX_FIELD_EQ(inName,"priority") ) { priority=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"useCapture") ) { useCapture=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Listener_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("listener"));
	outFields->push(HX_CSTRING("priority"));
	outFields->push(HX_CSTRING("useCapture"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("__id"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Listener_obj,id),HX_CSTRING("id")},
	{hx::fsObject /*::openfl::_v2::utils::WeakRef*/ ,(int)offsetof(Listener_obj,listener),HX_CSTRING("listener")},
	{hx::fsInt,(int)offsetof(Listener_obj,priority),HX_CSTRING("priority")},
	{hx::fsBool,(int)offsetof(Listener_obj,useCapture),HX_CSTRING("useCapture")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("listener"),
	HX_CSTRING("priority"),
	HX_CSTRING("useCapture"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("is"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Listener_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Listener_obj::__id,"__id");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Listener_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Listener_obj::__id,"__id");
};

#endif

Class Listener_obj::__mClass;

void Listener_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl._v2.events.Listener"), hx::TCanCast< Listener_obj> ,sStaticFields,sMemberFields,
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

void Listener_obj::__boot()
{
	__id= (int)1;
}

} // end namespace openfl
} // end namespace _v2
} // end namespace events
