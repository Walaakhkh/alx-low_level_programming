#include <stdio.h>

int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;

/*
* write your line of code here...
* Remember:
* - you are not allowed to use the variable a
* - you are not allowed to modify the variable p
* - you can only write one statement
* - you are not allowed to use ,
* - you are not allowed to code anything else than the line of expected
* line of code at the expected line
*/
	*(p + 5) = 98;
	/* ...so that this prints 98\n */
	printf("a[2] = %d\n", a[2]);
 	return (0);
}