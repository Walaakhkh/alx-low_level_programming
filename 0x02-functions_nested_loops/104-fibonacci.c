#include <stdio.h>
/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count;
	unsigned long a = 1, b = 2, limit = 1000000000, next_half1, next_half2;
	unsigned long a_half1, a_half2, b_half1, b_half2;

	printf("%lu, %lu", a, b);
	for (count = 2; count < 90; count++)
	{
	unsigned long next = a + b;

	printf(", %lu", next);
	a = b;
	b = next:
	}
	a_half1 = a / limit;
	a_half2 = a % limit;
	b_half1 = b / limit;
	b_half2 = b % limit;
	for (count = 90; count < 98; count++)
	{
	next_half1 = a_half1 + b_half1;
	next_half2 = a_half2 + b_half2;
	if (next_half2 >= limit)
	{
	next_half1 += 1;
	next_half2 -= limit;
	}
	printf(", %lu%09lu", next_half1, next_half2);
	a_half1 = b_half1;
	a_half2 = b_half2;
	b_half1 = next_half1;
	b_half2 = next_half2;
	}
	printf("\n");
	return (0);
}
