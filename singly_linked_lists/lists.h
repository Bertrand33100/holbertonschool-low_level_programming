#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct list_s - Structure représentant un nœud d'une liste chaînée
 * @str: Chaîne de caractères stockée dans le nœud
 * @len: Longueur de la chaîne de caractères
 * @next: Pointeur vers le nœud suivant
 *
 * Description: Cette structure représente un élément d'une
 * liste simplement chaînée.
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* Prototype des fonctions */

/**
 * print_list - Affiche tous les éléments d'une liste chaînée
 * @h: Pointeur vers le premier nœud de la liste
 *
 * Return: Retourne le nombre total de nœuds de la liste
 */
size_t print_list(const list_t *h);

#endif /* LISTS_H */