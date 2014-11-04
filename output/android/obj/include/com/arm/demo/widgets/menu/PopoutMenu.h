#ifndef INCLUDED_com_arm_demo_widgets_menu_PopoutMenu
#define INCLUDED_com_arm_demo_widgets_menu_PopoutMenu

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <fluid/display/FluidSprite.h>
HX_DECLARE_CLASS5(com,arm,demo,widgets,menu,Menu)
HX_DECLARE_CLASS5(com,arm,demo,widgets,menu,MenuItem)
HX_DECLARE_CLASS5(com,arm,demo,widgets,menu,PopoutMenu)
HX_DECLARE_CLASS2(fluid,display,FluidGraphics)
HX_DECLARE_CLASS2(fluid,display,FluidSprite)
HX_DECLARE_CLASS2(fluid,events,EventData)
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
namespace widgets{
namespace menu{


class HXCPP_CLASS_ATTRIBUTES  PopoutMenu_obj : public ::fluid::display::FluidSprite_obj{
	public:
		typedef ::fluid::display::FluidSprite_obj super;
		typedef PopoutMenu_obj OBJ_;
		PopoutMenu_obj();
		Void __construct(Float itemWidth,Float itemHeight);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PopoutMenu_obj > __new(Float itemWidth,Float itemHeight);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PopoutMenu_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PopoutMenu"); }

		::fluid::display::FluidSprite _container;
		Float _itemWidth;
		Float _itemHeight;
		::String _state;
		::com::arm::demo::widgets::menu::Menu _menu;
		::fluid::display::FluidGraphics _openButton;
		virtual Void _setupOpenButton( );
		Dynamic _setupOpenButton_dyn();

		virtual Void _setupMenu( Float itemWidth,Float itemHeight);
		Dynamic _setupMenu_dyn();

		virtual Void _toggleShow( ::fluid::events::EventData data);
		Dynamic _toggleShow_dyn();

		virtual Void show( );
		Dynamic show_dyn();

		virtual Void hide( );
		Dynamic hide_dyn();

		virtual ::com::arm::demo::widgets::menu::MenuItem addItem( ::String label,Dynamic data);
		Dynamic addItem_dyn();

		virtual Void _enableMenuItems( );
		Dynamic _enableMenuItems_dyn();

		virtual Void _disableMenuItems( );
		Dynamic _disableMenuItems_dyn();

		virtual Void _updateOpenButtonPosition( );
		Dynamic _updateOpenButtonPosition_dyn();

		static ::String STATE_SHOW;
		static ::String STATE_HIDE;
};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace widgets
} // end namespace menu

#endif /* INCLUDED_com_arm_demo_widgets_menu_PopoutMenu */ 
