/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main function of the program
*/

#include "my.h"
#include "minishell.h"

int main(const int ac, const char * const *av,
        const char * const *env)
{
    if (ac == 2 && !my_strcmp(av[1], "-h", 0))
        usage();
    else
        setup_minishell(env);
    return (0);
}