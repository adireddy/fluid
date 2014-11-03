#ifndef INCLUDED_com_arm_demo_Bunny
#define INCLUDED_com_arm_demo_Bunny

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <fluid/display/FluidSprite.h>
HX_DECLARE_CLASS3(com,arm,demo,Bunny)
HX_DECLARE_CLASS2(fluid,display,FluidSprite)
HX_DECLARE_CLASS3(openfl,_v2,display,BitmapData)
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


class HXCPP_CLASS_ATTRIBUTES  Bunny_obj : public ::fluid::display::FluidSprite_obj{
	public:
		typedef ::fluid::display::FluidSprite_obj super;
		typedef Bunny_obj OBJ_;
		Bunny_obj();
		Void __construct(::openfl::_v2::display::BitmapData texture);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Bunny_obj > __new(::openfl::_v2::display::BitmapData texture);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Bunny_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Bunny"); }

		Float speedX;
		Float speedY;
		Float scaleSpeed;
		Float rotationSpeed;
};

} // end namespace com
} // end namespace arm
} // end namespace demo

#endif /* INCLUDED_com_arm_demo_Bunny */ 
