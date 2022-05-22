#include <stdio.h>
#include <stdlib.h>

typedef struct cellule{
    int valeur;
    struct cellule *suivant;
}Cellule, *Liste;

Cellule * alloue_cellule(int valeur);
int ajoute_cellule_fin(Liste *lst, int valeur);
int ajoute_cellule_debut(Liste *lst, int valeur);
void supprime_cellule_debut(Liste *lst);
void supprime_cellule_fin(Liste *lst);
Cellule * recherche(Liste lst, int valeur);
void affiche_liste(Liste lst);
void parcours_liste(Liste lst, void (*appliquer)(Cellule *));
