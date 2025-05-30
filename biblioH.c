#include "biblioH.h"

int fonctionClef(char* auteur){
    int i, cmp;
    for (i=0; i<strlen(auteur; i++)){
        cmp+=(int)auteur[i];
    }
    return cmp;
}


LivreH* creer_livreH(int num,char* titre,char* auteur){
    LivreH* livre = malloc(sizeof(LivreH)); 
    if (livre == NULL){
        return NULL; 
    }
    else{
        livre->clef = fonctionClef(auteur); 
        livre->num = num; 
        livre->titre = strdup(titre);
        livre->auteur = strdup(auteur); 
        livre->suivant = NULL; 
    } 
    return livre; 
}

void liberer_livreH(LivreH* l){
    free(l->titre); 
    free(l->auteur); 
    free(l);
}

BiblioH* creer_biblioH(int m){
    BiblioH* new = (BiblioH*)malloc(sizeof(BiblioH)); 
    if (new == NULL){
        return NULL; 
    }
    else {
        new->nE = 0; 
        new->m = m; 
        new->T = (LivreH**)malloc(m*sizeof(LivreH*));    
    }
    return new ; 
}

void liberer_biblioH(BiblioH* b){
    int i; 
    LivreH ** tmp1 = (b->T);
    LivreH * tmp2 = NULL;
    int m = b->m; 
    for (i=0;i<m;; i++){
        while(tmp1[i]){
            tmp2= tmp1[i]->suivant; 
            liberer_livreH(tmp1[i]); 
            tmp1[i]=tmp2; 
        }
    
    }
}

int fonctionHachage(int cle, int m){
    double a=(sqrt(5)-1)/2;
    return  m*(cle*a*1.0-((int)(cle*a)));

}

void insererH(BiblioH* b,int num,char* titre,char* auteur){
    LivreH* new=creer_livreH(num,titre,auteur);
    new->clef=fonctionHachage(fonctionClef(auteur),b->m);
    new->suivant=b->T[new->clef];
    b->T[new->clef]=new;
}



void afficher_livreH(LivreH* l){
    printf("num= %d titre= %s auteur= %s",l->num,l->titre,l->auteur);
}

void afficher_biblioH(BiblioH* b){
    LivreH* l;
    for(int x=0;x<b->m;x++){
        l=b->T[x]
        while(l){
            afficher_livreH(l);
            l=l->suiv;
        }
    }
}

LivreH* recherche_ouvrage_num_H(BiblioH* b,int num){
    Livre* l;
    for(int x=0;x<b->m;x++){
        l=b->T[x]
        while(l){
            if(l->num==num)return l;
            l=l->suiv;
        }
    }    
    return NULL;
}



LivreH* recherche_ouvrage_titreH(BiblioH* b,char* titre){
    LivreH **l=b->T;
    int i; 
    int m = b->m; 
    for (i=0; i<m; i++){
        while(l[i]){
            if(strcmp(l[i]->titre,titre)==0){
                return l[i]; 
            }
            l[i]=l[i]->suivant; 
        }
    }
    return NULL; 
}

BiblioH* Recherche_meme_auteurH(BiblioH *b, char *auteur){
    BiblioH* new=creer_biblioH() ;
    int i; 
    int m = b->m; 
    if(b!=NULL){
        Livre **tmp = b->T; 
        for (i =0; i<m; i++){
            while(tmp[i]){
                if(strcmp(tmp[i]->auteur,auteur)==0){
                    inserer(new,tmp[i]->num, tmp[i]-->titre,tmp[i]->auteur);    
                }
                tmp[i]=tmp[i]->suivant; 
            }
        }
    return new; 
    }
    return NULL; 
}

LivreH* recherche_exemplairH(BiblioH* b){
    LivreH* l;
    LivreH* l2;
    LivreH* tmp;
    BiblioH* new=creer_biblioH();
    for(int x=0;x<b->m;x++){
        l=b->T[x];
        while(l){
        
            for(int i=x;i<b->m;x++){
                if(i==x){l2=l->suivant;}else{l2=b->T[i];}
                while(l2){
                
                    if(strcmp(l->auteur,tmp->auteur)==0 && l->titre==l2->titre){
                        inserer(new,l->num,l->titre,l->auteur);
                    }
                    l2=l2->suiv;
                }
            }
            l=l->suiv;
            }
        }
    return new->L;
}


BiblioH* fusionH(BiblioH* b1,BiblioJ* b2){
    BiblioH* new = creer_biblioH(b->m); 
    for(int x=0;x<b->m;x++){

        LivreH* tmp=b1->T[x];
        
        if(b1->T[x]==NULL || b1==NULL)new->T[x]=b2;
        if(b2->T[x]==NULL || b2==NULL)new->T[x]=b1;
        while(tmp->suiv){
            tmp=tmp->suiv;
        }
        tmp->suiv=b2->T[x];
        new->T[x] = b1->T[x]; 
        liberer_biblioH(b2);
    } 
    return new; 
 }





            














