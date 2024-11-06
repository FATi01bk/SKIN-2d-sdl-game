#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "fonctions.h"
#include <time.h>
#include "structures.h"
#include "back.h"
#define SCREEN_WIDTH 1450
#define SCREEN_HEIGHT 700
int ma()
{
SDL_Surface *screen, *backgroundanimbird =NULL;
SDL_Event event;
backgroundanimbird = IMG_Load("back2.png");
SDL_Rect positionbackbird ;
SDL_Init(SDL_INIT_EVERYTHING);
    screen=SDL_SetVideoMode(730,475, 32,SDL_HWSURFACE| SDL_DOUBLEBUF);
    SDL_WM_SetCaption("BIENVENUE DANS LE JEU",NULL);
bird b;
wind w;
    positionbackbird.x=0;
    positionbackbird.y=0;
int bcl = 1;
initanimBird(&b);
initanimwind(&w);
while (bcl)
{
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            bcl=0;

            break;
}
SDL_BlitSurface(backgroundanimbird,NULL,screen,&positionbackbird);

afficherBird(&b,screen);
animerBird (&b);

afficherwind(&w,screen);
animerwind (&w);
        SDL_Flip(screen);
}
SDL_FreeSurface(backgroundanimbird);
libererwind(&w);
libererBird(&b);
    SDL_Quit();

return 0;
}
void initanimBird( bird *b)

{
	b->PP.x=600;
	b->PP.y=-230;
	b->imgBird=NULL;
    b->imgBird=IMG_Load("bird1.png");
 
}

void afficherBird(bird* p,SDL_Surface *screen)
{
		SDL_BlitSurface(p->imgBird,NULL,screen,&p->PP);
}

void animerBird (bird* p)
{

p->frame++;
if ( p->frame > 8)
{
p->frame = 0;

}
if ( p->frame == 0 )
{
SDL_FreeSurface(p->imgBird);
p->imgBird= IMG_Load("bird1.png");
SDL_Delay(40);
}
if ( p->frame == 1 )
{
SDL_FreeSurface(p->imgBird);
p->imgBird= IMG_Load("bird2.png");
p->PP.x-=18;
SDL_Delay(40);
}
if ( p->frame == 2 )
{
SDL_FreeSurface(p->imgBird);
p->imgBird= IMG_Load("bird3.png");
SDL_Delay(40);
}
if ( p->frame == 3 )
{
SDL_FreeSurface(p->imgBird);
p->imgBird= IMG_Load("bird4.png");
SDL_Delay(40);
}
if ( p->frame == 4 )
{
SDL_FreeSurface(p->imgBird);
p->imgBird= IMG_Load("bird5.png");
SDL_Delay(40);
}
if ( p->frame == 5 )
{
SDL_FreeSurface(p->imgBird);
p->imgBird= IMG_Load("bird6.png");
SDL_Delay(40);
}
if ( p->frame == 6 )
{
SDL_FreeSurface(p->imgBird);
p->imgBird= IMG_Load("bird7.png");
SDL_Delay(40);
}
if ( p->frame == 7 )
{
SDL_FreeSurface(p->imgBird);
p->imgBird= IMG_Load("bird8.png");
SDL_Delay(40);
}
if ( p->frame == 8 )
{
SDL_FreeSurface(p->imgBird);
p->imgBird= IMG_Load("bird9.png");
SDL_Delay(40);

}
}

void libererBird(bird* b)
{
	SDL_FreeSurface(b->imgBird);

}




void initanimwind( wind *b)

{
	b->PP.x=100;
	b->PP.y=330;
	b->imgwind=NULL;
    b->imgwind=IMG_Load("wind1.png");
    
    
   
}

void afficherwind(wind* p,SDL_Surface *screen)
{
		SDL_BlitSurface(p->imgwind,NULL,screen,&p->PP);
}

void animerwind (wind* p)
{

p->frame++;
if ( p->frame > 8)
{
p->frame = 0;

}
if ( p->frame == 0 )
{
SDL_FreeSurface(p->imgwind);
p->imgwind= IMG_Load("wind1.png");
SDL_Delay(20);
}
if ( p->frame == 1 )
{
SDL_FreeSurface(p->imgwind);
p->imgwind= IMG_Load("wind2.png");
SDL_Delay(20);
}
if ( p->frame == 2 )
{
SDL_FreeSurface(p->imgwind);
p->imgwind= IMG_Load("wind3.png");
SDL_Delay(20);
}
if ( p->frame == 3 )
{
SDL_FreeSurface(p->imgwind);
p->imgwind= IMG_Load("wind4.png");
SDL_Delay(20);
}
if ( p->frame == 4 )
{
SDL_FreeSurface(p->imgwind);
p->imgwind= IMG_Load("wind5.png");
SDL_Delay(20);
}
if ( p->frame == 5 )
{
SDL_FreeSurface(p->imgwind);
p->imgwind= IMG_Load("wind6.png");
SDL_Delay(20);
}
if ( p->frame == 6 )
{
SDL_FreeSurface(p->imgwind);
p->imgwind= IMG_Load("wind7.png");
SDL_Delay(20);
}
if ( p->frame == 7 )
{
SDL_FreeSurface(p->imgwind);
p->imgwind= IMG_Load("wind8.png");
SDL_Delay(20);
}
if ( p->frame == 8 )
{
SDL_FreeSurface(p->imgwind);
p->imgwind= IMG_Load("wind9.png");
SDL_Delay(20);

}
}

