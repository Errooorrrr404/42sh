/*
** EPITECH PROJECT, 2019
** Created by Alexis Leclercq (alexis1.leclerq@epitech.eu)
** File description:
** my_strcpy.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}