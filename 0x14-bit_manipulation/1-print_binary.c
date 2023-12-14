#include "main.h"

/**
 * _pow - function calculate (base ^ power)
 * @base: base
 * @power: power
 * Return: value of (base ^ power)
 */
unsigned long int _pow(unsigned int base, unsigned int power)
{
	unsigned long int x;
	unsigned int y;

	x = 1;
	for (y = 0; y <= power; y++)
		x += base;
	return (x);
}

/**
 * print_binary - function that prints the binary representation of a number
 * @n: number to be printed
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int i, r;
	char z;

	z = 0;
	i = _pow(2, sizeof(unsigned long int) * 8 - 1);
	while (i != 0)
	{
		r = n & i;
		if (r == i)
		{
			z = 1;
			_putchar('1');
		}
		else if (z == 1 || i == 1)
		{
			_putchar('0');
		}
		i >>= 1;
	}
}
