#include <stddef.h>
#include <stdio.h>
#include "search_algos.h"

void print_array(int *array, size_t left, size_t right);

/**
 * print_array - Prints the current array being searched
 * @array: The array to be printed
 * @left: Left boundary index
 * @right: Right boundary index
 */
void print_array(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
       for (size_t i = left; i <= right; i++)
	{
		printf("%d", array[i]);
	if (i < right)
	{
	printf(", ");
	}
	}
	printf("\n");
}

/**
 * binary_search - Searches for a value in a sorted array using the binary
 * search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index where the value is located,
 * or -1 if not found or array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL)
	{
	return (-1);
	}

	size_t left = 0;
	size_t right = size - 1;

	while (left <= right)
	{
	print_array(array, left, right);
	size_t mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
	return (mid);
	}

	else if (array[mid] < value)
	{
	left = mid + 1;
	}
	else
	{
	right = mid - 1;
	}
	}

	return (-1);
}
