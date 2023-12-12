#include "main.h"
/**
 * _getenv - gets the value of an environment variable.
 * @name: name of the environment variable.
 *
 * Return: the environment variable or NULL if not found or on error.
 */
char *_getenv(const char *name)
{
	size_t lnt;
	char **env = NULL;

	if (name == NULL)
		return (NULL);
	if (environ == NULL)
		return (NULL);
	lnt = cstrlen(name);

	for (env = environ; *env != NULL; env++)
		if (cstrncmp(*env, name, lnt) == 0 && (*env)[lnt] == '=')
			return (*env + lnt + 1);
	return (NULL);
}
