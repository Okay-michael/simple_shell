#include "main.h"

/**
 * _setenv - Set/modify an environment variable.
 * @name: the name of the environment variable.
 * @value: the value to assign to the environment variable.
 *
 * Return: On success 0, otherwise 1.
 */
int _setenv(char *name, char *value)
{
	int i = 0;

	do {
		char *env_var = cstrdup(environ[i]);
		char *temporary = _strtok(env_var, "=");

		if (cstrcmp(name, temporary) == 0)
		{
			name = cstrcat(name, "=");
			value = cstrcat(name, value);
			environ[i] = value;
			free(name);
			free(env_var);
			return (1);
		}
		free(env_var);
		i++;
	} while (environ[i] != NULL);

	name = cstrcat(name, "=");
	value = cstrcat(name, value);
	environ[i] = value;
	environ[i + 1] = NULL;
	free(name);

	return (0);
}
