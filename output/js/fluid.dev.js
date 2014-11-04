(function () { "use strict";
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
Math.__name__ = true;
var Reflect = function() { };
Reflect.__name__ = true;
Reflect.isFunction = function(f) {
	return typeof(f) == "function" && !(f.__name__ || f.__ename__);
};
Reflect.compareMethods = function(f1,f2) {
	if(f1 == f2) return true;
	if(!Reflect.isFunction(f1) || !Reflect.isFunction(f2)) return false;
	return f1.scope == f2.scope && f1.method == f2.method && f1.method != null;
};
var Std = function() { };
Std.__name__ = true;
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
};
var arm = {};
arm.mvc = {};
arm.mvc.comms = {};
arm.mvc.comms.CommsController = function() {
};
arm.mvc.comms.CommsController.__name__ = true;
arm.mvc.comms.CommsController.prototype = {
	__class__: arm.mvc.comms.CommsController
};
arm.mvc.controller = {};
arm.mvc.controller.IController = function() { };
arm.mvc.controller.IController.__name__ = true;
arm.mvc.controller.Controller = function(m,v,c) {
	this.model = m;
	this.view = v;
	this.comms = c;
	this._addNotificationListeners();
	this._addViewListeners();
	this._setupComponents();
};
arm.mvc.controller.Controller.__name__ = true;
arm.mvc.controller.Controller.__interfaces__ = [arm.mvc.controller.IController];
arm.mvc.controller.Controller.prototype = {
	_addNotificationListeners: function() {
	}
	,_addViewListeners: function() {
	}
	,_setupComponents: function() {
	}
	,__class__: arm.mvc.controller.Controller
};
arm.mvc.model = {};
arm.mvc.model.IModel = function() { };
arm.mvc.model.IModel.__name__ = true;
arm.mvc.model.Model = function() {
	this.reset();
};
arm.mvc.model.Model.__name__ = true;
arm.mvc.model.Model.__interfaces__ = [arm.mvc.model.IModel];
arm.mvc.model.Model.prototype = {
	reset: function() {
	}
	,__class__: arm.mvc.model.Model
};
arm.mvc.view = {};
arm.mvc.view.IView = function() { };
arm.mvc.view.IView.__name__ = true;
arm.mvc.view.View = function(stage,container) {
	this.set_stage(stage);
	this.set_container(container);
};
arm.mvc.view.View.__name__ = true;
arm.mvc.view.View.__interfaces__ = [arm.mvc.view.IView];
arm.mvc.view.View.prototype = {
	set_stage: function(stage) {
		return this.stage = stage;
	}
	,set_container: function(container) {
		return this.container = container;
	}
	,__class__: arm.mvc.view.View
};
var fluid = {};
fluid.Fluid = function() {
	this.backgroundColor = 16777215;
	this.stats = false;
	this.skipFrame = false;
	this._fluidFrameSkip = false;
	this._lastTime = new Date();
	this._setStageProperties();
	var _this = window.document;
	this._canvas = _this.createElement("canvas");
	this._canvas.style.width = fluid.StageProperties.screenWidth + "px";
	this._canvas.style.height = fluid.StageProperties.screenHeight + "px";
	window.document.body.appendChild(this._canvas);
	this.stage = new PIXI.Stage(this.backgroundColor);
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
fluid.Fluid.__name__ = true;
fluid.Fluid.prototype = {
	_setStageProperties: function() {
		fluid.StageProperties.pixelRatio = window.devicePixelRatio;
		fluid.StageProperties.screenWidth = window.innerWidth;
		fluid.StageProperties.screenHeight = window.innerHeight;
		if(fluid.StageProperties.screenWidth > fluid.StageProperties.screenHeight) fluid.StageProperties.orientation = "LANDSCAPE"; else fluid.StageProperties.orientation = "PORTRAIT";
	}
	,set_backgroundColor: function(clr) {
		this.stage.setBackgroundColor(clr);
		return this.backgroundColor = clr;
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
		if(this.mouseClick != null) this.mouseClick(evt);
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
			if(this.update != null) this.update(this._elapsedTime);
			this._renderer.render(this.stage);
		}
		window.requestAnimationFrame($bind(this,this._fluidOnUpdate));
		if(this._stats != null) this._stats.update();
	}
	,_fluidCalculateElapsedTime: function() {
		this._currentTime = new Date();
		this._elapsedTime = this._currentTime.getTime() - this._lastTime.getTime();
		this._lastTime = this._currentTime;
	}
	,_fluidOnResize: function(event) {
		this._setStageProperties();
		if(this.resize != null) this.resize();
	}
	,set_stats: function(val) {
		if(val) {
			var _container = window.document.createElement("div");
			window.document.body.appendChild(_container);
			this._stats = new Stats();
			this._stats.domElement.style.position = "absolute";
			this._stats.domElement.style.top = "2px";
			this._stats.domElement.style.right = "2px";
			_container.appendChild(this._stats.domElement);
			this._stats.begin();
		}
		return this.stats = val;
	}
	,__class__: fluid.Fluid
};
var com = {};
com.arm = {};
com.arm.demo = {};
com.arm.demo.Application = function() {
	fluid.Fluid.call(this);
};
com.arm.demo.Application.__name__ = true;
com.arm.demo.Application.__super__ = fluid.Fluid;
com.arm.demo.Application.prototype = $extend(fluid.Fluid.prototype,{
	__class__: com.arm.demo.Application
});
fluid.display = {};
fluid.display.FluidSprite = function(texture) {
	PIXI.DisplayObjectContainer.call(this);
	if(texture != null) {
		this._texture = new PIXI.Sprite(texture);
		this.addChild(this._texture);
	}
};
fluid.display.FluidSprite.__name__ = true;
fluid.display.FluidSprite.__super__ = PIXI.DisplayObjectContainer;
fluid.display.FluidSprite.prototype = $extend(PIXI.DisplayObjectContainer.prototype,{
	__class__: fluid.display.FluidSprite
});
com.arm.demo.Bunny = function() { };
com.arm.demo.Bunny.__name__ = true;
com.arm.demo.Bunny.__super__ = fluid.display.FluidSprite;
com.arm.demo.Bunny.prototype = $extend(fluid.display.FluidSprite.prototype,{
	__class__: com.arm.demo.Bunny
});
com.arm.demo.Main = function() {
	com.arm.demo.Application.call(this);
	this.set_stats(true);
	this.set_backgroundColor(16776960);
	this.skipFrame = true;
	this.resize = $bind(this,this._onRresize);
	this._setupMVCS();
	this._minX = this._minY = 0;
	this._maxX = fluid.StageProperties.screenWidth;
	this._maxY = fluid.StageProperties.screenHeight;
	this._sprites = [];
	var _background = new fluid.display.FluidGraphics();
	_background.clear();
	_background.beginFill(13158);
	_background.drawRoundedRect(100,100,200,100,10);
	_background.endFill();
	this.container.addChild(_background);
	var btn = new com.arm.demo.widgets.Button("BUTTON",150,30);
	btn.enable();
	this.container.addChild(btn);
};
com.arm.demo.Main.__name__ = true;
com.arm.demo.Main.main = function() {
	new com.arm.demo.Main();
};
com.arm.demo.Main.__super__ = com.arm.demo.Application;
com.arm.demo.Main.prototype = $extend(com.arm.demo.Application.prototype,{
	_setupMVCS: function() {
		this.view = new com.arm.demo.view.DemoView(this.stage,this.container);
		this.comms = new com.arm.demo.comms.DemoCommsController();
		this.model = new com.arm.demo.model.DemoModel();
		this.controller = new com.arm.demo.controller.DemoController(this.model,this.view,this.comms);
	}
	,_onRresize: function() {
		this._maxX = fluid.StageProperties.screenWidth;
		this._maxY = fluid.StageProperties.screenHeight;
	}
	,__class__: com.arm.demo.Main
});
com.arm.demo.comms = {};
com.arm.demo.comms.DemoCommsController = function() {
	arm.mvc.comms.CommsController.call(this);
};
com.arm.demo.comms.DemoCommsController.__name__ = true;
com.arm.demo.comms.DemoCommsController.__super__ = arm.mvc.comms.CommsController;
com.arm.demo.comms.DemoCommsController.prototype = $extend(arm.mvc.comms.CommsController.prototype,{
	__class__: com.arm.demo.comms.DemoCommsController
});
com.arm.demo.controller = {};
com.arm.demo.controller.DemoController = function(m,v,c) {
	this._view = js.Boot.__cast(v , com.arm.demo.view.DemoView);
	arm.mvc.controller.Controller.call(this,m,v,c);
};
com.arm.demo.controller.DemoController.__name__ = true;
com.arm.demo.controller.DemoController.__super__ = arm.mvc.controller.Controller;
com.arm.demo.controller.DemoController.prototype = $extend(arm.mvc.controller.Controller.prototype,{
	_setupComponents: function() {
	}
	,__class__: com.arm.demo.controller.DemoController
});
com.arm.demo.model = {};
com.arm.demo.model.DemoModel = function() {
	arm.mvc.model.Model.call(this);
};
com.arm.demo.model.DemoModel.__name__ = true;
com.arm.demo.model.DemoModel.__super__ = arm.mvc.model.Model;
com.arm.demo.model.DemoModel.prototype = $extend(arm.mvc.model.Model.prototype,{
	__class__: com.arm.demo.model.DemoModel
});
com.arm.demo.view = {};
com.arm.demo.view.DemoView = function(stage,container) {
	arm.mvc.view.View.call(this,stage,container);
};
com.arm.demo.view.DemoView.__name__ = true;
com.arm.demo.view.DemoView.__super__ = arm.mvc.view.View;
com.arm.demo.view.DemoView.prototype = $extend(arm.mvc.view.View.prototype,{
	__class__: com.arm.demo.view.DemoView
});
com.arm.demo.widgets = {};
com.arm.demo.widgets.Button = function(label,width,height,data,fontSize) {
	fluid.display.FluidSprite.call(this);
	this.action = new msignal.Signal1(Dynamic);
	this._data = data;
	this._setupBackground(width,height);
	this._setupLabel(width,height,fontSize);
	this.setText(label);
};
com.arm.demo.widgets.Button.__name__ = true;
com.arm.demo.widgets.Button.__super__ = fluid.display.FluidSprite;
com.arm.demo.widgets.Button.prototype = $extend(fluid.display.FluidSprite.prototype,{
	_setupBackground: function(width,height) {
		this._rect = new fluid.geom.FluidRectangle(0,0,width,height);
		this._background = new fluid.display.FluidGraphics();
		this._redraw(2187531);
		this.addChild(this._background);
		this._background.interactive = true;
		this._background.mouseOver = $bind(this,this._onMouseOver);
		this._background.mouseOut = $bind(this,this._onMouseOut);
		this._background.mouseDown = $bind(this,this._onMouseDown);
		this._background.mouseUp = $bind(this,this._onMouseUp);
		this._background.touchBegin = $bind(this,this._onTouchStart);
		this._background.touchEnd = $bind(this,this._onTouchEnd);
		this._background.touchOut = $bind(this,this._onTouchEndOutside);
	}
	,_setupLabel: function(width,height,fontSize) {
		if(fontSize == null) fontSize = 16;
		var format = new fluid.text.FluidTextFormat();
		format.size = fontSize;
		format.font = "Arial";
		format.fill = "#FFFFFF";
		this._label = new fluid.text.FluidText("",format);
		this._label.setAnchor(0.5,0.5);
		this._label.interactive = false;
		this._label.x = width / 2;
		this._label.y = height / 2;
		this.addChild(this._label);
	}
	,_redraw: function(colour) {
		var border = 1;
		this._background.clear();
		this._background.beginFill(colour);
		this._background.drawRect(this._rect.x,this._rect.y,this._rect.width,this._rect.height);
		this._background.endFill();
		this._background.beginFill(colour);
		this._background.drawRect(this._rect.x + border / 2,this._rect.y + border / 2,this._rect.width - border,this._rect.height - border);
		this._background.endFill();
	}
	,setText: function(label) {
		this._label.setText(label);
	}
	,_onMouseDown: function(data) {
		if(this._enabled) this._redraw(13158);
	}
	,_onMouseUp: function(data) {
		if(this._enabled) {
			this.action.dispatch(this._data);
			this._redraw(2187531);
		}
	}
	,_onMouseOver: function(data) {
		if(this._enabled) this._redraw(13158);
	}
	,_onMouseOut: function(data) {
		if(this._enabled) this._redraw(2187531);
	}
	,_onTouchEndOutside: function(data) {
		if(this._enabled) this._redraw(2187531);
	}
	,_onTouchEnd: function(data) {
		if(this._enabled) {
			this._redraw(2187531);
			this.action.dispatch(this._data);
		}
	}
	,_onTouchStart: function(data) {
		if(this._enabled) this._redraw(13158);
	}
	,enable: function() {
		this._enabled = true;
	}
	,__class__: com.arm.demo.widgets.Button
});
fluid.StageProperties = function() { };
fluid.StageProperties.__name__ = true;
fluid.display.FluidGraphics = function() {
	PIXI.Graphics.call(this);
	this.mousedown = $bind(this,this._fluidOnMouseDown);
	this.mouseout = $bind(this,this._fluidOnMouseOut);
	this.mouseover = $bind(this,this._fluidOnMouseOver);
	this.mouseup = $bind(this,this._fluidOnMouseUp);
	this.click = $bind(this,this._fluidOnMouseClick);
	this.rightclick = $bind(this,this._fluidOnRightClick);
	this.rightdown = $bind(this,this._fluidOnRightMouseDown);
	this.rightup = $bind(this,this._fluidOnRightMouseUp);
	this.touchstart = $bind(this,this._fluidOnTouchBegin);
	this.touchend = $bind(this,this._fluidOnTouchEnd);
	this.touchendoutside = $bind(this,this._fluidOnTouchOut);
};
fluid.display.FluidGraphics.__name__ = true;
fluid.display.FluidGraphics.__super__ = PIXI.Graphics;
fluid.display.FluidGraphics.prototype = $extend(PIXI.Graphics.prototype,{
	_fluidOnMouseDown: function(evt) {
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
		if(this.mouseClick != null) this.mouseClick(evt);
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
	,clear: function() {
		return PIXI.Graphics.prototype.clear.call(this);
	}
	,beginFill: function(fill,alpha) {
		if(alpha == null) alpha = 1;
		return PIXI.Graphics.prototype.beginFill.call(this,fill);
	}
	,endFill: function() {
		return PIXI.Graphics.prototype.endFill.call(this);
	}
	,drawRect: function(x,y,w,h) {
		return PIXI.Graphics.prototype.drawRect.call(this,x,y,w,h);
	}
	,drawRoundedRect: function(x,y,w,h,r) {
		return PIXI.Graphics.prototype.drawRoundedRect.call(this,x,y,w,h,r);
	}
	,__class__: fluid.display.FluidGraphics
});
fluid.geom = {};
fluid.geom.FluidRectangle = function(x,y,width,height) {
	PIXI.Rectangle.call(this,x,y,width,height);
};
fluid.geom.FluidRectangle.__name__ = true;
fluid.geom.FluidRectangle.__super__ = PIXI.Rectangle;
fluid.geom.FluidRectangle.prototype = $extend(PIXI.Rectangle.prototype,{
	__class__: fluid.geom.FluidRectangle
});
fluid.text = {};
fluid.text.FluidText = function(txt,format) {
	PIXI.Text.call(this,txt);
	if(format != null) this.setFormat(format);
};
fluid.text.FluidText.__name__ = true;
fluid.text.FluidText.__super__ = PIXI.Text;
fluid.text.FluidText.prototype = $extend(PIXI.Text.prototype,{
	setText: function(value) {
		PIXI.Text.prototype.setText.call(this,value);
	}
	,setFormat: function(format) {
		var tf = new pixi.text.TextStyle();
		var fullFont = "";
		if(format.bold) fullFont += "bold ";
		if(format.italic) fullFont += "italic ";
		if(format.underline) fullFont += "underline ";
		tf.fill = format.fill;
		tf.align = format.align;
		tf.font = fullFont + format.size + "px " + format.font;
		PIXI.Text.prototype.setStyle.call(this,tf);
	}
	,setAnchor: function(ax,ay) {
		if(ay == null) ay = 0.5;
		if(ax == null) ax = 0.5;
		this.anchor.set(ax,ay);
	}
	,__class__: fluid.text.FluidText
});
fluid.text.FluidTextFormat = function(font,size,fill,bold,italic,underline,align) {
	this.align = "left";
	this.fill = "#000000";
	this.font = "Arial";
	this.size = 20;
	this.underline = false;
	this.italic = false;
	this.bold = false;
	if(font != null) this.font = font;
	if(size != null) this.size = size;
	if(fill != null) this.fill = fill;
	if(bold != null) this.bold = bold;
	if(italic != null) this.italic = italic;
	if(underline != null) this.underline = underline;
	if(align != null) this.align = align;
};
fluid.text.FluidTextFormat.__name__ = true;
fluid.text.FluidTextFormat.prototype = {
	__class__: fluid.text.FluidTextFormat
};
var js = {};
js.Boot = function() { };
js.Boot.__name__ = true;
js.Boot.getClass = function(o) {
	if((o instanceof Array) && o.__enum__ == null) return Array; else return o.__class__;
};
js.Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ || o.__ename__)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__) {
				if(o.length == 2) return o[0];
				var str = o[0] + "(";
				s += "\t";
				var _g1 = 2;
				var _g = o.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(i != 2) str += "," + js.Boot.__string_rec(o[i],s); else str += js.Boot.__string_rec(o[i],s);
				}
				return str + ")";
			}
			var l = o.length;
			var i1;
			var str1 = "[";
			s += "\t";
			var _g2 = 0;
			while(_g2 < l) {
				var i2 = _g2++;
				str1 += (i2 > 0?",":"") + js.Boot.__string_rec(o[i2],s);
			}
			str1 += "]";
			return str1;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			return "???";
		}
		if(tostr != null && tostr != Object.toString) {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str2 = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) {
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str2.length != 2) str2 += ", \n";
		str2 += s + k + " : " + js.Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str2 += "\n" + s + "}";
		return str2;
	case "function":
		return "<function>";
	case "string":
		return o;
	default:
		return String(o);
	}
};
js.Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0;
		var _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js.Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js.Boot.__interfLoop(cc.__super__,cl);
};
js.Boot.__instanceof = function(o,cl) {
	if(cl == null) return false;
	switch(cl) {
	case Int:
		return (o|0) === o;
	case Float:
		return typeof(o) == "number";
	case Bool:
		return typeof(o) == "boolean";
	case String:
		return typeof(o) == "string";
	case Array:
		return (o instanceof Array) && o.__enum__ == null;
	case Dynamic:
		return true;
	default:
		if(o != null) {
			if(typeof(cl) == "function") {
				if(o instanceof cl) return true;
				if(js.Boot.__interfLoop(js.Boot.getClass(o),cl)) return true;
			}
		} else return false;
		if(cl == Class && o.__name__ != null) return true;
		if(cl == Enum && o.__ename__ != null) return true;
		return o.__enum__ == cl;
	}
};
js.Boot.__cast = function(o,t) {
	if(js.Boot.__instanceof(o,t)) return o; else throw "Cannot cast " + Std.string(o) + " to " + Std.string(t);
};
var msignal = {};
msignal.Signal = function(valueClasses) {
	if(valueClasses == null) valueClasses = [];
	this.valueClasses = valueClasses;
	this.slots = msignal.SlotList.NIL;
	this.priorityBased = false;
};
msignal.Signal.__name__ = true;
msignal.Signal.prototype = {
	remove: function(listener) {
		var slot = this.slots.find(listener);
		if(slot == null) return null;
		this.slots = this.slots.filterNot(listener);
		return slot;
	}
	,__class__: msignal.Signal
};
msignal.Signal1 = function(type) {
	msignal.Signal.call(this,[type]);
};
msignal.Signal1.__name__ = true;
msignal.Signal1.__super__ = msignal.Signal;
msignal.Signal1.prototype = $extend(msignal.Signal.prototype,{
	dispatch: function(value) {
		var slotsToProcess = this.slots;
		while(slotsToProcess.nonEmpty) {
			slotsToProcess.head.execute(value);
			slotsToProcess = slotsToProcess.tail;
		}
	}
	,__class__: msignal.Signal1
});
msignal.Slot = function() { };
msignal.Slot.__name__ = true;
msignal.Slot.prototype = {
	remove: function() {
		this.signal.remove(this.listener);
	}
	,__class__: msignal.Slot
};
msignal.Slot1 = function() { };
msignal.Slot1.__name__ = true;
msignal.Slot1.__super__ = msignal.Slot;
msignal.Slot1.prototype = $extend(msignal.Slot.prototype,{
	execute: function(value1) {
		if(!this.enabled) return;
		if(this.once) this.remove();
		if(this.param != null) value1 = this.param;
		this.listener(value1);
	}
	,__class__: msignal.Slot1
});
msignal.SlotList = function(head,tail) {
	this.nonEmpty = false;
	if(head == null && tail == null) {
		if(msignal.SlotList.NIL != null) throw "Parameters head and tail are null. Use the NIL element instead.";
		this.nonEmpty = false;
	} else if(head == null) throw "Parameter head cannot be null."; else {
		this.head = head;
		if(tail == null) this.tail = msignal.SlotList.NIL; else this.tail = tail;
		this.nonEmpty = true;
	}
};
msignal.SlotList.__name__ = true;
msignal.SlotList.prototype = {
	filterNot: function(listener) {
		if(!this.nonEmpty || listener == null) return this;
		if(Reflect.compareMethods(this.head.listener,listener)) return this.tail;
		var wholeClone = new msignal.SlotList(this.head);
		var subClone = wholeClone;
		var current = this.tail;
		while(current.nonEmpty) {
			if(Reflect.compareMethods(current.head.listener,listener)) {
				subClone.tail = current.tail;
				return wholeClone;
			}
			subClone = subClone.tail = new msignal.SlotList(current.head);
			current = current.tail;
		}
		return this;
	}
	,find: function(listener) {
		if(!this.nonEmpty) return null;
		var p = this;
		while(p.nonEmpty) {
			if(Reflect.compareMethods(p.head.listener,listener)) return p.head;
			p = p.tail;
		}
		return null;
	}
	,__class__: msignal.SlotList
};
var pixi = {};
pixi.text = {};
pixi.text.TextStyle = function(font,fill,align,stroke,strokeThickness,wordWrap,wordWrapWidth,dropShadow,dropShadowColor,dropShadowAngle,dropShadowDistance) {
	this.dropShadowDistance = 5;
	this.dropShadowAngle = Math.PI / 4;
	this.dropShadowColor = "#000000";
	this.dropShadow = false;
	this.wordWrapWidth = 100;
	this.wordWrap = false;
	this.strokeThickness = 0;
	this.align = "left";
	this.fill = "#000000";
	this.font = "bold 20px Arial";
	if(font != null) this.font = font;
	if(fill != null) this.fill = fill;
	if(align != null) this.align = align;
	if(stroke != null) this.stroke = stroke;
	if(strokeThickness != null) this.strokeThickness = strokeThickness;
	if(wordWrap != null) this.wordWrap = wordWrap;
	if(wordWrapWidth != null) this.wordWrapWidth = wordWrapWidth;
	if(dropShadow != null) this.dropShadow = dropShadow;
	if(dropShadowColor != null) this.dropShadowColor = dropShadowColor;
	if(dropShadowAngle != null) this.dropShadowAngle = dropShadowAngle;
	if(dropShadowDistance != null) this.dropShadowDistance = dropShadowDistance;
};
pixi.text.TextStyle.__name__ = true;
pixi.text.TextStyle.prototype = {
	__class__: pixi.text.TextStyle
};
pixi.utils = {};
pixi.utils.RenderingOptions = function(view,resolution,transparent) {
	this.resolution = 1;
	this.transparent = false;
	if(view != null) this.view = view;
	if(resolution != null) this.resolution = resolution;
	if(transparent != null) this.transparent = transparent;
};
pixi.utils.RenderingOptions.__name__ = true;
pixi.utils.RenderingOptions.prototype = {
	__class__: pixi.utils.RenderingOptions
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
String.prototype.__class__ = String;
String.__name__ = true;
Array.__name__ = true;
Date.prototype.__class__ = Date;
Date.__name__ = ["Date"];
var Int = { __name__ : ["Int"]};
var Dynamic = { __name__ : ["Dynamic"]};
var Float = Number;
Float.__name__ = ["Float"];
var Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = { __name__ : ["Class"]};
var Enum = { };
msignal.SlotList.NIL = new msignal.SlotList(null,null);
fluid.StageProperties.pixelRatio = 1;
fluid.StageProperties.screenWidth = 800;
fluid.StageProperties.screenHeight = 600;
com.arm.demo.Main.main();
})();

//# sourceMappingURL=fluid.dev.js.map