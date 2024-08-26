#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int a = 1, b = 2, next;
	int count;

	printf("%ld, %ld", a, b);  /* Print the first two numbers */

	for (count = 3; count <= 50; count++)
	{
	next = a + b;
	printf(", %ld", next);
	a = b;
	b = next;
	}

	printf("\n");  /* Print a new line at the end */
	return (0);
}
