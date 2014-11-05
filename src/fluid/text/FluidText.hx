package fluid.text;

import StringTools;
class FluidText extends #if js pixi.text.Text #else openfl.text.TextField #end {

	#if !js
	@:noCompletion var _anchorX:Float = 0;
	@:noCompletion var _anchorY:Float = 0;

	public var interactive(null, set):Bool;
	public function set_interactive(val:Bool):Bool {
		mouseEnabled = val;
		return interactive = val;
	}
	#end

	@:noCompletion var __height:Float;
	@:noCompletion var __width:Float;

	public function new(txt:String, ?format:FluidTextFormat) {
		super(#if js txt #end);
		if (format != null) setFormat(format);
		#if !js text = txt; autoSize = openfl.text.TextFieldAutoSize.LEFT; selectable = false; #end
	}

	#if js override #end public function setText(value:String) {
		__width = width;
		__height = height;
		#if js super.setText(value);
		#else text = value; setAnchor(_anchorX, _anchorY); #end
	}

	public function setFormat(format:FluidTextFormat) {
		#if js
			var tf = new pixi.text.TextStyle();
			var fullFont:String = "";
			if (format.bold) fullFont += "bold ";
			if (format.italic) fullFont += "italic ";
			if (format.underline) fullFont += "underline ";
			tf.fill = format.fill;
			tf.align = format.align;
			tf.font = fullFont + format.size + "px " + format.font;
			super.setStyle(tf);
		#else
			var tf = new openfl.text.TextFormat();
			tf.font = format.font;
			tf.size = format.size;
			tf.color = Std.parseInt(StringTools.replace(format.fill, "#", "0x"));
			tf.bold = format.bold;
			tf.italic = format.italic;
			tf.underline = format.underline;
			defaultTextFormat = tf;
		#end
	}

	public function setAnchor(?ax:Float = 0, ?ay:Float = 0) {
		#if js anchor.set(ax, ay); #else
			_anchorX = ax;
			_anchorY = ay;
			x -= (width - __width) * ax;
			y -= (height - __height) * ay;
		#end
	}
}