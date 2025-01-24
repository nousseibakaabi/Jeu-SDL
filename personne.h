
#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>




typedef struct Personne
{
	SDL_Surface *images[2][4]; 
	SDL_Rect position;
	int direction;
	int nbr_frame;
	/*
		0:droite
		1:gauche
	*/
	double vitesse,acceleration,vitesse_saut;

}Personne;

typedef struct  vie
{
	SDL_Surface *vie;
	int valeur_vie;
	SDL_Rect pos_spr,pos;
}vie;




void initPerso(Personne *p);

void afficherPerso(Personne p, SDL_Surface * screen);

void deplacerPerso (Personne *p,int dt);

void animerPerso (Personne* p);

void saut (Personne* p) ;

void initialiser_vie(vie *v);
void update_vie(vie *v);
void afficher_vie(vie *v,SDL_Surface *screen);





 #endif

