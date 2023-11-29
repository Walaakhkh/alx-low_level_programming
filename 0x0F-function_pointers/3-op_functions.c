#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - return sum of numbers
 * @a: first number
 * @b: second number
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - return diffrence between numbers
 * @a: first number
 * @b: second number
 * Return: diffrence between a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - return product of numbers
 * @a: first number
 * @b: second number
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - return division of numbers
 * @a: first number
 * @b: second number
 * Return: division of a and b
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - return reminder of division of numbers
 * @a: first number
 * @b: second number
 * Return: reminder of division of a by b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
