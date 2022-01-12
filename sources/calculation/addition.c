/*
** EPITECH PROJECT, 2021
** addition.c
** File description:
** infinite addition
*/

#include "../../include/my.h"

int is_greater(char *nb1, char *nb2)
{
    if (my_strlen(nb1) > my_strlen(nb2))
        return (1);
    else if (my_strlen(nb1) < my_strlen(nb2))
        return (0);
    else
        return (my_strcmp(nb1, nb2) > 0);
}

char *addition(char **nbs, int sign)
{
    int id[2] = {my_strlen(nbs[0]) - 1, my_strlen(nbs[1]) - 1};
    int digits[2] = {0, 0};
    int carried = 0;
    int tmp_sum;
    int len = (id[0] > id[1] ? id[0] : id[1]) + 2 + (sign == -1);
    char *res = my_memset('0', len + 1);

    for (; id[0] >= 0 || id[1] >= 0; id[0]--, id[1]--) {
        for (int i = 0; i <= 1; i++)
            digits[i] = (id[i] < 0 ? 0 : nbs[i][id[i]] - '0');
        tmp_sum = digits[0] + digits[1] + carried;
        res[len] = tmp_sum % 10 + '0';
        carried = tmp_sum / 10;
        len--;
    }
    if (carried > 0)
        res[len--] = carried + '0';
    if (sign == -1)
        res[len] = '-';
    return (res);
}

char *determine_opp(char *nb1, char *nb2, int *signs)
{
    char *nbs[2] = {nb1, nb2};
    char *rev_nbs[2] = {nb2, nb1};

    if (signs[0] == 1 && signs[1] == 1)
        return (addition(nbs, 1));
    if (signs[0] == -1 && signs[1] == 1) {
        if (is_greater(nb1, nb2))
            return (substraction(nbs, -1));
        else
            return (substraction(rev_nbs, 1));
    }
    if (signs[0] == 1 && signs[1] == -1) {
        if (is_greater(nb1, nb2))
            return (substraction(nbs, 1));
        else
            return (substraction(rev_nbs, -1));
    }
    if (signs[0] == -1 && signs[1] == -1)
        return (addition(nbs, -1));
    return (NULL);
}

char *infin_add(char *nb1, char *nb2)
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
    return (remove_zeros(determine_opp(nbs[0], nbs[1], signs)));
}
