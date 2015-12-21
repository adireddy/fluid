package fluid.interaction;

import fluid.core.renderers.SystemRenderer;
import fluid.core.display.DisplayObject;
import fluid.core.math.Point;
import fluid.core.renderers.canvas.CanvasRenderer;
import fluid.core.renderers.webgl.WebGLRenderer;

@:native("PIXI.interaction.InteractionManager")
extern class InteractionManager extends EventEmitter {

	/**
	 * The interaction manager deals with mouse and touch events. Any DisplayObject can be interactive
	 * if its interactive parameter is set to true
	 * This manager also supports multitouch.
	 *
	 * @class
	 * @memberof PIXI.interaction
	 * @param renderer {CanvasRenderer|WebGLRenderer} A reference to the current renderer
	 * @param [options] {object}
	 * @param [options.autoPreventDefault=true] {boolean} Should the manager automatically prevent default browser actions.
	 * @param [options.interactionFrequency=10] {number} Frequency increases the interaction events will be checked.
	 */
	@:overload(function(renderer:CanvasRenderer, ?options:InteractionManagerOptions):Void {})
	function new(renderer:WebGLRenderer);

	/**
     * The renderer this interaction manager works for.
     *
     * @member {SystemRenderer}
     */
	var renderer:SystemRenderer;

	/**
     * Should default browser actions automatically be prevented.
     *
     * @member {Bool}
     * @default true
     */
	var autoPreventDefault:Bool;

	/**
     * As this frequency increases the interaction events will be checked more often.
     *
     * @member {Int}
     * @default 10
     */
	var interactionFrequency:Int;

	/**
     * The mouse data
     *
     * @member {InteractionData}
     */
	var mouse:InteractionData;

	/**
     * An event data object to handle all the event tracking/dispatching
     *
     * @member {EventTarget}
     */
	var eventData:EventTarget;

	/**
     * Tiny little interactiveData pool !
     *
     * @member {Array}
     */
	var interactiveDataPool:Array<InteractionData>;

	/**
     * @member {function}
     */
	var onMouseUp:EventTarget -> Void;

	/**
     * @member {function}
     */
	var onMouseDown:EventTarget -> Void;

	/**
     * @member {function}
     */
	var onMouseMove:EventTarget -> Void;

	/**
     * @member {function}
     */
	var onMouseOut:EventTarget -> Void;

	/**
     * @member {function}
     */
	var onTouchStart:EventTarget -> Void;

	/**
     * @member {function}
     */
	var onTouchEnd:EventTarget -> Void;

	/**
     * @member {function}
     */
	var onTouchMove:EventTarget -> Void;

	/**
     * @member {function}
     */
	var tap:EventTarget -> Void;

	/**
     * @member {function}
     */
	var click:EventTarget -> Void;

	/**
     * @member {Int}
     */
	var last:Int;

	/**
     * The css style of the cursor that is being used
     * @member {String}
     */
	var currentCursorStyle:String;

	/**
	 * Maps x and y coords from a DOM object and maps them correctly to the fluid.view. The resulting value is stored in the point.
	 * This takes into account the fact that the DOM element could be scaled and positioned anywhere on the screen.
	 *
	 * @param  {Point} point the point that the result will be stored in
	 * @param  {Float} x the x coord of the position to map
	 * @param  {Float} y the y coord of the position to map
	 */
	function mapPositionToPoint(point:Point, x:Float, y:Float):Void;

	/**
	 * This function is provides a neat way of crawling through the scene graph and running a specified 	function on all interactive objects it finds.
	 * It will also take care of hit testing the interactive objects and passes the hit across in the 	function.
	 *
	 * @param  {Point} point the point that is tested for collision
	 * @param  {Container|Sprite|TilingSprite} displayObject the displayObject that will be hit test (recurcsivly crawls its children)
	 * @param  {function} func the 	function that will be called on each interactive object. The displayObject and hit will be passed to the 	function
	 * @param  {Bool} hitTest this indicates if the objects inside should be hit test against the point
	 * @return {Bool} returns true if the displayObject hit the point
	 */
	function processInteractive(point:Point, displayObject:DisplayObject, func:Void -> Void, hitTest:Bool, interactive:Bool):Bool;
}

typedef InteractionManagerOptions = {
	@:optional var autoPreventDefault:Bool;
	@:optional var interactionFrequency:Int;
}