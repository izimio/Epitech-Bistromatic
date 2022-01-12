/*
** EPITECH PROJECT, 2021
** more_n_more_utils.c
** File description:
** mourir
*/

#include "../../include/my.h"

int is_in_lst(t_list *begin_list, char *str)
{
    while (begin_list) {
        if (is_incharset(str, begin_list->data[0]))
            return (1);
        begin_list = begin_list->next;
    }
    return (0);
}
