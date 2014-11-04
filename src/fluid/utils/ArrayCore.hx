package ;

class ArrayCore {

	public static inline function first<T>(a:Array<T>):T {
		return a[0];
	}

	public static inline function last<T>(a:Array<T>):T {
		return a[a.length - 1];
	}

	public static function moveTowardStart<T>(a:Array<T>, index:Int, ?wrap:Bool = true):Array<T> {
		if (a.length < 2 || index < 0 || index > a.length - 1) return a;

		if (index == 0) if (wrap) a.push(a.shift());
		else a.insert(index - 1, a.splice(index, 1)[0]);

		return a;
	}

	public static function moveTowardEnd<T>(a:Array<T>, index:Int, ?wrap:Bool = true):Array<T> {
		if (a.length < 2 || index < 0 || index > a.length - 1) return a;

		if (index == a.length - 1) if (wrap) a.unshift(a.pop());
		else a.insert(index + 1, a.splice(index, 1)[0]);

		return a;
	}

	public static inline function toString<T>(a:Array<T>):String {
		return a.toString();
	}
	
	public static function shuffle<T>(a:Array<T>):Array<T> {
		var copy = a.copy();
		var shuffled = [];
		while (copy.length > 0) shuffled.push(copy.splice(Std.random(copy.length), 1)[0]);
		return shuffled;
	}
}