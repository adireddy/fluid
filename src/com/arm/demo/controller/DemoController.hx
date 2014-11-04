package com.arm.demo.controller;

import arm.mvc.controller.Controller;
import com.arm.demo.view.DemoView;
import com.arm.demo.model.DemoModel;

//import com.arm.demo.components.menu.MenuController;
//import com.arm.demo.components.menu.MenuView;

class DemoController extends Controller {

	var _view:DemoView;

	public function new(m, v, c) {
		_view = cast(v, DemoView);
		super(m, v, c);
	}

	function _getMainModel():DemoModel {
		return cast(model, DemoModel);
	}

	override function _setupComponents() {
		//_setupMenuComponent();
		//_setupScreenGuideComponent();
		//_setupBunnymarkComponent();
	}

	/*function _setupMenuComponent() {
		var menuView:MenuView = new MenuView(_view.gameStage, _view.gameContainer);
		var menuController:MenuController = new MenuController(null, menuView, comms, _getMainModel());
	}*/
}