#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>

#include "Constants.h"
#include "Input.h"
#include "GameObjects.h"

typedef struct pauseMenu {
	Button resume;
	Button quit;
};

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

	void updateButtonPositions();

	static bool checkWithin(Vector2 loc, Vector2 origin, int width, int height);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running;
	bool paused;
	bool fullscreen;
	Input input;

	Player player;
	pauseMenu pM;
};
