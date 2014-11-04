#include <hxcpp.h>

#ifndef INCLUDED_fluid_events_EventData
#include <fluid/events/EventData.h>
#endif
namespace fluid{
namespace events{

Void EventData_obj::__construct()
{
HX_STACK_FRAME("fluid.events.EventData","new",0xc2bdaf05,"fluid.events.EventData.new","fluid/events/EventData.hx",13,0xf8c8fa2b)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//EventData_obj::~EventData_obj() { }

Dynamic EventData_obj::__CreateEmpty() { return  new EventData_obj; }
hx::ObjectPtr< EventData_obj > EventData_obj::__new()
{  hx::ObjectPtr< EventData_obj > result = new EventData_obj();
	result->__construct();
	return result;}

Dynamic EventData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventData_obj > result = new EventData_obj();
	result->__construct();
	return result;}


EventData_obj::EventData_obj()
{
}

void EventData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventData);
	HX_MARK_MEMBER_NAME(localX,"localX");
	HX_MARK_MEMBER_NAME(localY,"localY");
	HX_MARK_MEMBER_NAME(stageX,"stageX");
	HX_MARK_MEMBER_NAME(stageY,"stageY");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_END_CLASS();
}

void EventData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(localX,"localX");
	HX_VISIT_MEMBER_NAME(localY,"localY");
	HX_VISIT_MEMBER_NAME(stageX,"stageX");
	HX_VISIT_MEMBER_NAME(stageY,"stageY");
	HX_VISIT_MEMBER_NAME(target,"target");
}

Dynamic EventData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"localX") ) { return localX; }
		if (HX_FIELD_EQ(inName,"localY") ) { return localY; }
		if (HX_FIELD_EQ(inName,"stageX") ) { return stageX; }
		if (HX_FIELD_EQ(inName,"stageY") ) { return stageY; }
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EventData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"localX") ) { localX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localY") ) { localY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageX") ) { stageX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageY") ) { stageY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EventData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localX"));
	outFields->push(HX_CSTRING("localY"));
	outFields->push(HX_CSTRING("stageX"));
	outFields->push(HX_CSTRING("stageY"));
	outFields->push(HX_CSTRING("target"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(EventData_obj,localX),HX_CSTRING("localX")},
	{hx::fsFloat,(int)offsetof(EventData_obj,localY),HX_CSTRING("localY")},
	{hx::fsFloat,(int)offsetof(EventData_obj,stageX),HX_CSTRING("stageX")},
	{hx::fsFloat,(int)offsetof(EventData_obj,stageY),HX_CSTRING("stageY")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(EventData_obj,target),HX_CSTRING("target")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("localX"),
	HX_CSTRING("localY"),
	HX_CSTRING("stageX"),
	HX_CSTRING("stageY"),
	HX_CSTRING("target"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventData_obj::__mClass,"__mClass");
};

#endif

Class EventData_obj::__mClass;

void EventData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("fluid.events.EventData"), hx::TCanCast< EventData_obj> ,sStaticFields,sMemberFields,
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

void EventData_obj::__boot()
{
}

} // end namespace fluid
} // end namespace events
