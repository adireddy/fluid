package fluid.core.math.shapes;

class Ellipse {

	public var x:Float;
	public var y:Float;
	public var width:Float;
	public var height:Float;
	public var type:Int;

	public function new(?x:Float = 0, ?y:Float = 0, ?width:Float = 0, ?height:Float = 0):Void {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		this.type = Fluid.SHAPES.ELIP;
	}

	public function clone():Ellipse {
		return new Ellipse(this.x, this.y, this.width, this.height);
	}

	public function contains(x:Float, y:Float):Bool {
		if (this.width <= 0 || this.height <= 0) return false;

		var normx = ((x - this.x) / this.width);
		var normy = ((y - this.y) / this.height);

		normx *= normx;
		normy *= normy;

		return (normx + normy <= 1);
	}

	public function getBounds():Rectangle {
		return new Rectangle(this.x - this.width, this.y - this.height, this.width, this.height);
	}
}