#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth node of a listint_t
 * linked list
 * @head: pointer to address of the head of list_t list
 * @index: index of the node to return
 * Return: pointer to the node or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *t = head;

	while (t && i < index)
	{
		t = t->next;
		i++;
	}
	return (t ? t : NULL);
}
