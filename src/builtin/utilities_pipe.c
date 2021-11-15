/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** utilities_pipe
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "src.h"
#include "my.h"

int count_pipe(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '|')
            nb++;
    }
    return nb;
}

void prep_pipe(shell_t *shell)
{
    char *dup_input = strdup(shell->input);

    if (!dup_input)
        return;
    launch_pipe(shell, dup_input);
}

char *str_until_pipe(char *input)
{
    static int i = 0;
    char *str;
    int nb = 0;
    int size = 0;

    for (int tmp = i; input[tmp] != '|' && input[tmp] != '\0'; tmp++, nb++);
    str = malloc(sizeof(char) * (nb + 1));
    if (!str)
        return NULL;
    for (; input[i] != '|' && input[i] != '\0'; i++, size++)
        str[size] = input[i];
    str[size] = '\0';
    str = clean_str(str);
    i++;
    if (i >= my_strlen(input))
        i = 0;
    return str;
}

int assign_path2(shell_t *shell, char *str)
{
    int check = path_exist(shell);

    if (check == -1 || assign_new_path(shell) == -1)
        return -1;
    for (int i = 0; shell->array_path[i]; i++) {
        shell->path = my_strconcat(shell->array_path[i], str);
        if (access(shell->path, R_OK) != -1) {
            free (shell->path);
            return 0;
        } else
            free (shell->path);
    }
    return -1;
}

int check_com_pipe_exist(shell_t *shell)
{
    char **array = str_to_array(shell->input, '|');
    char **tmp;

    if (!array)
        return -1;
    for (int i = 0; i != size_array(array); i++) {
        array[i] = clean_str(array[i]);
        tmp = str_to_array(array[i], ' ');
        if (!tmp)
            return -1;
        if (assign_path2(shell, tmp[0]) != 0) {
            error_message(tmp[0], ": Command not found.\n");
            free_array(tmp);
            free_array(array);
            return -1;
        }
        free_array(tmp);
    }
    free_array(array);
    return 0;
}