/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_cd
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include "src.h"
#include "my.h"

void return_back_folder(shell_t *shell, char *str)
{
    if (size_array(shell->input_array) > 2)
        return;
    if (shell->old_pwd) {
        chdir(shell->old_pwd);
        free(shell->old_pwd);
        shell->old_pwd = strdup(str);
    }
}

void exist_or_not(int nb, int nb2, shell_t *shell, char *str)
{
    struct stat s;

    if (nb == -1)
        my_printf("\x1b[31m%s: %s.\n\x1B[0m", shell->input_array[1],
            strerror(errno));
    nb2 = stat(shell->input_array[1], &s);
    if (nb != -1 && nb2 != -1) {
        free (shell->old_pwd);
        shell->old_pwd = strdup(str);
    }
}

void cd_option2(shell_t *shell, char **option, int nb)
{
    char *str = getcwd(NULL, 100);
    int nb2 = 0;

    if (str) {
        if (strcmp(option[1], "-") == 0) {
            return_back_folder(shell, str);
            free(str);
            return;
        } else
            nb = chdir(option[1]);
        exist_or_not(nb, nb2, shell, str);
        free(str);
        change_dir(shell);
    }
}

void cd_option(shell_t *shell)
{
    int nb = 0;

    if (size_array(shell->input_array) == 1 && shell->home) {
        shell->old_pwd = getcwd(NULL, 100);
        if (!shell->old_pwd)
            return;
        chdir(shell->home);
        change_dir(shell);
        return ;
    } else if (size_array(shell->input_array) >= 3) {
        my_printf("cd: Too many arguments.\n");
        return ;
    }
    cd_option2(shell, shell->input_array, nb);
}

void my_cd(shell_t *shell)
{
    if (strcmp("cd", shell->input_array[0]) == 0) {
        cd_option(shell);
    }
}