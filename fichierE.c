#include "fichierE.h"
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void init_enigme(Enigme *e, SDL_Surface *screen){

    e->imag= IMG_Load("back.png");
    e->pos_imag.x = 0;
    e->pos_imag.y = 0;
    
    
    e->num=0;
    e->etat=0;
    e->c =IMG_Load("win.png");
    e->w=IMG_Load("w.png");
    e->pos_correct.x = 0;
    e->pos_correct.y = 0;
    e->pos_wrong.x = 0;
    e->pos_wrong.y = 0;
    
    e->police=TTF_OpenFont("Ubuntu-MediumItalic.ttf",22 );
    e->r1 = NULL;
    e->pos_r1.x=202;
    e->pos_r1.y=315;

    e->r2 = NULL;
    e->pos_r2.x=395;
    e->pos_r2.y=315;

    e->r3 = NULL;
    e->pos_r3.x=204;
    e->pos_r3.y=395;
    
    e->r4= NULL;
    e->pos_r4.x=394;
    e->pos_r4.y=395;

    e->police_q=TTF_OpenFont("Ubuntu-MediumItalic.ttf",30 );

    e->qes = NULL;
    e->pos_qes.x=250;
    e->pos_qes.y=111;
  
}
void afficherEnigme(Enigme *e,SDL_Surface * screen){
      
       SDL_BlitSurface(e->imag,NULL,screen,&e->pos_imag); 
       SDL_BlitSurface(e->r1,NULL,screen,&e->pos_r1);
       SDL_BlitSurface(e->r2,NULL,screen,&e->pos_r2);
       SDL_BlitSurface(e->r3,NULL,screen,&e->pos_r3);
       SDL_BlitSurface(e->r4,NULL,screen,&e->pos_r4);
       SDL_BlitSurface(e->qes,NULL,screen,&e->pos_qes);
}

void genererEnigme(Enigme *e, char *nomfichier){

        FILE* fichier = NULL;
        char ques[100] ;
	char rep1[20] ;
	char rep2[20] ;
	char rep3[20] ;
	char rep4[20] ;
	char np[10];
	int c,l=1;
	SDL_Color Color={0,0,0};
	srand(time(0));
	do {
		e->num = rand()%9 ;
	}while ( e->num <1 || e->num > 9 );

	fichier = fopen("enigme","r");
	if ( fichier != NULL )
	{
		while ( c!=EOF && l < e->num)
		{
			c= fgetc(fichier);
			if ( c == '\n')
				l++;
		}
		fscanf(fichier,"%s %s %s %s %s %s",ques,rep1,rep2,rep3,rep4,np);
		fclose(fichier);
	}
	e->qes =TTF_RenderText_Blended(e->police_q,ques,Color);
	e->r1 =TTF_RenderText_Blended(e->police,rep1,Color);
	e->r2 =TTF_RenderText_Blended(e->police,rep2,Color);
	e->r3 =TTF_RenderText_Blended(e->police,rep3,Color);
	e->r4 =TTF_RenderText_Blended(e->police,rep4,Color);
	e->np=atoi(np);
	
}

void animerEnigme(Enigme *e, SDL_Surface *screen){

    background *b;
    anim *a;
    Mix_Music *music;
    
    music=Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(music, -1); 
    
    a->b1= IMG_Load("b1.png");
    a->pos_b1.x = 0;
    a->pos_b1.y = 0;
    
    a->b2= IMG_Load("b2.png");
    a->pos_b2.x = 0;
    a->pos_b2.y = 0;
    
    a->b3= IMG_Load("b3.png");
    a->pos_b3.x = 0;
    a->pos_b3.y = 0;
    
    a->b4= IMG_Load("b4.png");
    a->pos_b4.x = 0;
    a->pos_b4.y = 0;
    
    a->b5= IMG_Load("b5.png");
    a->pos_b5.x = 0;
    a->pos_b5.y = 0;
    
    a->b6= IMG_Load("b6.png");
    a->pos_b6.x = 0;
    a->pos_b6.y = 0;
    
    a->b7= IMG_Load("b7.png");
    a->pos_b7.x = 0;
    a->pos_b7.y = 0;
    
    a->b8= IMG_Load("b8.png");
    a->pos_b8.x = 0;
    a->pos_b8.y = 0;
    
    a->b9= IMG_Load("b9.png");
    a->pos_b9.x = 0;
    a->pos_b9.y = 0;
    
       SDL_BlitSurface(a->b1,NULL,screen,&a->pos_b1);
       SDL_BlitSurface(a->b2,NULL,screen,&a->pos_b2);
       SDL_BlitSurface(a->b3,NULL,screen,&a->pos_b3);
       SDL_BlitSurface(a->b4,NULL,screen,&a->pos_b4);
       SDL_BlitSurface(a->b5,NULL,screen,&a->pos_b5);
       SDL_BlitSurface(a->b6,NULL,screen,&a->pos_b6);
       SDL_BlitSurface(a->b7,NULL,screen,&a->pos_b7);
       SDL_BlitSurface(a->b8,NULL,screen,&a->pos_b8);
       SDL_BlitSurface(a->b9,NULL,screen,&a->pos_b9);
         
         
}
	

