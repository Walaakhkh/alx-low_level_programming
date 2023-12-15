#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * print_listint_safe - function that prints a listint_t linked list
 * @head: pointer to address head of the list_t list
 * Return:  number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *t, *h;
	size_t no = 1;

	if (head == NULL || head->next == NULL)
	return (0);

	t = head->next;
	h = (head->next)->next;

	while (h)
	{
	if (t == h)
	{
	t = head;
	while (t != h)
	{
	no++;
				t = t->next;
				h = h->next;
			}
			t = t->next;
			while (t != h)
			{
				no++;
				t = t->next;
			}
		return (no);
			}
	t = t->next;
	h = (h->next)->next;
		}
return (0);
}
