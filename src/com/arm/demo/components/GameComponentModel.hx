package com.arm.demo.components;

import com.arm.demo.model.DemoModel;

class GameComponentModel {

	public var mainModel(default, default):DemoModel;

	public function new(mm:DemoModel) {
		mainModel = mm;
	}
}