/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** compares two strings for n chars
*/

#include "my.h"

int my_strncmp(const char *first, const char *second, const unsigned int n)
{
    int len_first = my_strlen(first);
    int len_second = my_strlen(second);
    int index = 0;

    if (len_first == -1 || len_second == -1)
        return (len_first - len_second);
    if (len_first != len_second)
        return (len_first - len_second);
    while (first[index] && second[index] && index < (int)n) {
        if (first[index] != second[index])
            break;
        index += 1;
    }
    return (first[index] - second[index]);
}
