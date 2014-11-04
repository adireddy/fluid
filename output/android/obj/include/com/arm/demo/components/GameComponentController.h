#ifndef INCLUDED_com_arm_demo_components_GameComponentController
#define INCLUDED_com_arm_demo_components_GameComponentController

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/arm/demo/controller/DemoController.h>
HX_DECLARE_CLASS4(com,arm,demo,comms,DemoCommsController)
HX_DECLARE_CLASS4(com,arm,demo,components,GameComponentController)
HX_DECLARE_CLASS4(com,arm,demo,controller,DemoController)
HX_DECLARE_CLASS4(com,arm,demo,model,DemoModel)
HX_DECLARE_CLASS4(com,arm,demo,view,DemoView)
namespace com{
namespace arm{
namespace demo{
namespace components{


class HXCPP_CLASS_ATTRIBUTES  GameComponentController_obj : public ::com::arm::demo::controller::DemoController_obj{
	public:
		typedef ::com::arm::demo::controller::DemoController_obj super;
		typedef GameComponentController_obj OBJ_;
		GameComponentController_obj();
		Void __construct(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mm);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GameComponentController_obj > __new(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mm);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GameComponentController_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameComponentController"); }

		::com::arm::demo::model::DemoModel mainModel;
		virtual Void _addNotificationListeners( );

		virtual Void _preload( );
		Dynamic _preload_dyn();

		virtual Void _create( );
		Dynamic _create_dyn();

		virtual Void _update( Float elapsedTime);
		Dynamic _update_dyn();

		virtual Void _resize( );
		Dynamic _resize_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components

#endif /* INCLUDED_com_arm_demo_components_GameComponentController */ 
