#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_arm_demo_Bunny
#include <com/arm/demo/Bunny.h>
#endif
#ifndef INCLUDED_com_arm_demo_Main
#include <com/arm/demo/Main.h>
#endif
#ifndef INCLUDED_fluid_Fluid
#include <fluid/Fluid.h>
#endif
#ifndef INCLUDED_fluid_FluidAssets
#include <fluid/FluidAssets.h>
#endif
#ifndef INCLUDED_fluid_StageProperties
#include <fluid/StageProperties.h>
#endif
#ifndef INCLUDED_fluid_display_FluidSprite
#include <fluid/display/FluidSprite.h>
#endif
#ifndef INCLUDED_fluid_text_FluidText
#include <fluid/text/FluidText.h>
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
#ifndef INCLUDED_openfl__v2_events_Event
#include <openfl/_v2/events/Event.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_MouseEvent
#include <openfl/_v2/events/MouseEvent.h>
#endif
#ifndef INCLUDED_openfl__v2_events_TouchEvent
#include <openfl/_v2/events/TouchEvent.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextField
#include <openfl/_v2/text/TextField.h>
#endif
namespace com{
namespace arm{
namespace demo{

Void Main_obj::__construct()
{
HX_STACK_FRAME("com.arm.demo.Main","new",0x87bbe177,"com.arm.demo.Main.new","com/arm/demo/Main.hx",10,0x9201fb7a)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(23)
	this->_addBunnies = false;
	HX_STACK_LINE(20)
	this->_count = (int)0;
	HX_STACK_LINE(25)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(26)
	super::__construct();
	HX_STACK_LINE(27)
	this->skipFrame = true;
	HX_STACK_LINE(28)
	Float _g1 = this->_minY = (int)0;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(28)
	this->_minX = _g1;
	HX_STACK_LINE(29)
	this->_maxX = ::fluid::StageProperties_obj::screenWidth;
	HX_STACK_LINE(30)
	this->_maxY = ::fluid::StageProperties_obj::screenHeight;
	HX_STACK_LINE(31)
	this->_sprites = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(40)
	::fluid::text::FluidText _g11 = ::fluid::text::FluidText_obj::__new(HX_CSTRING("BUNNIES: 0"));		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(40)
	this->_countText = _g11;
	HX_STACK_LINE(41)
	this->container->addChild(this->_countText);
	HX_STACK_LINE(43)
	::openfl::_v2::display::BitmapData _g2 = ::fluid::FluidAssets_obj::getImage(HX_CSTRING("assets/bunny.png"));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(43)
	this->_bunnyTexture = _g2;
	HX_STACK_LINE(44)
	this->_showStats();

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,_g)
	Void run(::openfl::_v2::events::TouchEvent evt){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","com/arm/demo/Main.hx",46,0x9201fb7a)
		HX_STACK_ARG(evt,"evt")
		{
			HX_STACK_LINE(46)
			_g->__get((int)0).StaticCast< ::com::arm::demo::Main >()->_addBunnies = true;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(46)
	this->touchBegin =  Dynamic(new _Function_1_1(_g));

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_2,Array< ::Dynamic >,_g)
	Void run(::openfl::_v2::events::MouseEvent evt){
		HX_STACK_FRAME("*","_Function_1_2",0x5200ed38,"*._Function_1_2","com/arm/demo/Main.hx",47,0x9201fb7a)
		HX_STACK_ARG(evt,"evt")
		{
			HX_STACK_LINE(47)
			_g->__get((int)0).StaticCast< ::com::arm::demo::Main >()->_addBunnies = true;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(47)
	this->mouseDown =  Dynamic(new _Function_1_2(_g));

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_3,Array< ::Dynamic >,_g)
	Void run(::openfl::_v2::events::MouseEvent evt){
		HX_STACK_FRAME("*","_Function_1_3",0x5200ed39,"*._Function_1_3","com/arm/demo/Main.hx",48,0x9201fb7a)
		HX_STACK_ARG(evt,"evt")
		{
			HX_STACK_LINE(48)
			_g->__get((int)0).StaticCast< ::com::arm::demo::Main >()->_addBunnies = false;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(48)
	this->mouseUp =  Dynamic(new _Function_1_3(_g));

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_4,Array< ::Dynamic >,_g)
	Void run(::openfl::_v2::events::TouchEvent evt){
		HX_STACK_FRAME("*","_Function_1_4",0x5200ed3a,"*._Function_1_4","com/arm/demo/Main.hx",49,0x9201fb7a)
		HX_STACK_ARG(evt,"evt")
		{
			HX_STACK_LINE(49)
			_g->__get((int)0).StaticCast< ::com::arm::demo::Main >()->_addBunnies = false;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(49)
	Dynamic _g3 = this->touchOut =  Dynamic(new _Function_1_4(_g));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(49)
	this->touchEnd = _g3;
}
;
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::_addBunnys( int count){
{
		HX_STACK_FRAME("com.arm.demo.Main","_addBunnys",0x1c5f95f8,"com.arm.demo.Main._addBunnys","com/arm/demo/Main.hx",52,0x9201fb7a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(count,"count")
		HX_STACK_LINE(53)
		hx::AddEq(this->_count,count);
		HX_STACK_LINE(54)
		this->_countText->setText((HX_CSTRING("BUNNIES: ") + this->_count));
		HX_STACK_LINE(55)
		{
			HX_STACK_LINE(55)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(55)
			while((true)){
				HX_STACK_LINE(55)
				if ((!(((_g < count))))){
					HX_STACK_LINE(55)
					break;
				}
				HX_STACK_LINE(55)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(56)
				::com::arm::demo::Bunny bunny = ::com::arm::demo::Bunny_obj::__new(this->_bunnyTexture);		HX_STACK_VAR(bunny,"bunny");
				HX_STACK_LINE(57)
				this->container->addChild(bunny);
				HX_STACK_LINE(58)
				int _g1 = ::Std_obj::_int(::fluid::StageProperties_obj::screenWidth);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(58)
				int _g11 = ::Std_obj::random(_g1);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(58)
				bunny->set_x(_g11);
				HX_STACK_LINE(59)
				int _g2 = ::Std_obj::_int(::fluid::StageProperties_obj::screenHeight);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(59)
				int _g3 = ::Std_obj::random(_g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(59)
				bunny->set_y(_g3);
				HX_STACK_LINE(62)
				Float _g4 = ::Math_obj::random();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(62)
				Float _g5 = (_g4 * (int)16);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(62)
				Float _g6 = (_g5 + (int)2);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(62)
				bunny->speedX = _g6;
				HX_STACK_LINE(63)
				Float _g7 = ::Math_obj::random();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(63)
				Float _g8 = (_g7 * (int)16);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(63)
				Float _g9 = (_g8 - (int)10);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(63)
				bunny->speedY = _g9;
				HX_STACK_LINE(64)
				Float _g10 = ::Math_obj::random();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(64)
				Float _g111 = (Float(_g10) / Float((int)50));		HX_STACK_VAR(_g111,"_g111");
				HX_STACK_LINE(64)
				Float _g12 = (_g111 + 0.01);		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(64)
				bunny->rotationSpeed = _g12;
				HX_STACK_LINE(65)
				Float _g13 = ::Math_obj::random();		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(65)
				Float _g14 = (Float(_g13) / Float((int)50));		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(65)
				Float _g15 = (_g14 + 0.01);		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(65)
				bunny->scaleSpeed = _g15;
				HX_STACK_LINE(66)
				this->_sprites->push(bunny);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_addBunnys,(void))

Void Main_obj::_update( Float elapsedTime){
{
		HX_STACK_FRAME("com.arm.demo.Main","_update",0x5ef8803f,"com.arm.demo.Main._update","com/arm/demo/Main.hx",70,0x9201fb7a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(elapsedTime,"elapsedTime")
		HX_STACK_LINE(71)
		if ((this->_addBunnies)){
			HX_STACK_LINE(71)
			this->_addBunnys((int)10);
		}
		HX_STACK_LINE(72)
		if (((this->_sprites->length > (int)0))){
			HX_STACK_LINE(73)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(73)
			int _g = this->_sprites->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(73)
			while((true)){
				HX_STACK_LINE(73)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(73)
					break;
				}
				HX_STACK_LINE(73)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(74)
				::com::arm::demo::Bunny bunny = this->_sprites->__get(i).StaticCast< ::com::arm::demo::Bunny >();		HX_STACK_VAR(bunny,"bunny");
				HX_STACK_LINE(75)
				{
					HX_STACK_LINE(75)
					::com::arm::demo::Bunny _g2 = bunny;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(75)
					Float _g3 = _g2->get_x();		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(75)
					Float _g11 = (_g3 + bunny->speedX);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(75)
					_g2->set_x(_g11);
				}
				HX_STACK_LINE(76)
				{
					HX_STACK_LINE(76)
					::com::arm::demo::Bunny _g2 = bunny;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(76)
					Float _g21 = _g2->get_y();		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(76)
					Float _g3 = (_g21 + bunny->speedY);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(76)
					_g2->set_y(_g3);
				}
				HX_STACK_LINE(77)
				hx::AddEq(bunny->speedY,4.75);
				HX_STACK_LINE(79)
				Float _g4 = bunny->get_x();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(79)
				if (((_g4 > this->_maxX))){
					HX_STACK_LINE(80)
					hx::MultEq(bunny->speedX,(int)-1);
					HX_STACK_LINE(81)
					bunny->set_x(this->_maxX);
				}
				else{
					HX_STACK_LINE(83)
					Float _g5 = bunny->get_x();		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(83)
					if (((_g5 < this->_minX))){
						HX_STACK_LINE(84)
						hx::MultEq(bunny->speedX,(int)-1);
						HX_STACK_LINE(85)
						bunny->set_x(this->_minX);
					}
				}
				HX_STACK_LINE(88)
				Float _g6 = bunny->get_y();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(88)
				if (((_g6 > this->_maxY))){
					HX_STACK_LINE(89)
					hx::MultEq(bunny->speedY,-0.90);
					HX_STACK_LINE(90)
					bunny->set_y(this->_maxY);
					HX_STACK_LINE(91)
					Float _g7 = ::Math_obj::random();		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(91)
					if (((_g7 > 0.5))){
						HX_STACK_LINE(91)
						Float _g8 = ::Math_obj::random();		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(91)
						Float _g9 = (_g8 * (int)6);		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(91)
						hx::SubEq(bunny->speedY,_g9);
					}
				}
				else{
					HX_STACK_LINE(93)
					Float _g10 = bunny->get_y();		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(93)
					if (((_g10 < this->_minY))){
						HX_STACK_LINE(94)
						bunny->speedY = (int)0;
						HX_STACK_LINE(95)
						bunny->set_y(this->_minY);
					}
				}
			}
		}
	}
return null();
}


Void Main_obj::_resize( ){
{
		HX_STACK_FRAME("com.arm.demo.Main","_resize",0xe06e542a,"com.arm.demo.Main._resize","com/arm/demo/Main.hx",110,0x9201fb7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(111)
		this->_maxX = ::fluid::StageProperties_obj::screenWidth;
		HX_STACK_LINE(112)
		this->_maxY = ::fluid::StageProperties_obj::screenHeight;
	}
return null();
}



Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(_bunnyTexture,"_bunnyTexture");
	HX_MARK_MEMBER_NAME(_sprites,"_sprites");
	HX_MARK_MEMBER_NAME(_maxX,"_maxX");
	HX_MARK_MEMBER_NAME(_maxY,"_maxY");
	HX_MARK_MEMBER_NAME(_minX,"_minX");
	HX_MARK_MEMBER_NAME(_minY,"_minY");
	HX_MARK_MEMBER_NAME(_count,"_count");
	HX_MARK_MEMBER_NAME(_countText,"_countText");
	HX_MARK_MEMBER_NAME(_addBunnies,"_addBunnies");
	::fluid::Fluid_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_bunnyTexture,"_bunnyTexture");
	HX_VISIT_MEMBER_NAME(_sprites,"_sprites");
	HX_VISIT_MEMBER_NAME(_maxX,"_maxX");
	HX_VISIT_MEMBER_NAME(_maxY,"_maxY");
	HX_VISIT_MEMBER_NAME(_minX,"_minX");
	HX_VISIT_MEMBER_NAME(_minY,"_minY");
	HX_VISIT_MEMBER_NAME(_count,"_count");
	HX_VISIT_MEMBER_NAME(_countText,"_countText");
	HX_VISIT_MEMBER_NAME(_addBunnies,"_addBunnies");
	::fluid::Fluid_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_maxX") ) { return _maxX; }
		if (HX_FIELD_EQ(inName,"_maxY") ) { return _maxY; }
		if (HX_FIELD_EQ(inName,"_minX") ) { return _minX; }
		if (HX_FIELD_EQ(inName,"_minY") ) { return _minY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_count") ) { return _count; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_update") ) { return _update_dyn(); }
		if (HX_FIELD_EQ(inName,"_resize") ) { return _resize_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_sprites") ) { return _sprites; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_countText") ) { return _countText; }
		if (HX_FIELD_EQ(inName,"_addBunnys") ) { return _addBunnys_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_addBunnies") ) { return _addBunnies; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_bunnyTexture") ) { return _bunnyTexture; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_maxX") ) { _maxX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_maxY") ) { _maxY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_minX") ) { _minX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_minY") ) { _minY=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_count") ) { _count=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_sprites") ) { _sprites=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_countText") ) { _countText=inValue.Cast< ::fluid::text::FluidText >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_addBunnies") ) { _addBunnies=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_bunnyTexture") ) { _bunnyTexture=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_bunnyTexture"));
	outFields->push(HX_CSTRING("_sprites"));
	outFields->push(HX_CSTRING("_maxX"));
	outFields->push(HX_CSTRING("_maxY"));
	outFields->push(HX_CSTRING("_minX"));
	outFields->push(HX_CSTRING("_minY"));
	outFields->push(HX_CSTRING("_count"));
	outFields->push(HX_CSTRING("_countText"));
	outFields->push(HX_CSTRING("_addBunnies"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Main_obj,_bunnyTexture),HX_CSTRING("_bunnyTexture")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Main_obj,_sprites),HX_CSTRING("_sprites")},
	{hx::fsFloat,(int)offsetof(Main_obj,_maxX),HX_CSTRING("_maxX")},
	{hx::fsFloat,(int)offsetof(Main_obj,_maxY),HX_CSTRING("_maxY")},
	{hx::fsFloat,(int)offsetof(Main_obj,_minX),HX_CSTRING("_minX")},
	{hx::fsFloat,(int)offsetof(Main_obj,_minY),HX_CSTRING("_minY")},
	{hx::fsInt,(int)offsetof(Main_obj,_count),HX_CSTRING("_count")},
	{hx::fsObject /*::fluid::text::FluidText*/ ,(int)offsetof(Main_obj,_countText),HX_CSTRING("_countText")},
	{hx::fsBool,(int)offsetof(Main_obj,_addBunnies),HX_CSTRING("_addBunnies")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_bunnyTexture"),
	HX_CSTRING("_sprites"),
	HX_CSTRING("_maxX"),
	HX_CSTRING("_maxY"),
	HX_CSTRING("_minX"),
	HX_CSTRING("_minY"),
	HX_CSTRING("_count"),
	HX_CSTRING("_countText"),
	HX_CSTRING("_addBunnies"),
	HX_CSTRING("_addBunnys"),
	HX_CSTRING("_update"),
	HX_CSTRING("_resize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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

void Main_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
