#include "lists.h"

/**
 * add_nodeint_end -  function that adds a new node at the end of a
 * listint_t list
 * @head: pointer to address of the head of the list_t list
 * @n: integer to new node to contain
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *x, *y;

	x = malloc(sizeof(listint_t));
	if (x == NULL)
		return (NULL);

	x->n = n;
	x->next = NULL;

	if (*head == NULL)
		*head = x;

	else
	{
		y = *head;
		while (y->next != NULL)
			y = y->next;
		y->next = x;
	}
	return (*head);
}
