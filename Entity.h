#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <stdio.h>     
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<time.h>





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
	
	

typedef struct
{
	SDL_Surface *perso; 
	SDL_Rect perso_pos ;
}personnage;
	



void init_tab_anim_Entity(SDL_Rect* ES,Entity *e);
void initEntity(Entity *e);				
void afficherEntity(Entity e,SDL_Surface *screen);
void animerEntity(Entity *e);				
void move(Entity * e);
void updateEntity(Entity *e);			
int collisionBB(personnage *p,Entity *e);
int gestion(Entity *e);

void initialiser_perso(personnage *p);
void afficher_perso(personnage p , SDL_Surface *screen);


#endif
