package fluid.core.renderers.webgl.managers;

import fluid.core.utils.Utils;
import js.html.webgl.RenderingContext;
import fluid.core.graphics.Graphics;
import fluid.core.renderers.webgl.utils.StencilMaskStack;

class StencilManager extends WebGLManager {

	public var stencilMaskStack:StencilMaskStack;

	public function new(renderer:WebGLRenderer) {
		super(renderer);
		this.stencilMaskStack = null;
	}

	public function setMaskStack(stencilMaskStack:StencilMaskStack) {
		this.stencilMaskStack = stencilMaskStack;
		var gl = this.renderer.gl;

		if (stencilMaskStack.stencilStack.length == 0) gl.disable(RenderingContext.STENCIL_TEST);
		else gl.enable(RenderingContext.STENCIL_TEST);
	}

	public function pushStencil(graphics:Graphics, webGLData:Dynamic) {
		this.renderer.currentRenderTarget.attachStencilBuffer();

		var gl = this.renderer.gl,
		sms = this.stencilMaskStack;

		this.bindGraphics(graphics, webGLData);

		if (sms.stencilStack.length == 0) {
			gl.enable(RenderingContext.STENCIL_TEST);
			gl.clear(RenderingContext.STENCIL_BUFFER_BIT);
			sms.reverse = true;
			sms.count = 0;
		}

		sms.stencilStack.push(webGLData);

		var level = sms.count;

		gl.colorMask(false, false, false, false);

		gl.stencilFunc(RenderingContext.ALWAYS, 0, 0xFF);
		gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.INVERT);

		// draw the triangle strip!

