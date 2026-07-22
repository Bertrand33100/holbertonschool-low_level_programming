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

/**
 * list_len - Compte le nombre d'éléments d'une liste chaînée
 * @h: Pointeur vers le premier nœud de la liste
 *
 * Return: Retourne le nombre de nœuds de la liste
 */
size_t list_len(const list_t *h);

/**
 * add_node - Ajoute un nouveau nœud au début d'une liste chaînée
 * @head: Adresse du pointeur vers le premier nœud
 * @str: Chaîne de caractères à copier dans le nouveau nœud
 *
 * Return: Retourne l'adresse du nouveau nœud ou NULL en cas d'échec
 */
list_t *add_node(list_t **head, const char *str);

/**
 * add_node_end - Ajoute un nouveau nœud à la fin d'une liste chaînée
 * @head: Adresse du pointeur vers le premier nœud
 * @str: Chaîne de caractères à copier dans le nouveau nœud
 *
 * Return: Retourne l'adresse du nouveau nœud ou NULL en cas d'échec
 */
list_t *add_node_end(list_t **head, const char *str);

/**
 * free_list - Libère toute la mémoire d'une liste chaînée
 * @head: Pointeur vers le premier nœud de la liste
 */
void free_list(list_t *head);

#endif /* LISTS_H */
