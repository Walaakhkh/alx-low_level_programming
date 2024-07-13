#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: head of the list
 * @n: value of the elements
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *a;
	dlistint_t *b;

	b = malloc(sizeof(dlistint_t));
	if (b == NULL)
		return (NULL);

	b->n = n;
	b->next = NULL;

	a = *head;

	if (a != NULL)
	{
		while (a->next != NULL)
			a = a->next;
		a->next = b;
	}
	else
	{
		*head = b;
	}
	b->prev = a;

	return (b);
}
