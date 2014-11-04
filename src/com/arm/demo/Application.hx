package com.arm.demo;

import fluid.Fluid;
import arm.mvc.model.Model;
import arm.mvc.view.View;
import arm.mvc.controller.Controller;
import arm.mvc.comms.CommsController;

class Application extends Fluid {

	public var model(default, default):Model;
	public var view(default, default):View;
	public var controller(default, default):Controller;
	public var comms(default, default):CommsController;

	public function new() {
		super();
	}
}