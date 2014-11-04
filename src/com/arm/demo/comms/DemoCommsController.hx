package com.arm.demo.comms;

import msignal.Signal;

class DemoCommsController {

	public var success:Signal2<String, String> = new Signal2(String, String);
	public var error:Signal1<String> = new Signal1(String);

	public function new() {

	}

	public function reset():Void {
		success.removeAll();
		error.removeAll();
		success = null;
		error = null;
	}
}