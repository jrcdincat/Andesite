#pragma once
#include "SDL_image.h";
#include "Math.h";

class Entity {
public:
	Entity(Vector2f posParam, SDL_Texture* textureParam);
	~Entity();
	Vector2f& getPos();
	SDL_Texture* getTexture();
	SDL_Rect getCurrentFrame();
private: 
	Vector2f position;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};