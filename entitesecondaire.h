/**
* @struct entite secondaire
* @brief struct for entite secondaire
*/
#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
  SDL_Surface* image[3];/*!< Surface. */
  SDL_Surface* image2[3];/*!< Surface. */
  SDL_Surface* Hit; /*!< Surface. */
  SDL_Surface* imageActuel;/*!< Surface. */
  SDL_Rect position; /*!< Rectangle*/
  int frame;//la position qui prend l'ennemi
  int direction;//gauche ou droite 0:droite 1:gauche
  int speed;//speed=0 donc pas de mouvement
  int state;
}Ennemi;//entite1 le pirate

typedef struct
{
 SDL_Surface *hero;//l image de l hero
 SDL_Rect  poshero;//la position de l'hero dans l'ecran
}
hero;//personnage principale*/


typedef struct {
SDL_Surface *img_back;
 SDL_Rect pos_back;
Mix_Music* son_contenu;
}back;


void initialiser_back(back *B);
void affiche_back(back B, SDL_Surface* screen) ;
hero inithero( hero h);
Ennemi initEnnemi( Ennemi e);
void  afficherEnnemi ( Ennemi e, SDL_Surface* screen);
Ennemi animerEnnemi( Ennemi e, int l);//l c'est pour la collision en cas de collision on fait apparaitre l'image de hit
Ennemi deplacer( Ennemi e, int l);
int Collision_Bounding_Box( hero h, Ennemi e); //collision entre le pirate et l'hero
Ennemi updateEnnemistate(Ennemi e, int d, hero h , int l);
Ennemi updateetat(Ennemi e,hero h);

#endif
