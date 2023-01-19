#pragma once

class Vector2 {
public:
	Vector2() = default;
	Vector2(int x, int y) {
		this->x = x;
		this->y = y;
	}
	
	int x;
	int y;
};