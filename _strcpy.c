#include "shell.h"

/**
 * _strcpy - copies the str pointed to by src,
 * which includes the terminating null byte (\0),
 * to the buf pointed to by dest
 * @dest: copy source to this buf
 * @src: this is the source to copy
 * Return: copy of origin source
 */

char *_strcpy(char *dest, char *src)
{
	int t, length;

	for (length = 0; src[length] != '\0'; length++)
		;

	for (t = 0; t <= length; t++)
		dest[t] = src[t];

	return (dest);
}
