package ;

class StringCore {

	public static function stripHTML(content:String):String {
		var pattern:EReg = ~/<[^>]*>/g;
		return pattern.replace(content, "");
	}

	public static function capitalize(value:String):String {
		var words = value.split(" ");
		for (i in 0...words.length) {
			var word = words[i];
			words[i] = word.charAt(0).toUpperCase() + word.substr(1);
		}
		
		return words.join(" ");
	}	

	public static function substitute(source:String, values:Array<Dynamic>):String {
		for (i in 0...values.length)
			source = source.split("{" + i + "}").join(values[i]);
		return source;
	}

	public static inline function contains(source:String, subject:String):Bool {
		return source.indexOf(subject) != -1;
	}
	
	public static inline function lastChar(source:String):String {
		return (source == "") ? "" : source.charAt(source.length - 1);
	}
}