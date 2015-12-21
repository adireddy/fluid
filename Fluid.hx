import fluid.system.Device;

class Fluid {

	//public static var Log:Kiwi.Utils.Log = new Kiwi.Utils.Log();

	public static var VERSION:String = "0.0.1";

	public static var RENDERER_CANVAS:Int = 0;

	public static var RENDERER_WEBGL:Int = 1;

	public static var RENDERER_AUTO:Int = 2;

	public static var TARGET_BROWSER:Int = 0;

	public static var TARGET_COCOON:Int = 1;

	public static var DEBUG_ON:Int = 0;

	public static var DEBUG_OFF:Int = 1;

	public static var DEVICE:Device = null;

	public static var STATE:Int = 0;

	public static var GROUP:Int = 2;

	public static var ENTITY:Int = 3;

	public static var CAMERA:Int = 4;

	public static var HUD_WIDGET:Int = 5;

	public static var TILE_LAYER:Int = 6;

	public function new() {

	}
}