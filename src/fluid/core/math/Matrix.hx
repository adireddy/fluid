package fluid.core.math;

class Matrix {

	public static var IDENTITY = new Matrix();
	public static var TEMP_MATRIX = new Matrix();

	public var a:Float;
	public var b:Float;
	public var c:Float;
	public var d:Float;
	public var tx:Float;
	public var ty:Float;
	public var array:Array<Float>;

	public function new():Void {
		this.a = 1;
		this.b = 0;
		this.c = 0;
		this.d = 1;
		this.tx = 0;
		this.ty = 0;
	}

	public function fromArray(array:Array<Float>):Void {
		this.a = array[0];
		this.b = array[1];
		this.c = array[3];
		this.d = array[4];
		this.tx = array[2];
		this.ty = array[5];
	}

	public function set(a:Float, b:Float, c:Float, d:Float, tx:Float, ty:Float):Matrix {
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;
		this.tx = tx;
		this.ty = ty;

		return this;
	}

	public function toArray(transpose:Bool, out:Array<Float>):Array<Float> {
		if (this.array == null) this.array = [];

		var array = (out == null) ? this.array : out;

		if (transpose) {
			array[0] = this.a;
			array[1] = this.b;
			array[2] = 0;
			array[3] = this.c;
			array[4] = this.d;
			array[5] = 0;
			array[6] = this.tx;
			array[7] = this.ty;
			array[8] = 1;
		}
		else {
			array[0] = this.a;
			array[1] = this.c;
			array[2] = this.tx;
			array[3] = this.b;
			array[4] = this.d;
			array[5] = this.ty;
			array[6] = 0;
			array[7] = 0;
			array[8] = 1;
		}

		return array;
	}

	public function apply(pos:Point, ?newPos:Point):Point {
		if (newPos == null) newPos = new Point();

		var x = pos.x;
		var y = pos.y;

		newPos.x = this.a * x + this.c * y + this.tx;
		newPos.y = this.b * x + this.d * y + this.ty;

		return newPos;
	}

	public function applyInverse(pos:Point, ?newPos:Point):Point {
		if (newPos == null) newPos = new Point();

		var id = 1 / (this.a * this.d + this.c * -this.b);

		var x = pos.x;
		var y = pos.y;

		newPos.x = this.d * id * x + -this.c * id * y + (this.ty * this.c - this.tx * this.d) * id;
		newPos.y = this.a * id * y + -this.b * id * x + (-this.ty * this.a + this.tx * this.b) * id;

		return newPos;
	}

	public function translate(x:Float, y:Float):Matrix {
		this.tx += x;
		this.ty += y;

		return this;
	}

	public function scale(x:Float, y:Float):Matrix {
		this.a *= x;
		this.d *= y;
		this.c *= x;
		this.b *= y;
		this.tx *= x;
		this.ty *= y;

		return this;
	}

	public function rotate(angle:Float):Matrix {
		var cos = Math.cos(angle);
		var sin = Math.sin(angle);

		var a1 = this.a;
		var c1 = this.c;
		var tx1 = this.tx;

		this.a = a1 * cos - this.b * sin;
		this.b = a1 * sin + this.b * cos;
		this.c = c1 * cos - this.d * sin;
		this.d = c1 * sin + this.d * cos;
		this.tx = tx1 * cos - this.ty * sin;
		this.ty = tx1 * sin + this.ty * cos;

		return this;
	}

	public function append(matrix:Matrix):Matrix {
		var a1 = this.a;
		var b1 = this.b;
		var c1 = this.c;
		var d1 = this.d;

		this.a = matrix.a * a1 + matrix.b * c1;
		this.b = matrix.a * b1 + matrix.b * d1;
		this.c = matrix.c * a1 + matrix.d * c1;
		this.d = matrix.c * b1 + matrix.d * d1;

		this.tx = matrix.tx * a1 + matrix.ty * c1 + this.tx;
		this.ty = matrix.tx * b1 + matrix.ty * d1 + this.ty;

		return this;

	}

	public function setTransform(x:Float, y:Float, pivotX:Float, pivotY:Float, scaleX:Float, scaleY:Float, rotation:Float, skewX:Float, skewY:Float):Matrix {
		var a, b, c, d, sr, cr, cy, sy, nsx, cx;

		sr = Math.sin(rotation);
		cr = Math.cos(rotation);
		cy = Math.cos(skewY);
		sy = Math.sin(skewY);
		nsx = -Math.sin(skewX);
		cx = Math.cos(skewX);

		a = cr * scaleX;
		b = sr * scaleX;
		c = -sr * scaleY;
		d = cr * scaleY;

		this.a = cy * a + sy * c;
		this.b = cy * b + sy * d;
		this.c = nsx * a + cx * c;
		this.d = nsx * b + cx * d;

		this.tx = x + ( pivotX * a + pivotY * c );
		this.ty = y + ( pivotX * b + pivotY * d );

		return this;
	}

	public function prepend(matrix:Matrix):Matrix {
		var tx1 = this.tx;

		if (matrix.a != 1 || matrix.b != 0 || matrix.c != 0 || matrix.d != 1) {
			var a1 = this.a;
			var c1 = this.c;
			this.a = a1 * matrix.a + this.b * matrix.c;
			this.b = a1 * matrix.b + this.b * matrix.d;
			this.c = c1 * matrix.a + this.d * matrix.c;
			this.d = c1 * matrix.b + this.d * matrix.d;
		}

		this.tx = tx1 * matrix.a + this.ty * matrix.c + matrix.tx;
		this.ty = tx1 * matrix.b + this.ty * matrix.d + matrix.ty;

		return this;
	}

	public function identity():Matrix {
		this.a = 1;
		this.b = 0;
		this.c = 0;
		this.d = 1;
		this.tx = 0;
		this.ty = 0;

		return this;
	}

	public function invert():Matrix {
		var a1 = this.a;
		var b1 = this.b;
		var c1 = this.c;
		var d1 = this.d;
		var tx1 = this.tx;
		var n = a1 * d1 - b1 * c1;

		this.a = d1 / n;
		this.b = -b1 / n;
		this.c = -c1 / n;
		this.d = a1 / n;
		this.tx = (c1 * this.ty - d1 * tx1) / n;
		this.ty = -(a1 * this.ty - b1 * tx1) / n;

		return this;
	}

	public function clone():Matrix {
		var matrix = new Matrix();
		matrix.a = this.a;
		matrix.b = this.b;
		matrix.c = this.c;
		matrix.d = this.d;
		matrix.tx = this.tx;
		matrix.ty = this.ty;

		return matrix;
	}

	public function copy(matrix:Matrix):Matrix {
		matrix.a = this.a;
		matrix.b = this.b;
		matrix.c = this.c;
		matrix.d = this.d;
		matrix.tx = this.tx;
		matrix.ty = this.ty;

		return matrix;
	}
}