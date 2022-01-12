/*
** EPITECH PROJECT, 2021
** convert_base_custom.c
** File description:
** yo
*/

#include "../include/my.h"

int count_len(char *str, char *base)
{
    int i = 0;

    if (my_strlen(str) == 1 && str[0] == '0')
        return (1);
    if (str[0] == '-') {
        i++;
        str = &str[1];
    }
    while (my_strlen(str) >= 1 && str[0] != '0') {
        i++;
        str = infin_divmod(str, my_itoa(my_strlen(base)), 0);
    }
    return (i);
}

char *my_malloc_char(char *str, char *base)
{
    char *res;
    int len = count_len(str, base);

    res = malloc(sizeof(char) * len + 1);
    if (!res)
        exit(84);
    res[len] = '\0';
    return (res);
}

char *my_convert_base_custom(char *str, char *base, char min)
{
    int index = count_len(str, base);
    int trig = 0;
    char *len = my_itoa(my_strlen(base));
    char *toa = my_malloc_char(str, base);

    if (str[0] == '-') {
        str = &str[1];
        trig = 1;
    }
    while (index--) {
        toa[index] = base[my_getnbr(infin_divmod(str, len, 1))];
        str = infin_divmod(str, len, 0);
    }
    if (trig == 1)
        toa[0] = min;
    free(len);
    return (toa);
}
