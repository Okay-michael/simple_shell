#include "main.h"
/**
 * ch_dir - this function is used to change the current directory
 * (cd command).
 * @refined: this is an array of tokens from user input.
 *
 * This function handles the 'cd' command, which changes the current
 * directory, it supports the following cases:
 * - If no directory argument is provided or the argument is '~', it
 * changes to the user's home directory.
 * - If the argument is '-', it changes to the previous working directory.
 * - If any other valid directory argument is provided, it changes to that
 * directory.
 *
 * @refined: An array of tokens from user input.
 */
void ch_dir(char **refined)
{
	if (refined[1] == NULL || cstrcmp(refined[1], "~") == 0)
	{
		char *home = getenv("HOME");

		if (home == NULL)
		{
			perror("cd: HOME not set");
		}
		else
		{
			if (chdir(home) == -1)
				perror("cd");
		}
	}
	else if (cstrcmp(refined[1], "-") == 0)
	{
		char *old_pwd = getenv("OLDPWD");

		if (old_pwd == NULL)
		{
			perror("cd: OLDPWD not set");
		}
		else
		{
			if (chdir(old_pwd) == -1)
				perror("cd");
		}
	}
	else
	{
		if (chdir(refined[1]) == -1)
			perror("cd");
	}
}
