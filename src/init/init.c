/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** init
*/

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "src.h"
#include "my.h"

char *my_put_home(char **env)
{
    int i = 0;
    int k = 0;
    char *str;

    for (; env[i]; i++) {
        if (strncmp("HOME", env[i], 4) == 0)
            break;
    }
    if (env[i] == NULL)
        return NULL;
    str = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
    for (int j = 5; env[i][j] != '\0'; j++) {
        str[k] = env[i][j];
        k++;
    }
    str[k] = '\0';
    return (str);
}

char **init_path(char **path)
{
    char *tmp;
    int i;
    int j;

    for (i = 0; path[i]; i++) {
        j = 0;
        tmp = malloc(sizeof(char) * my_strlen(path[i]) + 2);
        for (; path[i][j] != '\0'; j++)
            tmp[j] = path[i][j];
        tmp[j] = '/';
        tmp[j + 1] = '\0';
        free (path[i]);
        path[i] = my_strdup(tmp);
        free (tmp);
    }
    return path;
}

int init_hist(history_t *hist)
{
    hist->history = NULL;
    hist->concat_hist = NULL;
    return 0;
}

int init_struct(shell_t *shell, char **env)
{
    char *tmp = "PATH=/usr/local/bin:/usr/bin:/bin:";
    char *tmp2 = "/usr/local/games:/usr/games:/sbin:/usr/sbin";

    shell->old_pwd = NULL;
    shell->input_array = NULL;
    shell->env = create_env(env);
    shell->line_path = my_set_exec(env);
    if (shell->line_path == NULL)
        shell->line_path = assign_line_path(tmp, tmp2);
    shell->home = my_put_home(env);
    shell->my_return = 0;
    if (shell->line_path) {
        shell->array_path = str_to_array(shell->line_path, ':');
        shell->array_path = init_path(shell->array_path);
    } else
        shell->array_path = NULL;
    shell->input = NULL;
    shell->path = NULL;
    init_hist(shell->hist);
    return 0;
}

commands_t *init_commands(void)
{
    commands_t *commands = malloc(sizeof(commands_t) * 6);

    commands[0].command = my_strdup("env");
    commands[0].function = display_env;
    commands[1].command = my_strdup("setenv");
    commands[1].function = setenv_command;
    commands[2].command = my_strdup("cd");
    commands[2].function = my_cd;
    commands[3].command = my_strdup("unsetenv");
    commands[3].function = my_unsetenv;
    commands[4].command = my_strdup("echo");
    commands[4].function = my_echo;
    commands[5].command = NULL;
    commands[5].function = NULL;
    for (int i = 0; i != 5; i++) {
        if (!commands || !commands[i].command)
            return NULL;
    }
    return commands;
}