package fluid.core.textures;

import js.html.Image;
import msignal.Signal.Signal1;
import fluid.core.utils.Utils;

class BaseTexture {

	public var uid:Int;
	public var resolution:Float;
	public var width:Int;
	public var height:Int;
	public var realWidth:Int;
	public var realHeight:Int;
	public var scaleMode:Int;
	public var hasLoaded:Bool;
	public var isLoading:Bool;
	public var isPowerOfTwo:Bool;
	public var source:Dynamic;
	public var premultipliedAlpha:Bool;
	public var imageUrl:String;
	public var mipmap:Bool;

	public var _glTextures:Map<Int, js.html.webgl.Texture>;

	public var loaded:Signal1<BaseTexture>;
	public var error:Signal1<BaseTexture>;
	public var updated:Signal1<BaseTexture>;
	public var disposed:Signal1<Dynamic>;

	public function new(source:Dynamic, ?scaleMode:Int = 0, ?resolution:Float = 1) {
		this.uid = Utils.uid();
		this.resolution = resolution;
		this.width = 100;
		this.height = 100;
		this.realWidth = 100;
		this.realHeight = 100;
		this.scaleMode = scaleMode;
		this.hasLoaded = false;
		this.isLoading = false;
		this.source = null;
		this.premultipliedAlpha = true;
		this.imageUrl = null;
		this.isPowerOfTwo = false;
		this.mipmap = false;
		this._glTextures = new Map();

		loaded = new Signal1(BaseTexture);
		error = new Signal1(BaseTexture);
		updated = new Signal1(BaseTexture);
		disposed = new Signal1(BaseTexture);

		if (source != null) this.loadSource(source);
	}

	public function update():Void {
		this.realWidth = (this.source.naturalWidth != null) ? this.source.naturalWidth : this.source.width;
		this.realHeight = (this.source.naturalHeight != null) ? this.source.naturalHeight : this.source.height;

		this.width = Std.int(this.realWidth / this.resolution);
		this.height = Std.int(this.realHeight / this.resolution);

		this.isPowerOfTwo = Utils.isPowerOfTwo(this.realWidth, this.realHeight);

		updated.dispatch(this);
	}

	public function destroy():Void {
		if (this.imageUrl != null) {
			Utils.BaseTextureCache.set(this.imageUrl, null);
			Utils.TextureCache.set(this.imageUrl, null);
			this.imageUrl = null;
		}
		else if (this.source && this.source._pixiId) {
			Utils.BaseTextureCache.set(this.source._pixiId, null);
		}

		this.source = null;
		this.dispose();
	}

	public function dispose():Void {
		disposed.dispatch(this);
		this._glTextures = null;
	}

	public function loadSource(source:Dynamic):Void {
		var wasLoading = this.isLoading;
		this.hasLoaded = false;
		this.isLoading = false;

		if (wasLoading && this.source != null) {
			this.source.onload = null;
			this.source.onerror = null;
		}

		this.source = source;

		// Apply source if loaded. Otherwise setup appropriate loading monitors.
		if ((this.source.complete != null || this.source.getContext != null) && this.source.width != null && this.source.height != null) {
			this._sourceLoaded();
		}
		else if (source.getContext != null) {
			this.isLoading = true;
			var scope = this;

			source.onload = function() {
				source.onload = null;
				source.onerror = null;

				if (!scope.isLoading) return;

				scope.isLoading = false;
				scope._sourceLoaded();
				loaded.dispatch(scope);
			};

			source.onerror = function() {
				source.onload = null;
				source.onerror = null;

				if (!scope.isLoading) return;

				scope.isLoading = false;
				error.dispatch(scope);
			};

			if (source.complete != null && source.src != null) {
				this.isLoading = false;
				source.onload = null;
				source.onerror = null;

				if (source.width && source.height) {
					this._sourceLoaded();
					if (wasLoading) loaded.dispatch(this);
				}
				else {
					if (wasLoading) error.dispatch(this);
				}
			}
		}
	}

	function _sourceLoaded() {
		this.hasLoaded = true;
		this.update();
	}

	public function updateSourceImage(newSrc:String):Void {
		this.source.src = newSrc;
		this.loadSource(this.source);
	}

	public static function fromImage(imageUrl:String, ?crossorigin:Bool, ?scaleMode:Int = 0):BaseTexture {
		var baseTexture:BaseTexture = Utils.BaseTextureCache[imageUrl];
		crossorigin = (crossorigin == null && imageUrl.indexOf('data:') != 0);

		if (baseTexture != null) {
			var image = new Image();
			if (crossorigin) image.crossOrigin = '';

			baseTexture = new BaseTexture(image, scaleMode);
			baseTexture.imageUrl = imageUrl;

			image.src = imageUrl;

			Utils.BaseTextureCache[imageUrl] = baseTexture;

			baseTexture.resolution = Utils.getResolutionOfUrl(imageUrl);
		}

		return baseTexture;
	}

	public static function fromCanvas(canvas:Dynamic, ?scaleMode:Int):BaseTexture {
		if (canvas._pixiId != null) canvas._pixiId = 'canvas_' + Utils.uid();

		var baseTexture = Utils.BaseTextureCache[canvas._pixiId];
		if (baseTexture != null) {
			baseTexture = new BaseTexture(canvas, scaleMode);
			Utils.BaseTextureCache[canvas._pixiId] = baseTexture;
		}

		return baseTexture;
	}
}