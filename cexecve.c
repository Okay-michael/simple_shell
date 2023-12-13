#include "main.h"
int cexeve(char **cnd, char *usr_command);
/**
 * cexecve - This is where the execve is called on the args
 * @args: tokenized array of the user command
 * @usr_command: this is the command entered by the user
 * Return: int
 */
int cexecve(char **args, char *usr_command)
{
	int pid, exit_status, status;

	pid  = fork();
	if (pid == 0)
	{
		if (cstrcmp(args[0], "ls") == 0)
			execve("/bin/ls", args, environ);
		else if (cstrcmp(args[0], "echo") == 0)
			execve("/bin/echo", args, environ);
		else
			execve(args[0], args, environ);
		write(2, "./hsh", cstrlen("./hsh"));
		write(2, ": ", cstrlen(": "));
		write(2, "1", 1);
		write(2, ": ", 2);
		write(2, args[0], cstrlen(args[0]));
		write(2, ": not found\n", 12);
		tidy_up(args);
		free(usr_command);
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
				free(usr_command);
				tidy_up(args);
				exit(exit_status);
			}
		}
	}
	return (0);
}
