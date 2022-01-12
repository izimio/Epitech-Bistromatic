/*
** EPITECH PROJECT, 2021
** B-CPE-101-LYN-1-1-bistromatic-joshua.brionne
** File description:
** sanitize_expr.c
*/

#include "../../include/my.h"

int *sanitize_replace(char *ex, char **dest, char *base, int i_len[2])
{
    int sign = 1;
    int ev_sign = 0;
    int display = ((i_len[0] - 1) >= 0 && (ex[i_len[0] - 1] == ')' ||
        (is_incharset(base, ex[i_len[0] - 1]))));

    while (ex[i_len[0]] == '+' || ex[i_len[0]] == '-') {
        ev_sign = 1;
        sign *= (ex[i_len[0]] == '-' ? -1 : 1);
        i_len[0]++;
    }
    if (ev_sign && (sign == -1 || display)) {
        (*dest ? (*dest)[i_len[1]] = (sign == -1 ? '-' : '+') : 0);
        i_len[1]++;
    }
    if (*dest) {
        (*dest)[i_len[1]] = ex[i_len[0]];
    }
    i_len[1]++;
    return (i_len);
}

static int sanitize_expr_utilis(char *ex, char *dest, char *base)
{
    int i = 0;
    int len = 0;
    int *tmp_int = malloc(sizeof(int) * 2);

    for (i = 0; ex[i]; i++) {
        tmp_int[0] = i;
        tmp_int[1] = len;
        tmp_int = sanitize_replace(ex, &dest, base, tmp_int);
        i = tmp_int[0];
        len = tmp_int[1];
    }
    return (len);
}

char *sanitize_expr(char *expr, char *base)
{
    int len = sanitize_expr_utilis(expr, NULL, base);
    char *dest = malloc(sizeof(char) * (len + 1));

    sanitize_expr_utilis(expr, dest, base);
    dest[len] = '\0';
    return (dest);
}
