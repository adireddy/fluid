package fluid.filters.gray;

import fluid.core.renderers.webgl.filters.AbstractFilter;

@:native("PIXI.filters.GrayFilter")
extern class GrayFilter extends AbstractFilter {

	/**
	 * This filter applies a pixelate effect making display objects appear 'blocky'.
	 *
	 * @class
	 * @extends PIXI.AbstractFilter
	 * @memberof PIXI.filters
	 */
	function new();

	/**
     * The strength of the gray. 1 will make the object black and white, 0 will make the object its normal color.
     *
     * @member {number}
     * @memberof GrayFilter#
     */
	var gray:Float;
}