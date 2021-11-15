/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** history
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "src.h"
#include "my.h"

void put_in_history(shell_t *shell, history_t *hist)
{
    static int check = 0;

    if (check == 0) {
        hist->concat_hist = strdup(shell->input);
        hist->history = str_to_array(hist->concat_hist, '\0');
        free(hist->concat_hist);
    } else {
        hist->concat_hist = array_to_str(hist->history, shell->input);
        if (!hist->concat_hist)
            return;
        free_array(hist->history);
        hist->history = str_to_array(hist->concat_hist, '#');
        free(hist->concat_hist);
    }
    check++;
}