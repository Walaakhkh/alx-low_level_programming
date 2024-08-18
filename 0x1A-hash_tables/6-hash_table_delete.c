#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node;
	hash_node_t *temp_node;
	unsigned long int i;

	if (!ht)
	return;

	for (i = 0; i < ht->size; i++)
	{
	node = ht->array[i];
	while (node)
	{
	temp_node = node->next;
	free(node->key);
	free(node->value);
	free(node);
	node = temp_node;
	}
	}

	free(ht->array);

	free(ht);
}
