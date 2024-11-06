#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "map.h"


int main()
{
    int collision,distance =12, sens=0,enigme;
    int animation = 1;
    int lastTime = 0;
    int enigme_time;
    int last_enigme_time;
    SDL_Event event;
    minimap m;
    anim a,b;
    Personne p, pM, pMprochaine;
    Time temps;
    Text E;
    SDL_Surface *screen = NULL,*imageDeFond=NULL, *image_enigme=NULL,*masked=NULL;
    SDL_Rect position_BG,position_EG ;
    int longueurM=3211, largeurM=600, longueur =856, largeur=160;
    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
    TTF_Init();
    int continuer= 1;
    if(screen==NULL)
    {
        printf("ERREUR: %s\n", SDL_GetError());
        return 1;
    }


image_enigme = IMG_Load("trah.png");
    position_EG.x=0;
    position_EG.y=0;

    imageDeFond = IMG_Load("level 4.png");
    position_BG.x=0;
    position_BG.y=0;

    initmap( &m);
    init_anim( &a);
    inittemps(&temps);

    masked=IMG_Load("mask.png");

    p.sprite = IMG_Load("person_mini.png");
    p.position_perso.x=295;
    p.position_perso.y=65;



    pM.sprite=IMG_Load("person_gro.png");
    pM.position_perso.x=0;
    pM.position_perso.y=300;


    pMprochaine.position_perso.h=180;
    pMprochaine.position_perso.w=110;
    pMprochaine.position_perso.x=pM.position_perso.x;
    pMprochaine.position_perso.y=pM.position_perso.y;

    while (continuer)
    {enigme=1;
        sens=0;
	enigme_time=SDL_GetTicks();
        SDL_BlitSurface(imageDeFond, NULL, screen, &position_BG); // grand backgroud
        afficherminimap ( m,screen);


        SDL_BlitSurface(p.sprite, NULL, screen, &p.position_perso);
        SDL_BlitSurface(pM.sprite, NULL, screen, &pM.position_perso);
        affichertime(&temps,screen);
        afficher_anim(a, screen,&animation,&lastTime);


        while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break ;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;

                case SDLK_RIGHT :
                    sens=1;
                    break;

                case SDLK_LEFT :
                    sens=-1;
                    break;

                case SDLK_p:
                    imageDeFond = IMG_Load("mask.png");
                    break;
                case SDLK_o:
                    imageDeFond = IMG_Load("level 4.png");
                    break;
		case SDLK_e :

while(enigme)
{        SDL_Flip(screen);
 	SDL_BlitSurface(image_enigme, NULL, screen, &position_EG);
	last_enigme_time=SDL_GetTicks();
	last_enigme_time-=enigme_time;
	sprintf(E.txt,"%d Seconds",15-(last_enigme_time/1000));
 	initialiser_et_afficher_temps_enigme(screen,&E);
 	
	if(last_enigme_time>15000)
		enigme=0;
	while(SDL_PollEvent(&event))
        {

            switch(event.key.keysym.sym)
            {
            case SDLK_m:
                enigme = 0;
                break ;
            }
         }
}
		    break;

                }
            }

        }
        mouvement(&p,&pM,&pMprochaine,distance,longueur,longueurM, masked,  sens );
        collision = collisionPP(p, masked); // appel de la fonction collisionPP

        SDL_Flip(screen);

    }
    free_minimap (&m);
    free_anim (&a);
    SDL_FreeSurface(p.sprite);
    freeTexttime(temps.temps);
    SDL_FreeSurface(screen);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}


