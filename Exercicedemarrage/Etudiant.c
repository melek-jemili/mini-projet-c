#include "Etudiant.h"
#include <stdio.h>
#include <string.h>

extern Etudiant tableau_etd[100];
extern int taille_tab;

Etudiant saisir_etd(){
	Etudiant etd;
	int i;
	int rech;
    do
	{printf("\n introduire l'identifiant : ");
	scanf("%d",&etd.identifiant);
    rech=recherche_etd(tableau_etd,taille_tab,etd.identifiant);
    if (rech!=-1){
        printf("\n Identifiant existe d%cjà!!\n",130);
    }
	}while(rech!=-1);

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
void saisir_tab_etd(Etudiant tab[], int *N){
	char rep[3];
	Etudiant e;
	do{
		e=saisir_etd();
		tab[*N]=e;
		(*N)++;
		printf("\n Voulez-vous ajouter un autre etudiant oui/non:");
		scanf("%s",rep);
	}while(strcmp(rep,"oui")==0);


}
void Ajouter_tab_etd(Etudiant tab[], int *N){
	Etudiant e;
	int i;
	char rep[3];
	i=*N;

		e=saisir_etd();
		tab[i]=e;
		i++;

	*N=i;
}


void affiche_etd(Etudiant e){
	printf("\n *****\n identifiant : %d",e.identifiant);
	printf("\n Nom: %s",e.Nom);
	printf("\n Prenom : %s",e.Prenom);
	for (int i=0;i<4;i++){
		printf("\n notes[%d]=%f",i,e.Notes[i]);
	}
}

void affiche_tableau_etd(Etudiant tab[],int N){
	int i;
	for(i=0;i<N;i++){
		affiche_etd(tab[i]);
	}
}

int recherche_etd(Etudiant tab[],int N,int ident){
	for(int i=0;i<N;i++){
		if ((tab[i].identifiant)==ident){
			return i;
		}
	}
	return -1;
}


void modifier_etd(Etudiant tab[],int rech){
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
            gets(tab[rech].Nom);
            break;
        }
        case(2):{
            printf(" \nIntroduire le prénom:");
            fflush(stdin);
            gets(tab[rech].Prenom);
            break;
        }
        case(3):{
            do
            {printf(" \nIntroduire la note:");
            scanf("%f",&tab[rech].Notes[0]);
            if(tab[rech].Notes[0]<0 || tab[rech].Notes[0]>20){
                printf("\ Note %crron%ce !! : 0<note<20:\n",130,130);
            }
            }while(tab[rech].Notes[0]<0 || tab[rech].Notes[0]>20);
            break;
        }
        case(4):{
            do
            {printf(" \nIntroduire la note:");
            scanf("%f",&tab[rech].Notes[1]);
            if(tab[rech].Notes[1]<0 || tab[rech].Notes[1]>20){
                printf("\ Note %crron%ce !! : 0<note<20:\n",130,130);}
            }while(tab[rech].Notes[1]<0 || tab[rech].Notes[1]>20);
            break;
        }

        case(5):{
            do
             {printf(" \nIntroduire la note:");
            scanf("%f",&tab[rech].Notes[2]);
            if(tab[rech].Notes[2]<0 || tab[rech].Notes[2]>20){
                printf("\ Note %crron%ce !! : 0<note<20:\n",130,130);
            }
            }while(tab[rech].Notes[2]<0 || tab[rech].Notes[2]>20);
            break;
        }
        case(6):{
            do
            {printf(" \nIntroduire la note:");
            scanf("%f",&tab[rech].Notes[3]);
            if(tab[rech].Notes[3]<0 || tab[rech].Notes[3]>20){
                printf("\ Note %crron%ce !! : 0<note<20:\n",130,130);}
            }while(tab[rech].Notes[3]<0 || tab[rech].Notes[3]>20);
            break;}
        default:{
            printf("\n Choix érroné!!");}
    }
}







void supprimer_etd(Etudiant tab[],int *N,int rech){
    int i;
    int taille=(*N);
    for(i=rech;i<taille-1;i++){
        tab[i]=tab[i+1];
        }
    (*N)--;
}
