package fluid.core.renderers.webgl.managers;

class BlendModeManager extends WebGLManager {

	var currentBlendMode:Int;

	public function new(renderer:WebGLRenderer) {
		super(renderer);
		this.currentBlendMode = 99999;
	}

	public function setBlendMode(blendMode:Int):Bool {
		if (this.currentBlendMode == blendMode) return false;

		this.currentBlendMode = blendMode;

		var mode = this.renderer.blendModes[this.currentBlendMode];
		this.renderer.gl.blendFunc(mode[0], mode[1]);

		return true;
	}
}