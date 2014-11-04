package com.arm.demo.components;

import com.arm.demo.comms.DemoCommsController;
import com.arm.demo.view.DemoView;
import com.arm.demo.model.DemoModel;
import com.arm.demo.controller.DemoController;
import arm.mvc.model.Model;
import arm.mvc.notifications.ViewStateNotification;
import arm.mvc.comms.CommsController;

class GameComponentController extends DemoController {

	public var mainModel(default, default):Model;

	public function new(m:DemoModel, v:DemoView, c:DemoCommsController, mm:Model) {
		super(m, v, c);
		mainModel = mm;
	}

	override private function _addNotificationListeners():Void {
		ViewStateNotification.preload.addOnce(_preload);
		ViewStateNotification.create.addOnce(_create);
		ViewStateNotification.update.add(_update);
		ViewStateNotification.resize.add(_resize);
	}

	private function _preload():Void {}
	private function _create():Void {}
	private function _update(elapsedTime:Float):Void {}

	private function _resize():Void {
		mainModel = null;
		ViewStateNotification.reset();
	}
}