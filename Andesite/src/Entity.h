#pragma once
#include "SDL_image.h";
#include "Vector2f.h";

class Entity {
public:
	Entity(Vector2f posParam, SDL_Texture* textureParam);
	~Entity();
	Vector2f& GetPos();
	SDL_Texture* GetTexture();
	SDL_Rect GetCurrentFrame();

private: 
	Vector2f position;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};