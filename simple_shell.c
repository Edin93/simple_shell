#include "header.h"
/**
 * sig_handler - handler ctrl + c.
 * @i: integer.
 */
void sig_handler(int i)
{
	(void)i;
	_pstr("\n$ ");
}

/**
 * main - main simple shell function.
 * @ac: arguments count.
 * @av: arguments vector.
 * @envp: enviroments variables.
 * Return: int.
 */
int main(int ac, char **av, char **envp)
{
	char *lineptr = NULL, *token,  **cmds, *fp_res;
	size_t s = 0;
	int i, status, cmd_n = 0;
	pid_t c;
	ssize_t n_chars;

	signal(SIGINT, sig_handler);

	(void)envp;
	if (isatty(STDIN_FILENO))
		_pstr("$ ");
	while ((n_chars = getline(&lineptr, &s, stdin)) != -1)
	{
		cmds = NULL;
		cmds = malloc(sizeof(char *) * _get_cmds_number(lineptr));
		token = strtok(lineptr, " \n");
		i = 0;

		if (token == NULL || token[0] == '\0')
		{
			cmds[0] = NULL;
		}
		else
		{
			cmd_n++;
			while (token != NULL)
			{
				*(cmds + i) = _strdup(token);
				i++;
				token = strtok(NULL, " \n");
			}
			*(cmds + i) = NULL;
			i = 0;
			if (_strcmp(cmds[0], "exit") == 0)
			{
				_free_cmds(cmds);
				free(lineptr);
				exit(0);
			}
			fp_res = _find_path(*cmds);
			if (fp_res != NULL)
				cmds[0]  = _strdup(fp_res);
			c = fork();
			if (c == -1)
			{
				perror(av[0]);
			}
			if (c == 0)
			{
				if (execve(cmds[0], cmds, NULL) == -1)
				{
					perror(av[0]);
					exit(EXIT_FAILURE);
				}
			}
			if (wait(&status) == -1)
			{
				perror(av[0]);
			}
		}
		if (isatty(STDIN_FILENO))
			_pstr("$ ");
	}
	if (n_chars == -1)
	{
		if (isatty(STDIN_FILENO))
			_putchar('\n');
		exit(0);
	}
	if (cmds != NULL)
		_free_cmds(cmds);
	if (lineptr != NULL)
		free(lineptr);
	return (0);
}
