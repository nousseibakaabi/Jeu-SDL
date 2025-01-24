#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include <time.h>
#include "enigmeif.h"

int main()
{
	int hauteur_fenetre = 800,largeur_fenetre = 1366,done=1,dt=0;
	SDL_Event event;	
	char *nomfichier[100];
	SDL_Init(SDL_INIT_VIDEO);
//creation de la fenetre 
	SDL_Surface *screen;
	 if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
 	screen=SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }
  
	SDL_WM_SetCaption("JEUX", NULL); 
// creation background
 	SDL_Surface *backg;
	SDL_Rect backg_pos;
	
	backg = IMG_Load("background.jpeg");
	backg_pos.x = 0;
	backg_pos.y = 0;

 //initialisation 
 
 	enigmeif ee;
	ee.d=1;
	generer(&ee);
	//printf("%d",ee.d),
	
	InitEnigme(&ee ,&nomfichier[100]);
 
 	 while (done)
	{ 
	SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                done = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
			
 		
			case SDLK_p:
				afficherEnigme(ee,screen);
			break;
 	
                }
                break;
       }
       
		SDL_BlitSurface(backg,NULL,screen,&backg_pos);
		SDL_Flip(screen);
 
       }
       
		SDL_FreeSurface(backg);
		SDL_Quit();

	return 0;
      
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


