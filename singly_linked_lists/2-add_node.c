#include "lists.h"

/**
 * add_node - Ajoute un nouveau nœud au début d'une liste chaînée
 * @head: Adresse du pointeur vers le premier nœud
 * @str: Chaîne de caractères à copier dans le nouveau nœud
 *
 * Return: Retourne l'adresse du nouveau nœud ou NULL en cas d'échec
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	unsigned int len;

	/* Vérifie que les paramètres sont valides */
	if (head == NULL || str == NULL)
		return (NULL);

	/* Alloue la mémoire pour le nouveau nœud */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* Duplique la chaîne de caractères */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Calcule la longueur de la chaîne */
	len = 0;
	while (str[len] != '\0')
		len++;

	new_node->len = len;

	/* Le nouveau nœud pointe vers l'ancien premier nœud */
	new_node->next = *head;

	/* Le nouveau nœud devient la tête de la liste */
	*head = new_node;

	/* Retourne l'adresse du nouveau nœud */
	return (new_node);
}
