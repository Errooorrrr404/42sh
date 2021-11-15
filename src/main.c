/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <curses.h>
#include <termios.h>
#include <termcap.h>
#include "src.h"
#include "my.h"

int count_caract(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 32 && str[i] < 127 && str[i] != ';')
            nb++;
    }
    return nb;
}

void sigint_handler( __attribute__((unused)) int sig_num)
{
    signal(SIGINT, sigint_handler);
    my_putchar('\n');
}

int loop(int size, shell_t *shell, char **env)
{
    size_t bufsize = 0;
    commands_t *commands = init_commands();

    signal(SIGINT, sigint_handler);
    while (size != -1) {
        bufsize = 0;
        size = 0;
        shell->input = NULL;
        my_print_dir(shell, env);
        size = getline(&shell->input, &bufsize, stdin);
        if (size > 1) {
            shell->input[size - 1] = '\0';
            size = clean_and_launch(shell, size, commands);
        }
        free(shell->input);
    }
    size = shell->my_return;
    free_sh(shell);
    free_commands(commands);
    return (size);
}

int main(int ac, __attribute__((unused)) char **av, char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    int size = 0;
    int nb_return = 0;

    if (ac != 1 || !shell)
        return 84;
    shell->hist = malloc(sizeof(history_t));
    if (!shell->hist)
        return 84;
    if (isatty(0) == 0) {
        if (errno != EINVAL && errno != ENOTTY)
            perror("isatty");
    }
    init_struct(shell, env);
    nb_return = loop(size, shell, env);
    my_printf("\x1b[92mexit\x1b[0m\n");
    return nb_return;
}