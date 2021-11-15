/*
** EPITECH PROJECT, 2019
** unsetenv.c
** File description:
** unsetenv.c
*/

#include <stdlib.h>
#include <string.h>
#include "src.h"
#include "my.h"

int find_env_var(char *str, char **env)
{
    int i;

    for (i = 0; env[i]; i++) {
        if (strncmp(str, env[i], strlen(str)) == 0)
            return i;
    }
    return -1;
}

void do_unsetenv(shell_t *shell, int i)
{
    for (; shell->env[i + 1]; i++) {
        free(shell->env[i]);
        shell->env[i] = strdup(shell->env[i + 1]);
    }
    shell->env[i] = NULL;
    free(shell->env[i + 1]);
}

void my_unsetenv(shell_t *shell)
{
    int len = 1;
    int i = 0;

    if (size_array(shell->input_array) <= 1) {
        error_message("unsetenv:", " Too few arguments.\n");
        return;
    }
    for (; shell->input_array[len]; len++) {
        i = find_env_var(shell->input_array[len], shell->env);
        if (i != -1)
            do_unsetenv(shell, i);
    }
}