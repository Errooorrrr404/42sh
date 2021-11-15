/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** check
*/

#include <string.h>
#include "my.h"
#include "src.h"

int check_is_exec(shell_t *shell, int size)
{
    if (strcmp(shell->input_array[0], "exit") == 0 ||
    (shell->array_path && exec_command(shell) == 0))
        return size;
    return -84;
}

int check_commands(shell_t *shell, int size, commands_t *commands)
{
    if (my_exit(shell) == -1)
        return -1;
    if (!commands)
        return -1;
    for (int i = 0; commands[i].command; i++) {
        if (strcmp(shell->input_array[0], commands[i].command) == 0) {
            (*commands[i].function)(shell);
            return size;
        }
    }
    return (check_is_exec(shell, size));
}

int is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return -1;
    }
    return 1;
}