/*
** EPITECH PROJECT, 2018
** my_get_nbr.c
** File description:
** getnbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;

    if (str[0] == '-' && str[1] != '\0')
        i++;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr + str[i] - 48;
            nbr = nbr * 10;
        } else
            return (84);
        i++;
    }
    if (str[0] == '-')
        nbr = nbr * -1;
    nbr = nbr / 10;
    return (nbr);
}
