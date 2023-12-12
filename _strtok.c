#include "main.h"

/**
 * cstrchr - searches the first occurrence of a character in a string.
 * @string: The string to search within.
 * @xter: The character to search for.
 *
 * Return: If the character is found, a pointer to its location in the string.
 * If the character is not found, NULL is returned.
 */
static char *cstrchr(const char *string, char xter)
{
	if (string == NULL)
		return (NULL);

	while (*string != '\0' && *string != xter)
		string++;

	if (*string == xter || (*string == '\0' && xter == '\0'))
		return ((char *)string);

	return (NULL);
}

/**
 * _strtok - A custom version of strtok to tokenize a string.
 * @string: The string to be tokenized.
 * @delim: The delimiter characters for tokenization.
 *
 * Return: A pointer to the next token found in the string,
 * or NULL if no more tokens are found.
 */
char *_strtok(char *string, const char *delim)
{
	static char *next_token;
	char *token = NULL;

	if (string == NULL)
		string = next_token;
	if (string == NULL)
		return (NULL);
	while (*string != '\0' && cstrchr(delim, *string) != NULL)
		string++;
	if (*string == '\0')
	{
		next_token = NULL;
		return (NULL);
	}
	token = string;
	while (*string != '\0' && cstrchr(delim, *string) == NULL)
		string++;
	if (*string != '\0')
	{
		*string = '\0';
		next_token = string + 1;
	}
	else
	{
		next_token = NULL;
	}
	return (token);
}
