package fluid.core.math;

class Point {

	public var x:Float;
	public var y:Float;

	public function new(?x:Float = 0, ?y:Float = 0) {
		this.x = x;
		this.y = y;
	}

	public function clone():Point {
		return new Point(this.x, this.y);
	}

	public function copy(p:Point) {
		this.set(p.x, p.y);
	}

	public function equals(p:Point):Bool {
		return (p.x == this.x) && (p.y == this.y);
	}

	public function set(?x:Float = 0, ?y:Float):Void {
		this.x = x;
		this.y = (y != null) ? y : this.x;
	}
}