#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fichierE.h"

int main(){
  FILE* fichier;
  Enigme e;
  personne p;
  background b;
  Score s;
  anim a;
  Mix_Music *music;
  char nomfichier;
  SDL_Surface *screen =NULL;
  SDL_Init(SDL_INIT_EVERYTHING);
  screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
  TTF_Init();
    initialiser_audio(music);
    init_enigme(&e,screen);  
    genererEnigme(&e,&nomfichier); 
    resolution_enigme(&e,screen);
    free_enigme(&e,&a); 
    liberer_musique(music);
    charger(&p,&b,&s,"savefile.txt");
    sauvegarder (&p,&b,&s,"savefile.txt");
    SDL_Quit();

    return EXIT_SUCCESS ;
}


