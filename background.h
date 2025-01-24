#ifndef BACKGROUND_H_INCLUDE
#define BACKGROUND_H_INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
 #include "pres.h"
#define SCREEN_W 749
#define SCREEN_H 247
/**
*@struct Background 
*@brief struct for background
*/
typedef struct
{
	SDL_Surface *imgback; /*!< Rectangle*/  //zouz   
	SDL_Rect posback;   /*!< Surface*/       //masque 
	SDL_Rect posback2; //normal
	SDL_Rect camera; //masque
	SDL_Rect camera2;  //normal
	Mix_Music *son;
	SDL_Surface *image_fly;  
	SDL_Rect pos_image_fly; // fly lkol
	SDL_Rect single_fly;	// blka3baa 
	int fly_num;


}background;

void initBack (background *b); //normal
void initBackMasque (background *b); //masque

void afficherBack (background b, SDL_Surface *ecran); //masque
void afficherBack2 (background b,SDL_Surface *ecran);  //normal

SDL_Color getpixel(SDL_Surface *psurface,int x,int y); //traja3 couleur fi position x y 
int collisionparfaite(SDL_Surface *psurface,Personne perso); //traja3 win collision 
void collision(SDL_Surface *psurface,Personne *perso);

void scrolling (background *b,int direction);

void animerBackground(background *b);
void displayFly(background b,SDL_Surface *ecran);

#endif  
