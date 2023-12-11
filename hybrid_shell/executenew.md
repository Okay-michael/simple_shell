#include "main.h"
int Execve(char **cnd);
/**
 * Execve - exec ve
 * @args: command
 * Return: int
 */
int Execve(char **args)
{
	int pid, exit_status, status;

	pid  = fork();
	if (pid == 0)
	{
		if (_strcmp(args[0], "echo") == 0)
			execve("/bin/echo", args, environ);
		else if (_strcmp(args[0], "ls") == 0)
			execve("/bin/ls", args, environ);
		else
			execve(args[0], args, environ);
		write(2, "./hsh", _strlen("./hsh"));
		write(2, ": ", _strlen(": "));
		write(2, "1", 1);
		write(2, ": ", 2);
		write(2, args[0], _strlen(args[0]));
		write(2, ": not found\n", 12);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status  != 0 && !isatty(STDIN_FILENO))
			{
				exit(exit_status);
			}
		}
	}
	return (0);
}
