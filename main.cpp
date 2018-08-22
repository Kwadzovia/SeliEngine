#include "Game.hpp"

Game game;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;


	game.init("SeliEngine_1.0", 0, 0, 1280, 720, false);
	while (game.running())
	{
		frameStart = SDL_GetTicks();
		
		game.handleEvents();
		game.update();
		game.render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
		
	}
	game.clean();



	return 0;
}