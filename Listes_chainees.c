#include <stdio.h>
#include <stdlib.h>

typedef struct cellule{
    int valeur;
    struct cellule *suivant;
}Cellule, *Liste;

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

/* complexité =  O(n)*/
int ajoute_cellule_a_la_fin(Liste *lst, int valeur){
    Liste tmp; /*Cellule *tmp*/

    assert(NULL != lst); /* lst est un pointeur sur une liste */

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
        if(NULL == tmp->suivant)
            fprintf(stderr, "Erreur lors de l'ajout d'une cellule\n");
            return 0;
    }
    return 1;
}

int ajoute_cellule_au_debut(Liste *lst, int valeur){
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
        tmp = alloue_cellule(valeur);
        if(NULL == tmp){
            fprintf(stderr, "Erreur lors de l'ajout d'une cellule\n");
            return 0;
        }
        tmp->suivant = *lst;
        *lst = tmp;
    }
    return 1;
}

void supprime_cellule_fin(Liste *lst){
    Liste tmp;
    assert(NULL != lst);
    assert(NULL != *lst);
    if((*lst)->suivant == NULL)
        free(*lst);
        (*lst) = NULL;
    else{
        tmp = *Lst;
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

void affiche_liste(Liste lst){
    while(NULL != lst)
        printf("%d ",lst->valeur);
        lst = lst->suivant;
}

 void detruire_cell(Liste *lst, Cellule *cell){
//      Liste tmp;
     assert(NULL != lst);
     assert(NULL != *lst);

     if((*lst)->suivant == cell)
        free(*cell);
        (*cell) = NULL;
     else{
        tmp = *lst;
        while(tmp->suivant != cell){
            tmp = tmp->suivant;
        free(tmp->suivant);
        tmp->suivant = NULL;
        }
     }
 }

int ajout_debut(Liste *lst, int val){
    Liste tmp;
    assert(NULL != lst);
    tmp = *lst;
    *lst = alloue_cellule(val);
    if(NULL == *lst){
        fprintf(stderr, "Erreur lors de l'allocation\n");
        return 0;
    }
    *lst->suivant = tmp;
}

