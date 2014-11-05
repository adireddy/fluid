package com.arm.demo.widgets;

import fluid.text.FluidTextFormat;
import fluid.text.FluidText;
import fluid.display.FluidGraphics;
import fluid.geom.FluidRectangle;
import fluid.display.FluidSprite;

class Label extends FluidSprite {

	public static inline var BACKGROUND_COLOUR:Int = 0xFFFFFF;
	public static inline var BORDER_COLOUR:Int = 0x333333;
	public static inline var TEXT_COLOUR:String = "#333333";
	public static inline var TEXT_SIZE:Int = 16;
	public static inline var PADDING:Int = 4;

	var _label:FluidText;
	var _rect:FluidRectangle;
	var _background:FluidGraphics;
	var _format:FluidTextFormat;

	public function new(label:String, width:Float, height:Float, ?style:Dynamic) {
		super();
		_format = new FluidTextFormat();
		_format.size = Label.TEXT_SIZE;
		_format.font = "Arial";
		_format.fill = Label.TEXT_COLOUR;

		_setupBackground(width, height);
		_setupLabel(width, height);
		setText(label);
	}

	function _setupBackground(width:Float, height:Float) {
		_rect = new FluidRectangle(0, 0, width, height);
		_background = new FluidGraphics();

		_background.beginFill(Label.BORDER_COLOUR);
		_background.drawRect(_rect.x, _rect.y, _rect.width, _rect.height);
		_background.endFill();

		_background.beginFill(Label.BACKGROUND_COLOUR);
		_background.drawRect(_rect.x + 1, _rect.y + 1, _rect.width - 2, _rect.height - 2);
		_background.endFill();

		addChild(_background);
	}

	function _setupLabel(width:Float, height:Float) {
		_label = new FluidText("", _format);
		_label.setAnchor(0.5);
		_label.x = width / 2;
		_label.y = Label.PADDING;
		addChild(_label);
	}

	public function setText(label:String) {
		_label.setText(label);
	}
}