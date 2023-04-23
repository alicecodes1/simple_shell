#include "shell.h"

/**
 * _strcat - concatenate 2 str
 * @dest: str to be appended to
 * @src: str to append
 * Return: concatenated str
 */
char *_strcat(char *dest, char *src)
{
	int len = 0;
	int length2 = 0;
	int total_lent = 0;
	int j = 0;

	/* find total length of both str to _realloc */
	while (dest[len] != '\0')
	{
		len++;
		total_lent++;
	}
	while (src[length2] != '\0')
	{
		length2++;
		total_lent++;
	}

	/* _realloc bcos dest was malloced outside of function */
	dest = _realloc(dest, len, sizeof(char) * total_lent + 1);

	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}
