package fluid.geom;

class FluidPoint extends #if js pixi.core.Point #else openfl.geom.Point #end {

	#if js
		public var length(get, null):Float;

		@:noCompletion private function get_length():Float { return Math.sqrt(x * x + y * y); }

		public function add(v:FluidPoint) { return new FluidPoint(v.x + x, v.y + y); }
		public function equals(toCompare:FluidPoint):Bool { return toCompare != null && toCompare.x == x && toCompare.y == y; }

		public static function interpolate(pt1:FluidPoint, pt2:FluidPoint, f:Float):FluidPoint { return new FluidPoint(pt2.x + f * (pt1.x - pt2.x), pt2.y + f * (pt1.y - pt2.y)); }
		public static function distance(pt1:FluidPoint, pt2:FluidPoint):Float {
			var dx = pt1.x - pt2.x;
			var dy = pt1.y - pt2.y;
			return Math.sqrt (dx * dx + dy * dy);
		}

		public function normalize(thickness:Float):Void {
			if (x == 0 && y == 0) return;
			else {
				var norm = thickness / Math.sqrt (x * x + y * y);
				x *= norm;
				y *= norm;
			}
		}

		public function offset(dx:Float, dy:Float):Void { x += dx; y += dy; }
		public static function polar(len:Float, angle:Float):FluidPoint { return new FluidPoint(len * Math.cos(angle), len * Math.sin(angle)); }
		inline public function setTo(xa:Float, ya:Float):Void { x = xa; y = ya; }
		public function subtract(v:FluidPoint):FluidPoint { return new FluidPoint(x - v.x, y - v.y); }
		public function toString():String { return "(x=" + x + ", y=" + y + ")"; }
	#end

	public function new(x:Float = 0, y:Float = 0) {
		super(x, y);
	}
}