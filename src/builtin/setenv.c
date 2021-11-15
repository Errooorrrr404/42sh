/*
** EPITECH PROJECT, 2019
** setenv.c
** File description:
** setenv.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "src.h"

int setenv_formatter(char **command)
{
    int i = 0;

    if (isletter(command[1][0]) == 0) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    if (size_array(command) > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return (1);
    }
    while (command[1][i] != '\0') {
        if (isletter(command[1][i]) == 0 && isnumber(command[1][i]) == 0) {
            my_putstr("setenv: Variable name ");
            my_putstr("must contain alphanumeric characters.\n");
            return (1);
        }
        i++;
    }
    return (0);
}

char *add_line_env2(char **command, int k, int i, char *str)
{
    if (size_array(command) == 3) {
        while (command[2][k] != '\0') {
            str[i] = command[2][k];
            i++;
            k++;
        }
    }
    str[i] = '\0';
    return (str);
}

char *add_line_env(char **command)
{
    int i = 0;
    int k = 0;
    int alloc_int = my_strlen(command[1]) + 1;
    char *str;

    if (size_array(command) == 3)
        alloc_int += my_strlen(command[2]) + 2;
    str = malloc(sizeof(char) * (alloc_int + 1));
    while (command[1][k] != '\0') {
        str[i] = command[1][k];
        i++;
        k++;
    }
    str[i] = '=';
    k = 0;
    i++;
    return (add_line_env2(command, k, i, str));
}

void setenv_option_exist(shell_t *shell)
{
    int i = 0;
    char *str;
    int line = variable_exist(shell->env, shell->input_array[1]);
    int error = setenv_formatter(shell->input_array);

    if (error != 1) {
        while (shell->env[i] != NULL) {
            if (i == line) {
                free(shell->env[i]);
                shell->env[i] = add_line_env(shell->input_array);
            }
            i++;
        }
        if (line == -1) {
            str = add_line_env(shell->input_array);
            shell->env = to_strtab_char(shell->env, str);
            free(str);
        }
    }
}

void setenv_command(shell_t *shell)
{
    if (!shell->input_array[1])
        display_env(shell);
    else
        setenv_option_exist(shell);
}