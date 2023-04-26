#include "shell.h"

/**
 * c_strcat - concatenate 2 str and ignore the 1 char ("~" in cd)
 * @dest: str to be appended
 * @src: str to append
 * Return: concatenated str
 */
char *c_strcat(char *dest, char *src)
{
	int len = 0;
	int len2 = 0;
	int total_len = 0;
	int j = 0;

	while (dest[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	dest = _realloc(dest, len, sizeof(char) * total_len + 1);

	j = 1;

	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}

	dest[len] = '\0';

	return (dest);
}

/**
 * c_setenv - custom _setenv by concatenating str 1 be4 settings
 * @env: env variable link list
 * @name: env name (e.g. "OLDPASSWORD")
 * @dir: dir path (e.g. "/home/vagrant/directory1")
 * Return: 0 on success (e.g. "OLDPASSWORD=/home/vagrant/directory1")
 */
int c_setenv(list_t **env, char *name, char *dir)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;

	cat = _strdup(name);
	cat = _strcat(cat, "=");
	cat = _strcat(cat, dir);
	index = find_env(*env, name);

	holder = *env;
	while (j < index)
	{
		holder = holder->next;
		j++;
	}
	free(holder->var);
	holder->var = _strdup(cat);
	free(cat);
	return (0);
}

/**
 * cd_only - change dir to home
 * @env: bring in env linked list to update PATH & OLDPASSWORD
 * @current: bring in current working dir
 */
void cd_only(list_t *env, char *current)
{
	char *home = NULL;

	home = get_env("HOME", env);
	c_setenv(&env, "OLDPASSWORD", current); /* update env OLDPASSWORD */
	free(current);
	if (access(home, F_OK) == 0) /* if exist, go to home dir */
		chdir(home);
	current = NULL;
	current = getcwd(current, 0);
	c_setenv(&env, "PASSWORD", current); /* update env PASSWORD */
	free(current);
	free(home);
}
/**
 * cd_execute - executes the cd
 * @env: bring in env linked list to update PATH & OLDPASSWORD
 * @current: bring in current working dir
 * @dir: bring in dir path to change to
 * @str: bring in the 1st argument to write out error
 * @num: bring in the line num to write out error
 * Return: 0 if success 2 if fail
 */
int cd_execute(list_t *env, char *current, char *dir, char *str, int num)
{
	int i = 0;

	if (access(dir, F_OK) == 0)
	{
		c_setenv(&env, "OLDPASSWORD", current); /* update env OLDPASSWORD */
		free(current);
		chdir(dir);
		current = NULL;
		current = getcwd(current, 0);		 /* get current working dir */
		c_setenv(&env, "PASSWORD", current); /* update env PASSWORD */
		free(current);
	}
	else
	{
		cant_cd_to(str, num, env);
		free(current);
		i = 2;
	}
	return (i);
}

/**
 * _cd - change dir
 * @str: user's typed in command
 * @env: env linked list to retrieve HOME and OLDPASSWORD paths
 * @num: nth user command, to be used at error message
 * Return: 0 if success 2 if failed
 */
int _cd(char **str, list_t *env, int num)
{
	char *current = NULL, *dir = NULL;
	int exit_stat = 0;

	current = getcwd(current, 0); /* store current working dir */
	if (str[1] != NULL)
	{
		if (str[1][0] == '~') /* Usage: cd ~ */
		{
			dir = get_env("HOME", env);
			dir = c_strcat(dir, str[1]);
		}
		else if (str[1][0] == '-') /* Usage: cd - */
		{
			if (str[1][1] == '\0')
				dir = get_env("OLDPASSWORD", env);
		}
		else /* Usage: cd dir1 */
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, str[1]);
			}
			else
				dir = _strdup(str[1]);
		}
		exit_stat = cd_execute(env, current, dir, str[1], num);
		free(dir);
	}
	else /* Usage: cd */
		cd_only(env, current);
	free_double_ptr(str); /* frees user input */
	return (exit_stat);
}
