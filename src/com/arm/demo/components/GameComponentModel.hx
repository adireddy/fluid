package com.arm.demo.components;

import com.arm.demo.model.DemoModel;
import arm.mvc.components.ComponentModel;

class GameComponentModel extends ComponentModel {

	public var gameMainModel(default, default):DemoModel;

	public function new(mm) {
		super(mm);
		gameMainModel = cast(mainModel, DemoModel);
	}
}