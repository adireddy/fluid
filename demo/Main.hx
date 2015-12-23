package demo;

import fluid.core.textures.Texture;
import fluid.core.sprites.Sprite;
import fluid.plugins.app.Application;

class Main extends Application {

	var _bunny:Sprite;

	public function new() {
		super();
		backgroundColor = 0x00FFFF;
		super.start();

		_bunny = new Sprite(Texture.fromImage("bunny.png"));
		//_bunny.anchor.set(0.5);
		//_bunny.position.set(400, 300);

		stage.addChild(_bunny);

	}

	static function main() {
		new Main();
	}
}