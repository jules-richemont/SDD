#include"entreeSortieH.h"
#include "biblioH.h"

BiblioH* charger_n_entreesH(char* nomfic, int n){
    char ligne[256];
    char titre[256];
    char auteur[256];
    int num;
    BiblioH* b=creer_biblioH();
    FILE* fic=fopen(nomfic,"r");
    if(fic){
        for(int i=0;i<n && (fgets(ligne,256,fic));i++){
            
            if ( sscanf ( ligne , "%d %s %s ", num ,titre,auteur ) == 3){
                inserer(b,num,titre,auteur);
            }   
        }
    }

    return b;
}

void enregistrer_biblioH(BiblioH *b, char* nomfic){
    
    int i =0;
    FILE * fic = fopen ( nomfic , "w" ); 
    if ( fic != NULL ){
        LivreH *l;
        for(int x=0;x<m;x++){
            LivreH *l=b->T[x];
            while (l) {
                fprintf ( fic,"%d %s %s " ,l->num,l->titre,l->auteur);
                fputc ("\n",fic);
                l=l->suiv;
            }
        }
    }
    fclose ( fic );
}
