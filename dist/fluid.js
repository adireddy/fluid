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
EReg.__name__ = true;
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
Math.__name__ = true;
var fluid_core_renderers_SystemRenderer = function(system,width,height,options) {
	if(height == null) height = 728;
	if(width == null) width = 1024;
	fluid_core_utils_Utils.init();
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
	this.plugins = new haxe_ds_StringMap();
};
fluid_core_renderers_SystemRenderer.__name__ = true;
fluid_core_renderers_SystemRenderer.prototype = {
	set_backgroundColor: function(val) {
		this._backgroundColor = val;
		this._backgroundColorString = fluid_core_utils_Utils.hex2string(val);
		fluid_core_utils_Utils.hex2rgb(val,this._backgroundColorRgb);
		return this.backgroundColor = val;
	}
	,resize: function(width,height) {
		this.width = width * this.resolution | 0;
		this.height = height * this.resolution | 0;
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
var fluid_core_renderers_webgl_WebGLRenderer = function(width,height,options) {
	this.prerender = new msignal_Signal0();
	this.postrender = new msignal_Signal0();
	this.context = new msignal_Signal1(WebGLRenderingContext);
	if(options == null) options = { };
	fluid_core_renderers_SystemRenderer.call(this,"WebGL",width,height,options);
	this.__plugins = new haxe_ds_StringMap();
	fluid_core_utils_PluginTarget.registerPlugin(this,"sprite",fluid_core_sprites_webgl_SpriteRenderer);
	this.type = Fluid.RENDERER_TYPE.WEBGL;
	this.view.addEventListener("webglcontextlost",$bind(this,this._handleContextLost),false);
	this.view.addEventListener("webglcontextrestored",$bind(this,this._handleContextRestored),false);
	this._useFXAA = !(!options.forceFXAA) && options.antialias;
	this._FXAAFilter = null;
	this._contextOptions = { alpha : this.transparent, antialias : options.antialias, premultipliedAlpha : this.transparent, stencil : true, preserveDrawingBuffer : options.preserveDrawingBuffer};
	fluid_core_utils_PluginTarget.initPlugins(this);
	this.drawCount = 0;
	this.shaderManager = new fluid_core_renderers_webgl_managers_ShaderManager(this);
	this.maskManager = new fluid_core_renderers_webgl_managers_MaskManager(this);
	this.stencilManager = new fluid_core_renderers_webgl_managers_StencilManager(this);
	this.filterManager = new fluid_core_renderers_webgl_managers_FilterManager(this);
	this.blendModeManager = new fluid_core_renderers_webgl_managers_BlendModeManager(this);
	this.currentRenderTarget = null;
	this.currentRenderer = new fluid_core_renderers_webgl_utils_ObjectRenderer(this);
	this._createContext();
	this._initContext();
	this._mapGlModes();
	this._managedTextures = [];
	this._renderTargetStack = [];
};
fluid_core_renderers_webgl_WebGLRenderer.__name__ = true;
fluid_core_renderers_webgl_WebGLRenderer.__super__ = fluid_core_renderers_SystemRenderer;
fluid_core_renderers_webgl_WebGLRenderer.prototype = $extend(fluid_core_renderers_SystemRenderer.prototype,{
	render: function(object) {
		var _g = this;
		this.prerender.dispatch();
		if(this.gl.isContextLost()) return;
		this.drawCount = 0;
		this._lastObjectRendered = object;
		if(this._useFXAA) {
			this._FXAAFilter[0].uniforms.resolution.value.x = this.width;
			this._FXAAFilter[0].uniforms.resolution.value.y = this.height;
			object.filterArea = this.renderTarget.size;
			object.set_filters(this._FXAAFilter);
		}
		var cacheParent = object.parent;
		object.parent = this._tempDisplayObjectParent;
		object.updateTransform();
		object.parent = cacheParent;
		var gl = this.gl;
		this.setRenderTarget(this.renderTarget);
		if(this.clearBeforeRender) {
			if(this.transparent) gl.clearColor(0,0,0,0); else gl.clearColor(this._backgroundColorRgb[0],this._backgroundColorRgb[1],this._backgroundColorRgb[2],1);
			gl.clear(16384);
		}
		haxe_Timer.delay(function() {
			_g.renderDisplayObject(object,_g.renderTarget);
			_g.postrender.dispatch();
		},2000);
	}
	,renderDisplayObject: function(displayObject,renderTarget,clear) {
		if(clear == null) clear = false;
		this.setRenderTarget(renderTarget);
		if(clear) renderTarget.clear();
		this.filterManager.setFilterStack(renderTarget.filterStack);
		displayObject.renderWebGL(this);
		this.currentRenderer.flush();
	}
	,setObjectRenderer: function(objectRenderer) {
		if(this.currentRenderer == objectRenderer) return;
		this.currentRenderer.stop();
		this.currentRenderer = objectRenderer;
		this.currentRenderer.start();
	}
	,setRenderTarget: function(renderTarget) {
		if(this.currentRenderTarget == renderTarget) return;
		this.currentRenderTarget = renderTarget;
		this.currentRenderTarget.activate();
		this.stencilManager.setMaskStack(renderTarget.stencilMaskStack);
	}
	,resize: function(width,height) {
		fluid_core_renderers_SystemRenderer.prototype.resize.call(this,width,height);
		this.filterManager.resize(width,height);
		this.renderTarget.resize(width,height);
		if(this.currentRenderTarget == this.renderTarget) {
			this.renderTarget.activate();
			this.gl.viewport(0,0,this.width,this.height);
		}
	}
	,updateTexture: function(txt) {
		var texture;
		if(txt.baseTexture != null) texture = txt.baseTexture; else texture = txt;
		if(!texture.hasLoaded) return null;
		var gl = this.gl;
		if(texture._glTextures[Reflect.field(gl,"id")] == null) {
			texture._glTextures[Reflect.field(gl,"id")] = gl.createTexture();
			texture.updated.add($bind(this,this.updateTexture));
			texture.disposed.add($bind(this,this.destroyTexture));
			this._managedTextures.push(texture);
		}
		gl.bindTexture(3553,texture._glTextures[Reflect.field(gl,"id")]);
		gl.pixelStorei(37441,texture.premultipliedAlpha?1:0);
		gl.texImage2D(3553,0,6408,6408,5121,texture.source);
		gl.texParameteri(3553,10240,texture.scaleMode == Fluid.SCALE_MODES.LINEAR?9729:9728);
		if(texture.mipmap && texture.isPowerOfTwo) {
			gl.texParameteri(3553,10241,texture.scaleMode == Fluid.SCALE_MODES.LINEAR?9987:9984);
			gl.generateMipmap(3553);
		} else gl.texParameteri(3553,10241,texture.scaleMode == Fluid.SCALE_MODES.LINEAR?9729:9728);
		if(!texture.isPowerOfTwo) {
			gl.texParameteri(3553,10242,33071);
			gl.texParameteri(3553,10243,33071);
		} else {
			gl.texParameteri(3553,10242,10497);
			gl.texParameteri(3553,10243,10497);
		}
		return texture._glTextures[Reflect.field(gl,"id")];
	}
	,destroyTexture: function(txt) {
		var texture;
		if(txt.baseTexture != null) texture = txt.baseTexture; else texture = txt;
		if(!texture.hasLoaded) return;
		if(texture._glTextures[Reflect.field(this.gl,"id")] != null) {
			this.gl.deleteTexture(texture._glTextures[Reflect.field(this.gl,"id")]);
			texture._glTextures[Reflect.field(this.gl,"id")] = null;
		}
	}
	,_handleContextLost: function(event) {
		event.preventDefault();
	}
	,_handleContextRestored: function(event) {
		this._initContext();
		var _g1 = 0;
		var _g = this._managedTextures.length;
		while(_g1 < _g) {
			var i = _g1++;
			var texture = this._managedTextures[i];
			if(texture._glTextures[Reflect.field(this.gl,"id")] != null) texture._glTextures[Reflect.field(this.gl,"id")] = null;
		}
	}
	,_createContext: function() {
		var gl;
		var attribs = this._contextOptions;
		gl = js_html__$CanvasElement_CanvasUtil.getContextWebGL(this.view,attribs);
		this.gl = gl;
		fluid_core_renderers_webgl_WebGLRenderer.glContextId = fluid_core_renderers_webgl_WebGLRenderer.glContextId++;
		this.gl.id = fluid_core_renderers_webgl_WebGLRenderer.glContextId;
		this.gl.renderer = this;
	}
	,_initContext: function() {
		var gl = this.gl;
		gl.disable(2929);
		gl.disable(2884);
		gl.enable(3042);
		this.renderTarget = new fluid_core_renderers_webgl_utils_RenderTarget(gl,this.width,this.height,null,this.resolution,true);
		this.setRenderTarget(this.renderTarget);
		this.context.dispatch(gl);
		this.resize(this.width,this.height);
		if(!this._useFXAA) this._useFXAA = this._contextOptions.antialias && !gl.getContextAttributes().antialias;
		if(this._useFXAA) window.console.warn("FXAA antialiasing being used instead of native antialiasing");
	}
	,destroy: function(removeView) {
		if(removeView == null) removeView = false;
		fluid_core_utils_PluginTarget.destroyPlugins(this);
		this.view.removeEventListener("webglcontextlost",$bind(this,this._handleContextLost));
		this.view.removeEventListener("webglcontextrestored",$bind(this,this._handleContextRestored));
		var _g1 = 0;
		var _g = this._managedTextures.length;
		while(_g1 < _g) {
			var i = _g1++;
			var texture = this._managedTextures[i];
			this.destroyTexture(texture);
			texture.updated.remove($bind(this,this.updateTexture));
			texture.disposed.remove($bind(this,this.destroyTexture));
		}
		fluid_core_renderers_SystemRenderer.prototype.destroy.call(this,removeView);
		this.shaderManager.destroy();
		this.maskManager.destroy();
		this.stencilManager.destroy();
		this.filterManager.destroy();
		this.blendModeManager.destroy();
		this.shaderManager = null;
		this.maskManager = null;
		this.filterManager = null;
		this.blendModeManager = null;
		this.currentRenderer = null;
		this._contextOptions = null;
		this._managedTextures = null;
		this.drawCount = 0;
		this.gl.useProgram(null);
		this.gl = null;
	}
	,_mapGlModes: function() {
		var gl = this.gl;
		if(this.blendModes == null) {
			this.blendModes = { };
			this.blendModes[Fluid.BLEND_MODES.NORMAL] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.ADD] = [770,772];
			this.blendModes[Fluid.BLEND_MODES.MULTIPLY] = [774,771];
			this.blendModes[Fluid.BLEND_MODES.SCREEN] = [770,1];
			this.blendModes[Fluid.BLEND_MODES.OVERLAY] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.DARKEN] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.LIGHTEN] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.COLOR_DODGE] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.COLOR_BURN] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.HARD_LIGHT] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.SOFT_LIGHT] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.DIFFERENCE] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.EXCLUSION] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.HUE] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.SATURATION] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.COLOR] = [1,771];
			this.blendModes[Fluid.BLEND_MODES.LUMINOSITY] = [1,771];
		}
		if(this.drawModes == null) {
			this.drawModes = { };
			this.drawModes[Fluid.DRAW_MODES.POINTS] = 0;
			this.drawModes[Fluid.DRAW_MODES.LINES] = 1;
			this.drawModes[Fluid.DRAW_MODES.LINE_LOOP] = 2;
			this.drawModes[Fluid.DRAW_MODES.LINE_STRIP] = 3;
			this.drawModes[Fluid.DRAW_MODES.TRIANGLES] = 4;
			this.drawModes[Fluid.DRAW_MODES.TRIANGLE_STRIP] = 5;
			this.drawModes[Fluid.DRAW_MODES.TRIANGLE_FAN] = 6;
		}
	}
});
var fluid_core_utils_Utils = function() { };
fluid_core_utils_Utils.__name__ = true;
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
fluid_core_utils_Utils.init = function() {
	fluid_core_utils_Utils.BaseTextureCache = new haxe_ds_StringMap();
	fluid_core_utils_Utils.TextureCache = new haxe_ds_StringMap();
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
fluid_core_utils_Utils.removeItems = function(arr,index,count) {
	if(count == null) count = 1;
	if(index == null) index = 0;
	return arr.splice(index,count);
};
var Fluid = $hx_exports.Fluid = function() { };
Fluid.__name__ = true;
Fluid.autoDetectRenderer = function(width,height,options,noWebGL) {
	if(noWebGL == null) noWebGL = false;
	if(height == null) height = 728;
	if(width == null) width = 1024;
	if(!noWebGL && fluid_core_utils_Utils.isWebGLSupported()) return new fluid_core_renderers_webgl_WebGLRenderer(width,height,options);
	return new PIXI.CanvasRenderer(width,height,options);
};
var HxOverrides = function() { };
HxOverrides.__name__ = true;
HxOverrides.substr = function(s,pos,len) {
	if(pos != null && pos != 0 && len != null && len < 0) return "";
	if(len == null) len = s.length;
	if(pos < 0) {
		pos = s.length + pos;
		if(pos < 0) pos = 0;
	} else if(len < 0) len = s.length + len - pos;
	return s.substr(pos,len);
};
HxOverrides.indexOf = function(a,obj,i) {
	var len = a.length;
	if(i < 0) {
		i += len;
		if(i < 0) i = 0;
	}
	while(i < len) {
		if(a[i] === obj) return i;
		i++;
	}
	return -1;
};
HxOverrides.iter = function(a) {
	return { cur : 0, arr : a, hasNext : function() {
		return this.cur < this.arr.length;
	}, next : function() {
		return this.arr[this.cur++];
	}};
};
var Reflect = function() { };
Reflect.__name__ = true;
Reflect.field = function(o,field) {
	try {
		return o[field];
	} catch( e ) {
		if (e instanceof js__$Boot_HaxeError) e = e.val;
		return null;
	}
};
Reflect.isFunction = function(f) {
	return typeof(f) == "function" && !(f.__name__ || f.__ename__);
};
Reflect.compareMethods = function(f1,f2) {
	if(f1 == f2) return true;
	if(!Reflect.isFunction(f1) || !Reflect.isFunction(f2)) return false;
	return f1.scope == f2.scope && f1.method == f2.method && f1.method != null;
};
var Std = function() { };
Std.__name__ = true;
Std.string = function(s) {
	return js_Boot.__string_rec(s,"");
};
Std.parseFloat = function(x) {
	return parseFloat(x);
};
var Type = function() { };
Type.__name__ = true;
Type.createInstance = function(cl,args) {
	var _g = args.length;
	switch(_g) {
	case 0:
		return new cl();
	case 1:
		return new cl(args[0]);
	case 2:
		return new cl(args[0],args[1]);
	case 3:
		return new cl(args[0],args[1],args[2]);
	case 4:
		return new cl(args[0],args[1],args[2],args[3]);
	case 5:
		return new cl(args[0],args[1],args[2],args[3],args[4]);
	case 6:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5]);
	case 7:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
	case 8:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6],args[7]);
	default:
		throw new js__$Boot_HaxeError("Too many arguments");
	}
	return null;
};
var fluid_core_display_DisplayObject = function() {
	this._tempDisplayObjectParent = { worldTransform : new fluid_core_math_Matrix(), worldAlpha : 1, children : []};
	this.added = new msignal_Signal1(fluid_core_display_Container);
	this.removed = new msignal_Signal1(fluid_core_display_Container);
	this.position = new fluid_core_math_Point();
	this.scale = new fluid_core_math_Point(1,1);
	this.pivot = new fluid_core_math_Point(0,0);
	this.skew = new fluid_core_math_Point(0,0);
	this.rotation = 0;
	this.alpha = 1;
	this.visible = true;
	this.renderable = true;
	this.parent = null;
	this.worldAlpha = 1;
	this.worldTransform = new fluid_core_math_Matrix();
	this.filterArea = null;
	this._sr = 0;
	this._cr = 1;
	this._bounds = new fluid_core_math_shapes_Rectangle(0,0,1,1);
	this._currentBounds = null;
	this._mask = null;
	this._tempMatrix = new fluid_core_math_Matrix();
	this.displayObjectUpdateTransform = $bind(this,this.updateTransform);
	this.containerGetBounds = $bind(this,this.getBounds);
};
fluid_core_display_DisplayObject.__name__ = true;
fluid_core_display_DisplayObject.prototype = {
	set_filters: function(value) {
		return value != null?this._filters = value.slice(0):this._filters = null;
	}
	,get_filters: function() {
		if(this._filters != null) return this._filters.slice(0); else return null;
	}
	,getBounds: function(matrix) {
		return fluid_core_math_shapes_Rectangle.EMPTY;
	}
	,getLocalBounds: function() {
		return this.getBounds(fluid_core_math_Matrix.IDENTITY);
	}
	,toGlobal: function(position) {
		if(this.parent == null) {
			this.parent = this._tempDisplayObjectParent;
			this.displayObjectUpdateTransform();
			this.parent = null;
		} else this.displayObjectUpdateTransform();
		return this.worldTransform.apply(position);
	}
	,toLocal: function(position,from,point) {
		if(from != null) position = from.toGlobal(position);
		if(this.parent == null) {
			this.parent = this._tempDisplayObjectParent;
			this.displayObjectUpdateTransform();
			this.parent = null;
		} else this.displayObjectUpdateTransform();
		return this.worldTransform.applyInverse(position,point);
	}
	,updateTransform: function() {
		var pt = this.parent.worldTransform;
		var wt = this.worldTransform;
		var a;
		var b;
		var c;
		var d;
		var tx;
		var ty;
		if(this.skew.x != null || this.skew.y != null) {
			this._tempMatrix.setTransform(this.position.x,this.position.y,this.pivot.x,this.pivot.y,this.scale.x,this.scale.y,this.rotation,this.skew.x,this.skew.y);
			wt.a = this._tempMatrix.a * pt.a + this._tempMatrix.b * pt.c;
			wt.b = this._tempMatrix.a * pt.b + this._tempMatrix.b * pt.d;
			wt.c = this._tempMatrix.c * pt.a + this._tempMatrix.d * pt.c;
			wt.d = this._tempMatrix.c * pt.b + this._tempMatrix.d * pt.d;
			wt.tx = this._tempMatrix.tx * pt.a + this._tempMatrix.ty * pt.c + pt.tx;
			wt.ty = this._tempMatrix.tx * pt.b + this._tempMatrix.ty * pt.d + pt.ty;
		} else if(this.rotation % Fluid.PI_2 != null) {
			if(this.rotation != this.rotationCache) {
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
			if(this.pivot.x != null || this.pivot.y != null) {
				tx -= this.pivot.x * a + this.pivot.y * c;
				ty -= this.pivot.x * b + this.pivot.y * d;
			}
			wt.a = a * pt.a + b * pt.c;
			wt.b = a * pt.b + b * pt.d;
			wt.c = c * pt.a + d * pt.c;
			wt.d = c * pt.b + d * pt.d;
			wt.tx = tx * pt.a + ty * pt.c + pt.tx;
			wt.ty = tx * pt.b + ty * pt.d + pt.ty;
		} else {
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
		this.worldAlpha = this.alpha * this.parent.worldAlpha;
		this._currentBounds = null;
	}
	,renderWebGL: function(renderer) {
	}
	,generateTexture: function(renderer,resolution,scaleMode) {
		if(scaleMode == null) scaleMode = 0;
		if(resolution == null) resolution = 1;
		var bounds = this.getLocalBounds();
		if(bounds.width == null) bounds.width = 0;
		if(bounds.height == null) bounds.height = 0;
		var renderTexture = new PIXI.RenderTexture(renderer,bounds.width,bounds.height,scaleMode,resolution);
		this._tempMatrix.tx = -bounds.x;
		this._tempMatrix.ty = -bounds.y;
		renderTexture.render(this,this._tempMatrix);
		return renderTexture;
	}
	,setParent: function(container) {
		if(container == null || container.addChild == null) throw new Error("setParent: Argument must be a Container");
		container.addChild(this);
		return container;
	}
	,setTransform: function(x,y,scaleX,scaleY,rotation,skewX,skewY,pivotX,pivotY) {
		if(pivotY == null) pivotY = 0;
		if(pivotX == null) pivotX = 0;
		if(skewY == null) skewY = 0;
		if(skewX == null) skewX = 0;
		if(rotation == null) rotation = 0;
		if(scaleY == null) scaleY = 1;
		if(scaleX == null) scaleX = 1;
		if(y == null) y = 0;
		if(x == null) x = 0;
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
	,destroy: function(destroyTexture,destroyBaseTexture) {
		if(destroyBaseTexture == null) destroyBaseTexture = false;
		if(destroyTexture == null) destroyTexture = false;
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
};
var fluid_core_display_Container = function() {
	fluid_core_display_DisplayObject.call(this);
	this.children = [];
};
fluid_core_display_Container.__name__ = true;
fluid_core_display_Container.__super__ = fluid_core_display_DisplayObject;
fluid_core_display_Container.prototype = $extend(fluid_core_display_DisplayObject.prototype,{
	set_width: function(value) {
		var width = this.getLocalBounds().width;
		if(width != 0) this.scale.x = value / width; else this.scale.x = 1;
		return this._width = value;
	}
	,get_width: function() {
		return this.scale.x * this.getLocalBounds().width;
	}
	,set_height: function(value) {
		var height = this.getLocalBounds().height;
		if(height != 0) this.scale.y = value / height; else this.scale.y = 1;
		return this._height = value;
	}
	,get_height: function() {
		return this.scale.y * this.getLocalBounds().height;
	}
	,renderWebGL: function(renderer) {
		if(!this.visible || this.worldAlpha <= 0 || !this.renderable) return;
		var i;
		var j;
		if(this._mask != null || this._filters != null) {
			renderer.currentRenderer.flush();
			if(this._filters != null && this._filters.length > 0) renderer.filterManager.pushFilter(this,this._filters);
			if(this._mask != null) renderer.maskManager.pushMask(this,this._mask);
			renderer.currentRenderer.start();
			this._renderWebGL(renderer);
			i = 0;
			j = this.children.length;
			while(i < j) {
				this.children[i].renderWebGL(renderer);
				i++;
			}
			renderer.currentRenderer.flush();
			if(this._mask) renderer.maskManager.popMask(this,this._mask);
			if(this._filters != null) renderer.filterManager.popFilter();
			renderer.currentRenderer.start();
		} else {
			this._renderWebGL(renderer);
			i = 0;
			j = this.children.length;
			while(i < j) {
				this.children[i].renderWebGL(renderer);
				i++;
			}
		}
	}
	,_renderWebGL: function(renderer) {
	}
	,addChild: function(child) {
		if(child.parent != null) child.parent.removeChild(child);
		child.parent = this;
		this.children.push(child);
		child.added.dispatch(this);
		return child;
	}
	,addChildAt: function(child,index) {
		if(index >= 0 && index <= this.children.length) {
			if(child.parent != null) child.parent.removeChild(child);
			child.parent = this;
			this.children.splice(index,0,child);
			child.added.dispatch(this);
			return child;
		} else throw new Error(Std.string(child) + "addChildAt: The index " + index + " supplied is out of bounds " + this.children.length);
	}
	,swapChildren: function(child1,child2) {
	}
	,setChildIndex: function(child,index) {
	}
	,removeChild: function(child) {
		var index = HxOverrides.indexOf(this.children,child,0);
		if(index == -1) return null;
		child.parent = null;
		fluid_core_utils_Utils.removeItems(this.children,index,1);
		child.removed.dispatch(this);
		return child;
	}
});
var fluid_core_math_Matrix = function() {
	this.a = 1;
	this.b = 0;
	this.c = 0;
	this.d = 1;
	this.tx = 0;
	this.ty = 0;
};
fluid_core_math_Matrix.__name__ = true;
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
fluid_core_math_Point.__name__ = true;
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
var fluid_core_math_shapes_Circle = function(x,y,radius) {
	if(radius == null) radius = 0;
	if(y == null) y = 0;
	if(x == null) x = 0;
	this.x = x;
	this.y = y;
	this.radius = radius;
	this.type = Fluid.SHAPES.CIRC;
};
fluid_core_math_shapes_Circle.__name__ = true;
fluid_core_math_shapes_Circle.prototype = {
	clone: function() {
		return new fluid_core_math_shapes_Circle(this.x,this.y,this.radius);
	}
	,contains: function(x,y) {
		if(this.radius <= 0) return false;
		var dx = this.x - x;
		var dy = this.y - y;
		var r2 = this.radius * this.radius;
		dx *= dx;
		dy *= dy;
		return dx + dy <= r2;
	}
	,getBounds: function() {
		return new fluid_core_math_shapes_Rectangle(this.x - this.radius,this.y - this.radius,this.radius * 2,this.radius * 2);
	}
};
var fluid_core_math_shapes_Ellipse = function(x,y,width,height) {
	if(height == null) height = 0;
	if(width == null) width = 0;
	if(y == null) y = 0;
	if(x == null) x = 0;
	this.x = x;
	this.y = y;
	this.width = width;
	this.height = height;
	this.type = Fluid.SHAPES.ELIP;
};
fluid_core_math_shapes_Ellipse.__name__ = true;
fluid_core_math_shapes_Ellipse.prototype = {
	clone: function() {
		return new fluid_core_math_shapes_Ellipse(this.x,this.y,this.width,this.height);
	}
	,contains: function(x,y) {
		if(this.width <= 0 || this.height <= 0) return false;
		var normx = (x - this.x) / this.width;
		var normy = (y - this.y) / this.height;
		normx *= normx;
		normy *= normy;
		return normx + normy <= 1;
	}
	,getBounds: function() {
		return new fluid_core_math_shapes_Rectangle(this.x - this.width,this.y - this.height,this.width,this.height);
	}
};
var fluid_core_math_shapes_Polygon = function(points) {
	this._points = points;
	var p = [];
	var _g1 = 0;
	var _g = points.length;
	while(_g1 < _g) {
		var i = _g1++;
		p.push(points[i].x);
		p.push(points[i].y);
	}
	this.points = p;
	this.type = Fluid.SHAPES.POLY;
};
fluid_core_math_shapes_Polygon.__name__ = true;
fluid_core_math_shapes_Polygon.prototype = {
	clone: function() {
		return new fluid_core_math_shapes_Polygon(this._points);
	}
	,contains: function(x,y) {
		var inside = false;
		var length = this.points.length / 2 | 0;
		var j = length - 1;
		var _g = 0;
		while(_g < length) {
			var i = _g++;
			var xi = this.points[i * 2];
			var yi = this.points[i * 2 + 1];
			var xj = this.points[j * 2];
			var yj = this.points[j * 2 + 1];
			var intersect = yi > y != yj > y && x < (xj - xi) * (y - yi) / (yj - yi) + xi;
			if(intersect) inside = !inside;
			j = i;
		}
		return inside;
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
fluid_core_math_shapes_Rectangle.__name__ = true;
fluid_core_math_shapes_Rectangle.prototype = {
	clone: function() {
		return new fluid_core_math_shapes_Rectangle(this.x,this.y,this.width,this.height);
	}
	,contains: function(x,y) {
		if(this.width <= 0 || this.height <= 0) return false;
		return x >= this.x && x < this.x + this.width && (y >= this.y && y < this.y + this.height);
	}
};
var fluid_core_renderers_webgl_managers_WebGLManager = function(renderer) {
	this.renderer = renderer;
	this.renderer.context.add($bind(this,this._onContextChange));
};
fluid_core_renderers_webgl_managers_WebGLManager.__name__ = true;
fluid_core_renderers_webgl_managers_WebGLManager.prototype = {
	_onContextChange: function(gl) {
	}
	,destroy: function() {
		this.renderer.context.remove($bind(this,this._onContextChange));
		this.renderer = null;
	}
};
var fluid_core_renderers_webgl_managers_BlendModeManager = function(renderer) {
	fluid_core_renderers_webgl_managers_WebGLManager.call(this,renderer);
	this.currentBlendMode = 99999;
};
fluid_core_renderers_webgl_managers_BlendModeManager.__name__ = true;
fluid_core_renderers_webgl_managers_BlendModeManager.__super__ = fluid_core_renderers_webgl_managers_WebGLManager;
fluid_core_renderers_webgl_managers_BlendModeManager.prototype = $extend(fluid_core_renderers_webgl_managers_WebGLManager.prototype,{
	setBlendMode: function(blendMode) {
		if(this.currentBlendMode == blendMode) return false;
		this.currentBlendMode = blendMode;
		var mode = this.renderer.blendModes[this.currentBlendMode];
		this.renderer.gl.blendFunc(mode[0],mode[1]);
		return true;
	}
});
var fluid_core_renderers_webgl_managers_FilterManager = function(renderer) {
	fluid_core_renderers_webgl_managers_WebGLManager.call(this,renderer);
	this.filterStack = [];
	this.filterStack.push({ renderTarget : renderer.currentRenderTarget, filter : [], bounds : null});
	this.texturePool = [];
	this.textureSize = new fluid_core_math_shapes_Rectangle(0,0,renderer.width,renderer.height);
	this.currentFrame = null;
};
fluid_core_renderers_webgl_managers_FilterManager.__name__ = true;
fluid_core_renderers_webgl_managers_FilterManager.__super__ = fluid_core_renderers_webgl_managers_WebGLManager;
fluid_core_renderers_webgl_managers_FilterManager.prototype = $extend(fluid_core_renderers_webgl_managers_WebGLManager.prototype,{
	_onContextChange: function(gl) {
		this.texturePool = [];
		var gl1 = this.renderer.gl;
		this.quad = new fluid_core_renderers_webgl_utils_Quad(this.renderer.gl);
	}
	,setFilterStack: function(filterStack) {
		this.filterStack = filterStack;
	}
	,pushFilter: function(target,filters) {
		
			var bounds = target.filterArea ? target.filterArea.clone() : target.getBounds();

			//bounds = bounds.clone();

			// round off the rectangle to get a nice smoooooooth filter :)
			bounds.x = bounds.x | 0;
			bounds.y = bounds.y | 0;
			bounds.width = bounds.width | 0;
			bounds.height = bounds.height | 0;


			// padding!
			var padding = filters[0].padding | 0;
			bounds.x -= padding;
			bounds.y -= padding;
			bounds.width += padding * 2;
			bounds.height += padding * 2;


			if(this.renderer.currentRenderTarget.transform)
			{
				//TODO this will break if the renderTexture transform is anything other than a translation.
				//Will need to take the full matrix transform into acount..
				var transform = this.renderer.currentRenderTarget.transform;

				bounds.x += transform.tx;
				bounds.y += transform.ty;

				this.capFilterArea( bounds );

				bounds.x -= transform.tx;
				bounds.y -= transform.ty;
			}
			else
			{
				 this.capFilterArea( bounds );
			}

			if(bounds.width > 0 && bounds.height > 0)
			{
				this.currentFrame = bounds;

				var texture = this.getRenderTarget();

				this.renderer.setRenderTarget(texture);

				// clear the texture..
				texture.clear();

				// TODO get rid of object creation!
				this.filterStack.push({
					renderTarget: texture,
					filter: filters
				});

			}
			else
			{
				// push somthing on to the stack that is empty
				this.filterStack.push({
					renderTarget: null,
					filter: filters
				});
			}
		;
	}
	,popFilter: function() {
		
			var filterData = this.filterStack.pop();
			var previousFilterData = this.filterStack[this.filterStack.length-1];

			var input = filterData.renderTarget;

			// if the renderTarget is null then we don't apply the filter as its offscreen
			if(!filterData.renderTarget)
			{
				return;
			}

			var output = previousFilterData.renderTarget;

			// use program
			var gl = this.renderer.gl;


			this.currentFrame = input.frame;

			this.quad.map(this.textureSize, input.frame);


			// TODO.. this probably only needs to be done once!
			gl.bindBuffer(gl.ARRAY_BUFFER, this.quad.vertexBuffer);
			gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.quad.indexBuffer);

			var filters = filterData.filter;

			// assuming all filters follow the correct format??
			gl.vertexAttribPointer(this.renderer.shaderManager.defaultShader.attributes.aVertexPosition, 2, gl.FLOAT, false, 0, 0);
			gl.vertexAttribPointer(this.renderer.shaderManager.defaultShader.attributes.aTextureCoord, 2, gl.FLOAT, false, 0, 2 * 4 * 4);
			gl.vertexAttribPointer(this.renderer.shaderManager.defaultShader.attributes.aColor, 4, gl.FLOAT, false, 0, 4 * 4 * 4);

			// restore the normal blendmode!
			this.renderer.blendModeManager.setBlendMode(CONST.BLEND_MODES.NORMAL);

			if (filters.length === 1)
			{
				// TODO (cengler) - There has to be a better way then setting this each time?
				if (filters[0].uniforms.dimensions)
				{
					filters[0].uniforms.dimensions.value[0] = this.renderer.width;
					filters[0].uniforms.dimensions.value[1] = this.renderer.height;
					filters[0].uniforms.dimensions.value[2] = this.quad.vertices[0];
					filters[0].uniforms.dimensions.value[3] = this.quad.vertices[5];
				}

				filters[0].applyFilter( this.renderer, input, output );
				this.returnRenderTarget( input );

			}
			else
			{
				var flipTexture = input;
				var flopTexture = this.getRenderTarget(true);

				for (var i = 0; i < filters.length-1; i++)
				{
					var filter = filters[i];

					// TODO (cengler) - There has to be a better way then setting this each time?
					if (filter.uniforms.dimensions)
					{
						filter.uniforms.dimensions.value[0] = this.renderer.width;
						filter.uniforms.dimensions.value[1] = this.renderer.height;
						filter.uniforms.dimensions.value[2] = this.quad.vertices[0];
						filter.uniforms.dimensions.value[3] = this.quad.vertices[5];
					}

					filter.applyFilter( this.renderer, flipTexture, flopTexture );

					var temp = flipTexture;
					flipTexture = flopTexture;
					flopTexture = temp;
				}

				filters[filters.length-1].applyFilter( this.renderer, flipTexture, output );

				this.returnRenderTarget( flipTexture );
				this.returnRenderTarget( flopTexture );
			}

			return filterData.filter;
		;
		return null;
	}
	,getRenderTarget: function(clear) {
		if(clear == null) clear = false;
		var renderTarget = this.texturePool.pop();
		if(renderTarget == null) renderTarget = new fluid_core_renderers_webgl_utils_RenderTarget(this.renderer.gl,this.textureSize.width,this.textureSize.height,Fluid.SCALE_MODES.LINEAR,this.renderer.resolution * Fluid.FILTER_RESOLUTION);
		renderTarget.frame = this.currentFrame;
		if(clear) renderTarget.clear(true);
		return renderTarget;
	}
	,returnRenderTarget: function(renderTarget) {
		this.texturePool.push(renderTarget);
	}
	,applyFilter: function(shader,inputTarget,outputTarget,clear) {
		if(clear == null) clear = false;
		var gl = this.renderer.gl;
		this.renderer.setRenderTarget(outputTarget);
		if(clear) outputTarget.clear();
		this.renderer.shaderManager.setShader(shader);
		shader.uniforms.projectionMatrix.value = this.renderer.currentRenderTarget.projectionMatrix.toArray(true,null);
		shader.syncUniforms();
		gl.activeTexture(33984);
		gl.bindTexture(3553,inputTarget.texture);
		gl.drawElements(4,6,5123,0);
		this.renderer.drawCount++;
	}
	,calculateMappedMatrix: function(filterArea,sprite,outputMatrix) {
		var worldTransform = sprite.worldTransform.copy(fluid_core_math_Matrix.TEMP_MATRIX);
		var texture = sprite._texture.baseTexture;
		var mappedMatrix = outputMatrix.identity();
		var ratio = this.textureSize.height / this.textureSize.width;
		mappedMatrix.translate(filterArea.x / this.textureSize.width,filterArea.y / this.textureSize.height);
		mappedMatrix.scale(1,ratio);
		var translateScaleX = this.textureSize.width / texture.width;
		var translateScaleY = this.textureSize.height / texture.height;
		worldTransform.tx /= texture.width * translateScaleX;
		worldTransform.ty /= texture.width * translateScaleX;
		worldTransform.invert();
		mappedMatrix.prepend(worldTransform);
		mappedMatrix.scale(1,1 / ratio);
		mappedMatrix.scale(translateScaleX,translateScaleY);
		mappedMatrix.translate(sprite.anchor.x,sprite.anchor.y);
		return mappedMatrix;
	}
	,capFilterArea: function(filterArea) {
		if(filterArea.x < 0) {
			filterArea.width += filterArea.x;
			filterArea.x = 0;
		}
		if(filterArea.y < 0) {
			filterArea.height += filterArea.y;
			filterArea.y = 0;
		}
		if(filterArea.x + filterArea.width > this.textureSize.width) filterArea.width = this.textureSize.width - filterArea.x;
		if(filterArea.y + filterArea.height > this.textureSize.height) filterArea.height = this.textureSize.height - filterArea.y;
	}
	,resize: function(width,height) {
		this.textureSize.width = width;
		this.textureSize.height = height;
		var _g1 = 0;
		var _g = this.texturePool.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.texturePool[i].resize(width,height);
		}
	}
	,destroy: function() {
		this.quad.destroy();
		fluid_core_renderers_webgl_managers_WebGLManager.prototype.destroy.call(this);
		this.filterStack = null;
		var _g1 = 0;
		var _g = this.texturePool.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.texturePool[i].destroy();
		}
		this.texturePool = null;
	}
});
var fluid_core_renderers_webgl_managers_MaskManager = function(renderer) {
	fluid_core_renderers_webgl_managers_WebGLManager.call(this,renderer);
	this.stencilStack = [];
	this.reverse = true;
	this.count = 0;
	this.alphaMaskPool = [];
};
fluid_core_renderers_webgl_managers_MaskManager.__name__ = true;
fluid_core_renderers_webgl_managers_MaskManager.__super__ = fluid_core_renderers_webgl_managers_WebGLManager;
fluid_core_renderers_webgl_managers_MaskManager.prototype = $extend(fluid_core_renderers_webgl_managers_WebGLManager.prototype,{
	pushMask: function(target,maskData) {
		if(maskData.texture != null) this.pushSpriteMask(target,maskData); else this.pushStencilMask(target,maskData);
	}
	,popMask: function(target,maskData) {
		if(maskData.texture != null) this.popSpriteMask(); else this.popStencilMask(target,maskData);
	}
	,pushSpriteMask: function(target,maskData) {
		var alphaMaskFilter = this.alphaMaskPool.pop();
		if(alphaMaskFilter != null) alphaMaskFilter = [new PIXI.AbstractFilter(maskData)];
		alphaMaskFilter[0].maskSprite = maskData;
		this.renderer.filterManager.pushFilter(target,alphaMaskFilter);
	}
	,popSpriteMask: function() {
		var filters = this.renderer.filterManager.popFilter();
		this.alphaMaskPool.push(filters);
	}
	,pushStencilMask: function(target,maskData) {
		this.renderer.stencilManager.pushMask(maskData);
	}
	,popStencilMask: function(target,maskData) {
		this.renderer.stencilManager.popMask(maskData);
	}
});
var fluid_core_renderers_webgl_managers_ShaderManager = function(renderer) {
	fluid_core_renderers_webgl_managers_WebGLManager.call(this,renderer);
	this.maxAttibs = 10;
	this.attribState = [];
	this.tempAttribState = [];
	var _g1 = 0;
	var _g = this.maxAttibs;
	while(_g1 < _g) {
		var i = _g1++;
		this.attribState[i] = false;
	}
	this.stack = [];
	this._currentId = -1;
	this.currentShader = null;
};
fluid_core_renderers_webgl_managers_ShaderManager.__name__ = true;
fluid_core_renderers_webgl_managers_ShaderManager.__super__ = fluid_core_renderers_webgl_managers_WebGLManager;
fluid_core_renderers_webgl_managers_ShaderManager.prototype = $extend(fluid_core_renderers_webgl_managers_WebGLManager.prototype,{
	_onContextChange: function(gl) {
		this.maxAttibs = gl.getParameter(34921);
		this.attribState = [];
		var _g1 = 0;
		var _g = this.maxAttibs;
		while(_g1 < _g) {
			var i = _g1++;
			this.attribState[i] = false;
		}
		this.defaultShader = new fluid_core_renderers_webgl_shaders_TextureShader(this);
		this.primitiveShader = new fluid_core_renderers_webgl_shaders_PrimitiveShader(this);
		this.complexPrimitiveShader = new fluid_core_renderers_webgl_shaders_ComplexPrimitiveShader(this);
	}
	,setAttribs: function(attribs) {
		var i;
		var _g1 = 0;
		var _g = this.tempAttribState.length;
		while(_g1 < _g) {
			var i1 = _g1++;
			this.tempAttribState[i1] = false;
		}
		var _g2 = 0;
		while(_g2 < attribs.length) {
			var a = attribs[_g2];
			++_g2;
			this.tempAttribState[attribs[a]] = true;
		}
		var gl = this.renderer.gl;
		var _g11 = 0;
		var _g3 = this.attribState.length;
		while(_g11 < _g3) {
			var i2 = _g11++;
			if(this.attribState[i2] != this.tempAttribState[i2]) {
				this.attribState[i2] = this.tempAttribState[i2];
				if(this.attribState[i2]) gl.enableVertexAttribArray(i2); else gl.disableVertexAttribArray(i2);
			}
		}
	}
	,setShader: function(shader) {
		if(this._currentId == shader.uid) return false;
		this._currentId = shader.uid;
		this.currentShader = shader;
		this.renderer.gl.useProgram(shader.program);
		this.setAttribs(shader.attributes);
		return true;
	}
	,destroy: function() {
		this.primitiveShader.destroy();
		this.complexPrimitiveShader.destroy();
		fluid_core_renderers_webgl_managers_WebGLManager.prototype.destroy.call(this);
		this.attribState = null;
		this.tempAttribState = null;
	}
});
var fluid_core_renderers_webgl_managers_StencilManager = function(renderer) {
	fluid_core_renderers_webgl_managers_WebGLManager.call(this,renderer);
	this.stencilMaskStack = null;
};
fluid_core_renderers_webgl_managers_StencilManager.__name__ = true;
fluid_core_renderers_webgl_managers_StencilManager.__super__ = fluid_core_renderers_webgl_managers_WebGLManager;
fluid_core_renderers_webgl_managers_StencilManager.prototype = $extend(fluid_core_renderers_webgl_managers_WebGLManager.prototype,{
	setMaskStack: function(stencilMaskStack) {
		this.stencilMaskStack = stencilMaskStack;
		var gl = this.renderer.gl;
		if(stencilMaskStack.stencilStack.length == 0) gl.disable(2960); else gl.enable(2960);
	}
	,pushStencil: function(graphics,webGLData) {
		this.renderer.currentRenderTarget.attachStencilBuffer();
		var gl = this.renderer.gl;
		var sms = this.stencilMaskStack;
		this.bindGraphics(graphics,webGLData);
		if(sms.stencilStack.length == 0) {
			gl.enable(2960);
			gl.clear(1024);
			sms.reverse = true;
			sms.count = 0;
		}
		sms.stencilStack.push(webGLData);
		var level = sms.count;
		gl.colorMask(false,false,false,false);
		gl.stencilFunc(519,0,255);
		gl.stencilOp(7680,7680,5386);
		if(webGLData.mode == 1) {
			gl.drawElements(6,webGLData.indices.length - 4 | 0,5123,0);
			if(sms.reverse) {
				gl.stencilFunc(514,255 - level,255);
				gl.stencilOp(7680,7680,7683);
			} else {
				gl.stencilFunc(514,level,255);
				gl.stencilOp(7680,7680,7682);
			}
			gl.drawElements(6,4,5123,(webGLData.indices.length - 4) * 2 | 0);
			if(sms.reverse) gl.stencilFunc(514,255 - (level + 1),255); else gl.stencilFunc(514,level + 1,255);
			sms.reverse = !sms.reverse;
		} else {
			if(!sms.reverse) {
				gl.stencilFunc(514,255 - level,255);
				gl.stencilOp(7680,7680,7683);
			} else {
				gl.stencilFunc(514,level,255);
				gl.stencilOp(7680,7680,7682);
			}
			gl.drawElements(5,webGLData.indices.length,5123,0);
			if(!sms.reverse) gl.stencilFunc(514,255 - (level + 1),255); else gl.stencilFunc(514,level + 1,255);
		}
		gl.colorMask(true,true,true,true);
		gl.stencilOp(7680,7680,7680);
		sms.count++;
	}
	,bindGraphics: function(graphics,webGLData) {
		var gl = this.renderer.gl;
		var shader;
		if(webGLData.mode == 1) {
			shader = this.renderer.shaderManager.complexPrimitiveShader;
			this.renderer.shaderManager.setShader(shader);
			gl.uniformMatrix3fv(shader.uniforms.translationMatrix._location,false,graphics.worldTransform.toArray(true,null));
			gl.uniformMatrix3fv(shader.uniforms.projectionMatrix._location,false,this.renderer.currentRenderTarget.projectionMatrix.toArray(true,null));
			gl.uniform3fv(shader.uniforms.tint._location,fluid_core_utils_Utils.hex2rgb(graphics.tint));
			gl.uniform3fv(shader.uniforms.color._location,webGLData.color);
			gl.uniform1f(shader.uniforms.alpha._location,graphics.worldAlpha);
			gl.bindBuffer(34962,webGLData.buffer);
			gl.vertexAttribPointer(shader.attributes.aVertexPosition,2,5126,false,8,0);
			gl.bindBuffer(34963,webGLData.indexBuffer);
		} else {
			shader = this.renderer.shaderManager.primitiveShader;
			this.renderer.shaderManager.setShader(shader);
			gl.uniformMatrix3fv(shader.uniforms.translationMatrix._location,false,graphics.worldTransform.toArray(true,null));
			gl.uniformMatrix3fv(shader.uniforms.projectionMatrix._location,false,this.renderer.currentRenderTarget.projectionMatrix.toArray(true,null));
			gl.uniform3fv(shader.uniforms.tint._location,fluid_core_utils_Utils.hex2rgb(graphics.tint));
			gl.uniform1f(shader.uniforms.alpha._location,graphics.worldAlpha);
			gl.bindBuffer(34962,webGLData.buffer);
			gl.vertexAttribPointer(shader.attributes.aVertexPosition,2,5126,false,24,0);
			gl.vertexAttribPointer(shader.attributes.aColor,4,5126,false,24,8);
			gl.bindBuffer(34963,webGLData.indexBuffer);
		}
	}
	,popStencil: function(graphics,webGLData) {
		var gl = this.renderer.gl;
		var sms = this.stencilMaskStack;
		sms.stencilStack.pop();
		sms.count--;
		if(sms.stencilStack.length == 0) gl.disable(2960); else {
			var level = sms.count;
			this.bindGraphics(graphics,webGLData);
			gl.colorMask(false,false,false,false);
			if(webGLData.mode == 1) {
				sms.reverse = !sms.reverse;
				if(sms.reverse) {
					gl.stencilFunc(514,255 - (level + 1),255);
					gl.stencilOp(7680,7680,7682);
				} else {
					gl.stencilFunc(514,level + 1,255);
					gl.stencilOp(7680,7680,7683);
				}
				gl.drawElements(6,4,5123,(webGLData.indices.length - 4) * 2 | 0);
				gl.stencilFunc(519,0,255);
				gl.stencilOp(7680,7680,5386);
				gl.drawElements(6,webGLData.indices.length - 4 | 0,5123,0);
				this.renderer.drawCount += 2;
				if(!sms.reverse) gl.stencilFunc(514,255 - level,255); else gl.stencilFunc(514,level,255);
			} else {
				if(!sms.reverse) {
					gl.stencilFunc(514,255 - (level + 1),255);
					gl.stencilOp(7680,7680,7682);
				} else {
					gl.stencilFunc(514,level + 1,255);
					gl.stencilOp(7680,7680,7683);
				}
				gl.drawElements(5,webGLData.indices.length,5123,0);
				this.renderer.drawCount++;
				if(!sms.reverse) gl.stencilFunc(514,255 - level,255); else gl.stencilFunc(514,level,255);
			}
			gl.colorMask(true,true,true,true);
			gl.stencilOp(7680,7680,7680);
		}
	}
	,destroy: function() {
		fluid_core_renderers_webgl_managers_WebGLManager.prototype.destroy.call(this);
		this.stencilMaskStack.stencilStack = null;
	}
	,pushMask: function(maskData) {
		this.renderer.setObjectRenderer(this.renderer.plugins.get("graphics"));
		if(maskData.dirty) this.renderer.plugins.get("graphics").updateGraphics(maskData,this.renderer.gl);
		if(!maskData._webGL[Reflect.field(this.renderer.gl,"id")].data.length) return;
		this.pushStencil(maskData,maskData._webGL[Reflect.field(this.renderer.gl,"id")].data[0]);
	}
	,popMask: function(maskData) {
		this.renderer.setObjectRenderer(this.renderer.plugins.get("graphics"));
		this.popStencil(maskData,maskData._webGL[Reflect.field(this.renderer.gl,"id")].data[0]);
	}
});
var fluid_core_renderers_webgl_shaders_Shader = function(shaderManager,vertexSrc,fragmentSrc,uniforms,attributes) {
	if(vertexSrc == null && fragmentSrc == null) throw new Error("Error. Shader requires vertexSrc and fragmentSrc");
	this.uid = fluid_core_utils_Utils.uid();
	this.gl = shaderManager.renderer.gl;
	this.shaderManager = shaderManager;
	this.program = null;
	if(uniforms != null) this.uniforms = uniforms; else this.uniforms = { };
	if(attributes != null) this.attributes = attributes; else this.attributes = { };
	this.textureCount = 1;
	this.vertexSrc = vertexSrc;
	this.fragmentSrc = fragmentSrc;
	this.init();
};
fluid_core_renderers_webgl_shaders_Shader.__name__ = true;
fluid_core_renderers_webgl_shaders_Shader.prototype = {
	init: function() {
		
			this.compile();
			this.gl.useProgram(this.program);
			this.cacheUniformLocations(Object.keys(this.uniforms));
			this.cacheAttributeLocations(Object.keys(this.attributes));
		;
	}
	,cacheUniformLocations: function(keys) {
		
			for (var i = 0; i < keys.length; ++i) {
        		this.uniforms[keys[i]]._location = this.gl.getUniformLocation(this.program, keys[i]);
    		}
		;
	}
	,cacheAttributeLocations: function(keys) {
		
			for (var i = 0; i < keys.length; ++i) {
        		this.attributes[keys[i]] = this.gl.getAttribLocation(this.program, keys[i]);
    		}
		;
	}
	,compile: function() {
		
			var gl = this.gl;

			var glVertShader = this._glCompile(gl.VERTEX_SHADER, this.vertexSrc);
			var glFragShader = this._glCompile(gl.FRAGMENT_SHADER, this.fragmentSrc);

			var program = gl.createProgram();

			gl.attachShader(program, glVertShader);
			gl.attachShader(program, glFragShader);
			gl.linkProgram(program);

			// if linking fails, then log and cleanup
			if (!gl.getProgramParameter(program, gl.LINK_STATUS))
			{
				console.error('Pixi.js Error: Could not initialize shader.');
				console.error('gl.VALIDATE_STATUS', gl.getProgramParameter(program, gl.VALIDATE_STATUS));
				console.error('gl.getError()', gl.getError());

				// if there is a program info log, log it
				if (gl.getProgramInfoLog(program) !== '')
				{
					console.warn('Pixi.js Warning: gl.getProgramInfoLog()', gl.getProgramInfoLog(program));
				}

				gl.deleteProgram(program);
				program = null;
			}

			// clean up some shaders
			gl.deleteShader(glVertShader);
			gl.deleteShader(glFragShader);

			return (this.program = program);
		;
	}
	,syncUniforms: function() {
		
			this.textureCount = 1;
			for (var key in this.uniforms) {
				this.syncUniform(this.uniforms[key]);
			}
		;
	}
	,syncUniform: function(uniform) {
		
			var location = uniform._location,
				value = uniform.value,
				gl = this.gl,
				i, il;

			switch (uniform.type)
			{
				case 'b':
				case 'bool':
				case 'boolean':
					gl.uniform1i(location, value ? 1 : 0);
					break;

				// single int value
				case 'i':
				case '1i':
					gl.uniform1i(location, value);
					break;

				// single float value
				case 'f':
				case '1f':
					gl.uniform1f(location, value);
					break;

				// Float32Array(2) or JS Arrray
				case '2f':
					gl.uniform2f(location, value[0], value[1]);
					break;

				// Float32Array(3) or JS Arrray
				case '3f':
					gl.uniform3f(location, value[0], value[1], value[2]);
					break;

				// Float32Array(4) or JS Arrray
				case '4f':
					gl.uniform4f(location, value[0], value[1], value[2], value[3]);
					break;

				// a 2D Point object
				case 'v2':
					gl.uniform2f(location, value.x, value.y);
					break;

				// a 3D Point object
				case 'v3':
					gl.uniform3f(location, value.x, value.y, value.z);
					break;

				// a 4D Point object
				case 'v4':
					gl.uniform4f(location, value.x, value.y, value.z, value.w);
					break;

				// Int32Array or JS Array
				case '1iv':
					gl.uniform1iv(location, value);
					break;

				// Int32Array or JS Array
				case '2iv':
					gl.uniform2iv(location, value);
					break;

				// Int32Array or JS Array
				case '3iv':
					gl.uniform3iv(location, value);
					break;

				// Int32Array or JS Array
				case '4iv':
					gl.uniform4iv(location, value);
					break;

				// Float32Array or JS Array
				case '1fv':
					gl.uniform1fv(location, value);
					break;

				// Float32Array or JS Array
				case '2fv':
					gl.uniform2fv(location, value);
					break;

				// Float32Array or JS Array
				case '3fv':
					gl.uniform3fv(location, value);
					break;

				// Float32Array or JS Array
				case '4fv':
					gl.uniform4fv(location, value);
					break;

				// Float32Array or JS Array
				case 'm2':
				case 'mat2':
				case 'Matrix2fv':
					gl.uniformMatrix2fv(location, uniform.transpose, value);
					break;

				// Float32Array or JS Array
				case 'm3':
				case 'mat3':
				case 'Matrix3fv':

					gl.uniformMatrix3fv(location, uniform.transpose, value);
					break;

				// Float32Array or JS Array
				case 'm4':
				case 'mat4':
				case 'Matrix4fv':
					gl.uniformMatrix4fv(location, uniform.transpose, value);
					break;

				// a Color Value
				case 'c':
					if (typeof value === 'number')
					{
						value = utils.hex2rgb(value);
					}

					gl.uniform3f(location, value[0], value[1], value[2]);
					break;

				// flat array of integers (JS or typed array)
				case 'iv1':
					gl.uniform1iv(location, value);
					break;

				// flat array of integers with 3 x N size (JS or typed array)
				case 'iv':
					gl.uniform3iv(location, value);
					break;

				// flat array of floats (JS or typed array)
				case 'fv1':
					gl.uniform1fv(location, value);
					break;

				// flat array of floats with 3 x N size (JS or typed array)
				case 'fv':
					gl.uniform3fv(location, value);
					break;

				// array of 2D Point objects
				case 'v2v':
					if (!uniform._array)
					{
						uniform._array = new Float32Array(2 * value.length);
					}

					for (i = 0, il = value.length; i < il; ++i)
					{
						uniform._array[i * 2]       = value[i].x;
						uniform._array[i * 2 + 1]   = value[i].y;
					}

					gl.uniform2fv(location, uniform._array);
					break;

				// array of 3D Point objects
				case 'v3v':
					if (!uniform._array)
					{
						uniform._array = new Float32Array(3 * value.length);
					}

					for (i = 0, il = value.length; i < il; ++i)
					{
						uniform._array[i * 3]       = value[i].x;
						uniform._array[i * 3 + 1]   = value[i].y;
						uniform._array[i * 3 + 2]   = value[i].z;

					}

					gl.uniform3fv(location, uniform._array);
					break;

				// array of 4D Point objects
				case 'v4v':
					if (!uniform._array)
					{
						uniform._array = new Float32Array(4 * value.length);
					}

					for (i = 0, il = value.length; i < il; ++i)
					{
						uniform._array[i * 4]       = value[i].x;
						uniform._array[i * 4 + 1]   = value[i].y;
						uniform._array[i * 4 + 2]   = value[i].z;
						uniform._array[i * 4 + 3]   = value[i].w;

					}

					gl.uniform4fv(location, uniform._array);
					break;

				// PIXI.Texture
				case 't':
				case 'sampler2D':

					if (!uniform.value || !uniform.value.baseTexture.hasLoaded)
					{
						break;
					}

					// activate this texture
					gl.activeTexture(gl['TEXTURE' + this.textureCount]);

					var texture = uniform.value.baseTexture._glTextures[gl.id];

					if (!texture)
					{
						this.initSampler2D(uniform);

						// set the textur to the newly created one..
						texture = uniform.value.baseTexture._glTextures[gl.id];
					}

					// bind the texture
					gl.bindTexture(gl.TEXTURE_2D, texture);

					// set uniform to texture index
					gl.uniform1i(uniform._location, this.textureCount);

					// increment next texture id
					this.textureCount++;

					break;

				default:
					console.warn('Pixi.js Shader Warning: Unknown uniform type: ' + uniform.type);
			}
		;
	}
	,initSampler2D: function(uniform) {
		
			var gl = this.gl;

			var texture = uniform.value.baseTexture;

			if(!texture.hasLoaded) {
				return;
			}

			if (uniform.textureData) {
				//TODO move this...
				var data = uniform.textureData;

				texture._glTextures[gl.id] = gl.createTexture();

				gl.bindTexture(gl.TEXTURE_2D, texture._glTextures[gl.id]);

				gl.pixelStorei(gl.UNPACK_PREMULTIPLY_ALPHA_WEBGL, texture.premultipliedAlpha);
				// GLTexture = mag linear, min linear_mipmap_linear, wrap repeat + gl.generateMipmap(gl.TEXTURE_2D);
				// GLTextureLinear = mag/min linear, wrap clamp
				// GLTextureNearestRepeat = mag/min NEAREST, wrap repeat
				// GLTextureNearest = mag/min nearest, wrap clamp
				// AudioTexture = whatever + luminance + width 512, height 2, border 0
				// KeyTexture = whatever + luminance + width 256, height 2, border 0

				//  magFilter can be: gl.LINEAR, gl.LINEAR_MIPMAP_LINEAR or gl.NEAREST
				//  wrapS/T can be: gl.CLAMP_TO_EDGE or gl.REPEAT

				gl.texImage2D(gl.TEXTURE_2D, 0, data.luminance ? gl.LUMINANCE : gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, texture.source);

				gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, data.magFilter ? data.magFilter : gl.LINEAR );
				gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, data.wrapS ? data.wrapS : gl.CLAMP_TO_EDGE );

				gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, data.wrapS ? data.wrapS : gl.CLAMP_TO_EDGE);
				gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, data.wrapT ? data.wrapT : gl.CLAMP_TO_EDGE);
			}
			else
			{
				this.shaderManager.renderer.updateTexture(texture);
			}
		;
	}
	,destroy: function() {
		this.gl.deleteProgram(this.program);
		this.gl = null;
		this.uniforms = null;
		this.attributes = null;
		this.vertexSrc = null;
		this.fragmentSrc = null;
	}
	,_glCompile: function(t,src) {
		var shader = this.gl.createShader(t);
		this.gl.shaderSource(shader,src);
		this.gl.compileShader(shader);
		if(!this.gl.getShaderParameter(shader,35713)) {
			window.console.log(this.gl.getShaderInfoLog(shader));
			return null;
		}
		return shader;
	}
};
var fluid_core_renderers_webgl_shaders_ComplexPrimitiveShader = function(shaderManager) {
	fluid_core_renderers_webgl_shaders_Shader.call(this,shaderManager,["attribute vec2 aVertexPosition;","uniform mat3 translationMatrix;","uniform mat3 projectionMatrix;","uniform vec3 tint;","uniform float alpha;","uniform vec3 color;","varying vec4 vColor;","void main(void){","   gl_Position = vec4((projectionMatrix * translationMatrix * vec3(aVertexPosition, 1.0)).xy, 0.0, 1.0);","   vColor = vec4(color * alpha * tint, alpha);","}"].join("\n"),["precision mediump float;","varying vec4 vColor;","void main(void){","   gl_FragColor = vColor;","}"].join("\n"),{ tint : { type : "3f", value : [0,0,0]}, alpha : { type : "1f", value : 0}, color : { type : "3f", value : [0,0,0]}, translationMatrix : { type : "mat3", value : new Float32Array(9)}, projectionMatrix : { type : "mat3", value : new Float32Array(9)}},{ aVertexPosition : 0});
};
fluid_core_renderers_webgl_shaders_ComplexPrimitiveShader.__name__ = true;
fluid_core_renderers_webgl_shaders_ComplexPrimitiveShader.__super__ = fluid_core_renderers_webgl_shaders_Shader;
fluid_core_renderers_webgl_shaders_ComplexPrimitiveShader.prototype = $extend(fluid_core_renderers_webgl_shaders_Shader.prototype,{
});
var fluid_core_renderers_webgl_shaders_PrimitiveShader = function(shaderManager) {
	fluid_core_renderers_webgl_shaders_Shader.call(this,shaderManager,["attribute vec2 aVertexPosition;","attribute vec4 aColor;","uniform mat3 translationMatrix;","uniform mat3 projectionMatrix;","uniform float alpha;","uniform float flipY;","uniform vec3 tint;","varying vec4 vColor;","void main(void){","   gl_Position = vec4((projectionMatrix * translationMatrix * vec3(aVertexPosition, 1.0)).xy, 0.0, 1.0);","   vColor = aColor * vec4(tint * alpha, alpha);","}"].join("\n"),["precision mediump float;","varying vec4 vColor;","void main(void){","   gl_FragColor = vColor;","}"].join("\n"),{ tint : { type : "3f", value : [0,0,0]}, alpha : { type : "1f", value : 0}, translationMatrix : { type : "mat3", value : new Float32Array(9)}, projectionMatrix : { type : "mat3", value : new Float32Array(9)}},{ aVertexPosition : 0, aColor : 0});
};
fluid_core_renderers_webgl_shaders_PrimitiveShader.__name__ = true;
fluid_core_renderers_webgl_shaders_PrimitiveShader.__super__ = fluid_core_renderers_webgl_shaders_Shader;
fluid_core_renderers_webgl_shaders_PrimitiveShader.prototype = $extend(fluid_core_renderers_webgl_shaders_Shader.prototype,{
});
var fluid_core_renderers_webgl_shaders_TextureShader = function(shaderManager,vertexSrc,fragmentSrc,customUniforms,customAttributes) {
	var uniforms = { uSampler : { type : "sampler2D", value : 0}, projectionMatrix : { type : "mat3", value : new Float32Array([1,0,0,0,1,0,0,0,1])}};
	var attributes = { aVertexPosition : 0, aTextureCoord : 0, aColor : 0};
	
			if (customUniforms) {
				for (var u in customUniforms) {
					uniforms[u] = customUniforms[u];
				}
			}

			if (customAttributes) {
				for (var a in customAttributes) {
					attributes[a] = customAttributes[a];
				}
			}
		;
	if(vertexSrc != null) vertexSrc = vertexSrc; else vertexSrc = fluid_core_renderers_webgl_shaders_TextureShader.defaultVertexSrc;
	if(fragmentSrc != null) fragmentSrc = fragmentSrc; else fragmentSrc = fluid_core_renderers_webgl_shaders_TextureShader.defaultFragmentSrc;
	fluid_core_renderers_webgl_shaders_Shader.call(this,shaderManager,vertexSrc,fragmentSrc,uniforms,attributes);
};
fluid_core_renderers_webgl_shaders_TextureShader.__name__ = true;
fluid_core_renderers_webgl_shaders_TextureShader.__super__ = fluid_core_renderers_webgl_shaders_Shader;
fluid_core_renderers_webgl_shaders_TextureShader.prototype = $extend(fluid_core_renderers_webgl_shaders_Shader.prototype,{
});
var fluid_core_renderers_webgl_utils_ObjectRenderer = function(renderer) {
	fluid_core_renderers_webgl_managers_WebGLManager.call(this,renderer);
};
fluid_core_renderers_webgl_utils_ObjectRenderer.__name__ = true;
fluid_core_renderers_webgl_utils_ObjectRenderer.__super__ = fluid_core_renderers_webgl_managers_WebGLManager;
fluid_core_renderers_webgl_utils_ObjectRenderer.prototype = $extend(fluid_core_renderers_webgl_managers_WebGLManager.prototype,{
	start: function() {
	}
	,stop: function() {
	}
	,flush: function() {
	}
	,render: function(object) {
	}
});
var fluid_core_renderers_webgl_utils_Quad = function(gl) {
	this.gl = gl;
	this.vertices = new Float32Array([0,0,200,0,200,200,0,200]);
	this.uvs = new Float32Array([0,0,1,0,1,1,0,1]);
	this.colors = new Float32Array([1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]);
	this.indices = new Uint16Array([0,1,2,0,3,2]);
	this.vertexBuffer = gl.createBuffer();
	this.indexBuffer = gl.createBuffer();
	gl.bindBuffer(34962,this.vertexBuffer);
	gl.bufferData(34962,128,35048);
	gl.bindBuffer(34963,this.indexBuffer);
	gl.bufferData(34963,this.indices,35044);
	this.upload();
};
fluid_core_renderers_webgl_utils_Quad.__name__ = true;
fluid_core_renderers_webgl_utils_Quad.prototype = {
	map: function(rect,rect2) {
		var x = 0;
		var y = 0;
		this.uvs[0] = x;
		this.uvs[1] = y;
		this.uvs[2] = x + rect2.width / rect.width;
		this.uvs[3] = y;
		this.uvs[4] = x + rect2.width / rect.width;
		this.uvs[5] = y + rect2.height / rect.height;
		this.uvs[6] = x;
		this.uvs[7] = y + rect2.height / rect.height;
		x = rect2.x;
		y = rect2.y;
		this.vertices[0] = x;
		this.vertices[1] = y;
		this.vertices[2] = x + rect2.width;
		this.vertices[3] = y;
		this.vertices[4] = x + rect2.width;
		this.vertices[5] = y + rect2.height;
		this.vertices[6] = x;
		this.vertices[7] = y + rect2.height;
		this.upload();
	}
	,upload: function() {
		var gl = this.gl;
		gl.bindBuffer(34962,this.vertexBuffer);
		gl.bufferSubData(34962,0,this.vertices);
		gl.bufferSubData(34962,32,this.uvs);
		gl.bufferSubData(34962,64,this.colors);
	}
	,destroy: function() {
		var gl = this.gl;
		gl.deleteBuffer(this.vertexBuffer);
		gl.deleteBuffer(this.indexBuffer);
	}
};
var fluid_core_renderers_webgl_utils_RenderTarget = function(gl,width,height,scaleMode,resolution,root) {
	if(root == null) root = false;
	if(resolution == null) resolution = 1;
	if(scaleMode == null) scaleMode = 0;
	this.gl = gl;
	this.frameBuffer = null;
	this.texture = null;
	this.size = new fluid_core_math_shapes_Rectangle(0,0,1,1);
	this.resolution = resolution;
	this.projectionMatrix = new fluid_core_math_Matrix();
	this.transform = null;
	this.frame = null;
	this.stencilBuffer = null;
	this.stencilMaskStack = new fluid_core_renderers_webgl_utils_StencilMaskStack();
	this.filterStack = [{ renderTarget : this, filter : [], bounds : this.size}];
	this.scaleMode = scaleMode;
	this.root = root;
	if(!this.root) {
		this.frameBuffer = gl.createFramebuffer();
		var texture = gl.createTexture();
		this.texture = texture;
		gl.bindTexture(3553,texture);
		gl.texParameteri(3553,10240,scaleMode == Fluid.SCALE_MODES.LINEAR?9729:9728);
		gl.texParameteri(3553,10241,scaleMode == Fluid.SCALE_MODES.LINEAR?9729:9728);
		var isPowerOfTwo = fluid_core_utils_Utils.isPowerOfTwo(width,height);
		if(!isPowerOfTwo) {
			gl.texParameteri(3553,10242,33071);
			gl.texParameteri(3553,10243,33071);
		} else {
			gl.texParameteri(3553,10242,10497);
			gl.texParameteri(3553,10243,10497);
		}
		gl.bindFramebuffer(36160,this.frameBuffer);
		gl.framebufferTexture2D(36160,36064,3553,texture,0);
	}
	this.resize(width,height);
};
fluid_core_renderers_webgl_utils_RenderTarget.__name__ = true;
fluid_core_renderers_webgl_utils_RenderTarget.prototype = {
	clear: function(bind) {
		if(bind == null) bind = false;
		var gl = this.gl;
		if(bind) gl.bindFramebuffer(36160,this.frameBuffer);
		gl.clearColor(0,0,0,0);
		gl.clear(16384);
	}
	,attachStencilBuffer: function() {
		if(this.stencilBuffer != null) return;
		if(!this.root) {
			var gl = this.gl;
			this.stencilBuffer = gl.createRenderbuffer();
			gl.bindRenderbuffer(36161,this.stencilBuffer);
			gl.framebufferRenderbuffer(36160,33306,36161,this.stencilBuffer);
			gl.renderbufferStorage(36161,34041,this.size.width * this.resolution | 0,this.size.height * this.resolution | 0);
		}
	}
	,activate: function() {
		var gl = this.gl;
		gl.bindFramebuffer(36160,this.frameBuffer);
		var projectionFrame;
		if(this.frame != null) projectionFrame = this.frame; else projectionFrame = this.size;
		this.calculateProjection(projectionFrame);
		if(this.transform != null) this.projectionMatrix.append(this.transform);
		gl.viewport(0,0,projectionFrame.width * this.resolution | 0,projectionFrame.height * this.resolution | 0);
	}
	,calculateProjection: function(projectionFrame) {
		var pm = this.projectionMatrix;
		pm.identity();
		if(!this.root) {
			pm.a = 1 / projectionFrame.width * 2;
			pm.d = 1 / projectionFrame.height * 2;
			pm.tx = -1 - projectionFrame.x * pm.a;
			pm.ty = -1 - projectionFrame.y * pm.d;
		} else {
			pm.a = 1 / projectionFrame.width * 2;
			pm.d = -1 / projectionFrame.height * 2;
			pm.tx = -1 - projectionFrame.x * pm.a;
			pm.ty = 1 - projectionFrame.y * pm.d;
		}
	}
	,resize: function(width,height) {
		if(height == null) height = 0;
		if(width == null) width = 0;
		if(this.size.width == width && this.size.height == height) return;
		this.size.width = width;
		this.size.height = height;
		if(!this.root) {
			var gl = this.gl;
			gl.bindTexture(3553,this.texture);
			gl.texImage2D(3553,0,6408,width * this.resolution | 0,height * this.resolution | 0,0,6408,5121,null);
			if(this.stencilBuffer != null) {
				gl.bindRenderbuffer(36161,this.stencilBuffer);
				gl.renderbufferStorage(36161,34041,width * this.resolution | 0,height * this.resolution | 0);
			}
		}
		var projectionFrame;
		if(this.frame != null) projectionFrame = this.frame; else projectionFrame = this.size;
		this.calculateProjection(projectionFrame);
	}
	,destroy: function() {
		var gl = this.gl;
		gl.deleteRenderbuffer(this.stencilBuffer);
		gl.deleteFramebuffer(this.frameBuffer);
		gl.deleteTexture(this.texture);
		this.frameBuffer = null;
		this.texture = null;
	}
};
var fluid_core_renderers_webgl_utils_StencilMaskStack = function() {
	this.stencilStack = [];
	this.reverse = true;
	this.count = 0;
};
fluid_core_renderers_webgl_utils_StencilMaskStack.__name__ = true;
var fluid_core_sprites_Sprite = function(texture) {
	this.tempPoint = new fluid_core_math_Point();
	fluid_core_display_Container.call(this);
	this.anchor = new fluid_core_math_Point();
	this._texture = null;
	this._width = 0;
	this._height = 0;
	this.tint = 16777215;
	this.blendMode = Fluid.BLEND_MODES.NORMAL;
	this.shader = null;
	this.cachedTint = 16777215;
	this.set_texture(texture != null?texture:fluid_core_textures_Texture.EMPTY);
};
fluid_core_sprites_Sprite.__name__ = true;
fluid_core_sprites_Sprite.fromFrame = function(frameId) {
	var texture = fluid_core_utils_Utils.TextureCache.get(frameId);
	if(texture == null) throw new Error("The frameId \"" + frameId + "\" does not exist in the texture cache");
	return new fluid_core_sprites_Sprite(texture);
};
fluid_core_sprites_Sprite.fromImage = function(imageId,crossorigin,scaleMode) {
	return new fluid_core_sprites_Sprite(fluid_core_textures_Texture.fromImage(imageId,crossorigin,scaleMode));
};
fluid_core_sprites_Sprite.__super__ = fluid_core_display_Container;
fluid_core_sprites_Sprite.prototype = $extend(fluid_core_display_Container.prototype,{
	set_width: function(value) {
		var sign = fluid_core_utils_Utils.sign(this.scale.x);
		if(sign == null) sign = 1;
		this.scale.x = sign * value / this.texture.frame.width;
		return this._width = value;
	}
	,get_width: function() {
		return Math.abs(this.scale.x) * this.texture.frame.width;
	}
	,set_height: function(value) {
		var sign = fluid_core_utils_Utils.sign(this.scale.y);
		if(sign == null) sign = 1;
		this.scale.y = sign * value / this.texture.frame.height;
		return this._height = value;
	}
	,get_height: function() {
		return Math.abs(this.scale.y) * this.texture.frame.height;
	}
	,set_texture: function(value) {
		if(this.texture == value) return value;
		this.cachedTint = 16777215;
		this.texture = value;
		if(value != null) {
			if(value.baseTexture.hasLoaded) this._onTextureUpdate(value); else value.updated.addOnce($bind(this,this._onTextureUpdate));
		}
		return value;
	}
	,_onTextureUpdate: function(txt) {
		this.scale.x = fluid_core_utils_Utils.sign(this.scale.x) * this._width / this.texture.frame.width;
		this.scale.y = fluid_core_utils_Utils.sign(this.scale.y) * this._height / this.texture.frame.height;
	}
	,_renderWebGL: function(renderer) {
		renderer.setObjectRenderer(renderer.plugins.get("sprite"));
		renderer.plugins.get("sprite").render(this);
	}
	,getBounds: function(matrix) {
		if(this._currentBounds == null) {
			var width = this.texture.frame.width;
			var height = this.texture.frame.height;
			var w0 = width * (1 - this.anchor.x);
			var w1 = width * -this.anchor.x;
			var h0 = height * (1 - this.anchor.y);
			var h1 = height * -this.anchor.y;
			var worldTransform = matrix;
			if(worldTransform == null) worldTransform = this.worldTransform;
			var a = worldTransform.a;
			var b = worldTransform.b;
			var c = worldTransform.c;
			var d = worldTransform.d;
			var tx = worldTransform.tx;
			var ty = worldTransform.ty;
			var minX;
			var maxX;
			var minY;
			var maxY;
			var x1 = a * w1 + c * h1 + tx;
			var y1 = d * h1 + b * w1 + ty;
			var x2 = a * w0 + c * h1 + tx;
			var y2 = d * h1 + b * w0 + ty;
			var x3 = a * w0 + c * h0 + tx;
			var y3 = d * h0 + b * w0 + ty;
			var x4 = a * w1 + c * h0 + tx;
			var y4 = d * h0 + b * w1 + ty;
			minX = x1;
			if(x2 < minX) minX = x2; else minX = minX;
			if(x3 < minX) minX = x3; else minX = minX;
			if(x4 < minX) minX = x4; else minX = minX;
			minY = y1;
			if(y2 < minY) minY = y2; else minY = minY;
			if(y3 < minY) minY = y3; else minY = minY;
			if(y4 < minY) minY = y4; else minY = minY;
			maxX = x1;
			if(x2 > maxX) maxX = x2; else maxX = maxX;
			if(x3 > maxX) maxX = x3; else maxX = maxX;
			if(x4 > maxX) maxX = x4; else maxX = maxX;
			maxY = y1;
			if(y2 > maxY) maxY = y2; else maxY = maxY;
			if(y3 > maxY) maxY = y3; else maxY = maxY;
			if(y4 > maxY) maxY = y4; else maxY = maxY;
			if(this.children.length > 0) {
				var childBounds = this.containerGetBounds();
				w0 = childBounds.x;
				w1 = childBounds.x + childBounds.width;
				h0 = childBounds.y;
				h1 = childBounds.y + childBounds.height;
				if(minX < w0) minX = minX; else minX = w0;
				if(minY < h0) minY = minY; else minY = h0;
				if(maxX > w1) maxX = maxX; else maxX = w1;
				if(maxY > h1) maxY = maxY; else maxY = h1;
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
	,getLocalBounds: function() {
		this._bounds.x = -this.texture.frame.width * this.anchor.x;
		this._bounds.y = -this.texture.frame.height * this.anchor.y;
		this._bounds.width = this.texture.frame.width;
		this._bounds.height = this.texture.frame.height;
		return this._bounds;
	}
	,containsPoint: function(point) {
		this.worldTransform.applyInverse(point,this.tempPoint);
		var width = this.texture.frame.width;
		var height = this.texture.frame.height;
		var x1 = -width * this.anchor.x;
		var y1;
		if(this.tempPoint.x > x1 && this.tempPoint.x < x1 + width) {
			y1 = -height * this.anchor.y;
			if(this.tempPoint.y > y1 && this.tempPoint.y < y1 + height) return true;
		}
		return false;
	}
	,destroy: function(destroyTexture,destroyBaseTexture) {
		if(destroyBaseTexture == null) destroyBaseTexture = false;
		if(destroyTexture == null) destroyTexture = false;
		fluid_core_display_Container.prototype.destroy.call(this);
		this.anchor = null;
		if(destroyTexture) this.texture.destroy(destroyBaseTexture);
		this.set_texture(null);
		this.shader = null;
	}
});
var fluid_core_sprites_webgl_SpriteRenderer = function(renderer) {
	fluid_core_renderers_webgl_utils_ObjectRenderer.call(this,renderer);
	this.vertSize = 5;
	this.vertByteSize = this.vertSize * 4;
	this.size = Fluid.SPRITE_BATCH_SIZE;
	var numVerts = this.size * 4 * this.vertByteSize | 0;
	var numIndices = this.size * 6 | 0;
	this.vertices = new ArrayBuffer(numVerts);
	this.positions = new Float32Array(this.vertices);
	this.colors = new Uint32Array(this.vertices);
	this.indices = new Uint16Array(numIndices);
	var j = 0;
	var i = 0;
	while(i < numIndices) {
		this.indices[i] = j;
		this.indices[i + 1] = j + 1;
		this.indices[i + 2] = j + 2;
		this.indices[i + 3] = j;
		this.indices[i + 4] = j + 2;
		this.indices[i + 5] = j + 3;
		i += 6;
		j += 4;
	}
	this.currentBatchSize = 0;
	this.sprites = [];
	this.shader = null;
};
fluid_core_sprites_webgl_SpriteRenderer.__name__ = true;
fluid_core_sprites_webgl_SpriteRenderer.__super__ = fluid_core_renderers_webgl_utils_ObjectRenderer;
fluid_core_sprites_webgl_SpriteRenderer.prototype = $extend(fluid_core_renderers_webgl_utils_ObjectRenderer.prototype,{
	_onContextChange: function(gl) {
		var gl1 = this.renderer.gl;
		this.shader = this.renderer.shaderManager.defaultShader;
		this.vertexBuffer = gl1.createBuffer();
		this.indexBuffer = gl1.createBuffer();
		gl1.bindBuffer(34963,this.indexBuffer);
		gl1.bufferData(34963,this.indices,35044);
		gl1.bindBuffer(34962,this.vertexBuffer);
		gl1.bufferData(34962,this.vertices,35048);
		this.currentBlendMode = 99999;
	}
	,render: function(sprite) {
		var texture = sprite.texture;
		if(this.currentBatchSize >= this.size) this.flush();
		var uvs = texture._uvs;
		if(uvs == null) return;
		var aX = sprite.anchor.x;
		var aY = sprite.anchor.y;
		var w0;
		var w1;
		var h0;
		var h1;
		if(texture.trim != null && sprite.tileScale == null) {
			var trim = texture.trim;
			w1 = trim.x - aX * trim.width;
			w0 = w1 + texture.crop.width;
			h1 = trim.y - aY * trim.height;
			h0 = h1 + texture.crop.height;
		} else {
			w0 = texture.frame.width * (1 - aX);
			w1 = texture.frame.width * -aX;
			h0 = texture.frame.height * (1 - aY);
			h1 = texture.frame.height * -aY;
		}
		var index = this.currentBatchSize * this.vertByteSize | 0;
		var worldTransform = sprite.worldTransform;
		var a = worldTransform.a;
		var b = worldTransform.b;
		var c = worldTransform.c;
		var d = worldTransform.d;
		var tx = worldTransform.tx;
		var ty = worldTransform.ty;
		var colors = this.colors;
		var positions = this.positions;
		if(this.renderer.roundPixels) {
			var resolution = this.renderer.resolution;
		} else {
			positions[index] = a * w1 + c * h1 + tx;
			positions[index + 1] = d * h1 + b * w1 + ty;
			positions[index + 5] = a * w0 + c * h1 + tx;
			positions[index + 6] = d * h1 + b * w0 + ty;
			positions[index + 10] = a * w0 + c * h0 + tx;
			positions[index + 11] = d * h0 + b * w0 + ty;
			positions[index + 15] = a * w1 + c * h0 + tx;
			positions[index + 16] = d * h0 + b * w1 + ty;
		}
		positions[index + 2] = uvs.x0;
		positions[index + 3] = uvs.y0;
		positions[index + 7] = uvs.x1;
		positions[index + 8] = uvs.y1;
		positions[index + 12] = uvs.x2;
		positions[index + 13] = uvs.y2;
		positions[index + 17] = uvs.x3;
		positions[index + 18] = uvs.y3;
		var tint = sprite.tint;
		this.sprites[this.currentBatchSize++] = sprite;
	}
	,flush: function() {
		
		 	if (this.currentBatchSize === 0)
			{
				return;
			}

			var gl = this.renderer.gl;
			var shader;

			// upload the verts to the buffer
			if (this.currentBatchSize > ( this.size * 0.5 ) )
			{
				gl.bufferSubData(gl.ARRAY_BUFFER, 0, this.vertices);
			}
			else
			{
				var view = this.positions.subarray(0, this.currentBatchSize * this.vertByteSize);
				gl.bufferSubData(gl.ARRAY_BUFFER, 0, view);
			}

			var nextTexture, nextBlendMode, nextShader;
			var batchSize = 0;
			var start = 0;

			var currentBaseTexture = null;
			var currentBlendMode = this.renderer.blendModeManager.currentBlendMode;
			var currentShader = null;

			var blendSwap = false;
			var shaderSwap = false;
			var sprite;

			for (var i = 0, j = this.currentBatchSize; i < j; i++)
			{

				sprite = this.sprites[i];

				nextTexture = sprite.texture.baseTexture;
				nextBlendMode = sprite.blendMode;
				nextShader = sprite.shader || this.shader;

				blendSwap = currentBlendMode !== nextBlendMode;
				shaderSwap = currentShader !== nextShader; // should I use uidS???

				if (currentBaseTexture !== nextTexture || blendSwap || shaderSwap)
				{
					this.renderBatch(currentBaseTexture, batchSize, start);

					start = i;
					batchSize = 0;
					currentBaseTexture = nextTexture;

					if (blendSwap)
					{
						currentBlendMode = nextBlendMode;
						this.renderer.blendModeManager.setBlendMode( currentBlendMode );
					}

					if (shaderSwap)
					{
						currentShader = nextShader;



						shader = currentShader.shaders ? currentShader.shaders[gl.id] : currentShader;

						if (!shader)
						{
							shader = currentShader.getShader(this.renderer);

						}

						// set shader function???
						this.renderer.shaderManager.setShader(shader);

						//TODO - i KNOW this can be optimised! Once v3 is stable il look at this next...
						shader.uniforms.projectionMatrix.value = this.renderer.currentRenderTarget.projectionMatrix.toArray(true);
						//Make this a little more dynamic / intelligent!
						shader.syncUniforms();

						//TODO investigate some kind of texture state managment??
						// need to make sure this texture is the active one for all the batch swaps..
						gl.activeTexture(gl.TEXTURE0);

						// both thease only need to be set if they are changing..
						// set the projection
						//gl.uniformMatrix3fv(shader.uniforms.projectionMatrix._location, false, this.renderer.currentRenderTarget.projectionMatrix.toArray(true));


					}
				}

				batchSize++;
			}

			this.renderBatch(currentBaseTexture, batchSize, start);

			// then reset the batch!
			this.currentBatchSize = 0;
		;
	}
	,renderBatch: function(texture,size,startIndex) {
		
			if (size === 0)
			{
				return;
			}

			var gl = this.renderer.gl;

			if (!texture._glTextures[gl.id])
			{
				this.renderer.updateTexture(texture);
			}
			else
			{
				// bind the current texture
				gl.bindTexture(gl.TEXTURE_2D, texture._glTextures[gl.id]);
			}

			// now draw those suckas!
			gl.drawElements(gl.TRIANGLES, size * 6, gl.UNSIGNED_SHORT, startIndex * 6 * 2);

			// increment the draw count
			this.renderer.drawCount++;
		;
	}
});
var fluid_core_textures_BaseTexture = function(source,scaleMode,resolution) {
	if(resolution == null) resolution = 1;
	if(scaleMode == null) scaleMode = 0;
	this.uid = fluid_core_utils_Utils.uid();
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
	this._glTextures = { };
	this.loaded = new msignal_Signal1(fluid_core_textures_BaseTexture);
	this.error = new msignal_Signal1(fluid_core_textures_BaseTexture);
	this.updated = new msignal_Signal1(fluid_core_textures_BaseTexture);
	this.disposed = new msignal_Signal1(fluid_core_textures_BaseTexture);
	if(source != null) this.loadSource(source);
};
fluid_core_textures_BaseTexture.__name__ = true;
fluid_core_textures_BaseTexture.fromImage = function(imageUrl,crossorigin,scaleMode) {
	if(scaleMode == null) scaleMode = 0;
	var baseTexture = fluid_core_utils_Utils.BaseTextureCache.get(imageUrl);
	crossorigin = crossorigin == null && imageUrl.indexOf("data:") != 0;
	if(baseTexture == null) {
		var image = new Image();
		if(crossorigin) image.crossOrigin = "";
		baseTexture = new fluid_core_textures_BaseTexture(image,scaleMode);
		baseTexture.imageUrl = imageUrl;
		image.src = imageUrl;
		fluid_core_utils_Utils.BaseTextureCache.set(imageUrl,baseTexture);
		baseTexture.resolution = fluid_core_utils_Utils.getResolutionOfUrl(imageUrl);
	}
	return baseTexture;
};
fluid_core_textures_BaseTexture.fromCanvas = function(canvas,scaleMode) {
	if(canvas._pixiId != null) canvas._pixiId = "canvas_" + fluid_core_utils_Utils.uid();
	var baseTexture;
	var key = canvas._pixiId;
	baseTexture = fluid_core_utils_Utils.BaseTextureCache.get(key);
	if(baseTexture != null) {
		baseTexture = new fluid_core_textures_BaseTexture(canvas,scaleMode);
		var k = canvas._pixiId;
		fluid_core_utils_Utils.BaseTextureCache.set(k,baseTexture);
		baseTexture;
	}
	return baseTexture;
};
fluid_core_textures_BaseTexture.prototype = {
	update: function() {
		if(this.source.naturalWidth != null) this.realWidth = this.source.naturalWidth; else this.realWidth = this.source.width;
		if(this.source.naturalHeight != null) this.realHeight = this.source.naturalHeight; else this.realHeight = this.source.height;
		this.width = this.realWidth / this.resolution | 0;
		this.height = this.realHeight / this.resolution | 0;
		this.isPowerOfTwo = fluid_core_utils_Utils.isPowerOfTwo(this.realWidth,this.realHeight);
	}
	,destroy: function() {
		if(this.imageUrl != null) {
			fluid_core_utils_Utils.BaseTextureCache.set(this.imageUrl,null);
			fluid_core_utils_Utils.TextureCache.set(this.imageUrl,null);
			this.imageUrl = null;
		} else if(this.source && this.source._pixiId) {
			var key = this.source._pixiId;
			fluid_core_utils_Utils.BaseTextureCache.set(key,null);
		}
		this.source = null;
		this.dispose();
	}
	,dispose: function() {
		this.disposed.dispatch(this);
		this._glTextures = null;
	}
	,loadSource: function(source) {
		var _g = this;
		var wasLoading = this.isLoading;
		this.hasLoaded = false;
		this.isLoading = false;
		if(wasLoading && this.source != null) {
			this.source.onload = null;
			this.source.onerror = null;
		}
		this.source = source;
		if((this.source.complete != null || this.source.getContext != null) && this.source.width != null && this.source.height != null) this._sourceLoaded(); else if(source.getContext != null) {
			this.isLoading = true;
			var scope = this;
			source.onload = function() {
				source.onload = null;
				source.onerror = null;
				if(!scope.isLoading) return;
				scope.isLoading = false;
				scope._sourceLoaded();
				_g.loaded.dispatch(scope);
			};
			source.onerror = function() {
				source.onload = null;
				source.onerror = null;
				if(!scope.isLoading) return;
				scope.isLoading = false;
				_g.error.dispatch(scope);
			};
			if(source.complete != null && source.src != null) {
				this.isLoading = false;
				source.onload = null;
				source.onerror = null;
				if(source.width && source.height) {
					this._sourceLoaded();
					if(wasLoading) this.loaded.dispatch(this);
				} else if(wasLoading) this.error.dispatch(this);
			}
		}
	}
	,_sourceLoaded: function() {
		this.hasLoaded = true;
		this.update();
	}
	,updateSourceImage: function(newSrc) {
		this.source.src = newSrc;
		this.loadSource(this.source);
	}
};
var msignal_Signal = function(valueClasses) {
	if(valueClasses == null) valueClasses = [];
	this.valueClasses = valueClasses;
	this.slots = msignal_SlotList.NIL;
	this.priorityBased = false;
};
msignal_Signal.__name__ = true;
msignal_Signal.prototype = {
	add: function(listener) {
		return this.registerListener(listener);
	}
	,addOnce: function(listener) {
		return this.registerListener(listener,true);
	}
	,addWithPriority: function(listener,priority) {
		if(priority == null) priority = 0;
		return this.registerListener(listener,false,priority);
	}
	,addOnceWithPriority: function(listener,priority) {
		if(priority == null) priority = 0;
		return this.registerListener(listener,true,priority);
	}
	,remove: function(listener) {
		var slot = this.slots.find(listener);
		if(slot == null) return null;
		this.slots = this.slots.filterNot(listener);
		return slot;
	}
	,removeAll: function() {
		this.slots = msignal_SlotList.NIL;
	}
	,registerListener: function(listener,once,priority) {
		if(priority == null) priority = 0;
		if(once == null) once = false;
		if(this.registrationPossible(listener,once)) {
			var newSlot = this.createSlot(listener,once,priority);
			if(!this.priorityBased && priority != 0) this.priorityBased = true;
			if(!this.priorityBased && priority == 0) this.slots = this.slots.prepend(newSlot); else this.slots = this.slots.insertWithPriority(newSlot);
			return newSlot;
		}
		return this.slots.find(listener);
	}
	,registrationPossible: function(listener,once) {
		if(!this.slots.nonEmpty) return true;
		var existingSlot = this.slots.find(listener);
		if(existingSlot == null) return true;
		if(existingSlot.once != once) throw new js__$Boot_HaxeError("You cannot addOnce() then add() the same listener without removing the relationship first.");
		return false;
	}
	,createSlot: function(listener,once,priority) {
		if(priority == null) priority = 0;
		if(once == null) once = false;
		return null;
	}
	,get_numListeners: function() {
		return this.slots.get_length();
	}
};
var msignal_Signal1 = function(type) {
	msignal_Signal.call(this,[type]);
};
msignal_Signal1.__name__ = true;
msignal_Signal1.__super__ = msignal_Signal;
msignal_Signal1.prototype = $extend(msignal_Signal.prototype,{
	dispatch: function(value) {
		var slotsToProcess = this.slots;
		while(slotsToProcess.nonEmpty) {
			slotsToProcess.head.execute(value);
			slotsToProcess = slotsToProcess.tail;
		}
	}
	,createSlot: function(listener,once,priority) {
		if(priority == null) priority = 0;
		if(once == null) once = false;
		return new msignal_Slot1(this,listener,once,priority);
	}
});
var msignal_SlotList = function(head,tail) {
	this.nonEmpty = false;
	if(head == null && tail == null) {
		if(msignal_SlotList.NIL != null) throw new js__$Boot_HaxeError("Parameters head and tail are null. Use the NIL element instead.");
		this.nonEmpty = false;
	} else if(head == null) throw new js__$Boot_HaxeError("Parameter head cannot be null."); else {
		this.head = head;
		if(tail == null) this.tail = msignal_SlotList.NIL; else this.tail = tail;
		this.nonEmpty = true;
	}
};
msignal_SlotList.__name__ = true;
msignal_SlotList.prototype = {
	get_length: function() {
		if(!this.nonEmpty) return 0;
		if(this.tail == msignal_SlotList.NIL) return 1;
		var result = 0;
		var p = this;
		while(p.nonEmpty) {
			++result;
			p = p.tail;
		}
		return result;
	}
	,prepend: function(slot) {
		return new msignal_SlotList(slot,this);
	}
	,append: function(slot) {
		if(slot == null) return this;
		if(!this.nonEmpty) return new msignal_SlotList(slot);
		if(this.tail == msignal_SlotList.NIL) return new msignal_SlotList(slot).prepend(this.head);
		var wholeClone = new msignal_SlotList(this.head);
		var subClone = wholeClone;
		var current = this.tail;
		while(current.nonEmpty) {
			subClone = subClone.tail = new msignal_SlotList(current.head);
			current = current.tail;
		}
		subClone.tail = new msignal_SlotList(slot);
		return wholeClone;
	}
	,insertWithPriority: function(slot) {
		if(!this.nonEmpty) return new msignal_SlotList(slot);
		var priority = slot.priority;
		if(priority >= this.head.priority) return this.prepend(slot);
		var wholeClone = new msignal_SlotList(this.head);
		var subClone = wholeClone;
		var current = this.tail;
		while(current.nonEmpty) {
			if(priority > current.head.priority) {
				subClone.tail = current.prepend(slot);
				return wholeClone;
			}
			subClone = subClone.tail = new msignal_SlotList(current.head);
			current = current.tail;
		}
		subClone.tail = new msignal_SlotList(slot);
		return wholeClone;
	}
	,filterNot: function(listener) {
		if(!this.nonEmpty || listener == null) return this;
		if(Reflect.compareMethods(this.head.listener,listener)) return this.tail;
		var wholeClone = new msignal_SlotList(this.head);
		var subClone = wholeClone;
		var current = this.tail;
		while(current.nonEmpty) {
			if(Reflect.compareMethods(current.head.listener,listener)) {
				subClone.tail = current.tail;
				return wholeClone;
			}
			subClone = subClone.tail = new msignal_SlotList(current.head);
			current = current.tail;
		}
		return this;
	}
	,contains: function(listener) {
		if(!this.nonEmpty) return false;
		var p = this;
		while(p.nonEmpty) {
			if(Reflect.compareMethods(p.head.listener,listener)) return true;
			p = p.tail;
		}
		return false;
	}
	,find: function(listener) {
		if(!this.nonEmpty) return null;
		var p = this;
		while(p.nonEmpty) {
			if(Reflect.compareMethods(p.head.listener,listener)) return p.head;
			p = p.tail;
		}
		return null;
	}
};
var fluid_core_textures_Texture = function(txt,frame,crop,trim,rotate) {
	if(rotate == null) rotate = false;
	this.noFrame = false;
	if(frame == null) {
		this.noFrame = true;
		frame = new fluid_core_math_shapes_Rectangle(0,0,1,1);
	}
	var baseTexture;
	if(txt.baseTexture != null) baseTexture = txt.baseTexture; else baseTexture = txt;
	this.baseTexture = baseTexture;
	this.set_frame(frame);
	this.trim = trim;
	this.valid = false;
	this.requiresUpdate = false;
	this._uvs = null;
	this.width = 0;
	this.height = 0;
	if(crop != null) this.crop = crop; else this.crop = frame;
	this.rotate = rotate;
	if(this.baseTexture.hasLoaded) {
		if(this.noFrame) {
			frame = new fluid_core_math_shapes_Rectangle(0,0,baseTexture.width,baseTexture.height);
			this.baseTexture.updated.add($bind(this,this._onBaseTextureUpdated));
		}
		this.set_frame(frame);
	} else this.baseTexture.loaded.add($bind(this,this._onBaseTextureLoaded));
	this.updated = new msignal_Signal1(fluid_core_textures_Texture);
	this.disposed = new msignal_Signal1(fluid_core_textures_Texture);
};
fluid_core_textures_Texture.__name__ = true;
fluid_core_textures_Texture.fromImage = function(imageUrl,crossorigin,scaleMode) {
	var texture = fluid_core_utils_Utils.TextureCache.get(imageUrl);
	if(texture == null) {
		texture = new fluid_core_textures_Texture(fluid_core_textures_BaseTexture.fromImage(imageUrl,crossorigin,scaleMode));
		fluid_core_utils_Utils.TextureCache.set(imageUrl,texture);
	}
	return texture;
};
fluid_core_textures_Texture.fromFrame = function(frameId) {
	var texture = fluid_core_utils_Utils.TextureCache.get(frameId);
	if(texture == null) throw new Error("The frameId \"" + frameId + "\" does not exist in the texture cache");
	return texture;
};
fluid_core_textures_Texture.fromCanvas = function(canvas,scaleMode) {
	if(scaleMode == null) scaleMode = 0;
	return new fluid_core_textures_Texture(fluid_core_textures_BaseTexture.fromCanvas(canvas,scaleMode));
};
fluid_core_textures_Texture.fromVideo = function(video,scaleMode) {
	return new fluid_core_textures_Texture(PIXI.VideoBaseTexture.fromVideo(video,scaleMode));
};
fluid_core_textures_Texture.fromVideoUrl = function(videoUrl,scaleMode) {
	return new fluid_core_textures_Texture(PIXI.VideoBaseTexture.fromUrl(videoUrl,scaleMode));
};
fluid_core_textures_Texture.addTextureToCache = function(texture,id) {
	fluid_core_utils_Utils.TextureCache.set(id,texture);
};
fluid_core_textures_Texture.removeTextureFromCache = function(id) {
	var texture = fluid_core_utils_Utils.TextureCache.get(id);
	fluid_core_utils_Utils.TextureCache.set(id,null);
	fluid_core_utils_Utils.BaseTextureCache.set(id,null);
	return texture;
};
fluid_core_textures_Texture.prototype = {
	set_frame: function(frame) {
		this.noFrame = false;
		this.width = frame.width;
		this.height = frame.height;
		if(this.trim != null && this.rotate != null && (frame.x + frame.width > this.baseTexture.width || frame.y + frame.height > this.baseTexture.height)) throw new Error("Texture Error: frame does not fit inside the base Texture dimensions " + Std.string(this));
		this.valid = frame != null && frame.width != null && frame.height != null && this.baseTexture.hasLoaded;
		if(this.trim != null) {
			this.width = this.trim.width;
			this.height = this.trim.height;
			this.frame.width = this.trim.width;
			this.frame.height = this.trim.height;
		} else this.crop = frame;
		if(this.valid) this._updateUvs();
		return this.frame = frame;
	}
	,_onBaseTextureLoaded: function(baseTexture) {
		if(this.noFrame) this.set_frame(new fluid_core_math_shapes_Rectangle(0,0,baseTexture.width,baseTexture.height));
	}
	,_onBaseTextureUpdated: function(baseTexture) {
		this.frame.width = baseTexture.width;
		this.frame.height = baseTexture.height;
	}
	,destroy: function(destroyBase) {
		if(this.baseTexture != null) {
			if(destroyBase) this.baseTexture.destroy();
			this.baseTexture.updated.remove($bind(this,this._onBaseTextureUpdated));
			this.baseTexture.loaded.remove($bind(this,this._onBaseTextureLoaded));
			this.baseTexture = null;
		}
		this.set_frame(null);
		this._uvs = null;
		this.trim = null;
		this.crop = null;
		this.valid = false;
		this.disposed.removeAll();
		this.updated.removeAll();
	}
	,update: function() {
		this.baseTexture.update();
	}
	,_updateUvs: function() {
		if(this._uvs == null) this._uvs = new fluid_core_textures_TextureUvs();
		this._uvs.set(this.crop,this.baseTexture,this.rotate);
	}
};
var fluid_core_textures_TextureUvs = function() {
	this.x0 = 0;
	this.y0 = 0;
	this.x1 = 1;
	this.y1 = 0;
	this.x2 = 1;
	this.y2 = 1;
	this.x3 = 0;
	this.y3 = 1;
};
fluid_core_textures_TextureUvs.__name__ = true;
fluid_core_textures_TextureUvs.prototype = {
	set: function(frame,baseFrame,rotate) {
		var tw = baseFrame.width;
		var th = baseFrame.height;
		if(rotate) {
			this.x0 = (frame.x + frame.height) / tw;
			this.y0 = frame.y / th;
			this.x1 = (frame.x + frame.height) / tw;
			this.y1 = (frame.y + frame.width) / th;
			this.x2 = frame.x / tw;
			this.y2 = (frame.y + frame.width) / th;
			this.x3 = frame.x / tw;
			this.y3 = frame.y / th;
		} else {
			this.x0 = frame.x / tw;
			this.y0 = frame.y / th;
			this.x1 = (frame.x + frame.width) / tw;
			this.y1 = frame.y / th;
			this.x2 = (frame.x + frame.width) / tw;
			this.y2 = (frame.y + frame.height) / th;
			this.x3 = frame.x / tw;
			this.y3 = (frame.y + frame.height) / th;
		}
	}
};
var fluid_core_utils_PluginTarget = function() {
	console.log("AFASFSAFS");
};
fluid_core_utils_PluginTarget.__name__ = true;
fluid_core_utils_PluginTarget.registerPlugin = function(obj,pluginName,ctor) {
	obj.__plugins.set(pluginName,ctor);
};
fluid_core_utils_PluginTarget.initPlugins = function(obj) {
	var $it0 = obj.__plugins.keys();
	while( $it0.hasNext() ) {
		var o = $it0.next();
		var value = Type.createInstance(obj.__plugins.get(o),[obj]);
		obj.plugins.set(o,value);
	}
};
fluid_core_utils_PluginTarget.destroyPlugins = function(obj) {
	var $it0 = obj.plugins.keys();
	while( $it0.hasNext() ) {
		var o = $it0.next();
		obj.plugins.get(o).destroy();
		obj.plugins.set(o,null);
	}
	obj.plugins = null;
};
var haxe_IMap = function() { };
haxe_IMap.__name__ = true;
var haxe_Timer = function(time_ms) {
	var me = this;
	this.id = setInterval(function() {
		me.run();
	},time_ms);
};
haxe_Timer.__name__ = true;
haxe_Timer.delay = function(f,time_ms) {
	var t = new haxe_Timer(time_ms);
	t.run = function() {
		t.stop();
		f();
	};
	return t;
};
haxe_Timer.prototype = {
	stop: function() {
		if(this.id == null) return;
		clearInterval(this.id);
		this.id = null;
	}
	,run: function() {
	}
};
var haxe_ds_StringMap = function() {
	this.h = { };
};
haxe_ds_StringMap.__name__ = true;
haxe_ds_StringMap.__interfaces__ = [haxe_IMap];
haxe_ds_StringMap.prototype = {
	set: function(key,value) {
		if(__map_reserved[key] != null) this.setReserved(key,value); else this.h[key] = value;
	}
	,get: function(key) {
		if(__map_reserved[key] != null) return this.getReserved(key);
		return this.h[key];
	}
	,setReserved: function(key,value) {
		if(this.rh == null) this.rh = { };
		this.rh["$" + key] = value;
	}
	,getReserved: function(key) {
		if(this.rh == null) return null; else return this.rh["$" + key];
	}
	,keys: function() {
		var _this = this.arrayKeys();
		return HxOverrides.iter(_this);
	}
	,arrayKeys: function() {
		var out = [];
		for( var key in this.h ) {
		if(this.h.hasOwnProperty(key)) out.push(key);
		}
		if(this.rh != null) {
			for( var key in this.rh ) {
			if(key.charCodeAt(0) == 36) out.push(key.substr(1));
			}
		}
		return out;
	}
};
var js__$Boot_HaxeError = function(val) {
	Error.call(this);
	this.val = val;
	this.message = String(val);
	if(Error.captureStackTrace) Error.captureStackTrace(this,js__$Boot_HaxeError);
};
js__$Boot_HaxeError.__name__ = true;
js__$Boot_HaxeError.__super__ = Error;
js__$Boot_HaxeError.prototype = $extend(Error.prototype,{
});
var js_Boot = function() { };
js_Boot.__name__ = true;
js_Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ || o.__ename__)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__) {
				if(o.length == 2) return o[0];
				var str2 = o[0] + "(";
				s += "\t";
				var _g1 = 2;
				var _g = o.length;
				while(_g1 < _g) {
					var i1 = _g1++;
					if(i1 != 2) str2 += "," + js_Boot.__string_rec(o[i1],s); else str2 += js_Boot.__string_rec(o[i1],s);
				}
				return str2 + ")";
			}
			var l = o.length;
			var i;
			var str1 = "[";
			s += "\t";
			var _g2 = 0;
			while(_g2 < l) {
				var i2 = _g2++;
				str1 += (i2 > 0?",":"") + js_Boot.__string_rec(o[i2],s);
			}
			str1 += "]";
			return str1;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			if (e instanceof js__$Boot_HaxeError) e = e.val;
			return "???";
		}
		if(tostr != null && tostr != Object.toString && typeof(tostr) == "function") {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) {
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str.length != 2) str += ", \n";
		str += s + k + " : " + js_Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str += "\n" + s + "}";
		return str;
	case "function":
		return "<function>";
	case "string":
		return o;
	default:
		return String(o);
	}
};
var js_html__$CanvasElement_CanvasUtil = function() { };
js_html__$CanvasElement_CanvasUtil.__name__ = true;
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
var msignal_Signal0 = function() {
	msignal_Signal.call(this);
};
msignal_Signal0.__name__ = true;
msignal_Signal0.__super__ = msignal_Signal;
msignal_Signal0.prototype = $extend(msignal_Signal.prototype,{
	dispatch: function() {
		var slotsToProcess = this.slots;
		while(slotsToProcess.nonEmpty) {
			slotsToProcess.head.execute();
			slotsToProcess = slotsToProcess.tail;
		}
	}
	,createSlot: function(listener,once,priority) {
		if(priority == null) priority = 0;
		if(once == null) once = false;
		return new msignal_Slot0(this,listener,once,priority);
	}
});
var msignal_Signal2 = function(type1,type2) {
	msignal_Signal.call(this,[type1,type2]);
};
msignal_Signal2.__name__ = true;
msignal_Signal2.__super__ = msignal_Signal;
msignal_Signal2.prototype = $extend(msignal_Signal.prototype,{
	dispatch: function(value1,value2) {
		var slotsToProcess = this.slots;
		while(slotsToProcess.nonEmpty) {
			slotsToProcess.head.execute(value1,value2);
			slotsToProcess = slotsToProcess.tail;
		}
	}
	,createSlot: function(listener,once,priority) {
		if(priority == null) priority = 0;
		if(once == null) once = false;
		return new msignal_Slot2(this,listener,once,priority);
	}
});
var msignal_Slot = function(signal,listener,once,priority) {
	if(priority == null) priority = 0;
	if(once == null) once = false;
	this.signal = signal;
	this.set_listener(listener);
	this.once = once;
	this.priority = priority;
	this.enabled = true;
};
msignal_Slot.__name__ = true;
msignal_Slot.prototype = {
	remove: function() {
		this.signal.remove(this.listener);
	}
	,set_listener: function(value) {
		if(value == null) throw new js__$Boot_HaxeError("listener cannot be null");
		return this.listener = value;
	}
};
var msignal_Slot0 = function(signal,listener,once,priority) {
	if(priority == null) priority = 0;
	if(once == null) once = false;
	msignal_Slot.call(this,signal,listener,once,priority);
};
msignal_Slot0.__name__ = true;
msignal_Slot0.__super__ = msignal_Slot;
msignal_Slot0.prototype = $extend(msignal_Slot.prototype,{
	execute: function() {
		if(!this.enabled) return;
		if(this.once) this.remove();
		this.listener();
	}
});
var msignal_Slot1 = function(signal,listener,once,priority) {
	if(priority == null) priority = 0;
	if(once == null) once = false;
	msignal_Slot.call(this,signal,listener,once,priority);
};
msignal_Slot1.__name__ = true;
msignal_Slot1.__super__ = msignal_Slot;
msignal_Slot1.prototype = $extend(msignal_Slot.prototype,{
	execute: function(value1) {
		if(!this.enabled) return;
		if(this.once) this.remove();
		if(this.param != null) value1 = this.param;
		this.listener(value1);
	}
});
var msignal_Slot2 = function(signal,listener,once,priority) {
	if(priority == null) priority = 0;
	if(once == null) once = false;
	msignal_Slot.call(this,signal,listener,once,priority);
};
msignal_Slot2.__name__ = true;
msignal_Slot2.__super__ = msignal_Slot;
msignal_Slot2.prototype = $extend(msignal_Slot.prototype,{
	execute: function(value1,value2) {
		if(!this.enabled) return;
		if(this.once) this.remove();
		if(this.param1 != null) value1 = this.param1;
		if(this.param2 != null) value2 = this.param2;
		this.listener(value1,value2);
	}
});
var $_, $fid = 0;
function $bind(o,m) { if( m == null ) return null; if( m.__id__ == null ) m.__id__ = $fid++; var f; if( o.hx__closures__ == null ) o.hx__closures__ = {}; else f = o.hx__closures__[m.__id__]; if( f == null ) { f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; o.hx__closures__[m.__id__] = f; } return f; }
if(Array.prototype.indexOf) HxOverrides.indexOf = function(a,o,i) {
	return Array.prototype.indexOf.call(a,o,i);
};
String.__name__ = true;
Array.__name__ = true;
msignal_SlotList.NIL = new msignal_SlotList(null,null);
var __map_reserved = {}
fluid_core_renderers_webgl_WebGLRenderer.glContextId = 0;
fluid_core_utils_Utils._uid = 0;
fluid_core_utils_Utils._saidHello = false;
Fluid.utils = fluid_core_utils_Utils;
Fluid.WebGLRenderer = fluid_core_renderers_webgl_WebGLRenderer;
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
fluid_core_math_Matrix.IDENTITY = new fluid_core_math_Matrix();
fluid_core_math_Matrix.TEMP_MATRIX = new fluid_core_math_Matrix();
fluid_core_math_shapes_Rectangle.EMPTY = new fluid_core_math_shapes_Rectangle(0,0,0,0);
fluid_core_renderers_webgl_shaders_TextureShader.defaultVertexSrc = ["precision lowp float;","attribute vec2 aVertexPosition;","attribute vec2 aTextureCoord;","attribute vec4 aColor;","uniform mat3 projectionMatrix;","varying vec2 vTextureCoord;","varying vec4 vColor;","void main(void){","   gl_Position = vec4((projectionMatrix * vec3(aVertexPosition, 1.0)).xy, 0.0, 1.0);","   vTextureCoord = aTextureCoord;","   vColor = vec4(aColor.rgb * aColor.a, aColor.a);","}"].join("\n");
fluid_core_renderers_webgl_shaders_TextureShader.defaultFragmentSrc = ["precision lowp float;","varying vec2 vTextureCoord;","varying vec4 vColor;","uniform sampler2D uSampler;","void main(void){","   gl_FragColor = texture2D(uSampler, vTextureCoord) * vColor ;","}"].join("\n");
fluid_core_textures_Texture.EMPTY = new fluid_core_textures_Texture(new fluid_core_textures_BaseTexture());
})(typeof console != "undefined" ? console : {log:function(){}}, typeof window != "undefined" ? window : exports);

//# sourceMappingURL=fluid.js.map