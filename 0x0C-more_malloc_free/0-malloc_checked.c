#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * malloc_checked - function that allocates memory using malloc
 * @b: size of memory
 * Return: pointer to new memory allocated
 */

void *malloc_checked(unsigned int b)
{
	char *x;

	x = malloc(b);
	if (x == NULL)
		exit(98);
	else
		return (x);
}
