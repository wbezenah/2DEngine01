#pragma once

#include "Game.h"
#include "GameObject.h"

class Button : public GameObject {
public:
	Button() = default;
	Button(SDL_Renderer* renderer, const char* texture_sheet, int xPos, int yPos, int width, int height, int scale) :
		GameObject(renderer, texture_sheet, xPos, yPos, width, height, scale) {}


	void click() {
		this->pressed = true;
	}

	bool checkPressed() { return this->pressed; }

private:
	bool pressed = false;
};