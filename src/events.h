#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>

std::string listen_to_event(){

	std::string event_status = "playing";

	// Event listener
	while( SDL_PollEvent(&event) != 0)
	{
	    std::cout<<"Je suis dans la boucle "<<std::endl;

		/* Traitement de l'événement */
		switch (event.type) /* Quel événement avons-nous ? */
		{
			// Quit
			case SDL_QUIT:
				event_status="EXIT";
                return event_status;

			case SDL_KEYDOWN:
				fprintf(stdout, "Un appuie sur une touche :\n");
				fprintf(stdout, "\trépétition ? : %d\n",event.key.repeat);
				fprintf(stdout, "\tscancode : %d\n",event.key.keysym.scancode);
				fprintf(stdout, "\tkey : %d\n",event.key.keysym.sym);
				
				if ( event.key.keysym.scancode == SDL_SCANCODE_ESCAPE )
				{
					event_status="EXIT";
                    return event_status;
				}

				break;

			case SDL_KEYUP:
				fprintf(stdout, "Un relachement d'une touche :\n");
				fprintf(stdout, "\trépétition ? : %d\n",event.key.repeat);
				fprintf(stdout, "\tscancode : %d\n",event.key.keysym.scancode);
				fprintf(stdout, "\tkey : %d\n",event.key.keysym.sym);
				break;

			case SDL_MOUSEMOTION:
				fprintf(stdout, "Un déplacement de la souris :\n");
				fprintf(stdout, "\tfenêtre : %d\n",event.motion.windowID);
				fprintf(stdout, "\tsouris : %d\n",event.motion.which);
				fprintf(stdout, "\tposition : %d;%d\n",event.motion.x,event.motion.y);
				fprintf(stdout, "\tdelta : %d;%d\n",event.motion.xrel,event.motion.yrel);
				break;

			case SDL_MOUSEBUTTONUP:
				fprintf(stdout, "Un relachement d'un bouton de la souris :\n");
				fprintf(stdout, "\tfenêtre : %d\n",event.button.windowID);
				fprintf(stdout, "\tsouris : %d\n",event.button.which);
				fprintf(stdout, "\tbouton : %d\n",event.button.button);
				fprintf(stdout, "\tposition : %d;%d\n",event.button.x,event.button.y);
				event_status="click";
                return event_status;

			case SDL_MOUSEBUTTONDOWN:
				fprintf(stdout, "Un appuie sur un bouton de la souris :\n");
				fprintf(stdout, "\tfenêtre : %d\n",event.button.windowID);
				fprintf(stdout, "\tsouris : %d\n",event.button.which);
				fprintf(stdout, "\tbouton : %d\n",event.button.button);
				fprintf(stdout, "\tposition : %d;%d\n",event.button.x,event.button.y);
				event_status="click";
                return event_status;

			case SDL_MOUSEWHEEL:
				fprintf(stdout, "Roulette de la souris :\n");
				fprintf(stdout, "\tfenêtre : %d\n",event.wheel.windowID);
				fprintf(stdout, "\tsouris : %d\n",event.wheel.which);
				fprintf(stdout, "\tposition : %d;%d\n",event.wheel.x,event.wheel.y);
				break;

	
			case SDL_WINDOWEVENT:
				fprintf(stdout, "Un événement de fenêtre, sur la fenêtre : %d\n",event.window.windowID);
				// En théorie, ici, il faudrait faire un autre test ou switch pour chaque type de cet événement
				break;

		}
	}

    return event_status;
}
