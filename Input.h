#pragma once

#include <SDL.h>
#include <map>

class Input {
public:
	Input() = default;

	void begin();
	void keyUp(const SDL_Event& event);
	void keyDown(const SDL_Event& event);

	// Functions check key state
	bool wasPressed(SDL_Scancode key);
	bool wasReleased(SDL_Scancode key);
	bool isHeld(SDL_Scancode key);

private:
	std::map<SDL_Scancode, bool> heldKeys;
	std::map<SDL_Scancode, bool> pressedKeys;
	std::map<SDL_Scancode, bool> releasedKeys;
};