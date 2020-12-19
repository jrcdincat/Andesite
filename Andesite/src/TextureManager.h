#pragma once

class TextureManager {
public: 
	static SDL_Texture* LoadTexture(const char* file, SDL_Renderer* renderer);

};