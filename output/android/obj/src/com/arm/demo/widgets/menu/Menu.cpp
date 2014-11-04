#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_widgets_menu_Menu
#include <com/arm/demo/widgets/menu/Menu.h>
#endif
#ifndef INCLUDED_com_arm_demo_widgets_menu_MenuItem
#include <com/arm/demo/widgets/menu/MenuItem.h>
#endif
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
#endif
#ifndef INCLUDED_fluid_display_FluidStage
#include <fluid/display/FluidStage.h>
#endif
#ifndef INCLUDED_fluid_events_EventData
#include <fluid/events/EventData.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BitmapData
#include <openfl/_v2/display/BitmapData.h>
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
namespace widgets{
namespace menu{

Void Menu_obj::__construct(Float itemWidth,Float itemHeight)
{
HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","new",0xe3d81f35,"com.arm.demo.widgets.menu.Menu.new","com/arm/demo/widgets/menu/Menu.hx",17,0xeb837b3a)
HX_STACK_THIS(this)
HX_STACK_ARG(itemWidth,"itemWidth")
HX_STACK_ARG(itemHeight,"itemHeight")
{
	HX_STACK_LINE(18)
	super::__construct(null());
	HX_STACK_LINE(20)
	this->_itemWidth = itemWidth;
	HX_STACK_LINE(21)
	this->_itemHeight = itemHeight;
	HX_STACK_LINE(22)
	this->_menuItems = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(23)
	this->set_interactive(true);
}
;
	return null();
}

//Menu_obj::~Menu_obj() { }

Dynamic Menu_obj::__CreateEmpty() { return  new Menu_obj; }
hx::ObjectPtr< Menu_obj > Menu_obj::__new(Float itemWidth,Float itemHeight)
{  hx::ObjectPtr< Menu_obj > result = new Menu_obj();
	result->__construct(itemWidth,itemHeight);
	return result;}

Dynamic Menu_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Menu_obj > result = new Menu_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::com::arm::demo::widgets::menu::MenuItem Menu_obj::addItem( ::String label,Dynamic data){
	HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","addItem",0x5d19e529,"com.arm.demo.widgets.menu.Menu.addItem","com/arm/demo/widgets/menu/Menu.hx",26,0xeb837b3a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(label,"label")
	HX_STACK_ARG(data,"data")
	HX_STACK_LINE(27)
	::com::arm::demo::widgets::menu::MenuItem menuItem = ::com::arm::demo::widgets::menu::MenuItem_obj::__new(label,this->_itemWidth,this->_itemHeight,data);		HX_STACK_VAR(menuItem,"menuItem");
	HX_STACK_LINE(28)
	menuItem->set_y((this->_itemHeight * this->_menuItems->length));
	HX_STACK_LINE(29)
	this->addChild(menuItem);
	HX_STACK_LINE(30)
	this->_menuItems->push(menuItem);
	HX_STACK_LINE(31)
	this->_height = (this->_itemHeight * this->_menuItems->length);
	HX_STACK_LINE(33)
	if (((this->_height > ::fluid::display::FluidStage_obj::screenHeight))){
		HX_STACK_LINE(34)
		this->touchBegin = this->_onTouchStart_dyn();
		HX_STACK_LINE(35)
		this->touchEnd = this->_onTouchEnd_dyn();
		HX_STACK_LINE(36)
		this->mouseDown = this->_onMouseDown_dyn();
		HX_STACK_LINE(37)
		this->mouseUp = this->_onMouseUp_dyn();
	}
	HX_STACK_LINE(39)
	return menuItem;
}


HX_DEFINE_DYNAMIC_FUNC2(Menu_obj,addItem,return )

Void Menu_obj::_onTouchStart( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","_onTouchStart",0x268f9816,"com.arm.demo.widgets.menu.Menu._onTouchStart","com/arm/demo/widgets/menu/Menu.hx",42,0xeb837b3a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(43)
		this->_lastPosition = data->stageY;
		HX_STACK_LINE(44)
		this->touchMove = this->_onTouchMove_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Menu_obj,_onTouchStart,(void))

Void Menu_obj::_onTouchMove( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","_onTouchMove",0xd091b1dd,"com.arm.demo.widgets.menu.Menu._onTouchMove","com/arm/demo/widgets/menu/Menu.hx",47,0xeb837b3a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(48)
		Float distance = (this->_lastPosition - data->stageY);		HX_STACK_VAR(distance,"distance");
		HX_STACK_LINE(49)
		if (((bool(this->_dragging) || bool(((bool((distance < (int)-5)) || bool((distance > (int)5)))))))){
			HX_STACK_LINE(50)
			this->disableMenuItems();
			HX_STACK_LINE(51)
			this->_move((this->_lastPosition - data->stageY));
			HX_STACK_LINE(52)
			this->_dragging = true;
			HX_STACK_LINE(53)
			this->_lastPosition = data->stageY;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Menu_obj,_onTouchMove,(void))

Void Menu_obj::_onTouchEnd( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","_onTouchEnd",0xc8a9128f,"com.arm.demo.widgets.menu.Menu._onTouchEnd","com/arm/demo/widgets/menu/Menu.hx",57,0xeb837b3a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(58)
		this->touchMove = null();
		HX_STACK_LINE(59)
		this->_dragging = false;
		HX_STACK_LINE(60)
		::haxe::Timer_obj::delay(this->enableMenuItems_dyn(),(int)100);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Menu_obj,_onTouchEnd,(void))

Void Menu_obj::_onMouseDown( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","_onMouseDown",0xb186f094,"com.arm.demo.widgets.menu.Menu._onMouseDown","com/arm/demo/widgets/menu/Menu.hx",63,0xeb837b3a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(64)
		this->_lastPosition = data->stageY;
		HX_STACK_LINE(65)
		this->mouseMove = this->_onMouseMove_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Menu_obj,_onMouseDown,(void))

Void Menu_obj::_onMouseUp( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","_onMouseUp",0x3e7a8e0d,"com.arm.demo.widgets.menu.Menu._onMouseUp","com/arm/demo/widgets/menu/Menu.hx",68,0xeb837b3a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(69)
		this->mouseMove = null();
		HX_STACK_LINE(70)
		this->_dragging = false;
		HX_STACK_LINE(71)
		this->enableMenuItems();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Menu_obj,_onMouseUp,(void))

Void Menu_obj::_onMouseMove( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","_onMouseMove",0xb779db43,"com.arm.demo.widgets.menu.Menu._onMouseMove","com/arm/demo/widgets/menu/Menu.hx",74,0xeb837b3a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(75)
		Float distance = (this->_lastPosition - data->stageY);		HX_STACK_VAR(distance,"distance");
		HX_STACK_LINE(77)
		if (((bool(this->_dragging) || bool(((bool((distance < (int)-5)) || bool((distance > (int)5)))))))){
			HX_STACK_LINE(78)
			this->disableMenuItems();
			HX_STACK_LINE(79)
			this->_move((this->_lastPosition - data->stageY));
			HX_STACK_LINE(80)
			this->_dragging = true;
			HX_STACK_LINE(81)
			this->_lastPosition = data->stageY;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Menu_obj,_onMouseMove,(void))

Void Menu_obj::disableMenuItems( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","disableMenuItems",0x34a05ee4,"com.arm.demo.widgets.menu.Menu.disableMenuItems","com/arm/demo/widgets/menu/Menu.hx",86,0xeb837b3a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(86)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(86)
		int _g = this->_menuItems->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(86)
		while((true)){
			HX_STACK_LINE(86)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(86)
				break;
			}
			HX_STACK_LINE(86)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(87)
			this->_menuItems->__get(i).StaticCast< ::com::arm::demo::widgets::menu::MenuItem >()->disable();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Menu_obj,disableMenuItems,(void))

Void Menu_obj::enableMenuItems( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","enableMenuItems",0x09cf9933,"com.arm.demo.widgets.menu.Menu.enableMenuItems","com/arm/demo/widgets/menu/Menu.hx",92,0xeb837b3a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(92)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(92)
		int _g = this->_menuItems->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(92)
		while((true)){
			HX_STACK_LINE(92)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(92)
				break;
			}
			HX_STACK_LINE(92)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(93)
			this->_menuItems->__get(i).StaticCast< ::com::arm::demo::widgets::menu::MenuItem >()->enable();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Menu_obj,enableMenuItems,(void))

Void Menu_obj::_move( Float distance){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","_move",0x03c76d05,"com.arm.demo.widgets.menu.Menu._move","com/arm/demo/widgets/menu/Menu.hx",97,0xeb837b3a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(distance,"distance")
		HX_STACK_LINE(98)
		{
			HX_STACK_LINE(98)
			::com::arm::demo::widgets::menu::Menu _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(98)
			Float _g1 = _g->get_y();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(98)
			Float _g11 = (_g1 - distance);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(98)
			_g->set_y(_g11);
		}
		HX_STACK_LINE(99)
		Float _g2 = this->get_y();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(99)
		if (((_g2 > (int)0))){
			HX_STACK_LINE(99)
			this->set_y((int)0);
		}
		else{
			HX_STACK_LINE(100)
			Float _g3 = this->get_y();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(100)
			if (((_g3 < -(((this->_height - ::fluid::display::FluidStage_obj::screenHeight)))))){
				HX_STACK_LINE(101)
				this->set_y(-(((this->_height - ::fluid::display::FluidStage_obj::screenHeight))));
			}
		}
		HX_STACK_LINE(104)
		Float _g4 = this->get_x();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(104)
		int _g5 = ::Math_obj::round(_g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(104)
		this->set_x(_g5);
		HX_STACK_LINE(105)
		Float _g6 = this->get_y();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(105)
		int _g7 = ::Math_obj::round(_g6);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(105)
		this->set_y(_g7);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Menu_obj,_move,(void))

Array< ::Dynamic > Menu_obj::getItems( ){
	HX_STACK_FRAME("com.arm.demo.widgets.menu.Menu","getItems",0x00088895,"com.arm.demo.widgets.menu.Menu.getItems","com/arm/demo/widgets/menu/Menu.hx",109,0xeb837b3a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(109)
	return this->_menuItems;
}


HX_DEFINE_DYNAMIC_FUNC0(Menu_obj,getItems,return )


Menu_obj::Menu_obj()
{
}

void Menu_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Menu);
	HX_MARK_MEMBER_NAME(_itemWidth,"_itemWidth");
	HX_MARK_MEMBER_NAME(_itemHeight,"_itemHeight");
	HX_MARK_MEMBER_NAME(_menuItems,"_menuItems");
	HX_MARK_MEMBER_NAME(_lastPosition,"_lastPosition");
	HX_MARK_MEMBER_NAME(_dragging,"_dragging");
	HX_MARK_MEMBER_NAME(_height,"_height");
	::fluid::display::FluidSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Menu_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_itemWidth,"_itemWidth");
	HX_VISIT_MEMBER_NAME(_itemHeight,"_itemHeight");
	HX_VISIT_MEMBER_NAME(_menuItems,"_menuItems");
	HX_VISIT_MEMBER_NAME(_lastPosition,"_lastPosition");
	HX_VISIT_MEMBER_NAME(_dragging,"_dragging");
	HX_VISIT_MEMBER_NAME(_height,"_height");
	::fluid::display::FluidSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Menu_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_move") ) { return _move_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_height") ) { return _height; }
		if (HX_FIELD_EQ(inName,"addItem") ) { return addItem_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getItems") ) { return getItems_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_dragging") ) { return _dragging; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_itemWidth") ) { return _itemWidth; }
		if (HX_FIELD_EQ(inName,"_menuItems") ) { return _menuItems; }
		if (HX_FIELD_EQ(inName,"_onMouseUp") ) { return _onMouseUp_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_itemHeight") ) { return _itemHeight; }
		if (HX_FIELD_EQ(inName,"_onTouchEnd") ) { return _onTouchEnd_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_onTouchMove") ) { return _onTouchMove_dyn(); }
		if (HX_FIELD_EQ(inName,"_onMouseDown") ) { return _onMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"_onMouseMove") ) { return _onMouseMove_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_lastPosition") ) { return _lastPosition; }
		if (HX_FIELD_EQ(inName,"_onTouchStart") ) { return _onTouchStart_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"enableMenuItems") ) { return enableMenuItems_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"disableMenuItems") ) { return disableMenuItems_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Menu_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"_height") ) { _height=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_dragging") ) { _dragging=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_itemWidth") ) { _itemWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_menuItems") ) { _menuItems=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_itemHeight") ) { _itemHeight=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_lastPosition") ) { _lastPosition=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Menu_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_itemWidth"));
	outFields->push(HX_CSTRING("_itemHeight"));
	outFields->push(HX_CSTRING("_menuItems"));
	outFields->push(HX_CSTRING("_lastPosition"));
	outFields->push(HX_CSTRING("_dragging"));
	outFields->push(HX_CSTRING("_height"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Menu_obj,_itemWidth),HX_CSTRING("_itemWidth")},
	{hx::fsFloat,(int)offsetof(Menu_obj,_itemHeight),HX_CSTRING("_itemHeight")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Menu_obj,_menuItems),HX_CSTRING("_menuItems")},
	{hx::fsFloat,(int)offsetof(Menu_obj,_lastPosition),HX_CSTRING("_lastPosition")},
	{hx::fsBool,(int)offsetof(Menu_obj,_dragging),HX_CSTRING("_dragging")},
	{hx::fsFloat,(int)offsetof(Menu_obj,_height),HX_CSTRING("_height")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_itemWidth"),
	HX_CSTRING("_itemHeight"),
	HX_CSTRING("_menuItems"),
	HX_CSTRING("_lastPosition"),
	HX_CSTRING("_dragging"),
	HX_CSTRING("_height"),
	HX_CSTRING("addItem"),
	HX_CSTRING("_onTouchStart"),
	HX_CSTRING("_onTouchMove"),
	HX_CSTRING("_onTouchEnd"),
	HX_CSTRING("_onMouseDown"),
	HX_CSTRING("_onMouseUp"),
	HX_CSTRING("_onMouseMove"),
	HX_CSTRING("disableMenuItems"),
	HX_CSTRING("enableMenuItems"),
	HX_CSTRING("_move"),
	HX_CSTRING("getItems"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Menu_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Menu_obj::__mClass,"__mClass");
};

#endif

Class Menu_obj::__mClass;

void Menu_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.widgets.menu.Menu"), hx::TCanCast< Menu_obj> ,sStaticFields,sMemberFields,
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

void Menu_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace widgets
} // end namespace menu
