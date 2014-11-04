#ifndef INCLUDED_msignal_Signal0
#define INCLUDED_msignal_Signal0

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <msignal/Signal.h>
HX_DECLARE_CLASS1(msignal,Signal)
HX_DECLARE_CLASS1(msignal,Signal0)
namespace msignal{


class HXCPP_CLASS_ATTRIBUTES  Signal0_obj : public ::msignal::Signal_obj{
	public:
		typedef ::msignal::Signal_obj super;
		typedef Signal0_obj OBJ_;
		Signal0_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Signal0_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Signal0_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Signal0"); }

		virtual Void dispatch( );
		Dynamic dispatch_dyn();

		virtual Dynamic createSlot( Dynamic _tmp_listener,hx::Null< bool >  once,hx::Null< int >  priority);

};

} // end namespace msignal

#endif /* INCLUDED_msignal_Signal0 */ 
