package ;

import fluid.display.FluidSprite;

class Bunny extends FluidSprite {

	public var speedX(default, default):Float;
	public var speedY(default, default):Float;
	public var scaleSpeed(default, default):Float;
	public var rotationSpeed(default, default):Float;

	public function new(texture) {
		super(texture);
	}
}
