/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** with_char.c
*/

#include <stdlib.h>

int my_strlen_wi(char const *str, char c)
{
    int i = 0;

    for (; str[i] != '\0' && str[i] != c; i++);
    return i;
}

char *my_strcpy_wi(char *dest, char const *src, char c)
{
    int i = 0;

    for (; src[i] != '\0' && src[i] != '\n' && src[i] != c; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
