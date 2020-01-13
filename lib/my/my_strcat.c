/*
** EPITECH PROJECT, 2019
** library
** File description:
** my_strcat.c
*/

#include "my.h"
#include <stdlib.h>

static char *get_result(char *str, char const *to_append,
                        const unsigned int len_str,
                        const unsigned int len_append)
{
    char *result = NULL;
    unsigned int i = 0;
    unsigned int j = 0;

    result = malloc(sizeof(char) * len_str + len_append + 1);
    if (result == NULL)
        return (NULL);
    while (str[i]) {
        result[j] = str[i];
        i += 1;
        j += 1;
    }
    i = 0;
    while (to_append[i]) {
        result[j] = to_append[i];
        i += 1;
        j += 1;
    }
    result[j] = '\0';
    return (result);
}

char *my_strcat(char *str, char const *to_append)
{
    int len_str = my_strlen(str);
    int len_append = my_strlen(to_append);

    if (len_str <= 0 || len_append <= 0)
        return (len_str <= 0) ? my_strdup(to_append) : my_strdup(str);
    return (get_result(str, to_append,
                        (const unsigned)len_str,
                        (const unsigned)len_append));
}