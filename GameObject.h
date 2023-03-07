#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Vector2.h"

class GameObject {
public:
	GameObject() = default;
	GameObject(SDL_Renderer* renderer, const char* texture_sheet, int xPos, int yPos, int width, int height, int scale) {
		this->position = Vector2(xPos, yPos);

		SDL_Surface* tempSurface = IMG_Load(texture_sheet);
		if (!tempSurface) {
			std::cout << ">> FAILED TO LOAD IMAGE" << std::endl;
		}
		this->texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
		if (!this->texture) {
			std::cout << ">> FAILED TO CREATE TEXTURE" << std::endl;
			std::cout << "   " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(tempSurface);

		this->source = SDL_Rect();
		this->source.x = this->source.y = 0;
		this->source.w = width;
		this->source.h = width;

		this->destination = SDL_Rect();
		this->destination.x = this->position.x;
		this->destination.y = this->position.y;
		this->destination.w = width * scale;
		this->destination.h = height * scale;
	}
	virtual void space() {}
	virtual void moveTo(int x, int y) {}

	Vector2 getPosition() { return this->position; }
	int getWidth() { return this->destination.w; }
	int getHeight() { return this->destination.h; }

	void render(SDL_Renderer* renderer) {
		int flag = SDL_RenderCopy(renderer, this->texture, &this->source, &this->destination);
		if (flag != 0) {
			std::cout << ">> FAILED TO RENDER OBJECT\n   " << SDL_GetError() << std::endl;
		}
	}

protected:
	Vector2 position;
	SDL_Texture* texture;
	SDL_Rect source;
	SDL_Rect destination;
};