void libererwind(wind* b)
{
	SDL_FreeSurface(b->imgwind);

}
int play()
{
	int x, y, coup;
    tic T;
    TTF_Init();
    SDL_Surface *screen = NULL, *masked = NULL;
    SDL_Surface *button;
int distance=5,tic;
    SDL_Rect posButton;

    posButton.x = 10;
    posButton.y = 500;
    posButton.w = 350;
    posButton.h = 186;

    SDL_Surface *image_enigme = NULL;
    SDL_Rect fenetre;
    SDL_Rect position_EG;

    fenetre.x = 0;
    fenetre.y = 0;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Event event;
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("BIENVENUE DANS LE JEU", NULL);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    Mix_Music *music = NULL;
    music = Mix_LoadMUS("./music.mp3");
    Mix_PlayMusic(music, -1);

    TTF_Init();

    background back;
    background back1;

    initBack(&back);
    initBack(&back1);

    button = IMG_Load("button.png");

    ScoreInfo t[10];

    ScoreInfo s;

    s.score = 0;
    s.playerName[0] = '\0';

    int startTime = SDL_GetTicks() / 1000;
    int isMultiplayer = 0;

    SDL_Rect player1 = {0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT};
    SDL_Rect player2 = {SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT};
    Personne petit;

    int choix = 1;
    perso p, p2;
    int enigme_time=0;
    int last_enigme_time, enigme;
    int a = 1;
    int sens = 0;
    int longueurM = 3211, largeurM = 600, longueur = 856, largeur = 160;
    int lastTime = 0;
    int animation = 1;
    image g;
    Entity e;
    minimap m;
    Time temps;
    Text E;
    anim b;

    Uint32 dt;
    Uint32 tp;
    initialiser_sous(&g);
    init(&p, choix);
    inittemps(&temps);
    s.score = 0;
    init2(&p2,choix);
    initEntity(&e);
    initmap(&m);
   
    init_anim(&b);

    SDL_Surface *vie = IMG_Load("Vies_2.png");
    SDL_Rect pos_vie;
    pos_vie.x = 800;
    pos_vie.y = 20;

    petit.sprite = IMG_Load("person_mini.png");
    petit.position_perso.x = 295;
    petit.position_perso.y = 12;

    image_enigme = IMG_Load("trah.png");
    position_EG.x = 0;
    position_EG.y = 0;

    SDL_Color Noir = {255, 255, 255};
    
    
    int continuer = 1;
    enterPlayerName(s.playerName, screen, &continuer);
    
    while (continuer == 1)
    {
    
        int tempsSeconds = (SDL_GetTicks() / 1000) - startTime;
	coin c;
        enigme = 1;
        tic=1;
        tp = SDL_GetTicks();
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
            

        case SDL_MOUSEBUTTONDOWN:
            if (event.motion.x >= posButton.x &&
                event.motion.x <= posButton.x + posButton.w &&
                event.motion.y >= posButton.y &&
                event.motion.y <= posButton.y + posButton.h)
            {
                bestScore("best.txt", t);
                showBestScore(t, screen, &continuer);
            }
          
            if(event.button.button==SDL_BUTTON_LEFT ){
            if  (event.button.x<130 && event.button.x>58 && event.button.y<101 && event.button.y>35){                         
    image l1;
    SDL_Event event,events;
    int boucle1=1;
    initialiser_me(&l1);
 chargercoinc(&c,screen);
 SDL_Flip(screen);
    while(boucle1!=0)
    {  afficher_sous(screen,l1);
     afficher(&c,screen);
        while(SDL_PollEvent(&event))
        { 
            switch(event.type){
            
                case SDL_QUIT:
                    boucle1=0;
                    continuer = 0;
                    break;
                                      
                case SDL_MOUSEBUTTONDOWN: 
                
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<956 && event.button.x>920 && event.button.y<252 && event.button.y>202 ){
                        boucle1=0; }  
                        else if (event.button.x<858 && event.button.x>612 && event.button.y<497 && event.button.y>444){
                        boucle1=0;
                        continuer = 0;
                        }
                        else if (event.button.x<855 && event.button.x>615 && event.button.y<397 && event.button.y>343){
                         st();
                         boucle1=1;
                        }
                        else if (event.button.x<855 && event.button.x>616 && event.button.y<317 && event.button.y>265){
                        choix = 1;
                         init(&p, choix);
                         inittemps(&temps);
                          
                           boucle1=0;
                           continuer = 1;
                        }
                        
                         }         
                    break;
                     }
        }   
        SDL_Flip(screen); }
       
    liberer_image(l1);       
                    }}       
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;


                break;
                
                

            case SDLK_RIGHT:
            {
                sens = 1;
                animerPerso(&p, choix);
                p.sens = 0;
                movePerso(&p, dt);
                scrolling(&back, 1, 80);
                if (back.camera.x > 6000)
                {
                    p.PP.x = 0;
                    back.camera.x = 0;
                    back.camera.y = 0;
                    back.stageLoaded++;
                    if (back.stageLoaded >= 2)
                        initBack(&back);
                }
                                 mouvement(&petit,distance,sens );
            }
            
            break;

            case SDLK_LEFT:
            {
                sens = -1;
                animerPerso(&p, choix);
                p.sens = 1;
                movePerso(&p, dt);
                scrolling(&back, 2, 80);
                 mouvement(&petit,distance,sens );
            }
            break;
            case SDLK_x:
                s.temps = tempsSeconds;
                saveScore(s, "best.txt");
                continuer = 0;
                break;
            case SDLK_z:
            p2.PSSaut = 1;
                if (isMultiplayer == 1)
                
                    scrolling(&back1, 3, 80);
                break;
                            case SDLK_m:
                            
                isMultiplayer = 1;
                afficherPerso(&p2, screen);
                break;
            case SDLK_d:
            
                if (isMultiplayer == 1)
                                    scrolling(&back1, 1, 80);
                    animerPerso2(&p2,choix);
                                p2.sens =0;
                                                movePerso(&p2,dt);
                if (back.camera.x > 6000)
                {

                    p.PP.x = 0;
                    back1.camera.x = 0;
                    back1.camera.y = 0;
                    back1.stageLoaded++;
                    if (back1.stageLoaded >= 2)
                        initBack(&back1);
                }
                break;
            case SDLK_q:
                if (isMultiplayer == 1)

                    scrolling(&back1, 2, 80);
                                    animerPerso2(&p2,choix);
                                p2.sens =1;
                                                movePerso(&p2,dt);
                break;
            case SDLK_s:
                if (isMultiplayer == 1)
                    scrolling(&back1, 4, 80);
                break;


            case SDLK_n:
                isMultiplayer = 0;

                break;
                
                
                
            case SDLK_a:
                while (enigme)
                {
                     SDL_Flip(screen);
                        SDL_BlitSurface(image_enigme, NULL, screen, &position_EG);
                        last_enigme_time=SDL_GetTicks();
                        last_enigme_time-=enigme_time;
                        sprintf(E.txt,"%d Seconds",15-(last_enigme_time/1000));
                        initialiser_et_afficher_temps_enigme(screen,&E);

                        if(last_enigme_time>15000)
                            enigme=0;
                         if(last_enigme_time=0)
                            enigme=0;
                        while(SDL_PollEvent(&event))
                        {

                            switch(event.key.keysym.sym)
                            {
                            case SDLK_n:
                                enigme = 0;
                                break ;
                            }
                        }
                        
                }
                break;
                
                
            case SDLK_SPACE:
                p.PSSaut = 1;
                break;
                
                
                case SDLK_h :
                    initialiserTic(&T);
                    while (tic)
                    {
                  //  SDL_Flip(screen);
                    afficherTic(T, screen);
                        if (T.tour_actuel < 9 && atilganer(T.tabsuivi) == 0)
                        {
                            if ((T.tour_actuel /*+ t.joueur_actuel*/) % 2 == 1)
                            {
                                calcul_coup(T.tabsuivi);
                                T.tour_actuel++;
                            }
                            else
                            {
                                SDL_WaitEvent(&event);
                                if (event.type == SDL_MOUSEBUTTONUP)
                                {
                                    x = event.button.x/217 ;
                                    y = event.button.y/217 ;
                                    coup = 3 * y + x;
                                    if (T.tabsuivi[coup] == 0)
                                    {
                                        T.tabsuivi[coup] = -1;
                                        T.tour_actuel++;
                                    }
                                }
                               
                            }
                        }
                        else
                        {
                            Resultat(T.tabsuivi,screen);
                            tic = 0;
                        }   
                        
                         while (SDL_PollEvent(&event))
                    {

                        switch (event.key.keysym.sym)
                        {
                            case SDLK_v:
                                tic = 0;
                                break ; 
                                }
                                }       
                    }
                    break;
                  
                    
                
                
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
            {
                if (p.sens == 0 && p.acceleration >= 0.01)
                {
                    animerPerso(&p, choix);
                    p.acceleration -= 0.01;
                    movePerso(&p, dt);
                }
            }
            break;

            case SDLK_LEFT:
            {
                if (p.sens == 1 && p.acceleration >= 0.01)
                {
                    animerPerso(&p, choix);
                    p.acceleration -= 0.01;
                    movePerso(&p, dt);
                }
            }
            break;
            }
            break;
        }

        printf("%.3f \n", p.acceleration);
        saut(&p);
        saut(&p2);
        afficherPerso(&p2, screen);
        if (isMultiplayer == 1)
        {
        
            back.pos = player1;
            back1.pos = player2;
            afficherback(back, screen);
            afficherback(back1, screen);
        }
        else
        {
        
            back.pos.x = 0;
            back.pos.y = 0;
            afficherback(back, screen);
        }

        SDL_BlitSurface(button, NULL, screen, &posButton);

        if (SDL_GetTicks() % 5 == 0)
        {
            back.rain.clipLoaded++;
            if (back.rain.clipLoaded >= back.rain.frames)
                back.rain.clipLoaded = 0;

            back1.rain.clipLoaded++;
            if (back1.rain.clipLoaded >= back.rain.frames)
                back1.rain.clipLoaded = 0;
        }

        switch (tempsSeconds)
        {
        case 5:
            back.animation.clipLoaded = 1;
            s.score = 1;
            break;
        case 10:
            back.animation.clipLoaded = 2;
            s.score = 2;
            break;
        case 15:
            back.animation.clipLoaded = 3;
            s.score = 3;
            break;
        case 20:
            back.animation.clipLoaded = 4;
            s.score = 4;
            break;
        case 25:
            back.animation.clipLoaded = 5;
            s.score = 5;
            break;
        }
        
        SDL_BlitSurface(vie, NULL, screen, &pos_vie);
        afficherminimap(m, screen);
        SDL_BlitSurface(petit.sprite, NULL, screen, &petit.position_perso);
        afficherPerso(&p, screen);
        //afficherPerso(&p2, screen);
        afficherEntity(e, screen);
        affichertime(&temps, screen);
        afficher_sous(screen,g);
        afficher_anim(b, screen, &animation, &lastTime);
        // mouvement(&petit,&p,&pMprochaine,distance,longueur,longueurM, masked,  sens );
        SDL_Flip(screen);
        SDL_Delay(20);
        dt = SDL_GetTicks() - tp;
        updateEntity(&e);
        if (collisionBB(&p, &e))
        {
            a = gestion(&e);
        }
    }

    TTF_Quit();
    SDL_FreeSurface(petit.sprite);
    free_anim(&b);
    free_minimap(&m);
    libererPerso(&p);
    liberer(T);
    //libererPerso(&p2);
    freeTexttime(temps.temps);
    
    SDL_Quit();
    return EXIT_SUCCESS;
}
void initialiserTic(tic *T)
{
    T->images[1] = IMG_Load("case_x.png");
    T->images[2] = IMG_Load("case_o.png");
    T->images[0] = IMG_Load("case_vide.png");
    T -> bg = IMG_Load("white.jpeg");


    for (int i = 0; i < 9; i++)
    {
        T->tabsuivi[i] = 0;
    }

    T->posBg.x = 0;
    T->posBg.y = 0;

    T->joueur_actuel = 1;
    T->tour_actuel = 0;


    // Initialiser tabPos (contenant la position d'affichage de chaque case dans la grille)
    int xGrille = (600 - 3 * 217) / 2;
    int yGrille = (600 - 3 * 217) / 2;

    for (int i = 0; i < 9; i++)
    {
        T->tabPos[i].x = 217 * (i % 3) - xGrille;
        T->tabPos[i].y = 217* (i / 3) - yGrille;
    }
}
  

void afficherTic(tic T, SDL_Surface* ecran)
{
    SDL_BlitSurface(T.bg, NULL, ecran, NULL);
    SDL_BlitSurface(T.images[0], NULL, ecran, NULL);
    for (int i = 0; i < 9; i++)
    {
        SDL_Rect pos = T.tabPos[i];
        SDL_Surface *image;

        if (T.tabsuivi[i] == 1)
        {
            SDL_BlitSurface(T.images[1], NULL, ecran, &pos);
        }
        else if (T.tabsuivi[i] ==-1 )
        {
            SDL_BlitSurface(T.images[2], NULL, ecran, &pos);
        }
        
    }

    // Mettre à jour l'affichage
    SDL_Flip(ecran);
}


int atilganer(int tabsuivi[])
{

    int lignes_gagnantes[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};//8 lignes et 3 colonnes
    for (int i = 0; i < 8; i++)
    {
        int a = tabsuivi[lignes_gagnantes[i][0]];//comparer entre meme ligne et differente colone
        int b = tabsuivi[lignes_gagnantes[i][1]];
        int c = tabsuivi[lignes_gagnantes[i][2]];
        if (a != 0 && a == b && b == c)
        {
            if (a == 1)// 1 pour la machine
            {
                return 1;// La machine a gagné
            }
            else
            {
                return -1; // Le joueur humain a gagné
            }
        }
    }

    return 0;
}


void Resultat(int tabsuivi[], SDL_Surface* ecran)
{
    int resultat = atilganer(tabsuivi);

    // Charger la police de caractères
    TTF_Font* police = TTF_OpenFont("avocado.ttf", 30);

    SDL_Color couleur_texte = {0,0,255}; // Couleur du texte en blanc
    SDL_Surface* message = NULL;

    SDL_Rect position_texte;
    position_texte.x = 560;
    position_texte.y = 40;


    switch (resultat)
    {
    case 1:
        message = TTF_RenderText_Solid(police, "Victoire de la machine !", couleur_texte);
        break;
    case -1:
        message = TTF_RenderText_Solid(police, "Victoire du joueur !", couleur_texte);
        break;
    default:
        message = TTF_RenderText_Solid(police, "Match nul !", couleur_texte);
        break;
    }
    SDL_BlitSurface(message, NULL, ecran, &position_texte);
    SDL_Flip(ecran);
    SDL_Delay(3000); // Pause de 2 secondes avant de quitter
    SDL_FreeSurface(message);

}

void liberer(tic T)
{
    for (int i = 0; i < 3; i++)
    {
        SDL_FreeSurface(T.images[i]);
    }
    TTF_CloseFont(T.police);

}



int minimax(int tabsuivi [9],int joueur)//un entier joueur qui représente le joueur actuel (-1 pour le joueur humain, 1 pour l'ordinateur).
{
    // Vérification si la partie est terminée
    int resultat = atilganer(tabsuivi);
    if (resultat != 0)
        return resultat * joueur;

    // Recherche du meilleur coup
    int meilleurScore = -2;
    int meilleurCoup = -1;

    for (int i = 0; i < 9; i++)
    {
        if (tabsuivi[i] == 0)
        {
            tabsuivi[i] = joueur;
            int score = -minimax(tabsuivi, joueur * -1);//la fonction minimax est appelée récursivement en inversant le joueur (joueur * -1). Cela simule le tour de l'autre joueur.
            tabsuivi[i] = 0;

            if (score > meilleurScore)
            {
                meilleurScore = score;
                meilleurCoup = i;
            }
        }
    }

    // Retourne le meilleur score ou 0 si aucun coup possible
    if (meilleurCoup == -1)
        return 0;
    else
        return meilleurScore;
}

void calcul_coup(int tabsuivi[9])
{
    int coup = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; i++)
    {
        if (tabsuivi[i] == 0)
        {
            tabsuivi[i] = 1;
            int mmscore = -minimax(tabsuivi, -1);
            if (mmscore > score)
            {
                score = mmscore;
                coup = i;
            }
            tabsuivi[i] = 0;
        }
    }

    if (coup != -1)
    {
        tabsuivi[coup] = 1; // Joue le coup pour l'ordinateur
    }
}




