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
	float deltaTime = 0.0f;

	// Create and Initialize Game
	Game::GetInstance()->Init("Andesite", xPos, yPos, screenWidth, screenHeight, fullscreen);

	// Game Loop
	while (Game::GetInstance()->IsRunning() == true)
	{
 		Game::GetInstance()->HandleEvent();
		Game::GetInstance()->Update(deltaTime);
		Game::GetInstance()->Render();
		// SDL_Delay(10); need ? 
	} 
	delete Game::GetInstance();
	return 0;
}