/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** bistro's header
*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "bistromatic.h"
#include "eval.h"

#ifndef MY_H_
    #define MY_H_
    void my_putchar(char c);
    int my_str_isnum(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int my_strlen(char const *str);
    int my_putstr(char const *str);
    int my_getnbr(char const *str);
    char *my_evil_str(char *str);
    char *infin_add(char *nb1, char *nb2);
    char *infin_sub(char *nb1, char *nb2);
    char *my_infin_mul(char *s1, char *s2);
    char *infin_divmod(char *nb1, char *nb2, int catchmod);
    char *substraction(char **nbs, int sign);
    char *remove_zeros(char *res);
    char *my_strcat(char *dest, char const *src);
    int is_greater(char *nb1, char *nb2);
    char *my_itoa(int n);
    char *my_strdup(char *src);
    char *my_memset(char value, int len);
    char *my_getnbr_base(char *str, char *base);
    char *my_convert_base_custom(char *str, char *base, char min);
    char *my_ctoa(char c);
    int error_handling(int ac, char **av);
    int error_expr_handling(char *expr, char *base, char *operators);
    int error_charbase_and_op_comp(char base, char *operator);
    int error_base_and_op_comp(char *base, char *operator);
    int error_check_char_occurence(char *str, int pos);
    int error_check_occurence(char *str);
    int error_is_op_or_base(char expr, char *str);
    int error_last_char_check(char *expr, char *base, char *op);
    int error_unknown_digits_and_op(char *expr, char *base, char *op);
    int error_parenthesis(char *expr, char *op);
    int error_par_after_digits(char *expr, char *base, char *op);
    int error_check_operators(char *expr, char *op);
    char *init_str(int len);
    char *malloc_for_minus(char *res);
    void error_and_quit();
#endif /* !MY_H_ */
