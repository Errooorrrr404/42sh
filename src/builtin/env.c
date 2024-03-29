/*
** EPITECH PROJECT, 2019
** env.c
** File description:
** env.c
*/

#include <stdlib.h>
#include <string.h>
#include "src.h"
#include "my.h"

char **create_env(char **env)
{
    char **my_env;
    int i;
    int a;
    int b;

    for (i = 0; env[i]; i++);
    my_env = malloc(sizeof(char *) * (i + 10));
    if (my_env == NULL)
        return NULL;
    for (a = 0; env[a]; a++) {
        my_env[a] = malloc(sizeof(char) * (my_strlen(env[a]) + 1));
        if (my_env[a] == NULL)
            return NULL;
        for (b = 0; b < my_strlen(env[a]); b++)
            my_env[a][b] = env[a][b];
        my_env[a][b] = '\0';
    }
    my_env[a] = NULL;
    return my_env;
}

void display_env(shell_t *shell)
{
    if (strcmp(shell->input_array[0], "env") == 0) {
        if (shell->input_array[1]) {
            error_message("env: '", shell->input_array[1]);
            error_message("': No such file or directory\n", "\0");
            return;
        }
        for (int j = 0; shell->env[j]; j++)
            my_printf("%s\n", shell->env[j]);
    }
    if (strcmp(shell->input_array[0], "setenv") == 0 &&
    !shell->input_array[1]) {
        for (int j = 0; shell->env[j]; j++)
            my_printf("%s\n", shell->env[j]);
    }
}