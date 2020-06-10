#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>

std::string play_level1(){
	
	// Status
	std::string status = "Running"; 
	std::cout<<"Playing level one"<<std::endl;
	while (status!="EXIT")
	{
		// Get event
		std::string event_status = listen_to_event();

		// Quit
		if(event_status=="0" || event_status=="EXIT")
		{
			status = "EXIT";
		}

	}

	return status;
}
