/*
** EPITECH PROJECT, 2019
** exec
** File description:
** exec
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include "my.h"
#include "src.h"

void check_status(shell_t *shell, int nb, pid_t pid_fils)
{
    waitpid(pid_fils, &nb, 0);
    switch (nb) {
        case 6:
            my_printf("Abort");
            break;
        case 8:
            my_printf("Floating exception");
            break;
        case 11:
            my_printf("Segmentation fault");
            break;
        default:
            shell->my_return = 0;
    }
    check_status_check_nb(nb, shell);
}

int local_exec(shell_t *shell)
{
    static int nb = 0;
    pid_t pid_fils = fork();
    int status = 0;

    if (pid_fils == 0)
        nb = execve(shell->input_array[0], shell->input_array, shell->env);
    else
        check_status(shell, status, pid_fils);
    if (nb < 0 && (shell->input[0] == '.' || shell->input[0] == '/')
        && access(shell->input_array[0], 0) == 0) {
        my_printf("\x1b[31m%s: %s. Wrong Architecture.\n\x1B[0m",
                shell->input_array[0], strerror(errno));
        exit(pid_fils);
    } else if (nb < 0 && access(shell->input_array[0], 0) != 0) {
        error_message(shell->input_array[0], ": Command not found.\n");
        exit(pid_fils);
    }
    if (access(shell->input_array[0], 0) != 0)
        shell->my_return = 1;
    return 0;
}

void exec_with_path(shell_t *shell, char **argv)
{
    if (strcmp(shell->path, "/\0") != 0)
        execve(shell->path, argv, shell->env);
    else {
        error_message(shell->input_array[0], ": Command not found.\n");
        shell->my_return = 1;
    }
}

int sys_exec(shell_t *shell)
{
    int nb = assign_path(shell);
    char **argv;
    pid_t pid_fils;

    if (nb != 0)
        return -1;
    argv = str_to_array(shell->input, ' ');
    if (argv != NULL) {
        pid_fils = fork();
        if (pid_fils == 0) {
            exec_with_path(shell, argv);
            exit(pid_fils);
        } else
            wait(NULL);
    }
    free(shell->path);
    free_array(argv);
    if (argv == NULL)
        return -84;
    return 0;
}

int exec_command(shell_t *shell)
{
    if (sys_exec(shell) == 0)
        return 0;
    else {
        return (local_exec(shell));
    }
}