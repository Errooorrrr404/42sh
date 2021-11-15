/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** dleft_redir
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"
#include "src.h"

int assign_in_file(char *str)
{
    int fd = open("titi", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
    pid_t pid;

    if (fd == -1)
        return 84;
    pid = fork();
    if (pid == 0) {
        dup2(fd, 1);
        close(fd);
        my_printf("%s", str);
        exit(pid);
    } else
        wait(NULL);
    return 0;
}

char *get_second_input(shell_t *shell)
{
    int i;
    char *buff = NULL;

    for (i = 0; shell->input[i] != '<'; i++);
    for (; shell->input[i] == '<'; i++);
    buff = catch_str(i, ' ', shell->input, '\0');
    if (buff == NULL)
        return NULL;
    buff[my_strlen(buff)] = '\n';
    return buff;
}

int launch_command(shell_t *shell, commands_t *commands)
{
    int j;

    free(shell->input);
    shell->input = strdup(shell->input_array[0]);
    if (shell->input == NULL)
        return 84;
    for (j = 0; shell->input[j]; j++);
    shell->input[j + 1] = '\0';
    strconcate(shell->input, " < titi");
    for (j = 0; shell->input[j]; j++);
    shell->input[j + 1] = '\0';
    free_array(shell->input_array);
    shell->input_array = str_to_array(shell->input, ' ');
    do_left_redir(shell, commands, 0);
    remove("titi");
    return 0;
}

int double_left_redir(shell_t *shell, commands_t *commands)
{
    char *input = NULL;
    size_t buff;
    char *str = get_second_input(shell);

    my_printf("? ");
    getline(&input, &buff, stdin);
    assign_in_file(input);
    while (!check_word(input, str)) {
        my_printf("? ");
        getline(&input, &buff, stdin);
        if (!check_word(input, str))
            assign_in_file(input);
    }
    launch_command(shell, commands);
    free(input);
    return 0;
}