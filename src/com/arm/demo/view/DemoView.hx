package com.arm.demo.view;

import fluid.display.FluidSprite;

class DemoView {

	@:isVar public var container(get, set):FluidSprite;

	public function new(container:FluidSprite) {
		this.container = container;
	}

	private function get_container():FluidSprite {
		return container;
	}

	private function set_container(container):FluidSprite {
		return this.container = container;
	}

	public function reset():Void {
		container = null;
	}
}