void mouvement(Personne *petit , int distance,int sens)
{
   if(sens==1)
       petit->position_perso.x+=distance;
    else if(sens==-1)
        petit->position_perso.x-=distance;
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

void init_anim( anim *a)

{
	a->position_anim.x=1000;
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
    T->positionText.x = 1100;
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


void initmap( minimap *m)
{
	 m->position_mini.x=250;
    m->position_mini.y=0;
    m->sprite = NULL;
    m->sprite = IMG_Load("mmtays.png");
}

void afficherminimap (minimap m, SDL_Surface * screen)
{
	
    SDL_BlitSurface(m.sprite, NULL, screen, &m.position_mini);
   
}
void free_minimap (minimap *m)
{
    SDL_FreeSurface(m->sprite);
}


int nb_frame=12;
int Entity_h=100;
int Entity_w=100;
int Entity_y=100;
int Entity_x=100;

int collisionBB(perso *p,Entity *e)
{

      if ((p->PP.x+101< e->pos_Entity.x) ||(p->PP.x> e->pos_Entity.x + e->pos_Entity.w) ||
(p->PP.y+155< e->pos_Entity. y) || (p->PP.y > e->pos_Entity.y + e->pos_Entity.h ))
               return 0;
      else
               return 1;
}

void move(Entity * e)
{
      int maxi_down=400+rand()%500;
      int maxi_up=50+rand()%100;      
       
      if(e->pos_Entity.y>=maxi_down){
          e->direction=1;}
          
      if(e->pos_Entity.y<=maxi_up){
          e->direction=0;}
      
      if(e->direction==1){
           e->pos_Entity.y-=5;
           }
      if(e->direction==0){
           e->pos_Entity.y+=5;
           }

}

void animerEntity(Entity *e)
{   
	if (e->frame_Entity >=0 && e->frame_Entity <(nb_frame-1)) 
	e->frame_Entity++;
	
	if ( e->frame_Entity ==(nb_frame-1)) 
	e->frame_Entity=0;
}

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
		


void updateEntity(Entity *e)
{
    move(e);
    animerEntity(e);
}   

void afficherEntity(Entity e,SDL_Surface *screen)
{

    SDL_BlitSurface(e.Entity,&e.anim_Entity[e.frame_Entity], screen, &e.pos_Entity);

}

void initEntity(Entity *e)
{
    e->Entity = IMG_Load("es.png");
    e->pos_Entity.x = 800;
    e->pos_Entity.y = 150;
    init_tab_anim_Entity(e->anim_Entity,e); 
    e->frame_Entity=0;
    e->direction=0;  
    e->col=0;
    e->show=1;
    
}

void movePerso(perso *p,Uint32 dt)
{
    int VitesseDeplacement;

    VitesseDeplacement=((p->acceleration/2)*(dt*dt))+(p->vitesse*dt);

    if(p->sens==1)
        p->PP.x-=(VitesseDeplacement/35);
    else if(p->sens==0)
        p->PP.x+=(VitesseDeplacement/35);

}

int gestion(Entity* e)
{
   e->show=0; 
   return 0;
}

void init(perso* p,int numperso)
{
	p->PERDR= NULL;
	p->PERG= NULL;
	if ( numperso == 1 ){
		p->PERDR= IMG_Load("asr.png");
		p->PERG= IMG_Load("asl.png");
	}else if ( numperso == 2 )
	{
		// 2eme joueur
		p->PERDR= IMG_Load("awr.png");
		p->PERG= IMG_Load("awl.png");
	}
        
        p->gravite = 0;
	p->VIT=0;
	//p->text_score = NULL;
	//p->positionscore.x = 0;
	//p->positionscore.y = 80;
	//p->score = 100;
	p->PP.x = 100;
	p->PP.y = 425;
	p->sens= 0;
	p->frame= 0;
	p->PSSaut = 0;
	p->speedup = 0 ;
	p->speeddown = 10 ;
	p->SENSSaut = 1;
	p->sol = 425 ;
	//p->police = TTF_OpenFont("police.ttf",50 );
	p->vitesse = 5;
	p->acceleration = 0;
}


void afficherPerso(perso* p,SDL_Surface *screen)
{
	if (p->sens == 0)
	{
		SDL_BlitSurface(p->PERDR,NULL,screen,&p->PP);
	}
	else
		SDL_BlitSurface(p->PERG,NULL,screen,&p->PP);
}


void animerPerso (perso* p,int numperso)
{

p->frame++;
if ( p->frame > 10 )
{
p->frame = 0;
}
if ( numperso == 1 ){
if ( p->frame == 0 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("asr.png");
p->PERG= IMG_Load("asl.png");

}
if ( p->frame == 1 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("asr.png");
p->PERG= IMG_Load("asl.png");

}
if ( p->frame == 2 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("awr.png");
p->PERG= IMG_Load("awl.png");

}
if ( p->frame == 3 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("awr.png");
p->PERG= IMG_Load("awl.png");

}
if ( p->frame == 4 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("ahr.png");
p->PERG= IMG_Load("ahl.png");

}
if ( p->frame == 5 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("ahr.png");
p->PERG= IMG_Load("ahl.png");

}
if ( p->frame == 6 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("ahr.png");
p->PERG= IMG_Load("ahl.png");

}
if ( p->frame == 7 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("asr.png");
p->PERG= IMG_Load("asl.png");

}
if ( p->frame == 8 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("asr.png");
p->PERG= IMG_Load("asl.png");

}
if ( p->frame == 9 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("awr.png");
p->PERG= IMG_Load("awl.png");

}
if ( p->frame == 10 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("awr.png");
p->PERG= IMG_Load("awl.png");

}
}

//2eme joueur
else if ( numperso == 2 ){
if ( p->frame == 0 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("asr.png");
p->PERG= IMG_Load("asl.png");

}
}
}

void libererPerso(perso* h)
{
	SDL_FreeSurface(h->PERDR);
	SDL_FreeSurface(h->PERG);
	//SDL_FreeSurface(h->text_score);
	//TTF_CloseFont(h->police);

}




void saut(perso* P)
{

    if ( P->PSSaut == 1 )
    {
        if ( P->gravite == 0 )
        {
            P->PP.y -= (P->PP.y/8);
            SDL_Delay(P->speedup);
        }
        if( P->speedup <= 5)
        {
            P->speedup +=1;
        }

        if ( P->PP.y <= 220 )
        {
            P->gravite = 1;
        }
        if ( P->gravite == 1 )
        {
            SDL_Delay(P->speeddown);
            if ( P->speeddown >=1 )
            {
                P->speeddown -= 1;
            }
            if ( P->PP.y >= P->sol )
            {
                P->PP.y = P->sol;
                reinitsaut(P);
                P->PSSaut = 0;
            }
            if ( P->PP.y != P->sol )
            {
                P->PP.y += (P->PP.y/8);
            }
        }


    }
}


void reinitsaut (perso* p )
{
    p->speeddown = 20;
    p->speedup = 0;
    p->gravite = 0;
}






int choixPerso()
{
   SDL_Event event;
    int continuer=1;
 while(continuer == 1)
    {

        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;

            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE://pour quitter
                continuer=0;

                break;

            case SDLK_RIGHT :
            {
		return 1;
            }
            break;

            case SDLK_LEFT :
            {
		return 2;
            }
            break;


            }
            break;


        }


    }

}

void animerPerso2 (perso* p,int numperso)
{

p->frame++;
if ( p->frame > 10 )
{
p->frame = 0;
}
if ( numperso == 1 ){
if ( p->frame == 0 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("rsr.png");
p->PERG= IMG_Load("rsr.png");

}
if ( p->frame == 1 )
{
SDL_FreeSurface(p->PERDR);
SDL_FreeSurface(p->PERG);
p->PERDR= IMG_Load("rwr.png");
p->PERG= IMG_Load("rwr.png");

}
}
}

void init2(perso* p,int numperso)
{
	p->PERDR= NULL;
	p->PERG= NULL;
	p->PERHIT= NULL;
	if ( numperso == 1 ){
		p->PERDR= IMG_Load("rwr.png");
		p->PERG= IMG_Load("rwr.png");
	}else if ( numperso == 2 )
	{
		// 2eme joueur
		p->PERDR= IMG_Load("rsr.png");
		p->PERG= IMG_Load("rsr.png");
	}
	
        
        p->gravite = 0;
	p->VIT=0;
	//p->text_score = NULL;
	//p->positionscore.x = 0;
	//p->positionscore.y = 80;
	//p->score = 100;
	p->PP.x = 900;
	p->PP.y = 425;
	p->hit=0;
	p->sens= 0;
	p->frame= 0;
	p->PSSaut = 0;
	p->speedup = 0 ;
	p->speeddown = 10 ;
	p->SENSSaut = 1;
	p->sol = 225 ;
	//p->police = TTF_OpenFont("police.ttf",50 );
	p->vitesse = 5;
	p->acceleration = 0;
}

void initialiser_sous(image *imge)
{ 
   
       imge->url=("sous.png");
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=700;
    imge->pos_img_affiche.w=1450;

}
void initialiser_me(image *imge)
{ 
   
       imge->url=("me.png");
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=700;
    imge->pos_img_affiche.w=1450;

}
void afficher_sous(SDL_Surface *screen, image imge){ 
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}


int st(){

 SDL_Surface *screen;
    image s,s1,s2,s3,pro;
    SDL_Event event,events;
    int boucle1=1;
    coin c;

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) ==-1)
    {
        printf("Could not initialize SDL: %s. \n", SDL_GetError());
        return -1;
    }

    screen=SDL_SetVideoMode(730,470,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);

    initialiser_ss(&s);
    initialiser_ss1(&s1);
    initialiser_ss2(&s2);
    initialiser_ss3(&s3);
    initialiser_ppro(&pro);
    afficher_s(screen,s);
    afficher_pro(screen,pro);
    chargercoinc(&c,screen);
     afficher(&c,screen);
 int p=0;
 int etat;
 SDL_Flip(screen);
    while(boucle1!=0)
    {                   if(p==1){
                         afficher_s(screen,s1);
                         afficher_pro(screen,pro);
                         chargercoinc(&c,screen);
                         afficher(&c,screen);
                         }
                         else if(p==2){
                         afficher_s(screen,s2);
                         afficher_pro(screen,pro);
                         chargercoinc(&c,screen);
                         afficher(&c,screen);
                         }
                         else if(p==3){
                         afficher_s(screen,s3);
                         afficher_pro(screen,pro);
                         chargercoinc(&c,screen);
                         afficher(&c,screen);
                         }
                         else if(p==0){
                         afficher_s(screen,s);
                         afficher_pro(screen,pro);
                         chargercoinc(&c,screen);
                         afficher(&c,screen);
                         }
    
        while(SDL_PollEvent(&event))
        { 
            switch(event.type){
            
                case SDL_QUIT:
                    boucle1=0;
                    
                    break;
                                      
                case SDL_MOUSEBUTTONDOWN: 
                
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<81 && event.button.x>38 && event.button.y<438&& event.button.y>392 ){
                         return 1;
                         } 
                         boucle1=0;
                         } 
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<613 && event.button.x>580 && event.button.y<268&& event.button.y>222){
                           p=p+1; 
                         } 
                         boucle1=1;
                         }       
               if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<145 && event.button.x>113 && event.button.y<281&& event.button.y>236){
                           p=p-1; 
                         } 
                         boucle1=1;
                         }              
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<268 && event.button.x>161 && event.button.y<342&& event.button.y>307){
                              if (p==0){
                              etat=enigme();                                
                              }
                              if (etat==1){
                             save_coin(3);
                             }
                         } 
                         boucle1=1;
                         }               
                    break;
                    /*case SDL_MOUSEMOTION:// mouvement de sourie

		{
		//printf("Souris en position %d %d\n",event.motion.x, event.motion.y);// yekteblek les coordonnees ta3 sourie mta3ek fel terminal
		}   
		break;*/
            }
        }   

        SDL_Flip(screen); }

    
    liberer_image(s); 
    liberer_image(s1);  
    liberer_image(s2);
    liberer_image(s3); 
    liberer_image(pro);
    SDL_Quit();
 return 1;
}
void initialiser_ss(image *imge)
{ 
   imge->url=("shop0.png");

    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=470;
    imge->pos_img_affiche.w=730;

}
void initialiser_ss1(image *imge)
{  
       imge->url=("shop1.png");

    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=470;
    imge->pos_img_affiche.w=730;
}
void initialiser_ss2(image *imge)
{ 
       imge->url=("shop2.png");

    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
   imge->pos_img_affiche.h=470;
    imge->pos_img_affiche.w=730;

}
void initialiser_ss3(image *imge)
{ 
       imge->url=("shop3.png");

    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=470;
    imge->pos_img_affiche.w=730;
}

