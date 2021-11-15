/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** my_f_puiss.c
*/

#include "my.h"

float f_puiss_float(float nb, int puiss)
{
    int i = 1;
    float coef = nb;

    while (i != puiss) {
        nb = coef * nb;
        i++;
    }
    return (nb);
}
