#include "pch.h"
#include "Game.h"
#include "SDL_image.h"
#include "TextureManager.h"

Game::Game()
{
	isRunning = false; 
	window = nullptr;
	renderer = nullptr;
}
Game::~Game()
{
	clean();
}

void Game::init(const char* TITLE, int xPos, int yPos, int w, int h, bool fullscreen)
{
	int isFullScreen = 0;
	int imgTypeFlag = IMG_INIT_PNG;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		if (fullscreen)
		{
			isFullScreen = SDL_WINDOW_FULLSCREEN_DESKTOP;
		}

		// Create Window
		window = SDL_CreateWindow(TITLE, xPos, yPos, w, h, isFullScreen);
		if (!window)
		{
			std::cout << "ERROR::GAME::INITIALIZE: Unable to create window." << std::endl;
			return; 
		}

		// Create Renderer
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (!renderer)
		{
			std::cout << "ERROR::GAME::INITIALIZE: Unable to create renderer." << std::endl;
			return; 
		}


		if (!(IMG_Init(imgTypeFlag) & imgTypeFlag))
		{
			std::cout << "ERROR::GAME:INTIALIZE: Unable to intialize SDL IMG: " << IMG_GetError() << std::endl;
			return;
		}

		SDL_SetRenderDrawColor(renderer, 50, 50, 50, SDL_ALPHA_OPAQUE);	
		isRunning = true; 
	}
	else 
	{
		SDL_Log("ERROR::GAME::INITIALIZE: Unable to initialize SDL: %s", SDL_GetError());
		isRunning = false; 
	}
}

void Game::handleEvent()
{
	SDL_Event event; 
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false; 
		break;
	default: 
		break;
	}
}

void Game::update()
{

}

void Game::render()
{
	const char* img_path = "src\\assets\\andesite_volcano_background.png";

	SDL_RenderClear(renderer);
	SDL_Texture* background = TextureManager::LoadTexture(img_path, renderer);
	SDL_RenderCopy(renderer, background, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(background);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::running()
{
	return isRunning;
}