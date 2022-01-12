/*
** EPITECH PROJECT, 2021
** my_str_isnum.c
** File description:
** returns 1 if the string contains only digits characters
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return (0);
    return (1);
}
