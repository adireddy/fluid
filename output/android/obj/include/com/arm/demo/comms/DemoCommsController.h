#ifndef INCLUDED_com_arm_demo_comms_DemoCommsController
#define INCLUDED_com_arm_demo_comms_DemoCommsController

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,arm,demo,comms,DemoCommsController)
HX_DECLARE_CLASS1(msignal,Signal)
HX_DECLARE_CLASS1(msignal,Signal1)
HX_DECLARE_CLASS1(msignal,Signal2)
namespace com{
namespace arm{
namespace demo{
namespace comms{


class HXCPP_CLASS_ATTRIBUTES  DemoCommsController_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DemoCommsController_obj OBJ_;
		DemoCommsController_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< DemoCommsController_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~DemoCommsController_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DemoCommsController"); }

		::msignal::Signal2 success;
		::msignal::Signal1 error;
		virtual Void reset( );
		Dynamic reset_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace comms

#endif /* INCLUDED_com_arm_demo_comms_DemoCommsController */ 
