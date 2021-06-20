#pragma once
#include "IObject.h"
#include "Math.h"

class GameObject : public IObject {
public: 
	GameObject(std::string texID, int x, int y, int w, int h, SDL_RendererFlip flip = SDL_FLIP_NONE)
		:textureID(texID), width(w), height(h), renderFlip(flip) { 
		position.x = x; 
		position.y = y;
	};
	virtual ~GameObject() {};

	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;
	
protected:
	Vector2f position; 
	int width, height; 
	std::string textureID; 
	SDL_RendererFlip renderFlip; 
};