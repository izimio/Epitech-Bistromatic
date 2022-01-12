/*
** EPITECH PROJECT, 2021
** B-CPE-101-LYN-1-1-evalexpr-joshua.brionne
** File description:
** my_itoa.c
*/

#include "../../include/my.h"

static int count(int nb)
{
    long nbr = nb;
    int i = 0;

    if (nbr <= 0) {
        i++;
        nbr = -nbr;
    }
    while (nbr > 0) {
        i++;
        nbr = nbr / 10;
    }
    return (i);
}

char *my_itoa(int n)
{
    long nbr = n;
    int i = count(n);
    char *toa;

    toa = malloc(sizeof(char) * i + 1);
    toa[i] = '\0';
    if (!toa)
        return (NULL);
    toa[0] = '0';
    if (n == 0)
        return (toa);
    if (nbr < 0) {
        toa[0] = '-';
        nbr = -nbr;
    }
    while (nbr > 0) {
        toa[--i] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (toa);
}