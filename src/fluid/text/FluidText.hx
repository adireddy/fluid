package fluid.text;

class FluidText extends #if js pixi.text.Text #else openfl.text.TextField #end {

	public function new(txt:String) {
		super(#if js txt #end);
		#if !js text = txt; #end
	}

	#if js override #end public function setText(value:String) {
		#if js super.setText(value);
		#else text = value; #end
	}
}