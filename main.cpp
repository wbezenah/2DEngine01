#include <iostream>
#include <SDL.h>

#include "Constants.h"
#include "Game.h"

int main(int argc, char* argv[]) {
	Uint64 start;
	int timeElapsed;

	Game* game = new Game();
	game->_init_("ENGINE TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->isRunning()) {
		start = SDL_GetTicks64();

		game->handleEvents();
		game->updateGame();
		game->render();

		timeElapsed = SDL_GetTicks64() - start;

		if (gameconst::FRAME_DELAY > timeElapsed) {
			SDL_Delay(gameconst::FRAME_DELAY - timeElapsed);
		}
	}

	game->clean();

	return 0;
}