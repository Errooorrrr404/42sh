/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** array_tools
*/

#include <stdlib.h>
#include "my.h"

char *fill_str(char *dest, char **array, char *str)
{
    int len = 0;

    for (int line = 0, col = 0; array[line]; len++) {
        dest[len] = array[line][col];
        if (array[line][col] == '\0') {
            dest[len] = '#';
            line++;
            col = 0;
        } else
            col++;
    }
    for (int i = 0; str[i] != '\0'; i++, len++)
        dest[len] = str[i];
    dest[len] = '\0';
    return dest;
}

char *array_to_str(char **array, char *str)
{
    int my_malloc = 0;
    char *dest;

    for (int i = 0; array[i]; i++)
        my_malloc += (my_strlen(array[i]) + 2);
    my_malloc += (my_strlen(str) + 2);
    dest = malloc(sizeof(char) * (my_malloc + 2));

    if (!dest)
        return NULL;
    dest = fill_str(dest, array, str);
    return dest;
}

int size_array(char **array)
{
    int size = 0;

    for (; array[size]; size++);
    return size;
}

void print_array(char **array)
{
    for (int i = 0; array[i]; i++) {
        my_printf("%s\n", array[i]);
    }
}

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}