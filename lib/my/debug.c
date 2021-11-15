/*
** EPITECH PROJECT, 2019
** debug.c
** File description:
** debug.c
*/

#include "stdlib.h"
#include "stdio.h"
#include <unistd.h>
#include "my.h"

void debug(char *balise)
{
    char *buff;

    my_putstr(balise);
    read(0, &buff, 1);
}

void debug_loop(void)
{
    while (1);
}