#include "header.h"
/**
 * _get_cmds_number - returns the number of commands entered by the user.
 * @str: user input from buffer of getline.
 * Return: number of commands.
 */
int _get_cmds_number(char *str)
{
	int n = 0, i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			n++;
	}
	return (n);
}

/**
 * _free_cmds - function to frees commands
 * @cmds: pointer to pointer to commands token frm getline
 * Return: void
 */
void _free_cmds(char **cmds)
{
	int i = 0;

	while (cmds[i])
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

/**
 * _free_proc_conds - free cmds and getline buffer under certain conditions
 * @cmds: array of user commands.
 * @lineptr: getline's buffer.
 * Return: void.
 */
void _free_proc_conds(char **cmds, char *lineptr)
{
	if (cmds != NULL)
		_free_cmds(cmds);
	if (lineptr != NULL)
		free(lineptr);
}
