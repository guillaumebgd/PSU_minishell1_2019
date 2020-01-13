/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** put chars from a string
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int size = my_strlen(str);

    if (size == -1)
        return (84);
    if (write(1, str, size) < 0)
        return (84);
    return (0);
}