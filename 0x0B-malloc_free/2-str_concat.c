#include "main.h"

/**
 * *str_concat - function that concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: pointer to new allocated space
 */

char *str_concat(char *s1, char *s2)
{
	int len1 = 0;
	int len2 = 0;
	int i;
	char *x;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0 ; s1[i] != '\0' ; i++)
		len1++;
	for (i = 0 ; s2[i] != '\0' ; i++)
		len2++;

	x = malloc(sizeof(char) * (len1 + len2) + 1);

	if (x == NULL)
		return (NULL);
	for (i = 0 ; s1[i] != '\0' ; i++)
		x[i] = s1[i];
	for (i = 0 ; s2[i] != '\0'; i++)
		x[len1 + i] = s2[i];
	return (x);
}
