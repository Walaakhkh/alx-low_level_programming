#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a listint_t
 * linked list, and returns the head node’s data (n)
 * @head: pointer to address of the head of the list_t list
 * Return: the data inside the deleted element or 0 if the list
 * is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *t;
	int x;

	if (!head || !*head)
		return (0);

	x = (*head)->n;
	t = (*head)->next;
	free(*head);
	*head = t;

	return (x);
}
