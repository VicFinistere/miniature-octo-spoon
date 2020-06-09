#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>
#include "events.h"
#include "clean_context.h"

bool game_loop(){

	// Game loop
	bool quit = false;
	while ( !quit )
	{
		int event_status = listen_to_event(quit);
		if(event_status==0)
		{
			quit = true;
			Exit();
		}
	
	}

}
