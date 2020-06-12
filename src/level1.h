#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>

/**
 * \fn game_introduction
 * \brief Game introduction shows a splashscreen for game score and menu 
 * \return std::string status : Ending game introduction status like "EXIT" or "Level1" 
 * */
std::string play_level1(SDL_Renderer* ren){

	if(TTF_Init() == -1)
	{
		std::cout << "TTF Init failed" << std::endl;
	}

	// Status
	std::string status = "Running";
	std::cout<<"Play level one"<<std::endl;

	//SDL 2.0 now uses textures to draw things but SDL_LoadBMP returns a surface
	//this lets us choose when to upload or remove textures from the GPU
	SDL_Surface *background = IMG_Load("assets/background.jpg");
	if (background == nullptr){
		std::cout << "IMG_Load Error: " << SDL_GetError() << std::endl;
		status = "EXIT";

	}

	//To use a hardware accelerated texture for rendering we can create one from
	//the surface we loaded
	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, background);
	//We no longer need the surface
	SDL_FreeSurface(background);
	if (tex == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		status = "EXIT";
	}


	// Score font
	TTF_Font *font = NULL;
	SDL_Surface *score_surface = NULL;
	SDL_Color black = {0, 0, 0};
	font = TTF_OpenFont("assets/font.ttf", 20);
	if(font==nullptr){
		std::cout << "Font is not found " << std::endl;
	}

	// Score
	int score = 0;
	const char* score_as_text = std::to_string(score).c_str(); 
	score_surface = TTF_RenderText_Blended(font, score_as_text, black);

	// Score texture
	SDL_Texture *score_texture = SDL_CreateTextureFromSurface(ren, score_surface);	

	// Free score surface
	SDL_FreeSurface(score_surface);

	// Score position
	int score_width;
	int score_height;
	SDL_QueryTexture(score_texture, nullptr, nullptr, &score_width, &score_height);

	// Score rect
	SDL_Rect score_rect, score_rect_pos;
	score_rect.w = score_width * 4;
	score_rect.h = score_height;
	score_rect.x = 0;
	score_rect.y = 0;
	score_rect_pos = score_rect;
	score_rect_pos.x = 640 - (score_width*10);
	score_rect_pos.y = 0 + score_height;

	while (status!="EXIT")
	{
		// SDL Delay to slow down...
		SDL_Delay(100);
		score+=1;
		score_as_text = std::to_string(score).c_str(); 
		score_surface = TTF_RenderText_Blended(font, score_as_text, black);

		// Score texture
		SDL_Texture *score_texture = SDL_CreateTextureFromSurface(ren, score_surface);	

		// Free score surface
		SDL_FreeSurface(score_surface);

		// Score position
		SDL_QueryTexture(score_texture, nullptr, nullptr, &score_width, &score_height);

		// Get event
		std::string event_status = listen_to_event();

		//First clear the renderer
		SDL_RenderClear(ren);

		//Draw the texture
		SDL_RenderCopy(ren, tex, NULL, NULL);
		SDL_RenderCopy(ren, score_texture, &score_rect, &score_rect_pos);

		//Update the screen
		SDL_RenderPresent(ren);


		// Quit
		if(event_status=="0" || event_status=="EXIT")
		{
			//Clean up our objects
			TTF_CloseFont(font);
			SDL_DestroyTexture(tex);
			SDL_RenderClear(ren);
			SDL_RenderPresent(ren);
			status = "EXIT";
			return status;
		}

		// Click 	
		else if(event_status=="click")
		{
			//Clean up our objects
			TTF_CloseFont(font);
			SDL_DestroyTexture(tex);
			SDL_RenderClear(ren);	
			SDL_RenderPresent(ren);
			status = "Level1";
			std::cout<<"LEVEL 1 !!"<<std::endl;
			return status;

		} 

	}

	return status;
}
