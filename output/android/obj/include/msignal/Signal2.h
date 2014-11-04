#ifndef INCLUDED_msignal_Signal2
#define INCLUDED_msignal_Signal2

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <msignal/Signal.h>
HX_DECLARE_CLASS1(msignal,Signal)
HX_DECLARE_CLASS1(msignal,Signal2)
namespace msignal{


class HXCPP_CLASS_ATTRIBUTES  Signal2_obj : public ::msignal::Signal_obj{
	public:
		typedef ::msignal::Signal_obj super;
		typedef Signal2_obj OBJ_;
		Signal2_obj();
		Void __construct(Dynamic type1,Dynamic type2);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Signal2_obj > __new(Dynamic type1,Dynamic type2);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Signal2_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Signal2"); }

		virtual Void dispatch( Dynamic value1,Dynamic value2);
		Dynamic dispatch_dyn();

		virtual Dynamic createSlot( Dynamic _tmp_listener,hx::Null< bool >  once,hx::Null< int >  priority);

};

} // end namespace msignal

#endif /* INCLUDED_msignal_Signal2 */ 
