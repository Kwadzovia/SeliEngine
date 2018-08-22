#include "Game.hpp"

SDL_Texture* player_texture = NULL;
SDL_Rect srcRect, destRect;

Game::Game()
{

}


Game::~Game()
{
}

void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen == true)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_INIT_EVERYTHING < 0)
	{
		printf("ERROR: Issue initializing, SDL ERROR: %s", SDL_GetError());
	}
	else
	{
		isRunning = true;
		window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
		if (window == NULL)
		{
			printf("ERROR: WINDOW NOT INITIALIZED");
			isRunning = false;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL)
		{
			printf("ERROR: RENDERER NOT INITIALIZED");
			isRunning = false;
		}
		else
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		SDL_Surface*  tempSurface = IMG_Load("assets/seli.png");
		player_texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update()
{
	destRect.w = 250;
	destRect.h = 250;
	destRect.x = cnt;
	cnt++;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//render choices
	SDL_RenderCopy(renderer,player_texture,NULL,&destRect);

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	window = NULL;
	renderer = NULL;

	SDL_Quit();
	printf("Quit Successful.");
}