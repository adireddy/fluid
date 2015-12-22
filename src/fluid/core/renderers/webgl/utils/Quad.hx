package fluid.core.renderers.webgl.utils;

import js.html.ArrayBuffer;
import fluid.core.math.shapes.Rectangle;
import js.html.webgl.Buffer;
import js.html.webgl.RenderingContext;

class Quad {

	public var gl:RenderingContext;
	public var vertices:Dynamic;
	public var uvs:Dynamic;
	public var colors:Dynamic;
	public var indices:Dynamic;

	public var vertexBuffer:Buffer;
	public var indexBuffer:Buffer;

	public function new(gl:RenderingContext) {

		this.gl = gl;

		this.vertices = [
			0,0,
			200,0,
			200,200,
			0,200
		];

		this.uvs = [
			0,0,
			1,0,
			1,1,
			0,1
		];

		this.colors = [
			1,1,1,1,
			1,1,1,1,
			1,1,1,1,
			1,1,1,1
		];

		this.indices = [
			0, 1, 2, 0, 3, 2
		];

		this.vertexBuffer = gl.createBuffer();
		this.indexBuffer = gl.createBuffer();

		gl.bindBuffer(RenderingContext.ARRAY_BUFFER, this.vertexBuffer);
		gl.bufferData(RenderingContext.ARRAY_BUFFER, (8 + 8 + 16) * 4, RenderingContext.DYNAMIC_DRAW);

		gl.bindBuffer(RenderingContext.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
		gl.bufferData(RenderingContext.ELEMENT_ARRAY_BUFFER, this.indices, RenderingContext.STATIC_DRAW);

		this.upload();
	}

	public function map(rect:Rectangle, rect2:Rectangle) {
		var x:Float = 0;
		var y:Float = 0;

		this.uvs[0] = x;
		this.uvs[1] = y;

		this.uvs[2] = x + rect2.width / rect.width;
		this.uvs[3] = y;

		this.uvs[4] = x + rect2.width / rect.width;
		this.uvs[5] = y + rect2.height / rect.height;

		this.uvs[6] = x;
		this.uvs[7] = y + rect2.height / rect.height;

		x = rect2.x;
		y = rect2.y;

		this.vertices[0] = x;
		this.vertices[1] = y;

		this.vertices[2] = x + rect2.width;
		this.vertices[3] = y;

		this.vertices[4] = x + rect2.width;
		this.vertices[5] = y + rect2.height;

		this.vertices[6] = x;
		this.vertices[7] = y + rect2.height;

		this.upload();
	}

	public function upload() {
		var gl = this.gl;
		gl.bindBuffer(RenderingContext.ARRAY_BUFFER, this.vertexBuffer);
		//gl.bufferSubData(RenderingContext.ARRAY_BUFFER, 0, this.vertices);
		//gl.bufferSubData(RenderingContext.ARRAY_BUFFER, 8 * 4, this.uvs);
		//gl.bufferSubData(RenderingContext.ARRAY_BUFFER, (8 + 8) * 4, this.colors);
	}

	public function destroy() {
		var gl = this.gl;
		gl.deleteBuffer(this.vertexBuffer);
		gl.deleteBuffer(this.indexBuffer);
	}
}