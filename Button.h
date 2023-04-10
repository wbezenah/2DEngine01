#pragma once

#include "GameObject.h"

class Button : public GameObject {
public:
	Button() = default;
	Button(std::string name, SDL_Renderer* renderer, const char* texture_sheet, int xPos, int yPos, int width, int height, int scale) :
		GameObject(renderer, texture_sheet, xPos, yPos, width, height, scale), name(name) {}

	void moveTo(int x, int y) {
		this->position.x = x;
		this->position.y = y;
		//std::cout << "MOVED TO " << x << "," << y << std::endl;

		this->destination.x = this->position.x;
		this->destination.y = this->position.y;
	}
	bool isClicked(Vector2 clickPos) {
		return (clickPos.x >= this->position.x && clickPos.x <= (this->position.x + this->destination.w) &&
			clickPos.y >= this->position.y && clickPos.y <= (this->position.y + this->destination.h));
	}

	std::string getName() { return this->name; }

private:
	std::string name;
};