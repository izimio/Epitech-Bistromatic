/*
** EPITECH PROJECT, 2021
** B-CPE-101-LYN-1-1-evalexpr-joshua.brionne
** File description:
** evaluator.c
*/

#include "../../include/my.h"

char *eop(char *nb1, char *nb2, char op)
{
    switch (op) {
        case '+':
            return (infin_add(nb1, nb2));
        case '-':
            return (infin_sub(nb1, nb2));
        case '*':
            return (my_infin_mul(my_strdup(nb1), my_strdup(nb2)));
        case '/':
            return (infin_divmod(nb1, nb2, 0));
        case '%':
            return (infin_divmod(nb1, nb2, 1));
    }
    return (NULL);
}

char *eval_depth_lin(t_list *nb_l, t_list *lop, int sign)
{
    t_list *temp_ops_list = lop;
    t_list *temp_nb_l = nb_l;
    char *result;

    while (lop) {
        nb_l->next->data = eop(nb_l->data, nb_l->next->data, lop->data[0]);
        temp_nb_l = my_node_pop(&temp_nb_l, 0);
        temp_ops_list = my_node_pop(&temp_ops_list, 0);
        lop = temp_ops_list;
        nb_l = temp_nb_l;
    }
    if (sign == -1) {
        result = malloc(sizeof(char) * (my_strlen(temp_nb_l->data) + 2));
        result[0] = '-';
        result[1] = '\0';
        result = my_strcat(result, temp_nb_l->data);
        return (result);
    }
    return (temp_nb_l->data);
}

char *eval_depth(char *expr, t_list *begin_list, int depth, int sign)
{
    t_list *n = nb_to_lst(expr, begin_list, depth);
    t_list *ops_list = char_to_lst(expr);
    t_list *temps[2] = {n, ops_list};
    int op_index = 0;

    while (ops_list && is_in_lst(temps[1], "*/%")) {
        if (!is_incharset("*/%", ops_list->data[0])) {
            n = n->next;
            ops_list = ops_list->next;
            op_index++;
            continue;
        }
        n->next->data = eop(n->data, n->next->data, ops_list->data[0]);
        temps[0] = my_node_pop(&temps[0], op_index);
        temps[1] = my_node_pop(&temps[1], op_index);
        ops_list = temps[1];
        n = temps[0];
        op_index = 0;
    }
    return (eval_depth_lin(temps[0], temps[1], sign));
}
