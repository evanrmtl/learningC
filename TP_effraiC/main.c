#include <stdio.h>
#include <stdlib.h>

typedef struct maillon {
    int x;
    struct maillon *suiv;
} maillon_t;

maillon_t *ajouter_debut(maillon_t *pliste, int val);

maillon_t *ajouter_fin(maillon_t *pliste, int val);

maillon_t *rechecher(maillon_t *pliste, int val);

maillon_t *supprimer_debut(maillon_t *pliste);

maillon_t *supprimer_fin(maillon_t *pliste);

maillon_t *supprimer_val(maillon_t *pliste, int val);

void afficher(maillon_t *pliste);

void supprimer_liste(maillon_t *pliste);

int main(void) {
    maillon_t *initialeList = NULL;
    initialeList = ajouter_fin(initialeList, 10);
    initialeList = ajouter_fin(initialeList, 20);
    initialeList = ajouter_fin(initialeList, 30);
    initialeList = ajouter_fin(initialeList, 40);
    initialeList = ajouter_fin(initialeList, 1000);
    initialeList = ajouter_fin(initialeList, 1200);

    afficher(initialeList);

    initialeList = supprimer_val(initialeList, 30);

    afficher(initialeList);

    rechecher(initialeList, 14);
    rechecher(initialeList, 10);
    rechecher(initialeList, 1000);
    rechecher(initialeList, 123);

    supprimer_liste(initialeList);
    return 0;
}

void supprimer_liste(maillon_t *pliste) {
    maillon_t *temp;
    maillon_t *courant = pliste;
    while (courant != NULL) {
        temp = courant;
        courant = courant->suiv;
        free(temp);
    }
}

maillon_t *ajouter_debut(maillon_t *pliste, int val) {
    maillon_t *nouveau = (maillon_t *) malloc(sizeof(maillon_t));
    nouveau->x = val;
    if (pliste == NULL) {
        nouveau->suiv = NULL;
        return nouveau;
    }
    nouveau->suiv = pliste;
    return nouveau;
}

maillon_t *ajouter_fin(maillon_t *pliste, int val) {
    maillon_t *nouveau = (maillon_t *) malloc(sizeof(maillon_t));
    nouveau->x = val;
    nouveau->suiv = NULL;
    if (pliste == NULL) {
        return nouveau;
    }
    maillon_t *courant = pliste;
    while (courant->suiv != NULL) {
        courant = courant->suiv;
    }
    courant->suiv = nouveau;
    return pliste;
}

maillon_t *rechecher(maillon_t *pliste, int val) {
    maillon_t *courant = pliste;
    char found = 0;
    while(courant != NULL && found == 0) {
        if(courant->x == val)
            found = 1;
        else {
            courant = courant->suiv;
        }
    }
    return courant;
}

maillon_t *supprimer_debut(maillon_t *pliste) {
    maillon_t *wanted = pliste->suiv;
    free(pliste);
    return wanted;
}

maillon_t *supprimer_fin(maillon_t *pliste) {
    if (pliste == NULL) {
        return pliste;
    }
    maillon_t *courant = pliste;
    while (courant->suiv->suiv != NULL) {
        courant = courant->suiv;
    }
    free(courant->suiv);
    courant->suiv = NULL;
    return pliste;
}

maillon_t *supprimer_val(maillon_t *pliste, int val) {
    maillon_t *delete = rechecher(pliste, val);
    if(delete == NULL) {
        return NULL;
    }
    maillon_t *courant = pliste;
    while(courant->suiv != delete) {
        courant = courant->suiv;
    }
    courant->suiv = courant->suiv->suiv;
    return pliste;
}

void afficher(maillon_t *pliste) {
    maillon_t *courant = pliste;
    while (courant != NULL) {
        printf("%d\n", courant->x);
        courant = courant->suiv;
    }
}