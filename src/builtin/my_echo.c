/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_echo
*/

#include <stdlib.h>
#include <string.h>
#include "src.h"
#include "my.h"

void print_word(shell_t *shell, int i)
{
    int size;

    if (shell->input_array[i][0] != '\\')
        size = 0;
    else
        size = 1;
    for (; shell->input_array[i][size] != '\0'; size++) {
        if (shell->input_array[i][size] != 34)
            my_putchar(shell->input_array[i][size]);
    }
}

void print_echo_multi(shell_t *shell)
{
    for (int i = 1; i < size_array(shell->input_array); i++) {
        if (strncmp(shell->input_array[i], "$?", 2) == 0)
            my_printf("%d", shell->my_return);
        else
            print_word(shell, i);
        if (i + 1 < size_array(shell->input_array))
            my_putchar(' ');
    }
    my_printf("\n");
    shell->my_return = 0;
}

void my_echo(shell_t *shell)
{
    int size = size_array(shell->input_array);

    if (size == 1)
        my_printf("\n");
    else
        print_echo_multi(shell);
}