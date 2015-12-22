package fluid.core.utils;

class PluginTarget {

	public static var __plugins:Dynamic = {};

	public static function registerPlugin(obj:Dynamic, pluginName:String, ctor:Dynamic) {
		trace("AFASFSAFASFSAF");
		Reflect.setField(__plugins, pluginName, ctor);
	}

	public static function initPlugins(obj:Dynamic) {
		trace(obj);
		if (obj.plugins == null) obj.plugins = {};

		trace(__plugins);
	}
}