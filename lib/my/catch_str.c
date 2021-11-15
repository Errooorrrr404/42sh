/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *catch_str(int i, char symbol, const char * const origin, char symbol2)
{
    char *str = malloc(sizeof(char) * my_strlen(origin));
    int k = 0;

    if (!str)
        return NULL;
    if (symbol != '\0') {
        for (; origin[i] != symbol && origin[i] != '\0'; i++);
        i++;
    }
    for (; origin[i] != symbol2 && origin[i] != '\0'; i++, k++)
        str[k] = origin[i];
    str[k] = '\0';
    return (str);
}

int catch_str_int(int i, char symbol, char *origin, char symbol2)
{
    char *str = NULL;
    int nb = 0;

    str = catch_str(i, symbol, origin, symbol2);
    if (!str)
        return -1;
    nb = my_putint(str);
    free(str);
    return (nb);
}