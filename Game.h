#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>

#include "Constants.h"
#include "Input.h"
#include "GameObjects.h"

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
	bool isPaused();

	SDL_Renderer* getRenderer();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running;
	bool paused;
	bool fullscreen;
	Input input;

	Player player;
	std::vector<GameObject> pauseMenu;
};