void initialiser_ppro(image *imge)
{  
   
     imge->url=("propic.png");  
   
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=470;
    imge->pos_img_affiche.w=730;
}
 void initialiser_menu(image *imge,int f)
{  
   if(f==1){
     imge->url=("menuf.png");}
   if (f==-1){
      imge->url=("menu.png");}
      
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}
  void initialiser_pro(image *imge,int f)
{  
   if(f==1){
     imge->url=("propic.png");}
   if (f==-1){
      imge->url=("propic.png");}
      
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}

  void chargercoinc(coin *c,SDL_Surface *screen){
    char n[20];
    SDL_Color Color={255,255,255};
    FILE *fichier = NULL;
    fichier = fopen("coin.txt", "r");   
    fscanf(fichier, "%s ",n);
     c->pos_c1.x=1124;
     c->pos_c1.y=71;
      c->police=TTF_OpenFont("Ubuntu-MediumItalic.ttf",22 );
     c->c1=TTF_RenderText_Blended(c->police,n,Color);
    fclose(fichier);
} 
void initialiser_levels(image *imge,int f)
{ 
   
   if(f==1){
       imge->url=("levelsf.png");}
   if (f==-1){
       imge->url=("l.png");}

    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();

}


void initialiser_b1(image *imge,int f)
{  

    if(f==1){
        imge->url=("bf1.png");}
   if (f==-1){
        imge->url=("b1.png");}

  
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}

void initialiser_b2(image *imge,int f)
{ 
    if(f==1){
       imge->url=("bf2.png");}
   if (f==-1){
        imge->url=("b2.png");}
        
  
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}

void initialiser_b3(image *imge,int f)
{
    if(f==1){
        imge->url=("bf3.png");}
   if (f==-1){
       imge->url=("b3.png");}
       
  
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}

void initialiser_l1(image *imge,int f)
{
    if(f==1){
        imge->url=("level1f.png");}
    if (f==-1){
       imge->url=("l1.png");}

    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}

void initialiser_l2(image *imge,int f)
{
    if(f==1){
        imge->url=("level2f.png");}
   if (f==-1){
        imge->url=("l2.png");}

  
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}

void initialiser_l3(image *imge,int f)
{
    if(f==1){
        imge->url=("level3f.png");}
   if (f==-1){
        imge->url=("l3.png");}
        
  
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}

void initialiser_l4(image *imge,int f)
{
    if(f==1){
        imge->url=("level4f.png");}
   if (f==-1){
        imge->url=("l4.png");}
        
  
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}

void initialiser_00(image *imge,int f)
{
    if(f==1){
        imge->url=("00f.png");}
   if (f==-1){
        imge->url=("00.png");}

  
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}
void initialiser_20(image *imge,int f)
{  
    if(f==1){
        imge->url=("11f.png");}
   if (f==-1){
        imge->url=("20.png");}

 
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}
void initialiser_40(image *imge,int f)
{ 
    if(f==1){
        imge->url=("22f.png");}
   if (f==-1){
        imge->url=("40.png");}


  
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}
void initialiser_60(image *imge,int f)
{

    if(f==1){
       imge->url=("33f.png");}
   if (f==-1){
        imge->url=("60.png");}
        
  
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}
void initialiser_80(image *imge,int f)
{
    if(f==1){
        imge->url=("44f.png");}
   if (f==-1){
        imge->url=("80.png");}

  
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}
void initialiser_100(image *imge,int f)
{
      if(f==1){
        imge->url=("55f.png");}
   if (f==-1){
       imge->url=("100.png");}

  
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}

void initialiser_op2(image *imge,int f)
{  
   if(f==1){
     imge->url=("seet.png");}
   if (f==-1){
      imge->url=("seet.png");}
      
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}
void initialiser_bs(image *imge,int f)
{  
   if(f==1){
     imge->url=("bs.png");}
   if (f==-1){
      imge->url=("bs.png");}
      
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}

void initialiser_p(image *imge,int f)
{  
   if(f==1){
     imge->url=("pro.png");}
   if (f==-1){
      imge->url=("pro.png");}
      
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}



void initialiser_s(image *imge,int f)
{ 
   if(f==1){
       imge->url=("shop0.png");}
   if (f==-1){
       imge->url=("shop0.png");}

    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();

}
void initialiser_s1(image *imge,int f)
{ 
   if(f==1){
       imge->url=("shop1.png");}
   if (f==-1){
       imge->url=("shop1.png");}

    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();

}
void initialiser_s2(image *imge,int f)
{ 
   if(f==1){
       imge->url=("shop2.png");}
   if (f==-1){
       imge->url=("shop2.png");}

    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();

}
void initialiser_s3(image *imge,int f)
{ 
   if(f==1){
       imge->url=("shop3.png");}
   if (f==-1){
       imge->url=("shop3.png");}

    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();

}
void initialiser_score(image *imge,int f)
{  
    if(f==1){
        imge->url=("score.png");}
   if (f==-1){
        imge->url=("score.png");}

 
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}

 void initialiser_p1(image *imge,int f)
{  
   if(f==1){
     imge->url=("profpic.png");}
   if (f==-1){
      imge->url=("profpic.png");}
      
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}
 void initialiser_p2(image *imge,int f)
{  
   if(f==1){
     imge->url=("propic2.png");}
   if (f==-1){
      imge->url=("propic2.png");}
      
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}





void enterPlayerName(char playerName[], SDL_Surface *screen, int *continuer)
{

    TTF_Font *font = NULL;
    font = TTF_OpenFont("Retro.ttf", 24);

    SDL_Color textColor = {255, 255, 255};

    SDL_Event event;

    int loop = 1;
    while (loop)
    {

        SDL_FillRect(screen, NULL, 0x000000);
        renderText(screen, font, textColor, "Choose a name: ", 10, 10);

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                loop = 0;
                *continuer = 0;
                break;

            case SDL_KEYDOWN:
                if (strlen(playerName) < 20)
                {
                    if (event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z)
                    {
                        strncat(playerName, SDL_GetKeyName(event.key.keysym.sym), 1);
                    }
                }
                if (event.key.keysym.sym == SDLK_BACKSPACE && strlen(playerName) > 0)
                {
                    playerName[strlen(playerName) - 1] = '\0';
                }
                if (event.key.keysym.sym == SDLK_RETURN && strlen(playerName) > 0)
                {
                    loop = 0;
                }
                break;
            }
        }

        renderText(screen, font, textColor, playerName, 200, 50);

        SDL_Flip(screen);
    }
    TTF_CloseFont(font);
}
void initBack(background *b)
{
    int i, w;
    b->image[0] = IMG_Load("stage2.png");
    b->image[1] = IMG_Load("stage3.png");
    b->stageLoaded = 0;
    b->camera.x = 0;
    b->camera.y = 0;
    b->camera.h = 800;
    b->camera.w = 1450;

    b->animation.spriteSheet = IMG_Load("");
    b->animation.frames = 5;
    b->animation.clipLoaded = 0;
    for (i = 0, w = 0; i < b->animation.frames; i++, w += 500)
    {
        b->animation.Clips[i].w = 400;
        b->animation.Clips[i].h = 450;
        b->animation.Clips[i].x = w;
        b->animation.Clips[i].y = 0;
    }

    b->rain.spriteSheet = IMG_Load("rain_spritesheet.png");
    b->rain.frames = 8;
    b->rain.clipLoaded = 0;
    for (i = 0, w = 0; i < b->rain.frames; i++, w += 1450)
    {
        b->rain.Clips[i].w = 1450;
        b->rain.Clips[i].h = 800;
        b->rain.Clips[i].x = w;
        b->rain.Clips[i].y = 0;
    }
}
void afficherback(background b, SDL_Surface *screen)
{
    SDL_BlitSurface(b.image[b.stageLoaded], &b.camera, screen, &b.pos);
    SDL_BlitSurface(b.rain.spriteSheet, &b.rain.Clips[b.rain.clipLoaded], screen, NULL);

    SDL_BlitSurface(b.animation.spriteSheet, &b.animation.Clips[b.animation.clipLoaded], screen, NULL);
}
void scrolling(background *b, int direction, int pasAvancement)
{
    switch (direction)
    {
    case 1:
        b->camera.x += pasAvancement;
        break;

    case 2:
        if (b->camera.x >= 0)
            b->camera.x -= pasAvancement;
        break;
    case 3:
        if (b->camera.y >= 0)
            b->camera.y -= pasAvancement;
        break;

    case 4:
        b->camera.y += pasAvancement;
        break;
    }
}

void saveScore(ScoreInfo s, char nomfichier[])
{
    FILE *f;
    f = fopen(nomfichier, "a");
    if (f != NULL)
        fprintf(f, "%s %d %d\n", s.playerName, s.score, s.temps);
    fclose(f);
}

void bestScore(char *filename, ScoreInfo t[])
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return;
    }

    int n = 0;
    while (fscanf(fp, "%s %d %d", t[n].playerName, &t[n].score, &t[n].temps) != EOF)
    {
        n++;
    }

    fclose(fp);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].score < t[j].score || (t[i].score == t[j].score && t[i].temps > t[j].temps))
            {
                ScoreInfo tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}

