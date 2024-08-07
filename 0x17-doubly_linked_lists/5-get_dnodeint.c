#include "lists.h"

/**
 * get_dnodeint_at_index - function that returns the nth node of a dlistint_t
 * linked list
 * @head: head of the list
 * @index: index of the node
 * Return: nth node
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int a;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	a = 0;

	while (head != NULL)
	{
		if (a == index)
			break;
		head = head->next;
		a++;
	}
	return (head);
}
