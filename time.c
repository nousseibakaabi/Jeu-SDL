#include "time.h"



void Timer(int *td) 
{
    
   if( SDL_GetTicks() - *td >= 1000 )
    {
        *td= SDL_GetTicks() ;
    }
  
}


int initTexttime(Text* T)
{  
    int testfont;
    T->textSurface=NULL;
    T->positionText.x =0;
    T->positionText.y =0; 
    T->couleurTxt.r =255; 
    T->couleurTxt.g =255; 
    T->couleurTxt.b =255;
    strcpy(T->txt,"");
   
    testfont=loadFonttime(T,"angelina.TTF");
    
    return testfont;   
}


void inittemps(Time *t)
{   int test; 

	t->td=SDL_GetTicks();
	t->mm=0;
	t->ss=0;
	test=initTexttime(&t->temps);
   
}


int initTexttimeenig(Text* T)
{ int testfont;
    T->textSurface=NULL;
    T->positionText.x = 400;
    T->positionText.y = 10; 

    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 0; 
    T->couleurTxt.b = 0;
    strcpy(T->txt, "");
    
    testfont=loadFonttime(T,"angelina.TTF");
    
    return testfont;   
}



void inittempsenig(Time *t)
{   int test; 
	t->td=0;
	t->mm=0;
	t->ss=0;
	test=initTexttimeenig(&t->temps);
  
}




int loadFonttime(Text* T, char* font)
{
    if(TTF_Init() == -1) 
    {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }

    T->police= TTF_OpenFont(font,25);
    if (T->police == NULL)
    {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return -1;
    }
    return 0;
}

void update_time(Time* T)
{  
  int seconds;

    Timer(&T->td);

    seconds=T->td/1000;

    T->mm=seconds/60;

    T->ss=seconds % 60;

    if(T->mm<10&&T->ss<10)

       sprintf(T->temps.txt,"  time :0%d:0%d  ",T->mm,T->ss);

    else if(T->mm<10&&T->ss>10)

        sprintf(T->temps.txt," time :0%d:%d  ",T->mm,T->ss);

    else if(T->mm>10&&T->ss<10)

          sprintf(T->temps.txt," time :%d:0%d  ",T->mm,T->ss);
  
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);
}


void update_timeenig(Time* T,Time* T1)
{   int seconds;
    
    Timer(&T->td);
    
    T->td=SDL_GetTicks()-T1->td+1;

    seconds=T->td/1000;

    T->mm=seconds/ 60;

    T->ss=seconds % 60;

    if(T->mm<10&&T->ss<10)

       sprintf(T->temps.txt," time :0%d:0%d  ",T->mm,T->ss);

    else if(T->mm<10&&T->ss>10)

        sprintf(T->temps.txt," time :0%d:%d  ",T->mm,T->ss);

    else if(T->mm>10&&T->ss<10)

          sprintf(T->temps.txt," time :%d:0%d  ",T->mm,T->ss);

    else
         sprintf(T->temps.txt," time :%d:%d  ",T->mm,T->ss); 

    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);
}


void displaytime(Time T,SDL_Surface *screen)
{
    
     
     SDL_BlitSurface(T.temps.textSurface,NULL,screen,&(T.temps.positionText));

}


void freeTexttime(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}


