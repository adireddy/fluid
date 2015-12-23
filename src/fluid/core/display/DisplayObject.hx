package fluid.core.display;

import msignal.Signal.Signal1;
import fluid.core.textures.RenderTexture;
import js.Error;
import fluid.core.renderers.webgl.WebGLRenderer;
import fluid.core.textures.Texture;
import fluid.core.math.Matrix;
import fluid.core.math.shapes.Rectangle;
import fluid.core.math.Point;

class DisplayObject {

	public var added:Signal1<DisplayObject>;
	public var removed:Signal1<DisplayObject>;

	public var name:String;
	public var cacheAsBitmap:Bool;
	public var position:Point;
	public var scale:Point;
	public var pivot:Point;
	public var skew:Point;
	public var rotation:Float;
	public var alpha:Float;
	public var visible:Bool;
	public var renderable:Bool;
	public var parent:Container;
	public var worldAlpha:Float;
	public var worldTransform:Matrix;
	public var filterArea:Rectangle;
	public var x:Float;
	public var y:Float;
	public var worldVisible:Bool;
	public var mask:Dynamic;
	public var filters(get, set):Array<Dynamic>;
	public var interactive:Bool;
	public var buttonMode:Bool;
	public var interactiveChildren:Bool;
	public var defaultCursor:String;
	public var hitArea:Dynamic;

	public var displayObjectUpdateTransform:Void -> Void;
	public var containerGetBounds:?Matrix -> Rectangle;

	var _filters:Array<Dynamic>;

	var _sr:Float;
	var _cr:Float;
	var _bounds:Rectangle;
	var _currentBounds:Rectangle;
	var _mask:Dynamic;
	var _tempMatrix:Matrix;
	var _tempDisplayObjectParent:Dynamic = { worldTransform:new Matrix(), worldAlpha:1, children:[] };
	var rotationCache:Float;

	public function new() {
		added = new Signal1(Container);
		removed = new Signal1(Container);

		this.position = new Point();
		this.scale = new Point(1, 1);
		this.pivot = new Point(0, 0);
		this.skew = new Point(0, 0);
		this.rotation = 0;
		this.alpha = 1;
		this.visible = true;
		this.renderable = true;
		this.parent = null;
		this.worldAlpha = 1;
		this.worldTransform = new Matrix();
		this.filterArea = null;
		this._sr = 0;
		this._cr = 1;
		this._bounds = new Rectangle(0, 0, 1, 1);
		this._currentBounds = null;
		this._mask = null;
		_tempMatrix = new Matrix();

		displayObjectUpdateTransform = updateTransform;
		containerGetBounds = getBounds;
	}

	function set_filters(value:Array<Dynamic>):Array<Dynamic> {
		return this._filters = (value != null) ? value.slice(0) : null;
	}

	function get_filters():Array<Dynamic> {
		return (this._filters != null) ? this._filters.slice(0) : null;
	}

	public function getBounds(?matrix:Matrix):Rectangle {
		return Rectangle.EMPTY;
	}

	public function getLocalBounds():Rectangle {
		return this.getBounds(Matrix.IDENTITY);
	}

	public function toGlobal(position:Point):Point {
		if (this.parent == null) {
			this.parent = _tempDisplayObjectParent;
			this.displayObjectUpdateTransform();
			this.parent = null;
		}
		else this.displayObjectUpdateTransform();
		return this.worldTransform.apply(position);
	}

	public function toLocal(position:Point, ?from:DisplayObject, ?point:Point):Point {
		if (from != null) position = from.toGlobal(position);
		if (this.parent == null) {
			this.parent = _tempDisplayObjectParent;
			this.displayObjectUpdateTransform();
			this.parent = null;
		}
		else this.displayObjectUpdateTransform();
		return this.worldTransform.applyInverse(position, point);
	}

