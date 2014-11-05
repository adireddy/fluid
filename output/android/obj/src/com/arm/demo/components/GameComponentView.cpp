#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_components_GameComponentView
#include <com/arm/demo/components/GameComponentView.h>
#endif
#ifndef INCLUDED_com_arm_demo_components_bunnymark_Bunny
#include <com/arm/demo/components/bunnymark/Bunny.h>
#endif
#ifndef INCLUDED_com_arm_demo_view_DemoView
#include <com/arm/demo/view/DemoView.h>
#endif
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
namespace com{
namespace arm{
namespace demo{
namespace components{

Void GameComponentView_obj::__construct(::fluid::display::FluidSprite container)
{
HX_STACK_FRAME("com.arm.demo.components.GameComponentView","new",0x86fbf996,"com.arm.demo.components.GameComponentView.new","com/arm/demo/components/GameComponentView.hx",18,0x76330dbc)
HX_STACK_THIS(this)
HX_STACK_ARG(container,"container")
{
	HX_STACK_LINE(18)
	super::__construct(container);
}
;
	return null();
}

//GameComponentView_obj::~GameComponentView_obj() { }

Dynamic GameComponentView_obj::__CreateEmpty() { return  new GameComponentView_obj; }
hx::ObjectPtr< GameComponentView_obj > GameComponentView_obj::__new(::fluid::display::FluidSprite container)
{  hx::ObjectPtr< GameComponentView_obj > result = new GameComponentView_obj();
	result->__construct(container);
	return result;}

Dynamic GameComponentView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameComponentView_obj > result = new GameComponentView_obj();
	result->__construct(inArgs[0]);
	return result;}

Void GameComponentView_obj::_applyScale( ::com::arm::demo::components::bunnymark::Bunny item){
{
		HX_STACK_FRAME("com.arm.demo.components.GameComponentView","_applyScale",0x8e0f6691,"com.arm.demo.components.GameComponentView._applyScale","com/arm/demo/components/GameComponentView.hx",26,0x76330dbc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(item,"item")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameComponentView_obj,_applyScale,(void))


GameComponentView_obj::GameComponentView_obj()
{
}

Dynamic GameComponentView_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"_applyScale") ) { return _applyScale_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameComponentView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void GameComponentView_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_applyScale"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameComponentView_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameComponentView_obj::__mClass,"__mClass");
};

#endif

Class GameComponentView_obj::__mClass;

void GameComponentView_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.components.GameComponentView"), hx::TCanCast< GameComponentView_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void GameComponentView_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components
