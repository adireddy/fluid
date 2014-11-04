package com.arm.demo.widgets.menu;

import fluid.display.FluidSprite;
import com.arm.demo.widgets.Button;
import msignal.Signal.Signal1;

class MenuItem extends FluidSprite {

	var _data:Dynamic;
	var _button:Button;

	public var action:Signal1<Dynamic>;

	public function new(label:String, width:Float, height:Float, ?data:Dynamic) {
		super();
		_button = new Button(label, width, height, data);
		action = _button.action;
		addChild(_button);
	}

	public function setText(label:String) {
		_button.setText(label);
	}

	public function enable() {
		_button.enable();
	}

	public function disable() {
		_button.disable();
	}
}