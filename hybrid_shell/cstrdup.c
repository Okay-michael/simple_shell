#include "main.h"

/**
 * cstrdup - duplicates a string
 * @string: the string to be duplicated
 * Return: a pointer to the newly duplicated string
 */
char *cstrdup(char *string)
{
	char *string1;
	int i, size = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		size++;
	}
	size++;

	string1 = malloc(sizeof(char) * size);

	for (i = 0; string[i] != '\0'; i++)
	{
		string1[i] = string[i];
	}
	string1[i] = '\0';
	return (string1);
}
