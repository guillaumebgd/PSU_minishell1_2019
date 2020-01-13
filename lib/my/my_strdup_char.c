/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2019
** File description:
** duplicates a string upto a n number of itterations
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup_char(const char *template, const char c)
{
    char *result = NULL;
    int size = my_strlen_char(template, c);
    int i = 0;

    result = malloc(sizeof(char) * (size + 1));
    if (!result)
        return (NULL);
    result[size] = '\0';
    while (template[i] != '\0' && template[i] != c) {
        result[i] = template[i];
        i += 1;
    }
    return (result);
}