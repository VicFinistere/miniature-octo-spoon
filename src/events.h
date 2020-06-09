#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>

int listen_to_event(bool quit){
	
	int event_status = 100; 

	// Event listener
	while( SDL_PollEvent(&event) != 0)
	{

		// Event handler
		switch ( event.type )
		{

			// Quit
			case SDL_QUIT:
				event_status=0;
				break;

				// Mouse button
			case SDL_MOUSEBUTTONDOWN:
				break;
		}
	}

	return event_status;
}
