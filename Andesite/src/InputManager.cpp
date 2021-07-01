#include "pch.h"
#include "InputManager.h"
InputManager* InputManager::inputManagerInstance = nullptr;

InputManager::InputManager() {
	buttonSpace = new JumpCommand();
	buttonA = new MoveLeftCommand();
	buttonD = new MoveRightCommand();
	buttonS = nullptr;
	buttonW = nullptr;
}

InputManager::~InputManager() {
		delete buttonSpace;
		delete buttonA;
		delete buttonD;
}

// Get keyboard input state
Command* InputManager::handleKeyInput(const Uint8* state) {
	if (state[SDL_SCANCODE_A]) {
		return buttonA;
	}

	else if (state[SDL_SCANCODE_SPACE])
	{
		return buttonSpace;
	}

	else if (state[SDL_SCANCODE_D])
	{
		return buttonD;
	}

	return NULL;



	// Original input code
	/*if (state[SDL_SCANCODE_A])
	{
		std::cout << std::get<0>(player.getSpeed()) << std::endl;
		player.setSpeed(1.5f, 0.0f);
		std::cout << std::get<0>(player.getSpeed()) << std::endl;
		std::cout << "Move Left" << std::endl;
		if (state[SDL_SCANCODE_SPACE])
			std::cout << "Jump LEFT" << std::endl;
	}
	else if (state[SDL_SCANCODE_D])
	{
		std::cout << "Move Right" << std::endl;
		if (state[SDL_SCANCODE_SPACE])
			std::cout << "Jump Right" << std::endl;
	}
	else if (state[SDL_SCANCODE_SPACE])
	{
		std::cout << "Jump" << std::endl;
	}
	else if (state[SDL_SCANCODE_ESCAPE])
	{
		std::cout << "ESC" << std::endl;
	}*/


	/*if (type == SDL_KEYDOWN)
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			std::cout << "LEFT PRESSED" << std::endl;
			break;
		case SDLK_d:
			std::cout << "RIGHT PRESSED" << std::endl;
			break;
		case SDLK_SPACE:
			std::cout << "JUMP PRESSED" << std::endl;
			break;
		case SDLK_SPACE&& SDLK_a:
			std::cout << "LEFT JUMP" << std::endl;
			break;
		case SDLK_ESCAPE:
			std::cout << "ESCAPE PRESSED" << std::endl;
			break;
		}
	else if (type == SDL_KEYUP)
		std::cout << "UP" << std::endl;*/
}
