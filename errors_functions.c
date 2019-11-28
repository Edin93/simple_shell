#include "header.h"

/**
 * _disp_cnf_err - it displays error for command not found.
 * @pn: program name that from which generated the error.
 * @err_src: error source to print.
 * @num: typed commands number.
 * Return: nothing.
 */
void _disp_cnf_err(char *pn, char *err_src, int num)
{
	printf("%s: %d: %s: not found\n", pn, num, err_src);
}

/**
 * _disp_err - it displays normal errors.
 * @cmd: command.
 * Return: nothing.
 */
void _disp_err(char *cmd)
{
	perror(cmd);
}
