#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * *string_nconcat - function that concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to concatenates from s2
 * Return: concatenated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int x;
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	char *y;

	if (s1 == NULL)
	s1 = "";
	if (s2 == NULL)
	s2 = "";
	for (x = 0 ; s1[x] != '\0' ; x++)
	len1++;
	for (x = 0 ; s2[x] != '\0' ; x++)
		len2++;

	y = malloc(sizeof(char) * (len1 + n) + 1);
	if (y == NULL)
	return (NULL);
	if (n >= len2)
	{
	for (x = 0 ; s1[x] != '\0' ; x++)
	y[x] = s1[x];
	for (x = 0 ; s2[x] != '\0' ; x++)
	y[len1 + x] = s2[x];
	}
	else
	{
	for (x = 0 ; s1[x] != '\0' ; x++)
	y[x] = s1[x];
	for (x = 0 ; x < n ; x++)
	y[len1 + x] = s2[x];
	y[len1 + x] = '\0';
	}
	return (y);
}
