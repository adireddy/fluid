#include <hxcpp.h>

#ifndef INCLUDED_com_arm_demo_model_DemoModel
#include <com/arm/demo/model/DemoModel.h>
#endif
namespace com{
namespace arm{
namespace demo{
namespace model{

Void DemoModel_obj::__construct()
{
HX_STACK_FRAME("com.arm.demo.model.DemoModel","new",0x085e87a7,"com.arm.demo.model.DemoModel.new","com/arm/demo/model/DemoModel.hx",5,0x8e65b729)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//DemoModel_obj::~DemoModel_obj() { }

Dynamic DemoModel_obj::__CreateEmpty() { return  new DemoModel_obj; }
hx::ObjectPtr< DemoModel_obj > DemoModel_obj::__new()
{  hx::ObjectPtr< DemoModel_obj > result = new DemoModel_obj();
	result->__construct();
	return result;}

Dynamic DemoModel_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DemoModel_obj > result = new DemoModel_obj();
	result->__construct();
	return result;}

Void DemoModel_obj::reset( ){
{
		HX_STACK_FRAME("com.arm.demo.model.DemoModel","reset",0x1064a0d6,"com.arm.demo.model.DemoModel.reset","com/arm/demo/model/DemoModel.hx",9,0x8e65b729)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DemoModel_obj,reset,(void))


DemoModel_obj::DemoModel_obj()
{
}

Dynamic DemoModel_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DemoModel_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void DemoModel_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("reset"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DemoModel_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DemoModel_obj::__mClass,"__mClass");
};

#endif

Class DemoModel_obj::__mClass;

void DemoModel_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.arm.demo.model.DemoModel"), hx::TCanCast< DemoModel_obj> ,sStaticFields,sMemberFields,
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

void DemoModel_obj::__boot()
{
}

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace model
