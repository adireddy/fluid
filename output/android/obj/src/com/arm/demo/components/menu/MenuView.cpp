#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_components_GameComponentView
#include <com/arm/demo/components/GameComponentView.h>
#endif
#ifndef INCLUDED_com_arm_demo_components_menu_MenuView
#include <com/arm/demo/components/menu/MenuView.h>
#endif
#ifndef INCLUDED_com_arm_demo_notifications_internal_MenuNotification
#include <com/arm/demo/notifications/internal/MenuNotification.h>
#endif
#ifndef INCLUDED_com_arm_demo_view_DemoView
#include <com/arm/demo/view/DemoView.h>
#endif
#ifndef INCLUDED_com_arm_demo_widgets_menu_MenuItem
#include <com/arm/demo/widgets/menu/MenuItem.h>
#endif
#ifndef INCLUDED_com_arm_demo_widgets_menu_PopoutMenu
#include <com/arm/demo/widgets/menu/PopoutMenu.h>
#endif
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
#endif
#ifndef INCLUDED_fluid_display_FluidStage
#include <fluid/display/FluidStage.h>
#endif
#ifndef INCLUDED_msignal_Signal
#include <msignal/Signal.h>
#endif
#ifndef INCLUDED_msignal_Signal0
#include <msignal/Signal0.h>
#endif
#ifndef INCLUDED_msignal_Signal1
#include <msignal/Signal1.h>
#endif
#ifndef INCLUDED_msignal_Slot
#include <msignal/Slot.h>
#endif
#ifndef INCLUDED_msignal_Slot1
#include <msignal/Slot1.h>
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
#ifndef INCLUDED_openfl__v2_display_Stage
#include <openfl/_v2/display/Stage.h>
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
namespace menu{

Void MenuView_obj::__construct(::fluid::display::FluidSprite container)
{
HX_STACK_FRAME("com.arm.demo.components.menu.MenuView","new",0x970e1739,"com.arm.demo.components.menu.MenuView.new","com/arm/demo/components/menu/MenuView.hx",15,0x52c66a18)
HX_STACK_THIS(this)
HX_STACK_ARG(container,"container")
{
	HX_STACK_LINE(16)
	super::__construct(container);
	HX_STACK_LINE(17)
	this->_menuItems = Array_obj< ::String >::__new().Add(HX_CSTRING("Screen Test")).Add(HX_CSTRING("Screen Guide")).Add(HX_CSTRING("Localisation")).Add(HX_CSTRING("Sprites")).Add(HX_CSTRING("Bunnys")).Add(HX_CSTRING("Sprite Sheets")).Add(HX_CSTRING("Coin Shower")).Add(HX_CSTRING("Typekit")).Add(HX_CSTRING("Audio")).Add(HX_CSTRING("Currency Format")).Add(HX_CSTRING("Server Request")).Add(HX_CSTRING("Console Bridge")).Add(HX_CSTRING("Reels")).Add(HX_CSTRING("Skeleton Animation")).Add(HX_CSTRING("Physics")).Add(HX_CSTRING("Reset"));
}
;
	return null();
}

//MenuView_obj::~MenuView_obj() { }

Dynamic MenuView_obj::__CreateEmpty() { return  new MenuView_obj; }
hx::ObjectPtr< MenuView_obj > MenuView_obj::__new(::fluid::display::FluidSprite container)
{  hx::ObjectPtr< MenuView_obj > result = new MenuView_obj();
	result->__construct(container);
	return result;}

Dynamic MenuView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MenuView_obj > result = new MenuView_obj();
	result->__construct(inArgs[0]);
	return result;}

