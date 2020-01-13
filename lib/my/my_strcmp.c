/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** compares two strings
*/

#include "my.h"

static unsigned int check_null(char const *to_find, char const *template)
{
    if (!to_find || !template) {
        if (!to_find && !template)
            return (0);
        if ((!to_find && template) || (to_find && !template))
            return (1);
    }
    return (2);
}

int my_strcmp(char const *to_find, char const *template)
{
    unsigned int match = 0;
    unsigned int i = 0;
    unsigned int checker = 0;

    checker = check_null(to_find, template);
    if (checker == 1 || checker == 0)
        return (checker == 1) ? 1 : 0;
    while (to_find[i] != '\0' && template[i] != '\0') {
        if (to_find[i] != template[i])
            return (1);
        if (to_find[i] == template[i])
            match += 1;
        i += 1;
    }
    if (match == i)
        return (0);
    return (1);
}