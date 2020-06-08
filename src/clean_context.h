#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>

void Exit()
{
	TTF_Quit();
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
}


