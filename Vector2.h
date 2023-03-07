#pragma once

class Vector2 {
public:
	Vector2() = default;
	Vector2(int x, int y) {
		this->x = x;
		this->y = y;
	}

	bool operator==(const Vector2& vB) {
		return (this->x == vB.x && this->y == vB.y);
	}

	void zero() {
		this->x = 0;
		this->y = 0;
	}
	
	int x;
	int y;
};