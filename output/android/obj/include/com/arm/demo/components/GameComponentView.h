#ifndef INCLUDED_com_arm_demo_components_GameComponentView
#define INCLUDED_com_arm_demo_components_GameComponentView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/arm/demo/view/DemoView.h>
HX_DECLARE_CLASS4(com,arm,demo,components,GameComponentView)
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
namespace components{


class HXCPP_CLASS_ATTRIBUTES  GameComponentView_obj : public ::com::arm::demo::view::DemoView_obj{
	public:
		typedef ::com::arm::demo::view::DemoView_obj super;
		typedef GameComponentView_obj OBJ_;
		GameComponentView_obj();
		Void __construct(::fluid::display::FluidSprite container);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GameComponentView_obj > __new(::fluid::display::FluidSprite container);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GameComponentView_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("GameComponentView"); }

		virtual Void _applyScale( Dynamic item);
		Dynamic _applyScale_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components

#endif /* INCLUDED_com_arm_demo_components_GameComponentView */ 
