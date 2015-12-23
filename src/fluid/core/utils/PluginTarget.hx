package fluid.core.utils;

import fluid.core.renderers.webgl.WebGLRenderer;

class PluginTarget {

	public static function registerPlugin(obj:WebGLRenderer, pluginName:String, ctor:Class<Dynamic>) {
		obj.__plugins.set(pluginName, ctor);
	}

	public static function initPlugins(obj:WebGLRenderer) {
		for (o in obj.__plugins.keys()) {
			obj.plugins.set(o, Type.createInstance(obj.__plugins.get(o), [obj]));
		}
	}

	public static function destroyPlugins(obj:WebGLRenderer) {
		for (o in obj.plugins.keys()) {
			obj.plugins.get(o).destroy();
			obj.plugins.set(o, null);
		}

		obj.plugins = null;
	}
}