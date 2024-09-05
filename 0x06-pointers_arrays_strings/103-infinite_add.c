#include "main.h"
#include <stdio.h>

/**
 * infinite_add - Adds two numbers stored as strings
 * @n1: The first number as a string
 * @n2: The second number as a string
 * @r: The buffer to store the result
 * @size_r: The size of the buffer
 *
 * Return: A pointer to the result, or 0 if the result can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k = 0, carry = 0, sum = 0;
	int len1 = 0, len2 = 0;

	while (n1[len1] != '\0')
	len1++;
	while (n2[len2] != '\0')
	len2++;

	len1--;
	len2--;
	if (size_r <= 1)
	return (0);

	r[size_r - 1] = '\0';
	k = size_r - 2;

	while (len1 >= 0 || len2 >= 0 || carry)
	{
	sum = carry;
	if (len1 >= 0)
	sum += n1[len1--] - '0';
	if (len2 >= 0)
	sum += n2[len2--] - '0';
	carry = sum / 10;
	sum = sum % 10;

	if (k < 0)
	return (0);

	r[k--] = sum + '0';
	}

	if (k >= 0)
	for (i = k + 1, j = 0; r[i] != '\0'; i++, j++)
	r[j] = r[i];
	r[j] = '\0';

	return (r);
}
