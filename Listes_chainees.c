#include "Listes_chainees.h"

Cellule * alloue_cellule(int valeur){
    Cellule *tmp;
    tmp = (Cellule *)malloc(sizeof(Cellule));
    if(NULL == tmp){
        fprintf(stderr, "Erreur lors de l'allocation de la mémoire\n");
        return NULL;
    }
    tmp->valeur = valeur;
    tmp->suivant = NULL;
    return tmp;
}

/* void ajoute_cellule(Liste *lst, int valeur){
    Liste tmp;
    if(NULL == *lst)
        *lst = alloue_cellule(valeur);
    else{
        tmp = alloue_cellule(valeur);
        tmp->suivant = *lst;
        *lst = tmp;
    }
} */

int ajoute_cellule_fin(Liste *lst, int valeur){
    Liste tmp;

    assert(NULL != lst);

    if(NULL == *lst){
        *lst = alloue_cellule(valeur);
        if(NULL == *lst){
            fprintf(stderr, "Erreur lors de l'ajout d'une cellule\n");
            return 0;
        }
    }
    else{
        tmp = *lst;
        while(NULL != tmp->suivant)
            tmp = tmp->suivant;
        tmp->suivant = alloue_cellule(valeur);
        if(NULL == tmp->suivant){
            fprintf(stderr, "Erreur lors de l'ajout d'une cellule\n");
            return 0;
        }
    }
    return 1;
}

int ajoute_cellule_debut(Liste *lst, int valeur){
    Liste tmp;
    
    assert(NULL != lst);

    tmp = alloue_cellule(valeur);
    if(NULL == tmp){
        fprintf(stderr, "Erreur lors de l'ajout d'une cellule\n");
        return 0;
    }
    tmp->suivant = *lst;
    *lst = tmp;
     return 1;
}

void supprime_cellule_debut(Liste *lst){
    Liste tmp;
    
    assert(NULL != lst);
    assert(NULL != *lst);
    
    tmp = *lst;
    *lst = (*lst)->suivant;
    free(tmp);
}

void supprime_cellule_fin(Liste *lst){
    Liste tmp;
    
    assert(NULL != lst);
    assert(NULL != *lst);
    
    if((*lst)->suivant == NULL){
        free(*lst);
        (*lst) = NULL;
    }
    else{
        tmp = *lst;
        while(tmp->suivant->suivant)
            tmp = tmp->suivant;
        free(tmp->suivant);
        tmp->suivant = NULL;
    }
}

Cellule * recherche(Liste lst, int valeur){
    while(NULL != lst && lst->valeur != valeur)
        lst = lst->suivant;
    return lst;
}


void parcours_liste(Liste lst, void (*appliquer)(Cellule *)){
    while(NULL != lst){
        appliquer(lst);
        lst = lst->suivant;
    }
}

