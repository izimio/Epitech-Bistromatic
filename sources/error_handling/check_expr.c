/*
** EPITECH PROJECT, 2021
** check_expr.c
** File description:
** returns neg value if there is an error in expr
*/

#include "../../include/my.h"

int error_is_op_or_base(char expr, char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (expr == str[i])
            return (0);
        i += 1;
    }
    return (-1);
}

int error_par_after_digits(char *expr, char *base, char *op)
{
    int i = 0;

    while (expr[i] != 0) {
        if (error_is_op_or_base(expr[i], base) == 0 && expr[i + 1] == op[0])
            return (-1);
        i += 1;
    }
    return (0);
}

int error_last_char_check(char *expr, char *base, char *op)
{
    int i = my_strlen(expr) - 1;

    if (error_is_op_or_base(expr[i], base) == 0 || expr[i] == op[1])
        return (0);
    return (-1);
}

int error_unknown_digits_and_op(char *expr, char *base, char *op)
{
    int i = 0;

    while (expr[i] != 0) {
        if (error_is_op_or_base(expr[i], base) < 0 &&
        error_is_op_or_base(expr[i], op) < 0)
            return (-1);
        i += 1;
    }
    return (0);
}

int error_parenthesis(char *expr, char *op)
{
    int i = 0;
    int parenthesis = 0;

    while (expr[i] != 0) {
        if (expr[i] == op[0])
            parenthesis += 1;
        if (expr[i] == op[1])
            parenthesis -= 1;
        if (parenthesis < 0)
            return (-2);
        i += 1;
    }
    if (parenthesis != 0)
        return (-1);
    return (0);
}
