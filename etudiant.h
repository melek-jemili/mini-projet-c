#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H__INCLUDED

typedef struct etd
{
	int identifiant ;
	char Nom[25];
	char Prenom[25];
	float Notes[4];
	float Moy;
	
}Etudiant;
Etudiant saisir_etd();
void saisir_tab_etd(Etudiant tab[], int *N);
void affiche_etd(Etudiant e);
void affiche_tableau_etd(Etudiant tab[],int N);
int recherche_etd(Etudiant tab[],int N,int ident);



#endif // ETUDIANT_H_INCLUDED