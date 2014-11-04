package fluid.display;

class FluidStage extends #if js pixi.display.Stage #else openfl.display.Stage #end {

	public static var actualPixelRatio:Float;
	public static var pixelRatio:Float = 1;
	public static var screenWidth:Int = 800;
	public static var screenHeight:Int = 600;
	public static var orientation:String;

	public inline static var LANDSCAPE:String = "LANDSCAPE";
	public inline static var PORTRAIT:String = "PORTRAIT";

	public function new(#if js bgColor:UInt #end) {
		#if js super(bgColor);
		#elseif android super(null, screenWidth, screenHeight);
		#else super(); #end

	}
}