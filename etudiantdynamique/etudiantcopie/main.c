#include <stdio.h>
#include <stdlib.h>
#include "etudiant.h"
#include <string.h>
#include <time.h>

Liste Liste_etd=NULL;


int main()
{
	int id;
	int choix=0;
	Etudiant* rech=NULL;
    char rep[3];
	Etudiant etd;
	struct cellule* courrant;
	/*FILE* fichier;*/
	time_t seconde;
    struct tm instant;
    time(&seconde);
    instant=*localtime(&seconde);
    /*fichier=fopen("note.txt","rt");
    if (fichier=NULL){
        printf("\n fichier inéxistant !!!");
    }else{
        for (i=0;i<taille_tab;i++){
                fscanf(fichier,"%d\n",&courrant->valeur.identifiant);
                fgets(courrant->valeur.Nom,25,fichier);
                fgets(tableau_etd[i].Prenom,25,fichier);
                fscanf(fichier,"%f %f %f %f\n",&courrant->valeur.Notes[0],&courrant->valeur.Notes[1],&courrant->valeur.Notes[2],&courrant->valeur.Notes[3]);

        }

    }*/

	while (1)
	{   printf("\n****************************");
        printf("\n************MENU************");
        printf("\n****************************");
        printf("\n 1.Ajouter un étudiant");
        printf("\n 2.Rechercher un étudiant");
        printf("\n 3.Modifier un étudiant");
        printf("\n 4.Supprimer un étudiant");
        printf("\n 5.Afficher liste étudiant");
        printf("\n 0.Quitter");
        printf("\n*******************************");
        printf("\n %d/%d/%d\t\t %d:%d",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min);
        printf("\n*******************************");
        printf("\n Introduire votre choix: ");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            {
                do
                {etd=saisir_etd();
                Liste_etd=insere(etd,Liste_etd);
                printf("\n Voulez-vous ajouter un autre étudiant? oui/non:");
                fscanf("%s",rep);
                }while(strcmp(rep,"oui")==0);
                break;
            }
        case 2:
            {   printf("\n introduire l'identifiant à chercher:");
                scanf("%d",&id);
                rech=rechercher_etd(Liste_etd,id);
                if (rech==NULL){
                printf("\n identifiant inéxistant");
                }
                else{
                    affiche_etd(*rech);}
                break;}

        case 3:
            {
                printf("\n introduire l'identifiant à modifier:");
                scanf("%d",&id);
                rech=rechercher_etd(Liste_etd,id);
                if (rech==NULL){
                printf("\n identifiant inéxistant");
                }
                else{
                    affiche_etd(*rech);
                    printf("\n Vous êtes sure de vouloire modifier cet étudiant? oui/non:");
                    scanf("%s",rep);
                    if (strcmp(rep,"oui")==0){
                        modifier_etd(rech);}

                }
                break;
            }
        case 4:
            {
                break;}

        case 5:
            {
                affiche_Liste_etd(Liste_etd);
                break;}

        case 0:
            {
                fichier=fopen("note.txt","wt");
                if (fichier==NULL){
                    printf("\n fichier inéxistant !! ");
                }else{
                    courrant =Liste_etd;
                    while (courrant!=NULL){
                    //traitement afficher l’entier
                        fprintf(fichier,"%d\n",courrant->valeur.identifiant);
                        fputs(courrant->valeur.Nom,fichier);
                        fputs(courrant->valeur.Prenom,fichier);
                        fprintf(fichier,"%f %f %f %f\n",courrant->valeur.Notes[0],courrant->valeur.Notes[1],courrant->valeur.Notes[2],courrant->valeur.Notes[3]);
                        courrant=courrant->suivant;
                    }

                    }
                    fclose(fichier);
                }
                exit(0);
            }
        default:
            {
                printf("\n Choix érroné!!");
            }

	}
}

    return 0;

}


