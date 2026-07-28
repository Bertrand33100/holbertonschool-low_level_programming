#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * update_node - updates the value of an existing node
 * @node: node to update
 * @value: new value
 *
 * Return: 1 on success, 0 on failure
 */
static int update_node(hash_node_t *node, const char *value)
{
	char *copy;

	copy = strdup(value);
	if (copy == NULL)
		return (0);

	free(node->value);
	node->value = copy;

	return (1);
}

/**
 * hash_table_set - adds or updates an element in the hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	for (node = ht->array[index]; node; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
			return (update_node(node, value));
	}

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	node->key = strdup(key);
	node->value = strdup(value);
	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (0);
	}

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
