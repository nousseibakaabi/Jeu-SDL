/**
* @file entitesecondaire.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 20, 2022
*
* Testing program for entite secondaire *
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "entitesecondaire.h"
/**
* @brief To initialize the background b .
* @param b the back
* @return Nothing
*/
void initialiser_back(back *B)
 {
      (*B).img_back=IMG_Load("back.png");
         if((*B).img_back==NULL)
           {
            printf("loading error ! %s\n", SDL_GetError());
          return;
           }
        (*B).pos_back.x=0;
        (*B).pos_back.y=0;
  }


void affiche_back(back B, SDL_Surface* screen)
 {
   SDL_BlitSurface(B.img_back,NULL,screen,&B.pos_back);
 }
/**
* @brief To initialize the ennemy .
* @param e the Ennemi
* @return Ennemi
*/

Ennemi initEnnemi( Ennemi e)
{
  e.image[0]=IMG_Load("bochra21.png");
  e.image[1]=IMG_Load("bochra22.png");
  e.image[2]=IMG_Load("bochra23.png");
  e.Hit=IMG_Load("imagedehit.png");

  e.image2[0]=IMG_Load("bochra11.png");
  e.image2[1]=IMG_Load("bochra12.png");
  e.image2[2]=IMG_Load("bochra13.png");
  e.imageActuel=e.image[0];

  e.position.x= 500;
  e.position.y= 250;

  e.position.h= 736;
  e.position.w= 370;

  e.speed=1;
  e.frame=0;//kifah yemchi puisque teswira tetbdl
  e.direction=0; //0 : droite , 1 : gauche
  e.state=0; // initaliser a waiting  0 // following  1 // attacking 2
  return e;
}



/**
* @brief To initialize the Hero.
* @param h the Hero
* @return hero
*/


hero inithero(hero h)
{
 h.hero=IMG_Load("hero.png");

 h.poshero.x=50;
h.poshero.y=300;
//h.poshero.h=736;
//h.poshero.w=370;
return h;
}
/**
* @brief To show the ennemy.
* @param e the Ennemi
* @param screen the screen
* @return nothing
*/

void afficherEnnemi(Ennemi e,SDL_Surface* screen)
{
  SDL_BlitSurface(e.imageActuel,NULL,screen,&e.position);//(image à copier,region a copier,surface destinataire ecran ,emplacement sur l'ecran)
}


/**
* @brief To animate the ennemy.
* @param e the Ennemi
* @param l
* @return Ennemi
*/

Ennemi animerEnnemi(Ennemi e, int l)
{
  if (e.frame==2) //statut avec derniere image
  {
    e.frame=0;//statut avec premiere image
  }

  else
  e.frame++;// incrementation des images

if (e.direction== 0) //droite
  e.imageActuel=e.image[e.frame];//on va charger les differentes images
else if(e.direction== 1)
e.imageActuel=e.image2[e.frame];//gauche
  if(l==1)//il y a collision
    e.imageActuel=e.Hit;//charger l'image de hit en cas de collision
  return e;
}



/**
* @brief To move ennemy.
* @param e the Ennemi
* @param l
* @return Ennemi
*/

Ennemi deplacer( Ennemi e, int l)
{

  int PosMax=1100;//pos maximale qu'il ne faut pas depasser
  int PosMin=0;//pos minimale qu'il ne faut pas depasser
if (l ==1)
{
e.direction=0;
}
 if (e.direction==0 && e.position.x <PosMax)
 e.position.x+= e.speed;//incrementation du pos vers la droite

 else if (e.position.x == PosMax)//rebourse le chemin
 e.direction=1;

 if (e.direction==1 && e.position.x>0)
 e.position.x-= e.speed ;//decrementation du pos vers la gauche

 else if (e.position.x== 0)//rebourse le chemin
 e.direction=0;
  return e;
}


/**
* @brief To Collision_BB.
* @param e the Ennemi
* @param h the Hero
* @return integer
*/

int Collision_Bounding_Box(hero h, Ennemi e )
{
    int col=0;
   if ((h.poshero.x + h.poshero.w< e.position.x) || (h.poshero.x>  e.position.x +  e.position.w) ||
(h.poshero.y + h.poshero.h<  e.position.y) || (h.poshero.y>  e.position.y +  e.position.h ))


col = 0 ;// pas de collision
else

col= 1; // collision

return col;
}

Ennemi updateetat(Ennemi e, hero h)
{
  int d=e.position.x-(h.poshero.x+h.poshero.w);
  int s1=600;
  int s2=100;
  if (d>s1)
  e.state=0;
  else
  if ((s2<d)&&(d<=s1))
   e.state=1;
  else
  if ((0<d)&&(d<=s2))
 e.state=2;
 return e;
}

 Ennemi updateEnnemistate( Ennemi e , int d, hero h, int l)
 {

   switch(e.state)
   {
case 0: // waiting
e=animerEnnemi(e,l);
break;

case 1: //following

e=animerEnnemi(e, l);
e=deplacer(e,l);

break;

case 2: // attacking

e=animerEnnemi(e, l);
e=deplacer(e,l);

break;

  }
    e=updateetat(e,h);
return   e;
}
