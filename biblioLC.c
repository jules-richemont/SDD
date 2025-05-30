#include "biblioLC.h"


Livre* creer_livre(int num, char* titre, char* auteur){ 
    Livre* livre = (Livre*)malloc(sizeof(Livre)); 
    if (livre == NULL){
        printf("erreur lors de l'allocation mémoire\n"); 
        return NULL; 
    }
    else {
        livre->num = num; 
        livre->titre = strdup(titre);
        livre->auteur = strdup(auteur); 
        livre->suiv = NULL; 
    }
    return livre; 

}

void liberer_livre(Livre* l){  //libère l'espace mémoire occupé par le livre
    
    free(l->titre); 
    free(l->auteur); 
    free(l); 
}

Biblio* creer_biblio(){    //crée une bibliothèque vide 
    Biblio* new = (Biblio*)malloc(sizeof(Biblio)); 
    if (new == NULL){
        return NULL; 
    }
    else {
        new->L = NULL; 
    }
    return new ; 
}

void liberer_biblio(Biblio* b) { //libere l'espace alloué par la bibliothèque 
    Livre* tmp1=b->L;
    Livre* tmp2=NULL;
    while(tmp1){
        tmp2=tmp1->suiv;
        liberer_livre(tmp1);
        tmp1=tmp2;
    }
    free(b);
}

void inserer_en_tete(Biblio* b, int num, char* titre,char* auteur){  // insere au debut de la bibliotheque le livre(num,titre,auteur)
    Livre* l = creer_livre(num,titre,auteur); 
    if(b){
        l->suiv = b->L; 
        b->L = l; 
    }
    else {
        b=creer_biblio(); 
        b->L = l; 

    }
}

void afficher_livre(Livre* l){   //affiche le numero, le titre et l'auteur du livre
    if (l!=NULL){
    printf("num= %d titre= %s auteur= %s\n",l->num,l->titre,l->auteur);}
    else {
        printf("le livre est vide \n"); 
    }
}

void afficher_biblio(Biblio* b){ //affiche l'ensemble des livres de la bibliothèque
    if(b==NULL){
        printf("la bibliothèque est vide\n"); 
        return; 
    }
    else {
        
        if(b->L!=NULL){
            Livre* l=b->L;
            while(l){
                afficher_livre(l);
                l=l->suiv;
        }
    }
    }
}

Livre* recherche_ouvrage_num(Biblio* b,int num){  //renvoie le premier livre qui a le numéro num
    Livre* l=b->L;
    while(l){
        if(l->num==num){
            return l;
        }
        l=l->suiv;
    }
    printf("le livre n'a pas été trouvé\n"); 
    return NULL;
}

Livre* recherche_ouvrage_titre(Biblio* b,char* titre){  //renvoie le premier livre avec le titre passé en paramètre
    Livre* l=b->L;
    while(l){
        if(strcasecmp(l->titre,titre)==0){
            return l;
        }
        l=l->suiv;
    }
    printf("l'ouvrage avec le titre %s n'a pas été trouvé dans la bibliothèque\n",titre); 
    return NULL;
}

Biblio* recherche_meme_auteur(Biblio *b, char *auteur){ //renvoie la bibliothèque contenant l'ensemble des livre de l'auteur passé en paramètre
    Biblio* new=creer_biblio();
    if(b!=NULL){
        Livre*tmp = b->L; 
        while(tmp){
            if(strcasecmp(tmp->auteur,auteur)==0){ //strcasecmp fait abstraction des majuscules
                inserer_en_tete(new,tmp->num,tmp->titre,tmp->auteur); 
            }
            tmp = tmp->suiv; 
        } 
    }
    else {
        printf("nous n'avons pas trouvé d'ouvrages pour l'auter %s\n",auteur); 
        return NULL; 
    }
    return new;
}

