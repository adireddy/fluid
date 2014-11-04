#ifndef INCLUDED_msignal_SlotList
#define INCLUDED_msignal_SlotList

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(msignal,SlotList)
namespace msignal{


class HXCPP_CLASS_ATTRIBUTES  SlotList_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SlotList_obj OBJ_;
		SlotList_obj();
		Void __construct(Dynamic head,::msignal::SlotList tail);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SlotList_obj > __new(Dynamic head,::msignal::SlotList tail);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SlotList_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		static void __init__();

		::String __ToString() const { return HX_CSTRING("SlotList"); }

		Dynamic head;
		::msignal::SlotList tail;
		bool nonEmpty;
		int length;
		virtual int get_length( );
		Dynamic get_length_dyn();

		virtual ::msignal::SlotList prepend( Dynamic slot);
		Dynamic prepend_dyn();

		virtual ::msignal::SlotList append( Dynamic slot);
		Dynamic append_dyn();

		virtual ::msignal::SlotList insertWithPriority( Dynamic slot);
		Dynamic insertWithPriority_dyn();

		virtual ::msignal::SlotList filterNot( Dynamic listener);
		Dynamic filterNot_dyn();

		virtual bool contains( Dynamic listener);
		Dynamic contains_dyn();

		virtual Dynamic find( Dynamic listener);
		Dynamic find_dyn();

		static ::msignal::SlotList NIL;
};

} // end namespace msignal

#endif /* INCLUDED_msignal_SlotList */ 
