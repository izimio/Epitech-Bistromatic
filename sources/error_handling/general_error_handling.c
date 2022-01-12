/*
** EPITECH PROJECT, 2021
** general_error_handling.c
** File description:
** returns negative nb if there is any error case
*/

#include "../../include/my.h"

int error_expr_handling(char *expr, char *base, char *operators)
{
    if (error_unknown_digits_and_op(expr, base, operators) < 0)
        return (-6);
    if (error_parenthesis(expr, operators) < 0)
        return (-7);
    if (error_last_char_check(expr, base, operators) < 0)
        return (-8);
    if (error_check_operators(expr, operators) < 0)
        return (-9);
    if (error_par_after_digits(expr, base, operators) < 0)
        return (-10);
    return (0);
}

int error_handling(int ac, char **av)
{
    (void)ac;
    if (my_strlen(av[2]) != 7)
        return (-1);
    if (my_strlen(av[1]) < 2)
        return (-2);
    if (error_base_and_op_comp(av[1], av[2]) < 0)
        return (-3);
    if (error_check_occurence(av[1]) < 0)
        return (-4);
    if (error_check_occurence(av[2]) < 0)
        return (-5);
    return (0);
}
