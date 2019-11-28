#include "header.h"

/**
 * exec_usr_input - execute user input in shell.
 * @av0: first element of av.
 * @cmds: typed commands.
 * @status: number to change it's value with sys call wait.
 * Return: void.
 */
void exec_usr_input(char *av0, char **cmds, int status)
{
	pid_t c;

	c = fork();
	if (c == -1)
	{
		perror(av0);
	}
	if (c == 0)
	{
		if (execve(cmds[0], cmds, NULL) == -1)
		{
			perror(av0);
			exit(EXIT_FAILURE);
		}
	}
	if (wait(&status) == -1)
	{
		perror(av0);
	}
}
