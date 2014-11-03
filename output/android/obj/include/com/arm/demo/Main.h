#ifndef INCLUDED_com_arm_demo_Main
#define INCLUDED_com_arm_demo_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <fluid/Fluid.h>
HX_DECLARE_CLASS3(com,arm,demo,Bunny)
HX_DECLARE_CLASS3(com,arm,demo,Main)
HX_DECLARE_CLASS1(fluid,Fluid)
HX_DECLARE_CLASS2(fluid,display,FluidSprite)
HX_DECLARE_CLASS2(fluid,text,FluidText)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,text,TextField)
namespace com{
namespace arm{
namespace demo{


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public ::fluid::Fluid_obj{
	public:
		typedef ::fluid::Fluid_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		Dynamic _bunnyTexture;
		Array< ::Dynamic > _sprites;
		Float _maxX;
		Float _maxY;
		Float _minX;
		Float _minY;
		int _count;
		::fluid::text::FluidText _countText;
		bool _addBunnies;
		virtual Void _addBunnys( int count);
		Dynamic _addBunnys_dyn();

		virtual Void _update( Float elapsedTime);

		virtual Void _resize( );

};

} // end namespace com
} // end namespace arm
} // end namespace demo

#endif /* INCLUDED_com_arm_demo_Main */ 
