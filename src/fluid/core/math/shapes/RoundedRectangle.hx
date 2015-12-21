package fluid.core.math.shapes;

class RoundedRectangle {

	public var x:Float;
	public var y:Float;
	public var width:Float;
	public var height:Float;
	public var radius:Float;
	public var type:Int;

	public function new(?x:Float = 0, ?y:Float = 0, ?width:Float = 0, ?height:Float = 0, ?radius:Float = 20):Void {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		this.radius = radius;
		this.type = Fluid.SHAPES.RREC;
	}

	public function clone():RoundedRectangle {
		return new RoundedRectangle(this.x, this.y, this.width, this.height, this.radius);
	}

	public function contains(x:Float, y:Float):Bool {
		if (this.width <= 0 || this.height <= 0) return false;
		return (x >= this.x && x <= this.x + this.width) && (y >= this.y && y <= this.y + this.height);
	}
}