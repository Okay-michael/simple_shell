#include "main.h"

/**
 * cstrlen - calculate the length of the string passed in
 * @string: a pointer to the string to be calculated
 *
 * Return: integer value of the length calculated.
 */
size_t cstrlen(const char *string)
{
	if (*string == '\0')
		return (0);
	return (1 + cstrlen(string + 1));
}
