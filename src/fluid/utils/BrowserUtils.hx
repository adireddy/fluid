package gamesys.core.utils;

import js.Browser;

class BrowserUtils {

	public static function getPixelRatio():Float {
		var pixelRatio = (Browser.window.devicePixelRatio <= 2) ? Math.floor(Browser.window.devicePixelRatio) : 2;
		var iOS:EReg = ~/(iPad|iPhone|iPod)/i;
		if(iOS.match(Browser.navigator.userAgent)) {
			if(Browser.window.screen.width == 320 && Browser.window.screen.height == 480) {
				pixelRatio = 1;
			}
		}
		return pixelRatio;
	}

}