#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>
#include "init_sdl.h"
#include "game.h"

// This SDL2 program is made using SDL Simple menu base template
// (https://discourse.libsdl.org/t/a-simple-sdl2-menu/26923)

int main (int argc, char* argv[])
{
	SDL_Renderer* ren = init();

	if(ren==nullptr)
	{
		// Init failed 		
		printf( "Failed to initialize!\n" );
	
	} else {

		// Screen
		SDL_Surface *screen;
		screen = SDL_GetWindowSurface(gWindow);
		if(!screen)
		{
			// Window surface error
			printf("SDL_GetWindowSurface error: %s\n", SDL_GetError());
		}
		
		game_loop(ren);
	}

	return 0;
}
