#pragma once

namespace gameconst {
	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS;
}

namespace objconst {
	const int SPRITE_SCALE = 2;
	const int SPRITE_SPEED = 5;
	
	const int MENU_SCALE = 1;
}

namespace UIconst {
	const int buttonGap = 10;

	enum ButtonType {
		missing = 0,
		quit,
		resume
	};
}