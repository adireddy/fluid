package com.arm.demo.components.menu;

import fluid.display.FluidStage;
import com.arm.demo.notifications.internal.MenuNotification;
import com.arm.demo.widgets.menu.MenuItem;
import com.arm.demo.widgets.menu.PopoutMenu;
import com.arm.demo.components.GameComponentView;

class MenuView extends GameComponentView {

	var _menu:PopoutMenu;
	var _menuItems:Array<String>;
	var _currentItem:Int;

	public function new(container) {
		super(container);
		_menuItems = ["Screen Test", "Screen Guide", "Localisation", "Sprites", "Bunnys", "Sprite Sheets", "Coin Shower", "Typekit", "Audio", "Currency Format", "Server Request", "Console Bridge", "Reels", "Skeleton Animation", "Physics", "Reset"]; //"Particles"
	}

	public function create() {
		trace("FFFF");
		_menu = new PopoutMenu(180, 40);
		var _menuItem:MenuItem;
		for (i in 0 ... _menuItems.length) {
			_menuItem = _menu.addItem(_menuItems[i], i);
			_menuItem.action.add(_menuClick);
		}
		container.addChild(_menu);
		_menu.y = FluidStage.pixelRatio;
	}

	public function hide() {
		_menu.hide();
	}

	function _menuClick(id:Int) {
		if (_currentItem != id && id < _menuItems.length - 1) {
			MenuNotification.click.dispatch(id);
		}
		else {
			MenuNotification.reset.dispatch();
		}
		if (id != 15) hide();
	}
}