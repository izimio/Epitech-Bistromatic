/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** linked_lst_utils_bis.c
*/

#include "../../include/my.h"

void lst_to_decimal(t_list *begin, char *base)
{
    char *temp;
    t_list *tmp = begin;

    while (begin) {
        if (begin->sign == 1) {
            temp = my_getnbr_base(begin->data, base);
            begin->data = temp;
        }
        begin = begin->next;
    }
}

void lst_to_op(t_list *begin, char *charset)
{
    char *temp;
    int j = 0;
    char *or = "()+-*/%";

    while (begin) {
        if (begin->sign == 0) {
            for (j = 0; charset[j] && charset[j] != begin->data[0]; j++);
            temp = my_ctoa(charset[j] && or[j] ? or[j] : temp[0]);
            begin->data = temp;
        }
        begin = begin->next;
    }
}

int my_lst_len(t_list *begin)
{
    int i = 0;

    while (begin) {
        i += my_strlen(begin->data);
        begin = begin->next;
    }
    return (i);
}

char *my_lst_to_str(t_list *begin, char *base, char *charset)
{
    t_list *tmp = begin;
    char *res;

    lst_to_decimal(begin, base);
    lst_to_op(begin, charset);
    res = malloc(sizeof(char) * (my_lst_len(tmp) + 1));
    res[0] = '\0';
    while (begin) {
        res = my_strcat(res, begin->data);
        begin = begin->next;
    }
    return (res);
}
