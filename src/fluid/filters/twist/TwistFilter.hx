package fluid.filters.twist;

import fluid.core.math.Point;
import fluid.core.renderers.webgl.filters.AbstractFilter;

@:native("PIXI.filters.TwistFilter")
extern class TwistFilter extends AbstractFilter {

	/**
	 * This filter applies a twist effect making display objects appear twisted in the given direction.
	 *
	 * @class
	 * @extends PIXI.AbstractFilter
	 * @memberof PIXI.filters
	 */
	function new();

	/**
     * This point describes the the offset of the twist.
     *
     * @member {Point}
     * @memberof TwistFilter#
     */
	var offset:Point;

	/**
     * This radius of the twist.
     *
     * @member {number}
     * @memberof TwistFilter#
     */
	var radius:Float;

	/**
     * This angle of the twist.
     *
     * @member {number}
     * @memberof TwistFilter#
     */
	var angle:Float;
}