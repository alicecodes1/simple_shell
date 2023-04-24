#include "shell.h"

/**
 * _strcmp - comparing two str
 * @s1: str 1
 * @s2: str 2
 * Return: int that tells numb spaces in between, 0 if it is exactly  same str.
 */

int _strcmp(char *s1, char *s2)
{
	int r = 0;

	while (*(s1 + r) == *(s2 + r) && *(s1 + r))
		r++;

	if (*(s2 + r))
		return (*(s1 + r) - *(s2 + r));
	else
		return (0);
}
