/*
** EPITECH PROJECT, 2021
** B-CPE-101-LYN-1-1-bistromatic-joshua.brionne
** File description:
** my_memset.c
*/

#include <stdlib.h>

char *my_memset(char value, int len)
{
    int i = -1;
    char *res = malloc(sizeof(char) * (len + 1));

    if (!res)
        exit(1);
    while (++i < len)
        res[i] = value;
    res[len] = '\0';
    return (res);
}
