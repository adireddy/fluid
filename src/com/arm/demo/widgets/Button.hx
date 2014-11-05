package com.arm.demo.widgets;

import fluid.text.FluidTextFormat;
import fluid.display.FluidSprite;
import fluid.text.FluidText;
import fluid.display.FluidGraphics;
import fluid.geom.FluidRectangle;
import msignal.Signal;

class Button extends FluidSprite {

	public static inline var OVER_COLOUR:UInt = 0x003366;
	public static inline var OUT_COLOUR:UInt = 0x21610B;
	public static inline var TEXT_COLOUR:String = "#FFFFFF";

	var _data:Dynamic;

	var _label:FluidText;
	var _rect:FluidRectangle;
	var _background:FluidGraphics;

	var _enabled:Bool;

	public var action:Signal1<Dynamic> = new Signal1(Dynamic);

	public function new(label:String, width:Float, height:Float, ?data:Dynamic, ?fontSize:Int) {
		super();
		_data = data;
		_setupBackground(width, height);
		_setupLabel(width, height, fontSize);
		setText(label);
	}

	function _setupBackground(width:Float, height:Float) {
		_rect = new FluidRectangle(0, 0, width, height);
		_background = new FluidGraphics();
		//_background.hitArea = _rect;
		_redraw(Button.OUT_COLOUR);
		addChild(_background);

		_background.interactive = true;
		_background.mouseOver = _onMouseOver;
		_background.mouseOut = _onMouseOut;
		_background.mouseDown = _onMouseDown;
		_background.mouseUp = _onMouseUp;
		_background.touchBegin = _onTouchStart;
		_background.touchEnd = _onTouchEnd;
		_background.touchOut = _onTouchEndOutside;
	}

	function _setupLabel(width:Float, height:Float, ?fontSize:Int = 16) {
		var format = new FluidTextFormat();
		format.size = fontSize;
		format.font = "Arial";
		format.fill = Button.TEXT_COLOUR;
		_label = new FluidText("", format);
		_label.setAnchor(0.5, 0.5);
		_label.interactive = false;
		_label.x = width / 2;
		_label.y = height / 2;
		addChild(_label);
	}

	function _redraw(colour:UInt) {
		var border:Float = 1;
		_background.clear();
		_background.beginFill(colour);
		_background.drawRect(_rect.x, _rect.y, _rect.width, _rect.height);
		_background.endFill();
		_background.beginFill(colour);
		_background.drawRect(_rect.x + border / 2, _rect.y + border / 2, _rect.width - border, _rect.height - border);
		_background.endFill();
	}

	public function setText(label:String) {
		_label.setText(label);
	}

	function _onMouseDown(data:Dynamic) {
		if (_enabled) _redraw(Button.OVER_COLOUR);
	}

	function _onMouseUp(data) {
		if (_enabled) {
			action.dispatch(_data);
			_redraw(Button.OUT_COLOUR);
		}
	}

	function _onMouseUpOutside(data) {
		if (_enabled) _redraw(Button.OUT_COLOUR);
	}

	function _onMouseOver(data) {
		if (_enabled) _redraw(Button.OVER_COLOUR);
	}

	function _onMouseOut(data) {
		if (_enabled) _redraw(Button.OUT_COLOUR);
	}

	function _onTouchEndOutside(data) {
		if (_enabled) _redraw(Button.OUT_COLOUR);
	}

	function _onTouchEnd(data) {
		if (_enabled) {
			_redraw(Button.OUT_COLOUR);
			action.dispatch(_data);
		}
	}

	function _onTouchStart(data) {
		if (_enabled) _redraw(Button.OVER_COLOUR);
	}

	public function enable() {
		_enabled = true;
	}

	public function disable() {
		_redraw(Button.OUT_COLOUR);
		_enabled = false;
	}
}