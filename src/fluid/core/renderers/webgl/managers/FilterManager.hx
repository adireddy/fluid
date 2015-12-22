package fluid.core.renderers.webgl.managers;

import fluid.core.sprites.Sprite;
import fluid.core.math.Matrix;
import fluid.core.renderers.webgl.utils.RenderTarget;
import fluid.core.renderers.webgl.utils.Quad;
import js.html.webgl.RenderingContext;
import fluid.core.math.shapes.Rectangle;

class FilterManager extends WebGLManager {

	public var filterStack:Array<Dynamic>;
	public var texturePool:Array<Dynamic>;

	var textureSize:Rectangle;
	var currentFrame:Rectangle;
	var quad:Quad;

	public function new(renderer:WebGLRenderer) {
		this.filterStack = [];
		this.filterStack.push({
			renderTarget:renderer.currentRenderTarget,
			filter:[],
			bounds:null
		});

		this.texturePool = [];
		this.textureSize = new Rectangle(0, 0, renderer.width, renderer.height);
		this.currentFrame = null;

		super(renderer);
	}

	override function _onContextChange(gl:RenderingContext) {
		this.texturePool = [];
		this.quad = new Quad(this.renderer.gl);
	}

	public function setFilterStack(filterStack:Dynamic):Void {
		this.filterStack = filterStack;
	}

	public function pushFilter(target:Dynamic, filters:Dynamic):Void {
		var bounds:Rectangle = target.filterArea ? target.filterArea.clone() : target.getBounds();
		if (bounds == null) bounds = new Rectangle(0, 0, 0, 0);

		var padding = filters[0].padding;
		if (padding == null) padding = 0;
		bounds.x -= padding;
		bounds.y -= padding;
		bounds.width += padding * 2;
		bounds.height += padding * 2;

		if (this.renderer.currentRenderTarget.transform != null) {
			var transform = this.renderer.currentRenderTarget.transform;

			bounds.x += transform.tx;
			bounds.y += transform.ty;

			this.capFilterArea(bounds);

			bounds.x -= transform.tx;
			bounds.y -= transform.ty;
		}
		else this.capFilterArea(bounds);

		if (bounds.width > 0 && bounds.height > 0) {
			this.currentFrame = bounds;

			var texture = this.getRenderTarget();

			this.renderer.setRenderTarget(texture);

			texture.clear();
			this.filterStack.push({
				renderTarget: texture,
				filter: filters
			});

		}
		else {
			this.filterStack.push({
				renderTarget: null,
				filter: filters
			});
		}
	}

	public function popFilter():Dynamic {
		var filterData = this.filterStack.pop();
		var previousFilterData = this.filterStack[this.filterStack.length - 1];

		var input = filterData.renderTarget;

		if (filterData.renderTarget == null) return null;

		var output = previousFilterData.renderTarget;

		// use program
		var gl = this.renderer.gl;

		this.currentFrame = input.frame;

		this.quad.map(this.textureSize, input.frame);

		gl.bindBuffer(RenderingContext.ARRAY_BUFFER, this.quad.vertexBuffer);
		gl.bindBuffer(RenderingContext.ELEMENT_ARRAY_BUFFER, this.quad.indexBuffer);

		var filters:Array<Dynamic> = filterData.filter;

		// assuming all filters follow the correct format??
		gl.vertexAttribPointer(this.renderer.shaderManager.defaultShader.attributes.aVertexPosition, 2, RenderingContext.FLOAT, false, 0, 0);
		gl.vertexAttribPointer(this.renderer.shaderManager.defaultShader.attributes.aTextureCoord, 2, RenderingContext.FLOAT, false, 0, 2 * 4 * 4);
		gl.vertexAttribPointer(this.renderer.shaderManager.defaultShader.attributes.aColor, 4, RenderingContext.FLOAT, false, 0, 4 * 4 * 4);

		// restore the normal blendmode!
		this.renderer.blendModeManager.setBlendMode(Fluid.BLEND_MODES.NORMAL);

		if (filters.length == 1) {
			if (filters[0].uniforms.dimensions != null) {
				filters[0].uniforms.dimensions.value[0] = this.renderer.width;
				filters[0].uniforms.dimensions.value[1] = this.renderer.height;
				filters[0].uniforms.dimensions.value[2] = this.quad.vertices[0];
				filters[0].uniforms.dimensions.value[3] = this.quad.vertices[5];
			}

			filters[0].applyFilter(this.renderer, input, output);
			this.returnRenderTarget(input);

		}
		else {
			var flipTexture = input;
			var flopTexture = this.getRenderTarget(true);

			for (i in 0 ... filters.length - 1) {
				var filter:Dynamic = filters[i];

				if (filter.uniforms.dimensions != null) {
					filter.uniforms.dimensions.value[0] = this.renderer.width;
					filter.uniforms.dimensions.value[1] = this.renderer.height;
					filter.uniforms.dimensions.value[2] = this.quad.vertices[0];
					filter.uniforms.dimensions.value[3] = this.quad.vertices[5];
				}

				filter.applyFilter(this.renderer, flipTexture, flopTexture);

				var temp = flipTexture;
				flipTexture = flopTexture;
				flopTexture = temp;
			}

			filters[filters.length - 1].applyFilter(this.renderer, flipTexture, output);

			this.returnRenderTarget(flipTexture);
			this.returnRenderTarget(flopTexture);
		}

		return filterData.filter;
	}

