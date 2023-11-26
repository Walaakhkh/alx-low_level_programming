#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * *array_range - function that creates an array of integers
 * @min: minimum number in array
 * @max: maximum number of array
 * Return: new alloctated memory
 */

int *array_range(int min, int max)
{
	int size;
	int i;
	int *output;

	if (min > max)
		return (NULL);
	size = (max - min) + 1;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return (NULL);
	for (i = 0 ; min <= max ; i++)
		output[i] = min++;
	return (output);
}
