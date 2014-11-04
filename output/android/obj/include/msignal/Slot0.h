#ifndef INCLUDED_msignal_Slot0
#define INCLUDED_msignal_Slot0

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <msignal/Slot.h>
HX_DECLARE_CLASS1(msignal,Signal)
HX_DECLARE_CLASS1(msignal,Signal0)
HX_DECLARE_CLASS1(msignal,Slot)
HX_DECLARE_CLASS1(msignal,Slot0)
namespace msignal{


class HXCPP_CLASS_ATTRIBUTES  Slot0_obj : public ::msignal::Slot_obj{
	public:
		typedef ::msignal::Slot_obj super;
		typedef Slot0_obj OBJ_;
		Slot0_obj();
		Void __construct(::msignal::Signal0 signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Slot0_obj > __new(::msignal::Signal0 signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Slot0_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Slot0"); }

		virtual Void execute( );
		Dynamic execute_dyn();

};

} // end namespace msignal

#endif /* INCLUDED_msignal_Slot0 */ 
