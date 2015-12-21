package fluid.interaction;

import fluid.interaction.InteractionData;

typedef EventTarget = {
	var stopped:Bool;
	var type:String;
	var data:InteractionData;
	var target:Dynamic;
	function stopPropagation():Void;
}