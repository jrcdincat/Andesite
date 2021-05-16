#include "pch.h"
#include "SDL_image.h"
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* file, SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(file);

	if (!surface)
	{
		std::cout << "TEXTUREMANAGER::LOADTEXTURE::IMG_Load Failed: " << IMG_GetError() << std::endl;
		exit(1);
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (!texture)
	{
		std::cout << "TEXTUREMANAGER::LOADTEXTURE::SDL_CreateTextureFromSurface Failed: " << IMG_GetError() << std::endl;

		exit(1);
	}

	SDL_FreeSurface(surface);
	surface = NULL;

	return texture;
}

void TextureManager::renderTexture(Entity& entity, SDL_Renderer* renderer)
{
	SDL_Rect sourceRect;
	sourceRect.x = entity.getCurrentFrame().x; 
	sourceRect.y = entity.getCurrentFrame().y;
	sourceRect.w = entity.getCurrentFrame().w;
	sourceRect.h = entity.getCurrentFrame().h;

	SDL_Rect destinationRec; 
	destinationRec.x = entity.getPos().x;
	destinationRec.y = entity.getPos().y;
	destinationRec.w = entity.getCurrentFrame().w;
	destinationRec.h = entity.getCurrentFrame().h;
	
	SDL_RenderCopy(renderer, entity.getTexture(), &sourceRect, &destinationRec);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_Renderer* renderer,SDL_RendererFlip flip)
{
	SDL_Rect sourceRect = { width * frame, height * (row - 1), width, height };
	SDL_Rect destinationRect = { x, y, width, height };
	// SDL_RenderCopyEx(renderer, m_TextureMap[id], &sourceRect, &destinationRect, 0, nullptr, flip);
}