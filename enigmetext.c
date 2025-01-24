/**
* @file enigmetext.c
* @brief Testing Program.
* @author Dimensions
* @version 0.1
* @date Apr 20, 2022
*
* Testing program for enigme texte
*
*/

#include "enigmetext.h"
/**
* @brief pour initialiser l'enigme e .
* @param e enigme
* @param nom du fichier .
* @return Nothing
*/
void InitEnigme(enigme *e,char *nomfichier[]){   
 
	nomfichier[100];


	FILE *fquestionrep=NULL;
	
	
	e->pos_selected=0;
	e->background= IMG_Load("/home/code-yass/Bureau/Dimensions/fond_enigme1000.png");
	e->button= IMG_Load("/home/code-yass/Bureau/Dimensions/buttonn.png");
	e->button_s= IMG_Load("/home/code-yass/Bureau/Dimensions/buttonon.png");

	TTF_Init();


	SDL_Color couleur = {0,128,128}; 
SDL_Color couleurr = {255,255,255}; 
//SDL_Color couleurrv={0,128,0}; 

	(*e).police = TTF_OpenFont("/home/code-yass/Bureau/Dimensions/EXTRASerif-Italic.ttf", 40);
	e->police1 = TTF_OpenFont("/home/code-yass/Bureau/Dimensions/EXTRASerif-Italic.ttf", 20);
	  
	char questionn[50];
	
	srand(time(NULL)); 
	e->num_question=rand()%4;   

	while(e->num_question==0){
		srand(time(NULL));
		e->num_question=rand()%4;
	}
	 
	sprintf(*nomfichier,"enigme.txt"); 
	char reponse[50];

	int min,max,vrep;
    switch(e->num_question)
    {
    	case 1:
    	{
    		min=3;
    		max=5;
    		vrep=12;
    		 
    		break;
    	}
    	case 2:
    	{
    		min=6;
    		max=8;
    		vrep=13;
    		break;
    	}
    	case 3:
    	{
    		min=9;
    		max=11;
    		vrep=14;
    		break;
    	}
    }

	fquestionrep=fopen(*nomfichier,"r+");
	if(fquestionrep!=NULL){         

		int test=1;
		while (fgets(questionn, 50, fquestionrep) &&(test!=e->num_question)){ 
			test++;
		}		
		fclose(fquestionrep);
	}
	
	fquestionrep=fopen(*nomfichier,"r+");
	if(fquestionrep!=NULL){
	int testr=0;
	while (fgets((reponse), 50, fquestionrep) &&(testr<max)) 
                        {	
			
			if(testr>=min){
				e->reponses[testr-min]=TTF_RenderText_Blended(e->police1, reponse, couleurr); 
			}
			testr++;
		}
	fclose(fquestionrep);
	}
	
	fquestionrep=fopen(*nomfichier,"r+");
	if(fquestionrep!=NULL){
	int testrv=1;
	while (fgets((reponse), 50, fquestionrep)){
			
			if(testrv==vrep){ 
				printf("%s\n",reponse);
				e->reponses[2]=TTF_RenderText_Blended(e->police1, reponse, couleurr); 
			}
			testrv++;			
		}		
		fclose(fquestionrep);
	}
	
	

  

	srand(time(NULL));
	e->positionVraiReponse=rand()%4; 

	while(e->positionVraiReponse==0){
		srand(time(NULL));
		e->positionVraiReponse=rand()%4;
	}
	printf("%d\n",e->positionVraiReponse);


	e->question = TTF_RenderText_Blended(e->police, questionn, couleur);

	e->pos_question.x=195;
	e->pos_question.y=300;
 
	e->pos_reponse1.x=360;
	e->pos_reponse1.y=522;


	e->pos_reponse2.x=177;
	e->pos_reponse2.y=648;

	e->pos_reponse3.x=540;
	e->pos_reponse3.y=651;

	e->pos_reponse1txt.x=e->pos_reponse1.x+90;
	e->pos_reponse1txt.y=522+50;

	e->pos_reponse2txt.x=177+50;
	e->pos_reponse2txt.y=648+50;

	e->pos_reponse3txt.x=566+49;
	e->pos_reponse3txt.y=651+52;
	
	
	(*e).image_clock=IMG_Load("/home/code-yass/Bureau/Dimensions/hourrr.png");  

	e->pos_image_clock.x=165;
	e->pos_image_clock.y=300;
	
	e->single_Clock.w=129;
	e->single_Clock.h=220;
	e->single_Clock.x=0;
	e->single_Clock.y=0;

	e->clock_num=0;

 

}