void supprimer_ouvrage(Biblio* b,int num,char* titre,char* auteur){ //supprime le(s) ouvrage(s) prensent(s) dans la bibliothèque avec les arguments passés en paramètre
    Livre* tmp1=b->L;
    if (tmp1){
         Livre* tmp2=tmp1->suiv;
         while(tmp2){
             if(tmp2->num == num && strcasecmp(tmp2->titre,titre)==0 && strcasecmp(tmp2->auteur,auteur)==0){
                 if(tmp2->suiv !=NULL){
                     tmp1->suiv = tmp2->suiv;
                 }
                 else {
                     tmp1->suiv = NULL; 
                 }
                liberer_livre(tmp2);
             }
             else {
                 tmp1 = tmp2; 
                 tmp2 = tmp2->suiv; 
             }
         }
        if((b->L)->num == num && strcmp((b->L)->titre,titre)==0 && strcmp((b->L)->auteur,auteur)==0){
            (b->L) = (b->L)->suiv; 
            liberer_livre(b->L); 
        }
    }
}
        
Biblio* fusion(Biblio* b1,Biblio* b2){
    Livre* tmp=b1->L;
    if(b1->L==NULL || b1==NULL)return b2;
    if(b2->L==NULL || b2==NULL)return b1;

    while(tmp->suiv){
        tmp=tmp->suiv;
    }
    Livre *livre_de_b2 = b2->L; 
    while(livre_de_b2){
        tmp->suiv = creer_livre(livre_de_b2->num,livre_de_b2->titre, livre_de_b2->auteur); 
        tmp=tmp->suiv; 
        livre_de_b2 = livre_de_b2->suiv; 
    }
    liberer_biblio(b2); 
    return b1; 
 }

Livre* recherche_exemplaire(Biblio* b){
    Livre* l=b->L;
    Livre* tmp=l;
    Biblio* new=creer_biblio();
    while(l){
        tmp=l->suiv;
        while(tmp){
            if(strcasecmp(l->auteur,tmp->auteur)==0 && strcasecmp(l->titre,tmp->titre)==0){
                inserer_en_tete(new,l->num,l->titre,l->auteur);
            }
            tmp=tmp->suiv;
        }
        l=l->suiv;
    }
    return new->L;
}

void afficher_liste_livres(Biblio* b){
     Livre *l=b->L; 
     while(l){
         printf("num= %d titre= %s auteur= %s\n",l->num,l->titre,l->auteur);
         l=l->suiv; 
     }
 }

 int main(){
     Livre *l = creer_livre(12,"ok", "auteur1"); 
     //afficher_livre(l); 
     Livre *l2 = creer_livre(14,"ok2", "auteur2"); 
     //afficher_livre(l2); 
     Biblio *b = creer_biblio(); 
     inserer_en_tete(b,l->num,l->titre,l->auteur); 
     inserer_en_tete(b,l2->num,l2->titre,l2->auteur); 
     //afficher_biblio(b);
     //supprimer_ouvrage(b,12,"ok","auteur1"); 
     //printf("BIBLIO\n"); 
     //afficher_biblio(b); 
     Biblio *b2 = creer_biblio(); 
     Livre *l3=creer_livre(15,"livre2", "coso"); 
     Livre *l4 = creer_livre(16,"livre3", "gab"); 
     inserer_en_tete(b2, l3->num,l3->titre,l3->auteur); 
     inserer_en_tete(b2,l4->num,l4->titre,l4->auteur); 
     //printf("BIBLIO2\n"); 
     //afficher_biblio(b2); 

     Biblio *fusion1 = fusion(b,b2); 
     //printf("FUSION\n"); 
     //afficher_biblio(fusion1); 

     Livre *l5 = creer_livre(13,"gab","coso"); 
     Livre *l6 = creer_livre(7,"gab","coso");
     Livre *l7 = creer_livre(89,"jdzjs","COso");
     Biblio *b3 = creer_biblio(); 
     inserer_en_tete(b3,l5->num,l5->titre,l5->auteur); 
     inserer_en_tete(b3,l6->num,l6->titre,l6->auteur); 
     inserer_en_tete(b3,l7->num,l7->titre,l7->auteur); 

     Livre *coco = recherche_exemplaire(b3); 
      
     while(coco){
         afficher_livre(coco); 
         coco = coco->suiv; 
     }
     


     return 0; 

 }