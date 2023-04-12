#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenate all arguments into a single string
 *
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: pointer to concatenated string
 */
char *argstostr(int ac, char **av)
{
    int i, j, len = 0, k = 0;
    char *str;

    if (ac == 0 || av == NULL)
        return (NULL);

    /* Calculate total length of concatenated string */
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
            len++;
        len++;
    }

    /* Allocate memory for concatenated string */
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);

    /* Copy each argument into concatenated string */
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
        {
            str[k] = av[i][j];
            k++;
        }
        str[k] = '\n';
        k++;
    }

    /* Add null terminator */
    str[k] = '\0';

    return (str);
}