void resolution_enigme(Enigme *e,SDL_Surface* screen){

    SDL_Event event;
    int fin=1,np,rep=0,d=0;
   

   while(fin == 1)
    {  
    afficherEnigme(e,screen); 
    //animerEnigme(e,screen);
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            e->etat=0;
            fin=0;

            break;
            
        case SDL_MOUSEBUTTONDOWN:
        {
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:
            {
                if ( event.button.x>178 && event.button.x<343 && event.button.y>304 && event.button.y<359) 
                {     
			rep=1;
			d=1;
			
                }
                else if ( event.button.x>371 && event.button.x<543 && event.button.y>302 && event.button.y<359) 
                {     
			rep=2;
			d=1;
			
                }
                else if ( event.button.x>177 && event.button.x<352 && event.button.y>383 && event.button.y<443) 
                {     
			rep=3;
			d=1;
			
                }
                else if ( event.button.x>369 && event.button.x<543 && event.button.y>373 && event.button.y<445) 
                {     
			rep=4;
			d=1;
			
                }  
            }
        }
        }break;
        }         
     
       if ( rep == e->np && d==1 )
        {
            SDL_BlitSurface(e->c,NULL, screen, &e->pos_correct );
            e->etat=1;
            fin=0;
        }
        else if (rep!= e->np && d==1)
        {
            
            SDL_BlitSurface(e->w,NULL, screen, &e->pos_wrong );
            e->etat=0;
            fin=0;
        }
        
        SDL_Flip(screen);

}
 SDL_Delay(1500);
}


int charger(personne *p, background *b, Score *s ,char * nomfichier)
{
	int carac,caractereLu ;
	int ligne =0;
	FILE* fichier = fopen("savefile.txt","r");
	char data[6];
	int temp=0;
	if ( fichier != NULL )
	{
		carac = fgetc(fichier);
		if ( carac == EOF )
		{
			return 1; 
		}
		else
		{
			while ( caractereLu!=EOF )
			{
				switch ( ligne )
				{
					case 0:
						fscanf(fichier,"%s",data);
						temp = atoi(data);
						p->posSprite.x = temp;
					break;

					case 1:
						fscanf(fichier,"%s",data);
						temp = atoi(data);
						p->posSprite.y = temp;
					break;

					case 2:
						fscanf(fichier,"%s",data);
						temp = atoi(data);
						b->camera.x = temp;
					break;

					case 3:
						fscanf(fichier,"%s",data);
						temp = atoi(data);
						b->camera.y = temp;
					break;

					case 4:
						fscanf(fichier,"%s",data);
						temp = atoi(data);
						s->ScoreActuel= temp;
					break;
				}

				caractereLu = fgetc(fichier);
				if ( caractereLu == '\n')
					ligne++;

			}
				fclose(fichier);

		}
	}
	else
	{
		return 0;
	}

}


void sauvegarder (personne *p, background *b, Score *s ,char * nomfichier){

	FILE* fichier = fopen(nomfichier,"w");
	char data[6] ;
	int temp=0;
	char rl[2] = "\n";
	int i=0;

	for ( i = 0 ; i<6 ; i++)
            {
                switch (i)
                {

                case 0: 
                    temp =p->posSprite.x;
                    sprintf(data,"%d",temp);
                    strcat(data,rl);
                    fputs(data, fichier);
                    break;

                case 1:
                    temp =p->posSprite.y;
                    sprintf(data,"%d",temp);
                    strcat(data,rl);
                    fputs(data, fichier);
                    break;

                case 2:
                    temp = b->camera.x;
                    sprintf(data,"%d",temp);
                    strcat(data,rl);
                    fputs(data, fichier);
                    break;

                case 3:
                    temp = b->camera.y;
                    sprintf(data,"%d",temp);
                    strcat(data,rl);
                    fputs(data, fichier);
                    break;

                case 4:
                    temp = s->ScoreActuel;
                    sprintf(data,"%d",temp);
                    strcat(data,rl);
                    fputs(data, fichier);
                    break;
                }
            }
	fclose(fichier);


}



void free_enigme( Enigme *e , anim *a)
{
    SDL_FreeSurface(e->imag);
    SDL_FreeSurface(e->c);
    SDL_FreeSurface(e->w);
    SDL_FreeSurface(e->r1);
    SDL_FreeSurface(e->r2);
    SDL_FreeSurface(e->r3);
    SDL_FreeSurface(e->r4);
    SDL_FreeSurface(e->qes);
    TTF_CloseFont(e->police);
    TTF_CloseFont(e->police_q); 
    SDL_FreeSurface(a->b1);
    SDL_FreeSurface(a->b2);
    SDL_FreeSurface(a->b3);
    SDL_FreeSurface(a->b4);
    SDL_FreeSurface(a->b5);
    SDL_FreeSurface(a->b6);
    SDL_FreeSurface(a->b7);
    SDL_FreeSurface(a->b8);
    SDL_FreeSurface(a->b9);
}

void initialiser_audio (Mix_Music *music)
{
    //initialiser les fonction audio de SDL_mixer
    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
        printf ("%s",SDL_GetError());
    }
    //chargement de la musique
    music=Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(music,-1);
    Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);
}

void liberer_musique (Mix_Music *music)
{
    Mix_FreeMusic(music);
}

