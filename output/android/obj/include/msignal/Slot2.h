#ifndef INCLUDED_msignal_Slot2
#define INCLUDED_msignal_Slot2

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <msignal/Slot.h>
HX_DECLARE_CLASS1(msignal,Signal)
HX_DECLARE_CLASS1(msignal,Signal2)
HX_DECLARE_CLASS1(msignal,Slot)
HX_DECLARE_CLASS1(msignal,Slot2)
namespace msignal{


class HXCPP_CLASS_ATTRIBUTES  Slot2_obj : public ::msignal::Slot_obj{
	public:
		typedef ::msignal::Slot_obj super;
		typedef Slot2_obj OBJ_;
		Slot2_obj();
		Void __construct(::msignal::Signal2 signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Slot2_obj > __new(::msignal::Signal2 signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Slot2_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Slot2"); }

		Dynamic param1;
		Dynamic param2;
		virtual Void execute( Dynamic value1,Dynamic value2);
		Dynamic execute_dyn();

};

} // end namespace msignal

#endif /* INCLUDED_msignal_Slot2 */ 
