package fluid.display;

class FluidSprite extends #if js pixi.display.DisplayObjectContainer #else openfl.display.Sprite #end {

	@:noCompletion var _texture:#if js pixi.display.Sprite #else openfl.display.Bitmap #end;

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

	public function new(?texture:#if js pixi.textures.Texture #else openfl.display.BitmapData #end) {
		super();
		if (texture != null) {
			#if js
				_texture = new pixi.display.Sprite(texture);
			#else
				mouseChildren = false;
				_texture = new openfl.display.Bitmap(texture);
			#end
			addChild(_texture);
		}

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
}