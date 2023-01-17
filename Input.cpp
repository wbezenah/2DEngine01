#include "Input.h"

Input::Input() {
	this->commands.push_back(std::make_unique<JumpCommand>(JumpCommand()));
	this->commands.push_back(std::make_unique<MoveByCommand>(MoveByCommand(0, 1)));
	this->commands.push_back(std::make_unique<MoveByCommand>(MoveByCommand(-1, 0)));
	this->commands.push_back(std::make_unique<MoveByCommand>(MoveByCommand(0, -1)));
	this->commands.push_back(std::make_unique<MoveByCommand>(MoveByCommand(1, 0)));
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
	if (this->wasPressed(SDL_SCANCODE_SPACE)) {
		return this->commands[space].get();
	}
	else if (this->wasPressed(SDL_SCANCODE_W)) {
		return this->commands[w].get();
	}
	else if (this->wasPressed(SDL_SCANCODE_A)) {
		return this->commands[a].get();
	}
	else if (this->wasPressed(SDL_SCANCODE_S)) {
		return this->commands[s].get();
	}
	else if (this->wasPressed(SDL_SCANCODE_D)) {
		return this->commands[d].get();
	}
	else {
		return nullptr;
	}
}
