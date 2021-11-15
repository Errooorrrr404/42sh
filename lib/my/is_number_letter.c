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

int isletter(char c)
{
    if (c >= 65 && c <= 90)
        return (2);
    else if (c >= 97 && c <= 122)
        return (1);
    else
        return (0);
}

int isnumber(char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}
