#include "Game.h"

Game::Game() {
	this->window = nullptr;
	this->renderer = nullptr;
	this->running = false;
	this->fullscreen = false;
}

Game::~Game() {

}

/*
*	void _init_
*	initializes a Game object by createing a window and renderer.
*/
void Game::_init_(const char* windowTitle, int windowX, int windowY, int windowWidth, int windowHeight, bool fullscreen)
{	
	// Begin initialization by initializing SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << ">> SDL Initialized Properly" << std::endl;
		
		// Initialize Window
		this->fullscreen = fullscreen;
		this->window = SDL_CreateWindow(windowTitle, windowX, windowY, windowWidth, windowHeight, this->fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
		if (this->window) {
			std::cout << ">> Window Initialized Properly" << std::endl;
		}
		else {
			std::cout << ">>! Window FAILED TO INITIALIZE" << std::endl;
		}

		//Initialize Renderer
		this->renderer = SDL_CreateRenderer(this->window, -1, 0);
		if (this->renderer) {
			SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
			std::cout << ">> Renderer Initialized Properly" << std::endl;
		}
		else {
			std::cout << ">>! Renderer FAILED TO INITALIZE" << std::endl;
		}

		//Game is running
		this->running = true;
	}
	else {
		std::cout << ">>! SDL FAILED TO INITIALIZE" << std::endl;
	}
}

GameObject obj;
void Game::handleEvents() {
	this->input.begin();

	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		this->running = false;
		break;
		
	case SDL_KEYUP:
		input.keyUp(event);
		break;

	case SDL_KEYDOWN:
		input.keyDown(event);
		break;

	default:
		break;
	}

	Command* command = input.getCommand();
	//Check if input processes key as an object command
	if (command) {
		command->execute(obj);
	}
	//If not an object command, check for game command
	if (input.wasPressed(SDL_SCANCODE_ESCAPE)) {
		this->running = false;
	}
	else if (input.wasPressed(SDL_SCANCODE_F11)) {
		this->fullscreen = !this->fullscreen;
		SDL_SetWindowFullscreen(this->window, this->fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
		std::cout << ">> TOGGLED WINDOW FULLSCREEN: " << (this->fullscreen ? "ON" : "OFF") << std::endl;
	}
}

void Game::updateGame() {
	SDL_RenderClear(this->renderer);

	SDL_RenderPresent(this->renderer);
}

void Game::render() {

}

void Game::clean() {
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return this->running;
}