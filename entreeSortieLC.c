#include "entreeSortieLC.h"

Biblio* charger_n_entrees(char* nomfic, int n){ //permet de lire n lignes d'un fichier et de les stocker dans une bibliothèque
    FILE *f = fopen(nomfic, 'r');
    if (f){
        int i; 
        Biblio* b = creer_biblio(); 
        char ligne[256];
        int num; 
        char titre[256] ; 
        char auteur[256] ; 
        for (i=0; i<n && fgets(ligne,256,f)!=NULL; i++){
            if(sscanf(ligne, "%d %s %s", &num, titre, auteur )==3){ //sscanf lit une chaîne de caractères depuis un flux spécifié
                inserer_en_tete(b,num, titre,auteur); 
            }
        } 
    }
    else{
        return NULL; 
    }
    fclose(f); 
    return b; 
}

void enregistrer_biblio(Biblio b, char nomfic){ //permet de stocker une bibliothèque dans un fichier au bon format (numéro titre auteur)
    FILE* f= fopen(nomfic, 'w');
    if (f){
        Biblio * bib=creer_biblio();
        bib = b;
        Livre *courant=bib->L;
        while(courant){
            fprintf(f, "%d %s %s\n", courant->num, courant->titre, courant->auteur);
            courant=courant->suiv;
        }
    }
    fclose(f);
}