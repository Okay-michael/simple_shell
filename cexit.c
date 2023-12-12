#include "main.h"

/**
 * check_if_letter - =======
 * @str: =====
 * Return: (1)
 */
int check_if_letter(char *str)
{
	int i = 0;

	for (i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	return (1);
}



/**
 * cexit - Handle the exit command with an optional status.
 * @refined: An array of tokens from user input.
 * Return: (0)
 */
int cexit(char **refined)
{
	if (refined[1] != NULL)
	{
		int exit_status;
		int check;

		check = check_if_letter(refined[1]);
		if (check == -1)
		{
			write(2, "./hsh: 1: exit: Illegal number: ",
					cstrlen("./hsh: 1: exit: Illegal number: "));
			write(2, refined[1], cstrlen(refined[1]));
			write(2, "\n", 1);
			exit(2);
		}
		exit_status = catoi(refined[1]);
		tidy_up(refined);
		exit(exit_status);
	}
	else
	{
		tidy_up(refined);
		exit(0);
	}
	return (0);
}
