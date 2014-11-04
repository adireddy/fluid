#include <hxcpp.h>

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
namespace view{

Void DemoView_obj::__construct(::fluid::display::FluidSprite container)
{
HX_STACK_FRAME("com.arm.demo.view.DemoView","new",0x2aa714b7,"com.arm.demo.view.DemoView.new","com/arm/demo/view/DemoView.hx",10,0x29141e77)
HX_STACK_THIS(this)
HX_STACK_ARG(container,"container")
{
	HX_STACK_LINE(10)
	this->set_container(container);
}
;
	return null();
}

//DemoView_obj::~DemoView_obj() { }

Dynamic DemoView_obj::__CreateEmpty() { return  new DemoView_obj; }
hx::ObjectPtr< DemoView_obj > DemoView_obj::__new(::fluid::display::FluidSprite container)
{  hx::ObjectPtr< DemoView_obj > result = new DemoView_obj();
	result->__construct(container);
	return result;}

Dynamic DemoView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DemoView_obj > result = new DemoView_obj();
	result->__construct(inArgs[0]);
	return result;}

::fluid::display::FluidSprite DemoView_obj::get_container( ){
	HX_STACK_FRAME("com.arm.demo.view.DemoView","get_container",0xd0fe002f,"com.arm.demo.view.DemoView.get_container","com/arm/demo/view/DemoView.hx",14,0x29141e77)
	HX_STACK_THIS(this)
	HX_STACK_LINE(14)
	return this->container;
}


HX_DEFINE_DYNAMIC_FUNC0(DemoView_obj,get_container,return )

::fluid::display::FluidSprite DemoView_obj::set_container( ::fluid::display::FluidSprite container){
	HX_STACK_FRAME("com.arm.demo.view.DemoView","set_container",0x1603e23b,"com.arm.demo.view.DemoView.set_container","com/arm/demo/view/DemoView.hx",18,0x29141e77)
	HX_STACK_THIS(this)
	HX_STACK_ARG(container,"container")
	HX_STACK_LINE(18)
	return this->container = container;
}


HX_DEFINE_DYNAMIC_FUNC1(DemoView_obj,set_container,return )

Void DemoView_obj::reset( ){
{
		HX_STACK_FRAME("com.arm.demo.view.DemoView","reset",0xbfb691e6,"com.arm.demo.view.DemoView.reset","com/arm/demo/view/DemoView.hx",22,0x29141e77)
		HX_STACK_THIS(this)
		HX_STACK_LINE(22)
		this->set_container(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DemoView_obj,reset,(void))


DemoView_obj::DemoView_obj()
{
}

void DemoView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DemoView);
	HX_MARK_MEMBER_NAME(container,"container");
	HX_MARK_END_CLASS();
}

void DemoView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(container,"container");
}

Dynamic DemoView_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"container") ) { return inCallProp ? get_container() : container; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_container") ) { return get_container_dyn(); }
		if (HX_FIELD_EQ(inName,"set_container") ) { return set_container_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DemoView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"container") ) { if (inCallProp) return set_container(inValue);container=inValue.Cast< ::fluid::display::FluidSprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DemoView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("container"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::fluid::display::FluidSprite*/ ,(int)offsetof(DemoView_obj,container),HX_CSTRING("container")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("container"),
	HX_CSTRING("get_container"),
	HX_CSTRING("set_container"),
	HX_CSTRING("reset"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DemoView_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DemoView_obj::__mClass,"__mClass");
};

#endif

Class DemoView_obj::__mClass;

void DemoView_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.view.DemoView"), hx::TCanCast< DemoView_obj> ,sStaticFields,sMemberFields,
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

void DemoView_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace view
