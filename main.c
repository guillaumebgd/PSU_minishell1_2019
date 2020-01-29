/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main function of the program
*/

#include "minishell.h"

int main(const int ac, const char * const *av,
        const char * const *env)
{
    setup_minishell(env);
    return (0);
}