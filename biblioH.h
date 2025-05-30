#ifndef BIBLIOH_H
#define BIBLIOH_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct livreh {
    int clef ;
    int num; 
    char *titre; 
    char *auteur ; 

    struct livreh * suivant ;
} LivreH ;

typedef struct table {
    int nE ;        /*nombre d’elements contenus dans la table de hachage */
    int m ;         /*taille de la table de hachage */
    LivreH ** T ;   /*table de hachage avec resolution des collisions par chainage */
} BiblioH ;

int fonctionClef(char* auteur);
LivreH* creer_livreH(int num,char* titre,char* auteur) ;
void liberer_livreH(LivreH* l) ;
BiblioH* creer_biblioH(int m) ;
void liberer_biblioH(BiblioH* b);
int fonctionHachage(int cle, int m);
void insererH(BiblioH* b,int num,char* titre,char* auteur);
 
void afficher_livreH(LivreH* l);
void afficher_biblioH(BiblioH* b);
LivreH* recherche_ouvrage_titreH(BiblioH* b,char* titre);
LivreH* recherche_ouvrage_num_H(BiblioH* b,int num);
BiblioH* Recherche_meme_auteurH(BiblioH *b, char *auteur);
LivreH* recherche_exemplairH(BiblioH* b);


#endif 