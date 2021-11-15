/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** path_tools_next
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include<stdio.h>
#include "my.h"
#include "src.h"

int check_is_exist(char **array_tmp, char *path)
{
    if (!array_tmp || strlen(path) < 5) {
            free_array(array_tmp);
            free (path);
            return -1;
    }
    return 0;
}

int path_exist(shell_t *shell)
{
    int check = get_env_2("PATH", shell->env);
    char *path;
    char **array_tmp;

    if (check == -1)
        return 0;
    else {
        if (strcmp(shell->env[check], "PATH=/") == 0 ||
        strcmp(shell->env[check], "PATH=") == 0)
            return -1;
        path = strdup(shell->env[check]);
        if (!path)
            return -1;
        array_tmp = str_to_array(path, '=');
        if (check_is_exist(array_tmp, path) == -1)
            return -1;
        free_array(array_tmp);
        free (path);
    }
    return 0;
}