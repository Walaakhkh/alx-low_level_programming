#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints the elements of an array
 *
 * @array: The array to print
 * @left: The starting index of the subarray to print
 * @right: The ending index of the subarray to print
 */
void print_array(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Recursively searches for a value in a sorted
 * array of integers using the Binary search algorithm
 *
 * @array: Pointer to the first element of the array to search in
 * @left: Left boundary of the array/subarray
 * @right: Right boundary of the array/subarray
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if value is not present
 */
int advanced_binary_recursive(int *array, int left, int right, int value)
{
	int mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		return (advanced_binary_recursive(array, left, mid, value));
	}
	else if (array[mid] < value)
	{
		return (advanced_binary_recursive(array, mid + 1, right, value));
	}
	else
	return (advanced_binary_recursive(array, left, mid - 1, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * using the Advanced Binary search algorithm
 *
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if value is not present
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
