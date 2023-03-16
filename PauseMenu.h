#pragma once

#include <SDL.h>
#include <map>
#include <vector>

#include "Constants.h"
#include "Button.h"

class PauseMenu {
public:
	PauseMenu(){
		
	}

	void render(SDL_Renderer* renderer) {
		for (Button b : this->menuButtons) {
			b.render(renderer);
		}
	}

	void addButton(Button b, UIconst::ButtonType bT) {
		menuButtons.push_back(b);
		buttonTypes.insert(std::pair<std::string, UIconst::ButtonType>(b.getName(), bT));
	}

	UIconst::ButtonType checkClicks(Vector2 pos) {
		for (Button b : this->menuButtons) {
			if (b.isClicked(pos)) {
				return this->buttonTypes.at(b.getName());
			}
		}
		return UIconst::missing;
	}

private:
	std::map<std::string, UIconst::ButtonType> buttonTypes;
	std::vector<Button> menuButtons;
};