/*
** EPITECH PROJECT, 2019
** library
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *template)
{
    int len_template = my_strlen(template);
    char *dup = NULL;
    int i = 0;

    if (len_template == -1)
        return (NULL);
    dup = malloc(sizeof(char) * len_template + 1);
    if (dup == NULL)
        return (NULL);
    while (template[i]) {
        dup[i] = template[i];
        i += 1;
    }
    dup[i] = '\0';
    return (dup);
}