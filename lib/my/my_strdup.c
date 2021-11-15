/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** task01
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *new_string;
    int len_src = my_strlen(src);
    int i = 0;

    new_string = malloc(sizeof(char) * (len_src + 1));
    if (new_string == NULL)
        return NULL;
    while (i < len_src) {
        new_string[i] = src[i];
        i++;
    }
    new_string[i] = '\0';
    return (new_string);
}
