#pragma once

#include <iostream>

class GameObject {
public:
	GameObject() {
		_x = 0;
		_y = 0;
	}
	void jump() {
		std::cout << "JUMPED" << std::endl;
	}
	void moveTo(int x, int y) {
		this->_x = x;
		this->_y = y;
		std::cout << "MOVED TO " << x << "," << y << std::endl;
	}
	int getX() { return this->_x; }
	int getY() { return this->_y; }

private:
	int _x, _y;
};

class Command {
public:
	virtual ~Command() {}
	virtual void execute(GameObject& obj) {}
};