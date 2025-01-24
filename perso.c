#include "perso.h"

void initialiserperso(personne *p)
{	
	p->image_p=IMG_Load("mario.png");
	p->pos_perso.x=20;
	p->pos_perso.y=135;
	
}

void afficher_perso(SDL_Surface *screen,personne p)
{	
	SDL_BlitSurface(p.image_p,NULL,screen,&p.pos_perso);
}

void deplacer_perso(personne *p,SDL_Event event)
{	
	SDL_PollEvent(&event);
         switch(event.type)
            {
                case SDL_KEYDOWN:
                       switch(event.key.keysym.sym)
                        {
                        
                        case SDLK_UP:
                            p->pos_perso.y=p->pos_perso.y-20;
                            break;
                        case SDLK_DOWN:
                            p->pos_perso.y=p->pos_perso.y+20;
                            break;
                        case SDLK_RIGHT:
                            p->pos_perso.x=p->pos_perso.x+20;
                            break;
                        case SDLK_LEFT:
                             p->pos_perso.x=p->pos_perso.x-20;

                            break;
                        }
                 break;
             }
}
void free_perso(personne p)
{
	SDL_FreeSurface(p.image_p);
}

