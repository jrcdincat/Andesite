#pragma once
#include "Player.h"
#include "Command.h"
#include "InputManager.h"

class Game
{
public: 
	Game();
	~Game(); 

	void init(const char* TITLE, int xpos, int ypos, int w, int h, bool fullscreen);
	void handleEvent();
	void update();
	void render();
	void clean();
	bool running();

	
	

private:
	bool isRunning;
	SDL_Window* window; 
	SDL_Renderer* renderer;
	Player player;
	Command* command;
	InputManager* inputManager; 
	const Uint8* keyState;
};