/*
** EPITECH PROJECT, 2021
** B-CPE-101-LYN-1-1-bistromatic-joshua.brionne
** File description:
** my_ctoa.c
*/

#include <stdlib.h>

char *my_ctoa(char c)
{
    char *res = malloc(sizeof(char) * 2);

    res[0] = c;
    res[1] = '\0';
    return (res);
}