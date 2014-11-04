package ;

abstract Object<T>(Dynamic<T>) from Dynamic<T> {

	public inline function new() this = {};

	@:arrayAccess
	public inline function get(key:String):Null<T> return Reflect.field(this, key);

	@:arrayAccess
	public inline function set(key:String, value:T) Reflect.setField(this, key, value);

	public inline function has(key:String):Bool return Reflect.hasField(this, key);

	public inline function remove(key:String):Bool return Reflect.deleteField(this, key);

	public inline function keys():Array<String> return Reflect.fields(this);
}