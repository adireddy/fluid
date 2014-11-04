#ifndef INCLUDED_com_arm_demo_widgets_menu_MenuItem
#define INCLUDED_com_arm_demo_widgets_menu_MenuItem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <fluid/display/FluidSprite.h>
HX_DECLARE_CLASS4(com,arm,demo,widgets,Button)
HX_DECLARE_CLASS5(com,arm,demo,widgets,menu,MenuItem)
HX_DECLARE_CLASS2(fluid,display,FluidSprite)
HX_DECLARE_CLASS1(msignal,Signal)
HX_DECLARE_CLASS1(msignal,Signal1)
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


class HXCPP_CLASS_ATTRIBUTES  MenuItem_obj : public ::fluid::display::FluidSprite_obj{
	public:
		typedef ::fluid::display::FluidSprite_obj super;
		typedef MenuItem_obj OBJ_;
		MenuItem_obj();
		Void __construct(::String label,Float width,Float height,Dynamic data);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MenuItem_obj > __new(::String label,Float width,Float height,Dynamic data);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MenuItem_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MenuItem"); }

		Dynamic _data;
		::com::arm::demo::widgets::Button _button;
		::msignal::Signal1 action;
		virtual Void setText( ::String label);
		Dynamic setText_dyn();

		virtual Void enable( );
		Dynamic enable_dyn();

		virtual Void disable( );
		Dynamic disable_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace widgets
} // end namespace menu

#endif /* INCLUDED_com_arm_demo_widgets_menu_MenuItem */ 
