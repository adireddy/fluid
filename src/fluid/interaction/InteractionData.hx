package fluid.interaction;

import fluid.core.display.DisplayObject;
import js.html.Event;
import fluid.core.sprites.Sprite;
import fluid.core.math.Point;

@:native("PIXI.interaction.InteractionData")
extern class InteractionData {

	/**
	 * Holds all information related to an Interaction event
	 *
	 * @class
	 * @memberof PIXI.interaction
	 */
	function new();

	/**
     * This point stores the global coords of where the touch/mouse event happened
     *
     * @member {Point}
     */
	var global:Point;

	/**
     * The target Sprite that was interacted with
     *
     * @member {Sprite}
     */
	var target:Sprite;

	/**
     * When passed to an event handler, this will be the original DOM Event that was captured
     *
     * @member {Event}
     */
	var originalEvent:Event;


	/**
     * Touch identifier
     *
     * @member {Event}
     */
	var identifier:Int;

	/**
	 * This will return the local coordinates of the specified displayObject for this InteractionData
	 *
	 * @param displayObject {DisplayObject} The DisplayObject that you would like the local coords off
	 * @param [point] {Point} A Point object in which to store the value, optional (otherwise will create a new point)
	 * @return {Point} A point containing the coordinates of the InteractionData position relative to the DisplayObject
	 */
	function getLocalPosition(displayObject:DisplayObject, ?point:Point):Point;
}