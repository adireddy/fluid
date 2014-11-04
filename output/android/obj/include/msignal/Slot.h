#ifndef INCLUDED_msignal_Slot
#define INCLUDED_msignal_Slot

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(msignal,Slot)
namespace msignal{


class HXCPP_CLASS_ATTRIBUTES  Slot_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Slot_obj OBJ_;
		Slot_obj();
		Void __construct(Dynamic signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Slot_obj > __new(Dynamic signal,Dynamic listener,hx::Null< bool >  __o_once,hx::Null< int >  __o_priority);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Slot_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Slot"); }

		Dynamic listener;
		bool once;
		int priority;
		bool enabled;
		Dynamic signal;
		virtual Void remove( );
		Dynamic remove_dyn();

		virtual Dynamic get_listener( );
		Dynamic get_listener_dyn();

		virtual Dynamic set_listener( Dynamic value);
		Dynamic set_listener_dyn();

};

} // end namespace msignal

#endif /* INCLUDED_msignal_Slot */ 
