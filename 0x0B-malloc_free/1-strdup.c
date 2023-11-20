#include "main.h"

/**
 * *_strdup -  function that returns a pointer to a newly
 * allocated space in memory, which contains a copy of the
 * string given as a parameter
 * @str: string to copy to new memory
 * Return: pointer to new memory
 */

char *_strdup(char *str)
{
	int i;
	char *x;
	int y = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0 ; str[i] != '\0' ; i++)
		y++;

	x = malloc(sizeof(char) * y + 1);

	if (x == NULL)
		return (NULL);
	for (i = 0 ; str[i] != '\0' ; i++)
		x[i] = str[i];

	return (x);
}
