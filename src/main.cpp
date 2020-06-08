#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>
#include "init_sdl.h"
#include "clean_context.h"



int main (int argc, char* argv[])
{
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	} else 
	{

		SDL_Surface *screen;
		screen = SDL_GetWindowSurface(gWindow);
		if(!screen)
		{
			printf("SDL_GetWindowSurface error: %s\n", SDL_GetError());
		}

		bool quit = false;
		//      SDL_Event e;

		while ( !quit )
		{
			while( SDL_PollEvent(&event) != 0)
			{
				switch ( event.type )
				{
					case SDL_QUIT:
						quit = true;
						Exit();
						break;
					case SDL_MOUSEBUTTONDOWN:
						break;
				}
			}
		}
	}
	return 0;
}
