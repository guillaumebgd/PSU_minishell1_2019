/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** puts a nb on stdout considering its base
*/

#include "my.h"

void my_put_nbr(int nb, char const *base, unsigned int len_base)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb, base, len_base);
    } if (nb >= (int)len_base) {
        my_put_nbr(nb / len_base, base, len_base);
        my_put_nbr(nb % len_base, base, len_base);
    } else if (nb >= 0)
        my_putchar(base[nb]);
}
