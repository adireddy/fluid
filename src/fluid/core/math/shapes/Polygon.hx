package fluid.core.math.shapes;

class Polygon {

	public var points:Array<Float>;
	public var type:Int;

	var _points:Array<Point>;

	public function new(points:Array<Point>):Void {
		_points = points;
		var p = [];
		for (i in 0... points.length) {
			p.push(points[i].x);
			p.push(points[i].y);
		}
		this.points = p;
		this.type = Fluid.SHAPES.POLY;
	}

	public function clone():Polygon {
		return new Polygon(this._points);
	}

	public function contains(x:Float, y:Float):Bool {
		var inside = false;

		var length = Std.int(this.points.length / 2);
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