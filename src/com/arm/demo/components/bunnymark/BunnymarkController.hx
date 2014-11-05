package com.arm.demo.components.bunnymark;

import com.arm.demo.notifications.internal.MenuNotification;
import com.arm.demo.components.GameComponentController;

class BunnymarkController extends GameComponentController {

	var _id:Int = 4;
	var _view:BunnymarkView;
	var _showing:Bool = false;

	public function new(m, v, c, mainModel) {
		super(m, v, c, mainModel);
		_view = cast(v, BunnymarkView);
	}

	override function _update(elapsedTime:Float) {
		if (_showing) _view.update(elapsedTime);
	}

	override function _resize() {
		if (_showing) _view.resize();
	}

	override function _addNotificationListeners() {
		super._addNotificationListeners();
		MenuNotification.click.add(_onMenuClick);
		MenuNotification.reset.add(_reset);
	}

	function _reset() {
		if (_showing) {
			_view.hide();
			_showing = false;
		}
	}

	function _onMenuClick(id:Int) {
		if (id == _id) {
			if (!_showing) _view.show();
			_showing = true;
		}
	}
}