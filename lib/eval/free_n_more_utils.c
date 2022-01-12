/*
** EPITECH PROJECT, 2021
** free_n_more_utils.c
** File description:
** oui
*/

#include "../../include/my.h"

void free_char_etwal(char **res)
{
    int i = -1;

    while (res[++i])
        free(res[i]);
    free(res);
}

void my_lstclear(t_list **lst)
{
    t_list *tmp;

    if (!lst)
        return;
    while (*lst) {
        tmp = (*lst)->next;
        free(*lst);
        *lst = tmp;
    }
}
