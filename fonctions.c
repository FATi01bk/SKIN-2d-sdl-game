#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "structures.h"
#include "fonctions.h"
#include <time.h>

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

void liberer_image(image imge){
    SDL_FreeSurface(imge.img);
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
void afficher(coin *c,SDL_Surface *screen){
   SDL_BlitSurface(c->c1,NULL,screen,&c->pos_c1); 
}
void afficher_s(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_pro(SDL_Surface *screen, image imge){
    
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
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
                    
			rep=1;
			d=1;
			
                }
                else if ( event.button.x>371 && event.button.x<543 && event.button.y>302 && event.button.y<359) 
                {     
                    
			rep=2;
			d=1;
			
                }
                else if ( event.button.x>177 && event.button.x<352 && event.button.y>383 && event.button.y<443) 
                {     
                   
			rep=3;
			d=1;
			
                }
                else if ( event.button.x>369 && event.button.x<543 && event.button.y>373 && event.button.y<445) 
                {     
                    
			rep=4;
			d=1;
			
                }  
            }
        }
        }break;
        case SDL_MOUSEMOTION:
               

                       if(event.motion.x<343 && event.motion.x>178 && event.motion.y<359 && event.motion.y>304){ 
                       
                        b11=1;   
                                                   
                          afficherq1(e,screen);                                                                               
                                                
                       }
          
                      else if (event.motion.x<543 && event.motion.x>371 && event.motion.y<359 && event.motion.y>302 ){                              
                              b12=1;
                             
                               afficherq2(e,screen);                                                         
                                
                                   }   
           
                      else if(event.motion.x<352 && event.motion.x>177 && event.motion.y<443 && event.motion.y>383 ){                            
                            b13=1;
                                  
                                  afficherq3(e,screen);                               
                                                                
                                 }
                                 
                     else if(event.motion.x<543 && event.motion.x>369 && event.motion.y<445 && event.motion.y>373 ){                            
                            b14=1;
                                
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
int enigme(){
 FILE* fichier;
  Enigme e;
  personne p;
 
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

