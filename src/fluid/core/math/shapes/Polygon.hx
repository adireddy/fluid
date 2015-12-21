package fluid.core.math.shapes;

class Polygon {

	public var points:Array<Point>;
	public var type:Int;

	public function new(points:Array<Point>):Void {
		this.points = points;
		this.type = Fluid.SHAPES.POLY;
	}

	public function clone():Polygon {
		return new Polygon(this.points.slice());
	}

	public function contains(x:Float, y:Float):Bool {
		var inside = false;

		var length = this.points.length / 2;
		var j = length - 1;
		for (i in 0 ... length) {
			var xi = this.points[i * 2];
			var yi = this.points[i * 2 + 1];
			var xj = this.points[j * 2];
			var yj = this.points[j * 2 + 1];
			var intersect = ((yi > y) != (yj > y)) && (x < (xj - xi) * (y - yi) / (yj - yi) + xi);
			if (intersect) inside = !inside;
			j = i;
		}

		return inside;
	}
}