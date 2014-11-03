package fluid;

class Fluid #if !js extends openfl.display.Sprite #end {

	var _canvas:Dynamic;
	var _renderer:Dynamic;
	var _lastTime:Date;
	var _currentTime:Date;

	public var mouseDown:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var mouseOut:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var mouseOver:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var mouseUp:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var click:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var rightClick:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var rightMouseDown:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var rightMouseUp:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;

	public var touchBegin:#if js pixi.InteractionData #else openfl.events.TouchEvent #end -> Void;
	public var touchEnd:#if js pixi.InteractionData #else openfl.events.TouchEvent #end -> Void;
	public var touchOut:#if js pixi.InteractionData #else openfl.events.TouchEvent #end -> Void;

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
	        stage.mouseout = _fluidOnMouseOut;
	        stage.mouseover = _fluidOnMouseOver;
	        stage.mouseup = _fluidOnMouseUp;
	        stage.click = _fluidOnMouseClick;
	        stage.rightclick = _fluidOnRightClick;
	        stage.rightdown = _fluidOnRightMouseDown;
	        stage.rightup = _fluidOnRightMouseUp;
	        stage.touchstart = _fluidOnTouchBegin;
	        stage.touchend = _fluidOnTouchEnd;
	        stage.touchendoutside = _fluidOnTouchOut;
	        //stage.mouseupoutside = _fluidOnMouseDown;
	        //stage.rightupoutside = _fluidOnMouseDown;

	        var renderingOptions = new pixi.utils.Detector.RenderingOptions();
		    renderingOptions.view = _canvas;
		    renderingOptions.resolution = StageProperties.pixelRatio;

	        _renderer = pixi.utils.Detector.autoDetectRenderer(StageProperties.screenWidth, StageProperties.screenHeight, renderingOptions);
	        js.Browser.document.body.appendChild(_renderer.view);
	        js.Browser.window.onresize = _fluidOnResize;
	        js.Browser.window.requestAnimationFrame(cast _fluidOnUpdate);
	        _lastTime = Date.now();
		#else
			super();
			container = new openfl.display.Sprite();
			stage.addEventListener(openfl.events.Event.ENTER_FRAME, _fluidOnEnterFrame);
			stage.addEventListener(openfl.events.Event.RESIZE, _fluidOnResize);
			stage.addEventListener(openfl.events.MouseEvent.MOUSE_DOWN, _fluidOnMouseDown);
			stage.addEventListener(openfl.events.MouseEvent.MOUSE_OVER, _fluidOnMouseOver);
			stage.addEventListener(openfl.events.MouseEvent.MOUSE_OUT, _fluidOnMouseOut);
			stage.addEventListener(openfl.events.MouseEvent.MOUSE_UP, _fluidOnMouseUp);
			stage.addEventListener(openfl.events.MouseEvent.CLICK, _fluidOnMouseClick);
			stage.addEventListener(openfl.events.MouseEvent.RIGHT_CLICK, _fluidOnRightClick);
			stage.addEventListener(openfl.events.MouseEvent.RIGHT_MOUSE_DOWN, _fluidOnRightMouseDown);
			stage.addEventListener(openfl.events.MouseEvent.RIGHT_MOUSE_UP, _fluidOnRightMouseUp);
			stage.addEventListener(openfl.events.TouchEvent.TOUCH_BEGIN, _fluidOnTouchBegin);
			stage.addEventListener(openfl.events.TouchEvent.TOUCH_END, _fluidOnTouchEnd);
			stage.addEventListener(openfl.events.TouchEvent.TOUCH_OUT, _fluidOnTouchOut);
			addChild(container);
		#end
	}

	function _setStageProperties() {
		StageProperties.pixelRatio = #if js js.Browser.window.devicePixelRatio; #else (openfl.system.Capabilities.screenDPI < 300) ? 1 : 2; #end
		StageProperties.screenWidth = #if js js.Browser.window.innerWidth; #else stage.stageWidth; #end
		StageProperties.screenHeight = #if js js.Browser.window.innerHeight; #else stage.stageHeight; #end
		StageProperties.orientation = (StageProperties.screenWidth > StageProperties.screenHeight) ? StageProperties.LANDSCAPE : StageProperties.PORTRAIT;
	}

	@:noCompletion function _fluidOnMouseDown(evt) { if (mouseDown != null) mouseDown(evt); }
	@:noCompletion function _fluidOnMouseOver(evt) { if (mouseOver != null) mouseOver(evt); }
	@:noCompletion function _fluidOnMouseOut(evt) { if (mouseOut != null) mouseOut(evt); }
	@:noCompletion function _fluidOnMouseUp(evt) { if (mouseUp != null) mouseUp(evt); }
	@:noCompletion function _fluidOnMouseClick(evt) { if (click != null) click(evt); }
	@:noCompletion function _fluidOnRightClick(evt) { if (rightClick != null) rightClick(evt); }
	@:noCompletion function _fluidOnRightMouseDown(evt) { if (rightMouseDown != null) rightMouseDown(evt); }
	@:noCompletion function _fluidOnRightMouseUp(evt) { if (rightMouseUp != null) rightMouseUp(evt); }
	@:noCompletion function _fluidOnTouchBegin(evt) { if (touchBegin != null) touchBegin(evt); }
	@:noCompletion function _fluidOnTouchEnd(evt) { if (touchEnd != null) touchEnd(evt); }
	@:noCompletion function _fluidOnTouchOut(evt) { if (touchOut != null) touchOut(evt); }

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

	@:noCompletion function _fluidOnResize(event) {
		_setStageProperties();
		#if !js _stats.x = StageProperties.screenWidth - 50; #end
		_resize();
	}

	function _update(elapsed:Float) {

	}

	function _resize() {

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
			_stats.x = StageProperties.screenWidth - 50;
			addChild(_stats);
		#end
	}
}