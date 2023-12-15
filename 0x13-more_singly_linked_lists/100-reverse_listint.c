#include "lists.h"

/**
 * reverse_listint - function that reverses a listint_t linked list
 * @head: pointer to the address of the list_t list
 * Return: pointer to the first node in the new list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *p = NULL;
	listint_t *e = NULL;

	while (*head)
	{
		e = (*head)->next;
		(*head)->next = p;
		p = *head;
		*head = e;
	}
	*head = p;
	return (*head);
}
