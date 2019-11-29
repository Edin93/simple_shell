#include "header.h"

/**
 * exit_func - exit function
 * @cmds: commands array.
 * Return: void.
 */
void exit_func(char **cmds)
{
	int i;

	if (!cmds[1])
		exit(0);
	else
	{
		i = _atoi(cmds[1]);
		if (i < 0)
			i = 2;
		exit(i);
	}
}
