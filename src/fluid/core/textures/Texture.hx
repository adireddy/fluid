package fluid.core.textures;

import fluid.core.utils.Utils;
import fluid.core.math.Point;
import fluid.core.math.shapes.Rectangle;
import msignal.Signal.Signal1;
import js.html.VideoElement;
import js.Error;

class Texture {

	public static var EMPTY = new Texture(new BaseTexture());

	public var noFrame:Bool;
	public var baseTexture:BaseTexture;
	public var trim:Rectangle;
	public var valid:Bool;
	public var requiresUpdate:Bool;
	public var width:Float;
	public var height:Float;
	public var crop:Rectangle;
	public var spritePivot:Point;
	public var rotate:Bool;
	public var frame(default, set):Rectangle;

	public var updated:Signal1<Texture>;
	public var disposed:Signal1<Texture>;
	public var _uvs:TextureUvs;

	public function new(txt:Dynamic, ?frame:Rectangle, ?crop:Rectangle, ?trim:Rectangle, ?rotate:Bool = false) {
		this.noFrame = false;
		if (frame == null) {
			this.noFrame = true;
			frame = new Rectangle(0, 0, 1, 1);
		}

		var baseTexture = (txt.baseTexture != null) ? txt.baseTexture : txt;

		this.baseTexture = cast baseTexture;
		this.frame = frame;
		this.trim = trim;
		this.valid = false;
		this.requiresUpdate = false;
		this._uvs = null;
		this.width = 0;
		this.height = 0;
		this.crop = (crop != null) ? crop : frame;
		this.rotate = rotate;

		if (this.baseTexture.hasLoaded) {
			if (this.noFrame) {
				frame = new Rectangle(0, 0, baseTexture.width, baseTexture.height);
				this.baseTexture.updated.add(_onBaseTextureUpdated);
			}
			this.frame = frame;
		}
		else {
			this.baseTexture.loaded.add(_onBaseTextureLoaded);
		}

		updated = new Signal1(Texture);
		disposed = new Signal1(Texture);
	}

	function set_frame(frame:Rectangle):Rectangle {
		this.noFrame = false;

		this.width = frame.width;
		this.height = frame.height;

		if (this.trim != null && this.rotate != null && (frame.x + frame.width > this.baseTexture.width || frame.y + frame.height > this.baseTexture.height)) {
			throw new Error('Texture Error: frame does not fit inside the base Texture dimensions ' + this);
		}

		this.valid = (frame != null && frame.width != null && frame.height != null && this.baseTexture.hasLoaded);

		if (this.trim != null) {
			this.width = this.trim.width;
			this.height = this.trim.height;
			this.frame.width = this.trim.width;
			this.frame.height = this.trim.height;
		}
		else this.crop = frame;

		if (this.valid) this._updateUvs();

		return this.frame = frame;
	}

	function _onBaseTextureLoaded(baseTexture:BaseTexture) {
		if (this.noFrame) this.frame = new Rectangle(0, 0, baseTexture.width, baseTexture.height);
		//updated.dispatch(this);
	}

	function _onBaseTextureUpdated(baseTexture:BaseTexture) {
		this.frame.width = baseTexture.width;
		this.frame.height = baseTexture.height;
		//updated.dispatch(this);
	}

	public function destroy(?destroyBase:Bool):Void {
		if (this.baseTexture != null) {
			if (destroyBase) this.baseTexture.destroy();
			this.baseTexture.updated.remove(_onBaseTextureUpdated);
			this.baseTexture.loaded.remove(_onBaseTextureLoaded);
			this.baseTexture = null;
		}

		this.frame = null;
		this._uvs = null;
		this.trim = null;
		this.crop = null;

		this.valid = false;

		disposed.removeAll();
		updated.removeAll();
	}

	function update():Void {
		this.baseTexture.update();
	}

	function _updateUvs() {
		if (this._uvs == null) this._uvs = new TextureUvs();
		this._uvs.set(this.crop, this.baseTexture, this.rotate);
	}

	public static function fromImage(imageUrl:String, ?crossorigin:Bool, ?scaleMode:Int):Texture {
		var texture = Utils.TextureCache.get(imageUrl);
		if (texture == null) {
			texture = new Texture(BaseTexture.fromImage(imageUrl, crossorigin, scaleMode));
			Utils.TextureCache.set(imageUrl, texture);
		}
		return texture;
	}

	public static function fromFrame(frameId:String):Texture {
		var texture = Utils.TextureCache.get(frameId);
		if (texture == null) throw new Error('The frameId "' + frameId + '" does not exist in the texture cache');
		return texture;
	}

	public static function fromCanvas(canvas:Dynamic, ?scaleMode:Int = 0):Texture {
		return new Texture(BaseTexture.fromCanvas(canvas, scaleMode));
	}

	public static function fromVideo(video:VideoElement, ?scaleMode:Int):Texture {
		return new Texture(VideoBaseTexture.fromVideo(video, scaleMode));
	}

	public static function fromVideoUrl(videoUrl:String, ?scaleMode:Int):Texture {
		return new Texture(VideoBaseTexture.fromUrl(videoUrl, scaleMode));
	}

	public static function addTextureToCache(texture:Texture, id:String):Void {
		Utils.TextureCache.set(id, texture);
	}

	public static function removeTextureFromCache(id:String):Texture {
		var texture = Utils.TextureCache.get(id);
		Utils.TextureCache.set(id, null);
		Utils.BaseTextureCache.set(id, null);
		return texture;
	}
}