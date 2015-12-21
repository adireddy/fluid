(function (console, $hx_exports) { "use strict";
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
var EReg = function(r,opt) {
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
};
EReg.prototype = {
	match: function(s) {
		if(this.r.global) this.r.lastIndex = 0;
		this.r.m = this.r.exec(s);
		this.r.s = s;
		return this.r.m != null;
	}
	,matched: function(n) {
		if(this.r.m != null && n >= 0 && n < this.r.m.length) return this.r.m[n]; else throw new js__$Boot_HaxeError("EReg::matched");
	}
};
var fluid_core_utils_Utils = function() { };
fluid_core_utils_Utils.uid = function() {
	return ++fluid_core_utils_Utils._uid;
};
fluid_core_utils_Utils.hex2rgb = function(hex,out) {
	if(out == null) out = [];
	out[0] = (hex >> 16 & 255) / 255;
	out[1] = (hex >> 8 & 255) / 255;
	out[2] = (hex & 255) / 255;
	return out;
};
fluid_core_utils_Utils.hex2string = function(hex) {
	var h;
	if(hex == null) h = "null"; else h = "" + hex;
	h = HxOverrides.substr("000000",0,6 - h.length) + h;
	return "#" + h;
};
fluid_core_utils_Utils.rgb2hex = function(rgb) {
	return (rgb[0] * 255 << 16) + (rgb[1] * 255 << 8) + rgb[2] * 255;
};
fluid_core_utils_Utils.canUseNewCanvasBlendModes = function() {
	if(window.document == null) return false;
	var pngHead = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAQAAAABAQMAAADD8p2OAAAAA1BMVEX/";
	var pngEnd = "AAAACklEQVQI12NgAAAAAgAB4iG8MwAAAABJRU5ErkJggg==";
	var magenta = new Image();
	magenta.src = pngHead + "AP804Oa6" + pngEnd;
	var yellow = new Image();
	yellow.src = pngHead + "/wCKxvRF" + pngEnd;
	var canvas;
	var _this = window.document;
	canvas = _this.createElement("canvas");
	canvas.width = 6;
	canvas.height = 1;
	var context = canvas.getContext("2d",null);
	context.globalCompositeOperation = "multiply";
	context.drawImage(magenta,0,0);
	context.drawImage(yellow,2,0);
	var data = context.getImageData(2,0,1,1).data;
	return data[0] == 255 && data[1] == 0 && data[2] == 0;
};
fluid_core_utils_Utils.getNextPowerOfTwo = function(number) {
	if(number > 0 && (number & number - 1) == 0) return number; else {
		var result = 1;
		while(result < number) result <<= 1;
		return result;
	}
};
fluid_core_utils_Utils.isPowerOfTwo = function(width,height) {
	return width > 0 && (width & width - 1) == 0 && height > 0 && (height & height - 1) == 0;
};
fluid_core_utils_Utils.getResolutionOfUrl = function(url) {
	var resolution = Fluid.RETINA_PREFIX.match(url);
	if(resolution) return Std.parseFloat(Fluid.RETINA_PREFIX.matched(1));
	return 1;
};
fluid_core_utils_Utils.sayHello = function(type) {
	if(fluid_core_utils_Utils._saidHello) return;
	console.log("Fluid " + Fluid.VERSION + " - " + type);
	fluid_core_utils_Utils._saidHello = true;
};
fluid_core_utils_Utils.isWebGLSupported = function() {
	try {
		var can;
		var _this = window.document;
		can = _this.createElement("canvas");
		var contextOptions = { stencil : true};
		var gl = js_html__$CanvasElement_CanvasUtil.getContextWebGL(can,contextOptions);
		return !(!(gl != null && gl.getContextAttributes().stencil));
	} catch( e ) {
		if (e instanceof js__$Boot_HaxeError) e = e.val;
		return false;
	}
};
fluid_core_utils_Utils.sign = function(n) {
	if(n != null) {
		if(n < 0) return -1; else return 1;
	} else return 0;
};
var Fluid = $hx_exports.Fluid = function() { };
Fluid.autoDetectRenderer = function(width,height,options,noWebGL) {
	if(noWebGL == null) noWebGL = false;
	if(height == null) height = 728;
	if(width == null) width = 1024;
	if(!noWebGL && fluid_core_utils_Utils.isWebGLSupported()) return new PIXI.WebGLRenderer(width,height,options);
	return new PIXI.CanvasRenderer(width,height,options);
};
var HxOverrides = function() { };
HxOverrides.substr = function(s,pos,len) {
	if(pos != null && pos != 0 && len != null && len < 0) return "";
	if(len == null) len = s.length;
	if(pos < 0) {
		pos = s.length + pos;
		if(pos < 0) pos = 0;
	} else if(len < 0) len = s.length + len - pos;
	return s.substr(pos,len);
};
var Std = function() { };
Std.parseFloat = function(x) {
	return parseFloat(x);
};
var fluid_plugins_app_Application = function() {
	this.pixelRatio = 1;
	this.set_skipFrame(false);
	this.autoResize = true;
	this.transparent = false;
	this.antialias = false;
	this.forceFXAA = false;
	this.roundPixels = false;
	this.clearBeforeRender = true;
	this.preserveDrawingBuffer = false;
	this.backgroundColor = 16777215;
	this.width = window.innerWidth;
	this.height = window.innerHeight;
	this.set_fps(60);
};
fluid_plugins_app_Application.prototype = {
	set_fps: function(val) {
		this._frameCount = 0;
		return val >= 1 && val < 60?this.fps = val | 0:this.fps = 60;
	}
	,set_skipFrame: function(val) {
		if(val) {
			console.log("fluid.plugins.app.Application > Deprecated: skipFrame - use fps property and set it to 30 instead");
			this.set_fps(30);
		}
		return this.skipFrame = val;
	}
	,_setDefaultValues: function() {
		this.pixelRatio = 1;
		this.set_skipFrame(false);
		this.autoResize = true;
		this.transparent = false;
		this.antialias = false;
		this.forceFXAA = false;
		this.roundPixels = false;
		this.clearBeforeRender = true;
		this.preserveDrawingBuffer = false;
		this.backgroundColor = 16777215;
		this.width = window.innerWidth;
		this.height = window.innerHeight;
		this.set_fps(60);
	}
	,start: function(rendererType,parentDom) {
		if(rendererType == null) rendererType = "auto";
		var _this = window.document;
		this.canvas = _this.createElement("canvas");
		this.canvas.style.width = this.width + "px";
		this.canvas.style.height = this.height + "px";
		this.canvas.style.position = "absolute";
		if(parentDom == null) window.document.body.appendChild(this.canvas); else parentDom.appendChild(this.canvas);
		this.stage = new PIXI.Container();
		var renderingOptions = { };
		renderingOptions.view = this.canvas;
		renderingOptions.backgroundColor = this.backgroundColor;
		renderingOptions.resolution = this.pixelRatio;
		renderingOptions.antialias = this.antialias;
		renderingOptions.forceFXAA = this.forceFXAA;
		renderingOptions.autoResize = this.autoResize;
		renderingOptions.transparent = this.transparent;
		renderingOptions.clearBeforeRender = this.clearBeforeRender;
		renderingOptions.preserveDrawingBuffer = this.preserveDrawingBuffer;
		if(rendererType == "auto") this.renderer = Fluid.autoDetectRenderer(this.width,this.height,renderingOptions); else if(rendererType == "canvas") this.renderer = new PIXI.CanvasRenderer(this.width,this.height,renderingOptions); else this.renderer = new PIXI.WebGLRenderer(this.width,this.height,renderingOptions);
		if(this.roundPixels) this.renderer.roundPixels = true;
		window.document.body.appendChild(this.renderer.view);
		if(this.autoResize) window.onresize = $bind(this,this._onWindowResize);
		window.requestAnimationFrame($bind(this,this._onRequestAnimationFrame));
	}
	,pauseRendering: function() {
		window.onresize = null;
		window.requestAnimationFrame(function(elapsedTime) {
		});
	}
	,resumeRendering: function() {
		if(this.autoResize) window.onresize = $bind(this,this._onWindowResize);
		window.requestAnimationFrame($bind(this,this._onRequestAnimationFrame));
	}
	,_onWindowResize: function(event) {
		this.width = window.innerWidth;
		this.height = window.innerHeight;
		this.renderer.resize(this.width,this.height);
		this.canvas.style.width = this.width + "px";
		this.canvas.style.height = this.height + "px";
		if(this.onResize != null) this.onResize();
	}
	,_onRequestAnimationFrame: function(elapsedTime) {
		this._frameCount++;
		if(this._frameCount == (60 / this.fps | 0)) {
			this._frameCount = 0;
			if(this.onUpdate != null) this.onUpdate(elapsedTime);
			this.renderer.render(this.stage);
		}
		window.requestAnimationFrame($bind(this,this._onRequestAnimationFrame));
	}
	,addStats: function() {
		if(window.Perf != null) {
		}
	}
};
var demo_Main = function() {
	fluid_plugins_app_Application.call(this);
	this.backgroundColor = 65280;
	fluid_plugins_app_Application.prototype.start.call(this);
};
demo_Main.main = function() {
	new demo_Main();
};
demo_Main.__super__ = fluid_plugins_app_Application;
demo_Main.prototype = $extend(fluid_plugins_app_Application.prototype,{
});
var fluid_core_math_Matrix = function() {
	this.a = 1;
	this.b = 0;
	this.c = 0;
	this.d = 1;
	this.tx = 0;
	this.ty = 0;
};
fluid_core_math_Matrix.prototype = {
	fromArray: function(array) {
		this.a = array[0];
		this.b = array[1];
		this.c = array[3];
		this.d = array[4];
		this.tx = array[2];
		this.ty = array[5];
	}
	,set: function(a,b,c,d,tx,ty) {
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;
		this.tx = tx;
		this.ty = ty;
		return this;
	}
	,toArray: function(transpose,out) {
		if(this.array == null) this.array = [];
		var array;
		if(out == null) array = this.array; else array = out;
		if(transpose) {
			array[0] = this.a;
			array[1] = this.b;
			array[2] = 0;
			array[3] = this.c;
			array[4] = this.d;
			array[5] = 0;
			array[6] = this.tx;
			array[7] = this.ty;
			array[8] = 1;
		} else {
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
	,apply: function(pos,newPos) {
		if(newPos == null) newPos = new fluid_core_math_Point();
		var x = pos.x;
		var y = pos.y;
		newPos.x = this.a * x + this.c * y + this.tx;
		newPos.y = this.b * x + this.d * y + this.ty;
		return newPos;
	}
	,applyInverse: function(pos,newPos) {
		if(newPos == null) newPos = new fluid_core_math_Point();
		var id = 1 / (this.a * this.d + this.c * -this.b);
		var x = pos.x;
		var y = pos.y;
		newPos.x = this.d * id * x + -this.c * id * y + (this.ty * this.c - this.tx * this.d) * id;
		newPos.y = this.a * id * y + -this.b * id * x + (-this.ty * this.a + this.tx * this.b) * id;
		return newPos;
	}
	,translate: function(x,y) {
		this.tx += x;
		this.ty += y;
		return this;
	}
	,scale: function(x,y) {
		this.a *= x;
		this.d *= y;
		this.c *= x;
		this.b *= y;
		this.tx *= x;
		this.ty *= y;
		return this;
	}
	,rotate: function(angle) {
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
	,append: function(matrix) {
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
	,setTransform: function(x,y,pivotX,pivotY,scaleX,scaleY,rotation,skewX,skewY) {
		var a;
		var b;
		var c;
		var d;
		var sr;
		var cr;
		var cy;
		var sy;
		var nsx;
		var cx;
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
		this.tx = x + (pivotX * a + pivotY * c);
		this.ty = y + (pivotX * b + pivotY * d);
		return this;
	}
	,prepend: function(matrix) {
		var tx1 = this.tx;
		if(matrix.a != 1 || matrix.b != 0 || matrix.c != 0 || matrix.d != 1) {
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
	,identity: function() {
		this.a = 1;
		this.b = 0;
		this.c = 0;
		this.d = 1;
		this.tx = 0;
		this.ty = 0;
		return this;
	}
	,invert: function() {
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
	,clone: function() {
		var matrix = new fluid_core_math_Matrix();
		matrix.a = this.a;
		matrix.b = this.b;
		matrix.c = this.c;
		matrix.d = this.d;
		matrix.tx = this.tx;
		matrix.ty = this.ty;
		return matrix;
	}
	,copy: function(matrix) {
		matrix.a = this.a;
		matrix.b = this.b;
		matrix.c = this.c;
		matrix.d = this.d;
		matrix.tx = this.tx;
		matrix.ty = this.ty;
		return matrix;
	}
};
var fluid_core_math_Point = function(x,y) {
	if(y == null) y = 0;
	if(x == null) x = 0;
	this.x = x;
	this.y = y;
};
fluid_core_math_Point.prototype = {
	clone: function() {
		return new fluid_core_math_Point(this.x,this.y);
	}
	,copy: function(p) {
		this.set(p.x,p.y);
	}
	,equals: function(p) {
		return p.x == this.x && p.y == this.y;
	}
	,set: function(x,y) {
		if(x == null) x = 0;
		this.x = x;
		if(y != null) this.y = y; else this.y = this.x;
	}
};
var fluid_core_math_shapes_Rectangle = function(x,y,width,height) {
	if(height == null) height = 0;
	if(width == null) width = 0;
	if(y == null) y = 0;
	if(x == null) x = 0;
	this.x = x;
	this.y = y;
	this.width = width;
	this.height = height;
	this.type = Fluid.SHAPES.RECT;
};
fluid_core_math_shapes_Rectangle.prototype = {
	clone: function() {
		return new fluid_core_math_shapes_Rectangle(this.x,this.y,this.width,this.height);
	}
	,contains: function(x,y) {
		if(this.width <= 0 || this.height <= 0) return false;
		return x >= this.x && x < this.x + this.width && (y >= this.y && y < this.y + this.height);
	}
};
var fluid_core_renderers_SystemRenderer = function(system,width,height,options) {
	if(height == null) height = 728;
	if(width == null) width = 1024;
	fluid_core_utils_Utils.sayHello(system);
	if(options != null) {
		if(options.antialias == null) options.antialias = Fluid.DEFAULT_RENDER_OPTIONS.antialias;
		if(options.autoResize == null) options.autoResize = Fluid.DEFAULT_RENDER_OPTIONS.autoResize;
		if(options.backgroundColor == null) options.backgroundColor = Fluid.DEFAULT_RENDER_OPTIONS.backgroundColor;
		if(options.clearBeforeRender == null) options.clearBeforeRender = Fluid.DEFAULT_RENDER_OPTIONS.clearBeforeRender;
		if(options.forceFXAA == null) options.forceFXAA = Fluid.DEFAULT_RENDER_OPTIONS.forceFXAA;
		if(options.preserveDrawingBuffer == null) options.preserveDrawingBuffer = Fluid.DEFAULT_RENDER_OPTIONS.preserveDrawingBuffer;
		if(options.resolution == null) options.resolution = Fluid.DEFAULT_RENDER_OPTIONS.resolution;
		if(options.roundPixels == null) options.roundPixels = Fluid.DEFAULT_RENDER_OPTIONS.roundPixels;
		if(options.transparent == null) options.transparent = Fluid.DEFAULT_RENDER_OPTIONS.transparent;
		if(options.view == null) options.view = Fluid.DEFAULT_RENDER_OPTIONS.view;
	} else options = Fluid.DEFAULT_RENDER_OPTIONS;
	this.type = Fluid.RENDERER_TYPE.UNKNOWN;
	this.width = width;
	this.height = height;
	if(options.view == null) {
		var _this = window.document;
		this.view = _this.createElement("canvas");
	} else this.view = options.view;
	this.resolution = options.resolution;
	this.transparent = options.transparent;
	this.autoResize = options.autoResize;
	this.blendModes = null;
	this.preserveDrawingBuffer = options.preserveDrawingBuffer;
	this.clearBeforeRender = options.clearBeforeRender;
	this.roundPixels = options.roundPixels;
	this._backgroundColor = 0;
	this._backgroundColorRgb = [0,0,0];
	this._backgroundColorString = "#000000";
	this.set_backgroundColor(options.backgroundColor);
	this._tempDisplayObjectParent = { worldTransform : new fluid_core_math_Matrix(), worldAlpha : 1, children : []};
	this._lastObjectRendered = this._tempDisplayObjectParent;
};
fluid_core_renderers_SystemRenderer.prototype = {
	set_backgroundColor: function(val) {
		this._backgroundColor = val;
		this._backgroundColorString = fluid_core_utils_Utils.hex2string(val);
		fluid_core_utils_Utils.hex2rgb(val,this._backgroundColorRgb);
		return this.backgroundColor = val;
	}
	,resize: function(width,height) {
		this.width = width * this.resolution;
		this.height = height * this.resolution;
		this.view.width = this.width | 0;
		this.view.height = this.height | 0;
		if(this.autoResize) {
			this.view.style.width = this.width / this.resolution + "px";
			this.view.style.height = this.height / this.resolution + "px";
		}
	}
	,destroy: function(removeView) {
		if(removeView == null) removeView = false;
		if(removeView && this.view.parentNode != null) this.view.parentNode.removeChild(this.view);
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
};
var js__$Boot_HaxeError = function(val) {
	Error.call(this);
	this.val = val;
	this.message = String(val);
	if(Error.captureStackTrace) Error.captureStackTrace(this,js__$Boot_HaxeError);
};
js__$Boot_HaxeError.__super__ = Error;
js__$Boot_HaxeError.prototype = $extend(Error.prototype,{
});
var js_html__$CanvasElement_CanvasUtil = function() { };
js_html__$CanvasElement_CanvasUtil.getContextWebGL = function(canvas,attribs) {
	var _g = 0;
	var _g1 = ["webgl","experimental-webgl"];
	while(_g < _g1.length) {
		var name = _g1[_g];
		++_g;
		var ctx = canvas.getContext(name,attribs);
		if(ctx != null) return ctx;
	}
	return null;
};
var $_, $fid = 0;
function $bind(o,m) { if( m == null ) return null; if( m.__id__ == null ) m.__id__ = $fid++; var f; if( o.hx__closures__ == null ) o.hx__closures__ = {}; else f = o.hx__closures__[m.__id__]; if( f == null ) { f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; o.hx__closures__[m.__id__] = f; } return f; }
fluid_core_utils_Utils._uid = 0;
fluid_core_utils_Utils._saidHello = false;
Fluid.utils = fluid_core_utils_Utils;
Fluid.VERSION = "0.0.1";
Fluid.PI_2 = Math.PI * 2;
Fluid.RAD_TO_DEG = 180 / Math.PI;
Fluid.DEG_TO_RAD = Math.PI / 180;
Fluid.TARGET_FPMS = 0.06;
Fluid.RENDERER_TYPE = { UNKNOWN : 0, WEBGL : 1, CANVAS : 2};
Fluid.BLEND_MODES = { NORMAL : 0, ADD : 1, MULTIPLY : 2, SCREEN : 3, OVERLAY : 4, DARKEN : 5, LIGHTEN : 6, COLOR_DODGE : 7, COLOR_BURN : 8, HARD_LIGHT : 9, SOFT_LIGHT : 10, DIFFERENCE : 11, EXCLUSION : 12, HUE : 13, SATURATION : 14, COLOR : 15, LUMINOSITY : 16};
Fluid.DRAW_MODES = { POINTS : 0, LINES : 1, LINE_LOOP : 2, LINE_STRIP : 3, TRIANGLES : 4, TRIANGLE_STRIP : 5, TRIANGLE_FAN : 6};
Fluid.SCALE_MODES = { DEFAULT : 0, LINEAR : 0, NEAREST : 1};
Fluid.RETINA_PREFIX = new EReg("@(.+)x","");
Fluid.RESOLUTION = 1;
Fluid.FILTER_RESOLUTION = 1;
Fluid.DEFAULT_RENDER_OPTIONS = { view : null, resolution : 1, antialias : false, forceFXAA : false, autoResize : false, transparent : false, backgroundColor : 0, clearBeforeRender : true, preserveDrawingBuffer : false, roundPixels : false};
Fluid.SHAPES = { POLY : 0, RECT : 1, CIRC : 2, ELIP : 3, RREC : 4};
Fluid.SPRITE_BATCH_SIZE = 2000;
fluid_plugins_app_Application.AUTO = "auto";
fluid_plugins_app_Application.RECOMMENDED = "recommended";
fluid_plugins_app_Application.CANVAS = "canvas";
fluid_plugins_app_Application.WEBGL = "webgl";
fluid_core_math_Matrix.IDENTITY = new fluid_core_math_Matrix();
fluid_core_math_Matrix.TEMP_MATRIX = new fluid_core_math_Matrix();
demo_Main.main();
})(typeof console != "undefined" ? console : {log:function(){}}, typeof window != "undefined" ? window : exports);

//# sourceMappingURL=test.js.map