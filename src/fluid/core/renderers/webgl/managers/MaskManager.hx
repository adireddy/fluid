package fluid.core.renderers.webgl.managers;

import fluid.core.renderers.webgl.filters.AbstractFilter;
import fluid.core.renderers.webgl.utils.StencilMaskStack;

class MaskManager extends WebGLManager {

	public var stencilStack:Array<StencilMaskStack>;
	public var reverse:Bool;
	public var count:Int;
	public var alphaMaskPool:Array<Dynamic>;

	public function new(renderer:WebGLRenderer) {
		super(renderer);
		this.stencilStack = [];
		this.reverse = true;
		this.count = 0;
		this.alphaMaskPool = [];
	}

	public function pushMask(target:Dynamic, maskData:Dynamic):Void {
		if (maskData.texture != null) this.pushSpriteMask(target, maskData);
		else this.pushStencilMask(target, maskData);
	}

	public function popMask(target:Dynamic, maskData:Dynamic):Void {
		if (maskData.texture != null) this.popSpriteMask();
		else this.popStencilMask(target, maskData);
	}

	public function pushSpriteMask(target:Dynamic, maskData:Dynamic):Void {
		var alphaMaskFilter = this.alphaMaskPool.pop();
		if (alphaMaskFilter != null) alphaMaskFilter = [new AbstractFilter(maskData)];
		alphaMaskFilter[0].maskSprite = maskData;
		this.renderer.filterManager.pushFilter(target, alphaMaskFilter);
	}

	public function popSpriteMask():Void {
		var filters = this.renderer.filterManager.popFilter();
		this.alphaMaskPool.push(filters);
	}

	public function pushStencilMask(target:Dynamic, maskData:Dynamic):Void {
		this.renderer.stencilManager.pushMask(maskData);
	}

	public function popStencilMask(target:Dynamic, maskData:Dynamic):Void {
		this.renderer.stencilManager.popMask(maskData);
	}
}