/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** pipe
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "src.h"
#include "my.h"

void exec_pipe(shell_t *shell)
{
    int nb = assign_path(shell);
    char **argv;

    if (nb != 0)
        return;
    argv = str_to_array(shell->input, ' ');
    execve(shell->path, argv, shell->env);
}

int assign(shell_t *shell, char *input)
{
    free(shell->input);
    free_array(shell->input_array);
    shell->input = str_until_pipe(input);
    if (!shell->input)
        return -1;
    shell->input_array = str_to_array(shell->input, ' ');
    if (!shell->input_array)
        return -1;
    return 0;
}

void loop_pipe(shell_t *shell, char *input, int *pipefd, int nb_pipe)
{
    pid_t pid;

    for (int i = 0, commandc = 0; i <= nb_pipe; i++, commandc++) {
        if (assign(shell, input) == -1)
            break;
        pid = fork();
        if (pid == 0) {
            if (i != 0 && dup2(pipefd[(commandc - 1) * 2], 0) < 0)
                exit(pid);
            if (i != nb_pipe && dup2(pipefd[commandc * 2 + 1], 1) < 0)
                exit(pid);
            for (int i = 0; i < 2 * nb_pipe; i++)
                close(pipefd[i]);
            exec_pipe(shell);
        } else if (pid < 0)
            exit(EXIT_FAILURE);
    }
}

void launch_pipe(shell_t *shell, char *input)
{
    int status;
    int nb_pipe = count_pipe(input);
    int pipefd[2 * nb_pipe];

    if (nb_pipe > 1)
        return;
    for (int i = 0; i <= nb_pipe; i++)
        if (pipe(pipefd + i * 2) < 0)
            exit(EXIT_FAILURE);
    loop_pipe(shell, input, pipefd, nb_pipe);
    free(input);
    for (int i = 0; i < 2 * nb_pipe + 1; i++)
        close(pipefd[i]);
    for (int i = 0; i <= nb_pipe; i++)
        wait(&status);
}

void my_pipe(shell_t *shell, __attribute__((unused)) commands_t *commands)
{
    if (size_array(shell->input_array) < 2 || shell->input[0] == '|')
        return error_message("Invalid null", " command.\n");
    for (int i = 0; shell->input_array[i]; ++i)
        if (shell->input_array[i][0] == '|' && (shell->input_array[i][1] != '\0'
        || shell->input_array[i + 1] == NULL))
            return error_message("Invalid null", " command.\n");
    if (check_com_pipe_exist(shell) == -1)
        return;
    prep_pipe(shell);
}