/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** gets the size of an array
*/

int my_arrlen(char **array)
{
    int i = -1;

    if (array)
        while (array[++i]);
    return (i);
}