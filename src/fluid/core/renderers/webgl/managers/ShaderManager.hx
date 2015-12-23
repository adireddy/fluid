package fluid.core.renderers.webgl.managers;

import fluid.core.renderers.webgl.shaders.ComplexPrimitiveShader;
import fluid.core.renderers.webgl.shaders.PrimitiveShader;
import fluid.core.utils.PluginTarget;
import fluid.core.renderers.webgl.shaders.TextureShader;
import js.html.webgl.RenderingContext;

using fluid.core.utils.PluginTarget;

class ShaderManager extends WebGLManager {

	public var maxAttibs:Int;
	public var attribState:Array<Dynamic>;
	public var tempAttribState:Array<Dynamic>;
	public var stack:Array<Dynamic>;

	var _currentId:Int;
	var currentShader:Dynamic;

	public var defaultShader:TextureShader;
	public var primitiveShader:PrimitiveShader;
	public var complexPrimitiveShader:ComplexPrimitiveShader;

	public function new(renderer:WebGLRenderer) {
		super(renderer);
		this.maxAttibs = 10;
		this.attribState = [];
		this.tempAttribState = [];

		for (i in 0 ... this.maxAttibs) this.attribState[i] = false;

		this.stack = [];
		this._currentId = -1;
		this.currentShader = null;
	}

	override function _onContextChange(gl:RenderingContext) {
		this.maxAttibs = gl.getParameter(RenderingContext.MAX_VERTEX_ATTRIBS);
		this.attribState = [];

		for (i in 0 ... this.maxAttibs) this.attribState[i] = false;

		this.defaultShader = new TextureShader(this);
		this.primitiveShader = new PrimitiveShader(this);
		this.complexPrimitiveShader = new ComplexPrimitiveShader(this);
	}

	public function setAttribs(attribs:Array<Dynamic>) {
		var i;
		for (i in 0 ... this.tempAttribState.length) this.tempAttribState[i] = false;
		for (a in attribs) this.tempAttribState[attribs[a]] = true;

		var gl = this.renderer.gl;

		for (i in 0 ... this.attribState.length) {
			if (this.attribState[i] != this.tempAttribState[i]) {
				this.attribState[i] = this.tempAttribState[i];
				if (this.attribState[i]) gl.enableVertexAttribArray(i);
				else gl.disableVertexAttribArray(i);
			}
		}
	}

	public function setShader(shader:Dynamic):Bool {
		if (this._currentId == shader.uid) return false;
		this._currentId = shader.uid;
		this.currentShader = shader;
		this.renderer.gl.useProgram(shader.program);
		this.setAttribs(shader.attributes);
		return true;
	}

	override public function destroy() {
		this.primitiveShader.destroy();
		this.complexPrimitiveShader.destroy();
		super.destroy();
		this.attribState = null;
		this.tempAttribState = null;
	}
}