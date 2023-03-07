#pragma once

#include "Command.h"

class ClickCommand : public Command {
public:
	ClickCommand(Vector2 pos) {
		this->clickPos = pos;
	}
	void execute(GameObject& obj) {
		obj.click(this->clickPos);
	}

private:
	Vector2 clickPos;
};