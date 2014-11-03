(function e(t,n,r){function s(o,u){if(!n[o]){if(!t[o]){var a=typeof require=="function"&&require;if(!u&&a)return a(o,!0);if(i)return i(o,!0);var f=new Error("Cannot find module '"+o+"'");throw f.code="MODULE_NOT_FOUND",f}var l=n[o]={exports:{}};t[o][0].call(l.exports,function(e){var n=t[o][1][e];return s(n?n:e)},l,l.exports,e,t,n,r)}return n[o].exports}var i=typeof require=="function"&&require;for(var o=0;o<r.length;o++)s(r[o]);return s})({1:[function(require,module,exports){
(function () { "use strict";
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
var Std = function() { };
Std.random = function(x) {
	if(x <= 0) return 0; else return Math.floor(Math.random() * x);
};
var fluid = {};
fluid.display = {};
fluid.display.FluidSprite = function(texture) {
	PIXI.Sprite.call(this,texture);
};
fluid.display.FluidSprite.__super__ = PIXI.Sprite;
fluid.display.FluidSprite.prototype = $extend(PIXI.Sprite.prototype,{
});
var com = {};
com.arm = {};
com.arm.demo = {};
com.arm.demo.Bunny = function(texture) {
	fluid.display.FluidSprite.call(this,texture);
};
com.arm.demo.Bunny.__super__ = fluid.display.FluidSprite;
com.arm.demo.Bunny.prototype = $extend(fluid.display.FluidSprite.prototype,{
});
fluid.Fluid = function() {
	this._fluidFrameSkip = false;
	this.skipFrame = false;
	this.elapsedTime = 0;
	this._lastTime = new Date();
	this._setStageProperties();
	var _this = window.document;
	this._canvas = _this.createElement("canvas");
	this._canvas.style.width = fluid.StageProperties.screenWidth + "px";
	this._canvas.style.height = fluid.StageProperties.screenHeight + "px";
	window.document.body.appendChild(this._canvas);
	this.stage = new PIXI.Stage(16777215);
	this.container = new PIXI.DisplayObjectContainer();
	this.stage.addChild(this.container);
	this.stage.mousedown = $bind(this,this._fluidOnMouseDown);
	this.stage.mouseout = $bind(this,this._fluidOnMouseOut);
	this.stage.mouseover = $bind(this,this._fluidOnMouseOver);
	this.stage.mouseup = $bind(this,this._fluidOnMouseUp);
	this.stage.click = $bind(this,this._fluidOnMouseClick);
	this.stage.rightclick = $bind(this,this._fluidOnRightClick);
	this.stage.rightdown = $bind(this,this._fluidOnRightMouseDown);
	this.stage.rightup = $bind(this,this._fluidOnRightMouseUp);
	this.stage.touchstart = $bind(this,this._fluidOnTouchBegin);
	this.stage.touchend = $bind(this,this._fluidOnTouchEnd);
	this.stage.touchendoutside = $bind(this,this._fluidOnTouchOut);
	var renderingOptions = new pixi.utils.RenderingOptions();
	renderingOptions.view = this._canvas;
	renderingOptions.resolution = fluid.StageProperties.pixelRatio;
	this._renderer = PIXI.autoDetectRenderer(fluid.StageProperties.screenWidth,fluid.StageProperties.screenHeight,renderingOptions);
	window.document.body.appendChild(this._renderer.view);
	window.onresize = $bind(this,this._fluidOnResize);
	window.requestAnimationFrame($bind(this,this._fluidOnUpdate));
	this._lastTime = new Date();
};
fluid.Fluid.prototype = {
	_setStageProperties: function() {
		fluid.StageProperties.pixelRatio = window.devicePixelRatio;
		fluid.StageProperties.screenWidth = window.innerWidth;
		fluid.StageProperties.screenHeight = window.innerHeight;
		if(fluid.StageProperties.screenWidth > fluid.StageProperties.screenHeight) fluid.StageProperties.orientation = "LANDSCAPE"; else fluid.StageProperties.orientation = "PORTRAIT";
	}
	,_fluidOnMouseDown: function(evt) {
		if(this.mouseDown != null) this.mouseDown(evt);
	}
	,_fluidOnMouseOver: function(evt) {
		if(this.mouseOver != null) this.mouseOver(evt);
	}
	,_fluidOnMouseOut: function(evt) {
		if(this.mouseOut != null) this.mouseOut(evt);
	}
	,_fluidOnMouseUp: function(evt) {
		if(this.mouseUp != null) this.mouseUp(evt);
	}
	,_fluidOnMouseClick: function(evt) {
		if(this.click != null) this.click(evt);
	}
	,_fluidOnRightClick: function(evt) {
		if(this.rightClick != null) this.rightClick(evt);
	}
	,_fluidOnRightMouseDown: function(evt) {
		if(this.rightMouseDown != null) this.rightMouseDown(evt);
	}
	,_fluidOnRightMouseUp: function(evt) {
		if(this.rightMouseUp != null) this.rightMouseUp(evt);
	}
	,_fluidOnTouchBegin: function(evt) {
		if(this.touchBegin != null) this.touchBegin(evt);
	}
	,_fluidOnTouchEnd: function(evt) {
		if(this.touchEnd != null) this.touchEnd(evt);
	}
	,_fluidOnTouchOut: function(evt) {
		if(this.touchOut != null) this.touchOut(evt);
	}
	,_fluidOnUpdate: function() {
		if(this.skipFrame && this._fluidFrameSkip) this._fluidFrameSkip = false; else {
			this._fluidFrameSkip = true;
			this._fluidCalculateElapsedTime();
			this._update(this.elapsedTime);
			this._renderer.render(this.stage);
		}
		window.requestAnimationFrame($bind(this,this._fluidOnUpdate));
		if(this._stats != null) this._stats.update();
	}
	,_fluidCalculateElapsedTime: function() {
		this._currentTime = new Date();
		this.elapsedTime = this._currentTime.getTime() - this._lastTime.getTime();
		this._lastTime = this._currentTime;
	}
	,_fluidOnResize: function(event) {
		this._setStageProperties();
		this._resize();
	}
	,_update: function(elapsed) {
	}
	,_resize: function() {
	}
	,_showStats: function() {
		var _container = window.document.createElement("div");
		window.document.body.appendChild(_container);
		this._stats = new Stats();
		this._stats.domElement.style.position = "absolute";
		this._stats.domElement.style.top = "6px";
		this._stats.domElement.style.right = "6px";
		_container.appendChild(this._stats.domElement);
		this._stats.begin();
	}
};
com.arm.demo.Main = function() {
	this._addBunnies = false;
	this._count = 0;
	var _g = this;
	fluid.Fluid.call(this);
	this.skipFrame = true;
	this._minX = this._minY = 0;
	this._maxX = fluid.StageProperties.screenWidth;
	this._maxY = fluid.StageProperties.screenHeight;
	this._sprites = [];
	this._countText = new fluid.text.FluidText("BUNNIES: 0");
	this.container.addChild(this._countText);
	this._bunnyTexture = fluid.FluidAssets.getImage("assets/bunny.png");
	this._showStats();
	this.touchBegin = function(evt) {
		_g._addBunnies = true;
	};
	this.mouseDown = function(evt1) {
		_g._addBunnies = true;
	};
	this.mouseUp = function(evt2) {
		_g._addBunnies = false;
	};
	this.touchEnd = this.touchOut = function(evt3) {
		_g._addBunnies = false;
	};
};
com.arm.demo.Main.main = function() {
	new com.arm.demo.Main();
};
com.arm.demo.Main.__super__ = fluid.Fluid;
com.arm.demo.Main.prototype = $extend(fluid.Fluid.prototype,{
	_addBunnys: function(count) {
		this._count += count;
		this._countText.setText("BUNNIES: " + this._count);
		var _g = 0;
		while(_g < count) {
			var i = _g++;
			var bunny = new com.arm.demo.Bunny(this._bunnyTexture);
			this.container.addChild(bunny);
			bunny.x = Std.random(fluid.StageProperties.screenWidth | 0);
			bunny.y = Std.random(fluid.StageProperties.screenHeight | 0);
			bunny.speedX = Math.random() * 16 + 2;
			bunny.speedY = Math.random() * 16 - 10;
			bunny.rotationSpeed = Math.random() / 50 + 0.01;
			bunny.scaleSpeed = Math.random() / 50 + 0.01;
			this._sprites.push(bunny);
		}
	}
	,_update: function(elapsedTime) {
		if(this._addBunnies) this._addBunnys(10);
		if(this._sprites.length > 0) {
			var _g1 = 0;
			var _g = this._sprites.length;
			while(_g1 < _g) {
				var i = _g1++;
				var bunny = this._sprites[i];
				bunny.x += bunny.speedX;
				bunny.y += bunny.speedY;
				bunny.speedY += 4.75;
				if(bunny.x > this._maxX) {
					bunny.speedX *= -1;
					bunny.x = this._maxX;
				} else if(bunny.x < this._minX) {
					bunny.speedX *= -1;
					bunny.x = this._minX;
				}
				if(bunny.y > this._maxY) {
					bunny.speedY *= -0.90;
					bunny.y = this._maxY;
					if(Math.random() > 0.5) bunny.speedY -= Math.random() * 6;
				} else if(bunny.y < this._minY) {
					bunny.speedY = 0;
					bunny.y = this._minY;
				}
			}
		}
	}
	,_resize: function() {
		this._maxX = fluid.StageProperties.screenWidth;
		this._maxY = fluid.StageProperties.screenHeight;
	}
});
fluid.FluidAssets = function() { };
fluid.FluidAssets.getImage = function(url) {
	return PIXI.Texture.fromImage(url);
};
fluid.StageProperties = function() { };
fluid.text = {};
fluid.text.FluidText = function(txt) {
	PIXI.Text.call(this,txt);
};
fluid.text.FluidText.__super__ = PIXI.Text;
fluid.text.FluidText.prototype = $extend(PIXI.Text.prototype,{
	setText: function(value) {
		PIXI.Text.prototype.setText.call(this,value);
	}
});
var pixi = {};
pixi.text = {};
pixi.text.TextStyle = function() { };
pixi.utils = {};
pixi.utils.RenderingOptions = function(view,resolution,transparent) {
	this.resolution = 1;
	this.transparent = false;
	if(view != null) this.view = view;
	if(resolution != null) this.resolution = resolution;
	if(transparent != null) this.transparent = transparent;
};
var $_, $fid = 0;
function $bind(o,m) { if( m == null ) return null; if( m.__id__ == null ) m.__id__ = $fid++; var f; if( o.hx__closures__ == null ) o.hx__closures__ = {}; else f = o.hx__closures__[m.__id__]; if( f == null ) { f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; o.hx__closures__[m.__id__] = f; } return f; }
Math.NaN = Number.NaN;
Math.NEGATIVE_INFINITY = Number.NEGATIVE_INFINITY;
Math.POSITIVE_INFINITY = Number.POSITIVE_INFINITY;
Math.isFinite = function(i) {
	return isFinite(i);
};
Math.isNaN = function(i1) {
	return isNaN(i1);
};
fluid.StageProperties.pixelRatio = 1;
fluid.StageProperties.screenWidth = 800;
fluid.StageProperties.screenHeight = 600;
com.arm.demo.Main.main();
})();

//# sourceMappingURL=fluid.dev.js.map
},{}]},{},[1]);
