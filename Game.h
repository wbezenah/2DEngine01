#pragma once

#include <SDL.h>
#include <iostream>

#include "Input.h"
#include "GameObject.h"

class Game {
public:
	Game();
	~Game();

	void _init_(const char* windowTitle, int windowX, int windowY, int windowWidth, int windowHeight, bool fullscreen);
	void handleEvents();
	void updateGame();
	void render();

	void clean();
	bool isRunning();

	SDL_Renderer* getRenderer();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running;
	bool fullscreen;
	Input input;

	GameObject player;
};
