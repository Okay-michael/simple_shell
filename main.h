#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

int catoi(const char *strng);
int _setenv(char *name, char *value);
char *cstrcat(char *src, char *dest);
int cstrcmp(const char *string1, const char *string2);
char *cstrdup(char *strng);
char *cstrcpy(char *dest, const char *src);
size_t cstrlen(const char *string);
int cstrncmp(const char *strngA, const char *strngB, size_t lnt);
char *_strtok(char *string, const char *delim);
int _unsetenv(char *name);
char **tokenize_command(char *line);
int dispense(char **args);
int cexecve(char **);
void tidy_up(char **arr);
int cexit(char **refined/*, char **usr_input*/);
int env_print(void);
void ch_dir(char **refined);

/* Function prototypes*/
char *_getpath(char *input);

int _E_path(char **cmdlet);
int _Execute(char **cmdlet);
char **tokenizenew(char *str);


#endif /* MAIN_H */

