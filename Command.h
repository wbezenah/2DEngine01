#pragma once

#include <iostream>

#include "GameObject.h"

class Command {
public:
	virtual ~Command() {}
	virtual void execute(GameObject& obj) {}
};