/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** change_pwds
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "src.h"
#include "my.h"

char *concat_path(char *str, char *path)
{
    char *dest = malloc(sizeof(char) * (strlen(str) + strlen(path) + 2));
    int size = 0;

    for (unsigned int i = 0; i != strlen(str); i++, size++)
        dest[size] = str[i];
    for (unsigned int i = 0; i != strlen(path); i++, size++)
        dest[size] = path[i];
    dest[size] = '\0';
    return dest;
}

void change_dir(shell_t *shell)
{
    int nb = get_env_2("PWD", shell->env);
    int nb2 = get_env_2("OLDPWD", shell->env);
    char *str = getcwd(NULL, 100);

    if (nb != -1) {
        free(shell->env[nb]);
        shell->env[nb] = concat_path("PWD=", str);
    }
    if (nb2 != -1 && shell->old_pwd) {
        free(shell->env[nb2]);
        shell->env[nb2] = concat_path("OLDPWD=", shell->old_pwd);
    }
    free(str);
}