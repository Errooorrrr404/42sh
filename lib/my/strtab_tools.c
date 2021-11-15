/*
** EPITECH PROJECT, 2019
** strtab_tools.c
** File description:
** strtab_tools.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char **my_strtab_cpy(char **dest, char **src)
{
    int y = 0;

    while (src[y] != NULL) {
        to_strtab_char(dest, src[y]);
        y++;
    }
    return (dest);
}

char **re_malloc_strtab(char **strtab)
{
    int i = 0;
    char **strtab_cpy = define_strtab(sizeof(char *)
    * (my_strlen_array(strtab) + 2));

    if (strtab_cpy == NULL)
        return (NULL);
    while (strtab[i] != NULL) {
        to_strtab_char(strtab_cpy, strtab[i]);
        i++;
    }
    free_strtab(strtab);
    return (strtab_cpy);
}

char **define_strtab(int size)
{
    int i = 0;
    char **str = NULL;
    str = malloc(sizeof(char *) * (size + 2));

    if (str == NULL)
        return (NULL);
    while (i <= size) {
        str[i] = NULL;
        i++;
    }
    str[i] = NULL;
    return (str);
}

void free_strtab(char **strtab)
{
    int i = 0;

    while (strtab[i] != NULL) {
        free(strtab[i]);
        i++;
    }
    free(strtab);
}