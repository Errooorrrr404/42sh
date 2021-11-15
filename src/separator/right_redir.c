/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** right_redir.c
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "struct.h"
#include "my.h"
#include "src.h"

int get_new_input(shell_t *shell, char delim)
{
    int size = 0;
    int i = 0;
    char *str = strdup(shell->input);

    for (; shell->input[size] != delim; size++);
    free(shell->input);
    shell->input = malloc(sizeof(char) * (size + 1));
    if (shell->input == NULL || !str)
        return 84;
    for (; i != size; i++)
        shell->input[i] = str[i];
    shell->input[i] = '\0';
    shell->input = clean_str(shell->input);
    free_array(shell->input_array);
    shell->input_array = str_to_array(shell->input, ' ');
    if (!shell->input_array)
        return 84;
    free(str);
    return 0;
}

int do_right_redir(shell_t *shell, commands_t *commands, int is_double)
{
    int fd;
    pid_t pid;

    if (is_double)
        fd = open(shell->input_array[size_array(shell->input_array) - 1],
        O_APPEND | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    else
        fd = open(shell->input_array[size_array(shell->input_array) - 1],
        O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1 || get_new_input(shell, '>') == 84)
        return 84;
    pid = fork();
    if (pid == 0) {
        dup2(fd, 1);
        close(fd);
        check_which_command(shell, commands, 10);
        exit(pid);
    } else
        wait(NULL);
    return 0;
}
