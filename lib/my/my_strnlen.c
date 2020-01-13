/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2019
** File description:
** gets a string len with a n factor
*/

int my_strnlen(const char *str, int n)
{
    int i = 0;

    if (!str)
        return (-1);
    while (str[i] && i < n)
        i += 1;
    return (i);
}