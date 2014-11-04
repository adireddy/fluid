package com.arm.demo;

import com.arm.demo.comms.DemoCommsController;
import com.arm.demo.controller.DemoController;
import com.arm.demo.model.DemoModel;
import com.arm.demo.view.DemoView;
import fluid.Fluid;

class Application extends Fluid {

	public var model(default, default):DemoModel;
	public var view(default, default):DemoView;
	public var controller(default, default):DemoController;
	public var comms(default, default):DemoCommsController;

	public function new() {
		super();
	}
}