#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "map.h"


//**********************************************init minimap ***********************************
void initmap( minimap *m)
{
	 m->position_mini.x=295;
    m->position_mini.y=0;
    m->sprite = NULL;
    m->sprite = IMG_Load("level4,2.png");
}

void afficherminimap (minimap m, SDL_Surface * screen)
{
	
    SDL_BlitSurface(m.sprite, NULL, screen, &m.position_mini);
   
}
void free_minimap (minimap *m)
{
    SDL_FreeSurface(m->sprite);
}



//***********************************************init temps ********************************************************
void Timer(int *tempsdebut)
{
    
   if( SDL_GetTicks() - *tempsdebut >= 1000 )
    {
        *tempsdebut = SDL_GetTicks() ;
    }
  
}

void inittemps(Time *t)
{
	t->tempsdebut=SDL_GetTicks();
	t->mm=0;
	t->ss=0;
	init_Text_time(&t->temps);
}

void init_Text_time(Text* T)
{ 
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255;

    strcpy(T->txt,"");
    T->positionText.x = 20;
    T->positionText.y = 30; 
    T->police = TTF_OpenFont("avocado.ttf", 40);
    T->textSurface=NULL;
     
}

void affichertime(Time *T,SDL_Surface *screen)
{
    int ts;
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;
    T->mm=ts/60;
    T->ss=ts % 60;
     sprintf(T->temps.txt,"%02d : %02d",T->mm,T->ss );//%02d signifie "formater l'entier avec 2 chiffres
  
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);
     SDL_BlitSurface(T->temps.textSurface,NULL,screen,&(T->temps.positionText));
}


void freeTexttime(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}



//******************************************************animation *********************************************************************

void init_anim( anim *a)

{
	a->position_anim.x=450;
	a->position_anim.y=-130;
	a->sprite=NULL;
    a->sprite=IMG_Load("alarm1.png");
    
    
   
}

void afficher_anim(anim a, SDL_Surface *screen,int *animation,int *lastTime)
{
    int time = SDL_GetTicks();
    if (time - *lastTime > 500)
        {if(*animation==0)
            *animation=1;
        else
            *animation=0;
    *lastTime = time;
}

if (*animation)
{
    SDL_BlitSurface(a.sprite, NULL, screen, &a.position_anim);
}


SDL_Delay(10);
}




void free_anim (anim *a)
{
    SDL_FreeSurface(a->sprite);
    
     //SDL_FreeSurface(b->sprite);
}




//***************************************************************************collision ******************************************************

SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{
        
        SDL_Color color;
        Uint32 col = 0;
     

                char *pixelPosition = (char*)Background->pixels;
         
                pixelPosition += (Background->pitch * y);
               
                pixelPosition += (Background->format->BytesPerPixel * x);
            
                memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
               
                SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

                return (color);
}


int collisionPP( Personne p, SDL_Surface * Masque)
{
    SDL_Color test ,couleurnoir= {0,0,0};

    SDL_Rect pos[8];
    pos[0].x=p.position_perso.x+30;
    pos[0].y=p.position_perso.y;
    pos[1].x=p.position_perso.x+p.position_perso.w/2+30;
    pos[1].y=p.position_perso.y;
    pos[2].x=p.position_perso.x+p.position_perso.w+30;
    pos[2].y=p.position_perso.y;
    pos[3].x=p.position_perso.x+30;
    pos[3].y=p.position_perso.y+p.position_perso.h/2;   
    pos[4].x=p.position_perso.x+30;
    pos[4].y=p.position_perso.y+p.position_perso.h;
    pos[5].x=p.position_perso.x+p.position_perso.w/2+30;
    pos[5].y=p.position_perso.y+p.position_perso.h;
    pos[6].x=p.position_perso.x+p.position_perso.w+30;
    pos[6].y=p.position_perso.y+p.position_perso.h;    
    pos[7].x=p.position_perso.x+p.position_perso.w+30;
    pos[7].y=p.position_perso.y+p.position_perso.h/2;


     int collision=0 , x ,y ;

     for(int i=0 ;i<8 && collision==0;i++)
     {
        x=pos[i].x;
        y=pos[i].y;
        test=GetPixel(Masque,x,y);
        if(test.r==0 && test.g==0 && test.b==0)
            collision=1;
     }
     return collision;

}




void mouvement(Personne *p ,Personne *pM ,Personne *pMprochaine, int distance, int longueur,int longueurM , SDL_Surface *masked , int sens)
{
    if(sens==1)
    {
                    pMprochaine->position_perso.x+=distance;
                 
                    if(collisionPP( *pMprochaine, masked)==0)
                    {
                        pM->position_perso.x=pMprochaine->position_perso.x;
                        p->position_perso.x+=(distance*longueur/longueurM);
                    }
                    else{
                        pMprochaine->position_perso.x=pM->position_perso.x;
                    }
    }
    else if(sens==-1)
    {
        pMprochaine->position_perso.x-=distance;
                  if(collisionPP( *pMprochaine, masked)==0 )
                    {
                        pM->position_perso.x=pMprochaine->position_perso.x;
                        p->position_perso.x-=(distance*longueur/longueurM);
                       
                    }
                    else{
                        pMprochaine->position_perso.x=pM->position_perso.x;
                    }

    }
}



void initialiser_et_afficher_temps_enigme(SDL_Surface * screen,Text *T)
{
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255;
    T->positionText.x = 20;
    T->positionText.y = 30; 
    T->police = TTF_OpenFont("avocado.ttf", 40);
    T->textSurface=NULL;

  T->textSurface=TTF_RenderText_Solid(T->police,T->txt,T->couleurTxt);
     SDL_BlitSurface(T->textSurface,NULL,screen,&(T->positionText));

}








