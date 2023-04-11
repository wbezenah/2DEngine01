#pragma once

#include <SDL.h>
#include <map>
#include <vector>
#include <iostream>

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

	void updateButtonPositions(int windowWidth, int windowHeight) {
		int nButtons = this->menuButtons.size();
		if (nButtons == 0) { return; }
		int nAbove = nButtons / 2;
		int nBelow = nButtons - nAbove;
		int winHeightMid = UIconst::buttonGap + (windowHeight / 2);

		for (int i = 0; i < nAbove; i++) {
			auto& curr = this->menuButtons.at(i);
			int xPos = (windowWidth - curr.getWidth()) / 2;
			int yPos = winHeightMid - ((i+1) * UIconst::buttonGap) - ((i+1) * curr.getHeight());

			curr.moveTo(xPos, yPos);
		}
		for (int i = 0; i < nBelow; i++) {
			auto& curr = this->menuButtons.at(i + nAbove);
			int xPos = (windowWidth - curr.getWidth()) / 2;
			int yPos = winHeightMid + ((i) * UIconst::buttonGap) + ((i) * curr.getHeight());

			curr.moveTo(xPos, yPos);
		}
	}

private:
	std::map<std::string, UIconst::ButtonType> buttonTypes;
	std::vector<Button> menuButtons;
};