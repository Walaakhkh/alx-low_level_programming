#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the data (n) of a
 * listint_t linked list
 * @head: pointer to address of the head of the list_t list
 * Return: resulting sum
 */
int sum_listint(listint_t *head)
{
	int s = 0;
	listint_t *t = head;

	while (t)
	{
		s += t->n;
		t = t->next;
	}
	return (s);
}
