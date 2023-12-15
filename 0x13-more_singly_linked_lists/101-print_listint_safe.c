#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - count the number of unique nodes
 * @head: pointer to address head of the list_t list
 * Return: 0 if the list is not looped otherwise the number of unique nodes
 */
size_t looped_listint_len(const listint_t *head)
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

/**
 * print_listint_safe - print the list_t list safly
 * @head: pointer to address head of the list_t list
 * Return: the number of the nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t no, index = 0;

	no = looped_listint_len(head);
	if (no == 0)
	{
		for (; head != NULL; no++)
		{
			printf("[%p]%d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < no; index++)
		{
			printf("[%p]%d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("->[%p]%d\n", (void *)head, head->n);
	}
	return (no);
}
