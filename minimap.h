#ifndef map_H_INCLUDED
#define map_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
/**
* @struct minimap
* @brief struct for minimap
*/
typedef struct 
{	
	SDL_Surface *map ; /*!< Surface. */
	SDL_Rect pos_map; /*!< Rectangle*/
	SDL_Surface *mini_perso; /*!< Surface. */
	SDL_Rect perso_pos_map; /*!< Rectangle*/

}map;

	void initialiser_map (map *m,SDL_Surface *screen) ;
	void perso_map(map *m,personne *p);
	void affiche_map(map *m, SDL_Surface *screen);
	void free_minimap(map *m);
        void sauvegarder(int score,char nomjoueur[],char nomfichier[],int id);
	void meilleur(char nomfichier[],int score,char nomjoueur[]);
#endif

