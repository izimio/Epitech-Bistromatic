/*
** EPITECH PROJECT, 2021
** multiplication.c
** File description:
** infinite multiplication
*/

#include "../../include/my.h"

char *malloc_for_minus(char *res)
{
    char *tmp_res;
    res = remove_zeros(my_evil_str(res));
    if (res[0] == '0' && !res[1])
        return (res);
    tmp_res = malloc(sizeof(char) * (my_strlen(res) + 2));
    tmp_res[0] = '-';
    tmp_res[1] = '\0';
    tmp_res = my_strcat(tmp_res, res);
    return (tmp_res);
}

char *calc_mul(char *s1, char *s2, int sign)
{
    int i = -1;
    int j = -1;
    int len = my_strlen(s1) + my_strlen(s2) + 1;
    char *res = my_memset(0, len + sign);

    while (s1[++i]) {
        j = -1;
        while (s2[++j]) {
            res[i + j] += (s2[j] - '0') * (s1[i] - '0');
            res[i + j + 1] += res[i + j] / 10;
            res[i + j] = res[i + j] % 10;
        }
    }
    for (i = -1; ++i < len; i = i)
        res[i] += '0';
    if (sign)
        return (malloc_for_minus(res));
    return (remove_zeros(my_evil_str(res)));
}

char *my_infin_mul(char *s1, char *s2)
{
    int sign = 1;

    if ((s1[0] == '0' && !s1[1]) || (s2[0] == '0' && !s2[1]))
        return (my_strdup("0"));
    if (s1[0] == '-') {
        sign = -sign;
        s1 = &s1[1];
    }
    if (s2[0] == '-') {
        sign = -sign;
        s2 = &s2[1];
    }
    s1 = my_evil_str(s1);
    s2 = my_evil_str(s2);
    return (calc_mul(s1, s2, sign == -1));
}
