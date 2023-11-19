#include "main.h"

/**
 * _pow_recursion - find a power of a number over number
 * @x: base number
 * @y: power
 * Return: x power y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, (y - 1)));
	return (0);
}