	public function updateTransform():Void {
		var pt = this.parent.worldTransform;
		var wt = this.worldTransform;
		var a, b, c, d, tx, ty;

		if (this.skew.x != null || this.skew.y != null) {
			_tempMatrix.setTransform(
				this.position.x,
				this.position.y,
				this.pivot.x,
				this.pivot.y,
				this.scale.x,
				this.scale.y,
				this.rotation,
				this.skew.x,
				this.skew.y
			);

			// now concat the matrix (inlined so that we can avoid using copy)
			wt.a = _tempMatrix.a * pt.a + _tempMatrix.b * pt.c;
			wt.b = _tempMatrix.a * pt.b + _tempMatrix.b * pt.d;
			wt.c = _tempMatrix.c * pt.a + _tempMatrix.d * pt.c;
			wt.d = _tempMatrix.c * pt.b + _tempMatrix.d * pt.d;
			wt.tx = _tempMatrix.tx * pt.a + _tempMatrix.ty * pt.c + pt.tx;
			wt.ty = _tempMatrix.tx * pt.b + _tempMatrix.ty * pt.d + pt.ty;
		}
		else {
			if (this.rotation % Fluid.PI_2 != null) {
				if (this.rotation != this.rotationCache) {
					this.rotationCache = this.rotation;
					this._sr = Math.sin(this.rotation);
					this._cr = Math.cos(this.rotation);
				}

				a = this._cr * this.scale.x;
				b = this._sr * this.scale.x;
				c = -this._sr * this.scale.y;
				d = this._cr * this.scale.y;
				tx = this.position.x;
				ty = this.position.y;

				if (this.pivot.x != null || this.pivot.y != null) {
					tx -= this.pivot.x * a + this.pivot.y * c;
					ty -= this.pivot.x * b + this.pivot.y * d;
				}

				wt.a = a * pt.a + b * pt.c;
				wt.b = a * pt.b + b * pt.d;
				wt.c = c * pt.a + d * pt.c;
				wt.d = c * pt.b + d * pt.d;
				wt.tx = tx * pt.a + ty * pt.c + pt.tx;
				wt.ty = tx * pt.b + ty * pt.d + pt.ty;
			}
			else {
				a = this.scale.x;
				d = this.scale.y;

				tx = this.position.x - this.pivot.x * a;
				ty = this.position.y - this.pivot.y * d;

				wt.a = a * pt.a;
				wt.b = a * pt.b;
				wt.c = d * pt.c;
				wt.d = d * pt.d;
				wt.tx = tx * pt.a + ty * pt.c + pt.tx;
				wt.ty = tx * pt.b + ty * pt.d + pt.ty;
			}
		}

		this.worldAlpha = this.alpha * this.parent.worldAlpha;
		this._currentBounds = null;
	}

	public function renderWebGL(renderer:WebGLRenderer):Void {}

	public function generateTexture(renderer:Dynamic, ?resolution:Float = 1, ?scaleMode:Int = 0):Texture {
		var bounds = this.getLocalBounds();
		if (bounds.width == null) bounds.width = 0;
		if (bounds.height == null) bounds.height = 0;

		var renderTexture = new RenderTexture(renderer, bounds.width, bounds.height, scaleMode, resolution);

		_tempMatrix.tx = -bounds.x;
		_tempMatrix.ty = -bounds.y;

		renderTexture.render(this, _tempMatrix);

		return renderTexture;
	}

	public function setParent(container):Dynamic {
		if (container == null || container.addChild == null) {
			throw new Error("setParent: Argument must be a Container");
		}
		container.addChild(this);
		return container;
	}

	public function setTransform(?x:Int = 0, ?y:Int = 0, ?scaleX:Float = 1, ?scaleY:Float = 1, ?rotation:Float = 0, ?skewX:Float = 0, ?skewY:Float = 0, ?pivotX:Float = 0, ?pivotY:Float = 0):DisplayObject {
		this.position.x = x;
		this.position.y = y;
		this.scale.x = scaleX;
		this.scale.y = scaleY;
		this.rotation = rotation;
		this.skew.x = skewX;
		this.skew.y = skewY;
		this.pivot.x = pivotX;
		this.pivot.y = pivotY;
		return this;
	}

	public function destroy(?destroyTexture:Bool = false, ?destroyBaseTexture:Bool = false):Void {
		this.position = null;
		this.scale = null;
		this.pivot = null;
		this.skew = null;

		this.parent = null;

		this._bounds = null;
		this._currentBounds = null;
		this._mask = null;

		this.worldTransform = null;
		this.filterArea = null;
	}
}