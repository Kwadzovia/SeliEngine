#include "GameObject.hpp"
#include "TextureManager.hpp"


GameObject::GameObject(const char* textureSheet, SDL_Renderer* rend, int x,  int y)
{
	renderer = rend;
	objTexture = TextureManager::LoadTexture(textureSheet, renderer);
	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{

}

void GameObject::update()
{
	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}


void GameObject::render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}