void showBestScore(ScoreInfo t[], SDL_Surface *screen, int *continuer)
{
    TTF_Font *font = NULL;
    font = TTF_OpenFont("Retro.ttf", 12);

    SDL_Color textColor = {255, 255, 255};

    SDL_Surface *leader;
    leader = IMG_Load("best.png");

    int loop = 1;
    SDL_Event event;

    SDL_FillRect(screen, NULL, 0x000000);
    SDL_BlitSurface(leader, NULL, screen, NULL);
    int y = 170;
    for (int i = 0; i < 3; i++)
    {
        char nom[100];
        char info[100];

        sprintf(nom, "Nom du joueur : %s", t[i].playerName);
        sprintf(info, "Score : %d, Temps : %d", t[i].score, t[i].temps);

        renderText(screen, font, textColor, nom, 320, y);
        renderText(screen, font, textColor, info, 320, y + 50);
        y += 150;
    }
    SDL_Flip(screen);
    while (loop)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                loop = 0;
                *continuer = 0;
                break;
            }
        }
    }
}


void afficher_menu(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}

void afficher_p(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_s(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_pro(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_option(SDL_Surface *screen,image imge){
    
    SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}
 void afficher_bs(SDL_Surface *screen,image imge){
    
    SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_levels(SDL_Surface *screen,image imge){
    
    SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_b1(SDL_Surface *screen, image imge){
  
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_b2(SDL_Surface *screen, image imge){
   
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_b3(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}

void afficher_l1(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_l2(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_l3(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_l4(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_op(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}

void liberer_image(image imge){
    SDL_FreeSurface(imge.img);
}

int option(int f){

    SDL_Surface *screen;
    image IMAGE,i0,i20,i40,i60,i80,i100,bs,op,p,s;
    Mix_Music *music;
    Mix_Chunk *mus;
    texte txte,txe;
    SDL_Event event,events;
    int boucle1=1,i=1,boucle=1,bouclep=1;
    int volume;
    
    int SCREEN_w=get_screenw();
    int SCREEN_h=get_screenh();
    
    
    volume=get_volume();

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) ==-1)
    {
        printf("Could not initialize SDL: %s. \n", SDL_GetError());
        return -1;
    }
    initialiser_00(&s,f);
    initialiser_00(&i0,f);
    initialiser_p(&p,f);
    initialiser_20(&i20,f);
    initialiser_40(&i40,f);
    initialiser_60(&i60,f);
    initialiser_80(&i80,f);
    initialiser_100(&i100,f);
    initialiser_bs(&bs,f);
    initialiser_op2(&op,f);
    
    volume=get_volume();

    while(boucle1!=0)
    {   SCREEN_w=get_screenw();
        SCREEN_h=get_screenh(); 
        screen=SDL_SetVideoMode(SCREEN_w,SCREEN_h,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
        initialiser_00(&i0,f);
        initialiser_20(&i20,f);
        initialiser_40(&i40,f);
        initialiser_60(&i60,f);
        initialiser_80(&i80,f);
        initialiser_100(&i100,f);
        initialiser_00(&s,f);
        boucle=1;
    
        initialiser_audio(music,volume);
         
         if (volume ==0){ 
        initialiser_00(&i0,f);     
        afficher_option(screen,i0);
        afficher_bs(screen,bs);
          }
        else if (volume == 20){ 
        afficher_option(screen,i20);
        afficher_bs(screen,bs);    
          }
        else if (volume == 40){ 
        
        afficher_option(screen,i40); 
        afficher_bs(screen,bs);
          }
           else if (volume == 60){   
        afficher_option(screen,i60);
        afficher_bs(screen,bs);
          }
           else if (volume == 80){    
        afficher_option(screen,i80);
         afficher_bs(screen,bs);  
          }
           else if (volume == 100){
        afficher_option(screen,i100);
        afficher_bs(screen,bs);
          }
             
        while(SDL_PollEvent(&event))
        {        
            switch(event.type){
               
                case SDL_QUIT:
                    boucle1=0;
                    break;
                    
                case SDL_MOUSEBUTTONDOWN: 
                
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<439 && event.button.x>299 && event.button.y<441 && event.button.y>403 || event.button.x<816 && event.button.x>564 && event.button.y<572 && event.button.y> 527 ){
                          return f;
                         } 
                    }boucle1=0; 
                    
                
                 if(event.button.button==SDL_BUTTON_LEFT ){
                 
                           if  (event.button.x<256 && event.button.x>230 && event.button.y<249 && event.button.y>220 ||event.button.x<471 && event.button.x>429 && event.button.y<322 && event.button.y>291   ){                                       
                                  if (volume >0 )
                                {initialiser_audiobref(mus);
                                 volume =volume-20;
                                 save_volume(volume); }
                                 if (volume ==0){ 
                                  
                                     afficher_option(screen,i0);
                                      afficher_bs(screen,bs);   
                                    }
                                 else if (volume == 20){
                                     afficher_option(screen,i20);
                                      afficher_bs(screen,bs);                           
                                    }
                                 else if (volume == 40){   
                                      afficher_option(screen,i40); 
                                      afficher_bs(screen,bs);                                   
                                    }
                                 else if (volume == 60){                           
                                      afficher_option(screen,i60);
                                       afficher_bs(screen,bs);                               
                                     }
                                 else if (volume == 80){
                                      afficher_option(screen,i80); 
                                        afficher_bs(screen,bs);                
                                     }
                                  else if (volume == 100){
                                     afficher_option(screen,i100);
                                     afficher_bs(screen,bs);
                                    }
                                   
                                    boucle1=1; 
                         } 
 
              else  if  (event.button.x<513 && event.button.x>487 && event.button.y<247 && event.button.y>224 || event.button.x<964 && event.button.x>917 && event.button.y<324 && event.button.y>291 ){
              
                                  if (volume < 100)
                                 {initialiser_audiobref(mus);
                                  volume =volume + 20;
                                  save_volume(volume);      
                                     }
                                  if (volume ==0){                                     
                                     afficher_option(screen,i0);
                                     afficher_bs(screen,bs);                                    
                                    }
                                 else if (volume == 20){
         
                                     afficher_option(screen,i20); 
                                     afficher_bs(screen,bs);             
                                    }
                                 else if (volume == 40){     
                                      afficher_option(screen,i40); 
                                      afficher_bs(screen,bs);          
                                    }
                                 else if (volume == 60){
                                 afficher_bs(screen,bs);
                                      afficher_option(screen,i60);                                     
                                     }
                                 else if (volume == 80){
                                      afficher_option(screen,i80); 
                                      afficher_bs(screen,bs);                                  
                                     }
                                  else if (volume == 100){                                 
                                     afficher_option(screen,i100);
                                     afficher_bs(screen,bs);                      
                                     }   
                                     boucle1=1;             
                       }
                       
                       else  if  (event.button.x<442 && event.button.x>299 && event.button.y<351 && event.button.y>306 ||event.button.x<816 && event.button.x>564 && event.button.y<455 && event.button.y>409){
                          f=-f;
                           if (f==1){
                            save_screen(616,1364);     
                          }
                          if (f==-1){
                           save_screen(470,730);                     
                               }
                         boucle1=1;
                       }  
                       
                        else  if  (event.button.x<716 && event.button.x>672 && event.button.y<259 && event.button.y>227 ){ 
                           while(boucle!=0){
                        
                           afficher_op(screen,op);
                           while(SDL_PollEvent(&event))
                           {        
                               switch(event.type){
               
                                    case SDL_QUIT:
                                  boucle=0;
                                  break;
                                  case SDL_MOUSEBUTTONDOWN: 
                
                               if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<442 && event.button.x>297 && event.button.y<441 && event.button.y>397  ){
                          return f;
                         } 
                             }boucle=0;boucle1=0;
                      
                           if(event.button.button==SDL_BUTTON_LEFT ){
                           if  (event.button.x<77 && event.button.x>40 && event.button.y<275 && event.button.y>245){
                           boucle=0;
                           }
                           else if (event.button.x<444 && event.button.x>298 && event.button.y<182 && event.button.y>139){
                            afficherscore();
                            boucle=1;
                           }
                           else if (event.button.x<441 && event.button.x>303 && event.button.y<263 && event.button.y>225){
                           afficherprofile();
                           boucle=1;
                           }
                           else if (event.button.x<438 && event.button.x>298 && event.button.y<350 && event.button.y>308){
                           afficherpropic();
                           boucle=1;
                           }
                           }                      
     }
                                  }
                               SDL_Flip(screen);   
                           }
                         
                      } boucle1=1; 
                     break;
                     
                  
                  
      }  } SDL_Flip(screen);        
        } 
    }
    save_volume(volume);
    liberer_image(IMAGE);
    liberer_image(i0); 
    liberer_image(i20);
    liberer_image(i40);
    liberer_image(i60);
    liberer_image(i80); 
    liberer_image(i100);
    liberer_image(op);  
    liberer_musique(music);
    liberer_musiquebref(mus);
    SDL_Quit();
    return f;
}

int levels(int f){

    SDL_Surface *screen;
    image IMAGE,l1,l2,l3,l4;
    Mix_Music *music;
    Mix_Chunk *mus;
    SDL_Event event,events;
    int boucle1=1,i=1,b11=0,b12=0,b13=0,b14=0,b15=0;
    int volume;
    int SCREEN_w=get_screenw();
    int SCREEN_h=get_screenh();
    int v=0;
    
    volume=get_volume();
 
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) ==-1)
    {
        printf("Could not initialize SDL: %s. \n", SDL_GetError());
        return -1;
    }

    screen=SDL_SetVideoMode(SCREEN_w,SCREEN_h,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);

    initialiser_levels(&IMAGE,f);
    initialiser_audio(music,volume);
    initialiser_l1(&l1,f);
    initialiser_l2(&l2,f);
    initialiser_l3(&l3,f);
    initialiser_l4(&l4,f);
    
 afficher_levels(screen,IMAGE);
 SDL_Flip(screen);
    while(boucle1!=0)
    {   
       
        if (f==-1){ 
        b11=0;
        b12=0;
        b13=0;
        b14=0;
        b15=0;
    
        while(SDL_PollEvent(&event))
        { 
            switch(event.type){
            
                case SDL_QUIT:
                    boucle1=0;
                    
                    break;
                                      
                case SDL_MOUSEBUTTONDOWN: 
                
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<123 && event.button.x>52 && event.button.y<442 && event.button.y>409 ){
                         return 1;
                          boucle1=0;
                         } 
                        
                         else if (event.button.x<309 && event.button.x>149 && event.button.y<206 && event.button.y>104 ){
                         f=play();    
                         boucle1=1;
                        
                         }
                         }              
                    break;
                    
                 case SDL_MOUSEMOTION:
               
                      if(event.motion.x<309 && event.motion.x>149 && event.motion.y<206 && event.motion.y>104){ 
                       
                        b11=1;   
                                                        
                         afficher_l1(screen,l1);                                                                              
                                                 
                       }
          
                      else if (event.motion.x<619 && event.motion.x>457 && event.motion.y<206 && event.motion.y>105 ){                              
                              b12=1;
                             
                               afficher_l2(screen,l2);   
                                   }   
           
                      else if(event.motion.x<313 && event.motion.x>148 && event.motion.y<404 && event.motion.y>304){                            
                            b13=1;
                             
                                 afficher_l3(screen,l3);                                
                                 }
                                 
                     else if(event.motion.x<619 && event.motion.x>457 && event.motion.y<400 && event.motion.y>301){                            
                            b14=1;
                            
                                 afficher_l4(screen,l4);                                 
                                 }  
                                  
                     else if(event.motion.x<123 && event.motion.x>52 && event.motion.y<435 && event.motion.y>409){                              b15=1;                        
                            
                             afficher_levels(screen,IMAGE);                                
                                }   
                                
                     else if(b11==0 && b12==0 && b13==0 && b14==0 && b15==0){   
                          	  afficher_levels(screen,IMAGE);   
	    }
                    break;
               
            }
        }   
        SDL_Flip(screen); }
        if(f==1){ 
        b11=0;
    b12=0;
    b13=0;
    b14=0;
    b15=0;
    
        while(SDL_PollEvent(&event))
        { 
            switch(event.type){
            
                case SDL_QUIT:
                    boucle1=0;
                    
                    break;
                                      
                case SDL_MOUSEBUTTONDOWN: 
                
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<232 && event.button.x>140 && event.button.y<569 && event.button.y>545 ){
                         return 1;
                         } 
                         boucle1=0;
                         } 
                           
                    break;
                    
                 case SDL_MOUSEMOTION:
                 
                 
                      if(event.motion.x<588 && event.motion.x>281 && event.motion.y<269 && event.motion.y>133){ 
                       
                        b11=1;   
                                                        
                         afficher_l1(screen,l1);                                                                              
                                                 
                       }
          
                      else if ( event.motion.x<1161 && event.motion.x>854 && event.motion.y<269 && event.motion.y>135){                              
                              b12=1;
                             
                               afficher_l2(screen,l2);   
                                   }   
           
                      else if(event.motion.x<586 && event.motion.x>280 && event.motion.y<523 && event.motion.y>385){                            
                            b13=1;
                             
                                 afficher_l3(screen,l3);                                
                                 }
                                 
                     else if(event.motion.x<1159 && event.motion.x>853 && event.motion.y<523 && event.motion.y>394){                            
                            b14=1;
                            
                                 afficher_l4(screen,l4);                                 
                                 }  
                                  
                     else if(event.motion.x<232 && event.motion.x>140 && event.motion.y<569 && event.motion.y>545){                              b15=1;                        
                            
                             afficher_levels(screen,IMAGE);                                
                                }   
                                
                     else if(b11==0 && b12==0 && b13==0 && b14==0 && b15==0){   
                          	  afficher_levels(screen,IMAGE);   
	    }
                    break;
               
            }
        }   
        SDL_Flip(screen); }
    }
    
    
    liberer_image(IMAGE); 
    liberer_image(l1);  
    liberer_image(l2);
    liberer_image(l3);
    liberer_image(l4);    
    liberer_musique(music);
    liberer_musiquebref(mus);
          
    SDL_Quit();
 return 1;
}

