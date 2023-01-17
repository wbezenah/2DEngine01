#pragma once

#include "Command.h"
#include <iostream>

class MoveByCommand : public Command {
public:
	MoveByCommand() = default;
	MoveByCommand(int dx, int dy) : _dx(dx), _dy(dy) {

	}

	void execute(GameObject& obj) {
		obj.moveTo(obj.getX() + _dx, obj.getY() + _dy);
	}

private:
	int _dx, _dy;
};