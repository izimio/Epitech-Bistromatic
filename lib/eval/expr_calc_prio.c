/*
** EPITECH PROJECT, 2021
** expr_calc_prio.c
** File description:
** oui
*/

#include "../../include/my.h"

char *my_char_to_str(char c)
{
    char *tmp = malloc(sizeof(char) * 2);

    if (!tmp)
        return (NULL);
    tmp[0] = c;
    tmp[1] = '\0';
    return (tmp);
}

t_list *char_to_lst(char *str)
{
    t_list *lst = NULL;
    int i = -1;

    while (str[++i])
        if (in_c("+/*%", str, i))
            lst = my_list_push_back(&lst, my_char_to_str(str[i]), -1, 1);
    return (lst);
}

t_list *nb_to_lst(char *str, t_list *begin, int depth)
{
    char **res = my_split(str, "+*%/");
    int i = -1;
    t_list *lst = NULL;

    while (res[++i]) {
        if (res[i][0] == '\b')
            my_list_push_back(&lst, get_list_expr(begin, depth + 1), -1, 1);
        else
            my_list_push_back(&lst, my_strdup(res[i]), -1, 1);
    }
    free_char_etwal(res);
    return (lst);
}
