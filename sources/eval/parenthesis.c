/*
** EPITECH PROJECT, 2021
** evalexpr
** File description:
** parenthesis.c
*/
#include "../../include/my.h"
#include <stdlib.h>

int my_strlen_until(char *str)
{
    int i = 1;
    int len = 0;
    int depth = 1;
    int max_len;

    for (i = 0; str[i] && depth; i++) {
        if (str[i] == '(')
            depth++;
        else if (str[i] == ')')
            depth--;
        len++;
        if (depth == 1)
            max_len = len;
    }
    return (max_len);
}

int add_subliminal(char *s, char *dest)
{
    int i = 0;
    int len = 0;
    int end = my_strlen(s);
    int d;

    for (i = 0; s[i] && i <= end; i++) {
        d = i + 1;
        if (s[i] == '-' && !in_c("", s, i) && s[d] && s[d] == '\b')
            continue;
        if (s[i] == '\b' && i > 0 && !is_operator(s[i - 1])) {
            (dest ? dest[len] = '*' : 0);
            len++;
        }
        (dest ? dest[len] = s[i] : 0);
        len++;
    }
    return (len);
}

char *mst_n_str_pb_tiot_eit_ld(char *str)
{
    char *res;
    int len;
    int a = remove_parenthesis(str, NULL);
    char *dest = malloc(sizeof(char) * (a + 1));

    dest[a] = '\0';
    remove_parenthesis(str, dest);
    len = add_subliminal(dest, NULL);
    res = malloc(sizeof(char) * (len + 1));
    add_subliminal(dest, res);
    res[len] = '\0';
    free(dest);
    return (res);
}

int remove_parenthesis(char *str, char *dest)
{
    int i = 0;
    int depth = 0;
    int len = 0;
    int end = my_strlen_until(str);
    for (i = 0; str[i] && i <= end; i++) {
        if (str[i] == '(') {
            (dest && depth == 0 ? dest[len] = '\b' : 0);
            len += depth == 0;
            depth++;
        } else if (str[i] == ')')
            depth--;
        if (depth == 0 && str[i] != ')') {
            (dest ? dest[len] = str[i] : 0);
            len++;
        }
    }
    return (len);
}

t_list *str_to_depth(char *e, int depth, t_list *begin, int sign)
{
    int len_until = my_strlen_until(e);
    int i;
    int s;
    int d;

    for (i = 0; i < len_until; i++) {
        d = i - 1;
        if (e[i] == '(') {
            s = (i > 0 && e[d] == '-' && (i == 1 || !in_c("", e, d)) ? -1 : 1);
            begin = str_to_depth(&(e[i + 1]), depth + 1, begin, s);
            i += my_strlen_until(&(e[i + 1])) - 1;
        }
    }
    my_list_push_back(&begin, mst_n_str_pb_tiot_eit_ld(e), depth, sign);
    return (begin);
}
