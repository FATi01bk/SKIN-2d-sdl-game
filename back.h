#ifndef BACK
#define BACK
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>





typedef struct
{
     int score;
     int temps;
     char playerName[20];
} ScoreInfo;

typedef struct
{
     SDL_Surface *spriteSheet;
     SDL_Rect Clips[8];
     int frames;
     int clipLoaded;
} animation;

typedef struct
{
     animation animation;
     animation rain;
     SDL_Surface *image[3];
     int stageLoaded; // 0 stage 1 1 stage 2
     SDL_Rect camera;
     SDL_Rect pos;
} background;



void initBack(background *b);
void afficherback(background b, SDL_Surface *screen);
void scrolling(background *b, int direction, int pasAvancement);
void saveScore(ScoreInfo s, char nomfichier[]);
void bestScore(char *filename, ScoreInfo t[]);
void enterPlayerName(char playerName[], SDL_Surface *screen, int *continuer);
void showBestScore(ScoreInfo t[], SDL_Surface *screen, int *continuer);

#endif /* BACK */
