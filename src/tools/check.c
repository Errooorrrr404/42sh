/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** check.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "src.h"
#include "my.h"

int variable_exist(char **env, char *name)
{
    int i = 0;
    int k = 0;
    int sav_i = -1;
    char *variable;

    while (env[i] != NULL) {
        variable = malloc(sizeof(char) * my_strlen(env[i]));
        while (env[i][k] != '=') {
            variable[k] = env[i][k];
            k++;
        }
        variable[k] = '\0';
        if (match_str(variable, name) == 1)
            sav_i = i;
        i++;
        k = 0;
        free(variable);
    }
    return (sav_i);
}

int compare_args(char *input, char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] != input[i])
            return 84;
    return 0;
}

int check_alphanum(char *input)
{
    for (int i = 0; i < my_strlen(input); i++) {
        if ((input[i] < '0' || (input[i] > 'Z' && input[i] < 'a')
        || input[i] > 'z') && input[i] != ' ' && input[i] != '\n' &&
        input[i] != '/') {
            my_error("setenv: Variable name must contain ");
            my_error("alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}