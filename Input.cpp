#include "Input.h"

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
