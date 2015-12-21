package fluid.core.renderers.webgl;

import js.Browser;
import js.html.webgl.RenderingContext;
import Fluid.RenderOptions;
import fluid.core.renderers.webgl.managers.ShaderManager;
import fluid.core.renderers.webgl.managers.BlendModeManager;
import fluid.core.renderers.webgl.managers.FilterManager;
import fluid.core.renderers.webgl.managers.MaskManager;

class WebGLRenderer extends SystemRenderer {

	public static var glContextId:Int = 0;

	public var drawCount:Int;
	public var shaderManager:Dynamic;
	public var maskManager:MaskManager;
	public var stencilManager:Dynamic;
	public var filterManager:FilterManager;
	public var blendModeManager:BlendModeManager;
	public var currentRenderTarget:Dynamic;
	public var currentRenderer:Dynamic;
	public var type:Int;
	public var gl:RenderingContext;

	var _contextOptions:Dynamic;
	var _useFXAA:Bool;
	var _FXAAFilter:Dynamic;
	var _managedTextures:Array<Dynamic>;
	var _renderTargetStack:Array<Dynamic>;

	public function new(width:Float, height:Float, ?options:RenderOptions) {
		if (options == null) options = {};
		super("WebGL", width, height, options);

		this.type = Fluid.RENDERER_TYPE.WEBGL;

		this.handleContextLost = this.handleContextLost.bind(this);
		this.handleContextRestored = this.handleContextRestored.bind(this);

		this.view.addEventListener('webglcontextlost', this.handleContextLost, false);
		this.view.addEventListener('webglcontextrestored', this.handleContextRestored, false);


		this._useFXAA = !!options.forceFXAA && options.antialias;

		this._FXAAFilter = null;

		this._contextOptions = {
			alpha: this.transparent,
			antialias: options.antialias,
			premultipliedAlpha: this.transparent && this.transparent != 'notMultiplied',
			stencil: true,
			preserveDrawingBuffer: options.preserveDrawingBuffer
		};

		this.drawCount = 0;

		this.shaderManager = new ShaderManager(this);

		this.maskManager = new MaskManager(this);

		this.stencilManager = new StencilManager(this);

		this.filterManager = new FilterManager(this);

		this.blendModeManager = new BlendModeManager(this);

		this.currentRenderTarget = null;

		this.currentRenderer = new ObjectRenderer(this);

		this.initPlugins();

		this._createContext();
		this._initContext();

		this._mapGlModes();

		this._managedTextures = [];

		this._renderTargetStack = [];
	}

	function _createContext() {
		var gl:RenderingContext = this.view.getContextWebGL(this._contextOptions);
		this.gl = gl;

		this.glContextId = WebGLRenderer.glContextId++;
		//gl.id = this.glContextId;
		//gl.renderer = this;
	}

	function _initContext() {
		var gl = this.gl;
		gl.disable(gl.DEPTH_TEST);
		gl.disable(gl.CULL_FACE);
		gl.enable(gl.BLEND);

		/*this.renderTarget = new RenderTarget(gl, this.width, this.height, null, this.resolution, true);

		this.setRenderTarget(this.renderTarget);

		this.emit('context', gl);*/

		// setup the width/height properties and gl viewport
		this.resize(this.width, this.height);

		if(!this._useFXAA) {
			this._useFXAA = (this._contextOptions.antialias && ! gl.getContextAttributes().antialias);
		}

		if(this._useFXAA) {
			Browser.console.warn('FXAA antialiasing being used instead of native antialiasing');
			//this._FXAAFilter = [new FXAAFilter()];
		}
	}

	function _mapGlModes() {
		var gl = this.gl;

		if (!this.blendModes) {
			this.blendModes = {};

			this.blendModes[Fluid.BLEND_MODES.NORMAL]        = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.ADD]           = [RenderingContext.SRC_ALPHA, RenderingContext.DST_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.MULTIPLY]      = [RenderingContext.DST_COLOR, RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.SCREEN]        = [RenderingContext.SRC_ALPHA, RenderingContext.ONE];
			this.blendModes[Fluid.BLEND_MODES.OVERLAY]       = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.DARKEN]        = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.LIGHTEN]       = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.COLOR_DODGE]   = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.COLOR_BURN]    = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.HARD_LIGHT]    = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.SOFT_LIGHT]    = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.DIFFERENCE]    = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.EXCLUSION]     = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.HUE]           = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.SATURATION]    = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.COLOR]         = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
			this.blendModes[Fluid.BLEND_MODES.LUMINOSITY]    = [RenderingContext.ONE,       RenderingContext.ONE_MINUS_SRC_ALPHA];
		}

		if (!this.drawModes) {
			this.drawModes = {};

			this.drawModes[Fluid.DRAW_MODES.POINTS]         = RenderingContext.POINTS;
			this.drawModes[Fluid.DRAW_MODES.LINES]          = RenderingContext.LINES;
			this.drawModes[Fluid.DRAW_MODES.LINE_LOOP]      = RenderingContext.LINE_LOOP;
			this.drawModes[Fluid.DRAW_MODES.LINE_STRIP]     = RenderingContext.LINE_STRIP;
			this.drawModes[Fluid.DRAW_MODES.TRIANGLES]      = RenderingContext.TRIANGLES;
			this.drawModes[Fluid.DRAW_MODES.TRIANGLE_STRIP] = RenderingContext.TRIANGLE_STRIP;
			this.drawModes[Fluid.DRAW_MODES.TRIANGLE_FAN]   = RenderingContext.TRIANGLE_FAN;
		}
	}
}