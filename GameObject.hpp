#pragma once
#include "Game.hpp"
#include <string>

class GameObject
{
public:
	GameObject(const char* textureSheet, SDL_Renderer* rend, int x, int y);
	~GameObject();

	void update();
	void render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	SDL_Renderer* renderer;
};

