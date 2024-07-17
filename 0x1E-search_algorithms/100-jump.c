#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 * using Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	int step, prev, start, i;

	if (array == NULL || size == 0)
	return (-1);

	step = (int) sqrt(size);
	prev = 0;

	printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
	while (array[prev] < value)
	{
	prev += step;
	if (prev >= (int)size)
		break;
	  printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
	}
	start = prev - step;
	printf("Value found between indexes [%d] and [%d]\n", start, prev);

	for (i = start; i <= prev && i < (int)size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
	if (array[i] == value)
	return (i);
	}
	return (-1);
}
