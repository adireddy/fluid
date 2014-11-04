package fluid.display;

class FluidDisplayObjectContainer extends #if js pixi.display.DisplayObjectContainer #else openfl.display.DisplayObjectContainer #end {

	public function new() {
		super();
	}
}