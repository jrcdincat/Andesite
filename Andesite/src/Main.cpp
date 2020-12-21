#include "pch.h"
#include "Game.h"
#include "SDL_image.h"

int main(int argc, char*args[])
{
	int screenWidth = 640;
	int screenHeight = 480;
	bool fullscreen = false;
	int xPos = SDL_WINDOWPOS_UNDEFINED;
	int yPos = SDL_WINDOWPOS_UNDEFINED;

	// Create and Initialize Game
	Game* game = new Game();
	game->init("Andesite", xPos, yPos, screenWidth, screenHeight, fullscreen);
	
	// Game Loop
	while (game->running())
	{
		game->handleEvent();
		game->update();
		game->render();
		// SDL_Delay(10); need ? 
	} 

	delete game;
	return 0;
}