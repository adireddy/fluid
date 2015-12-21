package fluid.core.display;

import fluid.interaction.InteractionManager;
import fluid.core.renderers.canvas.CanvasRenderer;
import fluid.core.renderers.webgl.WebGLRenderer;
import fluid.core.textures.Texture;
import fluid.core.math.Matrix;
import fluid.core.math.shapes.Rectangle;
import fluid.core.math.Point;

@:native("PIXI.DisplayObject")
extern class DisplayObject extends InteractionManager {

	/**
	 * The base class for all objects that are rendered on the screen.
	 * This is an abstract class and should not be used on its own rather it should be extended.
	 *
	 * @class
	 * @namespace PIXI
	 */
	function new();

	/**
	 * Returns the global position of the displayObject
	 *
	 * @param point {Point} the point to write the global value to. If null a new point will be returned
	 * @return {Point}
	 */
	function getGlobalPosition(point:Point):Point;

	/**
	 * Retrieves the bounds of the displayObject as a rectangle object
	 *
	 * @param matrix {Matrix}
	 * @return {Rectangle} the rectangular bounding area
	 */
	function getBounds(?matrix:Matrix):Rectangle;

	/**
	 * Retrieves the local bounds of the displayObject as a rectangle object
	 *
	 * @return {Rectangle} the rectangular bounding area
	 */
	function getLocalBounds():Rectangle;

	/**
	 * Calculates the global position of the display object
	 *
	 * @param position {Point} The world origin to calculate from
	 * @return {Point} A point object representing the position of this object
	 */
	function toGlobal(position:Point):Point;

	/**
	 * Calculates the local position of the display object relative to another point
	 *
	 * @param position {Point} The world origin to calculate from
	 * @param [from] {DisplayObject} The DisplayObject to calculate the global position from
	 * @return {Point} A point object representing the position of this object
	 */
	function toLocal(position:Point, ?frm:DisplayObject):Point;

	/**
	 * Useful function that returns a texture of the display object that can then be used to create sprites
	 * This can be quite useful if your displayObject is static / complicated and needs to be reused multiple times.
	 *
	 * @param renderer {CanvasRenderer|WebGLRenderer} The renderer used to generate the texture.
	 * @param resolution {Number} The resolution of the texture being generated
	 * @param scaleMode {Number} See {@link SCALE_MODES} for possible values
	 * @return {Texture} a texture of the display object
	 */
	@:overload(function(renderer:CanvasRenderer, ?resolution:Float, ?scaleMode:Int):Texture {})
	function generateTexture(renderer:WebGLRenderer, ?resolution:Float, ?scaleMode:Int):Texture;

	/*
	 * Updates the object transform for rendering
	 *
	 * TODO - Optimization pass!
	 */
	function updateTransform():Void;
	function displayObjectUpdateTransform():Void;

	/**
	 * Base destroy method for generic display objects
	 * @param [destroyChildren] {Bool} if set to true, all the children will have their destroy method called as well (Container)
	 * @param [destroyTexture] {Bool} Should it destroy the current texture of the sprite as well (Sprite)
	 * @param [destroyBaseTexture] {Bool} whether to destroy the base texture as well (Text, Sprite)
	 */
	@:overload(function(?destroyTexture:Bool, ?destroyBaseTexture:Bool):Void {})
	@:overload(function(?destroyChildren:Bool):Void {})
	function destroy():Void;

	/**
	 * The instance name of the object.
	 *
	 * @member {String}
	 */
	var name:String;

	/**
	 * Set this to true if you want this display object to be cached as a bitmap.
	 * This basically takes a snap shot of the display object as it is at that moment. It can provide a performance benefit for complex static displayObjects.
	 * To remove simply set this property to 'null'
	 *
	 * @member {Bool}
	 * @memberof DisplayObject#
	 */
	var cacheAsBitmap:Bool;

	/**
	 * The coordinate of the object relative to the local coordinates of the parent.
	 *
	 * @member {Point}
	 */
	var position:Point;

	/**
	 * The scale factor of the object.
	 *
	 * @member {Point}
	 */
	var scale:Point;

	/**
	 * The pivot point of the displayObject that it rotates around
	 *
	 * @member {Point}
	 */
	var pivot:Point;

	/**
	 * The rotation of the object in radians.
	 *
	 * @member {Float}
	 */
	var rotation:Float;

	/**
	 * The opacity of the object.
	 *
	 * @member {Float}
	 */
	var alpha:Float;

	/**
	 * The visibility of the object. If false the object will not be drawn, and
	 * the updateTransform function will not be called.
	 *
	 * @member {Bool}
	 */
	var visible:Bool;

	/**
	 * Can this object be rendered, if false the object will not be drawn but the updateTransform
	 * methods will still be called.
	 *
	 * @member {Bool}
	 */
	var renderable:Bool;

	/**
	 * The display object container that contains this display object.
	 *
	 * @member {Container}
	 * @readOnly
	 */
	var parent:Container;

	/**
	 * The multiplied alpha of the displayObject
	 *
	 * @member {Float}
	 * @readOnly
	 */
	var worldAlpha:Float;

	/**
	 * Current transform of the object based on world (parent) factors
	 *
	 * @member {Matrix}
	 * @readOnly
	 */
	var worldTransform:Matrix;

	/**
	 * The area the filter is applied to. This is used as more of an optimisation
	 * rather than figuring out the dimensions of the displayObject each frame you can set this rectangle
	 *
	 * @member {Rectangle}
	 */
	var filterArea:Rectangle;

	/**
	 * The position of the displayObject on the x axis relative to the local coordinates of the parent.
	 *
	 * @member {Float}
	 * @memberof DisplayObject#
	 */
	var x:Float;

	/**
	 * The position of the displayObject on the y axis relative to the local coordinates of the parent.
	 *
	 * @member {Float}
	 * @memberof DisplayObject#
	 */
	var y:Float;

	/**
	 * Indicates if the displayObject is globally visible.
	 *
	 * @member {Bool}
	 * @memberof DisplayObject#
	 * @readonly
	 */
	var worldVisible:Bool;

	/**
	 * Sets a mask for the displayObject. A mask is an object that limits the visibility of an object to the shape of the mask applied to it.
	 * In PIXI a regular mask must be a PIXI.Graphics object. This allows for much faster masking in canvas as it utilises shape clipping.
	 * To remove a mask, set this property to null.
	 *
	 * @member {Graphics}
	 * @memberof DisplayObject#
	 */
	var mask:Dynamic;

	/**
	 * Sets the filters for the displayObject.
	 * * IMPORTANT: This is a webGL only feature and will be ignored by the canvas renderer.
	 * To remove filters simply set this property to 'null'
	 *
	 * @member {Filter[]}
	 * @memberof DisplayObject#
	 */
	var filters:Array<Dynamic>;

	/**
	 * Indicates if the displayObject is interactive or not.
	 *
	 * @member {Bool}
	 * @default false
	 * @memberof DisplayObject#
	 */
	var interactive:Bool;

	/**
	 * Indicates if the displayObject uses button mode or normal mode.
	 *
	 * @member {Bool}
	 * @default false
	 * @memberof DisplayObject#
	 */
	var buttonMode:Bool;

	/**
	 * Indicates if the children of displayObject are interactive or not.
	 *
	 * @member {Bool}
	 * @default true
	 * @memberof DisplayObject#
	 */
	var interactiveChildren:Bool;

	/**
	 * Default cursor.
	 *
	 * @member {String}
	 * @default pointer
	 * @memberof DisplayObject#
	 */
	var defaultCursor:String;

	/**
	 * Hit area
	 *
	 * @memberof DisplayObject#
	 */
	var hitArea:Dynamic;
}