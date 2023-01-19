#pragma once

#include <iostream>

#include "GameObject.h"

class Command {
public:
	virtual void execute(GameObject& obj) {}
};