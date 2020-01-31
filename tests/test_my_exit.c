/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests the my_exit function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(my_exit, functionnal_exit)
{
    cr_redirect_stdout();
    my_exit((char *[]){"exit", NULL});
    cr_assert_stdout_eq_str("exit\n");
}

Test(my_exit, none_functionnal_exit)
{
    cr_redirect_stdout();
    my_exit((char *[]){"exit", "a", NULL});
    cr_assert_stdout_eq_str("exit: Expression Syntax.\n");
}