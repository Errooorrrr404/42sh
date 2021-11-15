/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** print_alias
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

void print_alias(int fd, char **array)
{
    dup2(fd, 1);
    close(fd);
    for (int i = 0; array[i]; i++)
        my_printf("%s\n", array[i]);
    exit(0);
}