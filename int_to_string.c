#include "shell.h"

/**
 * numlength - counts the num of zeros in a tens power num
 * @n: num
 * Return: returns the count of digits
 */
int numlen(int n)
{
	int count = 0;
	int number = n;

	while (number > 9 || number < -9)
	{
		number /= 10;
		count++;
	}
	return (count);
}
/**
 * int_to_string - turns an integer into a string
 * @number: integer
 * Return: returns the integer as a str. returns NULL if fail
 */

char *int_to_string(int number)
{
	int digits, tens, b = 0, t = 0, x;
	char *res;

	digits = number;
	tens = 1;

	if (number < 0)
		t = 1;
	res = malloc(sizeof(char) * (numlen(digits) + 2 + t));
	if (res == NULL)
		return (NULL);
	if (number < 0)
	{
		res[b] = '-';
		b++;
	}
	for (x = 0; digits > 9 || digits < -9; x++)
	{
		digits /= 10;
		tens *= 10;
	}
	for (digits = number; x >= 0; x--)
	{
		if (digits < 0)
		{
			res[i] = (digits / tens) * -1 + '0';
			b++;
		}
		else
		{
			res[b] = (digits / tens) + '0';
			b++;
		}
		digits %= tens;
		tens /= 10;
	}
	res[i] = '\0';
	return (res);
}
