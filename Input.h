#pragma once

#include <SDL.h>
#include <map>
#include <vector>
#include <memory>
#include "CommandList.h"

enum Keys {
	space,
	w,
	a,
	s,
	d,
};

class Input {
public:
	Input();

	void begin();
	void keyUp(const SDL_Event& event);
	void keyDown(const SDL_Event& event);

	// Functions check key state
	bool wasPressed(SDL_Scancode key);
	bool wasReleased(SDL_Scancode key);
	bool isHeld(SDL_Scancode key);

	//Functions determine command
	Command* getCommand();

private:
	std::map<SDL_Scancode, bool> heldKeys;
	std::map<SDL_Scancode, bool> pressedKeys;
	std::map<SDL_Scancode, bool> releasedKeys;
	
	//std::vector<std::unique_ptr<Command>> commands;
	std::vector<std::unique_ptr<Command>> commands;
};