Void MenuView_obj::create( ){
{
		HX_STACK_FRAME("com.arm.demo.components.menu.MenuView","create",0x29f42dc3,"com.arm.demo.components.menu.MenuView.create","com/arm/demo/components/menu/MenuView.hx",20,0x52c66a18)
		HX_STACK_THIS(this)
		HX_STACK_LINE(21)
		::com::arm::demo::widgets::menu::PopoutMenu _g = ::com::arm::demo::widgets::menu::PopoutMenu_obj::__new((int)180,(int)40);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(21)
		this->_menu = _g;
		HX_STACK_LINE(22)
		::com::arm::demo::widgets::menu::MenuItem _menuItem;		HX_STACK_VAR(_menuItem,"_menuItem");
		HX_STACK_LINE(23)
		{
			HX_STACK_LINE(23)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(23)
			int _g2 = this->_menuItems->length;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(23)
			while((true)){
				HX_STACK_LINE(23)
				if ((!(((_g1 < _g2))))){
					HX_STACK_LINE(23)
					break;
				}
				HX_STACK_LINE(23)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(24)
				::com::arm::demo::widgets::menu::MenuItem _g11 = this->_menu->addItem(this->_menuItems->__get(i),i);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(24)
				_menuItem = _g11;
				HX_STACK_LINE(25)
				_menuItem->action->add(this->_menuClick_dyn());
			}
		}
		HX_STACK_LINE(27)
		this->get_container()->addChild(this->_menu);
		HX_STACK_LINE(28)
		this->_menu->set_y(::fluid::display::FluidStage_obj::pixelRatio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MenuView_obj,create,(void))

Void MenuView_obj::hide( ){
{
		HX_STACK_FRAME("com.arm.demo.components.menu.MenuView","hide",0x9151ebc9,"com.arm.demo.components.menu.MenuView.hide","com/arm/demo/components/menu/MenuView.hx",32,0x52c66a18)
		HX_STACK_THIS(this)
		HX_STACK_LINE(32)
		this->_menu->hide();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MenuView_obj,hide,(void))

Void MenuView_obj::_menuClick( int id){
{
		HX_STACK_FRAME("com.arm.demo.components.menu.MenuView","_menuClick",0x9a569831,"com.arm.demo.components.menu.MenuView._menuClick","com/arm/demo/components/menu/MenuView.hx",35,0x52c66a18)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_LINE(36)
		if (((bool((this->_currentItem != id)) && bool((id < (this->_menuItems->length - (int)1)))))){
			HX_STACK_LINE(37)
			::com::arm::demo::notifications::internal::MenuNotification_obj::click->dispatch(id);
		}
		else{
			HX_STACK_LINE(40)
			::com::arm::demo::notifications::internal::MenuNotification_obj::reset->dispatch();
		}
		HX_STACK_LINE(42)
		if (((id != (int)15))){
			HX_STACK_LINE(42)
			this->hide();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MenuView_obj,_menuClick,(void))


MenuView_obj::MenuView_obj()
{
}

void MenuView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MenuView);
	HX_MARK_MEMBER_NAME(_menu,"_menu");
	HX_MARK_MEMBER_NAME(_menuItems,"_menuItems");
	HX_MARK_MEMBER_NAME(_currentItem,"_currentItem");
	::com::arm::demo::view::DemoView_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MenuView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_menu,"_menu");
	HX_VISIT_MEMBER_NAME(_menuItems,"_menuItems");
	HX_VISIT_MEMBER_NAME(_currentItem,"_currentItem");
	::com::arm::demo::view::DemoView_obj::__Visit(HX_VISIT_ARG);
}

Dynamic MenuView_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"hide") ) { return hide_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_menu") ) { return _menu; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_menuItems") ) { return _menuItems; }
		if (HX_FIELD_EQ(inName,"_menuClick") ) { return _menuClick_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_currentItem") ) { return _currentItem; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MenuView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_menu") ) { _menu=inValue.Cast< ::com::arm::demo::widgets::menu::PopoutMenu >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_menuItems") ) { _menuItems=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_currentItem") ) { _currentItem=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MenuView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_menu"));
	outFields->push(HX_CSTRING("_menuItems"));
	outFields->push(HX_CSTRING("_currentItem"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::com::arm::demo::widgets::menu::PopoutMenu*/ ,(int)offsetof(MenuView_obj,_menu),HX_CSTRING("_menu")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(MenuView_obj,_menuItems),HX_CSTRING("_menuItems")},
	{hx::fsInt,(int)offsetof(MenuView_obj,_currentItem),HX_CSTRING("_currentItem")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_menu"),
	HX_CSTRING("_menuItems"),
	HX_CSTRING("_currentItem"),
	HX_CSTRING("create"),
	HX_CSTRING("hide"),
	HX_CSTRING("_menuClick"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MenuView_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MenuView_obj::__mClass,"__mClass");
};

#endif

Class MenuView_obj::__mClass;

void MenuView_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.components.menu.MenuView"), hx::TCanCast< MenuView_obj> ,sStaticFields,sMemberFields,
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

void MenuView_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components
} // end namespace menu
