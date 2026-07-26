#include <stdio.h>

void afficher_status(int pv, int or, char *arme) {
    printf("status : %d PV | %d or | arme: %s\n", pv, or, arme);
    printf("-------------------------\n");
}

void initialiser_hero(int *pv, int *or, char **arme_joueur, char ** catalogue) {
        *pv = 100;
        *or = 15;
        *arme_joueur = catalogue [0];
        printf("=> Le Héros entre dans le donjon.\n");
}

void declencher_piege_acide(int *pv, char **arme_joueur, char **catalogue)
{
    printf("piège à acide se décenche;\n");
    *pv -= 30;
    *arme_joueur = catalogue[3];
    printf("=> vous perdez 30 pv et votre arme fond !\n");

}
int main() {
    char *inventaire[4] = {
        "Dague rouillée",
        "Epee longue",
        "Hache de feu",
        "Main nues"
    };

    int hero_pv;
    int hero_or;
    char *hero_arme;
    initialiser_hero(&hero_pv, &hero_or, &hero_arme, inventaire);
    afficher_status(hero_pv,hero_or, hero_arme);
    declencher_piege_acide(&hero_pv, &hero_arme, inventaire);
    }



