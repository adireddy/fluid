package com.arm.demo.notifications.internal;

import msignal.Signal;

class MenuNotification {

	public static var click:Signal1<Int> = new Signal1(Int);
	public static var reset:Signal0 = new Signal0();

}