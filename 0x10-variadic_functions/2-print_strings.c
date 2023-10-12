#include "variadic_functions.h"
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - function that prints strings
 * @separator: string to be printed between the strings
 * @n: number of parameters
 * @...: variable number of string to be printed
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int index;
	va_list strings;
	char *str;

	va_start(strings, n);

	for (index = 0; index < n; index++)
	{
		str = va_arg(strings, char *);
		if (strings == NULL)
			printf("(nil)");
		else
			printf("%s", str);
		if (index != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");
	va_end(strings);
}
