#include "main.h"

/**
 * cstrcmp - compares two strings for equality
 * @string1: the pointer to the first string
 * @string2: the pointer to the second string.
 *
 * Return: returns an integer value indicating the
 * relationship between the two strings:
 *     * a (-ve) value if str1 is less than str2.
 *     * a (+ve) value if str1 is greater than str2.
 *     * and (0) if str1 is equal to str2.
 */
int cstrcmp(const char *string1, const char *string2)
{
	if (string1 == NULL || string2 == NULL)
		return (-1);

	if (*string1 == *string2 && *string1 != '\0' && *string2 != '\0')
		return (cstrcmp(string1 + 1, string2 + 1));

	return (*string1 - *string2);
}
