#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_arm_demo_components_GameComponentView
#include <com/arm/demo/components/GameComponentView.h>
#endif
#ifndef INCLUDED_com_arm_demo_components_bunnymark_Bunny
#include <com/arm/demo/components/bunnymark/Bunny.h>
#endif
#ifndef INCLUDED_com_arm_demo_components_bunnymark_BunnymarkView
#include <com/arm/demo/components/bunnymark/BunnymarkView.h>
#endif
#ifndef INCLUDED_com_arm_demo_view_DemoView
#include <com/arm/demo/view/DemoView.h>
#endif
#ifndef INCLUDED_com_arm_demo_widgets_Button
#include <com/arm/demo/widgets/Button.h>
#endif
#ifndef INCLUDED_com_arm_demo_widgets_Label
#include <com/arm/demo/widgets/Label.h>
#endif
#ifndef INCLUDED_fluid_FluidAssets
#include <fluid/FluidAssets.h>
#endif
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
#endif
#ifndef INCLUDED_fluid_display_FluidStage
#include <fluid/display/FluidStage.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_msignal_Signal
#include <msignal/Signal.h>
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
namespace components{
namespace bunnymark{

Void BunnymarkView_obj::__construct(::fluid::display::FluidSprite container)
{
HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkView","new",0x5c799da3,"com.arm.demo.components.bunnymark.BunnymarkView.new","com/arm/demo/components/bunnymark/BunnymarkView.hx",28,0xc54841d0)
HX_STACK_THIS(this)
HX_STACK_ARG(container,"container")
{
	HX_STACK_LINE(29)
	super::__construct(container);
	HX_STACK_LINE(30)
	Float _g = this->_minY = (int)0;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(30)
	this->_minX = _g;
	HX_STACK_LINE(31)
	this->_maxX = ::fluid::display::FluidStage_obj::screenWidth;
	HX_STACK_LINE(32)
	this->_maxY = ::fluid::display::FluidStage_obj::screenHeight;
}
;
	return null();
}

//BunnymarkView_obj::~BunnymarkView_obj() { }

Dynamic BunnymarkView_obj::__CreateEmpty() { return  new BunnymarkView_obj; }
hx::ObjectPtr< BunnymarkView_obj > BunnymarkView_obj::__new(::fluid::display::FluidSprite container)
{  hx::ObjectPtr< BunnymarkView_obj > result = new BunnymarkView_obj();
	result->__construct(container);
	return result;}

Dynamic BunnymarkView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BunnymarkView_obj > result = new BunnymarkView_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BunnymarkView_obj::show( ){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkView","show",0x9140a25a,"com.arm.demo.components.bunnymark.BunnymarkView.show","com/arm/demo/components/bunnymark/BunnymarkView.hx",35,0xc54841d0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(36)
		::openfl::_v2::display::BitmapData _g = ::fluid::FluidAssets_obj::getImage(HX_CSTRING("assets/bunny.png"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(36)
		this->_bunnyTexture = _g;
		HX_STACK_LINE(37)
		this->_sprites = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(38)
		this->_buttons = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(40)
		::fluid::display::FluidSprite _g1 = ::fluid::display::FluidSprite_obj::__new(null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(40)
		this->_spriteContainer = _g1;
		HX_STACK_LINE(41)
		::fluid::display::FluidSprite _g2 = ::fluid::display::FluidSprite_obj::__new(null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(41)
		this->_uiContainer = _g2;
		HX_STACK_LINE(43)
		this->_addButton(HX_CSTRING("Reset"),(int)0,(int)0,(int)100,(int)30,this->_reset_dyn(),null());
		HX_STACK_LINE(44)
		this->_addButton(HX_CSTRING("Scale"),(int)100,(int)0,(int)100,(int)30,this->_scale_dyn(),null());
		HX_STACK_LINE(45)
		this->_addButton(HX_CSTRING("Rotation"),(int)200,(int)0,(int)100,(int)30,this->_rotation_dyn(),null());
		HX_STACK_LINE(46)
		this->_addButton(HX_CSTRING("Add 10"),(int)0,(int)30,(int)100,(int)30,this->_addBunnys_dyn(),(int)10);
		HX_STACK_LINE(47)
		this->_addButton(HX_CSTRING("Add 100"),(int)100,(int)30,(int)100,(int)30,this->_addBunnys_dyn(),(int)100);
		HX_STACK_LINE(48)
		this->_addButton(HX_CSTRING("Add 500"),(int)200,(int)30,(int)100,(int)30,this->_addBunnys_dyn(),(int)500);
		HX_STACK_LINE(49)
		this->_addButton(HX_CSTRING("Add 1000"),(int)0,(int)60,(int)100,(int)30,this->_addBunnys_dyn(),(int)1000);
		HX_STACK_LINE(50)
		this->_addButton(HX_CSTRING("Add 5000"),(int)100,(int)60,(int)100,(int)30,this->_addBunnys_dyn(),(int)5000);
		HX_STACK_LINE(51)
		this->_addButton(HX_CSTRING("Add 10000"),(int)200,(int)60,(int)100,(int)30,this->_addBunnys_dyn(),(int)10000);
		HX_STACK_LINE(53)
		::com::arm::demo::widgets::Label _g3 = ::com::arm::demo::widgets::Label_obj::__new(HX_CSTRING(""),(int)300,(int)24,null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(53)
		this->_quantityLabel = _g3;
		HX_STACK_LINE(54)
		this->_quantityLabel->set_y((int)90);
		HX_STACK_LINE(55)
		this->_uiContainer->addChild(this->_quantityLabel);
		HX_STACK_LINE(56)
		this->_uiContainer->set_x((Float(((::fluid::display::FluidStage_obj::screenWidth - (int)300))) / Float((int)2)));
		HX_STACK_LINE(57)
		this->_uiContainer->set_y((int)20);
		HX_STACK_LINE(59)
		this->_updateQuanityLabel();
		HX_STACK_LINE(60)
		this->get_container()->addChild(this->_spriteContainer);
		HX_STACK_LINE(61)
		this->get_container()->addChild(this->_uiContainer);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BunnymarkView_obj,show,(void))

Void BunnymarkView_obj::_addButton( ::String label,Float x,Float y,Float width,Float height,Dynamic callback,Dynamic data){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkView","_addButton",0xedb8c3d1,"com.arm.demo.components.bunnymark.BunnymarkView._addButton","com/arm/demo/components/bunnymark/BunnymarkView.hx",64,0xc54841d0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(label,"label")
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(width,"width")
		HX_STACK_ARG(height,"height")
		HX_STACK_ARG(callback,"callback")
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(65)
		::com::arm::demo::widgets::Button button = ::com::arm::demo::widgets::Button_obj::__new(label,width,height,data,null());		HX_STACK_VAR(button,"button");
		HX_STACK_LINE(66)
		button->set_x(x);
		HX_STACK_LINE(67)
		button->set_y(y);
		HX_STACK_LINE(68)
		button->action->add(callback);
		HX_STACK_LINE(69)
		button->enable();
		HX_STACK_LINE(70)
		this->_buttons->push(button);
		HX_STACK_LINE(71)
		this->_uiContainer->addChild(button);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(BunnymarkView_obj,_addButton,(void))

Void BunnymarkView_obj::_updateQuanityLabel( ){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkView","_updateQuanityLabel",0xaf9639c2,"com.arm.demo.components.bunnymark.BunnymarkView._updateQuanityLabel","com/arm/demo/components/bunnymark/BunnymarkView.hx",75,0xc54841d0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(75)
		this->_quantityLabel->setText((HX_CSTRING("Quantity: ") + this->_sprites->length));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BunnymarkView_obj,_updateQuanityLabel,(void))

Void BunnymarkView_obj::_reset( ){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkView","_reset",0x98b12fad,"com.arm.demo.components.bunnymark.BunnymarkView._reset","com/arm/demo/components/bunnymark/BunnymarkView.hx",78,0xc54841d0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(79)
		{
			HX_STACK_LINE(79)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(79)
			int _g = this->_sprites->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(79)
			while((true)){
				HX_STACK_LINE(79)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(79)
					break;
				}
				HX_STACK_LINE(79)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(80)
				this->_spriteContainer->removeChild(this->_sprites->__get(i).StaticCast< ::com::arm::demo::components::bunnymark::Bunny >());
			}
		}
		HX_STACK_LINE(83)
		this->_sprites = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(84)
		this->_isScale = false;
		HX_STACK_LINE(85)
		this->_isRotation = false;
		HX_STACK_LINE(86)
		this->_updateQuanityLabel();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BunnymarkView_obj,_reset,(void))

Void BunnymarkView_obj::_scale( ){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkView","_scale",0x2ab7b468,"com.arm.demo.components.bunnymark.BunnymarkView._scale","com/arm/demo/components/bunnymark/BunnymarkView.hx",90,0xc54841d0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(90)
		this->_isScale = !(this->_isScale);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BunnymarkView_obj,_scale,(void))

Void BunnymarkView_obj::_rotation( ){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkView","_rotation",0x6837d620,"com.arm.demo.components.bunnymark.BunnymarkView._rotation","com/arm/demo/components/bunnymark/BunnymarkView.hx",94,0xc54841d0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(94)
		this->_isRotation = !(this->_isRotation);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BunnymarkView_obj,_rotation,(void))

Void BunnymarkView_obj::_addBunnys( int count){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkView","_addBunnys",0xe9bcf74c,"com.arm.demo.components.bunnymark.BunnymarkView._addBunnys","com/arm/demo/components/bunnymark/BunnymarkView.hx",97,0xc54841d0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(count,"count")
		HX_STACK_LINE(98)
		{
			HX_STACK_LINE(98)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(98)
			while((true)){
				HX_STACK_LINE(98)
				if ((!(((_g < count))))){
					HX_STACK_LINE(98)
					break;
				}
				HX_STACK_LINE(98)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(99)
				::com::arm::demo::components::bunnymark::Bunny bunny = ::com::arm::demo::components::bunnymark::Bunny_obj::__new(this->_bunnyTexture);		HX_STACK_VAR(bunny,"bunny");
				HX_STACK_LINE(100)
				this->_spriteContainer->addChild(bunny);
				HX_STACK_LINE(101)
				int _g1 = ::Std_obj::_int(::fluid::display::FluidStage_obj::screenWidth);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(101)
				int _g11 = ::Std_obj::random(_g1);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(101)
				bunny->set_x(_g11);
				HX_STACK_LINE(102)
				int _g2 = ::Std_obj::_int(::fluid::display::FluidStage_obj::screenHeight);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(102)
				int _g3 = ::Std_obj::random(_g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(102)
				bunny->set_y(_g3);
				HX_STACK_LINE(105)
				Float _g4 = ::Math_obj::random();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(105)
				Float _g5 = (_g4 * (int)16);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(105)
				Float _g6 = (_g5 + (int)2);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(105)
				bunny->speedX = _g6;
				HX_STACK_LINE(106)
				Float _g7 = ::Math_obj::random();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(106)
				Float _g8 = (_g7 * (int)16);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(106)
				Float _g9 = (_g8 - (int)10);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(106)
				bunny->speedY = _g9;
				HX_STACK_LINE(107)
				Float _g10 = ::Math_obj::random();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(107)
				Float _g111 = (Float(_g10) / Float((int)50));		HX_STACK_VAR(_g111,"_g111");
				HX_STACK_LINE(107)
				Float _g12 = (_g111 + 0.01);		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(107)
				bunny->rotationSpeed = _g12;
				HX_STACK_LINE(108)
				Float _g13 = ::Math_obj::random();		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(108)
				Float _g14 = (Float(_g13) / Float((int)50));		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(108)
				Float _g15 = (_g14 + 0.01);		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(108)
				bunny->scaleSpeed = _g15;
				HX_STACK_LINE(109)
				this->_sprites->push(bunny);
				HX_STACK_LINE(110)
				this->_applyScale(bunny);
			}
		}
		HX_STACK_LINE(112)
		this->_updateQuanityLabel();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BunnymarkView_obj,_addBunnys,(void))

Void BunnymarkView_obj::update( Float elapsedTime){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkView","update",0x3d0724a6,"com.arm.demo.components.bunnymark.BunnymarkView.update","com/arm/demo/components/bunnymark/BunnymarkView.hx",116,0xc54841d0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(elapsedTime,"elapsedTime")
		HX_STACK_LINE(116)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(116)
		int _g = this->_sprites->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(116)
		while((true)){
			HX_STACK_LINE(116)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(116)
				break;
			}
			HX_STACK_LINE(116)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(117)
			::com::arm::demo::components::bunnymark::Bunny bunny = this->_sprites->__get(i).StaticCast< ::com::arm::demo::components::bunnymark::Bunny >();		HX_STACK_VAR(bunny,"bunny");
			HX_STACK_LINE(118)
			{
				HX_STACK_LINE(118)
				::com::arm::demo::components::bunnymark::Bunny _g2 = bunny;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(118)
				Float _g3 = _g2->get_x();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(118)
				Float _g11 = (_g3 + bunny->speedX);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(118)
				_g2->set_x(_g11);
			}
			HX_STACK_LINE(119)
			{
				HX_STACK_LINE(119)
				::com::arm::demo::components::bunnymark::Bunny _g2 = bunny;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(119)
				Float _g21 = _g2->get_y();		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(119)
				Float _g3 = (_g21 + bunny->speedY);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(119)
				_g2->set_y(_g3);
			}
			HX_STACK_LINE(120)
			hx::AddEq(bunny->speedY,4.75);
			HX_STACK_LINE(122)
			Float _g4 = bunny->get_x();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(122)
			if (((_g4 > this->_maxX))){
				HX_STACK_LINE(123)
				hx::MultEq(bunny->speedX,(int)-1);
				HX_STACK_LINE(124)
				bunny->set_x(this->_maxX);
			}
			else{
				HX_STACK_LINE(126)
				Float _g5 = bunny->get_x();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(126)
				if (((_g5 < this->_minX))){
					HX_STACK_LINE(127)
					hx::MultEq(bunny->speedX,(int)-1);
					HX_STACK_LINE(128)
					bunny->set_x(this->_minX);
				}
			}
			HX_STACK_LINE(131)
			Float _g6 = bunny->get_y();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(131)
			if (((_g6 > this->_maxY))){
				HX_STACK_LINE(132)
				hx::MultEq(bunny->speedY,-0.90);
				HX_STACK_LINE(133)
				bunny->set_y(this->_maxY);
				HX_STACK_LINE(134)
				Float _g7 = ::Math_obj::random();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(134)
				if (((_g7 > 0.5))){
					HX_STACK_LINE(134)
					Float _g8 = ::Math_obj::random();		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(134)
					Float _g9 = (_g8 * (int)6);		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(134)
					hx::SubEq(bunny->speedY,_g9);
				}
			}
			else{
				HX_STACK_LINE(136)
				Float _g10 = bunny->get_y();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(136)
				if (((_g10 < this->_minY))){
					HX_STACK_LINE(137)
					bunny->speedY = (int)0;
					HX_STACK_LINE(138)
					bunny->set_y(this->_minY);
				}
			}
			HX_STACK_LINE(141)
			if ((this->_isScale)){
			}
			HX_STACK_LINE(148)
			if ((this->_isRotation)){
				HX_STACK_LINE(148)
				::com::arm::demo::components::bunnymark::Bunny _g2 = bunny;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(148)
				Float _g11 = _g2->get_rotation();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(148)
				Float _g12 = (_g11 + bunny->rotationSpeed);		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(148)
				_g2->set_rotation(_g12);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BunnymarkView_obj,update,(void))

Void BunnymarkView_obj::resize( ){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkView","resize",0xbe7cf891,"com.arm.demo.components.bunnymark.BunnymarkView.resize","com/arm/demo/components/bunnymark/BunnymarkView.hx",152,0xc54841d0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(153)
		this->_maxX = ::fluid::display::FluidStage_obj::screenWidth;
		HX_STACK_LINE(154)
		this->_maxY = ::fluid::display::FluidStage_obj::screenHeight;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BunnymarkView_obj,resize,(void))

Void BunnymarkView_obj::hide( ){
{
		HX_STACK_FRAME("com.arm.demo.components.bunnymark.BunnymarkView","hide",0x89fc021f,"com.arm.demo.components.bunnymark.BunnymarkView.hide","com/arm/demo/components/bunnymark/BunnymarkView.hx",157,0xc54841d0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(158)
		this->_reset();
		HX_STACK_LINE(160)
		{
			HX_STACK_LINE(160)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(160)
			int _g = this->_buttons->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(160)
			while((true)){
				HX_STACK_LINE(160)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(160)
					break;
				}
				HX_STACK_LINE(160)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(161)
				::com::arm::demo::widgets::Button button = this->_buttons->__get(i).StaticCast< ::com::arm::demo::widgets::Button >();		HX_STACK_VAR(button,"button");
				HX_STACK_LINE(162)
				button->disable();
				HX_STACK_LINE(163)
				this->_uiContainer->removeChild(button);
				HX_STACK_LINE(164)
				this->_buttons[i] = null();
			}
		}
		HX_STACK_LINE(167)
		this->_isScale = false;
		HX_STACK_LINE(168)
		this->_isRotation = false;
		HX_STACK_LINE(169)
		this->_uiContainer->removeChild(this->_quantityLabel);
		HX_STACK_LINE(170)
		this->get_container()->removeChild(this->_spriteContainer);
		HX_STACK_LINE(171)
		this->get_container()->removeChild(this->_uiContainer);
		HX_STACK_LINE(172)
		this->_spriteContainer = null();
		HX_STACK_LINE(173)
		this->_uiContainer = null();
		HX_STACK_LINE(174)
		this->_quantityLabel = null();
		HX_STACK_LINE(175)
		this->_buttons = null();
		HX_STACK_LINE(176)
		this->_sprites = null();
		HX_STACK_LINE(177)
		this->_bunnyTexture = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BunnymarkView_obj,hide,(void))


BunnymarkView_obj::BunnymarkView_obj()
{
}

void BunnymarkView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BunnymarkView);
	HX_MARK_MEMBER_NAME(_sprites,"_sprites");
	HX_MARK_MEMBER_NAME(_buttons,"_buttons");
	HX_MARK_MEMBER_NAME(_bunnyTexture,"_bunnyTexture");
	HX_MARK_MEMBER_NAME(_spriteContainer,"_spriteContainer");
	HX_MARK_MEMBER_NAME(_uiContainer,"_uiContainer");
	HX_MARK_MEMBER_NAME(_quantityLabel,"_quantityLabel");
	HX_MARK_MEMBER_NAME(_isScale,"_isScale");
	HX_MARK_MEMBER_NAME(_isRotation,"_isRotation");
	HX_MARK_MEMBER_NAME(_maxX,"_maxX");
	HX_MARK_MEMBER_NAME(_maxY,"_maxY");
	HX_MARK_MEMBER_NAME(_minX,"_minX");
	HX_MARK_MEMBER_NAME(_minY,"_minY");
	::com::arm::demo::view::DemoView_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BunnymarkView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_sprites,"_sprites");
	HX_VISIT_MEMBER_NAME(_buttons,"_buttons");
	HX_VISIT_MEMBER_NAME(_bunnyTexture,"_bunnyTexture");
	HX_VISIT_MEMBER_NAME(_spriteContainer,"_spriteContainer");
	HX_VISIT_MEMBER_NAME(_uiContainer,"_uiContainer");
	HX_VISIT_MEMBER_NAME(_quantityLabel,"_quantityLabel");
	HX_VISIT_MEMBER_NAME(_isScale,"_isScale");
	HX_VISIT_MEMBER_NAME(_isRotation,"_isRotation");
	HX_VISIT_MEMBER_NAME(_maxX,"_maxX");
	HX_VISIT_MEMBER_NAME(_maxY,"_maxY");
	HX_VISIT_MEMBER_NAME(_minX,"_minX");
	HX_VISIT_MEMBER_NAME(_minY,"_minY");
	::com::arm::demo::view::DemoView_obj::__Visit(HX_VISIT_ARG);
}

Dynamic BunnymarkView_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"show") ) { return show_dyn(); }
		if (HX_FIELD_EQ(inName,"hide") ) { return hide_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_maxX") ) { return _maxX; }
		if (HX_FIELD_EQ(inName,"_maxY") ) { return _maxY; }
		if (HX_FIELD_EQ(inName,"_minX") ) { return _minX; }
		if (HX_FIELD_EQ(inName,"_minY") ) { return _minY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_reset") ) { return _reset_dyn(); }
		if (HX_FIELD_EQ(inName,"_scale") ) { return _scale_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_sprites") ) { return _sprites; }
		if (HX_FIELD_EQ(inName,"_buttons") ) { return _buttons; }
		if (HX_FIELD_EQ(inName,"_isScale") ) { return _isScale; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_rotation") ) { return _rotation_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_addButton") ) { return _addButton_dyn(); }
		if (HX_FIELD_EQ(inName,"_addBunnys") ) { return _addBunnys_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_isRotation") ) { return _isRotation; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_uiContainer") ) { return _uiContainer; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_bunnyTexture") ) { return _bunnyTexture; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_quantityLabel") ) { return _quantityLabel; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_spriteContainer") ) { return _spriteContainer; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_updateQuanityLabel") ) { return _updateQuanityLabel_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BunnymarkView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_maxX") ) { _maxX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_maxY") ) { _maxY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_minX") ) { _minX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_minY") ) { _minY=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_sprites") ) { _sprites=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_buttons") ) { _buttons=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_isScale") ) { _isScale=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_isRotation") ) { _isRotation=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_uiContainer") ) { _uiContainer=inValue.Cast< ::fluid::display::FluidSprite >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_bunnyTexture") ) { _bunnyTexture=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_quantityLabel") ) { _quantityLabel=inValue.Cast< ::com::arm::demo::widgets::Label >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_spriteContainer") ) { _spriteContainer=inValue.Cast< ::fluid::display::FluidSprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BunnymarkView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_sprites"));
	outFields->push(HX_CSTRING("_buttons"));
	outFields->push(HX_CSTRING("_bunnyTexture"));
	outFields->push(HX_CSTRING("_spriteContainer"));
	outFields->push(HX_CSTRING("_uiContainer"));
	outFields->push(HX_CSTRING("_quantityLabel"));
	outFields->push(HX_CSTRING("_isScale"));
	outFields->push(HX_CSTRING("_isRotation"));
	outFields->push(HX_CSTRING("_maxX"));
	outFields->push(HX_CSTRING("_maxY"));
	outFields->push(HX_CSTRING("_minX"));
	outFields->push(HX_CSTRING("_minY"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(BunnymarkView_obj,_sprites),HX_CSTRING("_sprites")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(BunnymarkView_obj,_buttons),HX_CSTRING("_buttons")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(BunnymarkView_obj,_bunnyTexture),HX_CSTRING("_bunnyTexture")},
	{hx::fsObject /*::fluid::display::FluidSprite*/ ,(int)offsetof(BunnymarkView_obj,_spriteContainer),HX_CSTRING("_spriteContainer")},
	{hx::fsObject /*::fluid::display::FluidSprite*/ ,(int)offsetof(BunnymarkView_obj,_uiContainer),HX_CSTRING("_uiContainer")},
	{hx::fsObject /*::com::arm::demo::widgets::Label*/ ,(int)offsetof(BunnymarkView_obj,_quantityLabel),HX_CSTRING("_quantityLabel")},
	{hx::fsBool,(int)offsetof(BunnymarkView_obj,_isScale),HX_CSTRING("_isScale")},
	{hx::fsBool,(int)offsetof(BunnymarkView_obj,_isRotation),HX_CSTRING("_isRotation")},
	{hx::fsFloat,(int)offsetof(BunnymarkView_obj,_maxX),HX_CSTRING("_maxX")},
	{hx::fsFloat,(int)offsetof(BunnymarkView_obj,_maxY),HX_CSTRING("_maxY")},
	{hx::fsFloat,(int)offsetof(BunnymarkView_obj,_minX),HX_CSTRING("_minX")},
	{hx::fsFloat,(int)offsetof(BunnymarkView_obj,_minY),HX_CSTRING("_minY")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_sprites"),
	HX_CSTRING("_buttons"),
	HX_CSTRING("_bunnyTexture"),
	HX_CSTRING("_spriteContainer"),
	HX_CSTRING("_uiContainer"),
	HX_CSTRING("_quantityLabel"),
	HX_CSTRING("_isScale"),
	HX_CSTRING("_isRotation"),
	HX_CSTRING("_maxX"),
	HX_CSTRING("_maxY"),
	HX_CSTRING("_minX"),
	HX_CSTRING("_minY"),
	HX_CSTRING("show"),
	HX_CSTRING("_addButton"),
	HX_CSTRING("_updateQuanityLabel"),
	HX_CSTRING("_reset"),
	HX_CSTRING("_scale"),
	HX_CSTRING("_rotation"),
	HX_CSTRING("_addBunnys"),
	HX_CSTRING("update"),
	HX_CSTRING("resize"),
	HX_CSTRING("hide"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BunnymarkView_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BunnymarkView_obj::__mClass,"__mClass");
};

#endif

Class BunnymarkView_obj::__mClass;

void BunnymarkView_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.components.bunnymark.BunnymarkView"), hx::TCanCast< BunnymarkView_obj> ,sStaticFields,sMemberFields,
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

void BunnymarkView_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components
} // end namespace bunnymark
