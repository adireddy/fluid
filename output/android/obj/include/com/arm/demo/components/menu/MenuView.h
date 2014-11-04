#ifndef INCLUDED_com_arm_demo_components_menu_MenuView
#define INCLUDED_com_arm_demo_components_menu_MenuView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/arm/demo/components/GameComponentView.h>
HX_DECLARE_CLASS4(com,arm,demo,components,GameComponentView)
HX_DECLARE_CLASS5(com,arm,demo,components,menu,MenuView)
HX_DECLARE_CLASS4(com,arm,demo,view,DemoView)
HX_DECLARE_CLASS5(com,arm,demo,widgets,menu,PopoutMenu)
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
namespace menu{


class HXCPP_CLASS_ATTRIBUTES  MenuView_obj : public ::com::arm::demo::components::GameComponentView_obj{
	public:
		typedef ::com::arm::demo::components::GameComponentView_obj super;
		typedef MenuView_obj OBJ_;
		MenuView_obj();
		Void __construct(::fluid::display::FluidSprite container);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MenuView_obj > __new(::fluid::display::FluidSprite container);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MenuView_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MenuView"); }

		::com::arm::demo::widgets::menu::PopoutMenu _menu;
		Array< ::String > _menuItems;
		int _currentItem;
		virtual Void create( );
		Dynamic create_dyn();

		virtual Void hide( );
		Dynamic hide_dyn();

		virtual Void _menuClick( int id);
		Dynamic _menuClick_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components
} // end namespace menu

#endif /* INCLUDED_com_arm_demo_components_menu_MenuView */ 
