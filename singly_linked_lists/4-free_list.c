#include "lists.h"

/**
 * free_list - Libère toute la mémoire d'une liste chaînée
 * @head: Pointeur vers le premier nœud de la liste
 */
void free_list(list_t *head)
{
	list_t *temp;

	/* Parcourt toute la liste */
	while (head != NULL)
	{
		/* Sauvegarde l'adresse du nœud suivant */
		temp = head->next;

		/* Libère la chaîne de caractères */
		free(head->str);

		/* Libère le nœud courant */
		free(head);

		/* Passe au nœud suivant */
		head = temp;
	}
}
