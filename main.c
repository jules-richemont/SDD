#include "entreeSortieLC.h"
#include "biblioLC.h"
#include "biblioH.h"
#include "entreeSortieH.h"

void menu(){
    printf("0-sortie du programme\n1-Affichage\n2-Inserer ouvrage\n3-supprimer ouvrage\n4-recherche par num\n5-recherche par titre\n6-recherche des exemlaires\n"); 
}

int main(int argc, char** argv){
    if(argc!=3){
        return 0;
    } 
    Biblio* b=charger_n_entrees(argv[1],atoi(argv[2]));
    //enregistrer_biblio(b,"nouvau.txt");
    int rep ;
do{
    menu () ;
    scanf ("%d" ,& rep );
    int num;
    char titre[256];
    char auteur[256];
    switch ( rep ) {

        case 1:
            printf (" Affichage : \n") ;
            afficher_biblio(b) ;
            break ;

        case 2:
            printf (" Veuillez ecrire le numero , le titre et l’auteur de l’ouvrage. \n");
            /* On suppose que le titre et l’auteur ne contiennent pas d’espace*/
            if ( scanf (" %d %s %s " ,& num , titre , auteur ) ==3) {
            inserer_en_tete (b , num , titre , auteur ) ;
            printf (" Ajout fait . \nn");
            } else {
            printf (" Erreur format \n") ;
            }
            break ;

        case 3:
            printf (" Veuillez ecrire le numero , le titre et l’auteur de l’ouvrage. \n");
            /* On suppose que le titre et l’auteur ne contiennent pas d’espace*/
            if ( scanf (" %d %s %s " ,& num , titre , auteur ) ==3) {
            supprimer_ouvrage (b , num , titre , auteur ) ;
            printf (" suprimation fait . \nn");
            } else {
            printf (" Erreur format \n") ;
            }
            break ;

        case 4:
            printf (" Veuillez ecrire le numero \n");
            /* On suppose que le titre et l’auteur ne contiennent pas d’espace*/
            if ( scanf (" %d " ,& num ) ==1) {
            Livre* l=recherche_ouvrage_num (b , num ) ;
            printf (" Ouvrage trouvé \n");
            afficher_livre(l);
            } else {
            printf (" Erreur format \n") ;
            }
            break ;

        case 5:         
            printf (" Veuillez ecrire le titre \n");
            /* On suppose que le titre et l’auteur ne contiennent pas d’espace*/
            if ( scanf (" %s " ,titre ) ==1) {
            Livre* l=recherche_ouvrage_titre (b , titre ) ;
            printf (" ouvrage trouver . \n");
            afficher_livre(l);
            } else {
            printf (" Erreur format \n") ;
            }
            break ;  

        case 6:
            Livre* li=recherche_exemplaire(b) ;
            printf ("La liste avec des ouvrage avec plusier exemplaire. \n");
            afficher_livre(li);
            break ;          
    }
    } while ( rep !=0) ;
printf ("Merci , et au revoir. \n");
return 0;


}