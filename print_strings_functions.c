#include "header.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _pstr - function that displays string to stdou.
 * @str: string to display.
 * Return: void.
 */
void _pstr(char *str)
{
	int i;

	if (str == NULL)
		return;

	i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
