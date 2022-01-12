/*
** EPITECH PROJECT, 2021
** substraction.c
** File description:
** infinite substraction
*/

#include "../../include/my.h"

char *addition(char **nbs, int sign);

char *remove_zeros(char *res)
{
    int i;

    for (i = 0; res[i] == '0' && res[i + 1] != '\0'; i++);
    res = &res[i];
    return (res);
}

char *substraction(char **nbs, int sign)
{
    int indexs[2] = {my_strlen(nbs[0]) - 1, my_strlen(nbs[1]) - 1};
    int digits[2] = {0, 0};
    int get_ten = 0;
    int len = indexs[0] + 2 + (sign == -1);
    char *res = my_memset('0', len + 1);

    for (; indexs[0] >= 0 || indexs[1] >= 0; indexs[0]--, indexs[1]--) {
        for (int i = 0; i <= 1; i++)
            digits[i] = (indexs[i] < 0 ? 0 : nbs[i][indexs[i]] - '0');
        digits[0] -= get_ten;
        if (digits[0] < digits[1]) {
            get_ten = 1;
            digits[0] += 10;
        } else
            get_ten = 0;
        res[len--] = (digits[0] - digits[1]) + '0';
    }
    if (sign == -1)
        return (malloc_for_minus(my_evil_str(remove_zeros(res))));
    return (res);
}

char *determine_subopp(char *nb1, char *nb2, int *signs)
{
    char *nbs[2] = {nb1, nb2};
    char *rev_nbs[2] = {nb2, nb1};

    if (signs[0] == 1 && signs[1] == 1) {
        if (is_greater(nb2, nb1))
            return (substraction(rev_nbs, -1));
        else
            return (substraction(nbs, 1));
    }
    if (signs[0] == -1 && signs[1] == -1) {
        if (is_greater(nb2, nb1))
            return (substraction(rev_nbs, 1));
        else
            return (substraction(nbs, -1));
    }
    if (signs[0] == -1 && signs[1] == 1)
        return (addition(nbs, -1));
    if (signs[0] == 1 && signs[1] == -1)
        return (addition(nbs, 1));
    return (NULL);
}

char *infin_sub(char *nb1, char *nb2)
{
    char *nbs[2] = {nb1, nb2};
    int signs[2] = {1, 1};
    int k;

    for (int i = 0; i <= 1; i++) {
        for (k = 0; (nbs[i][k] == '-' || nbs[i][k] == '0')
        && nbs[i][k + 1] != '\0'; k++)
            signs[i] *= ((nbs[i][k] == '-') ?  -1 : 1);
        nbs[i] = &(nbs[i][k]);
    }
    if (!my_str_isnum(nbs[0]) || !my_str_isnum(nbs[1]))
        return (NULL);
    return (remove_zeros(determine_subopp(nbs[0], nbs[1], signs)));
}
