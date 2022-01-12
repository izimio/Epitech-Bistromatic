/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** display one by one the characters of a string
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return (0);
}
