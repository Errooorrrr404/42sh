/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** match_str.c
*/

#include "my.h"

int match_str(char *src, char *match)
{
    int i = 0;
    int check = 0;

    if (my_strlen(src) != my_strlen(match))
        check = 1;
    while (src[i] != '\0' && check == 0) {
        if (src[i] != match[i]) {
            check = 1;
        }
        i++;
    }
    if (check == 1)
        return (0);
    return (1);
}
