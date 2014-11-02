package fluid.display;

class FluidGraphics extends #if !js openfl.display.Shape #else pixi.primitives.Graphics #end {

	public function new() {
		super();
	}

	#if js override #end public function clear()#if js :pixi.primitives.Graphics #end {
		#if js return super.clear();
		#else this.graphics.clear(); #end
	}

	#if js override #end public function beginFill(fill:UInt, ?alpha:Float = 1)#if js :pixi.primitives.Graphics #end {
		#if js return super.beginFill(fill);
		#else this.graphics.beginFill(fill); this.alpha = alpha; #end
	}

	#if js override #end public function endFill()#if js :pixi.primitives.Graphics #end {
		#if js return super.endFill();
		#else this.graphics.endFill(); #end
	}

	#if js override #end public function drawRect(x:Float, y:Float, w:Float, h:Float)#if js :pixi.primitives.Graphics #end {
		#if js return super.drawRect(x, y, w, h);
		#else this.graphics.drawRect(x, y, w, h); #end
	}

	#if js override #end public function drawCircle(x:Float, y:Float, r:Float)#if js :pixi.primitives.Graphics #end {
		#if js return super.drawCircle(x, y, r);
		#else this.graphics.drawCircle(x, y, r); #end
	}

	#if js override #end public function drawEllipse(x:Float, y:Float, w:Float, h:Float)#if js :pixi.primitives.Graphics #end {
		#if js return super.drawEllipse(x, y, w, h);
		#else this.graphics.drawEllipse(x, y, w, h); #end
	}

	#if js override #end public function drawRoundedRect(x:Float, y:Float, w:Float, h:Float, r:Float)#if js :pixi.primitives.Graphics #end {
		#if js return super.drawRoundedRect(x, y, w, h, r);
		#else this.graphics.drawRoundRectComplex(x, y, w, h, r, r, r, r); #end
	}
}