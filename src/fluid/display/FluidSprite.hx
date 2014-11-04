package fluid.display;

class FluidSprite extends #if js pixi.display.DisplayObjectContainer #else openfl.display.Sprite #end {

	@:noCompletion var _texture:#if js pixi.display.Sprite #else openfl.display.Bitmap #end;

	public function new(?texture:#if js pixi.textures.Texture #else openfl.display.BitmapData #end) {
		super();
		if (texture != null) {
			#if js
				_texture = new pixi.display.Sprite(texture);
			#else
				mouseChildren = false;
				_texture = new openfl.display.Bitmap(texture);
			#end
			addChild(_texture);
		}
	}
}