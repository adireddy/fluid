#ifndef INCLUDED_com_arm_demo_components_menu_MenuController
#define INCLUDED_com_arm_demo_components_menu_MenuController

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/arm/demo/components/GameComponentController.h>
HX_DECLARE_CLASS4(com,arm,demo,comms,DemoCommsController)
HX_DECLARE_CLASS4(com,arm,demo,components,GameComponentController)
HX_DECLARE_CLASS4(com,arm,demo,components,GameComponentView)
HX_DECLARE_CLASS5(com,arm,demo,components,menu,MenuController)
HX_DECLARE_CLASS5(com,arm,demo,components,menu,MenuView)
HX_DECLARE_CLASS4(com,arm,demo,controller,DemoController)
HX_DECLARE_CLASS4(com,arm,demo,model,DemoModel)
HX_DECLARE_CLASS4(com,arm,demo,view,DemoView)
namespace com{
namespace arm{
namespace demo{
namespace components{
namespace menu{


class HXCPP_CLASS_ATTRIBUTES  MenuController_obj : public ::com::arm::demo::components::GameComponentController_obj{
	public:
		typedef ::com::arm::demo::components::GameComponentController_obj super;
		typedef MenuController_obj OBJ_;
		MenuController_obj();
		Void __construct(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mainModel);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MenuController_obj > __new(::com::arm::demo::model::DemoModel m,::com::arm::demo::view::DemoView v,::com::arm::demo::comms::DemoCommsController c,::com::arm::demo::model::DemoModel mainModel);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MenuController_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MenuController"); }

		::com::arm::demo::components::menu::MenuView _view;
		virtual Void _create( );

};

} // end namespace com
} // end namespace arm
} // end namespace demo
} // end namespace components
} // end namespace menu

#endif /* INCLUDED_com_arm_demo_components_menu_MenuController */ 