void save_screen(int h,int w)
{
    FILE *fichier = NULL;
    fichier = fopen("screen.txt", "w");
    fprintf(fichier, "%d %d", h,w);
    fclose(fichier);
}

int get_screenh()
{
    int h,w;
    FILE *fichier = NULL;
    fichier = fopen("screen.txt", "r");
    while (!feof(fichier))
        fscanf(fichier, "%d %d", &h,&w);
    fclose(fichier);
    return h;
}
int get_screenw()
{
    int h,w;
    FILE *fichier = NULL;
    fichier = fopen("screen.txt", "r");
    while (!feof(fichier))
        fscanf(fichier, "%d %d", &h,&w);
    fclose(fichier);
    return w;
}
void initialiser_audio (Mix_Music *music,int volume)
{
    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
        printf ("%s",SDL_GetError());
    }
    music=Mix_LoadMUS("music1.mp3");
    Mix_PlayMusic(music,-1);
    Mix_VolumeMusic(volume);
}

void liberer_musique (Mix_Music *music)
{
    Mix_FreeMusic(music);
}

void initialiser_audiobref (Mix_Chunk *music)
{
    Mix_OpenAudio (44100,MIX_DEFAULT_FORMAT,2,2048);
    music=Mix_LoadWAV("bref.wav");
    Mix_PlayChannel(-1,music,0);
    if (music==NULL) printf ("%s",SDL_GetError());
}

void liberer_musiquebref(Mix_Chunk *music)
{
    Mix_FreeChunk(music);
}

void save_volume(int volume)
{
    FILE *fichier = NULL;
    fichier = fopen("volume.txt", "w");
    fprintf(fichier, "%d", volume);
    fclose(fichier);
}

int get_volume()
{
    int volume;
    FILE *fichier = NULL;
    fichier = fopen("volume.txt", "r");
    while (!feof(fichier))
        fscanf(fichier, "%d", &volume);
    fclose(fichier);
    return volume;
}

void initialiser_texte (texte *txte,int f)
{   int i;
   if(f==1){
        txte->pos_txt.x=460;
        txte->pos_txt.y=35;
    i=220;}
   if (f==-1){
    txte->pos_txt.x=240;
    txte->pos_txt.y=90;
    i=120;}

    TTF_Init();
    txte->police=TTF_OpenFont("Ubuntu-B.ttf",i);
    if(!(txte->police)){
        printf("TTF_OpenFont: %s\n",TTF_GetError());
    }
    txte->color_txt.r=0;
    txte->color_txt.g=0;
    txte->color_txt.b=0;
}


void afficher_texte (SDL_Surface *screen, texte txte)
{   char s[20]="skin";
    if(screen==NULL){
        printf("Error\n");
        return;
    }
    
    txte.txt=TTF_RenderText_Solid(txte.police,s,txte.color_txt);
    if(txte.txt==NULL){
        printf("ERROR with text! %s\n",TTF_GetError());
        return;
    }
    if(SDL_BlitSurface(txte.txt,NULL,screen,&txte.pos_txt)!=0){
        printf("Error Surface: %s\n",SDL_GetError());
    }
}

void liberer_texte (texte txte)
{
    TTF_CloseFont(txte.police);
    TTF_Quit();
}

int store(int f){

   
 SDL_Surface *screen;
    image s,s1,s2,s3,pro;
    Mix_Music *music;
    Mix_Chunk *mus;
    SDL_Event event,events;
    int boucle1=1;
    int volume;
    int SCREEN_w=get_screenw();
    int SCREEN_h=get_screenh();
    coin c;
    volume=get_volume();
 
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) ==-1)
    {
        printf("Could not initialize SDL: %s. \n", SDL_GetError());
        return -1;
    }

    screen=SDL_SetVideoMode(SCREEN_w,SCREEN_h,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);


    initialiser_audio(music,volume);
    initialiser_s(&s,f);
    initialiser_s1(&s1,f);
    initialiser_s2(&s2,f);
    initialiser_s3(&s3,f);
    initialiser_pro(&pro,f);
    afficher_s(screen,s);
    afficher_pro(screen,pro);
    chargercoin(&c,screen);
     afficher(&c,screen);
 int p=0;
 int etat;
 SDL_Flip(screen);
    while(boucle1!=0)
    {                   if(p==1){
                         afficher_s(screen,s1);
                         afficher_pro(screen,pro);
                         chargercoin(&c,screen);
                         afficher(&c,screen);
                         }
                         else if(p==2){
                         afficher_s(screen,s2);
                         afficher_pro(screen,pro);
                         chargercoin(&c,screen);
                         afficher(&c,screen);
                         }
                         else if(p==3){
                         afficher_s(screen,s3);
                         afficher_pro(screen,pro);
                         chargercoin(&c,screen);
                         afficher(&c,screen);
                         }
                         else if(p==0){
                         afficher_s(screen,s);
                         afficher_pro(screen,pro);
                         chargercoin(&c,screen);
                         afficher(&c,screen);
                         }
    
        while(SDL_PollEvent(&event))
        { 
            switch(event.type){
            
                case SDL_QUIT:
                    boucle1=0;
                    
                    break;
                                      
                case SDL_MOUSEBUTTONDOWN: 
                
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<81 && event.button.x>38 && event.button.y<438&& event.button.y>392 ){
                         return 1;
                         } 
                         boucle1=0;
                         } 
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<613 && event.button.x>580 && event.button.y<268&& event.button.y>222){
                           p=p+1; 
                         } 
                         boucle1=1;
                         }       
               if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<145 && event.button.x>113 && event.button.y<281&& event.button.y>236){
                           p=p-1; 
                         } 
                         boucle1=1;
                         }              
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<268 && event.button.x>161 && event.button.y<342&& event.button.y>307){
                              if (p==0){
                              etat=enigme();                                
                              }
                              if (etat==1){
                             save_coin(3);
                             }
                         } 
                         boucle1=1;
                         }               
                    break;
                    /*case SDL_MOUSEMOTION:// mouvement de sourie

		{
		//printf("Souris en position %d %d\n",event.motion.x, event.motion.y);// yekteblek les coordonnees ta3 sourie mta3ek fel terminal
		}   
		break;*/
            }
        }   

        SDL_Flip(screen); }

    
    liberer_image(s); 
    liberer_image(s1);  
    liberer_image(s2);
    liberer_image(s3); 
    liberer_image(pro);
        liberer_musique(music);
    liberer_musiquebref(mus);
          
    SDL_Quit();
 return 1;
}

int enigme(){
 FILE* fichier;
  Enigme e;
  personne p;
  background b;
  Score s;
 
  int et;
  char nomfichier;
  SDL_Surface *screen =NULL;
  SDL_Init(SDL_INIT_EVERYTHING);
  screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
  TTF_Init();
    init_enigme(&e,screen);
    init_q1(&e,screen); 
    init_q2(&e,screen); 
    init_q3(&e,screen); 
    init_q4(&e,screen);  
    genererEnigme(&e,&nomfichier); 
    et=resolution_enigme(&e,screen);
    free_enigme(&e);
    return et; 
}

void save_coin(int n)
{ char nt[20];
  int np;
    FILE *fichier = NULL;
    fichier = fopen("coin.txt", "r+");
    while (!feof(fichier)){
        fscanf(fichier, "%s ",nt);
        np=atoi(nt);
        }
     fclose(fichier); 
     remove("coin.txt");
    fichier = fopen("coin.txt", "w");  
         np=np+n;
        sprintf(nt, "%d", np);   
        fprintf(fichier, "%s", nt);
    fclose(fichier);
}

void chargercoin(coin *c,SDL_Surface *screen){
    char n[20];
    SDL_Color Color={255,255,255};
    FILE *fichier = NULL;
    fichier = fopen("coin.txt", "r");   
    fscanf(fichier, "%s ",n);
     c->pos_c1.x=426;
     c->pos_c1.y=30;
      c->police=TTF_OpenFont("Ubuntu-MediumItalic.ttf",22 );
     c->c1=TTF_RenderText_Blended(c->police,n,Color);
    fclose(fichier);
}
void afficher(coin *c,SDL_Surface *screen){
   SDL_BlitSurface(c->c1,NULL,screen,&c->pos_c1); 
}

