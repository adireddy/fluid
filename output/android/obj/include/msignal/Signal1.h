#ifndef INCLUDED_msignal_Signal1
#define INCLUDED_msignal_Signal1

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <msignal/Signal.h>
HX_DECLARE_CLASS1(msignal,Signal)
HX_DECLARE_CLASS1(msignal,Signal1)
namespace msignal{


class HXCPP_CLASS_ATTRIBUTES  Signal1_obj : public ::msignal::Signal_obj{
	public:
		typedef ::msignal::Signal_obj super;
		typedef Signal1_obj OBJ_;
		Signal1_obj();
		Void __construct(Dynamic type);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Signal1_obj > __new(Dynamic type);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Signal1_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Signal1"); }

		virtual Void dispatch( Dynamic value);
		Dynamic dispatch_dyn();

		virtual Dynamic createSlot( Dynamic _tmp_listener,hx::Null< bool >  once,hx::Null< int >  priority);

};

} // end namespace msignal

#endif /* INCLUDED_msignal_Signal1 */ 
