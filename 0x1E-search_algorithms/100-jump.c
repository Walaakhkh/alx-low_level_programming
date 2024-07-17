#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers using Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    int step = (int) sqrt(size);
    int prev = 0;

    printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
    while (array[min(step, size) - 1] < value)
    {
        prev = step;
        step += (int) sqrt(size);
        if (prev >= (int)size)
        {
            return (-1);
	}
    }
}
