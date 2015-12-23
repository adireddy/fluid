package fluid.core.sprites.webgl;

import fluid.core.textures.BaseTexture;
import js.html.webgl.RenderingContext;
import js.html.webgl.Buffer;
import js.html.Float32Array;
import js.html.Uint16Array;
import js.html.Uint32Array;
import js.html.ArrayBuffer;
import fluid.core.renderers.webgl.WebGLRenderer;
import fluid.core.renderers.webgl.utils.ObjectRenderer;

class SpriteRenderer extends ObjectRenderer {

	public var vertSize:Float;
	public var vertByteSize:Float;
	public var size:Float;
	public var vertices:ArrayBuffer;
	public var positions:Float32Array;
	public var colors:Uint32Array;
	public var indices:Uint16Array;

	public var currentBatchSize:Int;
	public var sprites:Array<Sprite>;
	public var shader:Dynamic;

	public var vertexBuffer:Buffer;
	public var indexBuffer:Buffer;

	public var currentBlendMode:Int;

	public function new(renderer:WebGLRenderer) {
		super(renderer);

		this.vertSize = 5;
		this.vertByteSize = this.vertSize * 4;
		this.size = Fluid.SPRITE_BATCH_SIZE;
		var numVerts = Std.int((this.size * 4) * this.vertByteSize);
		var numIndices = Std.int(this.size * 6);
		this.vertices = new ArrayBuffer(numVerts);
		this.positions = new Float32Array(this.vertices);
		this.colors = new Uint32Array(this.vertices);
		this.indices = new Uint16Array(numIndices);

		var j = 0;
		var i = 0;
		while (i < numIndices) {
			this.indices[i + 0] = j + 0;
			this.indices[i + 1] = j + 1;
			this.indices[i + 2] = j + 2;
			this.indices[i + 3] = j + 0;
			this.indices[i + 4] = j + 2;
			this.indices[i + 5] = j + 3;
			i += 6;
			j += 4;
		}

		this.currentBatchSize = 0;
		this.sprites = [];
		this.shader = null;
	}

