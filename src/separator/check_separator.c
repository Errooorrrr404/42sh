/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** check_separator
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "src.h"

void check_right_redir(shell_t *shell, commands_t *commands, int i)
{
    for (int pos = 0, nb = 0, nb2 = 0; shell->input[pos] != '\0'; pos++) {
        if (shell->input[pos] == '>' && nb == 0)
            nb = pos;
        else if (shell->input[pos] == '>' && nb != 0)
            nb2 = pos;
        if (nb + 1 != nb2 && nb2 != 0) {
            my_printf("Ambiguous output redirect.\n");
            return ;
        }
    }
    i++;
    if (!shell->input[i]) {
        my_printf("Missing name for redirect.\n");
        return ;
    }
    shell->my_return = 0;
    if (shell->input[i] == '>' && shell->input[i + 1] == ' ')
        do_right_redir(shell, commands, 1);
    else if (shell->input[i] == ' ')
        do_right_redir(shell, commands, 0);
}

void check_left_redir(shell_t *shell, commands_t *commands, int i)
{
    for (int pos = 0, nb = 0, nb2 = 0; shell->input[pos] != '\0'; pos++) {
        if (shell->input[pos] == '<' && nb == 0)
            nb = pos;
        else if (shell->input[pos] == '<' && nb != 0)
            nb2 = pos;
        if (nb + 1 != nb2 && nb2 != 0) {
            my_printf("Ambiguous input redirect.\n");
            return ;
        }
    }
    i++;
    if (!shell->input[i]) {
        my_printf("Missing name for redirect.\n");
        return ;
    }
    shell->my_return = 0;
    if (shell->input[i] == '<' && shell->input[i + 1] == ' ')
        do_left_redir(shell, commands, 1);
    else if (shell->input[i] == ' ')
        do_left_redir(shell, commands, 0);
}

int has_redir(shell_t *shell, commands_t *commands)
{
    if ((shell->input[0] == '<' || shell->input[0] == '>') &&
    strlen(shell->input) > 2) {
        my_printf("Invalid null command.\n");
        return -1;
    }
    for (int i = 0; shell->input[i]; i++) {
        if (shell->input[i] == '>') {
            check_right_redir(shell, commands, i);
            return -1;
        }
    }
    for (int i = 0; shell->input[i]; i++) {
        if (shell->input[i] == '<') {
            check_left_redir(shell, commands, i);
            return -1;
        }
    }
    return 0;
}

int have_separator(shell_t *shell, int size, commands_t *commands)
{
    for (int i = 0; shell->input[i] && shell->input[i + 1]; i++) {
        if ((shell->input[i] == '&' && shell->input[i + 1] == '&') ||
        (shell->input[i] == '|' && shell->input[i + 1] == '|')) {
            clean_for_and_or(shell);
            and_or_or(shell, commands);
            return -1;
        }
    }
    if (has_redir(shell, commands) == -1)
        return -1;
    for (int i = 0; shell->input[i]; i++) {
        if (shell->input[i] == '|') {
            my_pipe(shell, commands);
            return -1;
        }
    }
    return size;
}