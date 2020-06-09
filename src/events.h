#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>
#include "clean_context.h"

int listen_to_event(bool quit){
	
	int event_status = 0; 

	// Event listener
	while( SDL_PollEvent(&event) != 0)
	{

		// Event handler
		switch ( event.type )
		{

			// Quit
			case SDL_QUIT:
				quit = true;
				Exit();
				break;

				// Mouse button
			case SDL_MOUSEBUTTONDOWN:
				break;
		}
	}

	return event_status;
}
