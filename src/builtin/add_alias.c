/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** add_alias
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

void print_alias_in_file(shell_t *shell)
{
    char *tmp;
    int size_arr = size_array(shell->input_array);
    int len = 0;

    if (size_arr == 2) {
        return ;
    } else {
        tmp = malloc(sizeof(char) * (strlen(shell->input) - 5));
        if (tmp) {
            for (int i = 6; shell->input[i] != '\0' &&
            shell->input[i] != ';'; i++, len++)
                tmp[len] = shell->input[i];
            tmp[len] = '\0';
            my_printf("%s\n", tmp);
        }
        free (tmp);
        return;
    }
}

void replace_alias(int fd, shell_t *shell, char **array, int pos)
{
    char *tmp;
    int len = 0;

    fd = open(".aliasrc", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (size_array(shell->input_array) != 3)
        return;
    tmp = malloc(sizeof(char) * (strlen(shell->input) - 5));
    if (tmp) {
        for (int i = 6; shell->input[i] != '\0'; i++, len++)
            tmp[len] = shell->input[i];
        tmp[len] = '\0';
        free(array[pos]);
        array[pos] = strdup(tmp);
    }
    free (tmp);
    if (fork() == 0) {
        print_alias(fd, array);
    } else
        wait (NULL);
    close (fd);
}

int alias_exist(int fd, shell_t *shell, char *file)
{
    char **array = str_to_array(file, '\n');
    char **array_tmp;

    if (!array)
        return 0;
    for (int i = 0; array[i]; i++) {
        array_tmp = str_to_array(array[i], ' ');
        if (!array_tmp)
            return 0;
        if (strcmp(array_tmp[0], shell->input_array[1]) == 0) {
            replace_alias(fd, shell, array, i);
            free_array(array_tmp);
            free_array(array);
            return 0;
        }
        free_array(array_tmp);
    }
    free_array(array);
    return -1;
}

void exec_add_alias(int fd, shell_t *shell, char *file)
{
    close(fd);

    if ((alias_exist(fd, shell, file)) == 0)
        return;
    fd = open(".aliasrc", O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
    if (fork() == 0) {
        dup2(fd, 1);
        close(fd);
        print_alias_in_file(shell);
        exit (0);
    } else
        wait (NULL);
}

int my_alias(shell_t *shell)
{
    int fd;
    char *file;
    struct stat s;

    stat(".aliasrc", &s);
    fd = open(".aliasrc", O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
    file = malloc(sizeof(char) * (s.st_size));
    if (!fd)
        return -1;
    read(fd, file, s.st_size - 1);
    file[s.st_size - 1] = '\0';
    if (fd == -1 || size_array(shell->input_array) == 1)
        return -1;
    close (fd);
    shell->my_return = 0;
    exec_add_alias(fd, shell, file);
    free (file);
    return -1;
}