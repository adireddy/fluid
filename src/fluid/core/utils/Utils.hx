package fluid.core.utils;

import fluid.core.renderers.webgl.WebGLRenderer;
import fluid.core.sprites.webgl.SpriteRenderer;
import fluid.core.renderers.webgl.WebGLRenderer;
import fluid.core.textures.Texture;
import fluid.core.textures.BaseTexture;
import js.html.webgl.RenderingContext;
import js.html.CanvasElement;
import js.html.Image;
import js.Browser;

class Utils {

	static var _uid:Int = 0;
	static var _saidHello:Bool = false;

	public static var TextureCache:Map<String, Texture>;
	public static var BaseTextureCache:Map<String, BaseTexture>;

	public static function uid():Int {
		return ++_uid;
	}

	public static function hex2rgb(hex:Int, ?out:Array<Float>):Array<Float> {
		if (out == null) out = [];
		out[0] = (hex >> 16 & 0xFF) / 255;
		out[1] = (hex >> 8 & 0xFF) / 255;
		out[2] = (hex & 0xFF) / 255;
		return out;
	}

	public static function hex2string(hex:Int):String {
		var h = Std.string(hex);
		h = '000000'.substr(0, 6 - h.length) + h;
		return '#' + h;
	}

	public static function rgb2hex(rgb:Array<Int>):Int {
		return ((rgb[0] * 255 << 16) + (rgb[1] * 255 << 8) + rgb[2] * 255);
	}

	public static function canUseNewCanvasBlendModes():Bool {
		if (Browser.document == null) return false;

		var pngHead = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAQAAAABAQMAAADD8p2OAAAAA1BMVEX/';
		var pngEnd = 'AAAACklEQVQI12NgAAAAAgAB4iG8MwAAAABJRU5ErkJggg==';

		var magenta = new Image();
		magenta.src = pngHead + 'AP804Oa6' + pngEnd;

		var yellow = new Image();
		yellow.src = pngHead + '/wCKxvRF' + pngEnd;

		var canvas:CanvasElement = Browser.document.createCanvasElement();
		canvas.width = 6;
		canvas.height = 1;

		var context = canvas.getContext2d();
		context.globalCompositeOperation = 'multiply';
		context.drawImage(magenta, 0, 0);
		context.drawImage(yellow, 2, 0);

		var data = context.getImageData(2, 0, 1, 1).data;

		return (data[0] == 255 && data[1] == 0 && data[2] == 0);
	}

	public static function getNextPowerOfTwo(number:Int):Int {
		if (number > 0 && (number & (number - 1)) == 0) return number;
		else {
			var result = 1;
			while (result < number) {
				result <<= 1;
			}
			return result;
		}
	}

	public static function isPowerOfTwo(width:Int, height:Int):Bool {
		return (width > 0 && (width & (width - 1)) == 0 && height > 0 && (height & (height - 1)) == 0);
	}

	public static function getResolutionOfUrl(url:String):Float {
		var resolution = Fluid.RETINA_PREFIX.match(url);
		if (resolution) return Std.parseFloat(Fluid.RETINA_PREFIX.matched(1));
		return 1;
	}

	public static function sayHello(type:String):Void {
		if (_saidHello) return;
		trace("Fluid " + Fluid.VERSION + ' - ' + type);
		_saidHello = true;
	}

	public static function init() {
		BaseTextureCache = new Map();
		TextureCache = new Map();
	}

	public static function isWebGLSupported():Bool {
		try {
			var can:CanvasElement = Browser.document.createCanvasElement();
			var contextOptions = { stencil: true };
			var gl:RenderingContext = can.getContextWebGL(contextOptions);

			return !!(gl != null && gl.getContextAttributes().stencil);
		}
		catch (e:Dynamic) {
			return false;
		}
	}

	public static function sign(n:Float):Int {
		return n != null ? (n < 0 ? -1 : 1) : 0;
	}

	public static function removeItems(arr:Dynamic, ?index:Int = 0, ?count:Int = 1):Dynamic {
		return arr.splice(index, count);
	}
}