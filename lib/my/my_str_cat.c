/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my_str_cat.c
*/

#include <stdlib.h>
#include "my.h"

int my_po(char *buffer, char letter, int i)
{
    int c = 0;

    for (int j = i; buffer[j] != '\0' && buffer[j] != '\n'
                    && buffer[j] != letter && buffer[j] != '\t'; j++) {
        c++;
    }
    return c;
}

char *my_str_cat(char *first, char *second)
{
    int i = 0;
    int s = 0;
    char *buffer = malloc(sizeof(char) * my_strlen(first) +
            my_po(second, ' ', 0) + 2);

    if (!buffer || !first || !second)
        return NULL;
    for (; i != (my_strlen(first) + my_po(second, ' ', 0) + 1); i++) {
        if (i < my_strlen(first))
            buffer[i] = first[i];
        else {
            buffer[i] = second[s];
            s++;
        }
    }
    if (buffer[my_strlen(first) + my_po(second, ' ', 0)] == ' ')
        buffer[my_strlen(first) + my_po(second, ' ', 0)] = '\0';
    buffer[my_strlen(first) + my_po(second, ' ', 0) + 1] = '\0';
    return buffer;
}
