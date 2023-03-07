#pragma once

#include "Command.h"

class ClickCommand : public Command {
public:
	void execute(GameObject& obj) {
		obj.click();
	}
};