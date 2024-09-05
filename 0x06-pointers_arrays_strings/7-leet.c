#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @s: The input string.
 *
 * Return: The pointer to the encoded string.
 */
char *leet(char *s)
{
	int i, j;
	char letters[] = "aAeEoOtTlL";
	char leet[] = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
	for (j = 0; j < 10; j++)
	{
	if (s[i] == letters[j])
	{
	s[i] = leet[j];
	break;
	}
	}
	}

	return (s);
}
