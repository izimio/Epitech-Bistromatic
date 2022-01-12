/*
** EPITECH PROJECT, 2021
** evalexpr
** File description:
** evalexpr.c
*/

#include "../../include/my.h"
#include <stdlib.h>

char *get_expr_base(char *src, char *base, char const *charset)
{
    int j = 0;
    int i = 0;
    char *tmp_nb;
    t_list *begin = NULL;
    for (i = 0; src[i]; i++) {
        for (j = i; src[j] && !is_incharset((char *) charset, src[j]); j++);
        if (j <= i) {
            my_list_push_back(&begin, my_ctoa(src[j]), 0, 0);
            continue;
        }
        tmp_nb = malloc(sizeof(char) * (j - i + 2));
        for (j = i; src[j] && !is_incharset((char *) charset, src[j]); j++)
            tmp_nb[j - i] = src[j];
        tmp_nb[j - i] = '\0';
        i = j - 1;
        my_list_push_back(&begin, my_strdup(tmp_nb), 0, 1);
        free(tmp_nb);
    }
    return (my_lst_to_str(begin, base, (char *)charset));
}

char *expr_to_kira_dodin(char *source, char *base, char const *charset)
{
    char *exp = get_expr_base(source, base, charset);

    return (sanitize_expr(exp, "0123456789"));
}

char *eval_expr(char const *base, char const *ops,
char const *expr, unsigned int size)
{
    char *res;
    char *exp = expr_to_kira_dodin((char *) expr, (char *) base, ops);
    char *tmp;

    (void)size;
    if (my_strlen((char *) exp) == 0)
        return (0);
    t_list *l_b = str_to_depth(exp, 0, NULL, 1);
    t_list *t = l_b;
    while (l_b) {
        tmp = eval_depth(&(l_b->data[0]), t, l_b->depth, l_b->sign);
        l_b->data = sanitize_expr(tmp, (char *)base);
        if (l_b->next)
            l_b = l_b->next;
        else
            break;
    }
    res = l_b->data;
    my_lstclear(&t);
    return (res);
}
