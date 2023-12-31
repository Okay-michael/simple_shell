#include "main.h"

/**
 * dispense - dispatches commands to appropriate handlers.
 * @args: An array of tokens from user input.
 * @usr_command: this is the command entered by the user
 *
 *Return: this function returns an integer.
 */
int dispense(char **args, char *usr_command)
{
	if (cstrcmp(args[0], "env") == 0 && args[1] == NULL)
	{
		env_print();
		return (0);
	}
	if (!cstrcmp(args[0], "setenv") && args[1] && args[2] && !args[3])
	{
		_setenv(args[1], args[2]);
		return (0);
	}
	if (cstrcmp(args[0], "cd") == 0)
	{
		ch_dir(args);
		return (0);
	}
	if (cstrcmp(args[0], "unsetenv") == 0 && args[1] && args[2] == NULL)
	{
		if (_unsetenv(args[1]) == 0)
		{
			return (0);
		}
	}
	if (cexecve(args, usr_command) == 0)
		return (0);
	return (1);
}
