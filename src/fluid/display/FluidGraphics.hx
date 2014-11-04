package fluid.display;

import fluid.events.EventData;

class FluidGraphics extends #if !js openfl.display.Sprite #else pixi.primitives.Graphics #end {

	public var mouseDown:EventData -> Void;
	public var mouseOut:EventData -> Void;
	public var mouseOver:EventData -> Void;
	public var mouseUp:EventData -> Void;
	public var mouseMove:EventData -> Void;
	public var mouseClick:EventData -> Void;
	public var rightClick:EventData -> Void;
	public var rightMouseDown:EventData -> Void;
	public var rightMouseUp:EventData -> Void;

	public var touchBegin:EventData -> Void;
	public var touchEnd:EventData -> Void;
	public var touchOut:EventData -> Void;
	public var touchMove:EventData -> Void;

	#if !js
		public var interactive(null, set):Bool;
		public function set_interactive(val:Bool):Bool {
			mouseEnabled = val;
			return interactive = val;
		}
	#end

	public function new() {
		super();
		#if js
			mousedown = _fluidOnMouseDown;
			mouseout = _fluidOnMouseOut;
			mouseover = _fluidOnMouseOver;
			mouseup = _fluidOnMouseUp;
			mousemove = _fluidOnMouseMove;
			click = _fluidOnMouseClick;
			rightclick = _fluidOnRightClick;
			rightdown = _fluidOnRightMouseDown;
			rightup = _fluidOnRightMouseUp;
			touchstart = _fluidOnTouchBegin;
			touchend = _fluidOnTouchEnd;
			touchendoutside = _fluidOnTouchOut;
			touchmove = _fluidOnTouchMove;
		#else
			addEventListener(openfl.events.MouseEvent.MOUSE_DOWN, _fluidOnMouseDown);
			addEventListener(openfl.events.MouseEvent.MOUSE_OVER, _fluidOnMouseOver);
			addEventListener(openfl.events.MouseEvent.MOUSE_OUT, _fluidOnMouseOut);
			addEventListener(openfl.events.MouseEvent.MOUSE_UP, _fluidOnMouseUp);
			addEventListener(openfl.events.MouseEvent.MOUSE_MOVE, _fluidOnMouseMove);
			addEventListener(openfl.events.MouseEvent.CLICK, _fluidOnMouseClick);
			addEventListener(openfl.events.MouseEvent.RIGHT_CLICK, _fluidOnRightClick);
			addEventListener(openfl.events.MouseEvent.RIGHT_MOUSE_DOWN, _fluidOnRightMouseDown);
			addEventListener(openfl.events.MouseEvent.RIGHT_MOUSE_UP, _fluidOnRightMouseUp);
			addEventListener(openfl.events.TouchEvent.TOUCH_BEGIN, _fluidOnTouchBegin);
			addEventListener(openfl.events.TouchEvent.TOUCH_END, _fluidOnTouchEnd);
			addEventListener(openfl.events.TouchEvent.TOUCH_OUT, _fluidOnTouchOut);
			addEventListener(openfl.events.TouchEvent.TOUCH_MOVE, _fluidOnTouchMove);
		#end
	}

	@:noCompletion function _fluidOnMouseDown(evt:Dynamic) { if (mouseDown != null) mouseDown(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnMouseOver(evt:Dynamic) { if (mouseOver != null) mouseOver(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnMouseOut(evt:Dynamic) { if (mouseOut != null) mouseOut(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnMouseUp(evt:Dynamic) { if (mouseUp != null) mouseUp(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnMouseMove(evt:Dynamic) { if (mouseMove != null) mouseMove(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnMouseClick(evt:Dynamic) { if (mouseClick != null) mouseClick(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnRightClick(evt:Dynamic) { if (rightClick != null) rightClick(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnRightMouseDown(evt:Dynamic) { if (rightMouseDown != null) rightMouseDown(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnRightMouseUp(evt:Dynamic) { if (rightMouseUp != null) rightMouseUp(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnTouchBegin(evt:Dynamic) { if (touchBegin != null) touchBegin(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnTouchEnd(evt:Dynamic) { if (touchEnd != null) touchEnd(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnTouchOut(evt:Dynamic) { if (touchOut != null) touchOut(_prepareEventData(evt)); }
	@:noCompletion function _fluidOnTouchMove(evt:Dynamic) { if (touchMove != null) touchMove(_prepareEventData(evt)); }

	@:noCompletion private function _prepareEventData(data):EventData {
		var evtData = new EventData();
		evtData.localX = #if js data.getLocalPosition(parent).x #else data.localX #end;
		evtData.localY = #if js data.getLocalPosition(parent).y #else data.localY #end;
		evtData.stageX = #if js data.global.x #else data.stageX #end;
		evtData.stageY = #if js data.global.y #else data.stageY #end;
		evtData.target = data.target;
		return evtData;
	}

	#if js override #end public function clear()#if js :pixi.primitives.Graphics #end {
		#if js return super.clear();
		#else this.graphics.clear(); #end
	}

	#if js override #end public function beginFill(fill:UInt, ?alpha:Float = 1)#if js :pixi.primitives.Graphics #end {
		#if js return super.beginFill(fill);
		#else this.graphics.beginFill(fill); this.alpha = alpha; #end
	}

	#if js override #end public function endFill()#if js :pixi.primitives.Graphics #end {
		#if js return super.endFill();
		#else this.graphics.endFill(); #end
	}

	#if js override #end public function drawRect(x:Float, y:Float, w:Float, h:Float)#if js :pixi.primitives.Graphics #end {
		#if js return super.drawRect(x, y, w, h);
		#else this.graphics.drawRect(x, y, w, h); #end
	}

	#if js override #end public function drawCircle(x:Float, y:Float, r:Float)#if js :pixi.primitives.Graphics #end {
		#if js return super.drawCircle(x, y, r);
		#else this.graphics.drawCircle(x, y, r); #end
	}

	#if js override #end public function drawEllipse(x:Float, y:Float, w:Float, h:Float)#if js :pixi.primitives.Graphics #end {
		#if js return super.drawEllipse(x, y, w, h);
		#else this.graphics.drawEllipse(x, y, w, h); #end
	}

	#if js override #end public function drawRoundedRect(x:Float, y:Float, w:Float, h:Float, r:Float)#if js :pixi.primitives.Graphics #end {
		#if js return super.drawRoundedRect(x, y, w, h, r);
		#else this.graphics.drawRoundRectComplex(x, y, w, h, r, r, r, r); #end
	}

	#if js override #end public function lineStyle(lineWidth:Float, ?color:UInt = 0, ?alpha:Float = 1)#if js :pixi.primitives.Graphics #end {
		#if js return super.lineStyle(lineWidth, color, alpha);
		#else this.graphics.lineStyle(lineWidth, color, alpha); #end
	}

	#if js override #end public function lineTo(x:Float, y:Float)#if js :pixi.primitives.Graphics #end {
		#if js return super.lineTo(x, y);
		#else this.graphics.lineTo(x, y); #end
	}

	#if js override #end public function moveTo(x:Float, y:Float)#if js :pixi.primitives.Graphics #end {
		#if js return super.moveTo(x, y);
		#else this.graphics.moveTo(x, y); #end
	}
}