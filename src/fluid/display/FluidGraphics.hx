package fluid.display;

class FluidGraphics extends #if !js openfl.display.Sprite #else pixi.primitives.Graphics #end {

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
			click = _fluidOnMouseClick;
			rightclick = _fluidOnRightClick;
			rightdown = _fluidOnRightMouseDown;
			rightup = _fluidOnRightMouseUp;
			touchstart = _fluidOnTouchBegin;
			touchend = _fluidOnTouchEnd;
			touchendoutside = _fluidOnTouchOut;
		#else
			addEventListener(openfl.events.MouseEvent.MOUSE_DOWN, _fluidOnMouseDown);
			addEventListener(openfl.events.MouseEvent.MOUSE_OVER, _fluidOnMouseOver);
			addEventListener(openfl.events.MouseEvent.MOUSE_OUT, _fluidOnMouseOut);
			addEventListener(openfl.events.MouseEvent.MOUSE_UP, _fluidOnMouseUp);
			addEventListener(openfl.events.MouseEvent.CLICK, _fluidOnMouseClick);
			addEventListener(openfl.events.MouseEvent.RIGHT_CLICK, _fluidOnRightClick);
			addEventListener(openfl.events.MouseEvent.RIGHT_MOUSE_DOWN, _fluidOnRightMouseDown);
			addEventListener(openfl.events.MouseEvent.RIGHT_MOUSE_UP, _fluidOnRightMouseUp);
			addEventListener(openfl.events.TouchEvent.TOUCH_BEGIN, _fluidOnTouchBegin);
			addEventListener(openfl.events.TouchEvent.TOUCH_END, _fluidOnTouchEnd);
			addEventListener(openfl.events.TouchEvent.TOUCH_OUT, _fluidOnTouchOut);
		#end
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
}