/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** clean_str.c
*/

#include "my.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int has_word_before(char *str, int i)
{
    int c = i;
    int j = i;

    if (i <= 0)
        return 0;
    for (; str[j]; j++) {
        if (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
            c++;
    }
    if (j == c)
        return -1;
    if (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\n') {
        return 1;
    }
    return 0;
}

int check_space(char *buffer)
{
    int c = 0;
    int i = 0;

    for (; buffer[i]; i++) {
        if (buffer[i] == '\t' || buffer[i] == ' ' || buffer[i] == '\0')
            c++;
    }
    if (i == c)
        return 1;
    return 0;
}

void feed_ret(char *buffer, char *ret)
{
    int col = 0;

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '\t')
            buffer[i] = ' ';
        if (buffer[i] != ' ' && buffer[i] != '\t') {
            ret[col] = buffer[i];
            col++;
        } else if (has_word_before(buffer, i) == 1) {
            ret[col] = buffer[i];
            col++;
        }
    }
    ret[col] = '\0';
}

char *clear_spaces(char *str)
{
    char *buffer = malloc(sizeof(char) * (my_strlen(str) + 1));
    char *ret = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!ret || !buffer)
        return NULL;
    buffer = my_strcpy(buffer, str);
    if (check_space(buffer) == 1)
        return NULL;
    feed_ret(buffer, ret);
    free(buffer);
    free(str);
    return ret;
}