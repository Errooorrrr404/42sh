/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** free_sh
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "src.h"
#include "my.h"

void free_sh(shell_t *shell)
{
    if (shell->old_pwd)
        free(shell->old_pwd);
    if (shell->line_path && shell->line_path[0] != 'E')
        free(shell->line_path);
    free(shell->home);
    if (shell->hist->history != NULL) {
        free_array(shell->hist->history);
    }
    if (shell->line_path) {
        free_array(shell->array_path);
        free_array(shell->env);
    }
    free(shell->hist);
    free(shell);
}

void free_commands(commands_t *commands)
{
    for (int i = 0; commands[i].command; i++)
        free(commands[i].command);
    free(commands);
}