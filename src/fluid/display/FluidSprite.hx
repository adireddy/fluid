package fluid.display;

class FluidSprite extends #if js pixi.display.Sprite #else openfl.display.Sprite #end {

	public function new(?texture:#if js pixi.textures.Texture #else openfl.display.BitmapData #end) {
		super(#if js texture #end);
		#if !js
			addChild(new openfl.display.Bitmap(texture));
		#end
	}
}