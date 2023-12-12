#include "main.h"

/**
 * catoi - this program converts a string to an integer.
 * @string: is the string to be converted to an integer.
 * Return: The integer value of the string, or 0 if the string can't
 * be converted to an integer.
 */
int catoi(const char *string)
{
	int integer = 0;
	int sign = 1;

	while (*string == ' ')
	{
		string++;
	}
	if (*string == '-' || *string == '+')
	{
		sign = *string == '-' ? -1 : 1;
		string++;
	}
	while (*string != '\0')
	{
		if (*string < '0' || *string > '9')
		{
			return (0);
		}

		integer = integer * 10 + (*string - '0');
		string++;
	}
	return (integer * sign);
}
