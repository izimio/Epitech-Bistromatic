/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** oui
*/

#ifndef _EVAL_H_
    #define _EVAL_H_
    /* Struct */
    typedef struct s_list {
        int depth;
        char *data;
        struct s_list *next;
        int taken;
        int sign;
    } t_list;
    /* Linked lists */
    t_list *create_elem(char *data, int depth, int sign);
    t_list *my_list_push_back(t_list **b_l, char *data, int depth, int sign);
    t_list *my_node_pop(t_list **begin_list, int nb);
    char *get_list_expr(t_list *begin_list, int depth_ref);
    char **my_split(char *str, char *charset);
    t_list *char_to_lst(char *str);
    void my_lstclear(t_list **lst);
    int is_in_lst(t_list *begin_list, char *str);
    t_list *nb_to_lst(char *str, t_list *begin, int depth);
    char *my_lst_to_str(t_list *begin, char *base, char *charset);
    /* Parenthesis */
    int remove_parenthesis(char *str, char *dest);
    t_list *str_to_depth(char *e, int depth, t_list *begin, int sign);
    char *sanitize_expr(char *expr, char *base);
    /* Is check functions */
    int in_c(char *set, char *s, int d);
    int is_incharset(char *str, char c);
    int is_operator(char c);
    /* Operators */
    char *my_add(char *a, char *b);
    char *my_sub(char *a, char *b);
    char *my_mul(char *a, char *b);
    char *my_div(char *a, char *b);
    char *my_mod(char *a, char *b);
    /* Eval */
    char *eval_depth(char *expr, t_list *begin_list, int depth, int sign);
    void free_char_etwal(char **res);
#endif
