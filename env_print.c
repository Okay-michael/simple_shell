#include "main.h"

/**
 * env_print - Handle the 'env' command, printing environment variables.
 * Return: this function returns 0
 */
int env_print(void)
{
	int k = 0;

	while (environ[k] != NULL)
	{
		write(1, environ[k], cstrlen(environ[k]));
		write(1, "\n", 1);
		k++;
	}
	return (0);
}
