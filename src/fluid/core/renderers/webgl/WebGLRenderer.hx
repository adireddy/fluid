package fluid.core.renderers.webgl;

import fluid.core.sprites.webgl.SpriteRenderer;
import fluid.core.utils.PluginTarget;
import fluid.core.display.DisplayObject;
import fluid.core.renderers.webgl.utils.RenderTarget;
import fluid.core.renderers.webgl.utils.ObjectRenderer;
import fluid.core.renderers.webgl.managers.StencilManager;
import msignal.Signal.Signal0;
import msignal.Signal.Signal1;
import fluid.core.textures.BaseTexture;
import js.html.Event;
import js.Browser;
import js.html.webgl.RenderingContext;
import Fluid.RenderOptions;
import fluid.core.renderers.webgl.managers.ShaderManager;
import fluid.core.renderers.webgl.managers.BlendModeManager;
import fluid.core.renderers.webgl.managers.FilterManager;
import fluid.core.renderers.webgl.managers.MaskManager;

using fluid.core.utils.PluginTarget;

class WebGLRenderer extends SystemRenderer {

	public static var glContextId:Int = 0;

	public var context:Signal1<RenderingContext>;
	public var prerender:Signal0;
	public var postrender:Signal0;

	public var drawModes:Dynamic;
	public var drawCount:Int;
	public var shaderManager:ShaderManager;
	public var maskManager:MaskManager;
	public var stencilManager:StencilManager;
	public var filterManager:FilterManager;
	public var blendModeManager:BlendModeManager;
	public var currentRenderTarget:RenderTarget;
	public var currentRenderer:ObjectRenderer;
	public var gl:RenderingContext;
	public var renderTarget:RenderTarget;

	public var __plugins:Map<String, Dynamic>;

	var _contextOptions:Dynamic;
	var _useFXAA:Bool;
	var _FXAAFilter:Dynamic;
	var _managedTextures:Array<BaseTexture>;
	var _renderTargetStack:Array<Dynamic>;

	public function new(width:Int, height:Int, ?options:RenderOptions) {
		prerender = new Signal0();
		postrender = new Signal0();
		context = new Signal1(RenderingContext);

		if (options == null) options = {};
		super("WebGL", width, height, options);

		__plugins = new Map();
		registerPlugin("sprite", fluid.core.sprites.webgl.SpriteRenderer);

		this.type = Fluid.RENDERER_TYPE.WEBGL;
		this.view.addEventListener('webglcontextlost', _handleContextLost, false);
		this.view.addEventListener('webglcontextrestored', _handleContextRestored, false);

		this._useFXAA = !!options.forceFXAA && options.antialias;

		this._FXAAFilter = null;

		this._contextOptions = {
			alpha: this.transparent,
			antialias: options.antialias,
			premultipliedAlpha: this.transparent,
			stencil: true,
			preserveDrawingBuffer: options.preserveDrawingBuffer
		};

		initPlugins();

		this.drawCount = 0;
		this.shaderManager = new ShaderManager(this);
		this.maskManager = new MaskManager(this);
		this.stencilManager = new StencilManager(this);
		this.filterManager = new FilterManager(this);
		this.blendModeManager = new BlendModeManager(this);
		this.currentRenderTarget = null;
		this.currentRenderer = new ObjectRenderer(this);

		this._createContext();
		this._initContext();
		this._mapGlModes();

		this._managedTextures = [];
		this._renderTargetStack = [];
	}

	public function render(object:DisplayObject) {
		prerender.dispatch();
		if (this.gl.isContextLost()) return;

		this.drawCount = 0;
		this._lastObjectRendered = object;

		if (this._useFXAA) {
			this._FXAAFilter[0].uniforms.resolution.value.x = this.width;
			this._FXAAFilter[0].uniforms.resolution.value.y = this.height;
			object.filterArea = this.renderTarget.size;
			object.filters = this._FXAAFilter;
		}

		var cacheParent = object.parent;
		object.parent = this._tempDisplayObjectParent;
		object.updateTransform();
		object.parent = cacheParent;

		var gl = this.gl;
		this.setRenderTarget(this.renderTarget);

		if (this.clearBeforeRender) {
			if (this.transparent) gl.clearColor(0, 0, 0, 0);
			else gl.clearColor(this._backgroundColorRgb[0], this._backgroundColorRgb[1], this._backgroundColorRgb[2], 1);
			gl.clear(RenderingContext.COLOR_BUFFER_BIT);
		}

		haxe.Timer.delay(function() {
			this.renderDisplayObject(object, this.renderTarget);
			postrender.dispatch();
		}, 2000);

	}

