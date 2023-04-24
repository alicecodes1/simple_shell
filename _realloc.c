#include "shell.h"

/**
 * _realloc - allocate memory & set all values to 0
 * @ptr: ptr to the memory previously allocated (malloc(old_size))
 * @old_size: size previously to be  allocated
 * @new_size: new size to be reallocated
 * Return: pointer to be reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	if (new_size == 0 && ptr != NULL) /* free memory if reallocate 0 */
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size) /* return pointer if reallocating same old size */
		return (ptr);

	if (ptr == NULL) /* malloc new size if ptr is originally null */
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		else
			return (p);
	}

	p = malloc(new_size); /* malloc & check error */
	if (p == NULL)
		return (NULL);

	/* fill up values until min of old or new size */
	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)p + i) = *((char *)ptr + i);
	free(ptr); /* free old ptr */

	return (p);
}

