#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>
#include "intro.h"
#include "level1.h"

std::string play(std::string action)
{	
	if(action=="start"){
        std::cout<<"Play introduction in play method"<<std::endl;
		action = game_introduction();
	} else if(action=="Level1"){
		action = play_level1();
	}

	return action;
}
