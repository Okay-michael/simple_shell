#include "main.h"

/**
 * cstrcat - this program concatenates two strings together
 * @src: the original string to concatenate
 * @dest: the other string to be joined to the first
 * Return: the new string
 */
char *cstrcat(char *src, char *dest)
{
	char *result = malloc(sizeof(char) * (strlen(src) + strlen(dest) + 1));
	int i, j;

	for (i = 0, j = 0; ; i++, j++)
	{
		if (src[j] == '\0')
		{
			j = 0;
			result[i] = dest[j];
			i++;
			j++;
			for (; dest[j] != '\0'; i++, j++)
			{
				result[i] = dest[j];
			}
			result[i] = '\0';
			break;
		}
		result[i] = src[j];
	}
	return (result);
}
