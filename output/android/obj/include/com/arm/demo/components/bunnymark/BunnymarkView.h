#ifndef INCLUDED_com_arm_demo_components_bunnymark_BunnymarkView
#define INCLUDED_com_arm_demo_components_bunnymark_BunnymarkView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/arm/demo/components/GameComponentView.h>
HX_DECLARE_CLASS4(com,arm,demo,components,GameComponentView)
HX_DECLARE_CLASS5(com,arm,demo,components,bunnymark,Bunny)
HX_DECLARE_CLASS5(com,arm,demo,components,bunnymark,BunnymarkView)
HX_DECLARE_CLASS4(com,arm,demo,view,DemoView)
HX_DECLARE_CLASS4(com,arm,demo,widgets,Button)
HX_DECLARE_CLASS4(com,arm,demo,widgets,Label)
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
namespace bunnymark{


class HXCPP_CLASS_ATTRIBUTES  BunnymarkView_obj : public ::com::arm::demo::components::GameComponentView_obj{
	public:
		typedef ::com::arm::demo::components::GameComponentView_obj super;
		typedef BunnymarkView_obj OBJ_;
		BunnymarkView_obj();
		Void __construct(::fluid::display::FluidSprite container);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BunnymarkView_obj > __new(::fluid::display::FluidSprite container);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BunnymarkView_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BunnymarkView"); }

		Array< ::Dynamic > _sprites;
		Array< ::Dynamic > _buttons;
		Dynamic _bunnyTexture;
		::fluid::display::FluidSprite _spriteContainer;
		::fluid::display::FluidSprite _uiContainer;
		::com::arm::demo::widgets::Label _quantityLabel;
		bool _isScale;
		bool _isRotation;
		Float _maxX;
		Float _maxY;
		Float _minX;
		Float _minY;
		virtual Void show( );
		Dynamic show_dyn();

		virtual Void _addButton( ::String label,Float x,Float y,Float width,Float height,Dynamic callback,Dynamic data);
		Dynamic _addButton_dyn();

		virtual Void _updateQuanityLabel( );
		Dynamic _updateQuanityLabel_dyn();

		virtual Void _reset( );
		Dynamic _reset_dyn();

		virtual Void _scale( );
		Dynamic _scale_dyn();

		virtual Void _rotation( );
		Dynamic _rotation_dyn();

		virtual Void _addBunnys( int count);
		Dynamic _addBunnys_dyn();

		virtual Void update( Float elapsedTime);
		Dynamic update_dyn();

		virtual Void resize( );
		Dynamic resize_dyn();

		virtual Void hide( );
		Dynamic hide_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components
} // end namespace bunnymark

#endif /* INCLUDED_com_arm_demo_components_bunnymark_BunnymarkView */ 
