#include "pch.h"
#include "Game.h"
#include "Timer.h"
#include "SDL_image.h"

int main(int argc, char*args[])
{
	int screenWidth = 640;
	int screenHeight = 480;
	bool fullscreen = false;
	int xPos = SDL_WINDOWPOS_UNDEFINED;
	int yPos = SDL_WINDOWPOS_UNDEFINED;

	// Create and Initialize Game
	Game::GetInstance()->Init("Andesite", xPos, yPos, screenWidth, screenHeight, fullscreen);

	// Game Loop
	while (Game::GetInstance()->IsRunning() == true)
	{
 		Game::GetInstance()->HandleEvent();
		Game::GetInstance()->Update();
		Game::GetInstance()->Render();
		Timer::GetInstance()->Tick();
	} 

	delete Game::GetInstance();
	delete Timer::GetInstance();
	return 0;
}