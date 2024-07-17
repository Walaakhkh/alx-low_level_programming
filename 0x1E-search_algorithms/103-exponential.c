#include <stdio.h>
#include <stdlib.h>

int binary_search(int *array, int left, int right, int value);

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 *
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The first index where value is located,
 * or -1 if value is not present
 * or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, left, right;
	int result;

	if (array == NULL)
	return (-1);

	if (array[0] == value)
	{
	printf("Value checked array[0] = [%d]\n", array[0]);
	return (0);
	}

	i = 1;
	while (i < size && array[i] <= value)
	{
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	i = i * 2;
	}

	left = i / 2;
	right = (i < size) ? i : size;

	printf("Value found between indexes [%ld] and [%ld]\n", left,
			right - 1);

	result = binary_search(array, left, right - 1, value);
	return (result);
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using the Binary search algorithm
 *
 * @array: Pointer to the first element of the array to search in
 * @left: Left boundary of the array/subarray
 * @right: Right boundary of the array/subarray
 * @value: Value to search for
 *
 * Return: The first index where value is located,
 * or -1 if value is not present
 */
int binary_search(int *array, int left, int right, int value)
{
	int i, mid;

	while (left <= right)
	{
	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
	printf("%d", array[i]);
	if (i < right)
	printf(", ");
	}
	printf("\n");

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	return (mid);
	if (array[mid] < value)
	left = mid + 1;
	else
	right = mid - 1;
	}
	return (-1);
}
