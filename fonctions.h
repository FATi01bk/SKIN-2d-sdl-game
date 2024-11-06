#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 470
#define SCREEN_W 730



typedef struct{
	int frame;
	SDL_Surface *imgBird;
	SDL_Rect PP;
	
}bird;

typedef struct{
	int frame;
	SDL_Surface *imgwind;
	SDL_Rect PP;
	
}wind;


typedef struct{
   char *url;
   SDL_Rect pos_img_affiche;
   SDL_Rect pos_img_ecran;
   SDL_Surface *img;
 }image;

 typedef struct{
    SDL_Surface *txt;
    SDL_Rect pos_txt;
    SDL_Colour color_txt;
    TTF_Font *police;
 }texte;

 typedef struct{
    SDL_Surface *c1;
    SDL_Rect  pos_c1; 
    TTF_Font *police;
 }coin;
 
  typedef struct{
    SDL_Surface *c1;
    SDL_Rect  pos_c1; 
    TTF_Font *police;
 }po;
 
 typedef struct{
    SDL_Surface *c1;
    SDL_Rect  pos_c1; 
    TTF_Font *police;
 }di;
 
  typedef struct{
    SDL_Surface *nom,*pre,*age;
    SDL_Rect  pos_nom,pos_pre,pos_age; 
    TTF_Font *police;
 }pro; 
 
 typedef struct{
 
   SDL_Surface* imag,*q1,*q2,*q3,*q4;
   SDL_Rect pos_imag,pos_q1,pos_q2,pos_q3,pos_q4;
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
 


typedef struct{

    SDL_Surface *fondScore;
    SDL_Surface *texteScore;
    SDL_Rect posFond;
    SDL_Rect posScore;
    int ScoreActuel;
    TTF_Font *police;  
}Score;


 void initialiser_menu(image *imge,int f);
 void initialiser_p(image *imge,int f);
 void initialiser_pro(image *imge,int f);
 void initialiser_levels(image *imge,int f);
 void initialiser_b1(image *imge,int f);
 void initialiser_b2(image *imge,int f);
 void initialiser_b3(image *imge,int f);
 void initialiser_l1(image *imge,int f);
 void initialiser_l2(image *imge,int f);
 void initialiser_l3(image *imge,int f);
 void initialiser_l4(image *imge,int f);
 void initialiser_00(image *imge,int f);
 void initialiser_20(image *imge,int f);
 void initialiser_40(image *imge,int f);
 void initialiser_60(image *imge,int f);
 void initialiser_80(image *imge,int f);
 void initialiser_100(image *imge,int f);
 void initialiser_op2(image *imge,int f);
 void initialiser_bs(image *imge,int f);
 void initialiser_s(image *imge,int f);
 void initialiser_s1(image *imge,int f);
 void initialiser_s2(image *imge,int f);
 void initialiser_s3(image *imge,int f);
void initialiser_p1(image *imge,int f);
void initialiser_p2(image *imge,int f);
void chargerpro(pro *p,SDL_Surface *screen);
void afficherprof(pro *p,SDL_Surface *screen);
 void afficher_menu(SDL_Surface *screen, image imge);
 void afficher_s(SDL_Surface *screen, image imge);
 void afficher_pro(SDL_Surface *screen, image imge);
 void afficher_option(SDL_Surface *screen, image imge);
 void afficher_bs(SDL_Surface *screen, image imge);
 void afficher_levels(SDL_Surface *screen,image imge);
 void afficher_b1(SDL_Surface *screen, image imge);
 void afficher_b2(SDL_Surface *screen, image imge);
 void afficher_b3(SDL_Surface *screen, image imge);
 void afficher_l1(SDL_Surface *screen, image imge);
 void afficher_l2(SDL_Surface *screen, image imge);
 void afficher_l3(SDL_Surface *screen, image imge);
 void afficher_l4(SDL_Surface *screen, image imge);
 void afficher_op(SDL_Surface *screen, image imge);
 void afficher_p(SDL_Surface *screen, image imge);
 int option(int f);
 int levels(int f);
 int store(int f);
 void liberer_image(image imge);
void initialiser_score(image *imge,int f);
int save_prof(char nom[],char pre[],char age[]);
int afficherscore();

 void initialiser_audio(Mix_Music *music,int volume);
 void liberer_musique(Mix_Music *music);
 void initialiser_audiobref(Mix_Chunk *music);
 void liberer_musiquebref(Mix_Chunk *music);
 void save_volume(int volume);
 int get_volume();

 void initialiser_texte(texte *txte,int f);
 void afficher_texte(SDL_Surface *screen, texte txte);
 void liberer_texte(texte txte);
void freep(pro *p);
void freec(coin *c);

 void save_screen(int h,int w);
 int get_screenh();
 int get_screenw();
void save_coin(int n);
void chargercoin(coin *c,SDL_Surface *screen);
void afficher(coin *c,SDL_Surface *screen);
 int afficherprofile();
int afficherpropic();
void enter(char playerName[], SDL_Surface *screen);
void renderText(SDL_Surface *surface, TTF_Font *font, SDL_Color color, char *text, int x, int y);
void animerEnigme(Enigme *e,SDL_Surface *screen);
int resolution_enigme(Enigme *e,SDL_Surface *screen);
void init_enigme(Enigme *e, SDL_Surface *screen);
void init_q1(Enigme *e, SDL_Surface *screen);
void init_q2(Enigme *e, SDL_Surface *screen);
void init_q3(Enigme *e, SDL_Surface *screen);
void init_q4(Enigme *e, SDL_Surface *screen);
void genererEnigme(Enigme *e, char *nomfichier);
void afficherq1(Enigme *e,SDL_Surface * screen);
void afficherq2(Enigme *e,SDL_Surface * screen);
void afficherq3(Enigme *e,SDL_Surface * screen);
void afficherq4(Enigme *e,SDL_Surface * screen);
void free_enigme( Enigme *e );

int enigme();
void initialiser_sous(image *imge);
void afficher_sous(SDL_Surface *screen, image imge);
void initialiser_me(image *imge);

void initialiser_ss(image *imge);
void initialiser_ss1(image *imge);
void initialiser_ss2(image *imge);
void initialiser_ss3(image *imge);
void initialiser_ppro(image *imge);
int st();
int play();
void chargercoinc(coin *c,SDL_Surface *screen);
void initanimBird( bird *b);
void libererBird(bird* b);
void afficherBird(bird* p,SDL_Surface *screen);
void animerBird (bird* p);

void initanimwind( wind *w);
void libererwind(wind* w);
void afficherwind(wind* w,SDL_Surface *screen);
void animerwind (wind* w);
int ma();
void chargerdi(di *c,SDL_Surface *screen);
void afficherdi(di *c,SDL_Surface *screen);
void initialiser_p11(image *imge,int f);
void afficher_p11(SDL_Surface *screen,image imge);
void charg(po *c,SDL_Surface *screen);
void affi(po *c,SDL_Surface *screen);
#endif