void init_enigme(Enigme *e, SDL_Surface *screen){

    e->imag= IMG_Load("back.png");
    e->pos_imag.x = 0;
    e->pos_imag.y = 0; 
    e->num=0;
    e->etat=0;
    e->c =IMG_Load("win.png");
    e->w=IMG_Load("lose.png");
    e->pos_correct.x = 0;
    e->pos_correct.y = 0;
    e->pos_wrong.x = 0;
    e->pos_wrong.y = 0;
    
    e->police=TTF_OpenFont("Ubuntu-MediumItalic.ttf",22 );
    e->r1 = NULL;
    e->pos_r1.x=202;
    e->pos_r1.y=315;

    e->r2 = NULL;
    e->pos_r2.x=395;
    e->pos_r2.y=315;

    e->r3 = NULL;
    e->pos_r3.x=204;
    e->pos_r3.y=395;
    
    e->r4= NULL;
    e->pos_r4.x=394;
    e->pos_r4.y=395;

    e->police_q=TTF_OpenFont("Ubuntu-MediumItalic.ttf",30 );

    e->qes = NULL;
    e->pos_qes.x=250;
    e->pos_qes.y=111;
  
}
void init_q1(Enigme *e, SDL_Surface *screen){

    e->q1= IMG_Load("q1.png");
    e->pos_q1.x = 0;
    e->pos_q1.y = 0;
}
void init_q2(Enigme *e, SDL_Surface *screen){

    e->q2= IMG_Load("q2.png");
    e->pos_q2.x = 0;
    e->pos_q2.y = 0;
}
void init_q3(Enigme *e, SDL_Surface *screen){

    e->q3= IMG_Load("q3.png");
    e->pos_q3.x = 0;
    e->pos_q3.y = 0;
}
void init_q4(Enigme *e, SDL_Surface *screen){

    e->q4= IMG_Load("q4.png");
    e->pos_q4.x = 0;
    e->pos_q4.y = 0;
}
void afficherEnigme(Enigme *e,SDL_Surface * screen){
      
       SDL_BlitSurface(e->imag,NULL,screen,&e->pos_imag); 
       SDL_BlitSurface(e->r1,NULL,screen,&e->pos_r1);
       SDL_BlitSurface(e->r2,NULL,screen,&e->pos_r2);
       SDL_BlitSurface(e->r3,NULL,screen,&e->pos_r3);
       SDL_BlitSurface(e->r4,NULL,screen,&e->pos_r4);
       SDL_BlitSurface(e->qes,NULL,screen,&e->pos_qes);
}
void afficherq1(Enigme *e,SDL_Surface * screen){
      
       SDL_BlitSurface(e->q1,NULL,screen,&e->pos_q1); 
       SDL_BlitSurface(e->r1,NULL,screen,&e->pos_r1);
       SDL_BlitSurface(e->r2,NULL,screen,&e->pos_r2);
       SDL_BlitSurface(e->r3,NULL,screen,&e->pos_r3);
       SDL_BlitSurface(e->r4,NULL,screen,&e->pos_r4);
       SDL_BlitSurface(e->qes,NULL,screen,&e->pos_qes);
}
void afficherq2(Enigme *e,SDL_Surface * screen){
      
       SDL_BlitSurface(e->q2,NULL,screen,&e->pos_q2); 
       SDL_BlitSurface(e->r1,NULL,screen,&e->pos_r1);
       SDL_BlitSurface(e->r2,NULL,screen,&e->pos_r2);
       SDL_BlitSurface(e->r3,NULL,screen,&e->pos_r3);
       SDL_BlitSurface(e->r4,NULL,screen,&e->pos_r4);
       SDL_BlitSurface(e->qes,NULL,screen,&e->pos_qes);
}
void afficherq4(Enigme *e,SDL_Surface * screen){
      
       SDL_BlitSurface(e->q4,NULL,screen,&e->pos_q4); 
       SDL_BlitSurface(e->r1,NULL,screen,&e->pos_r1);
       SDL_BlitSurface(e->r2,NULL,screen,&e->pos_r2);
       SDL_BlitSurface(e->r3,NULL,screen,&e->pos_r3);
       SDL_BlitSurface(e->r4,NULL,screen,&e->pos_r4);
       SDL_BlitSurface(e->qes,NULL,screen,&e->pos_qes);
}
void afficherq3(Enigme *e,SDL_Surface * screen){
      
       SDL_BlitSurface(e->q3,NULL,screen,&e->pos_q3); 
       SDL_BlitSurface(e->r1,NULL,screen,&e->pos_r1);
       SDL_BlitSurface(e->r2,NULL,screen,&e->pos_r2);
       SDL_BlitSurface(e->r3,NULL,screen,&e->pos_r3);
       SDL_BlitSurface(e->r4,NULL,screen,&e->pos_r4);
       SDL_BlitSurface(e->qes,NULL,screen,&e->pos_qes);
}

void genererEnigme(Enigme *e, char *nomfichier){
        FILE* fichier = NULL;
        char ques[100] ;
	char rep1[20] ;
	char rep2[20] ;
	char rep3[20] ;
	char rep4[20] ;
	char np[10];
	int c,l=1;
	SDL_Color Color={0,0,0};
	srand(time(0));
	do {
		e->num = rand()%9 ;
	}while ( e->num <1 || e->num > 9 );

	fichier = fopen("enigme","r");
	if ( fichier != NULL )
	{
		while ( c!=EOF && l < e->num)
		{
			c= fgetc(fichier);
			if ( c == '\n')
				l++;
		}
		fscanf(fichier,"%s %s %s %s %s %s",ques,rep1,rep2,rep3,rep4,np);
		fclose(fichier);
	}
	e->qes =TTF_RenderText_Blended(e->police_q,ques,Color);
	e->r1 =TTF_RenderText_Blended(e->police,rep1,Color);
	e->r2 =TTF_RenderText_Blended(e->police,rep2,Color);
	e->r3 =TTF_RenderText_Blended(e->police,rep3,Color);
	e->r4 =TTF_RenderText_Blended(e->police,rep4,Color);
	e->np=atoi(np);
	
}

int resolution_enigme(Enigme *e,SDL_Surface* screen){

    SDL_Event event;
    int fin=1,np,rep=0,d=0;
    int b11=0,b12=0,b13=0,b14=0;
    Mix_Chunk *mus;
    
   while(fin == 1)
    {  afficherEnigme(e,screen);
     
    
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            e->etat=0;
            fin=0;

            break;
            
        case SDL_MOUSEBUTTONDOWN:
        {
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:
            {
                if ( event.button.x>178 && event.button.x<343 && event.button.y>304 && event.button.y<359) 
                {     
                    initialiser_audiobref(mus);
			rep=1;
			d=1;
			
                }
                else if ( event.button.x>371 && event.button.x<543 && event.button.y>302 && event.button.y<359) 
                {     
                    initialiser_audiobref(mus);
			rep=2;
			d=1;
			
                }
                else if ( event.button.x>177 && event.button.x<352 && event.button.y>383 && event.button.y<443) 
                {     
                    initialiser_audiobref(mus);
			rep=3;
			d=1;
			
                }
                else if ( event.button.x>369 && event.button.x<543 && event.button.y>373 && event.button.y<445) 
                {     
                    initialiser_audiobref(mus);
			rep=4;
			d=1;
			
                }  
            }
        }
        }break;
        case SDL_MOUSEMOTION:
               

                       if(event.motion.x<343 && event.motion.x>178 && event.motion.y<359 && event.motion.y>304){ 
                       
                        b11=1;   
                          initialiser_audiobref(mus);                             
                          afficherq1(e,screen);                                                                               
                                                
                       }
          
                      else if (event.motion.x<543 && event.motion.x>371 && event.motion.y<359 && event.motion.y>302 ){                              
                              b12=1;
                               initialiser_audiobref(mus);
                               afficherq2(e,screen);                                                         
                                
                                   }   
           
                      else if(event.motion.x<352 && event.motion.x>177 && event.motion.y<443 && event.motion.y>383 ){                            
                            b13=1;
                                  initialiser_audiobref(mus);
                                  afficherq3(e,screen);                               
                                                                
                                 }
                                 
                     else if(event.motion.x<543 && event.motion.x>369 && event.motion.y<445 && event.motion.y>373 ){                            
                            b14=1;
                                 initialiser_audiobref(mus);
                                 afficherq4(e,screen);                                 
                                                               
                                 }
                                 
                      else if(b11==0 && b12==0 && b13==0 && b14==0){       
                      afficherEnigme(e,screen);
                                
                      }
                    break;
        }         
     
       if ( rep == e->np && d==1 )
        {
            SDL_BlitSurface(e->c,NULL, screen, &e->pos_correct ); 
            e->etat=1;
            fin=0;
        }
        else if (rep!= e->np && d==1)
        {     
            SDL_BlitSurface(e->w,NULL, screen, &e->pos_wrong );
            e->etat=0;
            fin=0;
        }
        
        SDL_Flip(screen);

}
 SDL_Delay(1500);
 return e->etat;
}


void free_enigme( Enigme *e )
{
    SDL_FreeSurface(e->imag);
    SDL_FreeSurface(e->c);
    SDL_FreeSurface(e->w);
    SDL_FreeSurface(e->r1);
    SDL_FreeSurface(e->r2);
    SDL_FreeSurface(e->r3);
    SDL_FreeSurface(e->r4);
    SDL_FreeSurface(e->qes);
    TTF_CloseFont(e->police);
    TTF_CloseFont(e->police_q); 
}

int afficherscore(){

SDL_Surface *screen;
    image s;
    Mix_Music *music;
    Mix_Chunk *mus;
    SDL_Event event,events;
    int boucle1=1;
    int volume;
    int SCREEN_w=get_screenw();
    int SCREEN_h=get_screenh();
    volume=get_volume();
     int f=1;
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) ==-1)
    {
        printf("Could not initialize SDL: %s. \n", SDL_GetError());
        return -1;
    }

    screen=SDL_SetVideoMode(SCREEN_w,SCREEN_h,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);


    initialiser_audio(music,volume);
    initialiser_score(&s,f);
    
 SDL_Flip(screen);
    while(boucle1!=0)
    {   afficher_s(screen,s);      
        while(SDL_PollEvent(&event))
        { 
            switch(event.type){
            
                case SDL_QUIT:
                    boucle1=0;
                    
                    break;
                                      
                case SDL_MOUSEBUTTONDOWN: 
                
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<69 && event.button.x>24 && event.button.y<433&& event.button.y>412 ){
                         return 1;
                         } 
                         boucle1=0;
                         }            
                   }
        }   
        SDL_Flip(screen); }
   
    liberer_image(s); 
    liberer_musique(music);
    liberer_musiquebref(mus);
          
    SDL_Quit();
 return 1;
 
}



