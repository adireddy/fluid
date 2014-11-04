package com.arm.demo.widgets.menu;

import fluid.events.EventData;
import fluid.display.FluidSprite;
import fluid.display.FluidStage;
import haxe.Timer;

class Menu extends FluidSprite {

	var _itemWidth:Float;
	var _itemHeight:Float;
	var _menuItems:Array<MenuItem>;
	var _lastPosition:Float;
	var _dragging:Bool;
	var _height:Float;

	public function new(itemWidth:Float, itemHeight:Float) {
		super();

		_itemWidth = itemWidth;
		_itemHeight = itemHeight;
		_menuItems = [];
		interactive = true;
	}

	public function addItem(label:String, ?data:Dynamic):MenuItem {
		var menuItem:MenuItem = new MenuItem(label, _itemWidth, _itemHeight, data);
		menuItem.y = _itemHeight * _menuItems.length;
		addChild(menuItem);
		_menuItems.push(menuItem);
		_height = _itemHeight * _menuItems.length;

		if (_height > FluidStage.screenHeight) {
			touchBegin = _onTouchStart;
			touchEnd = _onTouchEnd;
			mouseDown = _onMouseDown;
			mouseUp = _onMouseUp;
		}
		return menuItem;
	}

	function _onTouchStart(data:EventData) {
		_lastPosition = data.stageY;
		touchMove = _onTouchMove;
	}

	function _onTouchMove(data:EventData) {
		var distance = _lastPosition - data.stageY;
		if (_dragging || (distance < -5 || distance > 5)) {
			disableMenuItems();
			_move(_lastPosition - data.stageY);
			_dragging = true;
			_lastPosition = data.stageY;
		}
	}

	function _onTouchEnd(data:EventData) {
		touchMove = null;
		_dragging = false;
		Timer.delay(enableMenuItems, 100);
	}

	function _onMouseDown(data:EventData) {
		_lastPosition = data.stageY;
		mouseMove = _onMouseMove;
	}

	function _onMouseUp(data:EventData) {
		mouseMove = null;
		_dragging = false;
		enableMenuItems();
	}

	function _onMouseMove(data:EventData) {
		var distance = _lastPosition - data.stageY;

		if (_dragging || (distance < -5 || distance > 5)) {
			disableMenuItems();
			_move(_lastPosition - data.stageY);
			_dragging = true;
			_lastPosition = data.stageY;
		}
	}

	public function disableMenuItems() {
		for (i in 0 ... _menuItems.length) {
			_menuItems[i].disable();
		}
	}

	public function enableMenuItems() {
		for (i in 0 ... _menuItems.length) {
			_menuItems[i].enable();
		}
	}

	function _move(distance:Float) {
		y -= distance;
		if (y > 0) y = 0;
		else if (y < -(_height - FluidStage.screenHeight)) {
			y = -(_height - FluidStage.screenHeight);
		}

		x = Math.round(x);
		y = Math.round(y);
	}

	public function getItems():Array<MenuItem> {
		return _menuItems;
	}

}