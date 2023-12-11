#include "main.h"

/**
 * cstrcpy - uses recursion to copy a string to
 * another string
 * @src: the pointer to the source string
 * @dest: a pointer to the destination string
 *
 * Return: returns a pointer to the destination string.
 */
char *cstrcpy(char *dest, const char *src)
{
	if (dest == NULL)
		return (NULL);

	if (src == NULL)
	{
		*dest = '\0';
		return (dest);
	}

	*dest = *src;
	if (*src == '\0')
		return (dest);
	return (cstrcpy(dest + 1, src + 1));
}
