/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** left_redir.c
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"
#include "my.h"
#include "src.h"

int do_left_redir(shell_t *shell, commands_t *commands, int is_double)
{
    int fd = -1;
    pid_t pid;

    if (!is_double)
        fd = open(shell->input_array[size_array(shell->input_array) - 1],
        O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    else
        double_left_redir(shell, commands);
    if (fd == -1 || get_new_input(shell, '<') == 84)
        return 84;
    pid = fork();
    if (pid == 0) {
        dup2(fd, 0);
        close(fd);
        check_which_command(shell, commands, 10);
        exit(pid);
    } else
        wait(NULL);
    return 0;
}