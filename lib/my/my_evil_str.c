/*
** EPITECH PROJECT, 2021
** my_evil_str.c
** File description:
** swap each of the string’s characters, two by two
*/

#include "../../include/my.h"

char *my_evil_str(char *str)
{
    int len = my_strlen(str) - 1;
    int mid = len / 2;
    char buffer;
    int i = 0;

    while (i <= mid) {
        buffer = str[i];
        str[i] = str[len - i];
        str[len - i] = buffer;
        i++;
    }
    return (str);
}
