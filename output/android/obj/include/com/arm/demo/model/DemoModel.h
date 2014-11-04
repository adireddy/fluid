#ifndef INCLUDED_com_arm_demo_model_DemoModel
#define INCLUDED_com_arm_demo_model_DemoModel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,arm,demo,model,DemoModel)
namespace com{
namespace arm{
namespace demo{
namespace model{


class HXCPP_CLASS_ATTRIBUTES  DemoModel_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DemoModel_obj OBJ_;
		DemoModel_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< DemoModel_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~DemoModel_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("DemoModel"); }

		virtual Void reset( );
		Dynamic reset_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace model

#endif /* INCLUDED_com_arm_demo_model_DemoModel */ 
