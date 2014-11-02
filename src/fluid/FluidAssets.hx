package fluid;

class FluidAssets {

	public function new() {
	}

	static public function getImage(url:String):#if js pixi.textures.Texture #else openfl.display.BitmapData #end {
		return #if js pixi.textures.Texture.fromImage(url) #else openfl.Assets.getBitmapData(url) #end;
	}
}