/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** clean_and_lauch
*/

#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "my.h"
#include "src.h"

int my_exit(shell_t *shell)
{
    if (strcmp("exit", shell->input_array[0]) == 0) {
        shell->my_return = 0;
        if (size_array(shell->input_array) == 2 &&
        is_num(shell->input_array[1]) == 1)
            shell->my_return = my_getnbr(shell->input_array[1]);
        else if (size_array(shell->input_array) >= 2) {
            error_message("exit:", " Expression Syntax.\n");
            return 0;
        }
        return -1;
    }
    if (strcmp("echo", shell->input_array[0]) != 0)
        shell->my_return = 0;
    return 0;
}

int assign_input(shell_t *shell, char *input)
{
    free(shell->input);
    free_array(shell->input_array);
    shell->input = strdup(input);
    if (count_caract(shell->input) > 0)
        shell->input = clean_str(shell->input);
    if (!shell->input)
        return -1;
    shell->input_array = str_to_array(shell->input, ' ');
    if (!shell->input_array)
        return -1;
    return 0;
}

int check_which_command(shell_t *shell, commands_t *commands, int size)
{
    switch (have_separator(shell, size, commands)) {
        case 84:
            return 84;
        case -1:
            return size;
    }
    size = check_alias(shell);
    if (size == -1)
        return 1;
    size = check_commands(shell, size, commands);
    if (size == -84) {
        error_message(shell->input_array[0], ": Command not found.\n");
        shell->my_return = 1;
    }
    return size;
}

int loop_exec(shell_t *shell, commands_t *commands, char **array, int size)
{
    int array_size = size_array(array);
    int nb = 0;

    for (int i = 0; i != array_size; i++) {
        nb = 0;
        if (assign_input(shell, array[i]) == -1) {
            nb = -1;
            break;
        }
        if (count_caract(shell->input) > 0)
            nb = check_which_command(shell, commands, size);
        if (nb == -1)
            break;
    }
    free_array(shell->input_array);
    free_array(array);
    return nb;
}

int clean_and_launch(shell_t *shell, int size, commands_t *commands)
{
    char **array;

    if (count_caract(shell->input) <= 0)
        return size;
    shell->input = clean_str(shell->input);
    put_in_history(shell, shell->hist);
    shell->input_array = str_to_array(shell->input, ' ');
    if (!shell->input_array)
        return -1;
    array = str_to_array(shell->input, ';');
    if (!array)
        return -1;
    return (loop_exec(shell, commands, array, size));
}