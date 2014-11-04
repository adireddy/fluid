package com.arm.demo.notifications.internal;

import msignal.Signal;

class ViewStateNotification {

	public static var preloader:Signal0 = new Signal0();
	public static var preloaderProgress:Signal0 = new Signal0();
	public static var preload:Signal0 = new Signal0();
	public static var create:Signal0 = new Signal0();
	public static var update:Signal1<Float> = new Signal1(Float);
	public static var destroy:Signal0 = new Signal0();
	public static var resize:Signal0 = new Signal0();

	public static function reset():Void {
		preloader.removeAll();
		preloaderProgress.removeAll();
		preload.removeAll();
		create.removeAll();
		update.removeAll();
		destroy.removeAll();
		resize.removeAll();
	}
}