#include "main.h"

/**
 * tidy_up - this function frees the memory allocated for a null-terminated
 * array of stringgs in the function.
 * @arr: this is the array of strings to be freed.
 */
void tidy_up(char **arr)
{
	int i = 0;

	if (arr)
	{
		for (i = 0; arr[i] != NULL; i++)
		{
			if (arr[i])
				free(arr[i]);
		}
		free(arr);
	}
}