	override function _onContextChange(gl:RenderingContext) {
		var gl = this.renderer.gl;

		this.shader = this.renderer.shaderManager.defaultShader;

		this.vertexBuffer = gl.createBuffer();
		this.indexBuffer = gl.createBuffer();

		gl.bindBuffer(RenderingContext.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
		gl.bufferData(RenderingContext.ELEMENT_ARRAY_BUFFER, this.indices, RenderingContext.STATIC_DRAW);

		gl.bindBuffer(RenderingContext.ARRAY_BUFFER, this.vertexBuffer);
		gl.bufferData(RenderingContext.ARRAY_BUFFER, this.vertices, RenderingContext.DYNAMIC_DRAW);

		this.currentBlendMode = 99999;
	}

	override public function render(sprite:Sprite) {
		var texture = sprite.texture;
		if (this.currentBatchSize >= this.size) this.flush();

		var uvs = texture._uvs;
		if (uvs == null) return;

		var aX = sprite.anchor.x;
		var aY = sprite.anchor.y;

		var w0, w1, h0, h1;

		if (texture.trim != null && sprite.tileScale == null) {
			var trim = texture.trim;

			w1 = trim.x - aX * trim.width;
			w0 = w1 + texture.crop.width;

			h1 = trim.y - aY * trim.height;
			h0 = h1 + texture.crop.height;

		}
		else {
			w0 = (texture.frame.width ) * (1 - aX);
			w1 = (texture.frame.width ) * -aX;

			h0 = texture.frame.height * (1 - aY);
			h1 = texture.frame.height * -aY;
		}

		var index:Int = Std.int(this.currentBatchSize * this.vertByteSize);

		var worldTransform = sprite.worldTransform;

		var a = worldTransform.a;
		var b = worldTransform.b;
		var c = worldTransform.c;
		var d = worldTransform.d;
		var tx = worldTransform.tx;
		var ty = worldTransform.ty;

		var colors = this.colors;
		var positions = this.positions;

		if (this.renderer.roundPixels) {
			var resolution = this.renderer.resolution;
			// xy
			/*positions[index] = (((a * w1 + c * h1 + tx) * resolution) | 0) / resolution;
			positions[index + 1] = (((d * h1 + b * w1 + ty) * resolution) | 0) / resolution;

			// xy
			positions[index + 5] = (((a * w0 + c * h1 + tx) * resolution) | 0) / resolution;
			positions[index + 6] = (((d * h1 + b * w0 + ty) * resolution) | 0) / resolution;

			// xy
			positions[index + 10] = (((a * w0 + c * h0 + tx) * resolution) | 0) / resolution;
			positions[index + 11] = (((d * h0 + b * w0 + ty) * resolution) | 0) / resolution;

			// xy
			positions[index + 15] = (((a * w1 + c * h0 + tx) * resolution) | 0) / resolution;
			positions[index + 16] = (((d * h0 + b * w1 + ty) * resolution) | 0) / resolution;*/
		}
		else {

			// xy
			positions[index] = a * w1 + c * h1 + tx;
			positions[index + 1] = d * h1 + b * w1 + ty;

			// xy
			positions[index + 5] = a * w0 + c * h1 + tx;
			positions[index + 6] = d * h1 + b * w0 + ty;

			// xy
			positions[index + 10] = a * w0 + c * h0 + tx;
			positions[index + 11] = d * h0 + b * w0 + ty;

			// xy
			positions[index + 15] = a * w1 + c * h0 + tx;
			positions[index + 16] = d * h0 + b * w1 + ty;
		}

		// uv
		positions[index + 2] = uvs.x0;
		positions[index + 3] = uvs.y0;

		// uv
		positions[index + 7] = uvs.x1;
		positions[index + 8] = uvs.y1;

		// uv
		positions[index + 12] = uvs.x2;
		positions[index + 13] = uvs.y2;

		// uv
		positions[index + 17] = uvs.x3;
		positions[index + 18] = uvs.y3;

		// color and alpha
		var tint = sprite.tint;
		//colors[index + 4] = colors[index + 9] = colors[index + 14] = colors[index + 19] = (tint >> 16) + (tint & 0xff00) + ((tint & 0xff) << 16) + (sprite.worldAlpha * 255 << 24);

		// increment the batchsize
		this.sprites[this.currentBatchSize++] = sprite;
	}

	override public function flush() {
		untyped __js__("
		 	if (this.currentBatchSize === 0)
			{
				return;
			}

			var gl = this.renderer.gl;
			var shader;

			// upload the verts to the buffer
			if (this.currentBatchSize > ( this.size * 0.5 ) )
			{
				gl.bufferSubData(gl.ARRAY_BUFFER, 0, this.vertices);
			}
			else
			{
				var view = this.positions.subarray(0, this.currentBatchSize * this.vertByteSize);
				gl.bufferSubData(gl.ARRAY_BUFFER, 0, view);
			}

			var nextTexture, nextBlendMode, nextShader;
			var batchSize = 0;
			var start = 0;

			var currentBaseTexture = null;
			var currentBlendMode = this.renderer.blendModeManager.currentBlendMode;
			var currentShader = null;

			var blendSwap = false;
			var shaderSwap = false;
			var sprite;

			for (var i = 0, j = this.currentBatchSize; i < j; i++)
			{

				sprite = this.sprites[i];

				nextTexture = sprite.texture.baseTexture;
				nextBlendMode = sprite.blendMode;
				nextShader = sprite.shader || this.shader;

				blendSwap = currentBlendMode !== nextBlendMode;
				shaderSwap = currentShader !== nextShader; // should I use uidS???

				if (currentBaseTexture !== nextTexture || blendSwap || shaderSwap)
				{
					this.renderBatch(currentBaseTexture, batchSize, start);

					start = i;
					batchSize = 0;
					currentBaseTexture = nextTexture;

					if (blendSwap)
					{
						currentBlendMode = nextBlendMode;
						this.renderer.blendModeManager.setBlendMode( currentBlendMode );
					}

					if (shaderSwap)
					{
						currentShader = nextShader;



						shader = currentShader.shaders ? currentShader.shaders[gl.id] : currentShader;

						if (!shader)
						{
							shader = currentShader.getShader(this.renderer);

						}

						// set shader function???
						this.renderer.shaderManager.setShader(shader);

						//TODO - i KNOW this can be optimised! Once v3 is stable il look at this next...
						shader.uniforms.projectionMatrix.value = this.renderer.currentRenderTarget.projectionMatrix.toArray(true);
						//Make this a little more dynamic / intelligent!
						shader.syncUniforms();

						//TODO investigate some kind of texture state managment??
						// need to make sure this texture is the active one for all the batch swaps..
						gl.activeTexture(gl.TEXTURE0);

						// both thease only need to be set if they are changing..
						// set the projection
						//gl.uniformMatrix3fv(shader.uniforms.projectionMatrix._location, false, this.renderer.currentRenderTarget.projectionMatrix.toArray(true));


					}
				}

				batchSize++;
			}

			this.renderBatch(currentBaseTexture, batchSize, start);

			// then reset the batch!
			this.currentBatchSize = 0;
		");
	}

	public function renderBatch(texture:BaseTexture, size:Int, startIndex:Int) {
		untyped __js__("
			if (size === 0)
			{
				return;
			}

			var gl = this.renderer.gl;

			if (!texture._glTextures[gl.id])
			{
				this.renderer.updateTexture(texture);
			}
			else
			{
				// bind the current texture
				gl.bindTexture(gl.TEXTURE_2D, texture._glTextures[gl.id]);
			}

			// now draw those suckas!
			gl.drawElements(gl.TRIANGLES, size * 6, gl.UNSIGNED_SHORT, startIndex * 6 * 2);

			// increment the draw count
			this.renderer.drawCount++;
		");
	}
}