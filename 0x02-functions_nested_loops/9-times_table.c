#include "main.h"
#include <stdio.h>

/**
 * times_table - function prints 9 times table
 */

void times_table(void)
{
	int i, j, result;

	for (i = 0 ; i < 10 ; i++)
	{
		for (j = 0 ; j < 10 ; j++)
		{
			result = i * j;
			printf("%2d, ", result);
		}
		printf("\n");
	}
}
