/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for minimap
*
*/
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "time.h"
#include "minimap.h"
#include <string.h>

int main()
{	
		int continuer=1,done=1;

	SDL_Surface *screen,*backg,*backgm,*enig;

	SDL_Rect backg_pos,backgm_pos,enigpos;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);


	screen=SDL_SetVideoMode(748,250,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	if(screen==NULL)
	{
		printf("unable to set video mode:%s\n",SDL_GetError());
		return 1;
	}

	enig = IMG_Load("enigme.png");
	enigpos.x=0;
	enigpos.y=0;
	
	backg =IMG_Load("level2.png");
	backg_pos.x = 0;
	backg_pos.y = 0;
	


	Time temps;
	Time tempsenig;
	map m;
	personne p;
	
	inittemps(&temps);
	
	initialiser_map (&m,screen) ;
	initialiserperso(&p);
	
	SDL_Event event;
	
	while (continuer)
	{	
	SDL_PollEvent(&event);
        
	switch(event.type)
        {

         case SDL_QUIT:
            continuer=0;
            break;

        case SDL_KEYUP:

           
             switch(event.key.keysym.sym)
            {

            case SDLK_q:
               {
		while(done)
                 {
          
                inittempsenig(&tempsenig);
		update_timeenig(&tempsenig,&temps);

                screen=SDL_SetVideoMode(1000,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

		SDL_BlitSurface(enig,NULL,screen,&enigpos);

		displaytime(tempsenig,screen);

		SDL_Flip(screen);

		 if(tempsenig.ss==5)

		    { done=0;
                      screen=SDL_SetVideoMode(748,250,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
		    }
                
            

		  }

               }
                break ;
	    
	    }

           }	
		
		update_time(&temps);
		deplacer_perso(&p,event);

		perso_map(&m,&p);
		SDL_BlitSurface(backg,NULL,screen,&backg_pos);
		displaytime(temps,screen);
		
		
		affiche_map(&m,screen);
		afficher_perso(screen,p);
		SDL_Flip(screen);
		SDL_Delay(100);
	}
	
	sauvegarder(400,"raza","test.txt",4);
	char* nomjoueur;
	int score;
	meilleur ("test.txt",score,nomjoueur);
	freeTexttime(temps.temps);
	free_perso(p);
	SDL_Quit();
	return 0;
}

