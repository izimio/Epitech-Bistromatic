/*
** EPITECH PROJECT, 2021
** splitt.c
** File description:
** arr to world
*/

#include <stdlib.h>
#include "../../include/my.h"

int in_c(char *set, char *s, int d)
{
    int i = -1;
    char c = s[d];
    d--;

    if (c == '-' && d >= 0 && (s[d] == '\b' || s[d] == ')' ||
    (s[d] >= '0' && s[d] <= '9')))
        return (1);
    while (set[++i]) {
        if (set[i] == c)
            return (1);
    }
    return (0);
}

static int wcount(char *str, char *charset)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        while (str[i] && in_c(charset, str, i))
            i++;
        if (str[i] && !in_c(charset, str, i))
            count++;
        while (str[i] && !in_c(charset, str, i))
            i++;
    }
    return (count);
}

static char *wmalloc(char *str, char *charset)
{
    char *toa;
    int i = 0;

    while (str[i] && !in_c(charset, str, i))
        i++;
    toa = malloc(sizeof(char) * i + 1);
    i = -1;
    while (str[++i] && !in_c(charset, str, i))
        toa[i] = str[i];
    toa[i] = '\0';
    return (toa);
}

char **my_split(char *str, char *charset)
{
    int i = 0;
    int j = 0;
    char **arr;

    arr = malloc(sizeof(char *) * (wcount(str, charset) + 1));
    while (str[i]) {
        while (str[i] && in_c(charset, str, i))
            i++;
        if (str[i] && !in_c(charset, str, i))
            arr[j++] = wmalloc(&str[i], charset);
        while (str[i] && !in_c(charset, str, i))
            i++;
    }
    arr[j] = 0;
    return (arr);
}
