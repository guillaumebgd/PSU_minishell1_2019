/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2019
** File description:
** duplicates a string upto a n number of itterations
*/

#include "my.h"
#include <stdlib.h>

char *my_strndup(const char *template, int n)
{
    char *result = NULL;
    int size = my_strnlen(template, n);
    int i = 0;

    result = malloc(sizeof(char) * (size + 1));
    if (!result)
        return (NULL);
    result[size] = '\0';
    while (template[i] != '\0' && i < n) {
        result[i] = template[i];
        i += 1;
    }
    return (result);
}