/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** path_tools
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

char *clean_path(char *path)
{
    char *str = malloc(sizeof(char) * (strlen(path)));
    int i = 0;

    if (!str) {
        free(str);
        free(path);
        return NULL;
    }
    for (int size = 5; path[size] != '\0'; i++, size++)
        str[i] = path[size];
    str[i] = '\0';
    free(path);
    if (strlen(str) == 0) {
        free(str);
        return "E";
    }
    return str;
}

char *recup_new_path(char **env)
{
    char *path;
    int line = get_env_2("PATH", env);

    if (line == -1) {
        return "E";
    }
    else {
        path = strdup(env[line]);
        if (!path) {
            free(path);
            return NULL;
        } else
            return (clean_path(path));
    }
    return NULL;
}

int assign_new_path(shell_t *shell)
{
    if (shell->line_path[0] != 'E')
        free(shell->line_path);
    shell->line_path = recup_new_path(shell->env);
    if (shell->line_path[0] == 'E') {
        return 0;
    }
    free_array(shell->array_path);
    if (shell->line_path != NULL) {
        shell->array_path = str_to_array(shell->line_path, ':');
        shell->array_path = init_path(shell->array_path);
        return 0;
    }
    shell->line_path = NULL;
    shell->array_path = NULL;
    return -1;
}

int assign_path(shell_t *shell)
{
    int check = path_exist(shell);

    if (check == -1 || assign_new_path(shell) == -1)
        return -1;
    for (int i = 0; shell->array_path[i]; i++) {
        shell->path = my_strconcat(shell->array_path[i],
        shell->input_array[0]);
        if (access(shell->path, R_OK) != -1)
            return 0;
        else
            free (shell->path);
    }
    return -1;
}