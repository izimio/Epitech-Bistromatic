/*
** EPITECH PROJECT, 2021
** B-CPE-101-LYN-1-1-evalexpr-joshua.brionne
** File description:
** my_strcat.c
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (src[j])
        dest[i++] = src[j++];
    dest[i] = '\0';
    return (dest);
}
