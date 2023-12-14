#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - function that adds a new node at the beginning of a list_t list
 * @head: original linked list
 * @str: string to be added to the node
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *t;
	int len1 = 0;

	t = malloc(sizeof(list_t));
	if (t == NULL)
		return (NULL);

	while (str[len1])
		len1++;

	t->len = len1;
	t->str = strdup(str);
	t->next = *head;
	*head = t;
	return (t);
}
