#include "etudiant.h"
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

extern Etudiant tableau_etd[100];
extern int taille_tab;

Etudiant saisir_etd(){
	Etudiant etd;
	//int i;
	//int rech;
    /*do
	{printf("\n introduire l'identifiant : ");
	scanf("%d",&etd.identifiant);
    rech=recherche_etd(tableau_etd,taille_tab,etd.identifiant);
    if (rech!=-1){
        printf("\n Identifiant existe d%cjà!!\n",130);
    }
	}while(rech!=-1);*/
    printf("\n introduire l'identifiant : ");
	scanf("%d",&etd.identifiant);
	printf("\n introduire le nom: ");
	fflush(stdin);
	gets(etd.Nom);
	printf("\n introduire le prénom: ");
	fflush(stdin);
	gets(etd.Prenom);
	for ( int i=0;i<4;i++){
        do{
		printf("Note[%d]= ",i);
		scanf("%f",&etd.Notes[i]);
		if((etd.Notes[i]<0)||(etd.Notes[i]>20)){
            printf("\ Note %crron%ce !! : 0<note<20:",130,130);
		}
        }while((etd.Notes[i]<0)||(etd.Notes[i]>20));
	}
	return etd;
}




void affiche_etd(Etudiant e){
	printf("\n *****\n identifiant : %d",e.identifiant);
	printf("\n Nom: %s",e.Nom);
	printf("\n Prenom : %s",e.Prenom);
	for (int i=0;i<4;i++){
		printf("\n notes[%d]=%f",i,e.Notes[i]);
	}
}



void modifier_etd(Etudiant *etd){
    int choix;
    printf("\n******MENU***********");
    printf("\n 1.Modifier le nom");
    printf("\n 2.Modifier le prénom");
    printf("\n 3.Modifier Note 1");
    printf("\n 4.Modifier Note 2");
    printf("\n 5.Modifier Note 3");
    printf("\n 6.Modifier Note 4");
    printf("\n Introduire votre choix: ");
    scanf("%d",&choix);
    switch(choix){
        case(1):{
            printf(" \nIntroduire le nom:");
            fflush(stdin);
            gets(etd->Nom);
            break;
        }
        case(2):{
            printf(" \nIntroduire le prénom:");
            fflush(stdin);
            gets(etd->Prenom);
            break;
        }
        case(3):{
            do
            {printf(" \nIntroduire la note:");
            scanf("%f",&etd->Notes[0]);
            if(etd->Notes[0]<0 || etd->Notes[0]>20){
                printf("\n Note %crron%ce !! : 0<note<20:\n",130,130);
            }
            }while(etd->Notes[0]<0 || etd->Notes[0]>20);
            break;
        }
        case(4):{
            do
            {printf(" \nIntroduire la note:");
            scanf("%f",&etd->Notes[1]);
            if(etd->Notes[1]<0 || etd->Notes[1]>20){
                printf("\n Note %crron%ce !! : 0<note<20:\n",130,130);}
            }while(etd->Notes[1]<0 || etd->Notes[1]>20);
            break;
        }

        case(5):{
            do
             {printf(" \nIntroduire la note:");
            scanf("%f",&etd->Notes[2]);
            if(etd->Notes[2]<0 || etd->Notes[2]>20){
                printf("\n Note %crron%ce !! : 0<note<20:\n",130,130);
            }
            }while(etd->Notes[2]<0 || etd->Notes[2]>20);
            break;
        }
        case(6):{
            do
            {printf(" \nIntroduire la note:");
            scanf("%f",&etd->Notes[3]);
            if(etd->Notes[3]<0 || etd->Notes[3]>20){
                printf("\n Note %crron%ce !! : 0<note<20:\n",130,130);}
            }while(etd->Notes[3]<0 || etd->Notes[3]>20);
            break;}
        default:{
            printf("\n Choix érroné!!");}
    }
}

Liste insere(Etudiant element , Liste Lst){
    struct cellule * Courrant;
    Courrant=(struct cellule*)malloc(sizeof(struct cellule));
    Courrant->valeur= element;
    Courrant->suivant=Lst;
    return (Courrant);

}

void affiche_Liste_etd(Liste Lst)
{
struct cellule* courrant;
courrant =Lst;
while (courrant!=NULL)
{
//traitement afficher l’entier
affiche_etd(courrant->valeur);
courrant=courrant->suivant;
}
}

Etudiant* rechercher_etd(Liste Lst, int ident)
{
    struct cellule* courrant;
    courrant =Lst;
    while (courrant!=NULL){
        if(courrant->valeur.identifiant==ident)
            return &courrant->valeur;
        courrant=courrant->suivant;}
    return NULL;
}



