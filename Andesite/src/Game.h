#pragma once
#include "Player.h"

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
	void handleKeyInput(const Uint8* state);
	bool isRunning;
	SDL_Window* window; 
	SDL_Renderer* renderer;
	Player player;
};