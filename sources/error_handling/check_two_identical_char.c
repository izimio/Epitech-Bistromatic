/*
** EPITECH PROJECT, 2021
** handle_error.c
** File description:
** returns positive nb if there is no error, returns negative nb if not
*/

#include "../../include/my.h"

int error_charbase_and_op_comp(char base, char *operator)
{
    int i = 0;

    while (operator[i] != 0) {
        if (base == operator[i])
            return (-1);
        i += 1;
    }
    return (0);
}

int error_base_and_op_comp(char *base, char *operator)
{
    int i = 0;

    while (base[i] != 0) {
        if (error_charbase_and_op_comp(base[i], operator) < 0)
            return (-1);
        i += 1;
    }
    return (0);
}

int error_check_char_occurence(char *str, int pos)
{
    int i = pos + 1;

    while (str[i] != 0) {
        if (str[pos] == str[i])
            return (-2);
        i += 1;
    }
    return (0);
}

int error_check_occurence(char *str)
{
    int i = 0;

    while (str[i + 1] != 0) {
        if (error_check_char_occurence(str, i) < 0)
            return (-2);
        i += 1;
    }
    return (0);
}