/**
* @brief pour afficher l'enigme e .
* @param e enigme.
* @param la surface d'ecran.
* @return Nothing
*/
void afficherEnigme(enigme e,SDL_Surface *ecran){

	
		
	SDL_BlitSurface(e.background, NULL, ecran, NULL);
	SDL_Flip(ecran);
	AffichClock(e,ecran);

	SDL_BlitSurface(e.question, NULL, ecran, &e.pos_question);
	SDL_Flip(ecran);
	

	switch(e.positionVraiReponse){
		case 1:{

			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}	
			break;
		}
		case 2:{
			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}
			break;
		}
		case 3:{
			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:                       
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}

			break;
		}
	}
	
	SDL_Delay(100);
}
/**
* @brief pour la resolution de l'enigme e .
* @param e enigme .
* @param surface de l'ecran .
* @return Nothing
*/
void resoudre_enigme(enigme *e,SDL_Surface*ecran){

	SDL_Rect pos={113,400}; 
	if(e->positionVraiReponse==e->pos_selected)
	{
		printf("You win\n");
		SDL_Surface *youwin;
		youwin=IMG_Load("youwin .png");
		SDL_BlitSurface(youwin, NULL, ecran,&pos);
		SDL_Flip(ecran);
       
	}
	else
	{
		SDL_Surface *youlost;
		youlost=IMG_Load("youlost .png");
		SDL_BlitSurface(youlost, NULL, ecran, &pos);
		SDL_Flip(ecran);
		printf("You lost\n");
      
	}
	SDL_Delay(2000);

}
/**
* @brief pour afficher l'image de l'animation .
* @param e enigme .
* @param surface de l'ecran .
* @return Nothing
*/
void AffichClock(enigme e,SDL_Surface *ecran){
			
 		SDL_BlitSurface(e.image_clock,&(e.single_Clock), ecran, &e.pos_image_clock);
}
/**
* @brief pour l'animation .
* @param e enigme .
* @param surface de l'ecran .
* @return Nothing
*/
void animer(enigme *e,SDL_Surface *ecran){
		 	
	if (e->clock_num >=0 && e->clock_num <13) {
	e->single_Clock.x=e->clock_num * e->single_Clock.w;
	e->clock_num++;
	}
	
	if ( e->clock_num == 13) {
	//e->single_Clock.x=e->clock_num * e->single_Clock.w;
//	e->clock_num=0;
       SDL_Surface *gameover;
SDL_Rect pos1={-300,300}; 
		gameover=IMG_Load("gameoverr.png");

	SDL_BlitSurface(gameover, NULL, ecran, &pos1);

		SDL_Flip(ecran);
SDL_Delay(2000);
SDL_Quit();
	}
 
	 
}
/**
* @brief liberation de l'espace memoire .
* @param e enigme .
* @return Nothing
*/
void free_Surface_enigme(enigme e){

	SDL_FreeSurface(e.background);
	SDL_FreeSurface(e.question);
	SDL_FreeSurface(e.reponses[0]);
	SDL_FreeSurface(e.reponses[1]);
	SDL_FreeSurface(e.reponses[2]);
	SDL_FreeSurface(e.button);
	SDL_FreeSurface(e.button_s);
}



