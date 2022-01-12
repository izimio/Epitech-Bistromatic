/*
** EPITECH PROJECT, 2021
** linked_lst_utils.c
** File description:
** oui
*/

#include "../../include/my.h"

t_list *create_elem(char *data, int depth, int sign)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->data = data;
    new->depth = depth;
    new->taken = 0;
    new->sign = sign;
    new->next = NULL;
    return (new);
}

t_list *my_list_push_back(t_list **b_l, char *data, int depth, int sign)
{
    t_list *tmp;
    if (!(*b_l)) {
        *b_l = create_elem(data, depth, sign);
        return (*b_l);
    }
    tmp = *b_l;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = create_elem(data, depth, sign);
    return (*b_l);
}

t_list *my_node_pop(t_list **begin_list, int nb)
{
    t_list *tmp = *begin_list;
    t_list *res = *begin_list;
    t_list *prev = NULL;
    int i = 0;

    if (tmp && i == nb) {
        *begin_list = tmp->next;
        free(tmp);
        return (*begin_list);
    } else {
        while (tmp && i++ != nb) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (!tmp)
            return (NULL);
        prev->next = tmp->next;
        free (tmp);
    }
    return (res);
}

char *get_list_expr(t_list *begin_list, int depth_ref)
{
    while (begin_list) {
        if (begin_list->depth == depth_ref && !begin_list->taken) {
            begin_list->taken = 1;
            return (begin_list->data);
        }
        begin_list = begin_list->next;
    }
    return (NULL);
}