	public function renderDisplayObject(displayObject:DisplayObject, renderTarget:RenderTarget, ?clear:Bool = false) {
		this.setRenderTarget(renderTarget);
		if (clear) renderTarget.clear();
		this.filterManager.setFilterStack(renderTarget.filterStack);
		displayObject.renderWebGL(this);
		this.currentRenderer.flush();
	}

	public function setObjectRenderer(objectRenderer:ObjectRenderer) {
		if (this.currentRenderer == objectRenderer) return;
		this.currentRenderer.stop();
		this.currentRenderer = objectRenderer;
		this.currentRenderer.start();
	}

	public function setRenderTarget(renderTarget:RenderTarget) {
		if (this.currentRenderTarget == renderTarget) return;
		this.currentRenderTarget = renderTarget;
		this.currentRenderTarget.activate();
		this.stencilManager.setMaskStack(renderTarget.stencilMaskStack);
	}

	override public function resize(width:Int, height:Int) {
		super.resize(width, height);
		this.filterManager.resize(width, height);
		this.renderTarget.resize(width, height);

		if (this.currentRenderTarget == this.renderTarget) {
			this.renderTarget.activate();
			this.gl.viewport(0, 0, this.width, this.height);
		}
	}

	public function updateTexture(txt:Dynamic):js.html.webgl.Texture {
		var texture:BaseTexture = (txt.baseTexture != null) ? txt.baseTexture : txt;
		if (!texture.hasLoaded) return null;

		var gl = this.gl;

		if (texture._glTextures[Reflect.field(gl, "id")] == null) {
			texture._glTextures[Reflect.field(gl, "id")] = gl.createTexture();
			texture.updated.add(this.updateTexture);
			texture.disposed.add(this.destroyTexture);
			this._managedTextures.push(texture);
		}

		gl.bindTexture(RenderingContext.TEXTURE_2D, texture._glTextures[Reflect.field(gl, "id")]);
		gl.pixelStorei(RenderingContext.UNPACK_PREMULTIPLY_ALPHA_WEBGL, texture.premultipliedAlpha ? 1 : 0);
		gl.texImage2D(RenderingContext.TEXTURE_2D, 0, RenderingContext.RGBA, RenderingContext.RGBA, RenderingContext.UNSIGNED_BYTE, texture.source);
		gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_MAG_FILTER, texture.scaleMode == Fluid.SCALE_MODES.LINEAR ? RenderingContext.LINEAR : RenderingContext.NEAREST);

