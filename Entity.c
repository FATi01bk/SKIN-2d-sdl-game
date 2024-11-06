#include <stdio.h>     
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Entity.h"


int nb_frame=12;
int Entity_h=100;
int Entity_w=100;
int Entity_y=100;
int Entity_x=100;


void init_tab_anim_Entity(SDL_Rect *ES,Entity *e)
{	
	 
	for (int j=0;j<nb_frame;j++)
	{
	ES[j].h=Entity_h;
	ES[j].w=Entity_w;
	ES[j].x = j*Entity_x;
	ES[j].y = 0;
        }  
}

void initEntity(Entity *e)
{
    e->Entity = IMG_Load("es.png");
    e->pos_Entity.x = 400;
    e->pos_Entity.y = 100;
    init_tab_anim_Entity(e->anim_Entity,e); 
    e->frame_Entity=0;
    e->direction=0;  
    e->col=0;
    e->show=1;
    
}
    				
void afficherEntity(Entity e,SDL_Surface *screen)
{

    SDL_BlitSurface(e.Entity,&e.anim_Entity[e.frame_Entity], screen, &e.pos_Entity);

}

void move(Entity * e)
{
      int maxi_down=300+rand()%300;
      int maxi_up=50+rand()%300;      
       
      if(e->pos_Entity.y>=maxi_down){
          e->direction=1;}
          
      if(e->pos_Entity.y<=maxi_up){
          e->direction=0;}
      
      if(e->direction==1){
           e->pos_Entity.y-=5;
           }
      if(e->direction==0){
           e->pos_Entity.y+=7;
           }

}

void animerEntity(Entity *e)
{   
	if (e->frame_Entity >=0 && e->frame_Entity <(nb_frame-1)) 
	e->frame_Entity++;
	
	if ( e->frame_Entity ==(nb_frame-1)) 
	e->frame_Entity=0;
}
		


void updateEntity(Entity *e)
{
    move(e);
    animerEntity(e);
}   	
	


void initialiser_perso(personnage *p)
{
    p->perso= IMG_Load("per.png");
    p->perso_pos.x = 100;
    p->perso_pos.y = 100;
    p->perso_pos.h = 250;
    p->perso_pos.w = 147;
    
}
 
void afficher_perso(personnage p , SDL_Surface *screen)
{
   SDL_BlitSurface(p.perso,NULL, screen, &p.perso_pos);

}

int collisionBB(personnage *p,Entity *e)
{

      if ((p->perso_pos.x + p->perso_pos. w < e->pos_Entity.x) ||(p->perso_pos.x> e->pos_Entity.x + e->pos_Entity.w) ||
(p->perso_pos.y + p->perso_pos.h < e->pos_Entity. y) || (p->perso_pos.y > e->pos_Entity.y + e->pos_Entity.h ))
               return 0;
      else
               return 1;
}			

int gestion(Entity* e)
{
   e->show=0; 
   return 0;
}


