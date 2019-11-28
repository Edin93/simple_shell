#include "header.h"
/**
 * _get_cmds_number - returns the number of commands entered by the user.
 * @str: user input from buffer of getline.
 * Return: number of commands.
 */
int _get_cmds_number(char *str)
{
	int n, i;

	n = 0;
	if (str != NULL)
		n++;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
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
