package fluid.core.renderers.webgl.shaders;

import js.html.Float32Array;
import fluid.core.renderers.webgl.managers.ShaderManager;

class ComplexPrimitiveShader extends Shader {

	public function new(shaderManager:ShaderManager) {
		super(shaderManager,
		[
			'attribute vec2 aVertexPosition;',

			'uniform mat3 translationMatrix;',
			'uniform mat3 projectionMatrix;',

			'uniform vec3 tint;',
			'uniform float alpha;',
			'uniform vec3 color;',

			'varying vec4 vColor;',

			'void main(void){',
			'   gl_Position = vec4((projectionMatrix * translationMatrix * vec3(aVertexPosition, 1.0)).xy, 0.0, 1.0);',
			'   vColor = vec4(color * alpha * tint, alpha);',//" * vec4(tint * alpha, alpha);',
			'}'
		].join('\n'),
			// fragment shader
		[
			'precision mediump float;',

			'varying vec4 vColor;',

			'void main(void){',
			'   gl_FragColor = vColor;',
			'}'
		].join('\n'),
			// custom uniforms
		{
			tint:   { type: '3f', value: [0, 0, 0] },
			alpha:  { type: '1f', value: 0 },
			color:  { type: '3f', value: [0,0,0] },
			translationMatrix: { type: 'mat3', value: new Float32Array(9) },
			projectionMatrix: { type: 'mat3', value: new Float32Array(9) }
		},
			// attributes
		{
			aVertexPosition:0
		});
	}
}