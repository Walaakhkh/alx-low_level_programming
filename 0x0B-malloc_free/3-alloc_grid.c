#include "main.h"

/**
 * **alloc_grid - function that returns a pointer to
 * 2 dimensional array of integers
 * @width: columns number
 * @height: rows number
 * Return: pointer to array
 */

int **alloc_grid(int width, int height)
{
	int **x, i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	x =  malloc(sizeof(int *) * height);

	if (x == NULL)
		return (NULL);

	for (i = 0 ; i < height ; i++)
	{
		x[i] = malloc(sizeof(int) * width);

		if (x[i] == NULL)
		{
			free(x);
			for (j = 0 ; j <= height ; j++)
				free(x[j]);
			return (NULL);
		}
		for (j = 0 ; j < width ; j++)
			x[i][j] = 0;
	}
	return (x);
}
