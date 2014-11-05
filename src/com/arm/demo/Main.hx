package com.arm.demo;

import com.arm.demo.notifications.internal.ViewStateNotification;
import com.arm.demo.controller.DemoController;
import com.arm.demo.model.DemoModel;
import com.arm.demo.comms.DemoCommsController;
import com.arm.demo.view.DemoView;

import fluid.display.FluidSprite;

class Main extends Application {

	public function new() {
		super();

		stats = true;
		backgroundColor = 0xBEF781;
		skipFrame = true;

		resize = _onResize;
		update = _onUpdate;

		_setupMVCS();
	}

	function _setupMVCS() {
		view = new DemoView(container);
		comms = new DemoCommsController();
		model = new DemoModel();
		controller = new DemoController(model, view, comms);
		controller.setupComponents();
	}

	function _onUpdate(time:Float) {
		ViewStateNotification.update.dispatch(time);
	}

	function _onResize() {
		ViewStateNotification.resize.dispatch();
	}

	#if js
	static function main() {
		new Main();
	}
	#end
}