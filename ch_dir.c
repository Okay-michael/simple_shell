#include "main.h"

void cwrite(int fd, const char *str) {
    write(fd, str, strlen(str));
}

void ch_dir(char **refined)
{
	if (refined[1] == NULL || cstrcmp(refined[1], "~") == 0)
	{
		char *home = getenv("HOME");

		if (home == NULL)
		{
			cwrite(2, "cd: HOME not set\n");
		}
		else
		{
			if (chdir(home) == -1)
				perror("cd");
			else
			{
				setenv("OLDPWD", getenv("PWD"), 1);
				cwrite(1, home);
				cwrite(1, "\n");
			}
		}
	}
	else if (cstrcmp(refined[1], "-") == 0)
	{
		char *old_pwd = getenv("OLDPWD");

		if (old_pwd == NULL)
		{
			cwrite(2, "cd: OLDPWD not set\n");
		}
		else
		{
			char *current_dir = getenv("PWD");
			if (chdir(old_pwd) == -1)
				perror("cd");
			else
			{
				cwrite(1, old_pwd);
				cwrite(1, "\n");
				setenv("OLDPWD", current_dir, 1);
			}
		}
	}
	else
	{
		char *current_dir = getenv("PWD");
		if (chdir(refined[1]) == -1)
			perror("cd");
		else
		{
			cwrite(1, refined[1]);
			cwrite(1, "\n");
			setenv("OLDPWD", current_dir, 1);
		}
	}
}
