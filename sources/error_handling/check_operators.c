/*
** EPITECH PROJECT, 2021
** check_operators.c
** File description:
** returns a negative value if there is an error
*/

int error_check_after_op(char *expr, char *op, int i)
{
    int j = i + 1;

    if (expr[i] == op[0] || expr[i] == op[2] || expr[i] == op[3]) {
        if (expr[j] == op[4] || expr[j] == op[5] || expr[j] == op[6])
            return (-1);
        if (expr[j] == op[1])
            return (-2);
    }
    if (expr[i] == op[4] || expr[i] == op[5] || expr[i] == op[6]) {
        if (expr[j] == op[4] || expr[j] == op[5] || expr[j] == op[6])
            return (-3);
        if (expr[j] == op[1])
            return (-4);
    }
    return (0);
}

int error_check_operators(char *expr, char *op)
{
    int i = 0;

    if (expr[0] == op[4] || expr[0] == op[5] || expr[0] == op[6])
        return (-1);
    while (expr[i] != 0) {
        if (error_check_after_op(expr, op, i) < 0)
            return (-2);
        i += 1;
    }
    return (0);
}
