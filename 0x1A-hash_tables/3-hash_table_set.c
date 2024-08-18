#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_new_node - Creates a new hash table node.
 * @key: The key for the new node.
 * @value: The value for the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
static hash_node_t *create_new_node(const char *key, const char *value)
{
	hash_node_t *new_node;
	char *key_copy, *value_copy;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	return (NULL);

	key_copy = strdup(key);
	if (!key_copy)
	{
	free(new_node);
	return (NULL);
	}

	value_copy = strdup(value);
	if (!value_copy)
	{
	free(key_copy);
	free(new_node);
	return (NULL);
	}

	new_node->key = key_copy;
	new_node->value = value_copy;
	new_node->next = NULL;

	return (new_node);
}

/**
 * hash_table_set - Adds or updates an element in a hash table.
 * @ht: The hash table to add or update the key/value to.
 * @key: The key, cannot be an empty string.
 * @value: The value associated with the key. Must be duplicated.
 *
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *current_node, *new_node;

	if (!ht || !key || *key == '\0' || !value)
	return (0);

	index = key_index((const unsigned char *)key, ht->size);

	current_node = ht->array[index];
	while (current_node)
	{
	if (strcmp(current_node->key, key) == 0)
	{
	free(current_node->value);
	current_node->value = strdup(value);
	if (!current_node->value)
	return (0);
	return (1);

	}
	current_node = current_node->next;
	}

	new_node = create_new_node(key, value);
	if (!new_node)
	return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
