#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_widgets_menu_Menu
#include <com/arm/demo/widgets/menu/Menu.h>
#endif
#ifndef INCLUDED_com_arm_demo_widgets_menu_MenuItem
#include <com/arm/demo/widgets/menu/MenuItem.h>
#endif
#ifndef INCLUDED_com_arm_demo_widgets_menu_PopoutMenu
#include <com/arm/demo/widgets/menu/PopoutMenu.h>
#endif
#ifndef INCLUDED_fluid_display_FluidGraphics
#include <fluid/display/FluidGraphics.h>
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
#ifndef INCLUDED_fluid_geom_FluidRectangle
#include <fluid/geom/FluidRectangle.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_motion_Actuate
#include <motion/Actuate.h>
#endif
#ifndef INCLUDED_motion_actuators_IGenericActuator
#include <motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_motion_easing_Cubic
#include <motion/easing/Cubic.h>
#endif
#ifndef INCLUDED_motion_easing_IEasing
#include <motion/easing/IEasing.h>
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
#ifndef INCLUDED_openfl__v2_geom_Rectangle
#include <openfl/_v2/geom/Rectangle.h>
#endif
namespace com{
namespace arm{
namespace demo{
namespace widgets{
namespace menu{

Void PopoutMenu_obj::__construct(Float itemWidth,Float itemHeight)
{
HX_STACK_FRAME("com.arm.demo.widgets.menu.PopoutMenu","new",0xfff206f2,"com.arm.demo.widgets.menu.PopoutMenu.new","com/arm/demo/widgets/menu/PopoutMenu.hx",24,0x47376b5d)
HX_STACK_THIS(this)
HX_STACK_ARG(itemWidth,"itemWidth")
HX_STACK_ARG(itemHeight,"itemHeight")
{
	HX_STACK_LINE(25)
	super::__construct(null());
	HX_STACK_LINE(27)
	::fluid::display::FluidSprite _g = ::fluid::display::FluidSprite_obj::__new(null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(27)
	this->_container = _g;
	HX_STACK_LINE(28)
	this->_itemWidth = itemWidth;
	HX_STACK_LINE(29)
	this->_itemHeight = itemHeight;
	HX_STACK_LINE(30)
	this->_state = HX_CSTRING("STATE_HIDE");
	HX_STACK_LINE(32)
	this->_setupOpenButton();
	HX_STACK_LINE(33)
	this->_setupMenu(itemWidth,itemHeight);
	HX_STACK_LINE(35)
	this->addChild(this->_container);
}
;
	return null();
}

//PopoutMenu_obj::~PopoutMenu_obj() { }

Dynamic PopoutMenu_obj::__CreateEmpty() { return  new PopoutMenu_obj; }
hx::ObjectPtr< PopoutMenu_obj > PopoutMenu_obj::__new(Float itemWidth,Float itemHeight)
{  hx::ObjectPtr< PopoutMenu_obj > result = new PopoutMenu_obj();
	result->__construct(itemWidth,itemHeight);
	return result;}

Dynamic PopoutMenu_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PopoutMenu_obj > result = new PopoutMenu_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void PopoutMenu_obj::_setupOpenButton( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.PopoutMenu","_setupOpenButton",0x798e36e8,"com.arm.demo.widgets.menu.PopoutMenu._setupOpenButton","com/arm/demo/widgets/menu/PopoutMenu.hx",38,0x47376b5d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(39)
		::fluid::geom::FluidRectangle buttonRect = ::fluid::geom::FluidRectangle_obj::__new((int)0,(int)0,(int)30,(int)80);		HX_STACK_VAR(buttonRect,"buttonRect");
		HX_STACK_LINE(40)
		::fluid::geom::FluidRectangle hitRect = ::fluid::geom::FluidRectangle_obj::__new((int)0,(int)0,(int)15,(int)60);		HX_STACK_VAR(hitRect,"hitRect");
		HX_STACK_LINE(42)
		::fluid::display::FluidGraphics _g = ::fluid::display::FluidGraphics_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(42)
		this->_openButton = _g;
		HX_STACK_LINE(43)
		this->_openButton->beginFill((int)2187531,null());
		HX_STACK_LINE(44)
		this->_openButton->drawRect(buttonRect->x,buttonRect->y,buttonRect->width,buttonRect->height);
		HX_STACK_LINE(45)
		this->_openButton->endFill();
		HX_STACK_LINE(46)
		this->_openButton->set_interactive(true);
		HX_STACK_LINE(47)
		this->_openButton->touchBegin = this->_toggleShow_dyn();
		HX_STACK_LINE(48)
		this->_openButton->touchEnd = this->_toggleShow_dyn();
		HX_STACK_LINE(49)
		this->_openButton->mouseUp = this->_toggleShow_dyn();
		HX_STACK_LINE(50)
		this->_container->addChild(this->_openButton);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PopoutMenu_obj,_setupOpenButton,(void))

Void PopoutMenu_obj::_setupMenu( Float itemWidth,Float itemHeight){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.PopoutMenu","_setupMenu",0x9183be2b,"com.arm.demo.widgets.menu.PopoutMenu._setupMenu","com/arm/demo/widgets/menu/PopoutMenu.hx",53,0x47376b5d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(itemWidth,"itemWidth")
		HX_STACK_ARG(itemHeight,"itemHeight")
		HX_STACK_LINE(54)
		::com::arm::demo::widgets::menu::Menu _g = ::com::arm::demo::widgets::menu::Menu_obj::__new(itemWidth,itemHeight);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(54)
		this->_menu = _g;
		HX_STACK_LINE(55)
		this->_menu->set_x(-(itemWidth));
		HX_STACK_LINE(56)
		this->_container->addChild(this->_menu);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PopoutMenu_obj,_setupMenu,(void))

Void PopoutMenu_obj::_toggleShow( ::fluid::events::EventData data){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.PopoutMenu","_toggleShow",0xbe050062,"com.arm.demo.widgets.menu.PopoutMenu._toggleShow","com/arm/demo/widgets/menu/PopoutMenu.hx",60,0x47376b5d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(60)
		if (((this->_state == HX_CSTRING("STATE_SHOW")))){
			HX_STACK_LINE(60)
			this->hide();
		}
		else{
			HX_STACK_LINE(61)
			this->show();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PopoutMenu_obj,_toggleShow,(void))

Void PopoutMenu_obj::show( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.PopoutMenu","show",0xf7245e2b,"com.arm.demo.widgets.menu.PopoutMenu.show","com/arm/demo/widgets/menu/PopoutMenu.hx",64,0x47376b5d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(65)
		this->_state = HX_CSTRING("STATE_SHOW");
		HX_STACK_LINE(66)
		::motion::easing::IEasing _g = ::motion::easing::Cubic_obj::get_easeInOut();		HX_STACK_VAR(_g,"_g");
		struct _Function_1_1{
			inline static Dynamic Block( hx::ObjectPtr< ::com::arm::demo::widgets::menu::PopoutMenu_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","com/arm/demo/widgets/menu/PopoutMenu.hx",66,0x47376b5d)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , __this->_itemWidth,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(66)
		::motion::Actuate_obj::tween(this->_container,0.3,_Function_1_1::Block(this),null(),null())->ease(_g)->onComplete(this->_enableMenuItems_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PopoutMenu_obj,show,(void))

Void PopoutMenu_obj::hide( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.PopoutMenu","hide",0xefdfbdf0,"com.arm.demo.widgets.menu.PopoutMenu.hide","com/arm/demo/widgets/menu/PopoutMenu.hx",69,0x47376b5d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(70)
		this->_state = HX_CSTRING("STATE_HIDE");
		HX_STACK_LINE(71)
		::motion::easing::IEasing _g = ::motion::easing::Cubic_obj::get_easeInOut();		HX_STACK_VAR(_g,"_g");
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","com/arm/demo/widgets/menu/PopoutMenu.hx",71,0x47376b5d)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , (int)0,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(71)
		::motion::Actuate_obj::tween(this->_container,0.3,_Function_1_1::Block(),null(),null())->ease(_g)->onComplete(this->_disableMenuItems_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PopoutMenu_obj,hide,(void))

::com::arm::demo::widgets::menu::MenuItem PopoutMenu_obj::addItem( ::String label,Dynamic data){
	HX_STACK_FRAME("com.arm.demo.widgets.menu.PopoutMenu","addItem",0x5c6eef66,"com.arm.demo.widgets.menu.PopoutMenu.addItem","com/arm/demo/widgets/menu/PopoutMenu.hx",74,0x47376b5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(label,"label")
	HX_STACK_ARG(data,"data")
	HX_STACK_LINE(75)
	::com::arm::demo::widgets::menu::MenuItem menuItem = this->_menu->addItem(label,data);		HX_STACK_VAR(menuItem,"menuItem");
	HX_STACK_LINE(76)
	this->_updateOpenButtonPosition();
	HX_STACK_LINE(77)
	return menuItem;
}


HX_DEFINE_DYNAMIC_FUNC2(PopoutMenu_obj,addItem,return )

Void PopoutMenu_obj::_enableMenuItems( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.PopoutMenu","_enableMenuItems",0xd7d6b78d,"com.arm.demo.widgets.menu.PopoutMenu._enableMenuItems","com/arm/demo/widgets/menu/PopoutMenu.hx",81,0x47376b5d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(81)
		this->_menu->enableMenuItems();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PopoutMenu_obj,_enableMenuItems,(void))

Void PopoutMenu_obj::_disableMenuItems( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.PopoutMenu","_disableMenuItems",0xacd3cf4a,"com.arm.demo.widgets.menu.PopoutMenu._disableMenuItems","com/arm/demo/widgets/menu/PopoutMenu.hx",85,0x47376b5d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(85)
		this->_menu->disableMenuItems();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PopoutMenu_obj,_disableMenuItems,(void))

Void PopoutMenu_obj::_updateOpenButtonPosition( ){
{
		HX_STACK_FRAME("com.arm.demo.widgets.menu.PopoutMenu","_updateOpenButtonPosition",0x80f2dfff,"com.arm.demo.widgets.menu.PopoutMenu._updateOpenButtonPosition","com/arm/demo/widgets/menu/PopoutMenu.hx",88,0x47376b5d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(89)
		int _g = ::Math_obj::floor((Float(((this->_menu->getItems()->length - (int)1))) / Float((int)2)));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(89)
		Float openButtonPosition = (_g * this->_itemHeight);		HX_STACK_VAR(openButtonPosition,"openButtonPosition");
		HX_STACK_LINE(91)
		if (((openButtonPosition > (Float(::fluid::display::FluidStage_obj::screenHeight) / Float((int)2))))){
			HX_STACK_LINE(92)
			openButtonPosition = (Float(::fluid::display::FluidStage_obj::screenHeight) / Float((int)2));
		}
		HX_STACK_LINE(94)
		this->_openButton->set_y(openButtonPosition);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PopoutMenu_obj,_updateOpenButtonPosition,(void))

::String PopoutMenu_obj::STATE_SHOW;

::String PopoutMenu_obj::STATE_HIDE;


PopoutMenu_obj::PopoutMenu_obj()
{
}

void PopoutMenu_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PopoutMenu);
	HX_MARK_MEMBER_NAME(_container,"_container");
	HX_MARK_MEMBER_NAME(_itemWidth,"_itemWidth");
	HX_MARK_MEMBER_NAME(_itemHeight,"_itemHeight");
	HX_MARK_MEMBER_NAME(_state,"_state");
	HX_MARK_MEMBER_NAME(_menu,"_menu");
	HX_MARK_MEMBER_NAME(_openButton,"_openButton");
	::fluid::display::FluidSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PopoutMenu_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_container,"_container");
	HX_VISIT_MEMBER_NAME(_itemWidth,"_itemWidth");
	HX_VISIT_MEMBER_NAME(_itemHeight,"_itemHeight");
	HX_VISIT_MEMBER_NAME(_state,"_state");
	HX_VISIT_MEMBER_NAME(_menu,"_menu");
	HX_VISIT_MEMBER_NAME(_openButton,"_openButton");
	::fluid::display::FluidSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PopoutMenu_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"show") ) { return show_dyn(); }
		if (HX_FIELD_EQ(inName,"hide") ) { return hide_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_menu") ) { return _menu; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_state") ) { return _state; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addItem") ) { return addItem_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_container") ) { return _container; }
		if (HX_FIELD_EQ(inName,"_itemWidth") ) { return _itemWidth; }
		if (HX_FIELD_EQ(inName,"_setupMenu") ) { return _setupMenu_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_itemHeight") ) { return _itemHeight; }
		if (HX_FIELD_EQ(inName,"_openButton") ) { return _openButton; }
		if (HX_FIELD_EQ(inName,"_toggleShow") ) { return _toggleShow_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_setupOpenButton") ) { return _setupOpenButton_dyn(); }
		if (HX_FIELD_EQ(inName,"_enableMenuItems") ) { return _enableMenuItems_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_disableMenuItems") ) { return _disableMenuItems_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_updateOpenButtonPosition") ) { return _updateOpenButtonPosition_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PopoutMenu_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_menu") ) { _menu=inValue.Cast< ::com::arm::demo::widgets::menu::Menu >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_state") ) { _state=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_container") ) { _container=inValue.Cast< ::fluid::display::FluidSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_itemWidth") ) { _itemWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_itemHeight") ) { _itemHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_openButton") ) { _openButton=inValue.Cast< ::fluid::display::FluidGraphics >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PopoutMenu_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_container"));
	outFields->push(HX_CSTRING("_itemWidth"));
	outFields->push(HX_CSTRING("_itemHeight"));
	outFields->push(HX_CSTRING("_state"));
	outFields->push(HX_CSTRING("_menu"));
	outFields->push(HX_CSTRING("_openButton"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("STATE_SHOW"),
	HX_CSTRING("STATE_HIDE"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::fluid::display::FluidSprite*/ ,(int)offsetof(PopoutMenu_obj,_container),HX_CSTRING("_container")},
	{hx::fsFloat,(int)offsetof(PopoutMenu_obj,_itemWidth),HX_CSTRING("_itemWidth")},
	{hx::fsFloat,(int)offsetof(PopoutMenu_obj,_itemHeight),HX_CSTRING("_itemHeight")},
	{hx::fsString,(int)offsetof(PopoutMenu_obj,_state),HX_CSTRING("_state")},
	{hx::fsObject /*::com::arm::demo::widgets::menu::Menu*/ ,(int)offsetof(PopoutMenu_obj,_menu),HX_CSTRING("_menu")},
	{hx::fsObject /*::fluid::display::FluidGraphics*/ ,(int)offsetof(PopoutMenu_obj,_openButton),HX_CSTRING("_openButton")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_container"),
	HX_CSTRING("_itemWidth"),
	HX_CSTRING("_itemHeight"),
	HX_CSTRING("_state"),
	HX_CSTRING("_menu"),
	HX_CSTRING("_openButton"),
	HX_CSTRING("_setupOpenButton"),
	HX_CSTRING("_setupMenu"),
	HX_CSTRING("_toggleShow"),
	HX_CSTRING("show"),
	HX_CSTRING("hide"),
	HX_CSTRING("addItem"),
	HX_CSTRING("_enableMenuItems"),
	HX_CSTRING("_disableMenuItems"),
	HX_CSTRING("_updateOpenButtonPosition"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PopoutMenu_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(PopoutMenu_obj::STATE_SHOW,"STATE_SHOW");
	HX_MARK_MEMBER_NAME(PopoutMenu_obj::STATE_HIDE,"STATE_HIDE");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PopoutMenu_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PopoutMenu_obj::STATE_SHOW,"STATE_SHOW");
	HX_VISIT_MEMBER_NAME(PopoutMenu_obj::STATE_HIDE,"STATE_HIDE");
};

#endif

Class PopoutMenu_obj::__mClass;

void PopoutMenu_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.widgets.menu.PopoutMenu"), hx::TCanCast< PopoutMenu_obj> ,sStaticFields,sMemberFields,
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

void PopoutMenu_obj::__boot()
{
	STATE_SHOW= HX_CSTRING("STATE_SHOW");
	STATE_HIDE= HX_CSTRING("STATE_HIDE");
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace widgets
} // end namespace menu
