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

/* Function prototypes*/
int print_env(void);
char *_getpath(char *input);

int _E_path(char **cmdlet);
int _Execute(char **cmdlet);
int _E_xit(char **refined/*, char **usr_input*/);
char **tokenizenew(char *str);

void _Explore(char **refined);

#endif /* MAIN_H */

