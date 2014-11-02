package fluid.utils;

import js.html.DivElement;

@:native("Stats")
extern class StatsJS {
	public var REVISION(default, null):Int;
	public var domElement(default, null):DivElement;

	public function new();

	public function begin():Void;
	public function end():Void;
	public function update():Void;
	public function setMode(value:Int):Void;
}