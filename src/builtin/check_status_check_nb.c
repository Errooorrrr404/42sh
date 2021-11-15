/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include "my.h"
#include "src.h"

void check_status_check_nb(int nb, shell_t *shell)
{
    if (nb == 6 || nb == 8 || nb == 11)
        shell->my_return = nb + 128;
    if (shell->my_return != 0) {
        if (WIFSIGNALED(nb) && WCOREDUMP(nb))
            write(2, " (core dumped)", 14);
        my_printf("\n");
    }
}