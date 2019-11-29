#include "header.h"

/**
 * create_cmds - create array of typed commands.
 * @str: buffer from getline function.
 * Return: array of commands.
 */
char **create_cmds(char *str)
{
	int i = 0;
	char **cmds, *token;

	token = strtok(str, " \n");
	if (token == NULL || token[0] == '\0')
	{
		return (NULL);
	}
	cmds = malloc(sizeof(char *) * 2);
	*(cmds + i) = _strdup(token);
	i++;
	while (token != NULL)
	{
		cmds = _realloc(
			cmds,
			sizeof(char *) * (i + 1),
			sizeof(char *) * (i + 2)
			);
		token = strtok(NULL, " \n");
		*(cmds + i) = _strdup(token);
		i++;
	}
	*(cmds + i) = NULL;
	return (cmds);
}
