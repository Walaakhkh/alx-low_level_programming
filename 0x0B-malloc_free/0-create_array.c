#include "main.h"

/**
 * *create_array - function that creates an array of chars
 * and initializes it with a specific char
 * @size: size of an array
 * @c: characters to be store in array
 * Return: pointer to array
 */

char *create_array(unsigned int size, char c)
{
	unsigned int x;
	char *y;

	if (size == 0)
		return (NULL);

	y = malloc(sizeof(char) * size);

	if (y == NULL)
		return (NULL);

	for (x = 0 ; x < size ; x++)
		y[x] = c;
	return (y);
}
