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

	cmds = malloc(sizeof(char *) * _get_cmds_number(str));
	if (cmds == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	token = strtok(str, " \n");
	if (token == NULL || token[0] == '\0')
	{
		cmds[0] = NULL;
	}

	while (token != NULL)
	{
		*(cmds + i) = _strdup(token);
		i++;
		token = strtok(NULL, " \n");
	}
	*(cmds + i) = NULL;
	return (cmds);
}
