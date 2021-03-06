#pragma once
#include "Entity.h"
#include "Game.h"
#include <map>
class TextureManager {
public: 
	~TextureManager();
	static TextureManager* GetInstance() { return textureManagerInstance = (textureManagerInstance != nullptr) ? textureManagerInstance : new TextureManager(); }
	bool LoadTexture(std::string id, std::string filename);
	static void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	static void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void RemoveTexture(std::string id);
	void Clean();

private: 
	TextureManager() {}
	std::map<std::string, SDL_Texture*> textureMap;
	static TextureManager* textureManagerInstance;
};