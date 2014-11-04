package fluid.geom;

class FluidRectangle extends #if js pixi.core.Rectangle #else openfl.geom.Rectangle #end {

	#if js
		public var bottom(get, set):Float;
		public var bottomRight(get, set):pixi.core.Point;
		public var left(get, set):Float;
		public var right(get, set):Float;
		public var size(get, set):pixi.core.Point;
		public var top(get, set):Float;
		public var topLeft(get, set):pixi.core.Point;

		@:noCompletion private function get_bottom():Float { return y + height; }
		@:noCompletion private function set_bottom(b:Float):Float { height = b - y; return b; }
		@:noCompletion private function get_bottomRight():pixi.core.Point { return new pixi.core.Point(x + width, y + height); }
		@:noCompletion private function set_bottomRight(p:pixi.core.Point):pixi.core.Point { width = p.x - x; height = p.y - y; return p.clone (); }
		@:noCompletion private function get_left():Float { return x; }
		@:noCompletion private function set_left(l:Float):Float { width -= l - x; x = l; return l; }
		@:noCompletion private function get_right():Float { return x + width; }
		@:noCompletion private function set_right(r:Float):Float { width = r - x; return r; }
		@:noCompletion private function get_size():pixi.core.Point { return new pixi.core.Point(width, height); }
		@:noCompletion private function set_size(p:pixi.core.Point):pixi.core.Point { width = p.x; height = p.y; return p.clone (); }
		@:noCompletion private function get_top():Float { return y; }
		@:noCompletion private function set_top(t:Float):Float { height -= t - y; y = t; return t; }
		@:noCompletion private function get_topLeft():pixi.core.Point { return new pixi.core.Point(x, y); }
		@:noCompletion private function set_topLeft(p:pixi.core.Point):pixi.core.Point { x = p.x; y = p.y; return p.clone (); }

		public function containsPoint(point:pixi.core.Point):Bool { return contains(point.x, point.y); }

		public function containsRect(rect:FluidRectangle):Bool {
			if (rect.width <= 0 || rect.height <= 0) {
				return rect.x > x && rect.y > y && rect.right < right && rect.bottom < bottom;
			}
			else {
				return rect.x >= x && rect.y >= y && rect.right <= right && rect.bottom <= bottom;
			}
		}

		public function copyFrom(sourceRect:pixi.core.Rectangle):Void {
			x = sourceRect.x;
			y = sourceRect.y;
			width = sourceRect.width;
			height = sourceRect.height;
		}

		public function equals(toCompare:pixi.core.Rectangle):Bool {
			return toCompare != null && x == toCompare.x && y == toCompare.y && width == toCompare.width && height == toCompare.height;
		}

		public function inflate(dx:Float, dy:Float):Void {
			x -= dx; width += dx * 2;
			y -= dy; height += dy * 2;
		}

		public function inflatePoint(point:pixi.core.Point):Void { inflate(point.x, point.y); }
		public function isEmpty():Bool { return (width <= 0 || height <= 0); }
		public function offset(dx:Float, dy:Float):Void { x += dx; y += dy; }
		public function offsetPoint(point:FluidPoint):Void { x += point.x; y += point.y; }
		public function setEmpty():Void { x = y = width = height = 0; }

		public function setTo(xa:Float, ya:Float, widtha:Float, heighta:Float):Void {
			x = xa;
			y = ya;
			width = widtha;
			height = heighta;
		}

		public function transform(m:pixi.core.Matrix):FluidRectangle {
			var tx0 = m.a * x + m.c * y;
			var tx1 = tx0;
			var ty0 = m.b * x + m.d * y;
			var ty1 = tx0;

			var tx = m.a * (x + width) + m.c * y;
			var ty = m.b * (x + width) + m.d * y;

			if (tx < tx0) tx0 = tx;
			if (ty < ty0) ty0 = ty;
			if (tx > tx1) tx1 = tx;
			if (ty > ty1) ty1 = ty;

			tx = m.a * (x + width) + m.c * (y + height);
			ty = m.b * (x + width) + m.d * (y + height);

			if (tx < tx0) tx0 = tx;
			if (ty < ty0) ty0 = ty;
			if (tx > tx1) tx1 = tx;
			if (ty > ty1) ty1 = ty;

			tx = m.a * x + m.c * (y + height);
			ty = m.b * x + m.d * (y + height);

			if (tx < tx0) tx0 = tx;
			if (ty < ty0) ty0 = ty;
			if (tx > tx1) tx1 = tx;
			if (ty > ty1) ty1 = ty;

			return new FluidRectangle(tx0 + m.tx, ty0 + m.ty, tx1 - tx0, ty1 - ty0);
		}
	#end

	public function new(x:Float, y:Float, width:Float, height:Float) {
		super(x, y, width, height);
	}
}