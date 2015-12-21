package fluid.core.math.shapes;

class Circle {

	public var x:Float;
	public var y:Float;
	public var radius:Float;
	public var type:Int;

	public function new(?x:Float = 0, ?y:Float = 0, ?radius:Float = 0):Void {
		this.x = x;
		this.y = y;
		this.radius = radius;
		this.type = Fluid.SHAPES.CIRC;
	}

	public function clone():Circle {
		return new Circle(this.x, this.y, this.radius);
	}

	public function contains(x:Float, y:Float):Bool {
		if (this.radius <= 0) return false;

		var dx = (this.x - x);
		var dy = (this.y - y);
		var r2 = this.radius * this.radius;

		dx *= dx;
		dy *= dy;

		return (dx + dy <= r2);
	}

	public function getBounds():Rectangle {
		return new Rectangle(this.x - this.radius, this.y - this.radius, this.radius * 2, this.radius * 2);
	}
}