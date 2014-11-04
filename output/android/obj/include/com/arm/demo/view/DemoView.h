#ifndef INCLUDED_com_arm_demo_view_DemoView
#define INCLUDED_com_arm_demo_view_DemoView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,arm,demo,view,DemoView)
HX_DECLARE_CLASS2(fluid,display,FluidSprite)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
namespace com{
namespace arm{
namespace demo{
namespace view{


class HXCPP_CLASS_ATTRIBUTES  DemoView_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DemoView_obj OBJ_;
		DemoView_obj();
		Void __construct(::fluid::display::FluidSprite container);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< DemoView_obj > __new(::fluid::display::FluidSprite container);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~DemoView_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DemoView"); }

		::fluid::display::FluidSprite container;
		virtual ::fluid::display::FluidSprite get_container( );
		Dynamic get_container_dyn();

		virtual ::fluid::display::FluidSprite set_container( ::fluid::display::FluidSprite container);
		Dynamic set_container_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace view

#endif /* INCLUDED_com_arm_demo_view_DemoView */ 
