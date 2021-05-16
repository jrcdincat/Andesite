#include "pch.h"
#include "Entity.h"

Entity::Entity(Vector2f posParam, SDL_Texture* textureParam)
	:position(posParam), texture(textureParam) 
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

Vector2f& Entity::getPos()
{
	return position;
}

SDL_Texture* Entity::getTexture() 
{
	return texture;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}