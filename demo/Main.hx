package demo;

import fluid.plugins.app.Application;

class Main extends Application {

	public function new() {
		super();
		backgroundColor = 0x00FF00;
		super.start();
	}

	static function main() {
		new Main();
	}
}