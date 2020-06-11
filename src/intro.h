#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>

/**
 * \fn game_introduction
 * \brief Game introduction shows a splashscreen for game title and menu 
 * \return std::string status : Ending game introduction status like "EXIT" or "Level1" 
 * */
std::string game_introduction(SDL_Renderer* ren){

	if(TTF_Init() == -1)
	{
		std::cout << "TTF Init failed" << std::endl;
	}

	// Status
	std::string status = "Running";
	std::cout<<"Game introduction "<<std::endl;

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


	// Title font
	TTF_Font *font = NULL;
	SDL_Surface *title_surface = NULL;
	SDL_Color black = {0, 0, 0};
	font = TTF_OpenFont("assets/font.ttf", 90);
	if(font==nullptr){
		std::cout << "Font is not found " << std::endl;
	}

	// Title
	title_surface = TTF_RenderText_Blended(font, "SDL Game", black);

	// Title texture
	SDL_Texture *title_texture = SDL_CreateTextureFromSurface(ren, title_surface);	

	// Free title surface
	SDL_FreeSurface(title_surface);

	// Title position
	int title_width;
	int title_height;
	SDL_QueryTexture(title_texture, nullptr, nullptr, &title_width, &title_height);

	// Title rect
	SDL_Rect title_rect, title_rect_pos;
	title_rect.w = title_width;
	title_rect.h = title_height;
	title_rect.x = 0;
	title_rect.y = 0;
	title_rect_pos = title_rect;
	title_rect_pos.x = 640/3;
	title_rect_pos.y = 480/2 - title_height;

	while (status!="EXIT")
	{
		// Get event
		std::string event_status = listen_to_event();

		//First clear the renderer
		SDL_RenderClear(ren);

		//Draw the texture
		SDL_RenderCopy(ren, tex, NULL, NULL);
		SDL_RenderCopy(ren, title_texture, &title_rect, &title_rect_pos);

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
