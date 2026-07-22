#include "lists.h"

/**
 * list_len - Compte le nombre d'éléments d'une liste simplement chaînée
 * @h: Pointeur vers le premier nœud de la liste
 *
 * Return: Retourne le nombre total de nœuds présents dans la liste
 */
size_t list_len(const list_t *h)
{
	/* Variable qui servira à compter le nombre de nœuds */
	size_t count;

	/* Le compteur commence à 0 */
	count = 0;

	/* Parcourt la liste jusqu'à atteindre la fin (NULL) */
	while (h != NULL)
	{
		/* Un nœud a été trouvé : on incrémente le compteur */
		count++;

		/* Passe au nœud suivant */
		h = h->next;
	}

	/* Retourne le nombre total de nœuds */
	return (count);
}
