#ifndef enigmetext_H_INCLUDED
#define enigmetext_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>

/**
* @struct enigme
* @brief struct for enigme
*/

typedef struct
{ 

	SDL_Surface *background; /*!< Surface du background */
	SDL_Surface *question;   /*!< Surface du question */
	SDL_Surface *reponses[4]; /*!< Surface de la reponse */
	SDL_Surface *button;    /*!< Surface du bouton non appuyé */
	SDL_Surface *button_s;   /*!< Surface du bouton appuyé */

	int pos_selected; /*!< la position de la souris*/
	SDL_Rect pos_question; /*!< position de la question*/
	SDL_Rect pos_reponse1; /*!< la position du bouton ou je vais coller la 1ere rep*/
	SDL_Rect pos_reponse2; /*!< la position du bouton ou je vais coller la 2eme rep*/
	SDL_Rect pos_reponse3; /*!< la position du bouton ou je vais coller la 3eme rep*/
	int num_question;  /*!< numero de question*/
	
	SDL_Rect pos_reponse1txt; /*!< position de la 1ere rep*/
	SDL_Rect pos_reponse2txt; /*!< position de la 2eme rep*/
	SDL_Rect pos_reponse3txt; /*!< position de la 3eme rep*/
	int vrai_reponse; /*!< numero de la vrai reponse*/
	int positionVraiReponse; /*!< la position de la vrai reponse*/
	TTF_Font *police; /*!< la police du question*/
	TTF_Font *police1; /*!< la police de les reponses*/
	
		
	SDL_Surface *image_clock;  /*!< la surface du clock*/
	SDL_Rect pos_image_clock; /*!< la position du clock*/
	
	SDL_Rect single_Clock; /*!< la position d'une seule image clock*/
	
	
	int clock_num;  /*!< numero du clock dans l'image*/

}enigme;

void InitEnigme(enigme *e,char *nomfichier[]);
void afficherEnigme(enigme e,SDL_Surface *ecran);
void AffichClock(enigme e,SDL_Surface *ecran);
void resoudre_enigme(enigme *e,SDL_Surface*ecran);
void animer(enigme *e,SDL_Surface *ecran);
void free_Surface_enigme(enigme e);
#endif
