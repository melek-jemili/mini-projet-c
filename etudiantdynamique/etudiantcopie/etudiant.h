#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED

typedef struct etd
{
	int identifiant ;
	char Nom[25];
	char Prenom[25];
	float Notes[4];
	float Moy;

}Etudiant;

struct cellule
{
Etudiant valeur;
struct cellule *suivant;
};
typedef struct cellule *Liste;


Etudiant saisir_etd();

void affiche_etd(Etudiant e);

void modifier_etd(Etudiant *etd);

Liste insere(Etudiant element , Liste Lst);

void affiche_Liste_etd(Liste Lst);

Etudiant* rechercher_etd(Liste Lst, int ident);



#endif // ETUDIANT_H_INCLUDED
