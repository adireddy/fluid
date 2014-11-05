package com.arm.demo.controller;

import com.arm.demo.comms.DemoCommsController;
import com.arm.demo.view.DemoView;
import com.arm.demo.model.DemoModel;

import com.arm.demo.components.menu.MenuController;
import com.arm.demo.components.menu.MenuView;

import com.arm.demo.components.bunnymark.BunnymarkController;
import com.arm.demo.components.bunnymark.BunnymarkView;

class DemoController {

	public var model(default, default):DemoModel;
	public var view(default, default):DemoView;
	public var comms(default, default):DemoCommsController;

	public function new(m:DemoModel, v:DemoView, c:DemoCommsController) {
		model = m;
		view = v;
		comms = c;

		_addNotificationListeners();
		_addViewListeners();
	}

	private function _addNotificationListeners():Void {}
	private function _addViewListeners():Void {}

	public function reset():Void {
		if (view != null) view.reset();
		if (model != null) model.reset();
		if (comms != null) comms.reset();
		model = null;
		view = null;
		comms = null;
	}

	public function setupComponents() {
		_setupMenuComponent();
		//_setupScreenGuideComponent();
		_setupBunnymarkComponent();
	}

	function _setupBunnymarkComponent() {
		var bunnymarkView:BunnymarkView = new BunnymarkView(view.container);
		var bunnymarkController:BunnymarkController = new BunnymarkController(null, bunnymarkView, comms, model);
	}

	function _setupMenuComponent() {
		var menuView:MenuView = new MenuView(view.container);
		var menuController:MenuController = new MenuController(null, menuView, comms, model);
	}
}