	public function getRenderTarget(?clear:Bool = false):Dynamic {
		var renderTarget = this.texturePool.pop();
		if (renderTarget == null) renderTarget =  new RenderTarget(this.renderer.gl, cast this.textureSize.width, cast this.textureSize.height, Fluid.SCALE_MODES.LINEAR, this.renderer.resolution * Fluid.FILTER_RESOLUTION);
		renderTarget.frame = this.currentFrame;
		if (clear) renderTarget.clear(true);
		return renderTarget;
	}

	public function returnRenderTarget(renderTarget:Dynamic):Void {
		this.texturePool.push(renderTarget);
	}

	public function applyFilter(shader:Dynamic, inputTarget:Dynamic, outputTarget:Dynamic, ?clear:Bool = false):Void {
		var gl = this.renderer.gl;

		this.renderer.setRenderTarget(outputTarget);

		if (clear) outputTarget.clear();

		// set the shader
		this.renderer.shaderManager.setShader(shader);

		shader.uniforms.projectionMatrix.value = this.renderer.currentRenderTarget.projectionMatrix.toArray(true, null);

		shader.syncUniforms();

		gl.activeTexture(RenderingContext.TEXTURE0);
		gl.bindTexture(RenderingContext.TEXTURE_2D, inputTarget.texture);

		gl.drawElements(RenderingContext.TRIANGLES, 6, RenderingContext.UNSIGNED_SHORT, 0);
		this.renderer.drawCount++;
	}

	public function calculateMappedMatrix(filterArea:Rectangle, sprite:Sprite, outputMatrix:Matrix):Matrix {
		var worldTransform = sprite.worldTransform.copy(Matrix.TEMP_MATRIX),
		texture = sprite._texture.baseTexture;

		var mappedMatrix = outputMatrix.identity();

		// scale..
		var ratio = this.textureSize.height / this.textureSize.width;

		mappedMatrix.translate(filterArea.x / this.textureSize.width, filterArea.y / this.textureSize.height);

		mappedMatrix.scale(1, ratio);

		var translateScaleX = (this.textureSize.width / texture.width);
		var translateScaleY = (this.textureSize.height / texture.height);

		worldTransform.tx /= texture.width * translateScaleX;
		worldTransform.ty /= texture.width * translateScaleX;

		worldTransform.invert();

		mappedMatrix.prepend(worldTransform);

		// apply inverse scale..
		mappedMatrix.scale(1, 1 / ratio);

		mappedMatrix.scale(translateScaleX, translateScaleY);

		mappedMatrix.translate(sprite.anchor.x, sprite.anchor.y);

		return mappedMatrix;
	}

	public function capFilterArea(filterArea:Rectangle):Void {
		if (filterArea.x < 0) {
			filterArea.width += filterArea.x;
			filterArea.x = 0;
		}

		if (filterArea.y < 0) {
			filterArea.height += filterArea.y;
			filterArea.y = 0;
		}

		if (filterArea.x + filterArea.width > this.textureSize.width) {
			filterArea.width = this.textureSize.width - filterArea.x;
		}

		if (filterArea.y + filterArea.height > this.textureSize.height) {
			filterArea.height = this.textureSize.height - filterArea.y;
		}
	}

	public function resize(width:Int, height:Int):Void {
		this.textureSize.width = width;
		this.textureSize.height = height;
		for (i in 0 ... this.texturePool.length) this.texturePool[i].resize( width, height );
	}

	override public function destroy() {
		this.quad.destroy();

		super.destroy();

		this.filterStack = null;
		//this.offsetY = 0;

		for (i in 0 ... this.texturePool.length) this.texturePool[i].destroy();
		this.texturePool = null;
	}
}