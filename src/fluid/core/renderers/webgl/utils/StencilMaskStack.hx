package fluid.core.renderers.webgl.utils;

class StencilMaskStack {

	public var stencilStack:Array<Dynamic>;
	public var reverse:Bool;
	public var count:Int;

	public function new() {
		this.stencilStack = [];
		this.reverse = true;
		this.count = 0;
	}
}