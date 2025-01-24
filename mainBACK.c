/**
*@file main.c
*@brief Testing Program
@author Team C
@version 0.1
@date Apr 20, 2022
*
*Testing program for background scrolling 
*
*/
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "background.h"

int main(void)
{	
	int continuer=1;
	SDL_Surface *screen=NULL;
	background ba,bm;
	Personne perso;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	screen=SDL_SetVideoMode(749,247,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode:%s\n",SDL_GetError());
		return 1;
	}
		
	initBack(&ba);// back normal
	initBackMasque(&bm);//masque llcollision parfaite
	initialiserperso(&perso);
	while (continuer)
	{		
		deplacer_perso(&perso,event);
		afficherBack(bm,screen); //masque
 		collision(screen,&perso);
		SDL_PollEvent(&event);
     	switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
			case SDLK_RIGHT:
			     if ( collisionparfaite(screen,perso)==10)
                                {
				  scrolling(&ba,0);	//ymin normal	
				  scrolling(&bm,0);     //ymin masque
			        }		
                        break;

                        case SDLK_LEFT:
                             if ( collisionparfaite(screen,perso)==10)
                                 {
				   scrolling(&ba,1);//ysar normal
				   scrolling(&bm,1); //ysar masque
			         }			
                        break;

			case SDLK_UP:
		  	     if ( collisionparfaite(screen,perso)==10)
                                 {
                                    scrolling(&ba,2);	//lfou9 normal	
				    scrolling(&bm,2);   //lfou9 masque
				 }			 
                        break;

 			 case SDLK_DOWN:
 		  	      if ( collisionparfaite(screen,perso)==10)
                                    {
				      scrolling(&ba,3);		//louta normal
				      scrolling(&bm,3);  //louta masque
				    }			 
                        break;
	
      		 } 	
            break;
 	} 		
   animerBackground(&ba);	
   afficherBack2(ba,screen); //normal
   afficher_perso(screen,perso);	
   SDL_Flip(screen);
   SDL_Delay(100);
   }
   
   SDL_Quit();

	return 1;
}
