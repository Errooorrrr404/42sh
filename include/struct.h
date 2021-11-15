/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct history_s
{
    char **history;
    char *concat_hist;
} history_t;

typedef struct shell_s
{
    history_t *hist;
    char *path;
    char **env;
    char *input;
    char **input_array;
    char *line_path;
    char **array_path;
    char *home;
    char *old_pwd;
    int my_return;
    char *command;
} shell_t;

typedef struct commands_s
{
    char *command;
    void (*function)(shell_t *);
} commands_t;

#endif /* !STRUCT_H_ */
