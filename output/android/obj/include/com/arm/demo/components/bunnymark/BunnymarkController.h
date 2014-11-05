#ifndef INCLUDED_com_arm_demo_components_bunnymark_BunnymarkController
#define INCLUDED_com_arm_demo_components_bunnymark_BunnymarkController

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/arm/demo/components/GameComponentController.h>
HX_DECLARE_CLASS4(com,arm,demo,comms,DemoCommsController)
HX_DECLARE_CLASS4(com,arm,demo,components,GameComponentController)
HX_DECLARE_CLASS4(com,arm,demo,components,GameComponentView)
HX_DECLARE_CLASS5(com,arm,demo,components,bunnymark,BunnymarkController)
HX_DECLARE_CLASS5(com,arm,demo,components,bunnymark,BunnymarkView)
HX_DECLARE_CLASS4(com,arm,demo,controller,DemoController)
HX_DECLARE_CLASS4(com,arm,demo,model,DemoModel)
HX_DECLARE_CLASS4(com,arm,demo,view,DemoView)
namespace com{
namespace arm{
namespace demo{
namespace components{
namespace bunnymark{


class HXCPP_CLASS_ATTRIBUTES  BunnymarkController_obj : public ::com::arm::demo::components::GameComponentController_obj{
	public:
		typedef ::com::arm::demo::components::GameComponentController_obj super;
		typedef BunnymarkController_obj OBJ_;
		BunnymarkController_obj();
		Void __construct(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mainModel);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BunnymarkController_obj > __new(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mainModel);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BunnymarkController_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BunnymarkController"); }

		int _id;
		::com::arm::demo::components::bunnymark::BunnymarkView _view;
		bool _showing;
		virtual Void _update( Float elapsedTime);

		virtual Void _resize( );

		virtual Void _addNotificationListeners( );

		virtual Void _reset( );
		Dynamic _reset_dyn();

		virtual Void _onMenuClick( int id);
		Dynamic _onMenuClick_dyn();

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components
} // end namespace bunnymark

#endif /* INCLUDED_com_arm_demo_components_bunnymark_BunnymarkController */ 
