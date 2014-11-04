#ifndef INCLUDED_fluid_events_EventData
#define INCLUDED_fluid_events_EventData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(fluid,events,EventData)
namespace fluid{
namespace events{


class HXCPP_CLASS_ATTRIBUTES  EventData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventData_obj OBJ_;
		EventData_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< EventData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EventData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EventData"); }

		Float localX;
		Float localY;
		Float stageX;
		Float stageY;
		Dynamic target;
};

} // end namespace fluid
} // end namespace events

#endif /* INCLUDED_fluid_events_EventData */ 
