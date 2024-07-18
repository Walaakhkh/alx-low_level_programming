#include <stdio.h>

/**
 * add - addition of a and b
 * @a: first number
 * @b: second number
 * Return: addition of a and b
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - subtraction of a from b
 * @a: first number
 * @b: second number
 * Return: subtraction of a from b
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - miltiplication of a and b
 * @a: first number
 * @b: second number
 * Return: multiplcation of a and b
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - division between a and b
 * @a: first number
 * @b: second number
 * Return: division of a and b
 */
int div(int a, int b)
{
	if (b == 0)
	{
	return (0);
	}
	return (a / b);
}

/**
 * mod - modulation of a and b
 * @a: first number
 * @b: second number
 * Return: modulation of a and b
 */
int mod(int a, int b)
{
	if (b == 0)
	{
	return (0);
	}
	return (a % b);
}
