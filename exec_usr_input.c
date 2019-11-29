#include "header.h"

/**
 * exec_usr_input - execute user input in shell.
 * @av0: first element of av.
 * @cmds: typed commands.
 * @status: number to change it's value with sys call wait.
 * @lineptr: getline's buffer;
 * Return: void.
 */
void exec_usr_input(char *av0, char **cmds, int status, char *lineptr)
{
	pid_t c;

	c = fork();
	if (c == -1)
	{
		perror(av0);
	}
	if (c == 0)
	{
		if (execve(cmds[0], cmds, environ) == -1)
		{
			perror(av0);
			exit(EXIT_FAILURE);
		}
	}
	if (wait(&status) == -1)
	{
		_free_proc_conds(cmds, lineptr);
		perror(av0);
	}
}
