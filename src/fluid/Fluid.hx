package fluid;

import fluid.display.FluidStage;
import fluid.display.FluidSprite;

class Fluid #if !js extends openfl.display.Sprite #end {

	@:noCompletion var _canvas:Dynamic;
	@:noCompletion var _renderer:Dynamic;
	@:noCompletion var _lastTime:Date;
	@:noCompletion var _currentTime:Date;
	@:noCompletion var _elapsedTime:Float;
	@:noCompletion var _fluidFrameSkip:Bool = false;

	public var mouseDown:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var mouseOut:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var mouseOver:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var mouseUp:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var mouseClick:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var rightClick:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var rightMouseDown:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;
	public var rightMouseUp:#if js pixi.InteractionData #else openfl.events.MouseEvent #end -> Void;

	public var touchBegin:#if js pixi.InteractionData #else openfl.events.TouchEvent #end -> Void;
	public var touchEnd:#if js pixi.InteractionData #else openfl.events.TouchEvent #end -> Void;
	public var touchOut:#if js pixi.InteractionData #else openfl.events.TouchEvent #end -> Void;

	public var skipFrame(null, default):Bool = false;
	public var stats(null, set):Bool = false;
	public var backgroundColor(null, set):UInt = 0xFFFFFF;

	public var update:Float -> Void;
	public var resize:Void -> Void;

	@:noCompletion private var _fluidStage:FluidStage;

	public var container(default, null):FluidSprite;
	#if js private var _stats:fluid.utils.StatsJS;
	#else var _stats:openfl.display.FPS; #end

	public function new() {
		_lastTime = Date.now();
		_setStageProperties();
		#if js
			_canvas = js.Browser.document.createCanvasElement();
	        _canvas.style.width = FluidStage.screenWidth + "px";
	        _canvas.style.height = FluidStage.screenHeight + "px";
	        js.Browser.document.body.appendChild(_canvas);

	        _fluidStage = new FluidStage(backgroundColor);
	        container = new FluidSprite();
	        _fluidStage.addChild(container);
	        _fluidStage.mousedown = _fluidOnMouseDown;
	        _fluidStage.mouseout = _fluidOnMouseOut;
	        _fluidStage.mouseover = _fluidOnMouseOver;
	        _fluidStage.mouseup = _fluidOnMouseUp;
	        _fluidStage.click = _fluidOnMouseClick;
	        _fluidStage.rightclick = _fluidOnRightClick;
	        _fluidStage.rightdown = _fluidOnRightMouseDown;
	        _fluidStage.rightup = _fluidOnRightMouseUp;
	        _fluidStage.touchstart = _fluidOnTouchBegin;
	        _fluidStage.touchend = _fluidOnTouchEnd;
	        _fluidStage.touchendoutside = _fluidOnTouchOut;
	        //_fluidStage.mouseupoutside = _fluidOnMouseDown;
	        //_fluidStage.rightupoutside = _fluidOnMouseDown;

	        var renderingOptions = new pixi.utils.Detector.RenderingOptions();
		    renderingOptions.view = _canvas;
		    renderingOptions.resolution = FluidStage.pixelRatio;

	        _renderer = pixi.utils.Detector.autoDetectRenderer(FluidStage.screenWidth, FluidStage.screenHeight, renderingOptions);
	        js.Browser.document.body.appendChild(_renderer.view);
	        js.Browser.window.onresize = _fluidOnResize;
	        js.Browser.window.requestAnimationFrame(cast _fluidOnUpdate);
	        _lastTime = Date.now();
		#else
			super();
			container = new FluidSprite();
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
		FluidStage.pixelRatio = #if js js.Browser.window.devicePixelRatio; #else (openfl.system.Capabilities.screenDPI < 300) ? 1 : 2; #end
		FluidStage.screenWidth = #if js js.Browser.window.innerWidth; #else stage.stageWidth; #end
		FluidStage.screenHeight = #if js js.Browser.window.innerHeight; #else stage.stageHeight; #end
		FluidStage.orientation = (FluidStage.screenWidth > FluidStage.screenHeight) ? FluidStage.LANDSCAPE : FluidStage.PORTRAIT;
	}

	@:noCompletion function set_backgroundColor(clr:UInt):UInt {
		#if js _fluidStage.setBackgroundColor(clr); #else stage.color = clr; #end
		return backgroundColor = clr;
	}

	@:noCompletion function _fluidOnMouseDown(evt) { if (mouseDown != null) mouseDown(evt); }
	@:noCompletion function _fluidOnMouseOver(evt) { if (mouseOver != null) mouseOver(evt); }
	@:noCompletion function _fluidOnMouseOut(evt) { if (mouseOut != null) mouseOut(evt); }
	@:noCompletion function _fluidOnMouseUp(evt) { if (mouseUp != null) mouseUp(evt); }
	@:noCompletion function _fluidOnMouseClick(evt) { if (mouseClick != null) mouseClick(evt); }
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
			if (update != null) update(_elapsedTime);
		}
	}

	@:noCompletion function _fluidOnUpdate() {
		if (skipFrame && _fluidFrameSkip) _fluidFrameSkip = false;
		else {
			_fluidFrameSkip = true;
			_fluidCalculateElapsedTime();
			if (update != null) update(_elapsedTime);
			#if js _renderer.render(_fluidStage); #end
		}
		#if js
			js.Browser.window.requestAnimationFrame(cast _fluidOnUpdate);
			if (_stats != null) _stats.update();
		#end
	}

	@:noCompletion function _fluidCalculateElapsedTime() {
		_currentTime = Date.now();
		_elapsedTime = _currentTime.getTime() - _lastTime.getTime();
		_lastTime = _currentTime;
	}

	@:noCompletion function _fluidOnResize(event) {
		_setStageProperties();
		#if !js
			if (stats) _stats.x = FluidStage.screenWidth - 50;
		#end
		if (resize != null) resize();
	}

	function set_stats(val:Bool):Bool {
		if (val) {
			#if js
				var _container = js.Browser.document.createElement("div");
				js.Browser.document.body.appendChild(_container);
				_stats = new fluid.utils.StatsJS();
				_stats.domElement.style.position = "absolute";
				_stats.domElement.style.top = "2px";
				_stats.domElement.style.right = "2px";
				_container.appendChild(_stats.domElement);
				_stats.begin();
			#else
				_stats = new openfl.display.FPS();
				_stats.x = FluidStage.screenWidth - 50;
				addChild(_stats);
			#end
		}
		return stats = val;
	}
}