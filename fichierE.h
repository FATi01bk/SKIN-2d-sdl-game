#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 470
#define SCREEN_W 730


 typedef struct{
 
   SDL_Surface* imag;
   SDL_Rect pos_imag;
   SDL_Surface *r1,*r2,*r3,*r4,*qes;
   SDL_Rect  pos_r1,pos_r2,pos_r3,pos_r4,pos_qes;
   int num,etat,np;
   SDL_Surface *c,*w;
   SDL_Rect pos_correct,pos_wrong;
   TTF_Font *police,*police_q;
 }Enigme;

 typedef struct{
 
    SDL_Rect posSprite;
    SDL_Surface *Sprite;
    char nomplayer[20];
    
 }personne;
 
 typedef struct
{
     //animation animation;
     SDL_Surface *image[3];
     int stageLoaded;
     SDL_Rect camera;     
}background;

typedef struct{

    SDL_Surface *fondScore;
    SDL_Surface *texteScore;
    SDL_Rect posFond;
    SDL_Rect posScore;
    int ScoreActuel;
    TTF_Font *police;
    
}Score;

typedef struct{

   SDL_Surface* b1;
   SDL_Rect pos_b1;  
   SDL_Surface* b2;
   SDL_Rect pos_b2;  
   SDL_Surface* b3;
   SDL_Rect pos_b3;
   SDL_Surface* b4;
   SDL_Rect pos_b4;
   SDL_Surface* b5;
   SDL_Rect pos_b5;
   SDL_Surface* b6;
   SDL_Rect pos_b6;
   SDL_Surface* b7;
   SDL_Rect pos_b7;
   SDL_Surface* b8;
   SDL_Rect pos_b8;
   SDL_Surface* b9;
   SDL_Rect pos_b9;
   
    SDL_Surface *spriteSheet;
     SDL_Rect Clips[8];
     int frames;
     int clipLoaded;
}anim;

void animerEnigme(Enigme *e,SDL_Surface *screen);
void resolution_enigme(Enigme *e,SDL_Surface *screen);
void init_enigme(Enigme *e, SDL_Surface *screen);
void genererEnigme(Enigme *e, char *nomfichier);
void afficherEnigme(Enigme *e,SDL_Surface * screen);
void initialiser_audio (Mix_Music *music);
void free_enigme( Enigme *e ,anim *a);
void liberer_musique (Mix_Music *music);
int  charger ( personne* p, background *b,Score *s,char * nomfichier);
void sauvegarder (personne *p, background *b,Score *s ,char * nomfichier);

#endif
