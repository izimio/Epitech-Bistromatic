/*
** EPITECH PROJECT, 2021
** B-CPE-101-LYN-1-1-evalexpr-joshua.brionne
** File description:
** my_strdup.c
*/

#include "../../include/my.h"

char *my_strdup(char *src)
{
    int i = 0;
    char *cpy;
    i = 0;
    if (!(cpy = malloc(sizeof(char) * my_strlen(src) + 1)))
        return (NULL);
    while (src[i]) {
        cpy[i] = src[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}
