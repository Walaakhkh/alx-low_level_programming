#include "lists.h"

/**
 * delete_nodeint_at_index -  function that deletes the node at index
 * index of a listint_t linked list
 * @head: pointer to first element in the list
 * @index: index to node to delete
 * Return: 1 if success, -1 if fail
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *t = *head;
	listint_t *c = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(t);
		return (1);
	}

	while (i < index - 1)
	{
		if (!t || !(t->next))
			return (-1);
		t = t->next;
		i++;
	}
	c = t->next;
	t->next = c->next;
	free(c);

	return (1);
}
