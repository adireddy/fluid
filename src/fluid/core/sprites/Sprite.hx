package fluid.core.sprites;

import fluid.core.math.shapes.Rectangle;
import fluid.core.math.Matrix;
import fluid.core.renderers.webgl.WebGLRenderer;
import js.Error;
import fluid.core.utils.Utils;
import fluid.core.math.Point;
import fluid.core.textures.Texture;
import fluid.core.display.Container;

class Sprite extends Container {

	public var _texture:Texture;

	public var anchor:Point;
	public var texture(default, set):Texture;
	public var tint:Int;
	public var blendMode:Int;
	public var shader:Dynamic;

	public var tileScale:Dynamic;

	var cachedTint:Int;
	var tempPoint = new Point();

	public function new(texture:Texture) {
		super();

		this.anchor = new Point();
		this._texture = null;
		this._width = 0;
		this._height = 0;
		this.tint = 0xFFFFFF;
		this.blendMode = Fluid.BLEND_MODES.NORMAL;
		this.shader = null;
		this.cachedTint = 0xFFFFFF;
		this.texture = (texture != null) ? texture : Texture.EMPTY;
	}

	override function set_width(value:Float):Float {
		var sign = Utils.sign(this.scale.x);
		if (sign == null) sign = 1;
		this.scale.x = sign * value / this.texture.frame.width;
		return this._width = value;
	}

	override function get_width():Float {
		return Math.abs(this.scale.x) * this.texture.frame.width;
	}

	override function set_height(value:Float):Float {
		var sign = Utils.sign(this.scale.y);
		if (sign == null) sign = 1;
		this.scale.y = sign * value / this.texture.frame.height;
		return this._height = value;
	}

	override function get_height():Float {
		return Math.abs(this.scale.y) * this.texture.frame.height;
	}

	function set_texture(value:Texture):Texture {
		if (this.texture == value) return value;
		this.cachedTint = 0xFFFFFF;
		this.texture = value;

		if (value != null) {
			if (value.baseTexture.hasLoaded) this._onTextureUpdate(value);
			else value.updated.addOnce(this._onTextureUpdate);
		}

		return value;
	}

	function _onTextureUpdate(txt:Texture) {
		this.scale.x = Utils.sign(this.scale.x) * this._width / this.texture.frame.width;
		this.scale.y = Utils.sign(this.scale.y) * this._height / this.texture.frame.height;
	}

	override public function _renderWebGL(renderer:WebGLRenderer):Void {
		renderer.setObjectRenderer(renderer.plugins.get("sprite"));
		renderer.plugins.get("sprite").render(this);
	}

	override public function getBounds(?matrix:Matrix):Rectangle {
		if (this._currentBounds == null) {
			var width = this.texture.frame.width;
			var height = this.texture.frame.height;

			var w0 = width * (1 - this.anchor.x);
			var w1 = width * -this.anchor.x;

			var h0 = height * (1 - this.anchor.y);
			var h1 = height * -this.anchor.y;

			var worldTransform = matrix;
			if (worldTransform == null) worldTransform = this.worldTransform;

			var a = worldTransform.a;
			var b = worldTransform.b;
			var c = worldTransform.c;
			var d = worldTransform.d;
			var tx = worldTransform.tx;
			var ty = worldTransform.ty;

			var minX,
			maxX,
			minY,
			maxY;

			var x1 = a * w1 + c * h1 + tx;
			var y1 = d * h1 + b * w1 + ty;

			var x2 = a * w0 + c * h1 + tx;
			var y2 = d * h1 + b * w0 + ty;

			var x3 = a * w0 + c * h0 + tx;
			var y3 = d * h0 + b * w0 + ty;

			var x4 = a * w1 + c * h0 + tx;
			var y4 = d * h0 + b * w1 + ty;

			minX = x1;
			minX = x2 < minX ? x2 : minX;
			minX = x3 < minX ? x3 : minX;
			minX = x4 < minX ? x4 : minX;

			minY = y1;
			minY = y2 < minY ? y2 : minY;
			minY = y3 < minY ? y3 : minY;
			minY = y4 < minY ? y4 : minY;

			maxX = x1;
			maxX = x2 > maxX ? x2 : maxX;
			maxX = x3 > maxX ? x3 : maxX;
			maxX = x4 > maxX ? x4 : maxX;

			maxY = y1;
			maxY = y2 > maxY ? y2 : maxY;
			maxY = y3 > maxY ? y3 : maxY;
			maxY = y4 > maxY ? y4 : maxY;

			if (this.children.length > 0) {
				var childBounds = this.containerGetBounds();

				w0 = childBounds.x;
				w1 = childBounds.x + childBounds.width;
				h0 = childBounds.y;
				h1 = childBounds.y + childBounds.height;

				minX = (minX < w0) ? minX : w0;
				minY = (minY < h0) ? minY : h0;

				maxX = (maxX > w1) ? maxX : w1;
				maxY = (maxY > h1) ? maxY : h1;
			}

			var bounds = this._bounds;

			bounds.x = minX;
			bounds.width = maxX - minX;

			bounds.y = minY;
			bounds.height = maxY - minY;

			this._currentBounds = bounds;
		}

		return this._currentBounds;
	}

	override public function getLocalBounds():Rectangle {
		this._bounds.x = -this.texture.frame.width * this.anchor.x;
		this._bounds.y = -this.texture.frame.height * this.anchor.y;
		this._bounds.width = this.texture.frame.width;
		this._bounds.height = this.texture.frame.height;
		return this._bounds;
	}

	public function containsPoint(point:Point):Bool {
		this.worldTransform.applyInverse(point, tempPoint);

		var width = this.texture.frame.width;
		var height = this.texture.frame.height;
		var x1 = -width * this.anchor.x;
		var y1;

		if (tempPoint.x > x1 && tempPoint.x < x1 + width) {
			y1 = -height * this.anchor.y;
			if (tempPoint.y > y1 && tempPoint.y < y1 + height) return true;
		}

		return false;
	}

	override public function destroy(?destroyTexture:Bool = false, ?destroyBaseTexture:Bool = false) {
		super.destroy();
		this.anchor = null;
		if (destroyTexture) this.texture.destroy(destroyBaseTexture);
		this.texture = null;
		this.shader = null;
	}

	public static function fromFrame(frameId:String):Sprite {
		var texture = Utils.TextureCache.get(frameId);
		if (texture == null) throw new Error('The frameId "' + frameId + '" does not exist in the texture cache');
		return new Sprite(texture);
	}

	public static function fromImage(imageId:String, ?crossorigin:Bool, ?scaleMode:Int):Sprite {
		return new Sprite(Texture.fromImage(imageId, crossorigin, scaleMode));
	}
}