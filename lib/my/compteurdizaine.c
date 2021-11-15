/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** compteurdizaine.c
*/

#include "my.h"

int compteurdizaine(int nb)
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
