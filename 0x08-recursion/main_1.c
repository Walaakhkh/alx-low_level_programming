#include <stdio.h>

int is_palindrome(char *);

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	r = is_palindrome("abcdcba");
	printf("%d\n", r);
	return (0);
}
