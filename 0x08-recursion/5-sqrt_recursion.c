#include "main.h"
#include <stdio.h>

int _sqrt(int n, int i);

/**
 * _sqrt_recursion - return the squre rootof number
 * @n: number to calculate the squre root of
 * Return: squre root
 */
int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}


/**
 * _sqrt - calculates the squre root
 * @n: number to calculate the root of
 * @i: iterate number
 * Return: natural squre root
 */
int _sqrt(int n, int i)
{
	int sqrt = i * i;

	if (sqrt > n)
		return (-1);

	else if (sqrt == n)
		return (i);

	return (_sqrt(n, i + 1));
}
