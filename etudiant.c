#include "etudiant.h"
#include <stdio.h>
#include <string.h>

Etudiant saisir_etd(){
	Etudiant etd;
	printf("\n introduire l'identifiant : ");
	scanf("%d",&etd.identifiant);
	printf("\n introduire le nom: ");
	scanf("%s", etd.Nom);
	printf("\n introduire le prénom: ");
	scanf("%s",etd.Prenom);
	for ( int i=0;i<4;i++){
		printf("Note[%d]= ",i);
		scanf("%f",&etd.Notes[i]);
	}
	return etd;
}
void saisir_tab_etd(Etudiant tab[], int *N){
	Etudiant e;
	int i;
	char rep[3];
	i=*N;
	do{
		e=saisir_etd();
		tab[i]=e;
		i++;
		printf("\n Voulez-vous ajouter un autre etudiant oui/non:");
		scanf("%s",rep);
	}while(strcmp(rep,"oui")==0);
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
