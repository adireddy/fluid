#ifndef INCLUDED_com_arm_demo_controller_DemoController
#define INCLUDED_com_arm_demo_controller_DemoController

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,arm,demo,comms,DemoCommsController)
HX_DECLARE_CLASS4(com,arm,demo,controller,DemoController)
HX_DECLARE_CLASS4(com,arm,demo,model,DemoModel)
HX_DECLARE_CLASS4(com,arm,demo,view,DemoView)
namespace com{
namespace arm{
namespace demo{
namespace controller{


class HXCPP_CLASS_ATTRIBUTES  DemoController_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DemoController_obj OBJ_;
		DemoController_obj();
		Void __construct(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< DemoController_obj > __new(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~DemoController_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DemoController"); }

		::com::arm::demo::model::DemoModel model;
		::com::arm::demo::view::DemoView view;
		::com::arm::demo::comms::DemoCommsController comms;
		virtual Void _addNotificationListeners( );
		Dynamic _addNotificationListeners_dyn();

		virtual Void _addViewListeners( );
		Dynamic _addViewListeners_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void setupComponents( );
		Dynamic setupComponents_dyn();

		virtual Void _setupMenuComponent( );
		Dynamic _setupMenuComponent_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace controller

#endif /* INCLUDED_com_arm_demo_controller_DemoController */ 
