#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - function that adds a new node at the end of a list_t list
 * @head: head of linked list
 * @str: string to be stored in the list
 * Return: the address of the new element, or NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *e, *c;
	size_t n;

	e = malloc(sizeof(list_t));
	if (e == NULL)
		return (NULL);

	e->str = strdup(str);

	for (n = 0; str[n]; n++)
		;
	e->len = n;
	e->next = NULL;
	c = *head;

	if (c == NULL)
	{
		*head = e;
	}
	else
	{
		while (c->next != NULL)
			c = c->next;
		c->next = e;
	}
	return (*head);
}
