/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** bistro's main
*/

#include "../include/my.h"

static void print_bistro_man(void)
{
    my_putstr("USAGE\n./calc base operators size_read\n\nDESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for the parentheses and the 5");
    my_putstr(" operators\n");
    my_putstr("- size_read: number of characters to be read\n");
    exit(EXIT_VALUE);
}

static int check_error_one(int ac, char **av)
{
    if (error_handling(ac, av) < 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_VALUE);
    } else
        return (my_getnbr(av[3]));
    return (0);
}

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_VALUE);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_VALUE);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_VALUE);
    }
    expr[size] = 0;
    return (expr);
}

static void wrong_args(char **av)
{
    if (!av[2] && av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])
        print_bistro_man();
    else {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        exit(EXIT_VALUE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4)
        wrong_args(av);
    size = check_error_one(ac, av);
    expr = get_expr(size);
    if (error_expr_handling(expr, av[1], av[2]) < 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        return (84);
    }
    expr = sanitize_expr(eval_expr(av[1], av[2], expr, size), av[2]);
    my_putstr(my_convert_base_custom(expr,av[1], av[2][3]));
    free(expr);
    return (EXIT_SUCCESS);
}
