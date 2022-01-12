/*
** EPITECH PROJECT, 2021
** expr_utils.c
** File description:
** oui
*/

#include "../../include/my.h"

int is_incharset(char *str, char c)
{
    int i = -1;

    while (str[++i])
        if (c == str[i])
            return (1);
    return (0);
}

int is_operator(char c)
{
    char *operators = "+-*/%(";

    for (int i = 0; i < 6; i++)
        if (c == operators[i])
            return (1);
    return (0);
}
