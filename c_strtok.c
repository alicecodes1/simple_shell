#include "shell.h"

/**
 * c_t_size - returns num of delimeter
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: num of tokens
 */
int c_t_size(char *str, char delm)
{
	int j = 0, num_delm = 0;

	while (str[j] != '\0')
	{
		if (str[j] == delm)
		{
			num_delm++;
		}
		j++;
	}
	return (num_delm);
}


/**
 * c_str_tok - tokenizes a str even the continuous delimeter with empty string
 * (e.g. path --> ":/bin::/bin/usr" )
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: an array of tokens (e.g. {"\0", "/bin", "\0", "/bin/usr"}
 * (The purpose is to have which command look through current directory if ":")
 */
char **c_str_tok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, j = 0, length = 0, se = 0;
	char **toks = NULL, d_ch;

	/* set var to be delimeter character (" ") */
	d_ch = delm[0];
	/* malloc num of pointers to store array of tokens, and NULL ptr */
	buffsize = c_t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);

	/* repeat from string index 0 to string ending index */
	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		/* malloc length for each token ptr in array */
		length = t_strlen(str, si, d_ch);
		toks[p] = malloc(sizeof(char) * (length + 1));
		if (toks[p] == NULL)
			return (NULL);
		j = 0;
		while ((str[si] != d_ch) &&
		       (str[si] != '\0'))
		{
			toks[p][j] = str[si];
			j++;
			si++;
		}
		toks[p][j] = '\0'; 
		p++;
		si++;
	}
	toks[p] = NULL; 
	return (toks);
}

