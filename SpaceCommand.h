#pragma once

#include "Command.h"

class JumpCommand : public Command {
public:
	void execute(GameObject& obj) {
		obj.space();
	}
};