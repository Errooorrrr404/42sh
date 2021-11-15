/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_prompt
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "src.h"
#include "my.h"

void print_prompt(shell_t *shell, char *dir, char *str)
{
    int i = my_strlen(str);
    int j = 0;
    char *color;

    if (shell->my_return == 0)
        color = "\x1b[94m\x1b[4m[%s]\x1B[0m\x1B[1m\x1B[32m -> \x1B[0m";
    else
        color = "\x1b[94m\x1b[4m[%s]\x1B[0m\x1B[1m\x1B[31m -> \x1B[0m";
    for (; str[i - 1] != '/'; i--);
    for (; str[i]; i++, j++)
        dir[j] = str[i];
    dir[j] = '\0';
    if (dir[0] != '\0')
        my_printf(color, dir);
    else
        my_printf("\x1b[94m\x1b[4m[/]->\x1B[0m ");
}

void my_print_dir(shell_t *shell, char **env)
{
    int i = 0;
    char *str = NULL;
    char *dir;

    if (size_array(env) < 10) {
        if (shell->my_return == 0)
            my_printf("\x1B[1m\x1B[32m -> \x1B[0m");
        else
            my_printf("\x1B[1m\x1B[31m -> \x1B[0m");
        return;
    }
    for (; env[i]; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D')
            break;
    }
    str = getcwd(NULL, my_strlen(env[i]) + 1);
    dir = malloc(sizeof(char) * my_strlen(env[i]) + 1);
    print_prompt(shell, dir, str);
    free (dir);
    free (str);
}