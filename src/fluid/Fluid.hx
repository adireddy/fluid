package fluid;

class Fluid #if !js extends openfl.display.Sprite #end {

	var _canvas:Dynamic;
	var _renderer:Dynamic;
	var _lastTime:Date;
	var _currentTime:Date;

	public var mouseDown:Dynamic -> Void;

	public var elapsedTime(default, null):Float = 0;
	public var skipFrame(default, null):Bool = false;

	private var _fluidFrameSkip:Bool = false;

	#if js
		public var stage(default, default):pixi.display.Stage;
		public var container(default, default):pixi.display.DisplayObjectContainer;
		private var _stats:fluid.utils.StatsJS;
	#else
		public var container(default, default):openfl.display.Sprite;
		private var _stats:openfl.display.FPS;
	#end

	public function new() {
		_lastTime = Date.now();
		_setStageProperties();
		#if js
			_canvas = js.Browser.document.createCanvasElement();
	        _canvas.style.width = StageProperties.screenWidth + "px";
	        _canvas.style.height = StageProperties.screenHeight + "px";
	        js.Browser.document.body.appendChild(_canvas);

	        stage = new pixi.display.Stage(0xFFFFFF);
	        container = new pixi.display.DisplayObjectContainer();
	        stage.addChild(container);
	        stage.mousedown = _fluidOnMouseDown;

	        var renderingOptions = new pixi.utils.Detector.RenderingOptions();
		    renderingOptions.view = _canvas;
		    renderingOptions.resolution = StageProperties.pixelRatio;

	        _renderer = pixi.utils.Detector.autoDetectRenderer(StageProperties.screenWidth, StageProperties.screenHeight, renderingOptions);
	        js.Browser.document.body.appendChild(_renderer.view);
	        js.Browser.window.onresize = _onResize;
	        js.Browser.window.requestAnimationFrame(cast _fluidOnUpdate);
	        _lastTime = Date.now();
		#else
			super();
			container = new openfl.display.Sprite();
			stage.addEventListener(openfl.events.Event.ENTER_FRAME, _fluidOnEnterFrame);
			stage.addEventListener(openfl.events.Event.RESIZE, _onResize);
			stage.addEventListener(openfl.events.MouseEvent.MOUSE_DOWN, _fluidOnMouseDown);
			addChild(container);
		#end
	}

	function _setStageProperties() {
		StageProperties.pixelRatio = #if js js.Browser.window.devicePixelRatio; #else 1; #end
		StageProperties.screenWidth = #if js js.Browser.window.innerWidth; #else stage.stageWidth; #end
		StageProperties.screenHeight = #if js js.Browser.window.innerHeight; #else stage.stageHeight; #end
		StageProperties.orientation = (StageProperties.screenWidth > StageProperties.screenHeight) ? StageProperties.LANDSCAPE : StageProperties.PORTRAIT;
	}

	@:noCompletion function _fluidOnMouseDown(evt) {
		if (mouseDown != null) mouseDown(evt);
	}

	@:noCompletion function _fluidOnEnterFrame(evt) {
		if (skipFrame && _fluidFrameSkip) _fluidFrameSkip = false;
		else {
			_fluidFrameSkip = true;
			_fluidCalculateElapsedTime();
			_update(elapsedTime);
		}
	}

	@:noCompletion function _fluidOnUpdate() {
		if (skipFrame && _fluidFrameSkip) _fluidFrameSkip = false;
		else {
			_fluidFrameSkip = true;
			_fluidCalculateElapsedTime();
			_update(elapsedTime);
			#if js _renderer.render(stage); #end
		}
		#if js
			js.Browser.window.requestAnimationFrame(cast _fluidOnUpdate);
			if (_stats != null) _stats.update();
		#end
	}

	@:noCompletion function _fluidCalculateElapsedTime() {
		_currentTime = Date.now();
		elapsedTime = _currentTime.getTime() - _lastTime.getTime();
		_lastTime = _currentTime;
	}

	function _update(elapsed:Float) {

	}

	function _onResize(event) {

	}

	function _showStats() {
		#if js
			var _container = js.Browser.document.createElement("div");
			js.Browser.document.body.appendChild(_container);
			_stats = new fluid.utils.StatsJS();
			_stats.domElement.style.position = "absolute";
			_stats.domElement.style.top = "6px";
			_stats.domElement.style.right = "6px";
			_container.appendChild(_stats.domElement);
			_stats.begin();
		#else
			_stats = new openfl.display.FPS();
			addChild(_stats);
		#end
	}
}
