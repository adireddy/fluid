#ifndef INCLUDED_com_arm_demo_widgets_menu_Menu
#define INCLUDED_com_arm_demo_widgets_menu_Menu

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <fluid/display/FluidSprite.h>
HX_DECLARE_CLASS5(com,arm,demo,widgets,menu,Menu)
HX_DECLARE_CLASS5(com,arm,demo,widgets,menu,MenuItem)
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


class HXCPP_CLASS_ATTRIBUTES  Menu_obj : public ::fluid::display::FluidSprite_obj{
	public:
		typedef ::fluid::display::FluidSprite_obj super;
		typedef Menu_obj OBJ_;
		Menu_obj();
		Void __construct(Float itemWidth,Float itemHeight);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Menu_obj > __new(Float itemWidth,Float itemHeight);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Menu_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Menu"); }

		Float _itemWidth;
		Float _itemHeight;
		Array< ::Dynamic > _menuItems;
		Float _lastPosition;
		bool _dragging;
		Float _height;
		virtual ::com::arm::demo::widgets::menu::MenuItem addItem( ::String label,Dynamic data);
		Dynamic addItem_dyn();

		virtual Void _onTouchStart( ::fluid::events::EventData data);
		Dynamic _onTouchStart_dyn();

		virtual Void _onTouchMove( ::fluid::events::EventData data);
		Dynamic _onTouchMove_dyn();

		virtual Void _onTouchEnd( ::fluid::events::EventData data);
		Dynamic _onTouchEnd_dyn();

		virtual Void _onMouseDown( ::fluid::events::EventData data);
		Dynamic _onMouseDown_dyn();

		virtual Void _onMouseUp( ::fluid::events::EventData data);
		Dynamic _onMouseUp_dyn();

		virtual Void _onMouseMove( ::fluid::events::EventData data);
		Dynamic _onMouseMove_dyn();

		virtual Void disableMenuItems( );
		Dynamic disableMenuItems_dyn();

		virtual Void enableMenuItems( );
		Dynamic enableMenuItems_dyn();

		virtual Void _move( Float distance);
		Dynamic _move_dyn();

		virtual Array< ::Dynamic > getItems( );
		Dynamic getItems_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace widgets
} // end namespace menu

#endif /* INCLUDED_com_arm_demo_widgets_menu_Menu */ 
