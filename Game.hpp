#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>



class Game
{
public:
	Game();
	~Game();

	void init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running()
	{
		return isRunning;
	}
private:
	SDL_Renderer * renderer = NULL;
	SDL_Window * window = NULL;
	bool isRunning;
	int cnt = 0;
};
