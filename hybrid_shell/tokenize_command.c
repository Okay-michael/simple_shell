#include "main.h"

/**
 * wrd_cntr - Counts the number of words in a given line.
 * @string: The input line to count words from.
 *
 * Return: number of words found in the line.
 */
int wrd_cntr(char *string)
{
    char *token;
    int wrdcnt = 0;

    token = _strtok(string, " \n\r\t\'\"");
    while (token != NULL && *token != '#')
    {
        wrdcnt++;
        token = _strtok(NULL, " \n\r\t\'\"");
    }

    return (wrdcnt);
}

/**
 * tok_enizer - tokenize the input line and count the words.
 * @string: line to tokenize and count words.
 * @arr: array of string pointers to store the tokenized words.
 *
 * Return: number of words found in the line.
 */
int tok_enizer(char *string, char **arr)
{
    char *token;
    int k = 0;

    token = _strtok(string, " \n\r\t\'\"");
    while (token != NULL && *token != '#')
    {
        arr[k] = cstrdup(token);
        k++;
        token = _strtok(NULL, " \n\r\t\'\"");
    }

    arr[k] = NULL;

    return (k);
}

/**
 * tokenize_command - Splits a line into words and returns an array of strings.
 * @string: The input line to be refined.
 *
 * Return: An array of strings containing the words, or NULL if memory
 * allocation fails or no words are found.
 */
char **tokenize_command(char *string)
{
    int wrdcnt, tokenCount;
    char *dup_count, *dup_token;
    char **arr;

    dup_count = cstrdup(string);
    if (dup_count == NULL)
    {
        perror("Memory allocation failed");
        return (NULL);
    }
    wrdcnt = wrd_cntr(dup_count);
    free(dup_count);
    dup_token = cstrdup(string);
    if (dup_token == NULL)
    {
        perror("Memory allocation failed");
        return (NULL);
    }
    arr = (char **)malloc(sizeof(char *) * (wrdcnt + 1));
    if (arr == NULL)
    {
        perror("Memory allocation failed");
        free(dup_token);
        return (NULL);
    }
    tokenCount = tok_enizer(dup_token, arr);
    if (tokenCount == 0)
    {
        free(dup_token);
        free(arr);
        return (NULL);
    }
    free(dup_token);
    return (arr);
}