		if (webGLData.mode == 1) {
			gl.drawElements(RenderingContext.TRIANGLE_FAN, Std.int(webGLData.indices.length - 4), RenderingContext.UNSIGNED_SHORT, 0);

			if (sms.reverse) {
				gl.stencilFunc(RenderingContext.EQUAL, 0xFF - level, 0xFF);
				gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.DECR);
			}
			else {
				gl.stencilFunc(RenderingContext.EQUAL, level, 0xFF);
				gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.INCR);
			}

			// draw a quad to increment..
			gl.drawElements(RenderingContext.TRIANGLE_FAN, 4, RenderingContext.UNSIGNED_SHORT, Std.int((webGLData.indices.length - 4 ) * 2));

			if (sms.reverse) {
				gl.stencilFunc(RenderingContext.EQUAL, 0xFF - (level + 1), 0xFF);
			}
			else {
				gl.stencilFunc(RenderingContext.EQUAL, level + 1, 0xFF);
			}

			sms.reverse = !sms.reverse;
		}
		else {
			if (!sms.reverse) {
				gl.stencilFunc(RenderingContext.EQUAL, 0xFF - level, 0xFF);
				gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.DECR);
			}
			else {
				gl.stencilFunc(RenderingContext.EQUAL, level, 0xFF);
				gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.INCR);
			}

			gl.drawElements(RenderingContext.TRIANGLE_STRIP, webGLData.indices.length, RenderingContext.UNSIGNED_SHORT, 0);

			if (!sms.reverse) {
				gl.stencilFunc(RenderingContext.EQUAL, 0xFF - (level + 1), 0xFF);
			}
			else {
				gl.stencilFunc(RenderingContext.EQUAL, level + 1, 0xFF);
			}
		}

		gl.colorMask(true, true, true, true);
		gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.KEEP);

		sms.count++;
	}

	public function bindGraphics(graphics:Graphics, webGLData:Dynamic) {
		var gl = this.renderer.gl;

		var shader:Dynamic;

		if (webGLData.mode == 1) {
			shader = this.renderer.shaderManager.complexPrimitiveShader;

			this.renderer.shaderManager.setShader(shader);

			gl.uniformMatrix3fv(shader.uniforms.translationMatrix._location, false, graphics.worldTransform.toArray(true, null));
			gl.uniformMatrix3fv(shader.uniforms.projectionMatrix._location, false, this.renderer.currentRenderTarget.projectionMatrix.toArray(true, null));

			gl.uniform3fv(shader.uniforms.tint._location, Utils.hex2rgb(graphics.tint));
			gl.uniform3fv(shader.uniforms.color._location, webGLData.color);

			gl.uniform1f(shader.uniforms.alpha._location, graphics.worldAlpha);

			gl.bindBuffer(RenderingContext.ARRAY_BUFFER, webGLData.buffer);

			gl.vertexAttribPointer(shader.attributes.aVertexPosition, 2, RenderingContext.FLOAT, false, 4 * 2, 0);

			// now do the rest..
			// set the index buffer!
			gl.bindBuffer(RenderingContext.ELEMENT_ARRAY_BUFFER, webGLData.indexBuffer);
		}
		else {
			//this.renderer.shaderManager.activatePrimitiveShader();
			shader = this.renderer.shaderManager.primitiveShader;

			this.renderer.shaderManager.setShader(shader);

			gl.uniformMatrix3fv(shader.uniforms.translationMatrix._location, false, graphics.worldTransform.toArray(true, null));
			gl.uniformMatrix3fv(shader.uniforms.projectionMatrix._location, false, this.renderer.currentRenderTarget.projectionMatrix.toArray(true, null));

			gl.uniform3fv(shader.uniforms.tint._location, Utils.hex2rgb(graphics.tint));

			gl.uniform1f(shader.uniforms.alpha._location, graphics.worldAlpha);

			gl.bindBuffer(RenderingContext.ARRAY_BUFFER, webGLData.buffer);

			gl.vertexAttribPointer(shader.attributes.aVertexPosition, 2, RenderingContext.FLOAT, false, 4 * 6, 0);
			gl.vertexAttribPointer(shader.attributes.aColor, 4, RenderingContext.FLOAT, false, 4 * 6, 2 * 4);

			// set the index buffer!
			gl.bindBuffer(RenderingContext.ELEMENT_ARRAY_BUFFER, webGLData.indexBuffer);
		}
	}

	public function popStencil(graphics:Graphics, webGLData:Dynamic) {
		var gl = this.renderer.gl,
		sms = this.stencilMaskStack;
		sms.stencilStack.pop();
		sms.count--;

		if (sms.stencilStack.length == 0) gl.disable(RenderingContext.STENCIL_TEST);
		else {
			var level = sms.count;
			this.bindGraphics(graphics, webGLData);
			gl.colorMask(false, false, false, false);

			if (webGLData.mode == 1) {
				sms.reverse = !sms.reverse;

				if (sms.reverse) {
					gl.stencilFunc(RenderingContext.EQUAL, 0xFF - (level + 1), 0xFF);
					gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.INCR);
				}
				else {
					gl.stencilFunc(RenderingContext.EQUAL, level + 1, 0xFF);
					gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.DECR);
				}

				// draw a quad to increment..
				gl.drawElements(RenderingContext.TRIANGLE_FAN, 4, RenderingContext.UNSIGNED_SHORT, Std.int((webGLData.indices.length - 4 ) * 2));

				gl.stencilFunc(RenderingContext.ALWAYS, 0, 0xFF);
				gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.INVERT);

				// draw the triangle strip!
				gl.drawElements(RenderingContext.TRIANGLE_FAN, Std.int(webGLData.indices.length - 4), RenderingContext.UNSIGNED_SHORT, 0);

				this.renderer.drawCount += 2;

				if (!sms.reverse) gl.stencilFunc(RenderingContext.EQUAL, 0xFF - (level), 0xFF);
				else gl.stencilFunc(RenderingContext.EQUAL, level, 0xFF);
			}
			else {
				if (!sms.reverse) {
					gl.stencilFunc(RenderingContext.EQUAL, 0xFF - (level + 1), 0xFF);
					gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.INCR);
				}
				else {
					gl.stencilFunc(RenderingContext.EQUAL, level + 1, 0xFF);
					gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.DECR);
				}

				gl.drawElements(RenderingContext.TRIANGLE_STRIP, webGLData.indices.length, RenderingContext.UNSIGNED_SHORT, 0);

				this.renderer.drawCount++;

				if (!sms.reverse) {
					gl.stencilFunc(RenderingContext.EQUAL, 0xFF - (level), 0xFF);
				}
				else {
					gl.stencilFunc(RenderingContext.EQUAL, level, 0xFF);
				}
			}

			gl.colorMask(true, true, true, true);
			gl.stencilOp(RenderingContext.KEEP, RenderingContext.KEEP, RenderingContext.KEEP);

		}
	}

	override public function destroy() {
		super.destroy();
		this.stencilMaskStack.stencilStack = null;
	}

	public function pushMask(maskData:Dynamic) {
		this.renderer.setObjectRenderer(this.renderer.plugins.get("graphics"));
		if (maskData.dirty) {
			this.renderer.plugins.get("graphics").updateGraphics(maskData, this.renderer.gl);
		}

		if (!maskData._webGL[Reflect.field(this.renderer.gl, "id")].data.length) {
			return;
		}

		this.pushStencil(maskData, maskData._webGL[Reflect.field(this.renderer.gl, "id")].data[0]);
	}

	public function popMask(maskData:Dynamic) {
		this.renderer.setObjectRenderer(this.renderer.plugins.get("graphics"));
		this.popStencil(maskData, maskData._webGL[Reflect.field(this.renderer.gl, "id")].data[0]);
	}
}