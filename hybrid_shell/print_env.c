#include "main.h"

/**
 * print_env - Handle the 'env' command by cleaning up
 * and printing environment variables.
 * Return: this function returns 0
 */
int print_env(void)
{
	int k = 0;

	while (environ[k] != NULL)
	{
		write(1, environ[k], strlen(environ[k]));
		write(1, "\n", 1);
		k++;
	}
	return (0);
}
