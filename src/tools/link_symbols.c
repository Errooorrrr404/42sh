/*
** EPITECH PROJECT, 2019
** link_symbols.c
** File description:
** link_symbols.c
*/

#include "src.h"
#include "my.h"

int link_symbol3(char *str, int check)
{
    if (match_str(str, "<") == 1)
        check = 5;
    if (match_str(str, "<<") == 1)
        check = 6;
    return (check);
}

int link_symbol2(char *str, int check)
{
    if (match_str(str, ">") == 1)
        check = 3;
    if (match_str(str, ">>") == 1)
        check = 4;
    check = link_symbol3(str, check);
    return (check);
}

int link_symbol(char *str)
{
    int check = 0;

    if (match_str(str, ";") == 1)
        check = 1;
    if (match_str(str, "|") == 1)
        check = 2;
    check = link_symbol2(str, check);
    return (check);
}