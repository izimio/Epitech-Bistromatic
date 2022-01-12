/*
** EPITECH PROJECT, 2021
** divmod.c
** File description:
** infinite division and modulo
*/

#include "../../include/my.h"
#include "../../include/bistromatic.h"

char *substraction(char **nbs, int sign);

char *my_push(char *str, char a)
{
    int i = -1;

    while (str[++i])
        if (!str[i + 1])
            str[i] = a;
        else
            str[i] = str[i + 1];
    return (str);
}

char **str_to_list(char *str1, char *str2)
{
    char **res = malloc(sizeof(char *) * 2);
    res[0] = str1;
    res[1] = str2;
    return (res);
}

void div_utilis(char **nbs, int *occurences, char **tmp_nbr, int i)
{
    if (is_greater(nbs[1], remove_zeros(*tmp_nbr)))
        *tmp_nbr = my_push(*tmp_nbr, nbs[0][i]);
    while (!is_greater(nbs[1], remove_zeros(*tmp_nbr))) {
        *tmp_nbr = substraction(str_to_list(*tmp_nbr, nbs[1]), 1);
        (*occurences)++;
    }
}

char *divmod(char **nbs, int sign, int catchmod)
{
    int len[2] = {my_strlen(nbs[0]), my_strlen(nbs[1])};
    char *res = my_memset('0', len[0] + 1 + (sign == -1));
    int has_numbers = 0;
    char *tmp_nbr = my_memset('0', len[1] + 1);
    int occurences = 0;

    if (sign == -1)
        my_push(res, '-');
    for (int i = 0; i < len[0]; i++) {
        occurences = 0;
        div_utilis(nbs, &occurences, &tmp_nbr, i);
        if (occurences || has_numbers) {
            my_push(res, occurences + '0');
            has_numbers = 1;
        }
    }
    if (sign == -1)
        tmp_nbr = malloc_for_minus(my_evil_str(remove_zeros(tmp_nbr)));
    return (catchmod ? remove_zeros(tmp_nbr) : remove_zeros(res));
}

char *infin_divmod(char *nb1, char *nb2, int cmod)
{
    char *nbs[2] = {nb1, nb2};
    int signs[2] = {1, 1};
    int k;

    if (nb2[0] == '0' && !nb2[1])
        error_and_quit();
    for (int i = 0; i <= 1; i++) {
        for (k = 0; (nbs[i][k] == '-' || nbs[i][k] == '0')
        && nbs[i][k + 1] != '\0'; k++)
            signs[i] *= ((nbs[i][k] == '-') ? -1 : 1);
        nbs[i] = &(nbs[i][k]);
    }
    if (is_greater(nbs[1], nbs[0])) {
        if (signs[0] == -1 && cmod)
            nbs[0] = (malloc_for_minus(my_evil_str(remove_zeros(nbs[0]))));
        return (cmod ? nbs[0] : "0");
    }
    if (!my_str_isnum(nbs[0]) || !my_str_isnum(nbs[1]))
        return (NULL);
    return (divmod(nbs, (cmod ?  signs[0] : signs[0] * signs[1]), cmod));
}
