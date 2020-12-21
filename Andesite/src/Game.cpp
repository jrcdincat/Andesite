#include "pch.h"
#include "Game.h"
#include "SDL_image.h"
#include "TextureManager.h"
//#include "Player.h"

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
	const Uint8* state = SDL_GetKeyboardState(NULL);
	SDL_Event event; 
	SDL_PollEvent(&event);
	
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false; 
		break;
	case SDL_KEYDOWN: 
		handleKeyInput(state);
		break;
	case SDL_KEYUP:
		player.setSpeed(0.0f, 0.0f);
		break;
	//case SDL_KEYDOWN: 
		//handleKeyInput(SDL_KEYDOWN, event);
		//break;
	//case SDL_KEYUP:
		//handleKeyInput(SDL_KEYUP, event);
	default: 
		break;
	}
}

// Get keyboard input state
void Game::handleKeyInput(const Uint8* state) {

	
	if (state[SDL_SCANCODE_A])
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
	}


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