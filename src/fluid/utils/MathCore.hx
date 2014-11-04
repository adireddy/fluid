package ;

using MathCore;
using Lambda;
using Math;
using Std;

class MathCore {

	public static inline var INT32_MAX = 0x7fffffff;

	public static inline var WHOLE_NUMBER_MAX = 9007199254740992;

	public static inline var WHOLE_NUMBER_MIN = -9007199254740992;

	public static function isEven(n:Int):Bool {
		return n % 2 == 0;
	}

	public static function isOdd(n:Int):Bool {
		return !isEven(n);
	}

	public static function degreesToRadians(degrees:Float):Float {
		return (degrees * Math.PI) / 180;
	}

	public static function radiansToDegrees(radians:Float):Float {
		return (radians * 180) / Math.PI;
	}
}