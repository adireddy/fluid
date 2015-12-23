package fluid.core.renderers.webgl.shaders;

import js.html.Float32Array;
import fluid.core.renderers.webgl.managers.ShaderManager;

class TextureShader extends Shader {

	static var defaultVertexSrc:String = [
		'precision lowp float;',
		'attribute vec2 aVertexPosition;',
		'attribute vec2 aTextureCoord;',
		'attribute vec4 aColor;',

		'uniform mat3 projectionMatrix;',

		'varying vec2 vTextureCoord;',
		'varying vec4 vColor;',

		'void main(void){',
		'   gl_Position = vec4((projectionMatrix * vec3(aVertexPosition, 1.0)).xy, 0.0, 1.0);',
		'   vTextureCoord = aTextureCoord;',
		'   vColor = vec4(aColor.rgb * aColor.a, aColor.a);',
		'}'
	].join('\n');

	static var defaultFragmentSrc:String = [
		'precision lowp float;',

		'varying vec2 vTextureCoord;',
		'varying vec4 vColor;',

		'uniform sampler2D uSampler;',

		'void main(void){',
		'   gl_FragColor = texture2D(uSampler, vTextureCoord) * vColor ;',
		'}'
	].join('\n');

	public function new(shaderManager:ShaderManager, ?vertexSrc:String, ?fragmentSrc:String, ?customUniforms:Dynamic, ?customAttributes:Dynamic) {
		var uniforms = {
				uSampler:           { type: 'sampler2D', value: 0 },
				projectionMatrix:   { type: 'mat3', value: new Float32Array([1, 0, 0,
																			 0, 1, 0,
																			 0, 0, 1]) }
		};

		var attributes = {
			aVertexPosition:    0,
			aTextureCoord:      0,
			aColor:             0
		};


		untyped __js__("
			if (customUniforms) {
				for (var u in customUniforms) {
					uniforms[u] = customUniforms[u];
				}
			}

			if (customAttributes) {
				for (var a in customAttributes) {
					attributes[a] = customAttributes[a];
				}
			}
		");

		vertexSrc = vertexSrc != null ? vertexSrc : TextureShader.defaultVertexSrc;
		fragmentSrc = fragmentSrc != null ? fragmentSrc : TextureShader.defaultFragmentSrc;

		super(shaderManager, vertexSrc, fragmentSrc, uniforms, attributes);
	}
}