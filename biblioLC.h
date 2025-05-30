#ifndef BIBLIOLC_H
#define BIBLIOLC_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct livre{
    int num; 
    char *titre; 
    char *auteur ; 
    struct livre *suiv; 
} Livre ; 

typedef struct {
    Livre* L ; 
} Biblio ; 

Livre* creer_livre(int num, char* titre, char* auteur); 
void liberer_livre(Livre* l); 
Biblio* creer_biblio(); 
void liberer_biblio(Biblio* b); 
void inserer_en_tete(Biblio* b, int num, char* titre,char* auteur);
void afficher_livre(Livre* l);
void afficher_biblio(Biblio* b);
Livre* recherche_ouvrage_num(Biblio* b,int num);
Livre* recherche_ouvrage_titre(Biblio* b,char* titre);
Biblio* recherche_meme_auteur(Biblio *b, char *auteur);
void supprimer_ouvrage(Biblio* b,int num,char* titre,char* auteur);
Biblio* fusion(Biblio* b1,Biblio* b2);
Livre* recherche_exemplaire(Biblio* b);
void afficher_liste_livres(Biblio* b);

#endif