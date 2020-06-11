#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>
#include "conf.h"

// Initialize SDL
SDL_Renderer* init()
{
	//SDL Renderer
	SDL_Renderer *ren;
	

	//Initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
	
		//Create window
		gWindow = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 
				SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}

		//Create a renderer that will draw to the window, -1 specifies that we want to load whichever
		//video driver supports the flags we're passing
		//Flags: SDL_RENDERER_ACCELERATED: We want to use hardware accelerated rendering
		//SDL_RENDERER_PRESENTVSYNC: We want the renderer's present function (update screen) to be
		//synchronized with the monitor's refresh rate
		ren = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (ren == nullptr){
			SDL_DestroyWindow(gWindow);
			std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
		}

	}	
	return ren;
};
