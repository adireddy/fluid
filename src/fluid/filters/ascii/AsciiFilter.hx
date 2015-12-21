package fluid.filters.ascii;

import fluid.core.math.Point;
import fluid.core.renderers.webgl.filters.AbstractFilter;

@:native("PIXI.filters.AsciiFilter")
extern class AsciiFilter extends AbstractFilter {

	/**
	 * An ASCII filter.
	 *
	 * @class
	 * @extends PIXI.AbstractFilter
	 * @memberof PIXI.filters
	 */
	function new();

	/**
     * The pixel size used by the filter.
     *
     * @member {number}
     * @memberof AsciiFilter#
     */
	var size:Point;
}