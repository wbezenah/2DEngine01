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
		dy += -10;
	}
	if (this->wasPressed(SDL_SCANCODE_A) || this->isHeld(SDL_SCANCODE_A)) {
		dx += -10;
	}
	if (this->wasPressed(SDL_SCANCODE_S) || this->isHeld(SDL_SCANCODE_S)) {
		dy += 10;
	}
	if (this->wasPressed(SDL_SCANCODE_D) || this->isHeld(SDL_SCANCODE_D)) {
		dx += 10;
	}

	if (dx == 0 && dy == 0) {
		return nullptr;
	}

	return new MoveByCommand(dx, dy);
}
