#pragma once
#include "Entity.h"

class TextureManager {
public: 
	static SDL_Texture* LoadTexture(const char* file, SDL_Renderer* renderer);
	static void renderTexture(Entity &entity, SDL_Renderer* renderer);
	static void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
};