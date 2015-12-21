import js.Browser;
import haxe.extern.EitherType;
import fluid.core.renderers.canvas.CanvasRenderer;
import fluid.core.renderers.webgl.WebGLRenderer;
import fluid.core.utils.Utils;

@:expose class Fluid {

	public static var utils = Utils;

	public static var VERSION:String = "0.0.1";

	public static var PI_2:Float = Math.PI * 2;

	public static var RAD_TO_DEG:Float = 180 / Math.PI;

	public static var DEG_TO_RAD:Float = Math.PI / 180;

	public static var TARGET_FPMS:Float = 0.06;

	public static var RENDERER_TYPE:RendererType = { UNKNOWN: 0, WEBGL: 1, CANVAS: 2 };

	public static var BLEND_MODES:BlendModes = {
		NORMAL:         0,
		ADD:            1,
		MULTIPLY:       2,
		SCREEN:         3,
		OVERLAY:        4,
		DARKEN:         5,
		LIGHTEN:        6,
		COLOR_DODGE:    7,
		COLOR_BURN:     8,
		HARD_LIGHT:     9,
		SOFT_LIGHT:     10,
		DIFFERENCE:     11,
		EXCLUSION:      12,
		HUE:            13,
		SATURATION:     14,
		COLOR:          15,
		LUMINOSITY:     16
	};

	public static var DRAW_MODES:DrawModes = {POINTS: 0, LINES: 1, LINE_LOOP: 2, LINE_STRIP: 3, TRIANGLES: 4, TRIANGLE_STRIP: 5, TRIANGLE_FAN: 6 };

	public static var SCALE_MODES:ScaleModes = { DEFAULT: 0, LINEAR: 0, NEAREST: 1 };

	public static var RETINA_PREFIX:EReg = ~/@(.+)x/;

	public static var RESOLUTION:Float = 1;

	public static var FILTER_RESOLUTION:Float = 1;

	public static var DEFAULT_RENDER_OPTIONS:RenderOptions = {
		view: null,
		resolution: 1,
		antialias: false,
		forceFXAA: false,
		autoResize: false,
		transparent: false,
		backgroundColor: 0x000000,
		clearBeforeRender: true,
		preserveDrawingBuffer: false,
		roundPixels: false
	};

	public static var SHAPES:Shapes = { POLY: 0, RECT: 1, CIRC: 2, ELIP: 3, RREC: 4 };

	public static var SPRITE_BATCH_SIZE:Int = 2000;

	public static function autoDetectRenderer(?width:Float = 1024, ?height:Float = 728, ?options:RenderOptions, ?noWebGL:Bool = false):EitherType<WebGLRenderer, CanvasRenderer> {
		if (!noWebGL && Utils.isWebGLSupported()) return new WebGLRenderer(width, height, options);
		return new CanvasRenderer(width, height, options);
	}
}

typedef RendererType = {
	var UNKNOWN:Int;
	var WEBGL:Int;
	var CANVAS:Int;
}

typedef RenderOptions = {
	@:optional var view:Dynamic;
	@:optional var resolution:Float;
	@:optional var antialias:Bool;
	@:optional var forceFXAA:Bool;
	@:optional var autoResize:Bool;
	@:optional var transparent:Bool;
	@:optional var backgroundColor:Int;
	@:optional var clearBeforeRender:Bool;
	@:optional var preserveDrawingBuffer:Bool;
	@:optional var roundPixels:Bool;
}

typedef DrawModes = {
	var POINTS:Int;
	var LINES:Int;
	var LINE_LOOP:Int;
	var LINE_STRIP:Int;
	var TRIANGLES:Int;
	var TRIANGLE_STRIP:Int;
	var TRIANGLE_FAN:Int;
}

typedef ScaleModes = {
	var DEFAULT:Int;
	var LINEAR:Int;
	var NEAREST:Int;
}

typedef BlendModes = {
	var NORMAL:Int;
	var ADD:Int;
	var MULTIPLY:Int;
	var SCREEN:Int;
	var OVERLAY:Int;
	var DARKEN:Int;
	var LIGHTEN:Int;
	var COLOR_DODGE:Int;
	var COLOR_BURN:Int;
	var HARD_LIGHT:Int;
	var SOFT_LIGHT:Int;
	var DIFFERENCE:Int;
	var EXCLUSION:Int;
	var HUE:Int;
	var SATURATION:Int;
	var COLOR:Int;
	var LUMINOSITY:Int;
}

typedef Shapes = {
	var POLY:Int;
	var RECT:Int;
	var CIRC:Int;
	var ELIP:Int;
	var RREC:Int;
}