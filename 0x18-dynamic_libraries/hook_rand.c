#include <stdlib.h>

/**
 * rend - random function
 * Return: numbers
 */
int rand()
{
	static int i = 0;
	static int numbers[] = {9, 8, 10, 24, 75, 9};

	return (numbers[i++]);
}
