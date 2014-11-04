package com.arm.demo.components;

import com.arm.demo.view.DemoView;
import fluid.display.FluidStage;

//import gamesys.pixidemo.resources.Settings;
//import gamesys.pixidemo.resources.Layout;
//import gamesys.pixidemo.resources.Messages;

class GameComponentView extends DemoView {

	//var _messages:Messages;
	//var _layout:Layout;
	//var _settings:Settings;
	//var _sounds:Sounds;

	public function new(container) {
		super(container);

		//_messages = Messages.getInstance();
		//_layout = Layout.getInstance();
		//_settings = Settings.getInstance();
		//_sounds = Sounds.getInstance();
	}

	function _applyScale(item) {
		//item.scale.set(1 / FluidStage.pixelRatio, 1 / FluidStage.pixelRatio);
	}
}