package fluid.core.renderers.webgl.utils;

import fluid.core.utils.Utils;
import js.html.webgl.Framebuffer;
import js.html.webgl.Renderbuffer;
import fluid.core.math.Matrix;
import fluid.core.math.shapes.Rectangle;
import fluid.core.textures.Texture;
import js.html.webgl.RenderingContext;

class RenderTarget {

	public var gl:RenderingContext;
	public var frameBuffer:Framebuffer;
	public var texture:Texture;
	public var size:Rectangle;
	public var resolution:Float;
	public var projectionMatrix:Matrix;
	public var transform:Matrix;
	public var frame:Rectangle;
	public var stencilBuffer:Renderbuffer;
	public var stencilMaskStack:StencilMaskStack;
	public var filterStack:Dynamic;
	public var scaleMode:Int;
	public var root:Bool;

	public function new(gl:RenderingContext, width:Int, height:Int, ?scaleMode:Int = 0, ?resolution:Float = 1, ?root:Bool = false) {
		this.gl = gl;
		this.frameBuffer = null;
		this.texture = null;
		this.size = new Rectangle(0, 0, 1, 1);
		this.resolution = resolution;
		this.projectionMatrix = new Matrix();
		this.transform = null;
		this.frame = null;
		this.stencilBuffer = null;
		this.stencilMaskStack = new StencilMaskStack();

		this.filterStack = [
			{
				renderTarget:this,
				filter:[],
				bounds:this.size
			}
		];

		this.scaleMode = scaleMode;
		this.root = root;

		if (!this.root) {
			this.frameBuffer = gl.createFramebuffer();
			var texture = gl.createTexture();
			this.texture = cast texture;

			gl.bindTexture(RenderingContext.TEXTURE_2D, texture);
			gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_MAG_FILTER, scaleMode == Fluid.SCALE_MODES.LINEAR ? RenderingContext.LINEAR : RenderingContext.NEAREST);
			gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_MIN_FILTER, scaleMode == Fluid.SCALE_MODES.LINEAR ? RenderingContext.LINEAR : RenderingContext.NEAREST);

			var isPowerOfTwo = Utils.isPowerOfTwo(width, height);

			if (!isPowerOfTwo) {
				gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_WRAP_S, RenderingContext.CLAMP_TO_EDGE);
				gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_WRAP_T, RenderingContext.CLAMP_TO_EDGE);
			}
			else {
				gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_WRAP_S, RenderingContext.REPEAT);
				gl.texParameteri(RenderingContext.TEXTURE_2D, RenderingContext.TEXTURE_WRAP_T, RenderingContext.REPEAT);
			}

			gl.bindFramebuffer(RenderingContext.FRAMEBUFFER, this.frameBuffer);
			gl.framebufferTexture2D(RenderingContext.FRAMEBUFFER, RenderingContext.COLOR_ATTACHMENT0, RenderingContext.TEXTURE_2D, texture, 0);
		}

		this.resize(width, height);
	}

	public function clear(?bind:Bool = false) {
		var gl = this.gl;
		if (bind) gl.bindFramebuffer(RenderingContext.FRAMEBUFFER, this.frameBuffer);
		gl.clearColor(0, 0, 0, 0);
		gl.clear(RenderingContext.COLOR_BUFFER_BIT);
	}

	public function attachStencilBuffer() {
		if (this.stencilBuffer != null) return;

		if (!this.root) {
			var gl = this.gl;
			this.stencilBuffer = gl.createRenderbuffer();
			gl.bindRenderbuffer(RenderingContext.RENDERBUFFER, this.stencilBuffer);
			gl.framebufferRenderbuffer(RenderingContext.FRAMEBUFFER, RenderingContext.DEPTH_STENCIL_ATTACHMENT, RenderingContext.RENDERBUFFER, this.stencilBuffer);
			gl.renderbufferStorage(RenderingContext.RENDERBUFFER, RenderingContext.DEPTH_STENCIL, Std.int(this.size.width * this.resolution), Std.int(this.size.height * this.resolution));
		}
	}

	public function activate() {
		var gl = this.gl;
		gl.bindFramebuffer(RenderingContext.FRAMEBUFFER, this.frameBuffer);
		var projectionFrame:Rectangle = this.frame != null ? this.frame : this.size;
		this.calculateProjection(projectionFrame);
		if (this.transform != null) this.projectionMatrix.append(this.transform);
		gl.viewport(0, 0, Std.int(projectionFrame.width * this.resolution), Std.int(projectionFrame.height * this.resolution));
	}

	public function calculateProjection(projectionFrame:Rectangle) {
		var pm = this.projectionMatrix;
		pm.identity();

		if (!this.root) {
			pm.a = 1 / projectionFrame.width * 2;
			pm.d = 1 / projectionFrame.height * 2;

			pm.tx = -1 - projectionFrame.x * pm.a;
			pm.ty = -1 - projectionFrame.y * pm.d;
		}
		else {
			pm.a = 1 / projectionFrame.width * 2;
			pm.d = -1 / projectionFrame.height * 2;

			pm.tx = -1 - projectionFrame.x * pm.a;
			pm.ty = 1 - projectionFrame.y * pm.d;
		}
	}

	public function resize(?width:Int = 0, ?height:Int = 0) {
		if (this.size.width == width && this.size.height == height) return;
		this.size.width = width;
		this.size.height = height;

		if (!this.root) {
			var gl = this.gl;
			gl.bindTexture(RenderingContext.TEXTURE_2D, cast this.texture);
			gl.texImage2D(RenderingContext.TEXTURE_2D, 0, RenderingContext.RGBA, Std.int(width * this.resolution), Std.int(height * this.resolution), 0, RenderingContext.RGBA, RenderingContext.UNSIGNED_BYTE, null);

			if (this.stencilBuffer != null) {
				gl.bindRenderbuffer(RenderingContext.RENDERBUFFER, this.stencilBuffer);
				gl.renderbufferStorage(RenderingContext.RENDERBUFFER, RenderingContext.DEPTH_STENCIL, Std.int(width * this.resolution), Std.int(height * this.resolution));
			}
		}
		var projectionFrame = this.frame != null ? this.frame : this.size;
		this.calculateProjection(projectionFrame);
	}

	public function destroy() {
		var gl = this.gl;
		gl.deleteRenderbuffer(this.stencilBuffer);
		gl.deleteFramebuffer(this.frameBuffer);
		gl.deleteTexture(cast this.texture);

		this.frameBuffer = null;
		this.texture = null;
	}
}