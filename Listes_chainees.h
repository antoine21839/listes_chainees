#include <stdio.h>
#include <stdlib.h>

typedef struct cellule{
    int valeur;
    struct cellule *suivant;
}Cellule, *Liste;

Cellule * alloue_cellule(int valeur);
int ajoute_cellule_a_la_fin(Liste *lst, int valeur);
int ajoute_cellule_au_debut(Liste *lst, int valeur);
void supprime_cellule_fin(Liste *lst);
Cellule * recherche(Liste lst, int valeur);
void affiche_liste(Liste lst);
void detruire_cell(Liste *lst, Cellule *cell);
int ajout_debut(Liste *lst, int val);