int afficherpropic(){

    SDL_Surface *screen;
    image p1,p2;
    Mix_Music *music;
    Mix_Chunk *mus;
    SDL_Event event,events;
    int boucle1=1;
    int volume;
    int SCREEN_w=get_screenw();
    int SCREEN_h=get_screenh();
    volume=get_volume();
    int f=1,p=1;
    coin c;
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) ==-1)
    {
        printf("Could not initialize SDL: %s. \n", SDL_GetError());
        return -1;
    }

    screen=SDL_SetVideoMode(SCREEN_w,SCREEN_h,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);

    initialiser_audio(music,volume);
    initialiser_p1(&p1,f);
    initialiser_p2(&p2,f);
    SDL_Flip(screen);
    while(boucle1!=0)
    {                   if(p==1){
                         afficher_s(screen,p1);                     
                         chargercoin(&c,screen);
                         afficher(&c,screen);
                         }
                         else if(p==2){
                         afficher_s(screen,p2);                       
                         chargercoin(&c,screen);
                         afficher(&c,screen);
                         }
    
        while(SDL_PollEvent(&event))
        { 
            switch(event.type){
            
                case SDL_QUIT:
                    boucle1=0;
                    
                    break;
                                      
                case SDL_MOUSEBUTTONDOWN: 
                
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<81 && event.button.x>38 && event.button.y<438&& event.button.y>392 ){
                         return 1;
                         } 
                         boucle1=0;
                         } 
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<613 && event.button.x>580 && event.button.y<268&& event.button.y>222){
                           p=p+1; 
                         } 
                         boucle1=1;
                         }       
               if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<145 && event.button.x>113 && event.button.y<281&& event.button.y>236){
                           p=p-1; 
                         } 
                         boucle1=1;
                         }              
                    break;
                    /*case SDL_MOUSEMOTION:// mouvement de sourie

		{
		//printf("Souris en position %d %d\n",event.motion.x, event.motion.y);// yekteblek les coordonnees ta3 sourie mta3ek fel terminal
		}   
		break;*/
            }
        }   
        SDL_Flip(screen); }
 
    liberer_image(p1);
    liberer_image(p2);  
    liberer_musique(music);
    liberer_musiquebref(mus);
    freec(&c);
          
    SDL_Quit();
 return 1; 
}

void chargerpro(pro *p,SDL_Surface *screen){
    char n[20];
    char p1[20];
    char a[20];
    SDL_Color Color={255,255,255};
    FILE *fichier = NULL;
    fichier = fopen("profile.txt", "r");   
    fscanf(fichier, "%s %s %s ",n,p1,a);
     p->pos_nom.x=342;
     p->pos_nom.y=266;
     p->pos_pre.x=344;
     p->pos_pre.y=181;
     p->pos_age.x=348;
     p->pos_age.y=355;
      p->police=TTF_OpenFont("Ubuntu-MediumItalic.ttf",22 );
     p->nom=TTF_RenderText_Blended(p->police,n,Color);
     p->pre=TTF_RenderText_Blended(p->police,p1,Color);
     p->age=TTF_RenderText_Blended(p->police,a,Color);
    fclose(fichier);
}

void afficherprof(pro *p,SDL_Surface *screen){
   SDL_BlitSurface(p->nom,NULL,screen,&p->pos_nom);
   SDL_BlitSurface(p->pre,NULL,screen,&p->pos_pre);
   SDL_BlitSurface(p->age,NULL,screen,&p->pos_age); 
}
int save_prof(char nom[],char pre[],char age[])
{ 
    FILE *fichier = NULL;
    fichier = fopen("profile1.txt", "w");
    while (!feof(fichier)){
        fprintf(fichier, "%s %s %s ",nom,pre,age);
        }
        fclose(fichier);
        remove("profile.txt");
        rename("profile1.txt","profile.txt");
      
return 1;
}

int afficherprofile(){

SDL_Surface *screen;
    image p;
    Mix_Music *music;
    Mix_Chunk *mus;
    SDL_Event event,events;
    int boucle1=1;
    int volume;
    int SCREEN_w=get_screenw();
    int SCREEN_h=get_screenh();
    volume=get_volume();
     int f=1,m=0;
     pro pi;
     char pre[20]="username";
     char nom[20]="username";
     char age[20]="enter your age";
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) ==-1)
    {
        printf("Could not initialize SDL: %s. \n", SDL_GetError());
        return -1;
    }

    screen=SDL_SetVideoMode(SCREEN_w,SCREEN_h,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);

    initialiser_audio(music,volume);
    initialiser_p(&p,f);
    
 SDL_Flip(screen);
  afficher_s(screen,p);
    while(boucle1!=0)
    {   afficher_s(screen,p);
     
       chargerpro(&pi,screen);   
     afficherprof(&pi,screen);   
        while(SDL_PollEvent(&event))
        { 
            switch(event.type){
            
                case SDL_QUIT:
                    boucle1=0;
                    
                    break;
                                      
                case SDL_MOUSEBUTTONDOWN: 
                
                if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<75 && event.button.x>29 && event.button.y<458&& event.button.y>427){
                         return 1;
                         } 
                         }  boucle1=0;
                         
                 if(event.button.button==SDL_BUTTON_LEFT )
                           { if  (event.button.x<444 && event.button.x>284 && event.button.y<214&& event.button.y>180){
                           TTF_Font *font = NULL;
    font = TTF_OpenFont("Ubuntu-MediumItalic.ttf", 24);

    SDL_Color textColor = {255, 255, 255};

    SDL_Event event;

    int loop = 1;
    while (loop)
    { afficher_s(screen,p); 

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                loop = 0;
                
                break;

            case SDL_KEYDOWN:
                if (strlen(nom) < 20)
                {
                    if (event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z)
                    {
                        strncat(nom, SDL_GetKeyName(event.key.keysym.sym), 1);
                    }
                }
                if (event.key.keysym.sym == SDLK_BACKSPACE && strlen(nom) > 0)
                {
                    nom[strlen(nom) - 1] = '\0';
                }
                if (event.key.keysym.sym == SDLK_RETURN && strlen(nom) > 0)
                {
                    loop = 0;
                }
                break;
            }
        }
       renderText(screen, font, textColor, nom, 344, 181);

        SDL_Flip(screen);
        
    }
    TTF_CloseFont(font);
    //save_prof(nom,pre,age); 
    
                }
                
                else if  (event.button.x<445 && event.button.x>281 && event.button.y<303&& event.button.y>264){
               
                               TTF_Font *font = NULL;
    font = TTF_OpenFont("Ubuntu-MediumItalic.ttf", 24);

    SDL_Color textColor = {255, 255, 255};

    SDL_Event event;

    int loop = 1;
    while (loop)
    { afficher_s(screen,p); 

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                loop = 0;
                
                break;

            case SDL_KEYDOWN:
                if (strlen(nom) < 20)
                {
                    if (event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z)
                    {
                        strncat(pre, SDL_GetKeyName(event.key.keysym.sym), 1);
                    }
                }
                if (event.key.keysym.sym == SDLK_BACKSPACE && strlen(pre) > 0)
                {
                    pre[strlen(pre) - 1] = '\0';
                }
                if (event.key.keysym.sym == SDLK_RETURN && strlen(pre) > 0)
                {
                    loop = 0;
                }
                break;
            }
        }

       renderText(screen, font, textColor, pre, 342, 266);

        SDL_Flip(screen);
        
    }
    TTF_CloseFont(font);
    //save_prof(nom,pre,age); 
    
                } 
               }
                
                else if  (event.button.x<444 && event.button.x>280 && event.button.y<388&& event.button.y>355){
               
                            TTF_Font *font = NULL;
    font = TTF_OpenFont("Ubuntu-MediumItalic.ttf", 24);

    SDL_Color textColor = {255, 255, 255};

    SDL_Event event;

    int loop = 1;
    while (loop)
    { afficher_s(screen,p); 

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                loop = 0;
                
                break;

            case SDL_KEYDOWN:
                if (strlen(age) < 20)
                {
                    if (event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z)
                    {
                        strncat(age, SDL_GetKeyName(event.key.keysym.sym), 1);
                    }
                }
                if (event.key.keysym.sym == SDLK_BACKSPACE && strlen(age) > 0)
                {
                    age[strlen(age) - 1] = '\0';
                }
                if (event.key.keysym.sym == SDLK_RETURN && strlen(age) > 0)
                {
                    loop = 0;
                }
                break;
            }
        }

       renderText(screen, font, textColor, age, 348, 355);

        SDL_Flip(screen);
        
    }
    TTF_CloseFont(font);
    //save_prof(nom,pre,age); 
    
                             
                         } 
                         
                         boucle1=1;
                                     
                         break;
                          
                   }
        }  
        SDL_Flip(screen);
       
         }
    
    liberer_image(p); 
    liberer_musique(music);
    liberer_musiquebref(mus);
     freep(&pi);
          
    SDL_Quit();
 return 1;
 
}
void renderText(SDL_Surface *surface, TTF_Font *font, SDL_Color color, char *text, int x, int y)
{
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
     
     
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, text, color);

    SDL_BlitSurface(textSurface, NULL, surface, &destRect);
}

void freep(pro *pi){
SDL_FreeSurface(pi->nom);
     SDL_FreeSurface(pi->pre);
     SDL_FreeSurface(pi->age);
    TTF_CloseFont(pi->police);

}

void freec(coin *c){
    SDL_FreeSurface(c->c1);
    TTF_CloseFont(c->police);
}
 void initialiser_p11(image *imge,int f)
{  
   if(f==1){
     imge->url=("p1.png");}
   if (f==-1){
      imge->url=("p1.png");}
      
    imge->img=IMG_Load(imge->url);
    if(imge->img==NULL)
    {	
    	printf("unable to load background image %s \n ",SDL_GetError());
        return ;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affiche.x=0;
    imge->pos_img_affiche.y=0;
    imge->pos_img_affiche.h=get_screenh();
    imge->pos_img_affiche.w=get_screenw();
}
void afficher_p11(SDL_Surface *screen,image imge){
    
    SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void chargerdi(di *c,SDL_Surface *screen){
    char n[20];
    SDL_Color Color={255,255,255};
    FILE *fichier = NULL;
    fichier = fopen("di.txt", "r");   
    fscanf(fichier, "%s ",n);
     c->pos_c1.x=540;
     c->pos_c1.y=30;
      c->police=TTF_OpenFont("Ubuntu-MediumItalic.ttf",22 );
     c->c1=TTF_RenderText_Blended(c->police,n,Color);
    fclose(fichier);
}
void afficherdi(di *c,SDL_Surface *screen){
   SDL_BlitSurface(c->c1,NULL,screen,&c->pos_c1); 
}

void charg(po *c,SDL_Surface *screen){
    char n[20];
    SDL_Color Color={255,255,255};
    FILE *fichier = NULL;
    fichier = fopen("profile.txt", "r");   
    fscanf(fichier, "%s ",n);
     c->pos_c1.x=100;
     c->pos_c1.y=30;
      c->police=TTF_OpenFont("Ubuntu-MediumItalic.ttf",22 );
     c->c1=TTF_RenderText_Blended(c->police,n,Color);
    fclose(fichier);
}
void affi(po *c,SDL_Surface *screen){
   SDL_BlitSurface(c->c1,NULL,screen,&c->pos_c1); 
}
