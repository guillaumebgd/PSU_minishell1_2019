/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** returns nb from a str
*/

static int get_sign(char const *str, int *i)
{
    int neg = 1;

    while (str[(*i)] == '+' || str[(*i)] == '-') {
        if (str[(*i)] == '-')
            neg *= -1;
        (*i) += 1;
    }
    return (neg);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int neg = 1;

    neg = get_sign(str, &i);
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        if (i > 0)
            nb *= 10;
        nb += str[i] - 48;
        i += 1;
    }
    return (nb * neg);
}