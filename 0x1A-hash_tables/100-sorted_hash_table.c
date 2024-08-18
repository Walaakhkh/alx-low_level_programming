#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the created hash table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
	return (NULL);

	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (!ht->array)
	{
	free(ht);
	return (NULL);
	}

	for (i = 0; i < size; i++)
	ht->array[i] = NULL;

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Inserts or updates a key/value pair in the hash table.
 * @ht: The hash table.
 * @key: The key.
 * @value: The value.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *current, *prev;
	unsigned long int index;
	int cmp;

	if (!ht || !key || !*key || !value)
	return (0);

	index = hash_djb2((unsigned char *)key) % ht->size;

	current = ht->array[index];
	while (current)
	{
	if (strcmp(current->key, key) == 0)
	{
	free(current->value);
	current->value = strdup(value);
	return (1);
	}
	current = current->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
	return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	new_node->sprev = NULL;
	new_node->snext = NULL;

	if (ht->array[index])
	ht->array[index]->sprev = new_node;

	ht->array[index] = new_node;

	if (!ht->shead)
	{
	ht->shead = new_node;
	ht->stail = new_node;
	}
	else
	{
	current = ht->shead;
	while (current && strcmp(current->key, key) < 0)
	{
	current = current->snext;
	}

	if (current)
	{
	prev = current->sprev;
	if (prev)
	prev->snext = new_node;
	else
	ht->shead = new_node;
	new_node->sprev = prev;
	new_node->snext = current;
	current->sprev = new_node;
	}
	else
	{
	prev = ht->stail;
	prev->snext = new_node;
	new_node->sprev = prev;
	ht->stail = new_node;
	}
	}

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table.
 * @key: The key.
 *
 * Return: The value associated with the key, or NULL if key not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (!ht || !key || !*key)
	return (NULL);
	index = hash_djb2((unsigned char *)key) % ht->size;
	node = ht->array[index];

	while (node)
	{
	if (strcmp(node->key, key) == 0)
	return (node->value);
	node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the hash table in sorted order.
 * @ht: The hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
	return;

	printf("{");
	node = ht->shead;
	while (node)
	{
	printf("'%s': '%s'", node->key, node->value);
	node = node->snext;
	if (node)
	printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the hash table in reverse sorted order.
 * @ht: The hash table.
 */
void hash_table_t(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
	return;

	printf("{");
	node = ht->stail;
	while (node)
	{
	printf("'%s': '%s'", node->key, node->value);
	node = node->sprev;
	if (node)
	printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes the hash table.
 * @ht: The hash table to delete.
 */
void hash_table_t(shash_table_t *ht)
{
	shash_node_t *node, *temp;

	if (!ht)
	return;

	for (unsigned long int i = 0; i < ht->size; i++)
	{
	node = ht->array[i];
	while (node)
	{
	temp = node->next;
	free(node->key);
	free(node->value);
	free(node);
	node = temp;
	}
	}

	node = ht->shead;
	while (node)
	{
	temp = node->snext;
	free(node->key);
	free(node->value);
	free(node);
	node = temp;
	}

	free(ht->array);
	free(ht);
}
