/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** sep
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "src.h"

void clean_for_and_or(shell_t *shell)
{
    for (int i = 0; shell->input[i] != '\0'; i++) {
        if (shell->input[i] == '&' && shell->input[i + 1] == '&') {
            shell->input[i] = '#';
            shell->input[i + 1] = ' ';
        } else if (shell->input[i] == '|' && shell->input[i + 1] == '|') {
            shell->input[i] = '%';
            shell->input[i + 1] = ' ';
        }
    }
    shell->input = clean_str(shell->input);
}

int exec_and_or(shell_t *shell, commands_t *commands, char *str, int len)
{
    int size = 0;

    free_array(shell->input_array);
    shell->input_array = str_to_array(shell->input, ' ');
    if (!shell->input_array)
        return -1;
    size = check_alias(shell);
    if (size == -1)
        return 1;
    size = check_which_command(shell, commands, size);
    return (break_and_or(shell->input, str, len, shell->my_return));
}

int loop_sep(shell_t *shell, commands_t *commands, char *dup, int len)
{
    char *str = malloc(sizeof(char) * (my_strlen(dup) + 1));
    int size_str = 0;

    if (!str)
        return 10000;
    for (; dup[len] != '#' && dup[len] != '%' && dup[len] != '\0';
    size_str++, len++)
        str[size_str] = dup[len];
    str[size_str] = '\0';
    free(shell->input);
    shell->input = clean_str(strdup(str));
    if (!shell->input)
        return 10000;
    if (exec_and_or(shell, commands, dup, len) == -1) {
        free(str);
        return 10000;
    }
    free(str);
    for (len++ ; dup[len] == '#' || dup[len] == ' ' || dup[len] == '%'; len++);
    return len;
}

int error_and_or(char *str)
{
    int size = strlen(str) - 1;

    if ((str[size] == '#' || str[size] == '%') && size > 2) {
        error_message("Invalid", " null command.\n");
        return -1;
    } else if (size == 0 && str[0] == '%') {
        error_message("Invalid", " null command.\n");
        return -1;
    }
    return 0;
}

void and_or_or(shell_t *shell, commands_t *commands)
{
    int len = 0;
    char *dup = strdup(shell->input);
    int nb;

    if (!dup) {
        free(dup);
        return;
    } else if (error_and_or(shell->input) == -1) {
        free(dup);
        return;
    }
    nb = my_strlen(dup);
    for (; len < nb;) {
        len = loop_sep(shell, commands, dup, len);
    }
    free(dup);
}