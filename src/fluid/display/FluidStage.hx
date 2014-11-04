package fluid.display;

class FluidStage extends #if js pixi.display.Stage #else openfl.display.Stage #end {

	public function new(#if js bgColor:UInt #end) {
		super(#if js bgColor #end);
	}
}