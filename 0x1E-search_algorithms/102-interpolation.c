#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * interpolation_search - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 * Return: first index where value is located or -1 if NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t pos;

	if (array == NULL || size == 0)
	return (-1);

	while (low <= high && value >= array[low] && value <= array[high])
	{
	if (low == high)
	{
	if (array[low] == value)
	return (low);
	return (-1);
	}

	pos = low + (((double)(high - low) / (array[high] - array[low]))
			* (value - array[low]));

	printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

	if (array[pos] == value)
	return (pos);

	if (array[pos] < value)
	low = pos + 1;
	else
	high = pos - 1;
	}

	if (low < size && (value < array[low] || value > array[high]))
	printf("Value checked array[%lu] is out of range\n", low);

	return (-1);
}
