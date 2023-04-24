#include "shell.h"

/**
 * t_strlen - returns token str len for malloc
 * @str: a token
 * @pos: index position in user's command which is typed into the shell
 * @delm: delimeter (e.g. " ");
 * Return: token len
 */
int t_strlen(char *str, int pos, char delm)
{
	int length = 0;

	while ((str[pos] != delm) && (str[pos] != '\0'))
	{
		pos++;
		length++;
	}
	return (length);
}

/**
 * t_size - returns num of delimeter ignoring cont delim
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: num of delims so that (number token = delims + 1)
 */
int t_size(char *str, char delm)
{
	int d = 0, num_delm = 0;

	while (str[d] != '\0')
	{
		if ((str[d] == delm) && (str[d + 1] != delm))
		{
			/* handle cont delims */
			num_delm++;
		}
		if ((str[d] == delm) && (str[d + 1] == '\0'))
		{
			num_delm--;
		}
		d++;
	}
	return (num_delm);
}

/**
 * ignore_delm - returns a version of str without preceeding delims
 * @str: string
 * @delm: delimiter (e.g. " ")
 * Return: new string (e.g. "    ls -l" --> "ls -l")
 */
char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}

/**
 * _str_tok - tokenizes a string and returns an array of tokens
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: an array of tokens (e.g. {"ls", "-l", "/tmp"}
 */
char **_str_tok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, d = 0, length = 0, se = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];
	/* creates new version of string ignoring all delims infront*/
	str = ignore_delm(str, d_ch);
	/* malloc ptrs to store array of tokens (buffsize + 1), and NULL ptr */
	buffsize = t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);
	while (str[se] != '\0')	/* find string ending index */
		se++;
	while (si < se)
	{ /* malloc lengths for each token ptr in array */
		if (str[si] != d_ch)
		{
			length = t_strlen(str, si, d_ch);
			toks[p] = malloc(sizeof(char) * (length + 1));
			if (toks[p] == NULL)
				return (NULL);
			d = 0;
			while ((str[si] != d_ch) && (str[si] != '\0'))
			{
				toks[p][i] = str[si];
				d++;
				si++;
			}
			toks[p][i] = '\0'; /* null terminate at end*/
			t++;
		}
		/* handle repeated delimeters; increment ptr after ("ls __-l")*/
		if (si < se && (str[si + 1] != d_ch && str[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	toks[p] = NULL; 
	return (toks);
}
