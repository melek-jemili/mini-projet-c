#include <stdio.h>
#include <stdlib.h>
#include "Etudiant.h"
#include <string.h>
#include <time.h>

Etudiant tableau_etd[100];
int taille_tab=0;

int main()
{
	int id;
	int i;
	int choix=0;
	int rech=-1;
	char rep[3];
	FILE* fichier;
	time_t seconde;
    struct tm instant;
    time(&seconde);
    instant=*localtime(&seconde);
    fichier=fopen("note.txt","rt");
    if (fichier=NULL){
        printf("\n fichier inéxistant !!!");
    }else{
        for (i=0;i<taille_tab;i++){
                fscanf(fichier,"%d\n",&tableau_etd[i].identifiant);
                fgets(tableau_etd[i].Nom,25,fichier);
                fgets(tableau_etd[i].Prenom,25,fichier);
                fscanf(fichier,"%f %f %f %f\n",&tableau_etd[i].Notes[0],&tableau_etd[i].Notes[1],&tableau_etd[i].Notes[2],&tableau_etd[i].Notes[3]);

        }

    }

	while (1)
	{   printf("\n****************************");
        printf("\n************MENU************");
        printf("\n****************************");
        printf("\n 1.Saisir tableau d'etudiant");
        printf("\n 2.Ajouter un étudiant");
        printf("\n 3.Rechercher un étudiant");
        printf("\n 4.Modifier un étudiant");
        printf("\n 5.Supprimer un étudiant");
        printf("\n 6.Afficher tableau étudiant");
        printf("\n 0.Quitter");
        printf("\n*******************************");
        printf("\n %d/%d/%d\t\t %d:%d",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min);
        printf("\n*******************************");
        printf("\n Introduire votre choix: ");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            {   saisir_tab_etd(tableau_etd,&taille_tab);
                break;
            }
        case 2:
            {   Ajouter_tab_etd(tableau_etd,&taille_tab);
                break;
            }
        case 3:
            {   printf("\n introduire l'identifiant à chercher:");
                scanf("%d",&id);
                rech=recherche_etd(tableau_etd,taille_tab,id); // rech c'est l'indice de l'étudiant trouvé
                if (rech==-1){
                printf("\n identifiant inéxistant");
                }
                else{
                    affiche_etd(tableau_etd[rech]);}
                break;
            }
        case 4:
            {   printf("\n introduire l'identifiant de l'étudiant à modifier:");
                scanf("%d",&id);
                rech=recherche_etd(tableau_etd,taille_tab,id); // rech c'est l'indice de l'étudiant trouvé
                if (rech!=-1){
                    affiche_etd(tableau_etd[rech]);
                    printf("\n Vous êtes sure de vouloire modifier cet etudiant oui/non ?: ");
                    scanf("%s",rep);
                    if(strcmp(rep,"oui")==0){
                        modifier_etd(tableau_etd,rech);}
                }
                else{
                   printf("\n identifiant inéxistant");}
                break;}

        case 5:
            {   printf("\n introduire l'identifiant de l'étudiant à supprimer:");
                scanf("%d",&id);
                rech=recherche_etd(tableau_etd,taille_tab,id); // rech c'est l'indice de l'étudiant trouvé
                if (rech!=-1){
                    affiche_etd(tableau_etd[rech]);
                    printf("\n Vous êtes sure de vouloire supprimer cet etudiant oui/non ?: ");
                    scanf("%s",rep);
                    if(strcmp(rep,"oui")==0){
                        supprimer_etd(tableau_etd,&taille_tab,rech);}
                }
                else{
                   printf("\n identifiant inéxistant");}
                break;}

        case 6:
            {   affiche_tableau_etd(tableau_etd,taille_tab);
                break;
            }
        case 0:
            {
                fichier=fopen("note.txt","wt");
                if (fichier==NULL){
                    printf("\n fichier inéxistant !! ");
                }else{
                    for (i=0;i<taille_tab;i++){
                        fprintf(fichier,"%d\n",tableau_etd[i].identifiant);
                        fputs(tableau_etd[i].Nom,fichier);
                        fputs(tableau_etd[i].Prenom,fichier);
                        fprintf(fichier,"%f %f %f %f\n",tableau_etd[i].Notes[0],tableau_etd[i].Notes[1],tableau_etd[i].Notes[2],tableau_etd[i].Notes[3]);
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

