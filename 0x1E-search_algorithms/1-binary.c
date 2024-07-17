#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search - Perform binary search on sorted array
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of value in array, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	int low, high, mid, i;

	if (array == NULL)
	return (-1);

	low = 0;
	high = size - 1;

	while (low <= high)
	{
	mid = (low + high) / 2;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
	if (i > low)
	printf(", ");
	printf("%d", array[i]);
	}
	printf("\n");

	if (array[mid] == value)
	return (mid);
	else if (array[mid] < value)
	low = mid + 1;
	else
	high = mid - 1;
	}

	return (-1);
}