		if (texture.mipmap && texture.isPowerOfTwo) {
			gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_MIN_FILTER, texture.scaleMode == Fluid.SCALE_MODES.LINEAR ? RenderingContext.LINEAR_MIPMAP_LINEAR : RenderingContext.NEAREST_MIPMAP_NEAREST);
			gl.generateMipmap(RenderingContext.TEXTURE_2D);
		}
		else gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_MIN_FILTER, texture.scaleMode == Fluid.SCALE_MODES.LINEAR ? RenderingContext.LINEAR : RenderingContext.NEAREST);

		if (!texture.isPowerOfTwo) {
			gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_WRAP_S, RenderingContext.CLAMP_TO_EDGE);
			gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_WRAP_T, RenderingContext.CLAMP_TO_EDGE);
		}
		else {
			gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_WRAP_S, RenderingContext.REPEAT);
			gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_WRAP_T, RenderingContext.REPEAT);
		}

		return texture._glTextures[(Reflect.field(gl, "id"))];
	}

	public function destroyTexture(txt:Dynamic) {
		var texture:BaseTexture = (txt.baseTexture != null) ? txt.baseTexture : txt;
		if (!texture.hasLoaded) return;

		if (texture._glTextures[Reflect.field(gl, "id")] != null) {
			this.gl.deleteTexture(texture._glTextures[Reflect.field(gl, "id")]);
			texture._glTextures[Reflect.field(gl, "id")] = null;
		}
	}

	function _handleContextLost(event:Event) {
		event.preventDefault();
	}

	function _handleContextRestored(event:Event) {
		_initContext();
		for (i in 0 ... this._managedTextures.length) {
			var texture = this._managedTextures[i];
			if (texture._glTextures[Reflect.field(this.gl, "id")] != null) texture._glTextures[Reflect.field(this.gl, "id")] = null;
		}
	}

	function _createContext() {
		var gl:RenderingContext = this.view.getContextWebGL(this._contextOptions);
		this.gl = gl;
		glContextId = glContextId++;
		Reflect.setField(this.gl, "id", glContextId);
		Reflect.setField(this.gl, "renderer", this);
	}

	function _initContext() {
		var gl = this.gl;
		gl.disable(RenderingContext.DEPTH_TEST);
		gl.disable(RenderingContext.CULL_FACE);
		gl.enable(RenderingContext.BLEND);

		this.renderTarget = new RenderTarget(gl, this.width, this.height, null, this.resolution, true);
		this.setRenderTarget(this.renderTarget);
		context.dispatch(gl);

		this.resize(this.width, this.height);

		if (!this._useFXAA) {
			this._useFXAA = (this._contextOptions.antialias && !gl.getContextAttributes().antialias);
		}

		if (this._useFXAA) {
			Browser.console.warn('FXAA antialiasing being used instead of native antialiasing');
			//this._FXAAFilter = [new FXAAFilter()];
		}
	}

	override public function destroy(?removeView:Bool = false) {
		destroyPlugins();

		this.view.removeEventListener('webglcontextlost', _handleContextLost);
		this.view.removeEventListener('webglcontextrestored', _handleContextRestored);

		for (i in 0 ... this._managedTextures.length) {
			var texture = this._managedTextures[i];
			this.destroyTexture(texture);
			texture.updated.remove(this.updateTexture);
			texture.disposed.remove(this.destroyTexture);
		}

		super.destroy(removeView);

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

	function _mapGlModes() {
		var gl = this.gl;

		if (this.blendModes == null) {
			this.blendModes = {};

			this.blendModes[Fluid.BLEND_MODES.NORMAL] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.ADD] = [RenderingContext.SRC_ALPHA, RenderingContext.DST_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.MULTIPLY] = [RenderingContext.DST_COLOR, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.SCREEN] = [RenderingContext.SRC_ALPHA, RenderingContext.ONE];
			this.blendModes[Fluid.BLEND_MODES.OVERLAY] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.DARKEN] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.LIGHTEN] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.COLOR_DODGE] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.COLOR_BURN] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.HARD_LIGHT] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.SOFT_LIGHT] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.DIFFERENCE] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.EXCLUSION] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.HUE] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.SATURATION] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.COLOR] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.LUMINOSITY] = [RenderingContext.ONE, RenderingContext.ONE_MINUS_SRC_ALPHA];
		}

		if (this.drawModes == null) {
			this.drawModes = {};

			this.drawModes[Fluid.DRAW_MODES.POINTS] = RenderingContext.POINTS;
			this.drawModes[Fluid.DRAW_MODES.LINES] = RenderingContext.LINES;
			this.drawModes[Fluid.DRAW_MODES.LINE_LOOP] = RenderingContext.LINE_LOOP;
			this.drawModes[Fluid.DRAW_MODES.LINE_STRIP] = RenderingContext.LINE_STRIP;
			this.drawModes[Fluid.DRAW_MODES.TRIANGLES] = RenderingContext.TRIANGLES;
			this.drawModes[Fluid.DRAW_MODES.TRIANGLE_STRIP] = RenderingContext.TRIANGLE_STRIP;
			this.drawModes[Fluid.DRAW_MODES.TRIANGLE_FAN] = RenderingContext.TRIANGLE_FAN;
		}
	}
}