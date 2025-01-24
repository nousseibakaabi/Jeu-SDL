
#include "map.h"


void initialiser_map (map *m,SDL_Surface *screen)
{
	m->map=IMG_Load("mini.png");
	m->pos_map.x =500;
	m->pos_map.y = 50;
	m->mini_perso=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,10,10,32,0,0,0,0);
	SDL_FillRect(m->mini_perso,NULL,SDL_MapRGB(screen->format,255,0,0));
	m->perso_pos_map.x=0;
	m->perso_pos_map.y=0;

}


void perso_map(map *m,personne *p)
{
	m->perso_pos_map.x=p->pos_perso.x*0.2+1+m->pos_map.x;
	m->perso_pos_map.y=p->pos_perso.y*0.2+m->pos_map.y; 
}



void affiche_map(map *m , SDL_Surface *screen)
{
	SDL_BlitSurface(m->map, NULL, screen,&m->pos_map);
	SDL_BlitSurface(m->mini_perso, NULL, screen,&m->perso_pos_map);
}

void free_minimap(map *m)
{
	SDL_FreeSurface(m->map);
        SDL_FreeSurface(m->mini_perso);
}



void sauvegarder(int score,char nomjoueur[],char nomfichier[],int id)
{
	FILE *f,*fnom;
        char nom[255];
	f=fopen(nomfichier, "a+");
	fnom=fopen("testnom.txt", "a+");

	if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
	
       }
	
       if(fnom==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
       }

 	fprintf(f, "%d\n", score);
	fprintf(fnom,"%d %s\n",id,nomjoueur);
				
	fclose(f);
	fclose(fnom);
}

void meilleur (char nomfichier[],int score,char nomjoueur[])
{
	FILE *f,*fnom;

        char nom[255];
    
	int id;
 	
	int t[50];

	int i=0;
	
    f = fopen("test.txt", "r");
 fnom = fopen("testnom.txt", "r");
    
        if(f==NULL)
	{
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
        }
	if(fnom==NULL)
	{
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }

while(fscanf(f,"%d\n",&t[i])==1)
{
	i++;
}
	


int meilleur=t[0],d=1;



for(int h=1;h<i;h++)
{	
	if(t[h]>meilleur)
	{	d=h+1;
		meilleur=t[h];
		
	}
	
}

char nomjoueurmeilleur[4];

while( fscanf(fnom, "%d %s\n",&id,nom)!=EOF)
{
	

	if(id==d)
	{
		strcpy(nomjoueurmeilleur,nom);
		break;
		
	}

}


         printf("meilleur score: %d \n",meilleur);

         printf("meilleur jeouer: %s \n ",nomjoueurmeilleur);
    	 fclose(f);
	 fclose(fnom);
}



