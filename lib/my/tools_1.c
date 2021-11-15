/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** tools.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

char *strconcate(char *origin, char *str)
{
    int i = my_strlen(origin);
    int k = 0;

    while (str[k] != '\0') {
        origin[i] = str[k];
        i++;
        k++;
    }
    return (origin);
}

int my_strlen_array(char **str)
{
    int i = 0;

    while (str[i] != NULL) {
        i++;
    }
    return (i);
}

void print_strtab(char **strtab)
{
    int i = 0;

    while (strtab[i] != NULL) {
        my_putstr(strtab[i]);
        my_putchar('\n');
        i++;
    }
}