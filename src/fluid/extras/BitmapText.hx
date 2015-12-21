package fluid.extras;

import fluid.core.display.Container;

@:native("PIXI.extras.BitmapText")
extern class BitmapText extends Container {

	/**
	 * A BitmapText object will create a line or multiple lines of text using bitmap font. To
	 * split a line you can use '\n', '\r' or '\r\n' in your string. You can generate the fnt files using:
	 *
	 * A BitmapText can only be created when the font is loaded
	 *
	 * ```js
	 * // in this case the font is in a file called 'desyrel.fnt'
	 * 	var bitmapText = new PIXI.BitmapText("text using a fancy font!", {font: "35px Desyrel", align: "right"});
	 * ```
	 *
	 *
	 * http://www.angelcode.com/products/bmfont/ for windows or
	 * http://www.bmglyph.com/ for mac.
	 *
	 * @class
	 * @extends Container
	 * @memberof PIXI.text
	 * @param text {String} The copy that you would like the text to display
	 * @param style {TextStyle} The style parameters
	 * @param style.font {string|object} The font descriptor for the object, can be passed as a string of form
	 * "24px FontName" or "FontName" or as an object with explicit name/size properties.
	 * @param [style.font.name] {string} The bitmap font id
	 * @param [style.font.size] {number} The size of the font in pixels, e.g. 24
	 * @param [style.align='left'] {string} Alignment for multiline text ('left', 'center' or 'right'), does not affect
	 *      single line text
	 * @param [style.tint=0xFFFFFF] {number} The tint color
	 */
	function new(text:String, ?style:BitmapTextStyle):Void;

	/**
	 * The width of the overall text, different from fontSize,
	 * which is defined in the style object
	 *
	 * @member {Float}
	 * @readOnly
	 */
	var textWidth:Float;

	/**
	 * The height of the overall text, different from fontSize,
	 * which is defined in the style object
	 *
	 * @member {Float}
	 * @readOnly
	 */
	var textHeight:Float;

	/**
	 * The max width of this bitmap text in pixels. If the text provided is longer than the value provided, line breaks will be automatically inserted in the last whitespace.
	 * Disable by setting value to 0
	 *
	 * @member {Float}
	 */
	var maxWidth:Float;

	/**
	 * The dirty state of this object.
	 *
	 * @member {Bool}
	 */
	var dirty:Bool;

	/**
	 * The tint of the BitmapText object
	 *
	 * @member {Int}
	 * @memberof BitmapText#
	 */
	var tint:Int;

	/**
	 * The alignment of the BitmapText object
	 *
	 * @member {String}
	 * @default 'left'
	 * @memberof BitmapText#
	 */
	var align:String;

	/**
     * The font descriptor of the BitmapText object
     *
     * @member {Dynamic}
     * @memberof BitmapText#
     */
	var font:Dynamic;

	/**
	 * The text of the BitmapText object
	 *
	 * @member {String}
	 * @memberof BitmapText#
	 */
	var text:String;
}

typedef BitmapTextStyle = {
	@:optional var font:Dynamic;
	@:optional var align:String;
	@:optional var tint:Int;
}