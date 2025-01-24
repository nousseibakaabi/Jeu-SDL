
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "entitesecondaire.h"
   int main ()
{
//DECLARATION DES VARIABLES
    back b;
    Ennemi e;
    hero h;
    int done =1;
    int l,f;   // collision 1 ou 0
int d=e.position.x-h.poshero.x;

    SDL_Event event;
    SDL_Surface *screen =NULL;
    SDL_Init(SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(1200,800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF|SDL_RESIZABLE);
//INITIALISATION DU BACK & ENTITEES SECONDAIRES & HERO
      initialiser_back(&b);
      e = initEnnemi (e);
      h = inithero(h);
//LOADING DU SON
       if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
       {
            printf("NO AUDIO %s\n",Mix_GetError());
        }
        Mix_Music* music1;
        music1= Mix_LoadMUS("music.mp3");
        Mix_PlayMusic(music1,-1);
//LOAP
  while (done)
  {
 //AFFICHAGE DU BACK & ENTITES SECONDAIRES & HERO
        affiche_back(b,screen);
SDL_BlitSurface(h.hero, NULL, screen, &h.poshero);
        afficherEnnemi (e, screen);
        //ANIMATION DES ENTITES SECONDAIRES
        e = animerEnnemi (e, l);
        //COLLISION BOUNDING BOX
        l = Collision_Bounding_Box (h, e);
        //DEPLACEMENT DES ES
e = deplacer (e, l);
        e=updateetat(e,h);
   if(SDL_PollEvent(&event))
    {
     switch(event.type)
{
case SDL_QUIT:
done = 0;
break;

case SDL_KEYDOWN :
switch(event.type)
   {

case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_RIGHT:
h.poshero.x+= 15;
break;

case SDLK_LEFT:
h.poshero.x-= 15;
break;

}
   }

}
   }

        //MISE A JOUR DE L'ECRAN
        SDL_Flip(screen);
}

SDL_FreeSurface(screen);
//SDL_FreeSurface(b.img_back);
SDL_FreeSurface(h.hero);
SDL_Quit();

return 0;
}
