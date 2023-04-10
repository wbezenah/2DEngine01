#include "Game.h"

Game::Game() {
	this->window = nullptr;
	this->renderer = nullptr;
	this->running = false;
	this->paused = true;
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
			this->running = false;
			return;
		}
		SDL_SetWindowResizable(this->window, SDL_bool(true));
		//Initialize Renderer
		this->renderer = SDL_CreateRenderer(this->window, -1, 0);
		if (this->renderer) {
			SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
			std::cout << ">> Renderer Initialized Properly" << std::endl;
		}
		else {
			std::cout << ">>! Renderer FAILED TO INITALIZE" << std::endl;
			this->running = false;
			return;
		}
		IMG_Init(IMG_INIT_PNG);
		TTF_Init();

		//ADD MAIN MENU OBJECT
		int windowWidth;
		int windowHeight;
		SDL_GetWindowSize(this->window, &windowWidth, &windowHeight);
		//CALCULATE BUTTON POSITIONS
		int xPos = (windowWidth - 128) / 2;
		int y1 = (windowHeight / 2) - 64 - (UIconst::buttonGap / 2);
		int y2 = (windowHeight / 2) + (UIconst::buttonGap / 2);
		Button quitButton = Button("quit",this->renderer, "Content/QUIT_BUTTON.png", xPos, y2, 128, 64, objconst::MENU_SCALE);
		Button resumeButton = Button("resume",this->renderer, "Content/RESUME_BUTTON.png", xPos, y1, 128, 64, objconst::MENU_SCALE);
		
		this->pauseMenu.addButton(resumeButton, UIconst::resume);
		this->pauseMenu.addButton(quitButton, UIconst::quit);

		//ADD PLAYER OBJECT
		this->player = Player(this->renderer, "Content/OCTO1.png", 100, 100, 32, 32, objconst::SPRITE_SCALE);

		//Game is running
		this->paused = false;
		this->running = true;
		SDL_ShowCursor(SDL_DISABLE);
		std::cout << ">> DONE WITH INIT" << std::endl;
	}
	else {
		std::cout << ">>! SDL FAILED TO INITIALIZE" << std::endl;
	}
}

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
	
	case SDL_MOUSEBUTTONDOWN:
		if (this->paused && event.button.button == SDL_BUTTON(SDL_BUTTON_LEFT)) {
			Vector2 clickPos = Vector2(event.button.x, event.button.y);

			UIconst::ButtonType clickType = this->pauseMenu.checkClicks(clickPos);
			switch (clickType) {
			case UIconst::resume:
				this->paused = false;
				SDL_ShowCursor(SDL_DISABLE);
				break;
			case UIconst::quit:
				this->running = false;
				break;
			default:
				break;
			}
		}
		break;

	default:
		break;
	}

	Command* command;
	
	if (!this->paused) {
		//Check if input processes key as an object command
		command = input.getCommand();
		if (command) {
			command->execute(this->player);
			delete command;
		}
	}

	//If not an object command, check for game command
	if (input.wasPressed(SDL_SCANCODE_ESCAPE)) {
		if (this->paused) {
			std::cout << ">> TOGGLED PAUSE MENU: OFF" << std::endl;
			this->paused = false;
			SDL_ShowCursor(SDL_DISABLE);
		}
		else {
			std::cout << ">> TOGGLED PAUSE MENU: ON" << std::endl;
			this->paused = true;
			SDL_ShowCursor(SDL_ENABLE);
		}
	}
	else if (input.wasPressed(SDL_SCANCODE_F11)) {
		this->fullscreen = !this->fullscreen;
		SDL_SetWindowFullscreen(this->window, this->fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
		std::cout << ">> TOGGLED WINDOW FULLSCREEN: " << (this->fullscreen ? "ON" : "OFF") << std::endl;
	}
}

void Game::updateGame() {
	//SDL_RenderClear(this->renderer);
	if (this->paused) {
		this->updateButtonPositions();
	}
	//SDL_RenderPresent(this->renderer);
}

void Game::render() {
	SDL_RenderClear(this->renderer);

	this->player.render(this->renderer);

	if (this->paused) {
		this->pauseMenu.render(this->renderer);
	}

	SDL_RenderPresent(this->renderer);
}

void Game::clean() {
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

bool Game::isRunning() {
	return this->running;
}

bool Game::isPaused() {
	return this->paused;
}

SDL_Renderer* Game::getRenderer() {
	return this->renderer;
}

//checks if pos is within the rectangular bounds represented origin, width, and height
bool Game::checkWithin(Vector2 pos, Vector2 origin, int width, int height) {
	return (pos.x >= origin.x && pos.x <= (origin.x + width) &&
			pos.y >= origin.y && pos.y <= (origin.y + height));
}

void Game::updateButtonPositions() {
	int windowWidth;
	int windowHeight;
	SDL_GetWindowSize(this->window, &windowWidth, &windowHeight);
	this->pauseMenu.updateButtonPositions(windowWidth, windowHeight);
	//CALCULATE BUTTON POSITIONS
	//int xPos = (windowWidth - 128) / 2;
	//int y1 = (windowHeight / 2) - 64 - (UIconst::buttonGap / 2);
	//int y2 = (windowHeight / 2) + (UIconst::buttonGap / 2);
	//this->pM.quit.moveTo(xPos, y2);
	//this->pM.resume.moveTo(xPos, y1);
}