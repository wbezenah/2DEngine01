#include "Input.h"

Input::Input() {

}

void Input::begin() {
	this->pressedKeys.clear();
	this->releasedKeys.clear();
}

void Input::keyDown(const SDL_Event& event) {
	SDL_Scancode sc = event.key.keysym.scancode;
	this->pressedKeys[sc] = true;
	this->heldKeys[sc] = true;
}

void Input::keyUp(const SDL_Event& event) {
	SDL_Scancode sc = event.key.keysym.scancode;
	this->releasedKeys[sc] = true;
	this->heldKeys[sc] = false;
}

bool Input::wasPressed(SDL_Scancode key) {
	return this->pressedKeys[key];
}

bool Input::wasReleased(SDL_Scancode key) {
	return this->releasedKeys[key];
}

bool Input::isHeld(SDL_Scancode key) {
	return this->heldKeys[key];
}

Command* Input::getCommand() {
	int dx = 0;
	int dy = 0;

	if (this->wasPressed(SDL_SCANCODE_SPACE) || this->isHeld(SDL_SCANCODE_SPACE)) {
		return new JumpCommand();
	}
	if (this->wasPressed(SDL_SCANCODE_W) || this->isHeld(SDL_SCANCODE_W)) {
		dy += -1 * objconst::SPRITE_SPEED;
	}
	if (this->wasPressed(SDL_SCANCODE_A) || this->isHeld(SDL_SCANCODE_A)) {
		dx += -1 * objconst::SPRITE_SPEED;
	}
	if (this->wasPressed(SDL_SCANCODE_S) || this->isHeld(SDL_SCANCODE_S)) {
		dy += objconst::SPRITE_SPEED;
	}
	if (this->wasPressed(SDL_SCANCODE_D) || this->isHeld(SDL_SCANCODE_D)) {
		dx += objconst::SPRITE_SPEED;
	}

	if (dx == 0 && dy == 0) {
		return nullptr;
	}
	if (abs(dx) == abs(dy)) {
		float resultX = dx / abs(dx) * sqrt(dx * dx / 2);
		float resultY = dy / abs(dy) * sqrt(dy * dy/ 2);
		dx = static_cast<int>(resultX);
		dy = static_cast<int>(resultY);
	}
	return new MoveByCommand(dx, dy);
}
