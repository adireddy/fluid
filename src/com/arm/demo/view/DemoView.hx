package com.arm.demo.view;

import arm.mvc.view.View;

import fluid.display.FluidStage;
import fluid.display.FluidDisplayObjectContainer;

class DemoView extends View {

	//public var gameStage(default, default):FluidStage;
	//public var gameContainer(default, default):FluidDisplayObjectContainer;

	public function new(stage, ?container) {
		super(stage, container);
		//gameStage = cast(stage, FluidStage);
		//gameContainer = cast(container, FluidDisplayObjectContainer);
	}

	/*override function get_stage():FluidStage {
		return cast(stage, FluidStage);
	}

	override function get_container():FluidDisplayObjectContainer {
		return cast(container, FluidDisplayObjectContainer);
	}*/
}