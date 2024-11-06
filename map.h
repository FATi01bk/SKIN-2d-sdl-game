#ifndef TAYSIR_H_
#define TAYSIR_H_
#include <time.h>

typedef struct 
{
	SDL_Rect position_perso;
 	SDL_Surface *sprite;
}Personne;



typedef struct 
{
	SDL_Rect position_mini;
	SDL_Surface *sprite;
}minimap;



typedef struct  {
    SDL_Surface* textSurface;
    SDL_Rect positionText;
    char txt[20];
    SDL_Color couleurTxt;
    TTF_Font* police;
}Text;



typedef struct
{
    int tempsdebut;
    int mm; 
    int ss;
    Text temps;
    
} Time;




typedef struct 
{
	SDL_Rect position_anim;
	SDL_Surface *sprite;
}anim;




void initmap( minimap *m);
void afficherminimap (minimap m, SDL_Surface * screen);
void free_minimap (minimap *m);


void init_anim( anim *a);
void afficher_anim(anim a, SDL_Surface *screen,int *animation,int *lastTime);
void free_anim (anim *a);


void inittemps(Time *t); 
void Timer(int *tempsdebut);
void init_Text_time(Text* T);
void affichertime(Time *T,SDL_Surface *screen);
void freeTexttime(Text T);


void mouvement(Personne *p ,Personne *pM ,Personne *pMprochaine, int distance, int longueur,int longueurM , SDL_Surface *masked , int sens);
SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
int collisionPP( Personne p, SDL_Surface * Masque);

void initialiser_et_afficher_temps_enigme(SDL_Surface * screen,Text *T);

#endif


