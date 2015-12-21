package fluid.core.renderers;

import fluid.core.math.Matrix;
import js.Browser;
import Fluid.RenderOptions;
import fluid.core.utils.Utils;
import js.html.CanvasElement;

class SystemRenderer {

	public var type:Int;
	public var width:Float;
	public var height:Float;
	public var view:CanvasElement;
	public var resolution:Float;
	public var transparent:Bool;
	public var roundPixels:Bool;
	public var autoResize:Bool;
	public var blendModes:Dynamic;
	public var preserveDrawingBuffer:Bool;
	public var clearBeforeRender:Bool;
	public var backgroundColor(default, set):Int;
	public var plugins:Dynamic;

	var _backgroundColor:Int;
	var _backgroundColorRgb:Array<Float>;
	var _backgroundColorString:String;
	var _tempDisplayObjectParent:Dynamic;
	var _lastObjectRendered:Dynamic;

	public function new(system:String, ?width:Float = 1024, ?height:Float = 728, ?options:RenderOptions) {
		Utils.sayHello(system);
		if (options != null) {
			if (options.antialias == null) options.antialias = Fluid.DEFAULT_RENDER_OPTIONS.antialias;
			if (options.autoResize == null) options.autoResize = Fluid.DEFAULT_RENDER_OPTIONS.autoResize;
			if (options.backgroundColor == null) options.backgroundColor = Fluid.DEFAULT_RENDER_OPTIONS.backgroundColor;
			if (options.clearBeforeRender == null) options.clearBeforeRender = Fluid.DEFAULT_RENDER_OPTIONS.clearBeforeRender;
			if (options.forceFXAA == null) options.forceFXAA = Fluid.DEFAULT_RENDER_OPTIONS.forceFXAA;
			if (options.preserveDrawingBuffer == null) options.preserveDrawingBuffer = Fluid.DEFAULT_RENDER_OPTIONS.preserveDrawingBuffer;
			if (options.resolution == null) options.resolution = Fluid.DEFAULT_RENDER_OPTIONS.resolution;
			if (options.roundPixels == null) options.roundPixels = Fluid.DEFAULT_RENDER_OPTIONS.roundPixels;
			if (options.transparent == null) options.transparent = Fluid.DEFAULT_RENDER_OPTIONS.transparent;
			if (options.view == null) options.view = Fluid.DEFAULT_RENDER_OPTIONS.view;
		}
		else options = Fluid.DEFAULT_RENDER_OPTIONS;

		this.type = Fluid.RENDERER_TYPE.UNKNOWN;
		this.width = width;
		this.height = height;
		this.view = (options.view == null) ? Browser.document.createCanvasElement() : options.view;
		this.resolution = options.resolution;
		this.transparent = options.transparent;
		this.autoResize = options.autoResize;
		this.blendModes = null;
		this.preserveDrawingBuffer = options.preserveDrawingBuffer;
		this.clearBeforeRender = options.clearBeforeRender;
		this.roundPixels = options.roundPixels;
		this._backgroundColor = 0x000000;
		this._backgroundColorRgb = [0, 0, 0];
		this._backgroundColorString = "#000000";
		this.backgroundColor = options.backgroundColor;
		this._tempDisplayObjectParent = { worldTransform:new Matrix(), worldAlpha:1, children:[] };
		this._lastObjectRendered = this._tempDisplayObjectParent;
	}

	public function set_backgroundColor(val:Int):Int {
		this._backgroundColor = val;
		this._backgroundColorString = Utils.hex2string(val);
		Utils.hex2rgb(val, this._backgroundColorRgb);
		return backgroundColor = val;
	}

	public function resize(width:Float, height:Float):Void {
		this.width = width * this.resolution;
		this.height = height * this.resolution;

		this.view.width = Std.int(this.width);
		this.view.height = Std.int(this.height);

		if (this.autoResize) {
			this.view.style.width = this.width / this.resolution + 'px';
			this.view.style.height = this.height / this.resolution + 'px';
		}
	}

	public function destroy(?removeView:Bool = false):Void {
		if (removeView && this.view.parentNode != null) {
			this.view.parentNode.removeChild(this.view);
		}

		this.type = Fluid.RENDERER_TYPE.UNKNOWN;

		this.width = 0;
		this.height = 0;

		this.view = null;

		this.resolution = 0;

		this.transparent = false;

		this.autoResize = false;

		this.blendModes = null;

		this.preserveDrawingBuffer = false;
		this.clearBeforeRender = false;

		this.roundPixels = false;

		this._backgroundColor = 0;
		this._backgroundColorRgb = null;
		this._backgroundColorString = null;
	}
}