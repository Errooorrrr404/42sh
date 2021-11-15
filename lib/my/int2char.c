/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** int2char.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *case_neg_int2char(char *str)
{
    int i = 1;
    int j = 0;
    char *strneg = malloc(sizeof(str) + 50);

    if (strneg == NULL)
        return (NULL);
    strneg[0] = '-';
    while (str[j] != '\0') {
        strneg[i] = str[j];
        i++;
        j++;
    }
    return (strneg);
}

int compteurdizaine2(int nb)
{
    int i = 0;
    int j = 1;
    int obj = 100;

    while (i != nb) {
        if (i == 10)
            j++;
        if (i == obj && j != obj) {
            obj = obj * 10;
            j++;
        }
        i++;
    }
    if (nb == 100)
        j = 3;
    if (nb == 10)
        j = 2;
    return (j);
}

char *int2char_part2(char *str, int nb, int check)
{
    int i = 0;
    int nb2;
    int nb3;
    int nbdizaine;

    nbdizaine = compteurdizaine2(nb);
    while (i != nbdizaine - 1) {
        nb2 = nb / f_puiss(10, nbdizaine - i - 1);
        str[i] = nb2 + 48;
        nb3 = nb - nb2 * f_puiss(10, nbdizaine - i - 1);
        nb = nb3;
        i++;
    }
    str[i] = nb + 48;
    str[i + 1] = '\0';
    if (check == 1)
        str = case_neg_int2char(str);
    if (str == NULL)
        return (NULL);
    return (str);
}

char *int2char(char *str, int nb)
{
    int check = 0;

    if (nb < 0) {
        nb = nb * (-1);
        check = 1;
    }
    str = my_strcpy(str, int2char_part2(str, nb, check));
    return (str);
}
