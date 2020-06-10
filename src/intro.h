#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>

std::string game_introduction(){

	// Status
	std::string status = "Running";
	std::cout<<"Game introduction "<<std::endl;

	while (status!="EXIT")
	{
		// Get event
		std::string event_status = listen_to_event();

		// Quit
		if(event_status=="0" || event_status=="EXIT")
		{
			status = "EXIT";
		}

		// Click 	
		else if(event_status=="click")
		{
			status = "Level1";
			std::cout<<"LEVEL 1 !!"<<std::endl;

		}

	}

	return status;
}
