#include "header.h"

/**
 * _getenv - get an environment variable of the given name.
 * @name: name of env variable you're looking for.
 * Return: the env variable you're searching.
 */
char *_getenv(const char *name)
{
	char *envar, *tmp;
	int i;

	i = 0;
	envar = NULL;

	while (environ[i] != NULL)
	{
		tmp = _strdup(environ[i]);
		envar = strtok(tmp, "=");
		if (_strcmp(envar, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (envar);
}

/**
 * _setenv - initialize a new env var or change an existing one.
 * @name: name of the desired env variable.
 * @value: value of the env var you're looking for.
 * @overwrite: if 1, it overwrites the existing env var with the given name.
 * Return: 1 on success, 0 otherwise.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_var;
	int ei;

	ei = 0;
	env_var = *(environ + ei);

	while (env_var != NULL)
	{
		if (_strcmp(name, env_var) == 0)
		{
			if (overwrite != 0)
				*(environ + ei) = _const_strconcat(
					_const_strconcat(name, "="), value
					);
			return (0);
		}
		else
		{
			ei++;
			env_var = *(environ + ei);
		}
	}
	if (env_var == NULL)
	{
		*(environ + ei) = _const_strconcat(
			_const_strconcat(name, "="), value
			);
		ei++;
		*(environ + ei) = NULL;
		return (0);
	}
	return (1);
}

/**
 * _unsetenv - removes an environment variable.
 * @name: name of env var you're looking for.
 * Return: 1 on success.
 */
int _unsetenv(const char *name)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (_strcmp(name, environ[i]) == 0)
		{
			while (environ[i + 1])
			{
				environ[i] = environ[i + 1];
				i++;
			}
			environ[i] = NULL;
			break;
		}
		else
			i++;
	}
	return (1);
}
