#include "main.h"
/**
 * cstrncmp - compares at most the first n bytes of two strings.
 * @stringA: The first string to be compared.
 * @stringB: The second string to be compared.
 * @lnt: The maximum number of bytes to compare.
 *
 * Return: 0 if the strings are equal, an integer less than 0 if stringA
 * is less than stringB, and an integer greater than 0 if stringA
 * is greater than stringB.
 */
int cstrncmp(const char *stringA, const char *stringB, size_t lnt)
{
	size_t k = 0;

	for (k = 0; k < lnt; k++)
	{
		if (stringA[k] != stringB[k])
			return ((int)(stringA[k]) - (int)(stringB[k]));

		if (stringA[k] == '\0')
			return (0);
	}
	return (0);
}
