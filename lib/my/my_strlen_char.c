/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2019
** File description:
** gets a string len with a n factor
*/

int my_strlen_char(const char *str, const char c)
{
    int i = 0;

    if (!str)
        return (-1);
    while (str[i] && str[i] != c)
        i += 1;
    return (i);
}