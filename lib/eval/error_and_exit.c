/*
** EPITECH PROJECT, 2021
** B-CPE-101-LYN-1-1-bistromatic-joshua.brionne
** File description:
** error_and_exit.c
*/

#include "../../include/my.h"

void error_and_quit()
{
    my_putstr(SYNTAX_ERROR_MSG);
    exit(EXIT_VALUE);
}