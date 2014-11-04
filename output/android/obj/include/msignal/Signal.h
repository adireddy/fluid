#ifndef INCLUDED_msignal_Signal
#define INCLUDED_msignal_Signal

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(msignal,Signal)
HX_DECLARE_CLASS1(msignal,SlotList)
namespace msignal{


class HXCPP_CLASS_ATTRIBUTES  Signal_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Signal_obj OBJ_;
		Signal_obj();
		Void __construct(Dynamic valueClasses);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Signal_obj > __new(Dynamic valueClasses);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Signal_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Signal"); }

		Dynamic valueClasses;
		int numListeners;
		::msignal::SlotList slots;
		bool priorityBased;
		virtual Dynamic add( Dynamic listener);
		Dynamic add_dyn();

		virtual Dynamic addOnce( Dynamic listener);
		Dynamic addOnce_dyn();

		virtual Dynamic addWithPriority( Dynamic listener,Dynamic priority);
		Dynamic addWithPriority_dyn();

		virtual Dynamic addOnceWithPriority( Dynamic listener,Dynamic priority);
		Dynamic addOnceWithPriority_dyn();

		virtual Dynamic remove( Dynamic listener);
		Dynamic remove_dyn();

		virtual Void removeAll( );
		Dynamic removeAll_dyn();

		virtual Dynamic registerListener( Dynamic listener,hx::Null< bool >  once,hx::Null< int >  priority);
		Dynamic registerListener_dyn();

		virtual bool registrationPossible( Dynamic listener,bool once);
		Dynamic registrationPossible_dyn();

		virtual Dynamic createSlot( Dynamic listener,hx::Null< bool >  once,hx::Null< int >  priority);
		Dynamic createSlot_dyn();

		virtual int get_numListeners( );
		Dynamic get_numListeners_dyn();

};

} // end namespace msignal

#endif /* INCLUDED_msignal_Signal */ 
