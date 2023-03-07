#pragma once

#include <iostream>
#include "GameObject.h"

class Player : public GameObject {
public:
	Player() = default;
	Player(SDL_Renderer* renderer, const char* texture_sheet, int xPos, int yPos, int width, int height, int scale) :
		GameObject(renderer, texture_sheet, xPos, yPos, width, height, scale) { }

	void space() {
		std::cout << ">> PLAYER PRESSED SPACE" << std::endl;
	}

	void moveTo(int x, int y) {
		this->position.x = x;
		this->position.y = y;
		std::cout << "MOVED TO " << x << "," << y << std::endl;

		this->destination.x = this->position.x;
		this->destination.y = this->position.y;
	}

private:

};