#include "main.h"

/**
 * _unsetenv - Remove an environment variable from the environment.
 * @name: The name of the environment variable to remove.
 *
 * This function searches for an environment variable with the given name
 * in the current environment. If the variable is found, it is removed.
 *
 * Return: returns 0 on success, 1 otherwise.
 */
int _unsetenv(char *name)
{
	int k = 0;

	do {
		char *env_var = cstrdup(environ[k]);
		char *tmp = _strtok(env_var, "=");

		if (cstrcmp(name, tmp) == 0)
		{
			free(env_var);

			while (environ[k] != NULL)
			{
				environ[k] = environ[k + 1];
				k++;
			}

			return (0);
		}
		free(env_var);
		k++;
	} while (environ[k] != NULL);
	return (1);
}
