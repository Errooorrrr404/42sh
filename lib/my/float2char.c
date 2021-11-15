/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** to_strarg_float.c
*/

#include "stdio.h"
#include "stdlib.h"
#include "my.h"

char *isneg_float2char(char *str)
{
    int i = 0;
    int j = 1;
    char *neg = malloc(sizeof(str));

    if (neg == NULL)
        return (NULL);
    neg[0] = '-';
    while (str[i] != '\0') {
        neg[j] = str[i];
        i++;
        j++;
    }
    return (neg);
}

char *float2char_part3(char *str, char *decimal, int check)
{
    int i = 0;
    int len = 0;

    len = my_strlen(str);
    str[len] = '.';
    len++;
    while (decimal[i] != '\0') {
        str[len] = decimal[i];
        len++;
        i++;
    }
    if (check == 1)
        str = isneg_float2char(str);
    if (str == NULL)
        return (NULL);
    return (str);
}

char *to_decimale_float(char *str, char *op2)
{
    int j = 0;
    int i = 0;
    char *result = malloc(sizeof(str) * 4);

    if (result == NULL)
        return NULL;
    i = my_strlen(str) - my_putint(op2);
    while (str[i] != '\0') {
        result[j] = str[i];
        j++;
        i++;
    }
    return (result);
}

char *float2char_part2(char *op, float value, int check)
{
    int i = 0;
    int dec = 0;
    char *str = malloc(sizeof(value) * 4);
    char *op2 = malloc(sizeof(char));
    char *decimal = malloc(sizeof(value) * 4);

    if (str == NULL || op2 == NULL || decimal == NULL)
        return (NULL);
    while (i < value)
        i++;
    i--;
    str = int2char(str, i);
    op2[0] = op[2];
    dec = (int) value * f_puiss(10, my_putint(op2));
    decimal = int2char(decimal, dec);
    decimal = to_decimale_float(decimal, op2);
    str = float2char_part3(str, decimal, check);
    if (str == NULL)
        return (NULL);
    return (str);
}

char *float2char(char *op, float value)
{
    int check = 0;
    char *str = NULL;

    if (value < 0) {
        check = 1;
        value = value *-1;
    }
    str = float2char_part2(op, value, check);
    if (str == NULL)
        return (NULL);
    return (str);
}
