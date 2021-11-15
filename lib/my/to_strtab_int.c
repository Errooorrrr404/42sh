/*
** EPITECH PROJECT, 2019
** to_strtab_int.c
** File description:
** to_strtab_int.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char **to_strtab_int(char **tab, int nb)
{
    char *nb_str = malloc(sizeof(char) * 8);

    if (nb_str == NULL)
        return (NULL);
    nb_str = int2char(nb_str, nb);
    if (nb_str == NULL)
        return (NULL);
    tab = to_strtab_char(tab, nb_str);
    if (tab == NULL)
        return (NULL);
    free(nb_str);
    return (tab);
}