(function () { "use strict";
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
var HxOverrides = function() { };
HxOverrides.__name__ = true;
HxOverrides.indexOf = function(a,obj,i) {
	var len = a.length;
	if(i < 0) {
		i += len;
		if(i < 0) i = 0;
	}
	while(i < len) {
		if(a[i] === obj) return i;
		i++;
	}
	return -1;
};
HxOverrides.remove = function(a,obj) {
	var i = HxOverrides.indexOf(a,obj,0);
	if(i == -1) return false;
	a.splice(i,1);
	return true;
};
var IMap = function() { };
IMap.__name__ = true;
Math.__name__ = true;
var Reflect = function() { };
Reflect.__name__ = true;
Reflect.field = function(o,field) {
	try {
		return o[field];
	} catch( e ) {
		return null;
	}
};
Reflect.setField = function(o,field,value) {
	o[field] = value;
};
Reflect.getProperty = function(o,field) {
	var tmp;
	if(o == null) return null; else if(o.__properties__ && (tmp = o.__properties__["get_" + field])) return o[tmp](); else return o[field];
};
Reflect.setProperty = function(o,field,value) {
	var tmp;
	if(o.__properties__ && (tmp = o.__properties__["set_" + field])) o[tmp](value); else o[field] = value;
};
Reflect.fields = function(o) {
	var a = [];
	if(o != null) {
		var hasOwnProperty = Object.prototype.hasOwnProperty;
		for( var f in o ) {
		if(f != "__id__" && f != "hx__closures__" && hasOwnProperty.call(o,f)) a.push(f);
		}
	}
	return a;
};
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
var Type = function() { };
Type.__name__ = true;
Type.createInstance = function(cl,args) {
	var _g = args.length;
	switch(_g) {
	case 0:
		return new cl();
	case 1:
		return new cl(args[0]);
	case 2:
		return new cl(args[0],args[1]);
	case 3:
		return new cl(args[0],args[1],args[2]);
	case 4:
		return new cl(args[0],args[1],args[2],args[3]);
	case 5:
		return new cl(args[0],args[1],args[2],args[3],args[4]);
	case 6:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5]);
	case 7:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
	case 8:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6],args[7]);
	default:
		throw "Too many arguments";
	}
	return null;
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
	this._canvas.style.width = fluid.display.FluidStage.screenWidth + "px";
	this._canvas.style.height = fluid.display.FluidStage.screenHeight + "px";
	window.document.body.appendChild(this._canvas);
	this._fluidStage = new fluid.display.FluidStage(this.backgroundColor);
	this.container = new fluid.display.FluidSprite();
	this._fluidStage.addChild(this.container);
	this._fluidStage.mousedown = $bind(this,this._fluidOnMouseDown);
	this._fluidStage.mouseout = $bind(this,this._fluidOnMouseOut);
	this._fluidStage.mouseover = $bind(this,this._fluidOnMouseOver);
	this._fluidStage.mouseup = $bind(this,this._fluidOnMouseUp);
	this._fluidStage.click = $bind(this,this._fluidOnMouseClick);
	this._fluidStage.rightclick = $bind(this,this._fluidOnRightClick);
	this._fluidStage.rightdown = $bind(this,this._fluidOnRightMouseDown);
	this._fluidStage.rightup = $bind(this,this._fluidOnRightMouseUp);
	this._fluidStage.touchstart = $bind(this,this._fluidOnTouchBegin);
	this._fluidStage.touchend = $bind(this,this._fluidOnTouchEnd);
	this._fluidStage.touchendoutside = $bind(this,this._fluidOnTouchOut);
	var renderingOptions = new pixi.utils.RenderingOptions();
	renderingOptions.view = this._canvas;
	renderingOptions.resolution = fluid.display.FluidStage.pixelRatio;
	this._renderer = PIXI.autoDetectRenderer(fluid.display.FluidStage.screenWidth,fluid.display.FluidStage.screenHeight,renderingOptions);
	window.document.body.appendChild(this._renderer.view);
	window.onresize = $bind(this,this._fluidOnResize);
	window.requestAnimationFrame($bind(this,this._fluidOnUpdate));
	this._lastTime = new Date();
};
fluid.Fluid.__name__ = true;
fluid.Fluid.prototype = {
	_setStageProperties: function() {
		fluid.display.FluidStage.pixelRatio = window.devicePixelRatio;
		fluid.display.FluidStage.screenWidth = window.innerWidth;
		fluid.display.FluidStage.screenHeight = window.innerHeight;
		if(fluid.display.FluidStage.screenWidth > fluid.display.FluidStage.screenHeight) fluid.display.FluidStage.orientation = "LANDSCAPE"; else fluid.display.FluidStage.orientation = "PORTRAIT";
	}
	,set_backgroundColor: function(clr) {
		this._fluidStage.setBackgroundColor(clr);
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
			this._renderer.render(this._fluidStage);
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
	,__properties__: {set_backgroundColor:"set_backgroundColor",set_stats:"set_stats"}
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
	this.mousedown = $bind(this,this._fluidOnMouseDown);
	this.mouseout = $bind(this,this._fluidOnMouseOut);
	this.mouseover = $bind(this,this._fluidOnMouseOver);
	this.mouseup = $bind(this,this._fluidOnMouseUp);
	this.mousemove = $bind(this,this._fluidOnMouseMove);
	this.click = $bind(this,this._fluidOnMouseClick);
	this.rightclick = $bind(this,this._fluidOnRightClick);
	this.rightdown = $bind(this,this._fluidOnRightMouseDown);
	this.rightup = $bind(this,this._fluidOnRightMouseUp);
	this.touchstart = $bind(this,this._fluidOnTouchBegin);
	this.touchend = $bind(this,this._fluidOnTouchEnd);
	this.touchendoutside = $bind(this,this._fluidOnTouchOut);
	this.touchmove = $bind(this,this._fluidOnTouchMove);
};
fluid.display.FluidSprite.__name__ = true;
fluid.display.FluidSprite.__super__ = PIXI.DisplayObjectContainer;
fluid.display.FluidSprite.prototype = $extend(PIXI.DisplayObjectContainer.prototype,{
	_fluidOnMouseDown: function(evt) {
		if(this.mouseDown != null) this.mouseDown(this._prepareEventData(evt));
	}
	,_fluidOnMouseOver: function(evt) {
		if(this.mouseOver != null) this.mouseOver(this._prepareEventData(evt));
	}
	,_fluidOnMouseOut: function(evt) {
		if(this.mouseOut != null) this.mouseOut(this._prepareEventData(evt));
	}
	,_fluidOnMouseUp: function(evt) {
		if(this.mouseUp != null) this.mouseUp(this._prepareEventData(evt));
	}
	,_fluidOnMouseMove: function(evt) {
		if(this.mouseMove != null) this.mouseMove(this._prepareEventData(evt));
	}
	,_fluidOnMouseClick: function(evt) {
		if(this.mouseClick != null) this.mouseClick(this._prepareEventData(evt));
	}
	,_fluidOnRightClick: function(evt) {
		if(this.rightClick != null) this.rightClick(this._prepareEventData(evt));
	}
	,_fluidOnRightMouseDown: function(evt) {
		if(this.rightMouseDown != null) this.rightMouseDown(this._prepareEventData(evt));
	}
	,_fluidOnRightMouseUp: function(evt) {
		if(this.rightMouseUp != null) this.rightMouseUp(this._prepareEventData(evt));
	}
	,_fluidOnTouchBegin: function(evt) {
		if(this.touchBegin != null) this.touchBegin(this._prepareEventData(evt));
	}
	,_fluidOnTouchEnd: function(evt) {
		if(this.touchEnd != null) this.touchEnd(this._prepareEventData(evt));
	}
	,_fluidOnTouchOut: function(evt) {
		if(this.touchOut != null) this.touchOut(this._prepareEventData(evt));
	}
	,_fluidOnTouchMove: function(evt) {
		if(this.touchMove != null) this.touchMove(this._prepareEventData(evt));
	}
	,_prepareEventData: function(data) {
		var evtData = new fluid.events.EventData();
		evtData.localX = data.getLocalPosition(this.parent).x;
		evtData.localY = data.getLocalPosition(this.parent).y;
		evtData.stageX = data.global.x;
		evtData.stageY = data.global.y;
		evtData.target = data.target;
		return evtData;
	}
	,__class__: fluid.display.FluidSprite
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
	this.set_backgroundColor(13421772);
	this.skipFrame = true;
	this.resize = $bind(this,this._onRresize);
	this._setupMVCS();
	this._minX = this._minY = 0;
	this._maxX = fluid.display.FluidStage.screenWidth;
	this._maxY = fluid.display.FluidStage.screenHeight;
	this._sprites = [];
};
com.arm.demo.Main.__name__ = true;
com.arm.demo.Main.main = function() {
	new com.arm.demo.Main();
};
com.arm.demo.Main.__super__ = com.arm.demo.Application;
com.arm.demo.Main.prototype = $extend(com.arm.demo.Application.prototype,{
	_setupMVCS: function() {
		this.view = new com.arm.demo.view.DemoView(this.container);
		this.comms = new com.arm.demo.comms.DemoCommsController();
		this.model = new com.arm.demo.model.DemoModel();
		this.controller = new com.arm.demo.controller.DemoController(this.model,this.view,this.comms);
		this.controller.setupComponents();
	}
	,_onRresize: function() {
		this._maxX = fluid.display.FluidStage.screenWidth;
		this._maxY = fluid.display.FluidStage.screenHeight;
	}
	,__class__: com.arm.demo.Main
});
com.arm.demo.comms = {};
com.arm.demo.comms.DemoCommsController = function() {
};
com.arm.demo.comms.DemoCommsController.__name__ = true;
com.arm.demo.comms.DemoCommsController.prototype = {
	__class__: com.arm.demo.comms.DemoCommsController
};
com.arm.demo.controller = {};
com.arm.demo.controller.DemoController = function(m,v,c) {
	this.model = m;
	this.view = v;
	this.comms = c;
	this._addNotificationListeners();
	this._addViewListeners();
};
com.arm.demo.controller.DemoController.__name__ = true;
com.arm.demo.controller.DemoController.prototype = {
	_addNotificationListeners: function() {
	}
	,_addViewListeners: function() {
	}
	,setupComponents: function() {
		this._setupMenuComponent();
	}
	,_setupMenuComponent: function() {
		var menuView = new com.arm.demo.components.menu.MenuView(this.view.get_container());
		var menuController = new com.arm.demo.components.menu.MenuController(null,menuView,this.comms,this.model);
	}
	,__class__: com.arm.demo.controller.DemoController
};
com.arm.demo.components = {};
com.arm.demo.components.GameComponentController = function(m,v,c,mm) {
	com.arm.demo.controller.DemoController.call(this,m,v,c);
	this.mainModel = mm;
};
com.arm.demo.components.GameComponentController.__name__ = true;
com.arm.demo.components.GameComponentController.__super__ = com.arm.demo.controller.DemoController;
com.arm.demo.components.GameComponentController.prototype = $extend(com.arm.demo.controller.DemoController.prototype,{
	_addNotificationListeners: function() {
		com.arm.demo.notifications.internal.ViewStateNotification.preload.addOnce($bind(this,this._preload));
		com.arm.demo.notifications.internal.ViewStateNotification.create.addOnce($bind(this,this._create));
		com.arm.demo.notifications.internal.ViewStateNotification.update.add($bind(this,this._update));
		com.arm.demo.notifications.internal.ViewStateNotification.resize.add($bind(this,this._resize));
	}
	,_preload: function() {
	}
	,_create: function() {
	}
	,_update: function(elapsedTime) {
	}
	,_resize: function() {
		this.mainModel = null;
		com.arm.demo.notifications.internal.ViewStateNotification.reset();
	}
	,__class__: com.arm.demo.components.GameComponentController
});
com.arm.demo.view = {};
com.arm.demo.view.DemoView = function(container) {
	this.set_container(container);
};
com.arm.demo.view.DemoView.__name__ = true;
com.arm.demo.view.DemoView.prototype = {
	get_container: function() {
		return this.container;
	}
	,set_container: function(container) {
		return this.container = container;
	}
	,__class__: com.arm.demo.view.DemoView
	,__properties__: {set_container:"set_container",get_container:"get_container"}
};
com.arm.demo.components.GameComponentView = function(container) {
	com.arm.demo.view.DemoView.call(this,container);
};
com.arm.demo.components.GameComponentView.__name__ = true;
com.arm.demo.components.GameComponentView.__super__ = com.arm.demo.view.DemoView;
com.arm.demo.components.GameComponentView.prototype = $extend(com.arm.demo.view.DemoView.prototype,{
	__class__: com.arm.demo.components.GameComponentView
});
com.arm.demo.components.menu = {};
com.arm.demo.components.menu.MenuController = function(m,v,c,mainModel) {
	com.arm.demo.components.GameComponentController.call(this,m,v,c,mainModel);
	this._view = js.Boot.__cast(v , com.arm.demo.components.menu.MenuView);
	this._view.create();
};
com.arm.demo.components.menu.MenuController.__name__ = true;
com.arm.demo.components.menu.MenuController.__super__ = com.arm.demo.components.GameComponentController;
com.arm.demo.components.menu.MenuController.prototype = $extend(com.arm.demo.components.GameComponentController.prototype,{
	_create: function() {
		this._view.create();
	}
	,__class__: com.arm.demo.components.menu.MenuController
});
com.arm.demo.components.menu.MenuView = function(container) {
	com.arm.demo.components.GameComponentView.call(this,container);
	this._menuItems = ["Screen Test","Screen Guide","Localisation","Sprites","Bunnys","Sprite Sheets","Coin Shower","Typekit","Audio","Currency Format","Server Request","Console Bridge","Reels","Skeleton Animation","Physics","Reset"];
};
com.arm.demo.components.menu.MenuView.__name__ = true;
com.arm.demo.components.menu.MenuView.__super__ = com.arm.demo.components.GameComponentView;
com.arm.demo.components.menu.MenuView.prototype = $extend(com.arm.demo.components.GameComponentView.prototype,{
	create: function() {
		this._menu = new com.arm.demo.widgets.menu.PopoutMenu(180,40);
		var _menuItem;
		var _g1 = 0;
		var _g = this._menuItems.length;
		while(_g1 < _g) {
			var i = _g1++;
			_menuItem = this._menu.addItem(this._menuItems[i],i);
			_menuItem.action.add($bind(this,this._menuClick));
		}
		this.get_container().addChild(this._menu);
		this._menu.y = fluid.display.FluidStage.pixelRatio;
	}
	,hide: function() {
		this._menu.hide();
	}
	,_menuClick: function(id) {
		if(this._currentItem != id && id < this._menuItems.length - 1) com.arm.demo.notifications.internal.MenuNotification.click.dispatch(id); else com.arm.demo.notifications.internal.MenuNotification.reset.dispatch();
		if(id != 15) this.hide();
	}
	,__class__: com.arm.demo.components.menu.MenuView
});
com.arm.demo.model = {};
com.arm.demo.model.DemoModel = function() {
};
com.arm.demo.model.DemoModel.__name__ = true;
com.arm.demo.model.DemoModel.prototype = {
	__class__: com.arm.demo.model.DemoModel
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
	add: function(listener) {
		return this.registerListener(listener);
	}
	,addOnce: function(listener) {
		return this.registerListener(listener,true);
	}
	,remove: function(listener) {
		var slot = this.slots.find(listener);
		if(slot == null) return null;
		this.slots = this.slots.filterNot(listener);
		return slot;
	}
	,removeAll: function() {
		this.slots = msignal.SlotList.NIL;
	}
	,registerListener: function(listener,once,priority) {
		if(priority == null) priority = 0;
		if(once == null) once = false;
		if(this.registrationPossible(listener,once)) {
			var newSlot = this.createSlot(listener,once,priority);
			if(!this.priorityBased && priority != 0) this.priorityBased = true;
			if(!this.priorityBased && priority == 0) this.slots = this.slots.prepend(newSlot); else this.slots = this.slots.insertWithPriority(newSlot);
			return newSlot;
		}
		return this.slots.find(listener);
	}
	,registrationPossible: function(listener,once) {
		if(!this.slots.nonEmpty) return true;
		var existingSlot = this.slots.find(listener);
		if(existingSlot == null) return true;
		if(existingSlot.once != once) throw "You cannot addOnce() then add() the same listener without removing the relationship first.";
		return false;
	}
	,createSlot: function(listener,once,priority) {
		if(priority == null) priority = 0;
		if(once == null) once = false;
		return null;
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
	,createSlot: function(listener,once,priority) {
		if(priority == null) priority = 0;
		if(once == null) once = false;
		return new msignal.Slot1(this,listener,once,priority);
	}
	,__class__: msignal.Signal1
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
	prepend: function(slot) {
		return new msignal.SlotList(slot,this);
	}
	,insertWithPriority: function(slot) {
		if(!this.nonEmpty) return new msignal.SlotList(slot);
		var priority = slot.priority;
		if(priority >= this.head.priority) return this.prepend(slot);
		var wholeClone = new msignal.SlotList(this.head);
		var subClone = wholeClone;
		var current = this.tail;
		while(current.nonEmpty) {
			if(priority > current.head.priority) {
				subClone.tail = current.prepend(slot);
				return wholeClone;
			}
			subClone = subClone.tail = new msignal.SlotList(current.head);
			current = current.tail;
		}
		subClone.tail = new msignal.SlotList(slot);
		return wholeClone;
	}
	,filterNot: function(listener) {
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
msignal.Signal0 = function() {
	msignal.Signal.call(this);
};
msignal.Signal0.__name__ = true;
msignal.Signal0.__super__ = msignal.Signal;
msignal.Signal0.prototype = $extend(msignal.Signal.prototype,{
	dispatch: function() {
		var slotsToProcess = this.slots;
		while(slotsToProcess.nonEmpty) {
			slotsToProcess.head.execute();
			slotsToProcess = slotsToProcess.tail;
		}
	}
	,createSlot: function(listener,once,priority) {
		if(priority == null) priority = 0;
		if(once == null) once = false;
		return new msignal.Slot0(this,listener,once,priority);
	}
	,__class__: msignal.Signal0
});
com.arm.demo.notifications = {};
com.arm.demo.notifications.internal = {};
com.arm.demo.notifications.internal.MenuNotification = function() { };
com.arm.demo.notifications.internal.MenuNotification.__name__ = true;
com.arm.demo.notifications.internal.ViewStateNotification = function() { };
com.arm.demo.notifications.internal.ViewStateNotification.__name__ = true;
com.arm.demo.notifications.internal.ViewStateNotification.reset = function() {
	com.arm.demo.notifications.internal.ViewStateNotification.preloader.removeAll();
	com.arm.demo.notifications.internal.ViewStateNotification.preloaderProgress.removeAll();
	com.arm.demo.notifications.internal.ViewStateNotification.preload.removeAll();
	com.arm.demo.notifications.internal.ViewStateNotification.create.removeAll();
	com.arm.demo.notifications.internal.ViewStateNotification.update.removeAll();
	com.arm.demo.notifications.internal.ViewStateNotification.destroy.removeAll();
	com.arm.demo.notifications.internal.ViewStateNotification.resize.removeAll();
};
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
	,disable: function() {
		this._redraw(2187531);
		this._enabled = false;
	}
	,__class__: com.arm.demo.widgets.Button
});
com.arm.demo.widgets.menu = {};
com.arm.demo.widgets.menu.Menu = function(itemWidth,itemHeight) {
	fluid.display.FluidSprite.call(this);
	this._itemWidth = itemWidth;
	this._itemHeight = itemHeight;
	this._menuItems = [];
	this.interactive = true;
};
com.arm.demo.widgets.menu.Menu.__name__ = true;
com.arm.demo.widgets.menu.Menu.__super__ = fluid.display.FluidSprite;
com.arm.demo.widgets.menu.Menu.prototype = $extend(fluid.display.FluidSprite.prototype,{
	addItem: function(label,data) {
		var menuItem = new com.arm.demo.widgets.menu.MenuItem(label,this._itemWidth,this._itemHeight,data);
		menuItem.y = this._itemHeight * this._menuItems.length;
		this.addChild(menuItem);
		this._menuItems.push(menuItem);
		this._height = this._itemHeight * this._menuItems.length;
		if(this._height > fluid.display.FluidStage.screenHeight) {
			this.touchBegin = $bind(this,this._onTouchStart);
			this.touchEnd = $bind(this,this._onTouchEnd);
			this.mouseDown = $bind(this,this._onMouseDown);
			this.mouseUp = $bind(this,this._onMouseUp);
		}
		return menuItem;
	}
	,_onTouchStart: function(data) {
		this._lastPosition = data.stageY;
		this.touchMove = $bind(this,this._onTouchMove);
	}
	,_onTouchMove: function(data) {
		var distance = this._lastPosition - data.stageY;
		if(this._dragging || (distance < -5 || distance > 5)) {
			this.disableMenuItems();
			this._move(this._lastPosition - data.stageY);
			this._dragging = true;
			this._lastPosition = data.stageY;
		}
	}
	,_onTouchEnd: function(data) {
		this.touchMove = null;
		this._dragging = false;
		haxe.Timer.delay($bind(this,this.enableMenuItems),100);
	}
	,_onMouseDown: function(data) {
		this._lastPosition = data.stageY;
		this.mouseMove = $bind(this,this._onMouseMove);
	}
	,_onMouseUp: function(data) {
		this.mouseMove = null;
		this._dragging = false;
		this.enableMenuItems();
	}
	,_onMouseMove: function(data) {
		var distance = this._lastPosition - data.stageY;
		if(this._dragging || (distance < -5 || distance > 5)) {
			this.disableMenuItems();
			this._move(this._lastPosition - data.stageY);
			this._dragging = true;
			this._lastPosition = data.stageY;
		}
	}
	,disableMenuItems: function() {
		var _g1 = 0;
		var _g = this._menuItems.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._menuItems[i].disable();
		}
	}
	,enableMenuItems: function() {
		var _g1 = 0;
		var _g = this._menuItems.length;
		while(_g1 < _g) {
			var i = _g1++;
			this._menuItems[i].enable();
		}
	}
	,_move: function(distance) {
		this.y -= distance;
		if(this.y > 0) this.y = 0; else if(this.y < -(this._height - fluid.display.FluidStage.screenHeight)) this.y = -(this._height - fluid.display.FluidStage.screenHeight);
		this.x = Math.round(this.x);
		this.y = Math.round(this.y);
	}
	,getItems: function() {
		return this._menuItems;
	}
	,__class__: com.arm.demo.widgets.menu.Menu
});
com.arm.demo.widgets.menu.MenuItem = function(label,width,height,data) {
	fluid.display.FluidSprite.call(this);
	this._button = new com.arm.demo.widgets.Button(label,width,height,data);
	this.action = this._button.action;
	this.addChild(this._button);
};
com.arm.demo.widgets.menu.MenuItem.__name__ = true;
com.arm.demo.widgets.menu.MenuItem.__super__ = fluid.display.FluidSprite;
com.arm.demo.widgets.menu.MenuItem.prototype = $extend(fluid.display.FluidSprite.prototype,{
	enable: function() {
		this._button.enable();
	}
	,disable: function() {
		this._button.disable();
	}
	,__class__: com.arm.demo.widgets.menu.MenuItem
});
com.arm.demo.widgets.menu.PopoutMenu = function(itemWidth,itemHeight) {
	fluid.display.FluidSprite.call(this);
	this._container = new fluid.display.FluidSprite();
	this._itemWidth = itemWidth;
	this._itemHeight = itemHeight;
	this._state = "STATE_HIDE";
	this._setupOpenButton();
	this._setupMenu(itemWidth,itemHeight);
	this.addChild(this._container);
};
com.arm.demo.widgets.menu.PopoutMenu.__name__ = true;
com.arm.demo.widgets.menu.PopoutMenu.__super__ = fluid.display.FluidSprite;
com.arm.demo.widgets.menu.PopoutMenu.prototype = $extend(fluid.display.FluidSprite.prototype,{
	_setupOpenButton: function() {
		var buttonRect = new fluid.geom.FluidRectangle(0,0,30,80);
		var hitRect = new fluid.geom.FluidRectangle(0,0,15,60);
		this._openButton = new fluid.display.FluidGraphics();
		this._openButton.beginFill(2187531);
		this._openButton.drawRect(buttonRect.x,buttonRect.y,buttonRect.width,buttonRect.height);
		this._openButton.endFill();
		this._openButton.interactive = true;
		this._openButton.touchBegin = $bind(this,this._toggleShow);
		this._openButton.touchEnd = $bind(this,this._toggleShow);
		this._openButton.mouseUp = $bind(this,this._toggleShow);
		this._container.addChild(this._openButton);
	}
	,_setupMenu: function(itemWidth,itemHeight) {
		this._menu = new com.arm.demo.widgets.menu.Menu(itemWidth,itemHeight);
		this._menu.x = -itemWidth;
		this._container.addChild(this._menu);
	}
	,_toggleShow: function(data) {
		if(this._state == "STATE_SHOW") this.hide(); else this.show();
	}
	,show: function() {
		this._state = "STATE_SHOW";
		motion.Actuate.tween(this._container,0.3,{ x : this._itemWidth}).ease(motion.easing.Cubic.get_easeInOut()).onComplete($bind(this,this._enableMenuItems));
	}
	,hide: function() {
		this._state = "STATE_HIDE";
		motion.Actuate.tween(this._container,0.3,{ x : 0}).ease(motion.easing.Cubic.get_easeInOut()).onComplete($bind(this,this._disableMenuItems));
	}
	,addItem: function(label,data) {
		var menuItem = this._menu.addItem(label,data);
		this._updateOpenButtonPosition();
		return menuItem;
	}
	,_enableMenuItems: function() {
		this._menu.enableMenuItems();
	}
	,_disableMenuItems: function() {
		this._menu.disableMenuItems();
	}
	,_updateOpenButtonPosition: function() {
		var openButtonPosition = Math.floor((this._menu.getItems().length - 1) / 2) * this._itemHeight;
		if(openButtonPosition > fluid.display.FluidStage.screenHeight / 2) openButtonPosition = fluid.display.FluidStage.screenHeight / 2;
		this._openButton.y = openButtonPosition;
	}
	,__class__: com.arm.demo.widgets.menu.PopoutMenu
});
fluid.display.FluidGraphics = function() {
	PIXI.Graphics.call(this);
	this.mousedown = $bind(this,this._fluidOnMouseDown);
	this.mouseout = $bind(this,this._fluidOnMouseOut);
	this.mouseover = $bind(this,this._fluidOnMouseOver);
	this.mouseup = $bind(this,this._fluidOnMouseUp);
	this.mousemove = $bind(this,this._fluidOnMouseMove);
	this.click = $bind(this,this._fluidOnMouseClick);
	this.rightclick = $bind(this,this._fluidOnRightClick);
	this.rightdown = $bind(this,this._fluidOnRightMouseDown);
	this.rightup = $bind(this,this._fluidOnRightMouseUp);
	this.touchstart = $bind(this,this._fluidOnTouchBegin);
	this.touchend = $bind(this,this._fluidOnTouchEnd);
	this.touchendoutside = $bind(this,this._fluidOnTouchOut);
	this.touchmove = $bind(this,this._fluidOnTouchMove);
};
fluid.display.FluidGraphics.__name__ = true;
fluid.display.FluidGraphics.__super__ = PIXI.Graphics;
fluid.display.FluidGraphics.prototype = $extend(PIXI.Graphics.prototype,{
	_fluidOnMouseDown: function(evt) {
		if(this.mouseDown != null) this.mouseDown(this._prepareEventData(evt));
	}
	,_fluidOnMouseOver: function(evt) {
		if(this.mouseOver != null) this.mouseOver(this._prepareEventData(evt));
	}
	,_fluidOnMouseOut: function(evt) {
		if(this.mouseOut != null) this.mouseOut(this._prepareEventData(evt));
	}
	,_fluidOnMouseUp: function(evt) {
		if(this.mouseUp != null) this.mouseUp(this._prepareEventData(evt));
	}
	,_fluidOnMouseMove: function(evt) {
		if(this.mouseMove != null) this.mouseMove(this._prepareEventData(evt));
	}
	,_fluidOnMouseClick: function(evt) {
		if(this.mouseClick != null) this.mouseClick(this._prepareEventData(evt));
	}
	,_fluidOnRightClick: function(evt) {
		if(this.rightClick != null) this.rightClick(this._prepareEventData(evt));
	}
	,_fluidOnRightMouseDown: function(evt) {
		if(this.rightMouseDown != null) this.rightMouseDown(this._prepareEventData(evt));
	}
	,_fluidOnRightMouseUp: function(evt) {
		if(this.rightMouseUp != null) this.rightMouseUp(this._prepareEventData(evt));
	}
	,_fluidOnTouchBegin: function(evt) {
		if(this.touchBegin != null) this.touchBegin(this._prepareEventData(evt));
	}
	,_fluidOnTouchEnd: function(evt) {
		if(this.touchEnd != null) this.touchEnd(this._prepareEventData(evt));
	}
	,_fluidOnTouchOut: function(evt) {
		if(this.touchOut != null) this.touchOut(this._prepareEventData(evt));
	}
	,_fluidOnTouchMove: function(evt) {
		if(this.touchMove != null) this.touchMove(this._prepareEventData(evt));
	}
	,_prepareEventData: function(data) {
		var evtData = new fluid.events.EventData();
		evtData.localX = data.getLocalPosition(this.parent).x;
		evtData.localY = data.getLocalPosition(this.parent).y;
		evtData.stageX = data.global.x;
		evtData.stageY = data.global.y;
		evtData.target = data.target;
		return evtData;
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
	,__class__: fluid.display.FluidGraphics
});
fluid.display.FluidStage = function(bgColor) {
	PIXI.Stage.call(this,bgColor);
};
fluid.display.FluidStage.__name__ = true;
fluid.display.FluidStage.__super__ = PIXI.Stage;
fluid.display.FluidStage.prototype = $extend(PIXI.Stage.prototype,{
	__class__: fluid.display.FluidStage
});
fluid.events = {};
fluid.events.EventData = function() {
};
fluid.events.EventData.__name__ = true;
fluid.events.EventData.prototype = {
	__class__: fluid.events.EventData
};
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
var haxe = {};
haxe.Timer = function(time_ms) {
	var me = this;
	this.id = setInterval(function() {
		me.run();
	},time_ms);
};
haxe.Timer.__name__ = true;
haxe.Timer.delay = function(f,time_ms) {
	var t = new haxe.Timer(time_ms);
	t.run = function() {
		t.stop();
		f();
	};
	return t;
};
haxe.Timer.stamp = function() {
	return new Date().getTime() / 1000;
};
haxe.Timer.prototype = {
	stop: function() {
		if(this.id == null) return;
		clearInterval(this.id);
		this.id = null;
	}
	,run: function() {
	}
	,__class__: haxe.Timer
};
haxe.ds = {};
haxe.ds.ObjectMap = function() {
	this.h = { };
	this.h.__keys__ = { };
};
haxe.ds.ObjectMap.__name__ = true;
haxe.ds.ObjectMap.__interfaces__ = [IMap];
haxe.ds.ObjectMap.prototype = {
	set: function(key,value) {
		var id = key.__id__ || (key.__id__ = ++haxe.ds.ObjectMap.count);
		this.h[id] = value;
		this.h.__keys__[id] = key;
	}
	,get: function(key) {
		return this.h[key.__id__];
	}
	,exists: function(key) {
		return this.h.__keys__[key.__id__] != null;
	}
	,remove: function(key) {
		var id = key.__id__;
		if(this.h.__keys__[id] == null) return false;
		delete(this.h[id]);
		delete(this.h.__keys__[id]);
		return true;
	}
	,__class__: haxe.ds.ObjectMap
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
var motion = {};
motion.actuators = {};
motion.actuators.IGenericActuator = function() { };
motion.actuators.IGenericActuator.__name__ = true;
motion.actuators.IGenericActuator.prototype = {
	__class__: motion.actuators.IGenericActuator
};
motion.actuators.GenericActuator = function(target,duration,properties) {
	this._autoVisible = true;
	this._delay = 0;
	this._reflect = false;
	this._repeat = 0;
	this._reverse = false;
	this._smartRotation = false;
	this._snapping = false;
	this.special = false;
	this.target = target;
	this.properties = properties;
	this.duration = duration;
	this._ease = motion.Actuate.defaultEase;
};
motion.actuators.GenericActuator.__name__ = true;
motion.actuators.GenericActuator.__interfaces__ = [motion.actuators.IGenericActuator];
motion.actuators.GenericActuator.prototype = {
	apply: function() {
		var _g = 0;
		var _g1 = Reflect.fields(this.properties);
		while(_g < _g1.length) {
			var i = _g1[_g];
			++_g;
			if(Object.prototype.hasOwnProperty.call(this.target,i)) Reflect.setField(this.target,i,Reflect.field(this.properties,i)); else Reflect.setProperty(this.target,i,Reflect.field(this.properties,i));
		}
	}
	,autoVisible: function(value) {
		if(value == null) value = true;
		this._autoVisible = value;
		return this;
	}
	,callMethod: function(method,params) {
		if(params == null) params = [];
		return method.apply(method,params);
	}
	,change: function() {
		if(this._onUpdate != null) this.callMethod(this._onUpdate,this._onUpdateParams);
	}
	,complete: function(sendEvent) {
		if(sendEvent == null) sendEvent = true;
		if(sendEvent) {
			this.change();
			if(this._onComplete != null) this.callMethod(this._onComplete,this._onCompleteParams);
		}
		motion.Actuate.unload(this);
	}
	,delay: function(duration) {
		this._delay = duration;
		return this;
	}
	,ease: function(easing) {
		this._ease = easing;
		return this;
	}
	,move: function() {
	}
	,onComplete: function(handler,parameters) {
		this._onComplete = handler;
		if(parameters == null) this._onCompleteParams = []; else this._onCompleteParams = parameters;
		if(this.duration == 0) this.complete();
		return this;
	}
	,onRepeat: function(handler,parameters) {
		this._onRepeat = handler;
		if(parameters == null) this._onRepeatParams = []; else this._onRepeatParams = parameters;
		return this;
	}
	,onUpdate: function(handler,parameters) {
		this._onUpdate = handler;
		if(parameters == null) this._onUpdateParams = []; else this._onUpdateParams = parameters;
		return this;
	}
	,pause: function() {
	}
	,reflect: function(value) {
		if(value == null) value = true;
		this._reflect = value;
		this.special = true;
		return this;
	}
	,repeat: function(times) {
		if(times == null) times = -1;
		this._repeat = times;
		return this;
	}
	,resume: function() {
	}
	,reverse: function(value) {
		if(value == null) value = true;
		this._reverse = value;
		this.special = true;
		return this;
	}
	,smartRotation: function(value) {
		if(value == null) value = true;
		this._smartRotation = value;
		this.special = true;
		return this;
	}
	,snapping: function(value) {
		if(value == null) value = true;
		this._snapping = value;
		this.special = true;
		return this;
	}
	,stop: function(properties,complete,sendEvent) {
	}
	,__class__: motion.actuators.GenericActuator
};
motion.actuators.SimpleActuator = function(target,duration,properties) {
	this.active = true;
	this.propertyDetails = new Array();
	this.sendChange = false;
	this.paused = false;
	this.cacheVisible = false;
	this.initialized = false;
	this.setVisible = false;
	this.toggleVisible = false;
	this.startTime = haxe.Timer.stamp();
	motion.actuators.GenericActuator.call(this,target,duration,properties);
	if(!motion.actuators.SimpleActuator.addedEvent) {
		motion.actuators.SimpleActuator.addedEvent = true;
		motion.actuators.SimpleActuator.timer = new haxe.Timer(33);
		motion.actuators.SimpleActuator.timer.run = motion.actuators.SimpleActuator.stage_onEnterFrame;
	}
};
motion.actuators.SimpleActuator.__name__ = true;
motion.actuators.SimpleActuator.stage_onEnterFrame = function() {
	var currentTime = haxe.Timer.stamp();
	var actuator;
	var j = 0;
	var cleanup = false;
	var _g1 = 0;
	var _g = motion.actuators.SimpleActuator.actuatorsLength;
	while(_g1 < _g) {
		var i = _g1++;
		actuator = motion.actuators.SimpleActuator.actuators[j];
		if(actuator != null && actuator.active) {
			if(currentTime > actuator.timeOffset) actuator.update(currentTime);
			j++;
		} else {
			motion.actuators.SimpleActuator.actuators.splice(j,1);
			--motion.actuators.SimpleActuator.actuatorsLength;
		}
	}
};
motion.actuators.SimpleActuator.__super__ = motion.actuators.GenericActuator;
motion.actuators.SimpleActuator.prototype = $extend(motion.actuators.GenericActuator.prototype,{
	autoVisible: function(value) {
		if(value == null) value = true;
		this._autoVisible = value;
		if(!value) {
			this.toggleVisible = false;
			if(this.setVisible) this.setField(this.target,"visible",this.cacheVisible);
		}
		return this;
	}
	,delay: function(duration) {
		this._delay = duration;
		this.timeOffset = this.startTime + duration;
		return this;
	}
	,getField: function(target,propertyName) {
		var value = null;
		if(Object.prototype.hasOwnProperty.call(target,propertyName)) value = Reflect.field(target,propertyName); else value = Reflect.getProperty(target,propertyName);
		return value;
	}
	,initialize: function() {
		var details;
		var start;
		var _g = 0;
		var _g1 = Reflect.fields(this.properties);
		while(_g < _g1.length) {
			var i = _g1[_g];
			++_g;
			var isField = true;
			if(Object.prototype.hasOwnProperty.call(this.target,i)) start = Reflect.field(this.target,i); else {
				isField = false;
				start = Reflect.getProperty(this.target,i);
			}
			if(typeof(start) == "number") {
				details = new motion.actuators.PropertyDetails(this.target,i,start,this.getField(this.properties,i) - start,isField);
				this.propertyDetails.push(details);
			}
		}
		this.detailsLength = this.propertyDetails.length;
		this.initialized = true;
	}
	,move: function() {
		this.toggleVisible = Object.prototype.hasOwnProperty.call(this.properties,"alpha") && Object.prototype.hasOwnProperty.call(this.properties,"visible");
		if(this.toggleVisible && this.properties.alpha != 0 && !this.getField(this.target,"visible")) {
			this.setVisible = true;
			this.cacheVisible = this.getField(this.target,"visible");
			this.setField(this.target,"visible",true);
		}
		this.timeOffset = this.startTime;
		motion.actuators.SimpleActuator.actuators.push(this);
		++motion.actuators.SimpleActuator.actuatorsLength;
	}
	,onUpdate: function(handler,parameters) {
		this._onUpdate = handler;
		if(parameters == null) this._onUpdateParams = []; else this._onUpdateParams = parameters;
		this.sendChange = true;
		return this;
	}
	,pause: function() {
		this.paused = true;
		this.pauseTime = haxe.Timer.stamp();
	}
	,resume: function() {
		if(this.paused) {
			this.paused = false;
			this.timeOffset += (haxe.Timer.stamp() - this.pauseTime) / 1000;
		}
	}
	,setField: function(target,propertyName,value) {
		if(Object.prototype.hasOwnProperty.call(target,propertyName)) target[propertyName] = value; else Reflect.setProperty(target,propertyName,value);
	}
	,setProperty: function(details,value) {
		if(details.isField) details.target[details.propertyName] = value; else Reflect.setProperty(details.target,details.propertyName,value);
	}
	,stop: function(properties,complete,sendEvent) {
		if(this.active) {
			if(properties == null) {
				this.active = false;
				if(complete) this.apply();
				this.complete(sendEvent);
				return;
			}
			var _g = 0;
			var _g1 = Reflect.fields(properties);
			while(_g < _g1.length) {
				var i = _g1[_g];
				++_g;
				if(Object.prototype.hasOwnProperty.call(this.properties,i)) {
					this.active = false;
					if(complete) this.apply();
					this.complete(sendEvent);
					return;
				}
			}
		}
	}
	,update: function(currentTime) {
		if(!this.paused) {
			var details;
			var easing;
			var i;
			var tweenPosition = (currentTime - this.timeOffset) / this.duration;
			if(tweenPosition > 1) tweenPosition = 1;
			if(!this.initialized) this.initialize();
			if(!this.special) {
				easing = this._ease.calculate(tweenPosition);
				var _g1 = 0;
				var _g = this.detailsLength;
				while(_g1 < _g) {
					var i1 = _g1++;
					details = this.propertyDetails[i1];
					this.setProperty(details,details.start + details.change * easing);
				}
			} else {
				if(!this._reverse) easing = this._ease.calculate(tweenPosition); else easing = this._ease.calculate(1 - tweenPosition);
				var endValue;
				var _g11 = 0;
				var _g2 = this.detailsLength;
				while(_g11 < _g2) {
					var i2 = _g11++;
					details = this.propertyDetails[i2];
					if(this._smartRotation && (details.propertyName == "rotation" || details.propertyName == "rotationX" || details.propertyName == "rotationY" || details.propertyName == "rotationZ")) {
						var rotation = details.change % 360;
						if(rotation > 180) rotation -= 360; else if(rotation < -180) rotation += 360;
						endValue = details.start + rotation * easing;
					} else endValue = details.start + details.change * easing;
					if(!this._snapping) {
						if(details.isField) details.target[details.propertyName] = endValue; else Reflect.setProperty(details.target,details.propertyName,endValue);
					} else this.setProperty(details,Math.round(endValue));
				}
			}
			if(tweenPosition == 1) {
				if(this._repeat == 0) {
					this.active = false;
					if(this.toggleVisible && this.getField(this.target,"alpha") == 0) this.setField(this.target,"visible",false);
					this.complete(true);
					return;
				} else {
					if(this._onRepeat != null) this.callMethod(this._onRepeat,this._onRepeatParams);
					if(this._reflect) this._reverse = !this._reverse;
					this.startTime = currentTime;
					this.timeOffset = this.startTime + this._delay;
					if(this._repeat > 0) this._repeat--;
				}
			}
			if(this.sendChange) this.change();
		}
	}
	,__class__: motion.actuators.SimpleActuator
});
motion.easing = {};
motion.easing.Expo = function() { };
motion.easing.Expo.__name__ = true;
motion.easing.Expo.__properties__ = {get_easeOut:"get_easeOut"}
motion.easing.Expo.get_easeOut = function() {
	return new motion.easing.ExpoEaseOut();
};
motion.easing.IEasing = function() { };
motion.easing.IEasing.__name__ = true;
motion.easing.IEasing.prototype = {
	__class__: motion.easing.IEasing
};
motion.easing.ExpoEaseOut = function() {
};
motion.easing.ExpoEaseOut.__name__ = true;
motion.easing.ExpoEaseOut.__interfaces__ = [motion.easing.IEasing];
motion.easing.ExpoEaseOut.prototype = {
	calculate: function(k) {
		if(k == 1) return 1; else return 1 - Math.pow(2,-10 * k);
	}
	,__class__: motion.easing.ExpoEaseOut
};
motion.Actuate = function() { };
motion.Actuate.__name__ = true;
motion.Actuate.apply = function(target,properties,customActuator) {
	motion.Actuate.stop(target,properties);
	if(customActuator == null) customActuator = motion.Actuate.defaultActuator;
	var actuator = Type.createInstance(customActuator,[target,0,properties]);
	actuator.apply();
	return actuator;
};
motion.Actuate.getLibrary = function(target,allowCreation) {
	if(allowCreation == null) allowCreation = true;
	if(!motion.Actuate.targetLibraries.exists(target) && allowCreation) motion.Actuate.targetLibraries.set(target,new Array());
	return motion.Actuate.targetLibraries.get(target);
};
motion.Actuate.stop = function(target,properties,complete,sendEvent) {
	if(sendEvent == null) sendEvent = true;
	if(complete == null) complete = false;
	if(target != null) {
		if(js.Boot.__instanceof(target,motion.actuators.GenericActuator)) (js.Boot.__cast(target , motion.actuators.GenericActuator)).stop(null,complete,sendEvent); else {
			var library = motion.Actuate.getLibrary(target,false);
			if(library != null) {
				if(typeof(properties) == "string") {
					var temp = { };
					Reflect.setField(temp,properties,null);
					properties = temp;
				} else if((properties instanceof Array) && properties.__enum__ == null) {
					var temp1 = { };
					var _g = 0;
					var _g1;
					_g1 = js.Boot.__cast(properties , Array);
					while(_g < _g1.length) {
						var property = _g1[_g];
						++_g;
						Reflect.setField(temp1,property,null);
					}
					properties = temp1;
				}
				var i = library.length - 1;
				while(i >= 0) {
					library[i].stop(properties,complete,sendEvent);
					i--;
				}
			}
		}
	}
};
motion.Actuate.tween = function(target,duration,properties,overwrite,customActuator) {
	if(overwrite == null) overwrite = true;
	if(target != null) {
		if(duration > 0) {
			if(customActuator == null) customActuator = motion.Actuate.defaultActuator;
			var actuator = Type.createInstance(customActuator,[target,duration,properties]);
			var library = motion.Actuate.getLibrary(actuator.target);
			if(overwrite) {
				var i = library.length - 1;
				while(i >= 0) {
					library[i].stop(actuator.properties,false,false);
					i--;
				}
				library = motion.Actuate.getLibrary(actuator.target);
			}
			library.push(actuator);
			actuator.move();
			return actuator;
		} else return motion.Actuate.apply(target,properties,customActuator);
	}
	return null;
};
motion.Actuate.unload = function(actuator) {
	var target = actuator.target;
	if(motion.Actuate.targetLibraries.h.__keys__[target.__id__] != null) {
		HxOverrides.remove(motion.Actuate.targetLibraries.h[target.__id__],actuator);
		if(motion.Actuate.targetLibraries.h[target.__id__].length == 0) motion.Actuate.targetLibraries.remove(target);
	}
};
motion.IComponentPath = function() { };
motion.IComponentPath.__name__ = true;
motion.IComponentPath.prototype = {
	__class__: motion.IComponentPath
};
motion.actuators.MethodActuator = function(target,duration,properties) {
	this.currentParameters = new Array();
	this.tweenProperties = { };
	motion.actuators.SimpleActuator.call(this,target,duration,properties);
	if(!Object.prototype.hasOwnProperty.call(properties,"start")) this.properties.start = new Array();
	if(!Object.prototype.hasOwnProperty.call(properties,"end")) this.properties.end = this.properties.start;
	var _g1 = 0;
	var _g = this.properties.start.length;
	while(_g1 < _g) {
		var i = _g1++;
		this.currentParameters.push(null);
	}
};
motion.actuators.MethodActuator.__name__ = true;
motion.actuators.MethodActuator.__super__ = motion.actuators.SimpleActuator;
motion.actuators.MethodActuator.prototype = $extend(motion.actuators.SimpleActuator.prototype,{
	apply: function() {
		this.callMethod(this.target,this.properties.end);
	}
	,complete: function(sendEvent) {
		if(sendEvent == null) sendEvent = true;
		var _g1 = 0;
		var _g = this.properties.start.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.currentParameters[i] = Reflect.field(this.tweenProperties,"param" + i);
		}
		this.callMethod(this.target,this.currentParameters);
		motion.actuators.SimpleActuator.prototype.complete.call(this,sendEvent);
	}
	,initialize: function() {
		var details;
		var propertyName;
		var start;
		var _g1 = 0;
		var _g = this.properties.start.length;
		while(_g1 < _g) {
			var i = _g1++;
			propertyName = "param" + i;
			start = this.properties.start[i];
			this.tweenProperties[propertyName] = start;
			if(typeof(start) == "number" || ((start | 0) === start)) {
				details = new motion.actuators.PropertyDetails(this.tweenProperties,propertyName,start,this.properties.end[i] - start);
				this.propertyDetails.push(details);
			}
		}
		this.detailsLength = this.propertyDetails.length;
		this.initialized = true;
	}
	,update: function(currentTime) {
		motion.actuators.SimpleActuator.prototype.update.call(this,currentTime);
		if(this.active) {
			var _g1 = 0;
			var _g = this.properties.start.length;
			while(_g1 < _g) {
				var i = _g1++;
				this.currentParameters[i] = Reflect.field(this.tweenProperties,"param" + i);
			}
			this.callMethod(this.target,this.currentParameters);
		}
	}
	,__class__: motion.actuators.MethodActuator
});
motion.actuators.MotionPathActuator = function(target,duration,properties) {
	motion.actuators.SimpleActuator.call(this,target,duration,properties);
};
motion.actuators.MotionPathActuator.__name__ = true;
motion.actuators.MotionPathActuator.__super__ = motion.actuators.SimpleActuator;
motion.actuators.MotionPathActuator.prototype = $extend(motion.actuators.SimpleActuator.prototype,{
	apply: function() {
		var _g = 0;
		var _g1 = Reflect.fields(this.properties);
		while(_g < _g1.length) {
			var propertyName = _g1[_g];
			++_g;
			if(Object.prototype.hasOwnProperty.call(this.target,propertyName)) Reflect.setField(this.target,propertyName,(js.Boot.__cast(Reflect.field(this.properties,propertyName) , motion.IComponentPath)).get_end()); else Reflect.setProperty(this.target,propertyName,(js.Boot.__cast(Reflect.field(this.properties,propertyName) , motion.IComponentPath)).get_end());
		}
	}
	,initialize: function() {
		var details;
		var path;
		var _g = 0;
		var _g1 = Reflect.fields(this.properties);
		while(_g < _g1.length) {
			var propertyName = _g1[_g];
			++_g;
			path = js.Boot.__cast(Reflect.field(this.properties,propertyName) , motion.IComponentPath);
			if(path != null) {
				var isField = true;
				if(Object.prototype.hasOwnProperty.call(this.target,propertyName)) path.start = Reflect.field(this.target,propertyName); else {
					isField = false;
					path.start = Reflect.getProperty(this.target,propertyName);
				}
				details = new motion.actuators.PropertyPathDetails(this.target,propertyName,path,isField);
				this.propertyDetails.push(details);
			}
		}
		this.detailsLength = this.propertyDetails.length;
		this.initialized = true;
	}
	,update: function(currentTime) {
		if(!this.paused) {
			var details;
			var easing;
			var tweenPosition = (currentTime - this.timeOffset) / this.duration;
			if(tweenPosition > 1) tweenPosition = 1;
			if(!this.initialized) this.initialize();
			if(!this.special) {
				easing = this._ease.calculate(tweenPosition);
				var _g = 0;
				var _g1 = this.propertyDetails;
				while(_g < _g1.length) {
					var details1 = _g1[_g];
					++_g;
					if(details1.isField) Reflect.setField(details1.target,details1.propertyName,(js.Boot.__cast(details1 , motion.actuators.PropertyPathDetails)).path.calculate(easing)); else Reflect.setProperty(details1.target,details1.propertyName,(js.Boot.__cast(details1 , motion.actuators.PropertyPathDetails)).path.calculate(easing));
				}
			} else {
				if(!this._reverse) easing = this._ease.calculate(tweenPosition); else easing = this._ease.calculate(1 - tweenPosition);
				var endValue;
				var _g2 = 0;
				var _g11 = this.propertyDetails;
				while(_g2 < _g11.length) {
					var details2 = _g11[_g2];
					++_g2;
					if(!this._snapping) {
						if(details2.isField) Reflect.setField(details2.target,details2.propertyName,(js.Boot.__cast(details2 , motion.actuators.PropertyPathDetails)).path.calculate(easing)); else Reflect.setProperty(details2.target,details2.propertyName,(js.Boot.__cast(details2 , motion.actuators.PropertyPathDetails)).path.calculate(easing));
					} else if(details2.isField) Reflect.setField(details2.target,details2.propertyName,Math.round((js.Boot.__cast(details2 , motion.actuators.PropertyPathDetails)).path.calculate(easing))); else Reflect.setProperty(details2.target,details2.propertyName,Math.round((js.Boot.__cast(details2 , motion.actuators.PropertyPathDetails)).path.calculate(easing)));
				}
			}
			if(tweenPosition == 1) {
				if(this._repeat == 0) {
					this.active = false;
					if(this.toggleVisible && this.getField(this.target,"alpha") == 0) this.setField(this.target,"visible",false);
					this.complete(true);
					return;
				} else {
					if(this._reflect) this._reverse = !this._reverse;
					this.startTime = currentTime;
					this.timeOffset = this.startTime + this._delay;
					if(this._repeat > 0) this._repeat--;
				}
			}
			if(this.sendChange) this.change();
		}
	}
	,__class__: motion.actuators.MotionPathActuator
});
motion.actuators.PropertyDetails = function(target,propertyName,start,change,isField) {
	if(isField == null) isField = true;
	this.target = target;
	this.propertyName = propertyName;
	this.start = start;
	this.change = change;
	this.isField = isField;
};
motion.actuators.PropertyDetails.__name__ = true;
motion.actuators.PropertyDetails.prototype = {
	__class__: motion.actuators.PropertyDetails
};
motion.actuators.PropertyPathDetails = function(target,propertyName,path,isField) {
	if(isField == null) isField = true;
	motion.actuators.PropertyDetails.call(this,target,propertyName,0,0,isField);
	this.path = path;
};
motion.actuators.PropertyPathDetails.__name__ = true;
motion.actuators.PropertyPathDetails.__super__ = motion.actuators.PropertyDetails;
motion.actuators.PropertyPathDetails.prototype = $extend(motion.actuators.PropertyDetails.prototype,{
	__class__: motion.actuators.PropertyPathDetails
});
motion.easing.Cubic = function() { };
motion.easing.Cubic.__name__ = true;
motion.easing.Cubic.__properties__ = {get_easeInOut:"get_easeInOut"}
motion.easing.Cubic.get_easeInOut = function() {
	return new motion.easing.CubicEaseInOut();
};
motion.easing.CubicEaseInOut = function() {
};
motion.easing.CubicEaseInOut.__name__ = true;
motion.easing.CubicEaseInOut.__interfaces__ = [motion.easing.IEasing];
motion.easing.CubicEaseInOut.prototype = {
	calculate: function(k) {
		if((k /= 0.5) < 1) return 0.5 * k * k * k; else return 0.5 * ((k -= 2) * k * k + 2);
	}
	,__class__: motion.easing.CubicEaseInOut
};
msignal.Slot = function(signal,listener,once,priority) {
	if(priority == null) priority = 0;
	if(once == null) once = false;
	this.signal = signal;
	this.set_listener(listener);
	this.once = once;
	this.priority = priority;
	this.enabled = true;
};
msignal.Slot.__name__ = true;
msignal.Slot.prototype = {
	remove: function() {
		this.signal.remove(this.listener);
	}
	,set_listener: function(value) {
		if(value == null) throw "listener cannot be null";
		return this.listener = value;
	}
	,__class__: msignal.Slot
	,__properties__: {set_listener:"set_listener"}
};
msignal.Slot0 = function(signal,listener,once,priority) {
	if(priority == null) priority = 0;
	if(once == null) once = false;
	msignal.Slot.call(this,signal,listener,once,priority);
};
msignal.Slot0.__name__ = true;
msignal.Slot0.__super__ = msignal.Slot;
msignal.Slot0.prototype = $extend(msignal.Slot.prototype,{
	execute: function() {
		if(!this.enabled) return;
		if(this.once) this.remove();
		this.listener();
	}
	,__class__: msignal.Slot0
});
msignal.Slot1 = function(signal,listener,once,priority) {
	if(priority == null) priority = 0;
	if(once == null) once = false;
	msignal.Slot.call(this,signal,listener,once,priority);
};
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
if(Array.prototype.indexOf) HxOverrides.indexOf = function(a,o,i) {
	return Array.prototype.indexOf.call(a,o,i);
};
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
com.arm.demo.notifications.internal.MenuNotification.click = new msignal.Signal1(Int);
com.arm.demo.notifications.internal.MenuNotification.reset = new msignal.Signal0();
com.arm.demo.notifications.internal.ViewStateNotification.preloader = new msignal.Signal0();
com.arm.demo.notifications.internal.ViewStateNotification.preloaderProgress = new msignal.Signal0();
com.arm.demo.notifications.internal.ViewStateNotification.preload = new msignal.Signal0();
com.arm.demo.notifications.internal.ViewStateNotification.create = new msignal.Signal0();
com.arm.demo.notifications.internal.ViewStateNotification.update = new msignal.Signal1(Float);
com.arm.demo.notifications.internal.ViewStateNotification.destroy = new msignal.Signal0();
com.arm.demo.notifications.internal.ViewStateNotification.resize = new msignal.Signal0();
fluid.display.FluidStage.pixelRatio = 1;
fluid.display.FluidStage.screenWidth = 800;
fluid.display.FluidStage.screenHeight = 600;
haxe.ds.ObjectMap.count = 0;
motion.actuators.SimpleActuator.actuators = new Array();
motion.actuators.SimpleActuator.actuatorsLength = 0;
motion.actuators.SimpleActuator.addedEvent = false;
motion.Actuate.defaultActuator = motion.actuators.SimpleActuator;
motion.Actuate.defaultEase = motion.easing.Expo.get_easeOut();
motion.Actuate.targetLibraries = new haxe.ds.ObjectMap();
com.arm.demo.Main.main();
})();

//# sourceMappingURL=fluid.dev.js.map