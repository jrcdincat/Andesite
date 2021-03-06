#include "pch.h"
#include "Game.h"
#include "Player.h"
#include "Timer.h"

Game* Game::gameInstance = nullptr;

Game::Game()
{
	keyState = nullptr;
	isRunning = false; 
	window = nullptr;
	renderer = nullptr;
	command = nullptr;
	gameInstance = nullptr;
	player = nullptr;
}
Game::~Game()
{
	Clean();
}

bool Game::Init(const char* TITLE, int xPos, int yPos, int w, int h, bool fullscreen)
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
			SDL_Log("Failed to create window: %s", SDL_GetError());
			return false; 
		}

		// Create Renderer
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (!renderer)
		{
			SDL_Log("Failed to create renderer: %s", SDL_GetError());
			return false; 
		}


		if (!(IMG_Init(imgTypeFlag) & imgTypeFlag))
		{
			SDL_Log("Failed to initialize SDL IMG: %s", IMG_GetError());
			return false;
		}
	}
	else 
	{
		SDL_Log("ERROR::GAME::INITIALIZE: Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	TextureManager::GetInstance()->LoadTexture("player_idle", "src/assets/images/hero/Sprites/Idle.png");
	TextureManager::GetInstance()->LoadTexture("player_run", "src/assets/images/hero/Sprites/Run.png");
	playerProperties = new Properties("player_idle", 100, 100, 200, 200);
	player = new Player(playerProperties); // add delete properties in destructor

	isRunning = true;
	return isRunning;
}

void Game::HandleEvent() {
	SDL_Event event; 
	SDL_PollEvent(&event);
	keyState = SDL_GetKeyboardState(NULL);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false; 
		break;
	case SDL_KEYDOWN: 

		std::cout << InputManager::GetInstance()->handleKeyInput(keyState) <<std::endl;
		command = InputManager::GetInstance()->handleKeyInput(keyState);
		std::cout << command << std::endl;
		if (command)
		{
			std::cout << "in command" << std::endl;
			command->execute(player);
		}
		break;
	case SDL_KEYUP:
		player->Idle();
		break;
	default: 
		break;
	}
}



void Game::Update() {
	float deltaTime = Timer::GetInstance()->GetDeltaTime();
	player->Update(deltaTime);
}

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, SDL_ALPHA_OPAQUE);

	const char* img_path = "src\\assets\\images\\Background.png";

	SDL_RenderClear(renderer);

	//TextureManager::GetInstance()->DrawFrame("player", 100, 100, 200, 200,0, 7);
	/*TextureManager::GetInstance()->Draw("chest", 100, 100, 256, 256);*/
	player->Draw();

	//SDL_Texture* background = TextureManager::LoadTexture(img_path, renderer);
	//Entity entity(Vector2f(0.0f,0.0f), background);
	//Entity entity1(Vector2f(20.0f,50.0f), background);
	//SDL_RenderCopy(renderer, background, NULL, NULL);
	//TextureManager::renderTexture(entity, renderer);
	//TextureManager::renderTexture(entity1, renderer);
	SDL_RenderPresent(renderer);
	//SDL_DestroyTexture(background);
}

void Game::Clean() {
	delete playerProperties; 
	delete player;
	delete InputManager::GetInstance();
	TextureManager::GetInstance()->Clean();
	delete TextureManager::GetInstance();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}
