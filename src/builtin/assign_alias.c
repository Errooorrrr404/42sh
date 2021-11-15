/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** assign_alias
*/

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "src.h"

char *assign_left(char *input, char *tmp)
{
    int i = 0;
    int begin = 0;

    for (; input[begin] != ' '; begin++);
    for (; input[begin] != '\0'; begin++, i++)
        tmp[i] = input[begin];
    tmp[i] = '\0';
    return tmp;
}

char *assign_right(char *input, char *str)
{
    int i = 0;
    int size = 0;
    int len = strlen(input);

    for (; input[size] != ' ' && input[size] != '\0'; size++);
    for (; size <= len; size++, i++)
        str[i] = input[size];
    str[i] = '\0';
    return str;
}