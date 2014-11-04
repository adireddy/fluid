package fluid.text;

class FluidTextFormat {

	public var bold:Bool = false;
	public var italic:Bool = false;
	public var underline:Bool = false;
	public var size:Float = 20;
	public var font:String = "Arial";
	public var fill:String = "#000000";
	public var align:String = "left";

	public function new(?font:String, ?size:Float, ?fill:String, ?bold:Bool, ?italic:Bool, ?underline:Bool, ?align:String) {
		if (font != null) this.font = font;
		if (size != null) this.size = size;
		if (fill != null) this.fill = fill;
		if (bold != null) this.bold = bold;
		if (italic != null) this.italic = italic;
		if (underline != null) this.underline = underline;
		if (align != null) this.align = align;
	}
}
