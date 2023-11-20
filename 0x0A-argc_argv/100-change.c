#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make
 * change for an amount of money
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int x;
	int y = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	x = atoi(argv[1]);

	if (x < 0)
		printf("%d\n", 0);

	while (x > 0)
	{
		if (x >= 25)
			x = x - 25;
		else if (x >= 10)
			x = x - 10;
		else if (x >= x - 5)
			x = x - 5;
		else if (x >=  2)
			x = x - 2;
		else if (x >= 1)
			x = x - 1;
		y++;
	}
	printf("%d\n", y);
	return (0);
}
