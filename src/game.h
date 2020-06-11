#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>
#include "events.h"
#include "clean_context.h"
#include "level_manager.h"

void game_loop(SDL_Renderer* ren){
	
	// Game loop trace
	std::cout<<"Game loop"<<std::endl;
	
	// Game level
	std::string action = "start";
	while(action!="EXIT"){

		// Play requested action
		action = play(action, ren);
		std::cout<<action<<std::endl;
	}
	
	// Exit
	Exit();
}
