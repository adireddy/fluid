package fluid.core.display;

import fluid.core.renderers.webgl.WebGLRenderer;
import fluid.core.utils.Utils;
import js.Error;
import msignal.Signal.Signal1;

class Container extends DisplayObject {

	public var children:Array<DisplayObject>;
	public var width(get, set):Float;
	public var height(get, set):Float;

	var _width:Float;
	var _height:Float;

	public function new() {
		super();
		this.children = [];
	}

	function set_width(value:Float):Float {
		var width = this.getLocalBounds().width;
		if (width != 0) this.scale.x = value / width;
		else this.scale.x = 1;
		return this._width = value;
	}

	function get_width():Float {
		return this.scale.x * this.getLocalBounds().width;
	}

	function set_height(value:Float):Float {
		var height = this.getLocalBounds().height;
		if (height != 0) this.scale.y = value / height;
		else this.scale.y = 1;
		return this._height = value;
	}

	function get_height():Float {
		return this.scale.y * this.getLocalBounds().height;
	}

	override public function renderWebGL(renderer:WebGLRenderer):Void {
		if (!this.visible || this.worldAlpha <= 0 || !this.renderable) return;

		var i, j;

		if (this._mask != null || this._filters != null) {
			renderer.currentRenderer.flush();
			if (this._filters != null && this._filters.length > 0) {
				renderer.filterManager.pushFilter(this, this._filters);
			}

			if (this._mask != null) {
				renderer.maskManager.pushMask(this, this._mask);
			}

			renderer.currentRenderer.start();
			this._renderWebGL(renderer);
			i = 0;
			j = this.children.length;
			while (i < j) {
				this.children[i].renderWebGL(renderer);
				i++;
			}

			renderer.currentRenderer.flush();

			if (this._mask) {
				renderer.maskManager.popMask(this, this._mask);
			}

			if (this._filters != null) {
				renderer.filterManager.popFilter();

			}
			renderer.currentRenderer.start();
		}
		else {
			this._renderWebGL(renderer);
			i = 0;
			j = this.children.length;
			while (i < j) {
				this.children[i].renderWebGL(renderer);
				i++;
			}
		}
	}

	function _renderWebGL(renderer:WebGLRenderer) {}

	public function addChild(child:DisplayObject):DisplayObject {
		if (child.parent != null) child.parent.removeChild(child);
		child.parent = this;
		this.children.push(child);

		//this.onChildrenChange(this.children.length-1);
		child.added.dispatch(this);
		return child;
	}

	public function addChildAt(child:DisplayObject, index:Int):DisplayObject {
		if (index >= 0 && index <= this.children.length) {
			if (child.parent != null) child.parent.removeChild(child);
			child.parent = this;
			this.children.insert(index, child);
			//this.onChildrenChange(index);
			child.added.dispatch(this);

			return child;
		}
		else throw new Error(child + 'addChildAt: The index ' + index + ' supplied is out of bounds ' + this.children.length);
	}

	public function swapChildren(child1:DisplayObject, child2:DisplayObject):Void {

	}

	//public function getChildIndex(child:DisplayObject):Int;

	public function setChildIndex(child:DisplayObject, index:Int):Void {

	}

	//public function getChildAt(index:Int):DisplayObject {}

	public function removeChild(child:DisplayObject):DisplayObject {
		var index = this.children.indexOf(child);
		if (index == -1) return null;

		child.parent = null;
		Utils.removeItems(this.children, index, 1);
		//this.onChildrenChange(index);
		child.removed.dispatch(this);

		return child;
	}

	//public function removeChildAt(index:Int):DisplayObject;

	//public function removeChildren(?beginIndex:Int, ?endIndex:Int):Void;

	//public function getChildByName(name:String):DisplayObject;
}