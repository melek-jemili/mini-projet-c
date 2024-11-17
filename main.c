#include <stdio.h>
#include <stdlib.h>
#include "etudiant.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 

{ 	Etudiant tableau_etd[100];
	int id;
	int rech=-1;
	int taille_tab=0;
	saisir_tab_etd(tableau_etd,&taille_tab);
	affiche_tableau_etd(tableau_etd,taille_tab);
	printf("\n introduire l'identifiant à chercher:");
	scanf("%d",&id);
	rech=recherche_etd(tableau_etd,taille_tab,id); // rech c'est l'indice de l'étudiant trouvé
	if (rech==-1){
		printf("\n identifiant inéxistant");
	}
	else{
		affiche_etd(tableau_etd[rech]);
	}
	return 0;
}