#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctions.h"

int main(){

    SDL_Surface *screen;
    image IMAGE,b1,b2,b3,pro,j;
    Mix_Music *music;
    Mix_Chunk *mus;
    texte txte;
    SDL_Event event;
    int boucle=1,etat=0,bouclep=1,score=0000,b11=0,b12=0,b13=0,i=1,f=-1,m=1;
    SDL_Surface *back = NULL;
    SDL_Rect background_pos;
    char anim[10];
    int volume;
    save_screen(470,730);
    int SCREEN_w=get_screenw();
    int SCREEN_h=get_screenh();
    volume=get_volume();
    coin c;
    di d;
    po pp;

    
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) ==-1)
    {
        printf("Could not initialize SDL: %s. \n", SDL_GetError());
        return -1;
    }


    screen=SDL_SetVideoMode(SCREEN_w,SCREEN_h,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
 
    background_pos.x = 0;
    background_pos.y = 0;

    initialiser_audio(music,volume);
    initialiser_texte(&txte,f);
    //ma();
    afficher_texte(screen,txte);
    chargercoin(&c,screen);
    charg(&pp,screen);
     afficher(&c,screen);
     
    while(boucle)
    
    {    if (m==1){
         
         initialiser_pro(&pro,f);
         initialiser_menu(&IMAGE,f);
         initialiser_b1(&b1,f);
         initialiser_b2(&b2,f);
         initialiser_b3(&b3,f);
         initialiser_p11(&j,f);
         afficher_menu(screen,IMAGE);
         afficher_pro(screen,pro);
         initialiser_texte(&txte,f);
         afficher_texte(screen,txte);
         chargercoin(&c,screen);
         chargerdi(&d,screen);
         charg(&pp,screen);
         afficherdi(&d,screen);
         afficher_p11(screen,j);
         afficher(&c,screen);
         affi(&pp,screen); 
         m=0;
    }
   if (f==-1){
      b11=0;
      b12=0;
      b13=0;
    
        while(SDL_PollEvent(&event))
        {               
            switch(event.type)
            {
                case SDL_QUIT:
                    boucle=0;
                    break;    
                    
                case SDL_MOUSEBUTTONDOWN: 
                        if(event.button.button==SDL_BUTTON_LEFT && (event.button.x<=489 && event.button.x>=227 && event.button.y<=286 && event.button.y>=260 )){ 
                         boucle=levels(f);
                         initialiser_texte(&txte,f);
                         afficher_menu(screen,IMAGE);
                         afficher_pro(screen,pro);
                         afficher_texte(screen,txte);
                         chargercoin(&c,screen);
                          afficher(&c,screen);
                          afficherdi(&d,screen);
                           afficher_p11(screen,j);  
                           affi(&pp,screen);       
                                        
                        }

                        if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<=499 && event.button.x>=227 && event.button.y<=352 && event.button.y>322 ){ 
                            
                           f=option(f);  
                           m=1;                
                           boucle=1;
                           
                        }
                        }                           
                          if(event.button.button==SDL_BUTTON_LEFT && (event.button.x<=497 && event.button.x>=227 && event.button.y<=416 && event.button.y>=386)){
                        boucle=0;}
                        
                      if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<=699 && event.button.x>=610 && event.button.y<=59 && event.button.y>25 ){ 
                            
                           boucle=store(f);
                           chargercoin(&c,screen);
                           afficher(&c,screen);
                        } 
                    
                    break;  
                      
                case SDL_MOUSEMOTION:
                   
         //printf("Souris en position %d %d\n",event.motion.x, event.motion.y);// yekteblek les coordonnees ta3 sourie mta3ek fel terminal
                       if(event.motion.x<489 && event.motion.x>227 && event.motion.y<286 && event.motion.y>260  ){ 
                       
                        b11=1;   
                        initialiser_audiobref(mus);                                
                         afficher_b1(screen,b1); 
                         afficher_pro(screen,pro);                                                                              
                         afficher_texte(screen,txte); 
                          chargercoin(&c,screen);
                          afficher(&c,screen);
                          afficherdi(&d,screen);
                           afficher_p11(screen,j);  
                           affi(&pp,screen);                     
                       }
          
                      else if (event.motion.x<499 && event.motion.x>227 && event.motion.y<352 && event.motion.y>322  ){                              
                              b12=1;
                              initialiser_audiobref(mus);
                              afficher_b2(screen,b2); 
                              afficher_pro(screen,pro);                                                        
                              afficher_texte(screen,txte);
                               chargercoin(&c,screen);
                               afficher(&c,screen); 
                               afficherdi(&d,screen);
                               afficher_p11(screen,j); 
                               affi(&pp,screen);   
                                   }   
           
                      else if(event.motion.x<497 && event.motion.x>227 && event.motion.y<416 && event.motion.y>386  ){                            
                            b13=1;
                            initialiser_audiobref(mus); 
                                 afficher_b3(screen,b3); 
                                 afficher_pro(screen,pro);                                
                                 afficher_texte(screen,txte);
                                  chargercoin(&c,screen);
                                 afficher(&c,screen);
                                 afficherdi(&d,screen);
                                 afficher_p11(screen,j);
                                 affi(&pp,screen);                                  
                                 }
                                 
                      else if(b11==0 && b12==0 && b13==0){       
                      afficher_menu(screen,IMAGE);
                      afficher_pro(screen,pro);
                      afficher_texte(screen,txte);
                       chargercoin(&c,screen);
                        afficher(&c,screen); 
                        afficherdi(&d,screen);
                       afficher_p11(screen,j); 
                       affi(&pp,screen);          
                      }
                    break;
            }
        }

      SDL_Flip(screen); }}
      else if (f==1){
      
      b11=0;
      b12=0;
      b13=0;
    
        while(SDL_PollEvent(&event))
        {               
            switch(event.type)
            {
                case SDL_QUIT:
                    boucle=0;
                    break;    
                    
                case SDL_MOUSEBUTTONDOWN: 
                        if(event.button.button==SDL_BUTTON_LEFT && (event.button.x<=930 && event.button.x>=428 && event.button.y<=375 && event.button.y>=335 )){ 
                         boucle=levels(f);
                         initialiser_texte(&txte,f);
                         afficher_menu(screen,IMAGE);
                         afficher_texte(screen,txte);
                                                
                        }

                        if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<=934 && event.button.x>=426 && event.button.y<=441 && event.button.y>423 ){ 
                            
                           f=option(f);  
                           m=1;                
                           boucle=1;
                           
                        }
                        }                           
                          if(event.button.button==SDL_BUTTON_LEFT && (event.button.x<=931 && event.button.x>=426 && event.button.y<=512 && event.button.y>505)){
                        boucle=0;}
                        
                    if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<=699 && event.button.x>=610 && event.button.y<=59 && event.button.y>25 ){ 
                            
                           boucle=store(f);
                           initialiser_texte(&txte,f);
                           afficher_menu(screen,IMAGE);
                           afficher_texte(screen,txte);                            
                        }
                        } 
                    
                    break;  
                      
                case SDL_MOUSEMOTION:
                printf("Souris en position %d %d\n",event.motion.x, event.motion.y);// yekteblek les coordonnees ta3 sourie mta3ek fel terminal             

                       if(event.motion.x<930 && event.motion.x>428 && event.motion.y<375 && event.motion.y>335 ){ 
                       
                        b11=1;   
                        initialiser_audiobref(mus);                                
                         afficher_b1(screen,b1);                                                                               
                         afficher_texte(screen,txte);                         
                       }
          
                      else if (event.motion.x<934 && event.motion.x>426 && event.motion.y<441 && event.motion.y>423 ){                              
                              b12=1;
                              initialiser_audiobref(mus);
                              afficher_b2(screen,b2);                                                         
                              afficher_texte(screen,txte);    
                                   }   
           
                      else if(event.motion.x<931 && event.motion.x>426 && event.motion.y<512 && event.motion.y>505 ){                            
                            b13=1;
                            initialiser_audiobref(mus); 
                                 afficher_b3(screen,b3);                                 
                                 afficher_texte(screen,txte);                                
                                 }
                                 
                      else if(b11==0 && b12==0 && b13==0){       
                      afficher_menu(screen,IMAGE);
                      afficher_texte(screen,txte);
                                 
                      }
                    break;
            }
        }

      SDL_Flip(screen);
      
      }
      }
      
    SDL_FreeSurface(back);
    liberer_image(IMAGE);
    liberer_image(b1);
    liberer_image(b2);
    liberer_image(b3);
    liberer_musique(music);
    liberer_musiquebref(mus);
    liberer_texte(txte);

    SDL_Quit();
    return 0;
}

