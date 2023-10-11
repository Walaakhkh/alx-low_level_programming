#include <stdlib.h>
#include "dog.h"
#include <stdio.h>

/**
 * free_dog - function that frees dogs
 * @d: dog to set free
 */

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
