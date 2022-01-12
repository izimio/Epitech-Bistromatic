/*
** EPITECH PROJECT, 2021
** convert_base.c
** File description:
** convrt base kekw
*/

#include "../include/my.h"

int in_base(char *base, char c)
{
    int i = 0;

    while (base[i]) {
        if (base[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

char *malloc_for_minus_again(char *res)
{
    char *r;

    r = malloc(sizeof(char) * (my_strlen(res) + 1));
    r[0] = '-';
    r = my_strcat(r, res);
    return (r);
}

char *my_getnbr_base(char *str, char *base)
{
    int i = 0;
    int si = 0;
    char *res = my_ctoa('0');

    if (str[0] == '-') {
        str = &str[1];
        si = 1;
    }
    while (str[i] && in_base(base, str[i]) != -1) {
        res = my_infin_mul(res, my_itoa(my_strlen(base)));
        res = remove_zeros(res);
        res = infin_add(res, my_itoa(in_base(base, str[i++])));
    }
    if (si)
        return (malloc_for_minus_again(res));
    return (res);
}
