#pragma once
#include "Command.h"

class InputManager {
public:
	InputManager();
	~InputManager();
	Command* handleKeyInput(const Uint8* state);

private: 
	Command* buttonA; 
	Command* buttonS;
	Command* buttonD;
	Command* buttonW;
	Command* buttonSpace;
};