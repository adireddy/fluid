package com.arm.demo.components.menu;

import com.arm.demo.components.GameComponentController;

class MenuController extends GameComponentController {

	var _view:MenuView;

	public function new(m, v, c, mainModel) {
		super(m, v, c, mainModel);
		_view = cast(v, MenuView);

		_view.create();
	}

	override function _create() {
		_view.create();
	}

}