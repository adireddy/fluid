package com.arm.demo.widgets.menu;

import fluid.events.EventData;
import fluid.display.FluidGraphics;
import fluid.geom.FluidRectangle;
import fluid.display.FluidGraphics;
import fluid.display.FluidSprite;
import fluid.display.FluidStage;
import motion.easing.Cubic;
import motion.Actuate;

class PopoutMenu extends FluidSprite {

	public static inline var STATE_SHOW:String = "STATE_SHOW";
	public static inline var STATE_HIDE:String = "STATE_HIDE";

	var _container:FluidSprite;
	var _itemWidth:Float;
	var _itemHeight:Float;
	var _state:String;
	var _menu:Menu;
	var _openButton:FluidGraphics;

	public function new(itemWidth:Float, itemHeight:Float) {
		super();

		_container = new FluidSprite();
		_itemWidth = itemWidth;
		_itemHeight = itemHeight;
		_state = PopoutMenu.STATE_HIDE;

		_setupOpenButton();
		_setupMenu(itemWidth, itemHeight);

		addChild(_container);
	}

	function _setupOpenButton() {
		var buttonRect = new FluidRectangle(0, 0, 30, 80);
		var hitRect = new FluidRectangle(0, 0, 15, 60);

		_openButton = new FluidGraphics();
		_openButton.beginFill(0x21610B);
		_openButton.drawRect(buttonRect.x, buttonRect.y, buttonRect.width, buttonRect.height);
		_openButton.endFill();
		_openButton.interactive = true;
		_openButton.touchBegin = _toggleShow;//function(data:EventData) {};
		_openButton.touchEnd = _toggleShow;
		_openButton.mouseUp = _toggleShow;
		_container.addChild(_openButton);
	}

	function _setupMenu(itemWidth:Float, itemHeight:Float) {
		_menu = new Menu(itemWidth, itemHeight);
		_menu.x = -itemWidth;
		_container.addChild(_menu);
	}

	function _toggleShow(data:EventData) {
		if (_state == PopoutMenu.STATE_SHOW) hide();
		else show();
	}

	public function show() {
		_state = PopoutMenu.STATE_SHOW;
		Actuate.tween(_container, 0.3, { x: _itemWidth }).ease(Cubic.easeInOut).onComplete(_enableMenuItems);
	}

	public function hide() {
		_state = PopoutMenu.STATE_HIDE;
		Actuate.tween(_container, 0.3, { x: 0 }).ease(Cubic.easeInOut).onComplete(_disableMenuItems);
	}

	public function addItem(label:String, ?data:Dynamic):MenuItem {
		var menuItem:MenuItem = _menu.addItem(label, data);
		_updateOpenButtonPosition();
		return menuItem;
	}

	function _enableMenuItems() {
		_menu.enableMenuItems();
	}

	function _disableMenuItems() {
		_menu.disableMenuItems();
	}

	function _updateOpenButtonPosition() {
		var openButtonPosition = Math.floor((_menu.getItems().length - 1) / 2) * _itemHeight;

		if (openButtonPosition > FluidStage.screenHeight / 2) {
			openButtonPosition = FluidStage.screenHeight / 2;
		}
		_openButton.y = openButtonPosition;
	}
}