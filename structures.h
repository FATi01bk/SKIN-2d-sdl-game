#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "string.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


typedef struct
{
    int tabsuivi[9];
    SDL_Surface* images[3];
    int joueur_actuel;
    int tour_actuel;
    TTF_Font* police_resultat;
    int couleur_resultat[3];
    SDL_Rect position_resultat;
    TTF_Font* police;
    SDL_Surface *bg;
     SDL_Rect posBg;
      SDL_Rect tabPos[9];
} tic;


typedef struct  {
    SDL_Surface* textSurface;
    SDL_Rect positionText;
    char txt[20];
    SDL_Color couleurTxt;
    TTF_Font* police;
}Text;

typedef struct 
{
	SDL_Rect position_anim;
	SDL_Surface *sprite;
}anim;

typedef struct
{
    int tempsdebut;
    int mm; 
    int ss;
    Text temps;
    
} Time;


typedef struct{
double acceleration, vitesse;
	int frame, PSSaut, sens, hit, gravite,speedup,speeddown,SENSSaut,sol,VIT;
	SDL_Surface *PERDR;
	SDL_Surface *PERG, *PERHIT;
	SDL_Rect PP;
	
}perso;

typedef struct 
{
	SDL_Rect position_mini;
	SDL_Surface *sprite;
}minimap;

typedef struct 
{
	SDL_Rect position_perso;
 	SDL_Surface *sprite;
}Personne;


typedef struct{
            
        SDL_Surface *Entity; 
	SDL_Rect pos_Entity; 
	SDL_Rect anim_Entity[40];
	int frame_Entity; 
	int col; 
	int direction;
	int maxi_up,maxi_down;
	int show;
	}Entity;
	

void inittemps(Time *t); 
void Timer(int *tempsdebut);
void init_Text_time(Text* T);
void affichertime(Time *T,SDL_Surface *screen);
void freeTexttime(Text T);

void initialiser_et_afficher_temps_enigme(SDL_Surface * screen,Text *T);

void mouvement(Personne *petit , int distance,int sens);
	
void initmap( minimap *m);
void afficherminimap (minimap m, SDL_Surface * screen);
void free_minimap (minimap *m);


void init_tab_anim_Entity(SDL_Rect* ES,Entity *e);
void initEntity(Entity *e);				
void afficherEntity(Entity e,SDL_Surface *screen);
void animerEntity(Entity *e);				
void move(Entity * e);
void updateEntity(Entity *e);			
int collisionBB(perso *p,Entity *e);
int gestion(Entity *e);

void init_anim( anim *a);
void afficher_anim(anim a, SDL_Surface *screen,int *animation,int *lastTime);
void free_anim (anim *a);


int choixPerso();
void animerPerso2 (perso* p,int numperso);
void libererPerso(perso* p);
void init2(perso* p,int numperso);
void saut(perso* p);
void reinitsaut ( perso* p);
void movePerso(perso *p,Uint32 dt);
void init(perso* p,int numperso);
void afficherPerso( perso* p,SDL_Surface *screen);
void animerPerso (perso* p,int numperso);


void initialiserTic(tic* T);
void afficherTic(tic T, SDL_Surface* screen);
int atilganer(int tabsuivi[]);
void Resultat(int tabsuivi[], SDL_Surface* screens);
void liberer(tic T);
int minimax(int tabsuivi [],int joueur);
void calcul_coup(int tabsuivi []);


#endif 
