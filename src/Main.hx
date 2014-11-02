package ;

import fluid.text.FluidText;
import fluid.StageProperties;
import fluid.display.FluidSprite;
import fluid.FluidAssets;
import fluid.Fluid;
import fluid.display.FluidGraphics;

class Main extends Fluid {

	var _bunnyTexture:Dynamic;
	var _sprites:Array<Bunny>;

	var _maxX:Float;
	var _maxY:Float;
	var _minX:Float;
	var _minY:Float;

	var _count:Int = 0;
	var _countText:FluidText;

	public function new() {
		super();
		skipFrame = true;
		_minX = _minY = 0;
		_maxX = StageProperties.screenWidth;
		_maxY = StageProperties.screenHeight;
		_sprites = [];

		/*var _background = new FluidGraphics();
		_background.clear();
		_background.beginFill(0x003366);
		_background.drawRoundedRect(100, 100, 200, 100, 10);
		_background.endFill();
		container.addChild(_background);*/

		_countText = new FluidText("BUNNIES: 0");
		container.addChild(_countText);

		_bunnyTexture = FluidAssets.getImage("assets/bunny.png");
		_showStats();

		//stage.addEventListener("touchstart", _onTouchStart, true);
		//stage.addEventListener("touchend", _onTouchEnd, true);
		mouseDown = _onMouseDown;
	}

	function _onMouseDown(evt) {
		_count += 1000;
		_countText.setText("BUNNIES: " + _count);
		_addBunnys(1000);
	}

	function _addBunnys(count:Int) {
		for (i in 0...count) {
			var bunny:Bunny = new Bunny(_bunnyTexture);
			container.addChild(bunny);
			bunny.x = Std.random(Std.int(StageProperties.screenWidth));
			bunny.y = Std.random(Std.int(StageProperties.screenHeight));
			//bunny.anchor.x = 0.5;
			//bunny.anchor.y = 0.5;
			bunny.speedX = Math.random() * 16 + 2;
			bunny.speedY = (Math.random() * 16) - 10;
			bunny.rotationSpeed = Math.random() / 50 + 0.01;
			bunny.scaleSpeed = Math.random() / 50 + 0.01;
			_sprites.push(bunny);
		}
	}

	override public function _update(elapsedTime) {
		if(_sprites.length > 0) {
			for (i in 0..._sprites.length) {
				var bunny:Bunny = _sprites[i];
				bunny.x += bunny.speedX;
				bunny.y += bunny.speedY;
				bunny.speedY += 4.75;

				if (bunny.x > _maxX) {
					bunny.speedX *= -1;
					bunny.x = _maxX;
				}
				else if (bunny.x < _minX) {
					bunny.speedX *= -1;
					bunny.x = _minX;
				}

				if (bunny.y > _maxY) {
					bunny.speedY *= -0.90;
					bunny.y = _maxY;
					if (Math.random() > 0.5) bunny.speedY -= Math.random() * 6;
				}
				else if (bunny.y < _minY) {
					bunny.speedY = 0;
					bunny.y = _minY;
				}

				/*if(_isScale) {
					bunny.scale.x += bunny.scaleSpeed;
					bunny.scale.y += bunny.scaleSpeed;
					if (bunny.scale.x > 2) bunny.scaleSpeed = -bunny.scaleSpeed;
					else if(bunny.scale.x < 0.01) bunny.scaleSpeed = -bunny.scaleSpeed;
				}

				if (_isRotation) bunny.rotation += bunny.rotationSpeed;*/
			}
		}
	}

	#if js
	static function main() {
		new Main();
	}
	#end
}
