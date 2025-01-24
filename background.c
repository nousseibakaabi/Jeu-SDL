/**
*@file background.c
*@brief Testing Program
@author Team C
@version 0.1
@date Apr 20, 2022
*
*Testing program for background scrolling 
*
*/
#include "background.h"
/**
*@brief To initialize the background 
*@param the background
*@return Nothing
*/
void initBackMasque (background *b)
{
//background
b->imgback=SDL_LoadBMP("lev11.bmp");
b->posback.x=0;
b->posback.y=0;

//camera
b->camera.x=0;
b->camera.y=0;
b->camera.w=SCREEN_W; 
b->camera.h=SCREEN_H;

}

void initBack (background *b)
{
//background2
b->imgback=SDL_LoadBMP("lev1.bmp");
b->posback2.x=0;
b->posback2.y=0;
//camera2
b->camera2.x=0;
b->camera2.y=0;
b->camera2.w=SCREEN_W; 
b->camera2.h=SCREEN_H;
//musique
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",Mix_GetError());
    }
b->son=Mix_LoadMUS("music.mp3"); 
//animation 
	b->image_fly=IMG_Load("fly.png");  
	b->pos_image_fly.x=300;
	b->pos_image_fly.y=20;
	
	b->single_fly.w=50;
	b->single_fly.h=400;
	b->single_fly.x=0;
	b->single_fly.y=0;

	b->fly_num=0;

}
/**
*@brief To show the background 
*@param the background
*@return Nothing
*/
void afficherBack (background b, SDL_Surface *ecran) //masque
{
SDL_BlitSurface(b.imgback,&b.camera,ecran,&b.posback);
}
void afficherBack2 (background b, SDL_Surface *ecran) //normal
{ 
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",Mix_GetError());
    }
b.son=Mix_LoadMUS("music.mp3");  
Mix_PlayMusic(b.son, -1);
SDL_BlitSurface(b.imgback,&b.camera2,ecran,&b.posback2);
displayFly(b,ecran);

}


SDL_Color getpixel(SDL_Surface *masque,int x,int y)
{	
	SDL_Color color;
	Uint32 col=0;
	char* pPosition=(char* ) masque->pixels;
	pPosition+= (masque->pitch * y);
	pPosition+= (masque->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,masque->format->BytesPerPixel);
	SDL_GetRGB(col,masque->format, &color.r, &color.g, &color.b);
	return (color);
}

int  collisionparfaite(SDL_Surface *masque,Personne p)
{	
	int tabx[7],taby[7],i;
	SDL_Color color1,color;
	color1.r = 0;
	color1.g = 0;
	color1.b = 0;
	tabx[0]=p.pos_perso.x;
	tabx[1]=(p.pos_perso.x)+((p.pos_perso.w)/2);
	tabx[2]=(p.pos_perso.x+p.pos_perso.w);
	tabx[3]=p.pos_perso.x;
	tabx[4]=p.pos_perso.x;
	tabx[5]=(p.pos_perso.x)+((p.pos_perso.w)/2);
	tabx[6]=(p.pos_perso.x+p.pos_perso.w);
	tabx[7]=(p.pos_perso.x+p.pos_perso.w);
	taby[0]=p.pos_perso.y;
	taby[1]=p.pos_perso.y;
	taby[2]=p.pos_perso.y;
	taby[3]=(p.pos_perso.y)+((p.pos_perso.h)/2);
	taby[4]=(p.pos_perso.y+p.pos_perso.h);
	taby[5]=(p.pos_perso.y+p.pos_perso.h);
	taby[6]=(p.pos_perso.y+p.pos_perso.h);
	taby[7]=(p.pos_perso.y)+((p.pos_perso.h)/2);
	
	for(i=0;i<8;i++)
	{
	color=getpixel(masque,tabx[i],taby[i]);
	if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
	{
		return i;

	}
	}
	return 10;
	
}	

void collision(SDL_Surface *masque,Personne *p)
{	int i;
	i=collisionparfaite(masque,*p);

	switch (i)
	{
		case 0 :p->pos_perso.y=p->pos_perso.y+10;
			break;
		case 1 :p->pos_perso.y=p->pos_perso.y+10;
			 break;
		case 2 :p->pos_perso.y=p->pos_perso.y+10;
			break;
		case 3 :p->pos_perso.x=p->pos_perso.x+10;
			break;
		case 4 :p->pos_perso.y=p->pos_perso.y-10;
			break;
		case 5 :p->pos_perso.y=p->pos_perso.y-10; 
			break;
		case 6 :p->pos_perso.y=p->pos_perso.y-10; 
			break;
		case 7 :p->pos_perso.x=p->pos_perso.x-10;
			break;
		

	}
}





void scrolling (background *b,int direction)
{
 const int h=1;
if (direction ==0)//ymin 
	{
          b->camera.x= b->camera.x+h;  //masque        
	   b->camera2.x=b->camera2.x+h; //normal
        }

else if (direction ==1) //ysar 
        {         
	b->camera.x=b->camera.x-h; //masque 
	b->camera2.x=b->camera2.x-h;  //normal
	}

else if (direction ==2)//lfou9  
         {
        b->camera.y= b->camera.y-h; //masque 

         b->camera2.y= b->camera2.y-h; //normal
	}

else if (direction ==3)//loutaa          
        {
         b->camera.y= b->camera.y+h; //masque 
	 b->camera2.y= b->camera2.y+h; //normal
	 } 

}


void displayFly(background b,SDL_Surface *ecran)
{	
   SDL_BlitSurface(b.image_fly,&(b.single_fly), ecran, &b.pos_image_fly);
}
void animerBackground(background *b)
{ 	
	if (b->fly_num >=0 && b->fly_num <4) 
           {
	     b->single_fly.x=b->fly_num * b->single_fly.w;
	     b->fly_num++;
	   }
	if ( b->fly_num == 4)
            {
	      b->single_fly.x=b->fly_num * b->single_fly.w;
	      b->fly_num=0;
	    }
	 
}
