#include "lists.h"

/**
 * *add_nodeint - function that adds a new node at the beginning of a
 * listint_t list.
 * @head: pointer to the address of the head of the list_t list
 * @n: integer to the new node to contain
 * Return: NULL if the function fail, otherwise the address of the
 * new element
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *x;

	x = malloc(sizeof(listint_t));
	if (x == NULL)
		return (NULL);

	x->n = n;
	x->next = *head;

	*head = x;
	return (x);
}
