#pragma once

#include "GameObject.h"

class Button : public GameObject {
public:
	Button() = default;
	Button(SDL_Renderer* renderer, const char* texture_sheet, int xPos, int yPos, int width, int height, int scale) :
		GameObject(renderer, texture_sheet, xPos, yPos, width, height, scale) {}

	void moveTo(int x, int y) {
		this->position.x = x;
		this->position.y = y;
		std::cout << "MOVED TO " << x << "," << y << std::endl;

		this->destination.x = this->position.x;
		this->destination.y = this->position.y;
	}
private:
	
};