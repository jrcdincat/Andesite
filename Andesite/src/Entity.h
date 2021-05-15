#pragma once
#include "SDL_image.h";

class Entity {
public:
	Entity(float xParam, float yParam, SDL_Texture* textureParam);
	~Entity();
	float getX();
	float getY();
	SDL_Texture* getTexture();
	SDL_Rect getCurrentFrame();
private: 
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};