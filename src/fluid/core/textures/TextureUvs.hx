package fluid.core.textures;

import fluid.core.math.shapes.Rectangle;

class TextureUvs {

	public var x0:Float;
	public var y0:Float;
	public var x1:Float;
	public var y1:Float;
	public var x2:Float;
	public var y2:Float;
	public var x3:Float;
	public var y3:Float;

	public function new() {
		this.x0 = 0;
		this.y0 = 0;

		this.x1 = 1;
		this.y1 = 0;

		this.x2 = 1;
		this.y2 = 1;

		this.x3 = 0;
		this.y3 = 1;
	}

	public function set(frame:Rectangle, baseFrame:BaseTexture, rotate:Bool) {
		var tw = baseFrame.width;
		var th = baseFrame.height;

		if(rotate) {
			this.x0 = (frame.x + frame.height) / tw;
			this.y0 = frame.y / th;

			this.x1 = (frame.x + frame.height) / tw;
			this.y1 = (frame.y + frame.width) / th;

			this.x2 = frame.x / tw;
			this.y2 = (frame.y + frame.width) / th;

			this.x3 = frame.x / tw;
			this.y3 = frame.y / th;
		}
		else {
			this.x0 = frame.x / tw;
			this.y0 = frame.y / th;

			this.x1 = (frame.x + frame.width) / tw;
			this.y1 = frame.y / th;

			this.x2 = (frame.x + frame.width) / tw;
			this.y2 = (frame.y + frame.height) / th;

			this.x3 = frame.x / tw;
			this.y3 = (frame.y + frame.height) / th;
		}
	}
}