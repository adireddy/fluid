#ifndef INCLUDED_ScaledStage
#define INCLUDED_ScaledStage

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Stage.h>
HX_DECLARE_CLASS0(ScaledStage)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Stage)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  ScaledStage_obj : public ::openfl::_v2::display::Stage_obj{
	public:
		typedef ::openfl::_v2::display::Stage_obj super;
		typedef ScaledStage_obj OBJ_;
		ScaledStage_obj();
		Void __construct(Dynamic inHandle,int inWidth,int inHeight);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ScaledStage_obj > __new(Dynamic inHandle,int inWidth,int inHeight);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ScaledStage_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("ScaledStage"); }

		int __stageHeight;
		int __stageWidth;
		virtual int get___stageHeight( );
		Dynamic get___stageHeight_dyn();

		virtual int get___stageWidth( );
		Dynamic get___stageWidth_dyn();

		virtual int get_stageHeight( );

		virtual int get_stageWidth( );

};


#endif /* INCLUDED_ScaledStage */ 
