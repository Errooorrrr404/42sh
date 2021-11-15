/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** break_and_or
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "src.h"

int chose_end(int size, char c)
{
    if (size == 1) {
        if (c == '#')
            return -1;
        if (c == '%')
            return 0;
    } else {
        if (c == '#')
            return 0;
        if (c == '%')
            return -1;
    }
    return 0;
}

int break_and_or(char *input, char *str, int len, int size)
{
    int i = len - strlen(input);

    for (int j = 0; j != my_strlen(input) + 1 && str[i] != '\0'; i++, j++) {
        if (str[i] == '%' || str[i] == '#') {
            return (chose_end(size, str[i]));
        }
    }
    return -1;
}