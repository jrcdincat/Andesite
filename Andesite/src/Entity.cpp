#include "pch.h"
#include "Entity.h"

Entity::Entity(float xParam, float yParam, SDL_Texture* textureParam)
	:x(xParam), y(yParam), texture(textureParam) 
{
	// Remove hardcode later
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32; // 32 pixels
	currentFrame.h = 32;
}
Entity::~Entity() 
{

}

float Entity::getX() 
{
	return x;
}

float Entity::getY() 
{
	return y;
}

SDL_Texture* Entity::getTexture() 
{
	return texture;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}