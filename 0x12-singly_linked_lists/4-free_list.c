#include "lists.h"
#include <stdlib.h>

/**
 * free_list - function that frees a list_t list
 * @head: head of linked list
 * Return: no return
 */
void free_list(list_t *head)
{
	list_t *c;


	while ((c = head) != NULL)
	{
		head = head->next;
		free(c->str);
		free(c);
	}
}
