#pragma once
#include "Player.h"
#include "Command.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "SDL_image.h"


class Game
{
public: 
	static Game* GetInstance() {
		return gameInstance = ( gameInstance != nullptr ) ? gameInstance : new Game();
	}
	~Game(); 

	bool Init(const char* TITLE, int xpos, int ypos, int w, int h, bool fullscreen);

	void HandleEvent();
	void Update(float deltaTime);
	void Render();
	void Clean();

	inline bool IsRunning() { return isRunning; }
	inline SDL_Renderer* GetRenderer() { return renderer; }

private:
	Game();
	bool isRunning;
	SDL_Window* window; 
	SDL_Renderer* renderer;
	Player player;
	Command* command;
	const Uint8* keyState;
	static Game* gameInstance;
};