package fluid.core.renderers.webgl.managers;

import js.html.webgl.RenderingContext;
import fluid.core.renderers.webgl.WebGLRenderer;

class WebGLManager {

	public var renderer:WebGLRenderer;

	public function new(renderer:WebGLRenderer) {
		this.renderer = renderer;
		this.renderer.context.add(_onContextChange);
	}

	function _onContextChange(gl:RenderingContext):Void {}

	public function destroy():Void {
		this.renderer.context.remove(_onContextChange);
		this.renderer = null;
	}
}