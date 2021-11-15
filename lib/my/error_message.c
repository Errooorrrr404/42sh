/*
** EPITECH PROJECT, 2019
** error_message.c
** File description:
** error_message.c
*/

#include "my.h"

void error_message(char *first_name, char *message)
{
    my_printf("\x1b[31m");
    my_error(first_name);
    my_error(message);
    my_printf("\x1B[0m");
}