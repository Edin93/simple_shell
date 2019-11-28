#include "header.h"
/**
 * _find_path - finds a command's path in the path env variable.
 * @str: user input.
 * Return: full cmd path.
 */
char *_find_path(char *str)
{
	char *path, *env, *token, *tmp;
	struct stat statbuf;

	path = _getenv("PATH");
	env = _strdup(path);
	token = strtok(env, ":");

	while (token != NULL)
	{
		tmp = _strconcat(_strconcat(token, "/"), str);
		if (stat(tmp, &statbuf) == 0)
			return (tmp);
		token = strtok(NULL, ":");
	}
	return (0);
}
