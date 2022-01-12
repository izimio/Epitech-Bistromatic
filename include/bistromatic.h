/*
** EPITECH PROJECT, 2021
** bistromatic.h
** File description:
** bistro's header
*/

#ifndef _BISTRO_H_
    #define _BISTRO_H_
    #define OP_OPEN_PARENT_IDX 0
    #define OP_CLOSE_PARENT_IDX 1
    #define OP_PLUS_IDX 2
    #define OP_SUB_IDX 3
    #define OP_NEG_IDX 3
    #define OP_MULT_IDX 4
    #define OP_DIV_IDX 5
    #define OP_MOD_IDX 6
    #define EXIT_VALUE 84
    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG "error"
    char *eval_expr(char const *base, char const *ops,
        char const *expr, unsigned int size);
#endif
