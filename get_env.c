#include "shell.h"

/**
 * c_strdup - custom str duplication; which eliminate the b beginning bytes
 * @str: str to duplicate (e.g. env var PATH=/bin:/bin/ls)
 * @cs: num of bytes to exclude (e.g. excludes "PATH=")
 * Return: str (e.g. /bin:/bin/ls)
 */
char *c_strdup(char *str, int cs)
{
	char *duplicate_str;
	int m, length = 0;

	if (str == NULL)
		return (NULL);

	/* calc length + null terminator to malloc */
	while (*(str + length))
		length++;
	length++;

	/* allocate memory but exclude environmental variable title (PATH) */
	duplicate_str = malloc(sizeof(char) * (length - cs));
	if (duplicate_str == NULL)
		return (NULL);

	m = 0;
	while (m < (length - cs))
	{
		*(duplicate_str + m) = *(str + cs + m);
		m++;
	}
	return (duplicate_str);
}

/**
 * get_env - finds & returns a copy of the requested env var
 * @str: str to store it in
 * @env: entire set of env variables
 * Return: copy of requested environmental var
 */
char *get_env(char *str, list_t *env)
{
	int y = 0, cs = 0;

	while (env != NULL)
	{
		y = 0;
		while ((env->var)[y] == str[y]) /* find desired env variable */
			y++;
		if (str[y] == '\0' && (env->var)[y] == '=')
			break;
		env = env->next;
	}

	while (str[cs] != '\0') /* find how many bytes in env variable title */
		cs++;
	cs++; /*counts 1 more for = sign*/
	return (c_strdup(env->var, cs)); /* make a copy of variable w/o title */
}
