#include "main.h"

/**
 * main - The shell is launched from within the main.
 *
 * Return: Always 0.
 */
int main(void)
{
	char **arg = NULL;
	char *usr_command = NULL;
	int bytesread = 0;
	size_t buffer = 0;

	while (10)
	{
		int interact = isatty(STDIN_FILENO);

		if (interact != 0)
			write(STDIN_FILENO, "$ ", 2);
		bytesread = getline(&usr_command, &buffer, stdin);

		if (bytesread == -1)
			break;
		arg = tokenize_command(usr_command);
		if (arg == NULL)
			continue;
		if (cstrcmp(arg[0], "exit") == 0)
		{
			free(usr_command);
			cexit(arg);
		}
		if (dispense(arg, usr_command) == 0)
		{
			tidy_up(arg);
			continue;
		}
	}
	if (usr_command != NULL)
		free(usr_command);
	return (0);
}
