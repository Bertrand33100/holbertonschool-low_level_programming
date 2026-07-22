#include "lists.h"      /* Contient la structure list_t et le prototype */
#include <stdio.h>       /* Permet d'utiliser printf() */

/**
 * print_list - Affiche tous les éléments d'une liste chaînée
 * @h: Pointeur vers le premier nœud de la liste
 *
 * Return: Retourne le nombre de nœuds de la liste
 */
size_t print_list(const list_t *h)
{
	size_t count;          /* Variable qui compte le nombre de nœuds */

	count = 0;             /* Le compteur commence à 0 */

	while (h != NULL)      /* Tant que la liste n'est pas terminée */
	{
		if (h->str == NULL)          /* Si la chaîne est NULL */
			printf("[0] (nil)\n");   /* Affiche (nil) */
		else
			printf("[%u] %s\n", h->len, h->str); /* Affiche la longueur et la chaîne */

		count++;            /* Incrémente le compteur */
		h = h->next;        /* Passe au nœud suivant */
	}

	return (count);        /* Retourne le nombre total de nœuds */
}
