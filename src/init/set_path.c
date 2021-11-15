/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** set_path
*/

#include <stdlib.h>
#include <string.h>
#include "src.h"
#include "my.h"

char *assign_line_path(char *tmp, char *tmp2)
{
    char *res = malloc(sizeof(char) * (strlen(tmp) + strlen(tmp2) + 100));
    char *str1 = strdup(tmp);
    char *str2 = strdup(tmp2);

    if (!res || !str1 || !str2)
        return NULL;
    res = strdup(strcat(str1, str2));

    return res;
}

int check(char *str, char *str2)
{
    int size = my_strlen(str) - 1;
    int i = 0;

    for (;i <= size; i++) {
        if (str[i] != str2[i])
            return (-1);
    }
    return 1;
}

int get_env_2(char *path, char **env)
{
    for (int i = 0; env[i]; i++) {
        if (check(path, env[i]) == 1)
            return (i);
    }
    return (-1);
}

char *my_set_exec(char **env)
{
    char *line_path;
    char *str;
    int j = 0;
    int i = get_env_2("PATH", env);

    if (i == -1) {
        line_path = NULL;
        return NULL;
    }
    str = env[i];
    line_path = malloc(sizeof(char) * (my_strlen(env[i]) + 1));

    for (int i = 5; str[i]; i++, j++)
        line_path[j] = str[i];
    line_path[j] = '\0';
    return (line_path);
}