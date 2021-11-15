/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** alias
*/

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "src.h"

void launch_alias(shell_t *shell, char *input)
{
    char *tmp = malloc(sizeof(char) * (strlen(input) + 1));
    char *str = malloc(sizeof(char) * (strlen(shell->input) + 1));

    if (!str || !tmp)
        return;

    tmp = assign_left(input, tmp);
    str = assign_right(shell->input, str);
    free_array(shell->input_array);
    free(shell->input);
    shell->input = strdup(strcat(tmp, str));
    shell->input = clean_str(shell->input);
    shell->input_array = str_to_array(shell->input, ' ');
    free(tmp);
    free(str);
}

void loop_comp(shell_t *shell, char *tmp, char **array_file)
{
    int len_array = size_array(array_file);
    char **array_line;

    for (int i = 0; i != len_array && len_array != 0; i++) {
        array_line = str_to_array(array_file[i], ' ');
        if (!array_line) {
            free_array(array_line);
            break;
        }
        if (strcmp(array_line[0], shell->input_array[0]) == 0)
            launch_alias(shell, array_file[i]);
        free_array(array_line);
    }
    free_array(array_file);
    free(tmp);
}

void alias_loop(shell_t *shell, char *tmp)
{
    char **array_file = str_to_array(tmp, '\n');

    if (!array_file) {
        free_array(array_file);
        free(tmp);
        return;
    }
    loop_comp(shell, tmp, array_file);
}

int exec_alias(shell_t *shell)
{
    struct stat s;
    char *tmp;
    int fd;

    stat(".aliasrc", &s);
    fd = open(".aliasrc", O_RDONLY);
    if (fd == -1) {
        return -1;
    } else {
        tmp = malloc(sizeof(char) * s.st_size + 1);
        if (!tmp) {
            free(tmp);
            return -1;
        }
        read(fd, tmp, s.st_size);
        tmp[s.st_size - 1] = '\0';
        alias_loop(shell, tmp);
    }
    return 0;
}

int check_alias(shell_t *shell)
{
    int fd = open(".aliasrc", O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);

    close (fd);
    if (strcmp(shell->input_array[0], "alias") == 0) {
        return (my_alias(shell));
    } else
        exec_alias(shell);
    return 0;
}